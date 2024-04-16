#include <iostream>
#include <vector>
#include "greedy.h"

using namespace std;

void lerEntradas(int &n, int &m, int &p, vector<pair<int, float>> &arrayB, vector<vector<int>> &matrizT, vector<vector<int>> &matrizC) {
    // Lendo as entradas
    cin >> n; // Número de jobs
    cin >> m; // Número de servidores
    cin >> p; // Alguma métrica (por exemplo, tempo ou custo)

    int temp;
    // Lendo o array B
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        arrayB.push_back(make_pair(i, temp));   
    }

    // Lendo a matriz T
    for (int i = 0; i < m; ++i) {
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            row.push_back(temp);
        }
        matrizT.push_back(row);
    }

    // Lendo a matriz C
    for (int i = 0; i < m; ++i) {
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            row.push_back(temp);
        }
        matrizC.push_back(row);
    }
}

int main() {
    int n, m, p;
    vector<pair<int, float>>  arrayB;
    vector<vector<int>> matrizT;
    vector<vector<int>> matrizC;

    lerEntradas(n, m, p, arrayB, matrizT, matrizC);
    // Exibindo as entradas lidas (apenas para verificação)
    cout << "Array B: ";
    for (const auto &pair : arrayB) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;

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

    greedy(n, m, p, arrayB, matrizT, matrizC);
    
    return 0;
}
