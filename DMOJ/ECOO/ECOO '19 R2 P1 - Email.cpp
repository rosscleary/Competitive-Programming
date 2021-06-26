#include <bits/stdc++.h>
using namespace std;

void solve_tc() {
  int N;
  cin >> N;
  set<string> dist;
  while(N--) {
    string S;
    cin >> S;
    string real_S = "";
    bool at_sign = false, plus = false;
    for(auto i: S) {
      if(i == '@') {
        at_sign = true;
      }
      if(i == '+') {
        plus = true;
      }
      if(!at_sign && (i == '.' || plus)) {
        continue;
      }
      real_S += tolower(i);
    }
    dist.insert(real_S);
  }

  cout << dist.size() << '\n'; 
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int test_case = 10;
  while(test_case--) {
    solve_tc();
  }

  return 0;
}