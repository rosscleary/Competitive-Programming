#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int distinct_cnt = 0;
  vector<int> freq(N + 1);
  int i = -1;
  for(int j = 0; j < N; j++) {
    freq[a[j]]++;
    if(freq[a[j]] == 1) {
      distinct_cnt++;
    }
    if(distinct_cnt == K) {
      i = j;
      break;
    }
  }

  if(i == -1) {
    cout << "0\n";
    return 0;
  }

  int j = 0;
  int ans = 0;
  freq[a[i]]--, distinct_cnt--;
  for(; i < N; i++) {
    freq[a[i]]++;
    if(freq[a[i]] == 1) {
      distinct_cnt++;
    }
    while(distinct_cnt >= K) {
      freq[a[j]]--;
      if(freq[a[j]] == 0) {
        distinct_cnt--;
      }
      j++;
    }
    ans += j;
  }

  cout << ans << '\n';

  return 0;
}