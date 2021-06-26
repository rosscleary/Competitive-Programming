#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;

  int answer = 0;
  for(int num = 0; num <= N; num++) {
    string str_num = to_string(num);
    for(int i = 0; i < str_num.length(); i++) answer += str_num[i] == '0';
  } 

  cout << answer << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
  int test_case = 5;
  while(test_case--) solve();
 
  return 0;
}