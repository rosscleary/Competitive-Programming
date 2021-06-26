#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> s(N), d(N);
	for(int i = 0; i < N; i++) {
    cin >> s[i] >> d[i];
  }
  
  int best_freq_overall = -1, time_ans, dist_ans;
  for(int time = 1; time <= 4; time++) {
    map<int, int> dist_freq;
    for(int i = 0; i < N; i++) {
      dist_freq[s[i] + time * d[i]]++;
    }
    int best_freq = -1, dist_best;
    for(auto i: dist_freq) {
      if(i.second > best_freq) {
        best_freq = i.second, dist_best = i.first;
      }
    }
    if(best_freq > best_freq_overall) {
      best_freq_overall = best_freq, time_ans = time, dist_ans = dist_best;
    }
  }

  cout << best_freq_overall << ' ' << time_ans << ' ' << dist_ans << '\n';
	
  return 0;
}