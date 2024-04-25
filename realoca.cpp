#include "realoca.h"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

vector<vector<int>> realoca(int m,  int n, int p, vector<vector<int>>& solution, vector<vector<int>>& matrizT, vector<vector<int>>& matrizC, vector<CostTimeServer>& costTimeServers){
    float soma, nova_soma;
    int job = -1;
    int servidor = -1;
    bool found_element = false;
    int servidor_job = -1;
    int servidor_group = -1;
    // int servidor_origem = -1;
    bool encontrou_soma = false;

    for(int i = 0; i <= m; i++){
        soma += costTimeServers[i].costUsed;
    }
    // cout << "soma " << soma << endl;

    for(int i = 0; i < n; i++){
        // cout << "teste"<< i << endl;
        servidor_group = 0;
        if(encontrou_soma){
            // cout << "saiu for" << endl;
            encontrou_soma = false;
            break;
        }
        for (const auto& group : solution) {
            if(found_element){
                found_element = false;
                break;
            }
            for (int l = 0; l < group.size(); ++l){
                if(servidor_group == m){
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
        
        // cout << servidor_job << i << endl;
        for(int j = 0; j < m; j++){
            // cout << costTimeServers[j].id << " " << servidor_job << " " << i << endl;
            if(costTimeServers[j].id == servidor_job){
                // cout << costTimeServers[j].id << " " << servidor_job << " " << i << endl;
                continue;
            }else{
                // cout << "job 0 no servidor " << j << " " << matrizT[costTimeServers[j].id][i] << " " << costTimeServers[j].timeUsed << " " << costTimeServers[j].timeMax << " " << i << endl;
                if(((matrizT[costTimeServers[j].id][i] + costTimeServers[j].timeUsed) <= (costTimeServers[j].timeMax))){
                    
                    costTimeServers[j].timeUsed += matrizT[costTimeServers[j].id][i];
                    costTimeServers[j].costUsed += matrizC[costTimeServers[j].id][i];
                    
                    if(servidor_job == m){
                        costTimeServers[costTimeServers[j].id].costUsed -= p;
                    }else{
                        costTimeServers[costTimeServers[j].id].timeUsed -= matrizT[j][i];
                        costTimeServers[costTimeServers[j].id].costUsed -= matrizC[j][i];
                    }
                    
                    nova_soma = 0;
                    for(int k = 0; k <= m; k++){
                        nova_soma += costTimeServers[k].costUsed;
                    }
                    if(nova_soma < soma){
                        // servidor_origem = servidor_job;
                        job = i;
                        servidor = j;
                        soma = nova_soma;
                        encontrou_soma = true;
                        break;
                    }else{
                        costTimeServers[j].timeUsed -= matrizT[costTimeServers[j].id][i];
                        costTimeServers[j].costUsed -= matrizC[costTimeServers[j].id][i];
                        if(servidor_job == m){
                            costTimeServers[costTimeServers[j].id].costUsed -= 1000;
                        }else{
                            costTimeServers[costTimeServers[j].id].timeUsed -= matrizT[j][i];
                            costTimeServers[costTimeServers[j].id].costUsed -= matrizC[j][i];
                        }
                        
                    }
                }
            }
        }
    }

    // int job_troca = job;
    int elementoRemovido;
    // Percorrendo o vector principal
    if(job != -1){
        for (vector<int>& vetorInterno : solution) {
            // Percorrendo o vetor interno
            for (int i = 0; i < vetorInterno.size(); ++i) {
                if (vetorInterno[i] == job) {
                    elementoRemovido=vetorInterno[i];
                    vetorInterno.erase(vetorInterno.begin() + i);
                    // Ajustando o índice após a remoção
                    i--;
                }
            }
        }
        
        solution[servidor].push_back(elementoRemovido);

        for (vector<int>& vetorInterno : solution) {
            // Percorrendo o vetor interno
            for (int i = 0; i < vetorInterno.size(); ++i) {
                // cout << "cuida "<< vetorInterno[i] << " " << i << endl;
                return solution;
            }
        }
    }else{
        cout << "Não houve troca" << endl;
        return solution;
    }
};
    //  int m=2;
    // vector<vector<int>> solution = {{1,2,4},{0,3},{5}};
    // vector<vector<int>> matrizT= {
    //     {120, 80, 180, 95, 35, 52},//220
    //     {145, 70, 230, 70, 40, 59},//350
    //     {0,0,0,0,0,0}
    // };
    // vector<vector<int>> matrizC = {
    //     {350, 50, 540, 245, 145, 200},//220
    //     {410, 80, 500, 200, 100, 196},//350
    //     {1000,1000,1000,1000,1000,1000}
    // };
    // vector<CostTimeServer> costTimeServers= {
    //     {1, 2000.0f},//350
    //     {0, 2000.0f},//220
    //     {2, 10000.0f}
    // };
    // int n=6;
    
    // costTimeServers[1].costUsed = 595;
    // costTimeServers[0].costUsed = 680;
    // costTimeServers[1].timeUsed = 215;
    // costTimeServers[0].timeUsed = 340;
    // costTimeServers[2].costUsed = 1000;
    // costTimeServers[2].timeUsed = 0;
