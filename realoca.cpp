#include "realoca.h"
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

bool realoca(int m,  int n, int p, vector<vector<int>>& solution, vector<vector<int>>& matrizT, vector<vector<int>>& matrizC, vector<CostTimeServer>& costTimeServers){
    bool encontrou_job = false;
    bool encontrou_menor_custo = false;

    int servidor_job = -1; 
    int contador_servidor;
    int servidor_origem;
    int job_exclui;

    for(int i = 0; i < n; i++){ // Inicia o for para percorrer a lista de jobs
        contador_servidor = 0;
        encontrou_job = false;
        if(encontrou_menor_custo){ // verificar se uma solução com menor custo foi encontrada e encerra o for
            break;
        }
        for (const auto& group : solution){ // percorre todas a solução para encontrar em qual servidor o job que estamos testando se encontra
            if(encontrou_job){
                break;
            }
            for (int l = 0; l < costTimeServers[contador_servidor].numSolutions; ++l){
                if(contador_servidor == m){ // caso seja o último servidor , servidor local
                    if (group[l] == i){
                        job_exclui = l;
                        encontrou_job = true;
                        servidor_job = -1;
                        servidor_origem = -1;
                        break;
                    }
                }else if (group[l] == i) {
                    job_exclui = l;
                    encontrou_job = true;
                    servidor_job = costTimeServers[contador_servidor].id; 
                    servidor_origem = contador_servidor;
                    break;
                }
            }
            contador_servidor++;
        }
        for(int j = 0; j < m; j++){ // percorre todos os servidores analisando se é possível fazer a inserção do job atual
            if(costTimeServers[j].id == servidor_job){ // caso servidor seja igual ao servidor que o job já está alocado
                continue;
            }else{
                // verfiica se a soma do tempo do job naquele servidor com o tempo já usado é menor que o tempo máximo
                // e se o custo nesse novo servidor é menor que naquele que ele já está alocado para que haja a troca
                // caso servidor_job seja igual a -1 significa que se trata do servidor local logo o custo é sempre menor
                if (((matrizT[costTimeServers[j].id][i] + costTimeServers[j].timeUsed) <= (costTimeServers[j].timeMax)) and ((servidor_job == -1) || (matrizC[costTimeServers[j].id][i] < matrizC[servidor_job][i]))){
                    
                    costTimeServers[j].timeUsed += matrizT[costTimeServers[j].id][i];
                    costTimeServers[j].costUsed += matrizC[costTimeServers[j].id][i];
                    
                    if(servidor_origem == -1){ // caso seja servidor local
                       costTimeServers[m].costUsed -= p;
                    }else{
                        
                        costTimeServers[servidor_origem].timeUsed -= matrizT[servidor_job][i];
                        costTimeServers[servidor_origem].costUsed -= matrizC[servidor_job][i];
                    }
                    
                    servidor_job = j; // servidor_job armazena o novo servidor onde o job deve ser alocado
                    encontrou_menor_custo = true;
                    break;
                }
            }
        }
    }
    int elementoRemovido;
    // Percorrendo o vector principal
    if(encontrou_menor_custo){ // caso um job tenha sido realocado

        //altera o servidor do job
        if(servidor_origem == -1){ // caso seja servidor local
            elementoRemovido= solution[m][job_exclui];
            solution[m].erase(solution[m].begin() + job_exclui);
            costTimeServers[m].numSolutions -= - 1;
            solution[servidor_job].push_back(elementoRemovido);
            costTimeServers[servidor_job].numSolutions += 1;
        }else{
            elementoRemovido= solution[servidor_origem][job_exclui];
            solution[servidor_origem].erase(solution[servidor_origem].begin() + job_exclui);
            costTimeServers[servidor_origem].numSolutions -= - 1;
            solution[servidor_job].push_back(elementoRemovido);
            costTimeServers[servidor_job].numSolutions += 1;
        }

        cout << "houve troca" << endl;

        return true;
    }else{
        cout << "Não houve troca" << endl;
        return false;
    }
};