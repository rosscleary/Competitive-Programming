#include <bits/stdc++.h>
using namespace std;

#define int long long

int N;
vector<int> b;

int solve_dist(int dist, int size) {
  vector<int> freq(N + 1);
  for(int i = 0; i < size; i++) {
    freq[b[i]]++;
  }

  int correct_cnt = 0, ans = 0;
  for(int i = 1; i <= N; i++) {
    if(freq[i] > 0) {
      correct_cnt += freq[i] == dist;
    }
  }
  ans += correct_cnt == dist;
  for(int i = 1, j = size; j < N; i++, j++) {
    int remove_freq = freq[b[i - 1]], add_freq = freq[b[j]];
    freq[b[i - 1]]--, freq[b[j]]++;
    correct_cnt += remove_freq != dist && freq[b[i - 1]] == dist, correct_cnt -= remove_freq == dist && freq[b[i - 1]] != dist;
    correct_cnt += add_freq != dist && freq[b[j]] == dist, correct_cnt -= add_freq == dist && freq[b[j]] != dist;
    ans += correct_cnt == dist;
  }

  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N;
  b.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> b[i];
  }

  int ans = 0;
  for(int dist = 1; dist * dist <= N; dist++) {
    ans += solve_dist(dist, dist * dist);
  }

  cout << ans << '\n';

  return 0;
}