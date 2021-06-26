#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int m;
int n;
int coins[10];
int mem[101];

int min_coins(int);

int main () {

for (int i=1; i<=5; i++) {

memset(mem,0,sizeof(mem));

cin>>m;
cin>>n;

for (int ii=0; ii<=n-1; ii++)
cin>>coins[ii];

sort(coins,coins+n);

cout<<min_coins(m)<<endl;

}

return 0;

}

int min_coins(int amount_left) {

if (amount_left==0)
  return 0;

if (mem[amount_left])
  return mem[amount_left];

int smallest=1000000000;

for (int i=0; i<=n-1; i++) {

if (coins[i]<=amount_left) {

int result=1+min_coins(amount_left-coins[i]);

if (result<smallest)
  smallest=result;

}

else
  break;

}

mem[amount_left]=smallest;
return smallest;

}