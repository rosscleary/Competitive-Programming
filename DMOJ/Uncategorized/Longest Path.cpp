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

map<int,vector<int> > graph;
int dp[100005]={0};
bool dp_solved[100005]={false};

int dfs (int curr) {

  if (dp_solved[curr]) {
    return dp[curr];
  }

  if (graph[curr].size()==0) {
    dp[curr]=0;
    dp_solved[curr]=true;
    return 0;
  }

  for (int i=0; i<graph[curr].size(); i++) {
    dp[curr]=max(dp[curr],dfs(graph[curr][i])+1);
  }

  dp_solved[curr]=true;
  return dp[curr];

}

int main () {

  int N,M;
  scanf("%d%d",&N,&M);

  for (int i=0,x,y; i<M; i++) {
    scanf("%d%d",&x,&y);
    graph[x].push_back(y);
  }

  int longest_path=0;
  for (int i=1; i<=N; i++) {
    if (!dp_solved[i]) {
      dfs(i);
    }
    longest_path=max(longest_path,dp[i]);
  }

  printf("%d\n",longest_path);

  return 0;

}