#include "swap.h"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

vector<vector<int>> matrizCost;
vector<vector<int>> matrizTime;
int p;
int serverSize;

bool validationSwapJobs(vector<CostTimeServer> &servers, vector<vector<int>> &solution , int currentServer, int swappingServer, int currentJobIndex, int swappingJobIndex){

    // server solution

    // current server

    int swappingJobId = solution[swappingServer][swappingJobIndex];
    int currentJobId = solution[currentServer][currentJobIndex];

    int newJobTime= matrizTime[servers[currentServer].id][swappingJobId];
    int oldJobTime = matrizTime[servers[currentServer].id][currentJobId];
    int newCurrentServerTime = servers[currentServer].timeUsed - oldJobTime + newJobTime;
 
    if(newCurrentServerTime <= servers[currentServer].timeMax){
        
        if(servers[swappingServer].id == -1){
            // local server
            // current server    
            int newJobCost = matrizCost[servers[currentServer].id][swappingJobId];
            int oldJobCost = matrizCost[servers[currentServer].id][currentJobId];
            int newCurrentServerCost = servers[currentServer].costUsed - oldJobCost + newJobCost;

            // swapping server cost doesn't modify
            if(newCurrentServerCost < servers[currentServer].costUsed){
                servers[currentServer].costUsed = newCurrentServerCost;
                servers[currentServer].timeUsed = newCurrentServerTime;
                int aux = solution[currentServer][currentJobIndex];
                solution[currentServer][currentJobIndex] = solution[swappingServer][swappingJobIndex];
                solution[swappingServer][swappingJobIndex] = aux;
                // found a better solution
                return 1;
            }

            return 0;
           
        }  
            
        // swapping server
        newJobTime = matrizTime[servers[swappingServer].id][currentJobId];
        oldJobTime = matrizTime[servers[swappingServer].id][swappingJobId];
        int newSwappingServerTime = servers[swappingServer].timeUsed - oldJobTime + newJobTime;

        if(newSwappingServerTime <= servers[swappingServer].timeMax){    

            // current server    
            int newJobCost = matrizCost[servers[currentServer].id][swappingJobId];
            int oldJobCost = matrizCost[servers[currentServer].id][currentJobId];
            int newCurrentServerCost = servers[currentServer].costUsed - oldJobCost + newJobCost;

            // swapping server
            newJobCost = matrizCost[servers[swappingServer].id][currentJobId];
            oldJobCost = matrizCost[servers[swappingServer].id][swappingJobId];
            int newSwappingServerCost = servers[swappingServer].costUsed - oldJobCost + newJobCost;

            if(newCurrentServerCost + newSwappingServerCost < servers[currentServer].costUsed + servers[swappingServer].costUsed){
                servers[currentServer].costUsed = newCurrentServerCost;
                servers[swappingServer].costUsed = newSwappingServerCost;
                servers[currentServer].timeUsed = newCurrentServerTime;
                servers[swappingServer].timeUsed = newSwappingServerTime;
                int aux = solution[currentServer][currentJobIndex];
                solution[currentServer][currentJobIndex] = solution[swappingServer][swappingJobIndex];
                solution[swappingServer][swappingJobIndex] = aux;
                // found a better solution
                return 1;
            }
        }
    }
    return 0;
}

bool swapJobs(vector<CostTimeServer> &servers, vector<vector<int>>& solution, int serverIndex, int jobIndex) {
    
    if (jobIndex > solution[serverIndex].size()-1) {
        if (serverIndex == serverSize-2) {
            return 0;
        } 
        else{
            return swapJobs(servers, solution, serverIndex + 1, 0);
        }
    }

    for (int i = serverIndex + 1; i < serverSize; i++) {
        for (int j = 0; j < solution[i].size(); j++) {

            if(validationSwapJobs(servers, solution, serverIndex, i, jobIndex, j)){
                cout << "found a better solution" << endl;
                return 1;
            }
        }
    }

    return swapJobs(servers, solution, serverIndex, jobIndex + 1);
}

bool swap(vector<vector<int>>& solution, vector<vector<int>>& matrizT, vector<vector<int>>& matrizC, vector<CostTimeServer>& servers, int p) {
    /** if i have an a array solution like [[1 2 3][5][6 7]] just make swappings like [[5 2 3][1][6 7]]*/
    /** once the newJobId = 6 an jobId =1  , i'll verify  if  server[0] supports newJobTime= matrizT[server[0].id][newJobId] checking if (server[0].timeUsed - oldJobTime + newJobTime <= server[0].timeMax)
     *  so, if it's true, i'll verify if server[1] supports newJobTime= matrizT[server[1].id][oldJobId], and oldJobTime = matrizT[server[1].id][newJobId], given that oldJobId is the same of newJobId and newJobId is the same of jobId 
     * once checking if (server[1].timeUsed - oldJobTime + oldJobTime <= server[1].timeMax)
     * Before this verification, i'll check if the new solution is better than the old one, if it is, i'll update the solution
     * And iterate to the next job of this same server[1] if exists or change to next server
     * Swapping each job of each server to whole jobs from another servers
     */
    bool foundGreedy = 0;
    int nonEmptyVectorCount = 0;
    for(const auto& vec : solution) {
        if(!vec.empty()) {
            nonEmptyVectorCount++;
        }

        if(nonEmptyVectorCount >= 2) {
            matrizCost = matrizC;
            matrizTime = matrizT;
            p = p;
            serverSize = servers.size();

            foundGreedy = swapJobs(servers, solution, 0, 0);
            cout << "foundGreedy: " << foundGreedy << endl;
            return foundGreedy; // Return the answer of found a better solution
        }
    }

    return foundGreedy;
}
