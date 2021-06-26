#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;

int main () {
  int n;
  scanf("%d",&n);
  string names_1[31];
  string names_2[31];
  for (int i=1; i<=n; i++) {
    cin>>names_1[i];
  }
  for (int i=1; i<=n; i++) {
    cin>>names_2[i];
  }
  bool good=true;
  map <string,string> partners;
  for (int i=1; i<=n; i++) {
    if (names_1[i]==names_2[i]) {
      good=false;
      break;
    }
    if (partners[names_2[i]]!="") {
      if (names_1[i]!=partners[names_2[i]]) {
        good=false;
        break;
      }
    }
    else {
      partners[names_1[i]]=names_2[i];
    }
  }
  if (good) {
    printf("good");
  }
  else {
    printf("bad");
  }
}