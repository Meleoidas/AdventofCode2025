#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int>> vec;
vector<string> grid;
int i=0, j=0, len, rez1=0, rez2=0;

void addup() {
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      if (di == 0 && dj == 0) continue;
      int ni = i + di, nj = j + dj;
      if (0 <= ni && ni < len && 0 <= nj && nj < len)
        vec[ni][nj]++;
    }
  }
}

void remove(int m, int n){
  grid[m][n] = '.';
  rez2++;
  for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      if (di == 0 && dj == 0) continue;
      int ni = m + di, nj = n + dj;
      if (0 <= ni && ni < len && 0 <= nj && nj < len && grid[ni][nj]=='@') {
        vec[ni][nj]--;
        if(vec[ni][nj]<4) remove(ni, nj);
      }
    }
  }
}

int main(){
  ifstream input("input");
  string str;

  while(getline(input, str)) {
    grid.push_back(str);
  }

  len = grid.size();
  for(int i = 0; i < len; i++) {
    vector<int> row(grid[i].length(), 0);
    vec.push_back(row);
  }

  // p1
  for(int row = 0; row < grid.size(); row++) {
    for(int col = 0; col < grid[row].length(); col++) {
      if(grid[row][col] == '@') {
        i = row;
        j = col;
        addup();
      }
    }
  }

  for(int m=0; m < vec.size(); m++){
    for(int n=0; n < vec[m].size(); n++) {
      if(vec[m][n]<4 && grid[m][n] == '@') rez1++;
    }
  }

  // p2
  for(int m=0; m < vec.size(); m++){
    for(int n=0; n < vec[m].size(); n++) {
      if(vec[m][n]<4 && grid[m][n] == '@') {
        remove(m, n);
      }
    }
  }

  cout << rez1 << endl << rez2;
}