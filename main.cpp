#include <iostream>
#include <vector>
#include "greedy.h"

using namespace std;

int main() {
    int n, m, p;
    // vector<pair<int, float>>  arrayB;
    // vector<vector<int>> matrizT;
    // vector<vector<int>> matrizC;
    
    // lerEntradas(n, m, p, arrayB, matrizT, matrizC);
    n=6;
    m=2;
    p=1000;
    std::vector<std::pair<int, float>> arrayB = {
        {0, 220.0f}, 
        {1, 350.0f}
    };
    std::vector<std::vector<int>> matrizT = {
        {120, 80, 180, 95, 35, 52},
        {145, 70, 230, 70, 40, 59}
    };

    std::vector<std::vector<int>> matrizC = {
        {350, 50, 540, 245, 145, 200},
        {410, 80, 500, 200, 100, 196}
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

    pairMergeSort(arrayB); 
    
    // Exibindo as entradas lidas (apenas para verificação)
    cout << "Array B: ";
    for (const auto &pair : arrayB) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;
    vector<vector<int>> greedySolution = greedy(n, m, arrayB, matrizT, matrizC);
    
    cout << "HERE THE SOLUTION" << endl;
    for(const auto& row: greedySolution){
        for(int val: row){
            cout << val << " ";
        }
        cout << endl;
    }

    int countInverse = m-1;
    for(int i=0; i<m+1; i++){
        cout << "Servidor " << i << ": " << endl;
        float time = 0;
        float cost = 0;
        for(int j=0; j<greedySolution[i].size(); j++){
            if(i != m){
                time += matrizT[arrayB[countInverse].first][greedySolution[i][j]];
                cost += matrizC[arrayB[countInverse].first][greedySolution[i][j]];
            }
            else{
                cost += p;  
            }
        }
        if(i != m){
            countInverse--;
            cout << "Time: " << time << " Cost: " << cost << endl; 
        }
        else{
            cout << "Cost: " << cost << endl; 
        }

    }
    return 0;
}
