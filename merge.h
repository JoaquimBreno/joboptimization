#ifndef MERGE_H
#define MERGE_H
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Definindo um template para o mergePairs, agora aceitando um comparador genérico
template<typename T, typename Compare>
void mergePairs(vector<T>& v, int i, int meio, int j, int fim, int k, vector<T>& aux, Compare comp) {
    if (i <= meio && (j > fim || comp(v[i], v[j]))) {
        aux[k] = v[i];
        mergePairs(v, i + 1, meio, j, fim, k + 1, aux, comp);
    } else if (j <= fim) {
        aux[k] = v[j];
        mergePairs(v, i, meio, j + 1, fim, k + 1, aux, comp);
    }
}

// Mesma adaptação para a função mergeSortPairs, aceitando um comparador
template<typename T, typename Compare>
void mergeSortPairs(vector<T>& v, int inicio, int fim, vector<T>& aux, Compare comp) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSortPairs(v, inicio, meio, aux, comp);
        mergeSortPairs(v, meio + 1, fim, aux, comp);
        mergePairs(v, inicio, meio, meio + 1, fim, 0, aux, comp);

        for (int l = 0; l <= fim - inicio; ++l) {
            v[inicio + l] = aux[l];
        }
    }
}

// Generalizando a função pairMergeSort para utilizar qualquer tipo e comparador
template<typename T, typename Compare>
void genericMergeSort(vector<T>& v, Compare comp) {
    
    vector<T> aux(v.size());
    mergeSortPairs(v, 0, v.size() - 1, aux, comp);
}
// MERGE GENERIC

#endif // "MERGE_H"