#include "vnd.h"
#include <iostream>
#include <vector>

using namespace std;

void vndFunction(vector<CostTimeServer>& servers, vector<vector<int>>& solution, vector<vector<int>> &matrizT, vector<vector<int>> &matrizC, int m, int n, int p){
    int k = 1;
    bool solucao_nova = false;

    while(k<=3){
        if(k == 2){
            // chama swap
            solucao_nova = swap(solution, matrizT, matrizC, servers, p);
        }else if(k == 1){
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


// Server 0 time used: 35 cost used: 32
// Server 1 time used: 34 cost used: 35
// Server 2 time used: 29 cost used: 32
// Server 3 time used: 29 cost used: 31
// Server 4 time used: 27 cost used: 74
// Server 5 time used: 0 cost used: 3000
// HERE THE SOLUTION
// 0 11 
// 10 8 
// 3 1 
// 2 7 
// 6 5 9 4 
// 14 12 13 
// soma custo 3204