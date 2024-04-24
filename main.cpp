#include <iostream>
#include <vector>
#include "greedy.h"
#include "CostTimeServer.h"
#include "merge.h"

using namespace std;

int main() {
    int n, m, p;
    // vector<pair<int, float>>  arrayB;
    // vector<vector<int>> matrizT;
    // vector<vector<int>> matrizC;
    
    // lerEntradas(n, m, p, arrayB, matrizT, matrizC);
    n=6;
    m=2;
    p=1000;
    vector<CostTimeServer> servers = {
        {0, 220.0f}, 
        {1, 350.0f}
    };

    vector<vector<int>> matrizT = {
        {120, 80, 180, 95, 35, 52},
        {145, 70, 230, 70, 40, 59}
    };

    vector<vector<int>> matrizC = {
        {350, 50, 540, 245, 145, 200},
        {410, 80, 500, 200, 100, 196}
    };



    cout << "Matriz T:" << endl;
    for (const auto &row : matrizT) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "Matriz C:" << endl;
    for (const auto &row : matrizC) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    genericMergeSort(servers, [](const  CostTimeServer& a, const CostTimeServer& b) {
        return a.timeMax < b.timeMax; // Ordenando por timeMax
    });
    
    // Exibindo as entradas lidas (apenas para verificação)
    cout << "Array B: ";
    for (const auto &server : servers) {
        cout << "(" << server.id << ", " << server.timeMax << ") ";
    }
    cout << endl;
    vector<vector<int>> greedySolution = greedy(n, m, servers, matrizT, matrizC);
    
    cout << "HERE THE SOLUTION" << endl;
    for(const auto& row: greedySolution){
        for(int val: row){
            cout << val << " ";
        }
        cout << endl;
    }

    // Adding local server
    // CostTimeServer local_server = CostTimeServer{-1, p};
    // servers.push_back(local_server);
    
    // int countInverse = m-1;
    // for(int i=0; i<m+1; i++){
    //     cout << "Servidor " << i << ": " << endl;
    //     float time = 0;
    //     float cost = 0;
    //     for(int j=0; j<greedySolution[i].size(); j++){
    //         if(i != m){
    //             servers[countInverse] += matrizT[servers[countInverse].id][greedySolution[i][j]];
    //             cost += matrizC[servers[countInverse].id][greedySolution[i][j]];
    //         }
    //         else{
    //             cost += p;  
    //         }
    //     }
    //     if(i != m){
    //         countInverse--;
    //         cout << "Time: " << time << " Cost: " << cost << endl; 
    //         costTimeServers.push_back(CostTimeServer{cost, time});
    //     }
    //     else{
    //         cout << "Cost: " << cost << endl; 
    //         costTimeServers.push_back(CostTimeServer{cost, 0});
    //     }

    // }


    return 0;
}
