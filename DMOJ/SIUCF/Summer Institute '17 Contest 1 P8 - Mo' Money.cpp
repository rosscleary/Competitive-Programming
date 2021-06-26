#include <iostream>
using namespace std;

int num_ways(int amount_left, int coins[], int coin_num) {

if (coin_num==0 && amount_left==0)
    return 1;

if (amount_left==0)
    return 1;
    
if (coin_num==0)
    return 0;
    
return num_ways(amount_left-coins[coin_num-1],coins,coin_num-1) + num_ways(amount_left,coins,coin_num-1);

}

int main () {

int amount_left;
int num_coins;
int *coins;

cin>>num_coins;
cin>>amount_left;

int coin_num=num_coins;

coins=new int[num_coins];

for (int i=0; i<=num_coins-1; i++)
cin>>coins[i];

cout<<num_ways(amount_left,coins,coin_num)<<endl;
    
return 0;
}