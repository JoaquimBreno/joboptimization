#include "greedy.h"
#include <iostream>
#include <vector>

using namespace std;

void mergeInt(vector<int>& v, int i, int meio, int j, int fim, int k, vector<int>& aux) {
    if (i <= meio && (j > fim || v[i] < v[j])) {
        aux[k] = v[i];
        mergeInt(v, i + 1, meio, j, fim, k + 1, aux);
    } else if (j <= fim) {
        aux[k] = v[j];
        mergeInt(v, i, meio, j + 1, fim, k + 1, aux);
    }
}

void mergeSortInt(vector<int>& v, int inicio, int fim, vector<int>& aux) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSortInt(v, inicio, meio, aux);
        mergeSortInt(v, meio + 1, fim, aux);
        mergeInt(v, inicio, meio, meio + 1, fim, 0, aux);

        for (int l = 0; l <= fim - inicio; ++l) {
            v[inicio + l] = aux[l];
        }
    }
}

void mergeSort(vector<int>& v) {
    vector<int> aux(v.size());
    mergeSortInt(v, 0, v.size() - 1, aux);
}

// int main() {
//     vector<int> a = {10, 2, 7, 1, 4, 9, 3, 8, 0, 5, 6};
//     mergeSort(a);
//     for (int num : a) {
//         cout << num << " ";
//     }
//     cout << endl;
//     return 0;
// }

vector<vector<int>> greedy(int &n, int &m, int &p, std::vector<int> &arrayB, std::vector<std::vector<int>> &matrizT, std::vector<std::vector<int>> &matrizC){

    mergeSort(arrayB);
    cout << "Array B: ";
    for (int val : arrayB) {
        cout << val << " ";
    }
    cout << endl;

    vector<vector<pair<int, float>>> matrizCT;
    for (size_t i = 0; i < matrizT.size(); ++i) {
        vector<pair<int, float>> row;
        for (size_t j = 0; j < matrizT[i].size(); ++j) {
            float result = static_cast<float>(matrizC[i][j]) / matrizT[i][j];
            row.push_back(make_pair(j, result));
        }
        matrizCT.push_back(row);
    }

    for (const auto& row : matrizCT) {
        for (const auto& pair : row) {
            cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        cout << endl;
    }

}
