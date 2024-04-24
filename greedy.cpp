#include "greedy.h"
#include <iostream>
#include <vector>


using namespace std;

// BUSCA BINÀRIA
int binary_search(vector<int> &jobs_used, int search){

    genericMergeSort(jobs_used, [](const int& a, const int& b) {
        return a < b;
    });

    // intervalo
    int left = 0;
    int right = jobs_used.size()-1;
    while(left<right){
        int mid = (left+right)/2;
        
        if(jobs_used[mid]<search){
            left = mid+1;
        }else if(jobs_used[mid]>search){
            right = mid-1;
        }else{
            left = right = mid;
        }
    }
    
    if(jobs_used[left]==search){
        return 1;
        
    }else{
        return 0;
    }
}
// BUSCA BINÁRIA


vector<vector<int>> greedy(int &n, int &m, vector<CostTimeServer> &servers, vector<vector<int>> &matrizT, vector<vector<int>> &matrizC){

    vector<vector<pair<int, float>>> matrizCT;
    for (int i = 0; i < m; ++i) {
        vector<pair<int, float>> row;
        for (int j = 0; j < n; ++j) {
            float result = static_cast<float>(matrizC[i][j]) / matrizT[i][j];
            row.push_back(make_pair(j, result));
        }
        matrizCT.push_back(row);
    }

    for (vector<pair<int,float>> & row : matrizCT) {
        genericMergeSort(row, [](const pair<int, float>& a, const pair<int, float>& b) {
            return a.second < b.second;
        });
    }

    vector<vector<int>> greedySolution;
    float timeCost;
    int time;
    vector<int> jobs_used;
    int answer; // retorno busca binária
    
    for (int i = m-1; i >= 0; --i) {
            CostTimeServer server = servers[i];
            timeCost = server.timeMax;
            vector<int> solution;
            vector<int> lastSolution;
            for(pair<int,float> &row: matrizCT[server.id]){
                time = matrizT[server.id][row.first];
                if((time <= timeCost) && (i == m-1)){
                    solution.push_back(row.first);
                    timeCost -= time;
                    jobs_used.push_back(row.first);
                }else{
                    answer = binary_search(jobs_used, row.first);
                    if(answer == 0){
                        if(time <= timeCost){
                            solution.push_back(row.first);
                            timeCost -= time;
                            jobs_used.push_back(row.first);
                        }
                        else if(time > timeCost && i==0){
                            lastSolution.push_back(row.first);
                        }
                    }
                }
            }
            greedySolution.push_back(solution);
            if(i==0){
                greedySolution.push_back(lastSolution);
            }
    }

    return greedySolution;
}
