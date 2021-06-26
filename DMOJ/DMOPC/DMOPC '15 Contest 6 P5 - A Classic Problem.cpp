#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;
  vector<int> arr(N);
  for(int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int j = 0;
  multiset<int> curr_arr;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    curr_arr.insert(arr[i]);
    while(curr_arr.size() >= 2 && *curr_arr.rbegin() - *curr_arr.begin() > K) {
      curr_arr.erase(curr_arr.find(arr[j]));
      j++;
    }
    ans += i - j + 1;
  }

  cout << ans << '\n';

  return 0;
}