#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
 
  int real_start = 0;
  string real_start_string = "";
  for(int i = 0; i < m; i++) {
    set<char> distinct_letters;
    for(int j = 0; j < n; j++) distinct_letters.insert(a[j][i]);
    if(distinct_letters.size() > 1) break;
    real_start++;
    real_start_string += a[0][i];
  }
 
  if(real_start == m) {
    cout << a[0] << '\n';
    return;
  }
 
  vector<char> first_letters;
  set<char> first_letters_unique;
  for(int i = 0; i < n; i++) {
    if(!first_letters_unique.count(a[i][real_start])) {
      first_letters.push_back(a[i][real_start]);
      first_letters_unique.insert(a[i][real_start]);
    }
  }
 
  for(int i = 0; i < first_letters.size(); i++) {
    char first_choice = first_letters[i];
    vector<string> distinct_ends;
    set<string> distinct_ends_unique;
    vector<int> match;
    for(int j = 0; j < n; j++) {
      if(a[j][real_start] != first_choice) {
        string end = a[j].substr(real_start + 1, m - 1);
        if(!distinct_ends_unique.count(end)) {
          distinct_ends.push_back(end);
          distinct_ends_unique.insert(end);
        }
      } else match.push_back(j);
    }
    if(distinct_ends.size() == 1) {
      bool match_valid = true;
      for(int j = 0; j < match.size(); j++) {
        int diff_amount = 0;
        for(int k = real_start + 1; k < m; k++) diff_amount += a[match[j]][k] != distinct_ends[0][k - real_start - 1];
        if(diff_amount > 1) {
          match_valid = false;
          break;
        }
      }
      if(match_valid) {
        cout << real_start_string << first_choice << distinct_ends[0] << '\n';
        return;
      }
    }
  }
  cout << "-1\n";
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}