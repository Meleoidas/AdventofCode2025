#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream input("input");
    long long rez1;
    string str;
    vector<pair<long long, long long>> vec;
    while(input >> str) {
        istringstream ss(str);
        long long a, b;
        char c;
        ss >> a >> c >> b;
        vec.push_back({a, b});
    }

    vector<long long> sizes;
    for(long long i = 0; i < vec.size(); i++){
        pair<long long, long long> p1 = vec[i];
        for (long long j = i; j < vec.size(); j++) {
            pair<long long, long long> p2 = vec[j];
            long long s = (abs((p1.first - p2.first)) + 1) * (abs(p1.second - p2.second) + 1);
            sizes.push_back(s);
        }
    }
    sort(sizes.rbegin(), sizes.rend());
    rez1 = sizes[0];

    for(long long i = 0; i < 10; i++) {
        cout << sizes[i] << " ";
    }
    cout << endl;

    cout << rez1;
}