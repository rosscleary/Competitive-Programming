#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  string n; cin >> n;
 
  vector<string> answer;
  for(int i = 0; i < n.length(); i++) {
    if(n[i] == '0') continue;
    string curr_answer = ""; curr_answer += n[i];
    for(int j = 0; j < n.length() - i - 1; j++) curr_answer += '0';
    answer.push_back(curr_answer);
  }
 
  cout << answer.size() << '\n';
  for(int i = 0; i < answer.size() - 1; i++) cout << answer[i] << " ";
  cout << answer[answer.size() - 1] << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}