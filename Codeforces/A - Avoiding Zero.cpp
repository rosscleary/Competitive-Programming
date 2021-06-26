#include <bits/stdc++.h>
using namespace std;
 
void solve_tc() {
  int n;
  cin >> n;
  unordered_map<int, int> freq;
  for(int i = 0; i < n; i++) {
    int a_i;
    cin >> a_i;
    freq[a_i]++;
  }
 
  int sum = 0;
  vector<int> ans;
  for(int i = 0; i < n; i++) {
    int greatest = 0, pick = 51;
    for(int j = -50; j <= 50; j++) {
      if(sum + j != 0 && freq[j] && freq[j] > greatest) {
        greatest = freq[j], pick = j;
      }
    }
    if(pick == 51) {
      cout << "NO\n";
      return;
    }
    freq[pick]--, sum += pick, ans.push_back(pick);
  }
 
  cout << "YES\n";
  for(auto i: ans) {
    cout << i << ' ';
  }
  cout << '\n';
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) {
    solve_tc();
  }
 
  return 0;
}