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
#include <climits>
#define ll long long
using namespace std;

int main () {

  string str_1,str_2;
  cin>>str_1>>str_2;

  if (str_1.length()!=str_2.length()) {
    printf("N\n");
    return 0;
  }

  map<char,int> lett_freq;
  for (int i=0; i<str_1.size(); i++) {
    lett_freq[str_1[i]]++;
  }

  map<char,int> lett_freq_2;
  for (int i=0; i<str_2.length(); i++) {
    if (str_2[i]!='*') {
      lett_freq_2[str_2[i]]++;
      if (lett_freq_2[str_2[i]]>lett_freq[str_2[i]]) {
          printf("N\n");
          return 0;
      }
    }
  }

  printf("A\n");

  return 0;

}