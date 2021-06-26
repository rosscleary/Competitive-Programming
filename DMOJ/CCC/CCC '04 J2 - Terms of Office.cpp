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
using namespace std;

int main () {

  int X,Y;
  cin>>X>>Y;

  for (int i=X; i<=Y; i+=60) {
    cout<<"All positions change in year "<<i<<endl;
  }

  return 0;

}