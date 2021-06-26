#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;

bool prefix_free(string[3]);
bool suffix_free(string[3]);

int main () {

  int n;
  cin>>n;

  for (int i=1; i<=n; i++) {
    string words[3];
    cin>>words[0]>>words[1]>>words[2];
    if (prefix_free(words) && suffix_free(words)) {
      cout<<"Yes"<<endl;
    }
    else {
      cout<<"No"<<endl;
    }
  }

  return 0;

}

bool prefix_free(string words[3]) {

  for (int i=0; i<=1; i++) {
    for (int j=i+1; j<=2; j++) {
      if (words[i]==words[j]) {
        return false;
      }
      if (words[i].length()>words[j].length()) {
        if (words[i].substr(0,words[j].length())==words[j]) {
          return false;
        }
      }
      else {
        if (words[j].substr(0,words[i].length())==words[i]) {
          return false;
        }
      }
    }
  }

  return true;

}

bool suffix_free(string words[3]) {

  for (int i=0; i<=1; i++) {
    for (int j=i+1; j<=2; j++) {
      if (words[i]==words[j]) {
        return false;
      }
      if (words[i].length()>words[j].length()) {
        if (words[i].substr(words[i].length()-words[j].length(),words[j].length())==words[j]) {
          return false;
        }
      }
      else {
        if (words[j].substr(words[j].length()-words[i].length(),words[i].length())==words[i]) {
          return false;
        }
      }
    }
  }

  return true;

}