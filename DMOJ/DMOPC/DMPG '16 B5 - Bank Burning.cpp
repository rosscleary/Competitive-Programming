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
  int m,n;
  cin>>m>>n;
  double safe_amounts[100000];
  double money_sum=m;
  for (int i=0; i<n; i++) {
    cin>>safe_amounts[i];
    money_sum+=safe_amounts[i];
  }
  sort(safe_amounts,safe_amounts+n);
  int burn_counter=0;
  for (int i=n-1; i>=0; i--) {
    double current=money_sum/(i+2);
    double possible_change=(money_sum-safe_amounts[i])/(i+1);
    if (possible_change<current) {
      burn_counter++;
      money_sum-=safe_amounts[i];
    }
    else {
      break;
    }
  }
  cout<<burn_counter<<endl;
}