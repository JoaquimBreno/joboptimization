#include "realoca.h"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

bool realoca(int m,  int n, int p, vector<vector<int>>& solution, vector<vector<int>>& matrizT, vector<vector<int>>& matrizC, vector<CostTimeServer>& costTimeServers){
    float soma, nova_soma;
    int job = -1;
    int servidor = -1;
    bool found_element = false;
    int servidor_job = -1;
    int servidor_group = -2;
    int servidor_origem = -1;
    bool encontrou_soma = false;

    for(int i = 0; i <= m; i++){
        soma += costTimeServers[i].costUsed;
    }

    for(int i = 0; i < n; i++){
        servidor_group = 0;
        found_element = false;
        if(encontrou_soma){
            break;
        }
        for (const auto& group : solution){
            if(found_element){
                break;
            }
            for (int l = 0; l < costTimeServers[servidor_group].numSolutions; ++l){
                if(servidor_group == m){
                    if (group[l] == i){
                        found_element = true;
                        servidor_job = -1;
                        break;
                    }
                }else if (group[l] == i) {
                    found_element = true;
                    servidor_job = costTimeServers[servidor_group].id; 
                    servidor_origem = servidor_group;
                    break;
                }
            }
            servidor_group++;
        }
        for(int j = 0; j < m; j++){
            if(costTimeServers[j].id == servidor_job){
                continue;
            }else{
                
                if (((matrizT[costTimeServers[j].id][i] + costTimeServers[j].timeUsed) <= (costTimeServers[j].timeMax)) and ((servidor_job == -1) || (matrizC[costTimeServers[j].id][i] < matrizC[servidor_job][i]))){
                    // if(servidor_job != -1){
                    //     cout << "entrou " << endl;
                    //     cout << servidor_job << endl;
                    //     cout << "J: " << j << " " << i << " " << matrizT[costTimeServers[j].id][i] << " " << matrizC[servidor_job][i] << " " << costTimeServers[j].timeUsed << " " << costTimeServers[j].timeMax << endl;
                    // }else{
                    //     cout << "entrou local " << endl;
                    //     cout << servidor_job << endl;
                    //     cout << "J: " << j << " " << i << " " << matrizT[costTimeServers[j].id][i] << " " << 1000 << " " << costTimeServers[j].timeUsed << " " << costTimeServers[j].timeMax << endl;
                    // }
                    costTimeServers[j].timeUsed += matrizT[costTimeServers[j].id][i];
                    costTimeServers[j].costUsed += matrizC[costTimeServers[j].id][i];
                    
                    if(servidor_job == -1){
                       costTimeServers[m].costUsed -= p;

                        nova_soma = soma - p + matrizC[costTimeServers[j].id][i];
                    }else{
                        
                        costTimeServers[servidor_origem].timeUsed -= matrizT[servidor_job][i];
                        costTimeServers[servidor_origem].costUsed -= matrizC[servidor_job][i];
                    }
                    
                    if (nova_soma < soma){
                        job = i;
                        servidor_job = j;
                        encontrou_soma = true;
                        break;
                    }
                }
            }
        }
    }
    int elementoRemovido;
    // Percorrendo o vector principal
    servidor_group = 0;
    if(encontrou_soma){
        for (vector<int>& vetorInterno : solution) {
            // Percorrendo o vetor interno
            for (int i = 0; i < costTimeServers[servidor_group].numSolutions; ++i) {
                if (vetorInterno[i] == job) {
                    elementoRemovido=vetorInterno[i];
                    vetorInterno.erase(vetorInterno.begin() + i);
                    // Ajustando o índice após a remoção
                    i--;
                }
            }
            servidor_group++;
        }
        
        costTimeServers[servidor_origem].numSolutions -= - 1;
        solution[servidor_job].push_back(elementoRemovido);
        costTimeServers[servidor_job].numSolutions += 1;

        cout << "houve troca" << endl;

        return true;
    }else{
        cout << "Não houve troca" << endl;
        return false;
    }
};