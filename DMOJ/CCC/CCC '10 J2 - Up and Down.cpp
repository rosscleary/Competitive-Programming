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

  int a,b,c,d,s;
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&s);
  int nikky=(s/(a+b))*(a-b);
  if (s%(a+b)<=a) {
    nikky+=s%(a+b);
  }
  else {
    nikky+=a-(s%(a+b)-a);
  }

  int byron=(s/(c+d))*(c-d);
  if (s%(c+d)<=a) {
    byron+=s%(c+d);
  }
  else {
    byron+=c-(s%(c+d)-c);
  }

  if (nikky>byron) {
    printf("Nikky\n");
  }
  else {
    if (byron>nikky) {
      printf("Byron\n");
    }
    else {
      printf("Tied\n");
    }
  }


  return 0;

}