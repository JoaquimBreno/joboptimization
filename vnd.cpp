#include "vnd.h"
#include <iostream>
#include <vector>

using namespace std;

void swap(){
    return 0;
}  

vector<vector<int>> vnd(int &custoT, int &tempoT, std::vector<std::pair<int, float>> &arrayB, std::vector<std::vector<int>> &matrizT, std::vector<std::vector<int>> &matrizC){
    int k = 1;
    int custo_novo;
    vector<vector<int>> greedySolution;

    while(k<=3){
        if(k == 1){
            // chama swap
            swap(greedySolution, matrizT, matrizC, servers, p);
            // custo novo = swap();
        }else if(k == 2){
            // chama algoritimo de busca
            // custo novo = busca_local();
        }else if(k == 3){
            // chama algoritimo de busca
            // custo novo = busca_local();
        }

        if(custo_novo < custoT){
            custoT = custo_novo;
            k = 1;
        }else(){
            k++;
        }

    }

    return greedySolution;
}