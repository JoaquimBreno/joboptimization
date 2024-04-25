#include "vnd.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vnd(int &custoT, int &tempoT, std::vector<std::pair<int, float>> &arrayB, std::vector<std::vector<int>> &matrizT, std::vector<std::vector<int>> &matrizC){
    int k = 1;
    int custo_novo;
    vector<vector<int>> greedySolution;
    bool solucao_nova = false;

    while(k<=3){
        if(k == 1){
            // chama swap
            // custo novo = swap();
        }else if(k == 2){
            // chama algoritimo de realoca
            // solucao_nova = realoca();
        }else if(k == 3){
            // chama algoritimo de busca
            // custo novo = busca_local();
        }

        if(solucao_nova){
            k = 1;
        }else{
            k++;
        }

    }

    return greedySolution;
}