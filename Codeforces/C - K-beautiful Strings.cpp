#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n, k;
  string s;
  cin >> n >> k >> s;
 
  vector<int> freq(26);
  for(auto i: s) {
    freq[i - 'a']++;
  }
 
  bool same_valid = true;
  for(int i = 0; i < 26; i++) {
    if(freq[i] % k) {
      same_valid = false;
      break;
    }
  }
  if(same_valid) {
    cout << s << '\n';
    return;
  }
 
  for(int i = n - 1; i >= 0; i--) {
    for(char j = s[i] + 1; j <= 'z'; j++) {
      freq[j - 'a' - 1]--, freq[j - 'a']++;
 
      int left = n - 1 - i;
      vector<int> add(26);
      for(int l = 0; l < 26; l++) {
        add[l] = (k - freq[l] % k) % k, left -= add[l];
        if(left < 0) {
          break;
        }
      }
 
      if(left >= 0 && left % k == 0) {
        for(int l = 0; l < i; l++) {
          cout << s[l];
        }
        cout << j;
        for(int l = 0; l < left; l++) {
          cout << 'a';
        }
        for(char l = 'a'; l <= 'z'; l++) {
          for(int m = 0; m < add[l - 'a']; m++) {
            cout << l;
          }
        }
        cout << '\n';
        return;
      }
    }
 
    freq['z' - 'a']--;
  }
 
  cout << "-1\n";
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int T;
  cin >> T;
  while(T--) {
    solve_tc();
  }
 
  return 0;
}