#ifndef JOBS_H
#define JOBS_H

struct CostTimeServer {
    int id;
    

    CostTimeServer() : id(0), timeMax(0.0f), costUsed(0.0f), timeUsed(0.0f) {}

    CostTimeServer(int id_val, float timeMax_val, float costUsed_val = 0.0f, float timeUsed_val = 0.0f)
        : id(id_val), costUsed(costUsed_val), timeUsed(timeUsed_val), timeMax(timeMax_val) {}
};

#endif // COSTTIMESERVER_H
