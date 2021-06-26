#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;

int t;

pair <int,int> cost_values[6][1001]={make_pair(0,0)};

int b;

int min_lefts[6]={0};

int dp[6][3000001];
bool did_mem[6][3000001]={false};

int max_value(int type_on, int money_left) {

if (did_mem[type_on][money_left]) {
  return dp[type_on][money_left];
}

if (type_on>t) {
  return 0;
}

int best_option=0;

for (int i=0; cost_values[type_on][i].first!=0; i++) {
  if (money_left-cost_values[type_on][i].first>=min_lefts[type_on]) {
    int result=cost_values[type_on][i].second+max_value(type_on+1,money_left-cost_values[type_on][i].first);
    if (result>best_option) {
      best_option=result;
    }
  }
}

did_mem[type_on][money_left]=true;
dp[type_on][money_left]=best_option;
return best_option;

}

int main () {

cin>>t;

int n;
cin>>n;

int mins[6];

for (int i=0; i<=5; i++) {
  mins[i]=1000000000;
}

int cost,value,type;

int type_counter[6]={0};

for (int i=1; i<=n; i++) {
  cin>>cost>>value>>type;
  cost_values[type][type_counter[type]]=make_pair(cost,value);
  type_counter[type]++;
  if (cost<mins[type]) {
    mins[type]=cost;
  }
}

for (int i=1; i<=t-1; i++) {
  for (int ii=i+1; ii<=t; ii++) {
    min_lefts[i]+=mins[ii];
  }
}

min_lefts[t]=0;

int b;
cin>>b;

int answer=max_value(1,b);

if (answer==0) {
  cout<<"-1"<<endl;
}
else {
  cout<<answer<<endl;
}

return 0;

}