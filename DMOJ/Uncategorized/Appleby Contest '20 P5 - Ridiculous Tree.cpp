#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> factorial_cnt;
int max_factorial = -1;

int solve(int curr) {
  int cnt = 0;
  for(auto i: adj[curr]) {
    int next = solve(i);
    if(cnt > 0) {
      factorial_cnt[cnt + next]++, factorial_cnt[cnt]--, factorial_cnt[next]--;
      max_factorial = max(max_factorial, cnt + next);
    }
    cnt += next;
  }

  return cnt + 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  adj.resize(N + 1);
  for(int i = 2; i <= N; i++) {
    int p_i;
    cin >> p_i;
    adj[p_i].push_back(i);
  }

  factorial_cnt.resize(N + 2), solve(1);
  for(int i = N; i > 1; i--) {
    factorial_cnt[i] += factorial_cnt[i + 1];
  }
  vector<int> ans(N + 1);
  for(int i = 2; i <= max_factorial; i++) {
    int value_remain = i;
    for(int div = 2; div * div <= value_remain; div++) {
      while(value_remain % div == 0) {
        value_remain /= div, ans[div] += factorial_cnt[i];
      }
    }
    if(value_remain != 1) {
      ans[value_remain] += factorial_cnt[i];
    }
  }

  vector<pair<int, int>> output_ans;
  for(int i = 1; i <= N; i++) {
    if(ans[i] > 0) {
      output_ans.push_back({i, ans[i]});
    }
  }
  cout << output_ans.size() << '\n';
  for(auto i: output_ans) {
    cout << i.first << ' ' << i.second << '\n';
  }

  return 0;
}