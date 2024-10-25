#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>

using namespace std;

int main() {
    vector<string> vecCodes;
    list<string> listCodes;
    set<string> setCodes;
    
    struct Timings {
        long long readTime;
        long long sortTime;
        long long insertTime;
        long long deleteTime;
    };

    Timings vecTimings = {0, 0, 0, 0};
    Timings listTimings = {0, 0, 0, 0};
    Timings setTimings = {0, 0, 0 ,0};

    return 0;
}

