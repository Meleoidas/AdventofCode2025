#include <iostream>
#include <string>
#include <fstream>
using namespace std;

unsigned long long calcJolt(string line, int nr){
  int l = line.length(), ind=0, k=0;
  unsigned long long rez = 0;
  do {
    for(int i=ind; i<l-nr+1; i++) {
      if(line[i]-'0' > k) {
        k = line[i]-'0';
        ind = i+1;
      }
    }
    rez = rez*10+k;
    k=0;
  } while (--nr);
  return rez;
}

int main () {
  ifstream input("input");
  string line;
  unsigned long long rez1=0, rez2=0;
  while(input >> line) {
    int k1 = line[0]-'0', k2 = line[1]-'0';
    int l = line.length();

    // p1
    for(int i=1; i<l; i++){
      if(line[i]-'0' > k1 && i<l-1) {
        k1 = line[i]-'0';
        k2 = line[i+1]-'0';
      } else if (line[i]-'0' > k2) {
        k2 = line[i]-'0';
      }
    }
    rez1 += k1*10+k2;

    // p2
    rez2 += calcJolt(line, 12);
  }
  cout << rez1 << endl << rez2;
}