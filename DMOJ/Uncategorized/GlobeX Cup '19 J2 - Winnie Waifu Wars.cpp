#include <iostream>
#include <algorithm>
using namespace std;

long long int pow_levels[7][11];

long long int max_power(int current, int upgrades_left) {

if (current>6)
  return 0;

long long int best_option=0;

for (int i=1; i<=min(upgrades_left+1,10); i++) {

long long int result=max_power(current+1,upgrades_left-i+1) + pow_levels[current][i];

if (result>best_option)
  best_option=result;

}

return best_option;

}


int main () {

long long int n;
long long int m;

cin>>n;
cin>>m;

long long int a;
long long int b;

cin>>a;
cin>>b;

for (int i=1; i<=6; i++) {

for (int ii=1; ii<=10; ii++)
cin>>pow_levels[i][ii];

}

long long int num_upgrades=min(n/a,m/b);

cout<<max_power(1,num_upgrades)<<endl;

return 0;

}