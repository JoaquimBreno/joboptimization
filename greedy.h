#ifndef GREEDY_H
#define GREEDY_H

#include <vector>
#include "CostTimeServer.h"
#include "merge.h"

using namespace std;

vector<vector<int>> greedy(int &n, int &m, vector<CostTimeServer> &servers, vector<vector<int>> &matrizT, vector<vector<int>> &matrizC);

#endif // GREEDY_H