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

void readVector(vector<string>& vecCodes, long long& timeTaken) {
    ifstream inFile(FILE_NAME);

    if (!inFile) {
        cerr << "Error opening file: " << FILE_NAME << endl;
        exit(1);

    }
    string code;
    auto start = high_resolution_clock::now();
    while (getline(inFile, code)) {
        vecCodes.push_back(code);
}
void sortVector (vector<string>& vecCodes, long long& timeTaken) {
    auto start = high_resolution___clock::now();
    sort(vecCodes.rbegin(), vecCodes.rend());
    auto end = high_resolution_clock::now();
    timeTaken = duration_cast<milliseconds>(end - start).count();
}

