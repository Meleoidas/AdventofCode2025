#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ifstream input("input");
  string str;
  long long rez1 = 0, rez2 = 0;
  
  vector<pair<long long, long long>> ranges;
  while(getline(input, str) && str != "") {
    int dashPos = str.find('-');
    long long a = stoll(str.substr(0, dashPos));
    long long b = stoll(str.substr(dashPos+1));
    ranges.push_back({a, b});
  }
  
  sort(ranges.begin(), ranges.end());
  
  vector<pair<long long, long long>> merged;
  for(auto& range : ranges) {
    if(merged.empty() || merged.back().second < range.first - 1) {
      merged.push_back(range);
    } else {
      merged.back().second = max(merged.back().second, range.second);
    }
  }

  // p1
  while(getline(input, str)) {
    long long id = stoll(str);
    
    for(auto& range : merged) {
      if(id >= range.first && id <= range.second) {
        rez1++;
        break;
      }
    }
  }

  // p2
  for(auto range: merged) {
    rez2 += range.second - range.first + 1;
  }

  cout << rez1 << endl << rez2;
}

