#include "realoca.h"
#include <iostream>
#include <vector>
#include <algorithm> 

#include "CostTimeServer.h"

using namespace std;

vector<vector<int>> realoca(int m, vector<vector<int>>& solution, vector<vector<int>>& matrizT, vector<vector<int>>& matrizC, vector<CostTimeServer>& costTimeServers, int n){
float soma, nova_soma;
    int job = -1;
    int servidor = -1;
    bool found_element = false;
    int servidor_job = -1;
    int servidor_group = -1;
    int servidor_origem = -1;

    for(int i = 0; i <= m; i++){
        soma += costTimeServers[i].costUsed;
    }
    // cout << "soma " << soma << endl;

    for(int i = 0; i < n; i++){
        // cout << "teste"<< i << endl;
        servidor_group = 0;
        for (const auto& group : solution) {
            if(found_element){
                found_element = false;
                break;
            }
            for (int l = 0; l < group.size(); ++l){
                if(servidor_group == 2){
                    if (group[l] == i){
                        found_element = true;
                        servidor_job = m; 
                        break;
                    }
                }else if (group[l] == i) {
                    found_element = true;
                    servidor_job = costTimeServers[servidor_group].id; 
                    break;
                }
            }
            servidor_group++;
        }
        
        for(int j = 0; j < m; j++){
            if(costTimeServers[j].id == servidor_job){
                continue;
            }else{
                // cout << "job 0 no servidor " << j << " " << matrizT[j][i] << " " << costTimeServers[j].timeUsed << " " << costTimeServers[j].timeMax << endl;
                if (((matrizT[j][i] + costTimeServers[j].timeUsed) <= (costTimeServers[j].timeMax))){
                    // cout << "teste " << matrizT[j][i] + costTimeServers[j].timeUsed  << endl;
                    // cout << "teste " << matrizC[j][i] <<" " << costTimeServers[j].costUsed  << endl;
                    costTimeServers[j].timeUsed += matrizT[j][i];
                    costTimeServers[j].costUsed += matrizC[j][i];
                    // cout << "teste " << matrizC[j][i] <<" " << costTimeServers[j].costUsed  << endl;
                    // cout << "teste " << costTimeServers[j].timeUsed  << endl;
                    // percorrer solution e verificar em que servidor o job está
                    // [[1 2 3][4 5][6]] o job 1 está no j= 0
                    // logo o server dele será igual a servers[j]
                    // para pegar as informações do server, server = servers[j].id, servers[j].timeMax, servers[j].timeUsed, servers[j].costUsed
                    // cout << "teste 2 " << costTimeServers[costTimeServers[j].id].timeUsed  << endl;
                    // cout << "teste 1 " << matrizC[costTimeServers[j].id][i] << endl;
                    costTimeServers[costTimeServers[j].id].timeUsed -= matrizT[costTimeServers[j].id][i];
                    costTimeServers[costTimeServers[j].id].costUsed -= matrizC[costTimeServers[j].id][i];
                    // cout << "teste 1 " << costTimeServers[costTimeServers[j].id].costUsed  << endl;
                    // cout << "teste 2 " << costTimeServers[costTimeServers[j].id].timeUsed  << endl;
                    for(int k = 0; k <= m; k++){
                        nova_soma += costTimeServers[k].costUsed;
                        // cout << "soma: " << k << " " << costTimeServers[k].costUsed << endl;
                    }
                    if(nova_soma < soma){
                        servidor_origem = servidor_job;
                        job = i;
                        servidor = j;
                        soma = nova_soma;
                        break;
                    }
                }
            }
        }
    }

    int job_troca = job;
    int elementoRemovido;
    // Percorrendo o vector principal
    for (vector<int>& vetorInterno : solution) {
        // Percorrendo o vetor interno
        for (int i = 0; i < vetorInterno.size(); ++i) {
            // Verificando se o elemento é 5
            if (vetorInterno[i] == job) {
                // Removendo o elemento 5
                elementoRemovido=vetorInterno[i];
                vetorInterno.erase(vetorInterno.begin() + i);
                // Ajustando o índice após a remoção
                i--;
            }
        }
    }

    solution[servidor].push_back(elementoRemovido);

    // for (vector<int>& vetorInterno : solution) {
    //     // Percorrendo o vetor interno
    //     for (int i = 0; i < vetorInterno.size(); ++i) {
    //         // Verificando se o elemento é 5
    //         cout << "cuida "<< vetorInterno[i] << " " << i << endl;
    //     }
    // }

    return solution;
};
//     int m=2;
//     vector<vector<int>> solution = {{1,2,4},{0,3},{5}};
//     vector<vector<int>> matrizT= {
//         {120, 80, 180, 95, 35, 52},
//         {145, 70, 230, 70, 40, 59}
//     };
//     vector<vector<int>> matrizC = {
//         {350, 50, 540, 245, 145, 200},
//         {410, 80, 500, 200, 100, 196}
//     };
//     vector<CostTimeServer> costTimeServers= {
//         {1, 500.0f}, 
//         {0, 220.0f},
//         {2, 0}
//     };
//     int n=6;
    
//     costTimeServers[1].costUsed = 595;
//     costTimeServers[0].costUsed = 680;
//     costTimeServers[1].timeUsed = 215;
//     costTimeServers[0].timeUsed = 340;
//     costTimeServers[2].costUsed = 1000;
//     costTimeServers[2].timeUsed = 0;
