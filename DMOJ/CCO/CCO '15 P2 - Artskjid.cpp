#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 18, MIN_VALUE = -1e6;

int n, m;
vector<pair<int, int> > graph[MAX_N];
int dp[1 << MAX_N][MAX_N];
bool dp_solved[1 << MAX_N][MAX_N];

int dp_value(int mask, int place) {
  if(place == n - 1) return 0;
  if(dp_solved[mask][place]) return dp[mask][place];

  for(int i = 0; i < graph[place].size(); i++) {
    int next = graph[place][i].first;
    if(mask & (1 << next)) {
      dp[mask][place] = max(dp[mask][place], graph[place][i].second + dp_value(mask & ~(1 << next), next));
    }
  }

  dp_solved[mask][place] = true;
  return dp[mask][place];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int s, d, l;
    cin >> s >> d >> l;
    graph[s].push_back(make_pair(d, l));
  }

  memset(dp, MIN_VALUE, sizeof(dp));
  cout << dp_value(((1 << n) - 1) & ~(1), 0) << "\n";

  return 0;
}