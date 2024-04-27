#include <iostream>
#include <vector>
#include "greedy.h"
#include "merge.h"
#include "vnd.h"
#include "realoca.h"

#include "CostTimeServer.h"

using namespace std;

int main() {
    int n, m;
    float p;
    // vector<pair<int, float>>  arrayB;
    // vector<vector<int>> matrizT;
    // vector<vector<int>> matrizC;
    
    // lerEntradas(n, m, p, arrayB, matrizT, matrizC);
    // n=6;
    // m=2;
    // p=1000;
    // vector<CostTimeServer> servers = {
    //     {0, 220.0f}, 
    //     {1, 350.0f}
    // };

    // vector<vector<int>> matrizT = {
    //     {120, 80, 180, 95, 35, 52},
    //     {145, 70, 230, 70, 40, 59}
    // };

    // vector<vector<int>> matrizC = {
    //     {350, 50, 540, 245, 145, 200},
    //     {410, 80, 500, 200, 100, 196}
    // };


    n=15;
    m=5;
    p=1000;
    vector<CostTimeServer> servers = {
        {0, 36.0f}, 
        {1, 34.0f}, 
        {2, 38.0f}, 
        {3, 27.0f}, 
        {4, 33.0f}
    };
    
    // {2, 38.0f}, 
    // {0, 36.0f}, 
    // {1, 34.0f}, 
    // {4, 33.0f}
    // {3, 27.0f},
    

    vector<vector<int>> matrizT = {
        {8, 15, 14, 23,  8, 16,  8, 25,  9, 17, 25, 15, 10,  8, 24},
        {15,  7, 23, 22, 11, 11, 12, 10, 17, 16,  7, 16, 10, 18, 22},
        {21, 20,  6, 22, 24, 10, 24,  9, 21, 14, 11, 14, 11, 19, 16},
        {20, 11,  8, 14,  9,  5,  6, 19, 19,  7,  6,  6, 13,  9, 18},
        {8, 13, 13, 13, 10, 20, 25, 16, 16, 17, 10, 10,  5, 12, 23}
    };

    vector<vector<int>> matrizC = {
        {17, 21, 22, 18, 24, 15, 20, 18, 19, 18, 16, 22, 24, 24, 16},
        {23, 16, 21, 16, 17, 16, 19, 25, 18, 21, 17, 15, 25, 17, 24},
        {16, 20, 16, 25, 24, 16, 17, 19, 19, 18, 20, 16, 17, 21, 24},
        {19, 19, 22, 22, 20, 16, 19, 17, 21, 19, 25, 23, 25, 25, 25},
        {18, 19, 15, 15, 21, 25, 16, 16, 23, 15, 22, 17, 19, 22, 24}
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
        return a.timeMax > b.timeMax; // Ordenando por timeMax
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
    //Adding local server
    CostTimeServer local_server = CostTimeServer{-1, p};
    servers.push_back(local_server);
    

    for(int i=0; i<=m; i++){
        float time = 0;
        float cost = 0;

        for(int j=0; j<greedySolution[i].size(); j++){
            if(i != m){
                servers[i].timeUsed += matrizT[servers[i].id][greedySolution[i][j]];
                servers[i].costUsed += matrizC[servers[i].id][greedySolution[i][j]];
                servers[i].numSolutions++;
            }
            else{
                servers[i].costUsed  += p;  
                servers[i].numSolutions++;
            }
        }
    }

    for (int i= 0 ; i<=m; i++){
        cout << "Server " << i << " time used: " << servers[i].timeUsed << " cost used: " << servers[i].costUsed << " num solutions: " << servers[i].numSolutions << endl;
    }

    for (int i= 0 ; i<=m; i++){
        cout << "Server " << i << " time used: " << servers[i].timeUsed << " cost used: " << servers[i].costUsed << endl;
    }

    // vector<CostTimeServer> Cservers = {
    //     {1, 350.0f}, 
    //     {0, 290.0f},
    //     {-1, n*p}
    // };
    // Cservers[1].costUsed = 595;
    // Cservers[0].costUsed = 680;
    // Cservers[1].timeUsed = 215;
    // Cservers[0].timeUsed = 340;
    // Cservers[m].costUsed = 1000;
    // Cservers[m].timeUsed = 0;

    int soma = 0;
    for(int i = 0; i <= m; i++){
        soma += servers[i].costUsed;
    }
    cout << "soma custo " << soma << endl;

    vndFunction(servers, greedySolution, matrizT, matrizC, m, n, p);
    // cout << servers[2].costUsed << " serversaqui" << endl;
    // bool resposta = true;
    // int i = 0;
    // while(resposta){
    // resposta = realoca(m, n, p, greedySolution, matrizT, matrizC, servers);
    // for (int i= 0 ; i<=m; i++){
    //     cout << "Server " << i << " time used: " << servers[i].timeUsed << " cost used: " << servers[i].costUsed << endl;
    //     //
    // }

    // cout << "HERE THE SOLUTION" << endl;
    // for(const auto& row: greedySolution){
    //     for(int val: row){
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }
    // }

    for (int i= 0 ; i<=m; i++){
        cout << "Server " << i << " time used: " << servers[i].timeUsed << " cost used: " << servers[i].costUsed << endl;
        //
    }

    cout << "HERE THE SOLUTION" << endl;
    for(const auto& row: greedySolution){
        for(int val: row){
            cout << val << " ";
        }
        cout << endl;
    }

    soma = 0;
    for(int i = 0; i <= m; i++){
        soma += servers[i].costUsed;
    }
    cout << "soma custo " << soma << endl;
}
