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

#define ll long long

const ll mod=1000000007;
const string alph_l("abcdefghijklmnopqrstuvwxyz");
const string alph_c("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

int main () {

  int N,V;
  scanf("%d%d",&N,&V);

  int coin_values[2005];

  for (int i=1; i<=N; i++)
  {
    scanf("%d",&coin_values[i]);
  }

  int max_amount=INT_MIN;

  map<int,vector<pair<int,int> > > q_list;

  for (int i=1; i<=V; i++)
  {
    int c,l;
    scanf("%d%d",&c,&l);
    q_list[l].push_back(make_pair(c,i));
    max_amount=max(max_amount,c);
  }

  int dp[10005];
  memset(dp,-1,sizeof(dp));
  dp[0]=0;

  int q_values[100005];
  for (int coin=1; coin<=N; coin++)
  {
    int curr_value=coin_values[coin];
    for (int amount=curr_value; amount<=max_amount; amount++)
    {
      int dp_solve=dp[amount];
      if (dp_solve==-1)
      {
        dp_solve=INT_MAX;
      }
      if (dp[amount-curr_value]!=-1)
      {
        dp_solve=min(dp_solve,dp[amount-curr_value]+1);
      }
      if (dp_solve==INT_MAX)
      {
        dp[amount]=-1;
      }
      else
      {
        dp[amount]=dp_solve;
      }
    }
    for (int i=0; i<q_list[coin].size(); i++)
    {
      q_values[q_list[coin][i].second]=dp[q_list[coin][i].first];
    }
  }

  for (int i=1; i<=V; i++)
  {
    printf("%d\n",q_values[i]);
  }

  return 0;

}