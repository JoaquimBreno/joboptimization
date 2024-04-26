#include "vnd.h"
#include <iostream>
#include <vector>

using namespace std;

void vndFunction(vector<CostTimeServer>& servers, vector<vector<int>>& solution, vector<vector<int>> &matrizT, vector<vector<int>> &matrizC, int m, int n, int p){
    int k = 1;
    bool solucao_nova = false;

    while(k<=3){
        if(k == 1){
            // chama swap
            solucao_nova = swap(solution, matrizT, matrizC, servers, p);
        }else if(k == 2){
            // chama algoritimo de realoca
            solucao_nova = realoca(m, n, p, solution, matrizT, matrizC, servers);
        }else if(k == 3){
            cout << " Não implementado ainda!" << endl;
            solucao_nova = false;
            // chama algoritimo de busca
            // custo novo = busca_local();
        }

        if(solucao_nova){
            k = 1;
        }else{
            k++;
        }

    }
}