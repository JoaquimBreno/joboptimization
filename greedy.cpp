#include "greedy.h"
#include <iostream>
#include <vector>

using namespace std;

// BUSCA BINÀRIA
int binary_search(vector<int>& jobs_used, int search){
    // intervalo
    int left = 0;
    int right = jobs_used.size()-1;
    while(left<right){
        int mid = (left+right)/2;
        
        if(jobs_used[mid]<search){
            left = mid+1;
        }else if(jobs_used[mid]>search){
            right = mid-1;
        }else{
            left = right = mid;
        }
    }
    
    if(jobs_used[left]==search){
        return 1;
        
    }else{
        return 0;
    }
}
// BUSCA BINÁRIA


void mergePairs(vector<pair<int, float>>& v, int i, int meio, int j, int fim, int k, vector<pair<int, float>>& aux) {
    if (i <= meio && (j > fim || v[i].second < v[j].second)) {
        aux[k] = v[i];
        mergePairs(v, i + 1, meio, j, fim, k + 1, aux);
    } else if (j <= fim) {
        aux[k] = v[j];
        mergePairs(v, i, meio, j + 1, fim, k + 1, aux);
    }
}

void mergeSortPairs(vector<pair<int, float>>& v, int inicio, int fim, vector<pair<int, float>>& aux) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSortPairs(v, inicio, meio, aux);
        mergeSortPairs(v, meio + 1, fim, aux);
        mergePairs(v, inicio, meio, meio + 1, fim, 0, aux);

        for (int l = 0; l <= fim - inicio; ++l) {
            v[inicio + l] = aux[l];
        }
    }
}

void pairMergeSort(vector<pair<int, float>>& v) {
    vector<pair<int, float>> aux(v.size());
    mergeSortPairs(v, 0, v.size() - 1, aux);
}  

vector<vector<int>> greedy(int &n, int &m, std::vector<pair<int, float>> &arrayB, std::vector<std::vector<int>> &matrizT, std::vector<std::vector<int>> &matrizC){
    
    pairMergeSort(arrayB);
    cout << "Array B: ";
    for (const auto& pair : arrayB) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;

    vector<vector<pair<int, float>>> matrizCT;
    for (int i = 0; i < m; ++i) {
        vector<pair<int, float>> row;
        for (int j = 0; j < n; ++j) {
            float result = static_cast<float>(matrizC[i][j]) / matrizT[i][j];
            row.push_back(make_pair(j, result));
        }
        matrizCT.push_back(row);
    }
    
    for (auto& row : matrizCT) {
        pairMergeSort(row);
    }

    vector<vector<int>> greedySolution;
    float timeCost;
    int time;
    vector<int> jobs_used;
    int answer; // retorno busca binária
    
    for (int i = m-1; i >= 0; --i) {
            pair<int,float> itemB = arrayB[i];
            timeCost = itemB.second;
            vector<int> solution;
            vector<int> lastSolution;
            for(pair<int,float> &row: matrizCT[itemB.first]){
                time = matrizT[itemB.first][row.first];
                if((time <= timeCost) && (i == m-1)){
                    solution.push_back(row.first);
                    timeCost -= time;
                    jobs_used.push_back(row.first);
                }else{
                    answer = binary_search(jobs_used, row.first);
                    if(answer == 0){
                        if(time <= timeCost){
                            solution.push_back(row.first);
                            timeCost -= time;
                            jobs_used.push_back(row.first);
                        }
                        else if(time > timeCost && i==0){
                            lastSolution.push_back(row.first);
                        }
                    }
                }
            }
            greedySolution.push_back(solution);
            if(i==0){
                greedySolution.push_back(lastSolution);
            }
    }

    return greedySolution;
}
