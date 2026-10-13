#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
  ifstream input("input");
  long long rez1=0, rez2=0;
  string str;
  vector<vector<string>> vec;

  while(getline(input, str)) {
    istringstream line(str);
    vector<string> temp;
    string part;
    while(line >> part){
      temp.push_back(part);
    }
    vec.push_back(temp);
  }

  // p1
  for(int j=0; j<vec[0].size(); j++){
    long long temp=0;
    for(int i=0; i<vec.size()-1; i++) {
      if(temp == 0) temp = (vec[vec.size() - 1][j] == "+") ? 0 : 1;
      temp = (vec[vec.size() - 1][j] == "+") ? temp+stoi(vec[i][j]) : temp*stoi(vec[i][j]);
    }
    rez1 += temp;
  }

  // p2
  vector<vector<vector<int>>> ints;
  for(int j=0; j<vec[0].size(); j++){
    vector<vector<int>> temp;
    for(int i=0; i<vec.size()-1; i++){
      vector<int> temp2;
      int t = stoi(vec[i][j]);
      while(t) {
        temp2.push_back(t%10);
        t /= 10;
      }
      temp.push_back(temp2);
    }
    ints.push_back(temp);
  }

  for(int i=0; i<ints.size(); i++) {
    long long temp;
    for(int k=0; k<ints[i][0].size(); k++) {
      for(int j=0; j<ints[i].size(); j++) {
        if(0 <= ints[i][j][k] && ints[i][j][k] <= 9) cout << ints[i][j][k];
      }
      cout << endl;
    }
    cout << endl;
  }

  // cout << rez1 << endl << rez2;
}