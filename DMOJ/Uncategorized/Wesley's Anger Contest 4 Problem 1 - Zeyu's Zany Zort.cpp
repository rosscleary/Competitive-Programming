#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double

#define fast_inputandoutput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

// ---------- END OF TEMPLATE ---------- //

const int M1 = 2e2 + 5;

int N, a[M1];
int Q;

int32_t main() { fast_inputandoutput

  cin >> N >> Q;
  for(int i = 1; i <= N; i++) cin >> a[i];

  while(Q--) {
    int type, l, r; cin >> type >> l >> r;
    vector<int> new_range;
    for(int i = l; i <= r; i++) new_range.push_back(a[i]);
    sort(new_range.begin(), new_range.end());
    if(type == 1) {
      int real_index = l;
      for(int i = 0; i < new_range.size(); i++) {
        a[real_index] = new_range[i];
        real_index++;
      }
    } else {
      int real_index = l;
      for(int i = new_range.size() - 1; i >= 0; i--) {
        a[real_index] = new_range[i];
        real_index++;
      }
    }
  }

  for(int i = 1; i < N; i++) cout << a[i] << " ";
  cout << a[N] << endl;

  return 0;
}