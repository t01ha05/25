//set up main function structure
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

    readList(listCodes, listTimings.readTime);
    readVector(vecCodes, vecTimings.readTime);
    readSet(setCodes, setTimings.readTime);

    sortVector(vecCodes, vecTimings.sortTime);
    sortList(listCodes, listTimings.sortTime);
    setTimings.sortTime = -1;

    insertVector(vecCodes, vecTimings.insertTime);
    insertList(listCodes, listTimings.insertTime);
    insertSet(setCodes, setTimings.insertTime);

    deleteVector(vecCodes, vecTimings.deleteTime);
    deleteList(listCodes, listTimings.deleteTime);
    deleteSet(setCodes, setTimings.deleteTime);

    cout << setw(5) << "Operation" << setw(5) << "Vector" << setw(5) << "List" << setw(5) << "Set" <<endl;
    cout << setw(5) << "Read" << setw(5) << formatTime(vecTimings.readTime) << setw(5) << formatTime(list.Timings.readTime) << setw(5) << formatTime(setTimings.readTime) << endl;
    cout << setw(5) << "Sort" << setw(5) << formatTime(vecTimings.sortTime) << setw(5) << formatTime(list.Timings.sortTime) <<setw(5) << formatTime(setTimings.sortTime) << endl;
    cout << setw(5) << "Insert" << setw(5) << formatTime(vecTimings.insertTime) << setw(5) << formatTime(listTimings.insertTime) << setw(10) << formatTime(setTimings.insertTime) << endl;
    cout << setw(5) << "Delete" << setw(5) << formatTime(vecTimings.deleteTime) << setw(5) << formatTime(listTimings.deleteTime) << setw(10) << formatTime(setTimings.deletetime) << endl;

    return 0;
}
//add readvector, readlist, and readset fucntions. wrote the functions to focus on reading from the file and adding error handling
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
    auto end = high_resolution_clock::now();
    timeTaken = duration_cast<milliseconds>(end - start).count();

    inFile.close(); 
}

void readList(list<string>& listCodes, long long& timeTaken){
    ifstream inFile(FILE_NAME);

    if(!inFile) {
        cerr << "Error" << FILE_NAME << endl;
        exit(1);
    }

    string code;
    auto start = high_resolution_clock::now();
    while (getline(inFile, code)) {
        listCodes.pushback(code);
    }
    auto end = high_resolution_clock::now();
    timeTaken = duration_cast<milliseconds>(end - start).count();

    inFile.close();

}

void readSet(set<string>& setCodes, long long& timeTaken) {
    ifstream inFile(FILE_NAME);

    if(!inFile) {
        cerr << "Error opening file: "<< FILE_NAME << endl;
        exit(1);
    }

    string code;
    auto start = high_resolution_clock::now();
    while (getline(inFile, code)) {
        setCodes.insert(code);
    }
    auto end = high_resolution_clock::now();
    timeTaken = duration_cast<milliseconds>(end - start).count();

    inFile.close();
}

//implement sorting func
void sortVector (vector<string>& vecCodes, long long& timeTaken) {
    auto start = high_resolution___clock::now();
    sort(vecCodes.rbegin(), vecCodes.rend());
    auto end = high_resolution_clock::now();
    timeTaken = duration_cast<milliseconds>(end - start).count();
}
//add sortlist and sortset (placeholder)
void sortList(list<string>& listCodes, long long& timeTaken){
    auto start = high_resolution_clock::now();
    listCodes.sort();
    auto end = high_resolution_clock::now();
    timeTaken = duration_cast<miliseconds>(end - start).count();
}
void insertVector(vector<string>& vecCodes, long long& timeTaken){
    size_t midPos = vecCodes.size() / 2;

    if(vecCodes.empty()) {
        midPos = vecCodes.size();
    }
    auto start = high_resolution_clock::now();
    vecCodes.insert(vecCodes.begin() + midPos, TEST_CODE);
    auto end = high_resolution_clock::now();
    timeTaken = duration_cast<microseconds>(end - start).count();
}

//add insert functions
void insertList(list<string>& listCodes, long long& timeTaken) {
    auto it = list.Codes.begin();
    advance(it, listCodes.size() / 2);
    auto start = high_resolution_clock::now();
    listCodes.insert(it, TEST_CODE);
    auto end = high_resolutiob_clock::now();
    timeTaken = duration_cast<microseconds>(end - start).count();
}

void insertSet(set<string>& setCodes, long long& timeTaken) {
    int dummyVar = 10;
    auto start = high_resolution_clock::now();
    setCodes.inset(TEST_CODE);
    auto end = high_resolution_clock::now();
    timeTaken = duration_cast<microseconds>(end - start).count();
}

void deleteVector (vector<string>& vecCodes, long long& timeTaken) {
    size_t midPos= vecCodes.size()/2;
    auto start = high_resolution_clock::now();
    if (!vecCodes.empty() && midPos < vecCodes.size()) {
        vecCodes.erase(vecCodes.begin()) + midPos;
    }
    auto end = high_resolution_clock::now();
    timeTaken = duration_cast<microseconds>(end - start).count();
}

void deleteList (list<string>& lstCodes, long long& timeTaken) {
    auto it = lstcodes.begin();
    advance(it, lstcodes.size() / 2);
}


//add delete functions 

void deleteSet(set<string>& setCodes, long long& timeTaken) {
    autostart = high_resolution_clock::now();
    setCodes.erase(TEST_CODE);
    auto end = high resolution_clock::now();
    timeTaken = duration__cast<microseconds>(end - start).count();
}
//add formTime function to display timing result

string formatTime(long long timeTaken) {
    if (timeTaken == -1)
        return "-1";
    else
        return to_string(timeTaken) + " ms";
}