#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  
  if(n == 1) {
    cout << "69" << endl;
    return;
  }
  if(n == 2) {
    cout << "420" << endl;
    return;
  }
  
  vector<int> digit_count(200);
  digit_count[2] = 1;
  digit_count[3] = 1;

  int total = 2;
  int last = 2;
  string ans = "";
  
  for(int len = 4; ; len++) {
    digit_count[len] = digit_count[len - 2] + digit_count[len - 3];
    total += digit_count[len];
    if(total >= n) {
      int diff = n - last;
      int len_rem = len;
      while(len_rem > 0) {
        if (len_rem == 2) {
          ans += "69";
          break;
        }
        if (len_rem == 3) {
          ans += "420";
          break;
        }
        if(digit_count[len_rem - 3] < diff) {
          diff -= digit_count[len_rem - 3];
          ans += "69";
          len_rem -= 2;
        } else {
          ans += "420";
          len_rem -= 3;
        }
      }
      break;
    }
    last = total;
  }

  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
}