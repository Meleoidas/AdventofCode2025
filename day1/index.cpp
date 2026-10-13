#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

int main(){
  ifstream input("input");
  int pos = 50;
  int part1 = 0;
  int part2 = 0;
  string rot;

  while (input >> rot) {
    char dir = rot[0];
    int d = stoi(rot.substr(1));

    if (dir == 'R') {

      int t0 = 100 - pos;
      if (t0 == 0) t0 = 100;
      if (d >= t0) part2 += 1 + (d - t0) / 100;
      pos = (pos + d) % 100;
      
    } else if (dir == 'L') {

      int t0 = pos;
      if (t0 == 0) t0 = 100;
      if (d >= t0) part2 += 1 + (d - t0) / 100;
      pos = ( (pos-(d%100)) +100) % 100;

    }

    if (pos == 0) part1++;
  }

  cout << part1 << "\n" << part2 << "\n";
  return 0;
}