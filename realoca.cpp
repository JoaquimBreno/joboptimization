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

    for(int i = 0; i < n; i++){
        servidor_group = 0
        for (const auto& group : solution) {
            if(found_element){
                break;
            }
            for (int l = 0; l < group.size(); ++l) {
                if (group[l] == i) {
                found_element = true;
                servidor_job = servidor_group; 
                break;
                }
            }
            servidor_group++;
        }

        for(int j = 0; i < m; i++){
            if(costTimeServers[j].id == servidor_job){
                continue;
            }else{
                if (((matrizT[i][j] + costTimeServers[j].timeUsed) <= (costTimeServers[j].timeMax))){
                    costTimeServers[j].timeUsed += matrizT[i][j];
                    // percorrer solution e verificar em que servidor o job está
                    // [[1 2 3][4 5][6]] o job 1 está no j= 0
                    // logo o server dele será igual a servers[j]
                    // para pegar as informações do server, server = servers[j].id, servers[j].timeMax, servers[j].timeUsed, servers[j].costUsed
                    costTimeServers[servidor_job].timeUsed -= matrizT[i][costTimeServers[servidor_job].id];
                    for(int k = 0; k <= m; k++){
                        nova_soma += costTimeServers[k].costUsed;
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

    solution[servidor].push_back[elementoRemovido]

    return solution;
}