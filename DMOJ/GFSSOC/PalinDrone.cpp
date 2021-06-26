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
  unsigned long long n;
  cin>>n;

  if (n==1) {
    cout<<"9"<<endl;
    return 0;
  }

  if (n==2) {
    cout<<"18"<<endl;
    return 0;
  }

  if (n==3) {
    cout<<"108"<<endl;
    return 0;
  }

  unsigned long long answer=0;
  if (n%2==0) {
    if ((n-2)/2>=9) {
      answer=999999998;
    }
    else {
      long long ones_num=0;
      for (int i=0; i<=(n-2)/2; i++) {
        ones_num+=pow(10,i);
      }
      answer=(ones_num)*18%1000000000;
    }
  }

  else {
    if ((n-2)/2>=9) {
      answer=999999998;
    }
    else {
      long long ones_num=0;
      for (int i=0; i<=(n-2)/2; i++) {
        ones_num+=pow(10,i);
      }
      answer=(ones_num)*18%1000000000;
    }
    if ((n-2)/2+1<=8) {
      answer+=9*pow(10,(n-2)/2+1);
    }
  }

  cout<<answer<<endl;

  return 0;
}