#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  set<int> fav_nums;
  map<int, int> num_freq;
  while(N--) {
    int fav_num;
    cin >> fav_num;
    fav_nums.insert(fav_num);
    num_freq[fav_num]++;
  }

  int Q;
  cin >> Q;
  while(Q--) {
    int query;
    cin >> query;
    int ans = *fav_nums.lower_bound(query);
    cout << ans << ' ' << num_freq[ans] << '\n';
  }

  return 0;
}