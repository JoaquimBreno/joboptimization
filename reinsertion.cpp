#include "reinsertion.h"
#include <iostream>
#include <vector>
#include <algorithm> 

#include "CostTimeServer.h"

using namespace std;

vector<vector<int>> reinsertion(vector<vector<int>>& solution, vector<vector<int>>& matrizT, vector<vector<int>>& matrizC, vector<pair<int, float>>& arrayB, vector<CostTimeServer>& costTimeServers){
    vector<vector<int>> new_solution;
    /** if i have an a array solution like [[1 2 3][5][6 7]] just make random swappings like [[1 2][5 3][6 7]]*/
    for (const auto& group : solution) {
        if (group.size() > 1) {
            vector<int> new_group = group;
            new_solution.push_back(new_group);
        } else {
            new_solution.push_back(group);
        }
    }


    return new_solution;
}