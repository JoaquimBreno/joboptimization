#include "greedy.h"
#include <iostream>

using namespace std;
/*
#include "greedy.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void mergeSort(vector<int> &arrayB, &p, &r){
    int q;
    if(p<r){
        q = static_cast<int>(floor((p+r)/2));
        mergeSort(arrayB, p, r);
        mergeSort(arrayB, q+1, r);
        merge(arrayB, p, q, r)
    }
}

void mergeSort(vector<int> &arrayB, &p, &r){
    int q;
    if(p<r){
        q = static_cast<int>(floor((p+r)/2));
        mergeSort(arrayB, p, r);
        mergeSort(arrayB, q+1, r);
        merge(arrayB, p, q, r)
    }
}

int main ()
{
  printf ("Hello World");

  return 0;
}

    
}

*/
vector<vector<int>> greedy(int &n, int &m, int &p, std::vector<int> &arrayB, std::vector<std::vector<int>> &matrizT, std::vector<std::vector<int>> &matrizC){

    vector<vector<int>> matrizCT;
    for (int i = 0; i < matrizT.size(); ++i) {
        vector<int> row;
        for (int j = 0; j < matrizT[i].size(); ++j) {
            row.push_back(matrizC[i][j]/matrizT[i][j]);
        }
        matrizCT.push_back(row);
    }

    
}