#ifndef COSTTIMESERVER_H
#define COSTTIMESERVER_H

struct CostTimeServer {
    int id;
    float costUsed = 0.0f;
    float timeUsed = 0.0f;
    float timeMax;
    int numSolutions = 0;

    CostTimeServer() : id(0), timeMax(0.0f), costUsed(0.0f), timeUsed(0.0f) {}

    CostTimeServer(int id_val, float timeMax_val, float costUsed_val = 0.0f, float timeUsed_val = 0.0f)
        : id(id_val), costUsed(costUsed_val), timeUsed(timeUsed_val), timeMax(timeMax_val) {}
};

#endif // COSTTIMESERVER_H
