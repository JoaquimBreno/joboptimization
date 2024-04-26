#ifndef VND_H
#define VND_H

#include <vector>
#include "swap.h"
#include "realoca.h"
#include "CostTimeServer.h"

using namespace std;

void vndFunction(vector<CostTimeServer>& servers, vector<vector<int>>& solution, vector<vector<int>> &matrizT, vector<vector<int>> &matrizC, int m, int n, int p);

#endif // VND_H