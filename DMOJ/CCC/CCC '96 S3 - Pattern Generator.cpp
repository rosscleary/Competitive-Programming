#include <bits/stdc++.h>
using namespace std;

class Pattern {
  public:
  Pattern(int, int);
  vector<string> patterns();

  private:
  int n;
  int k;
};

Pattern::Pattern(int n, int k) {
    this->n = n;
    this->k = k;
}

vector<string> Pattern::patterns() {
  if(n == 0) {
    return {""};
  }

  vector<string> ans; 
  if(k > 0) {
    Pattern next(n-1, k-1);
    for(auto i: next.patterns()) {
      ans.push_back("1" + i);
    }
  }
  if(k < n) {
    Pattern next(n-1, k);
    for(auto i: next.patterns()) {
      ans.push_back("0" + i);
    }
  }

  return ans;
}

void solve_tc() {
  int n, k;
  cin >> n >> k;

  Pattern pattern(n, k);

  vector<string> ans = pattern.patterns();
  cout << "The bit patterns are\n";
  for(auto i: ans) {
    cout << i << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    solve_tc();
    if(tc > 0) {
      cout << '\n';
    }
  }

  return 0;
}