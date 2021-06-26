#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;

bool is_prime(int);
vector <bool> primes(10000);

int main () {

  int n,m;
  cin>>n>>m;

  vector <int> costs(m+1);
  for (int i=1; i<=m; i++) {
    cin>>costs[i];
  }

  vector <bool> dp(10000);

  for (int money_amount=0; money_amount<=n; money_amount++) {

    for (int item_amount=2; item_amount*costs[m]<=money_amount; item_amount++) {

      if (is_prime(item_amount)) {
        dp[money_amount]=true;
        break;
      }

    }

  }

  for (int item=m-1; item>=1; item--) {

    vector <bool> new_dp(10000);

    for (int money_amount=0; money_amount<=n; money_amount++) {

      for (int item_amount=2; item_amount*costs[item]<=money_amount; item_amount++) {

        if ((primes[item_amount] || is_prime(item_amount)) && dp[money_amount-(costs[item]*item_amount)]) {
          new_dp[money_amount]=true;
          break;
        }

      }

    }

    dp=new_dp;

  }

  if (dp[2]) {
    cout<<"its primetime"<<endl;
    return 0;
  }

  for (int amount_used=3; amount_used<=n; amount_used+=2) {
    if ((primes[amount_used] || is_prime(amount_used)) && dp[amount_used]) {
      cout<<"its primetime"<<endl;
      return 0;
    }
  }

  cout<<"not primetime"<<endl;

  return 0;

}

bool is_prime(int x) {

  if (x==2) {
    primes[2]=true;
    return true;
  }

  if (x%2==0) {
    return false;
  }

  for (int i=3; i<=sqrt(x); i+=2) {
    if (x%i==0) {
      return false;
    }
  }

  primes[x]=true;
  return true;

}