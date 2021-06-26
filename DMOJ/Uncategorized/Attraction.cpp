#include <bits/stdc++.h>
using namespace std;

void solve_tc() {
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> P(A);
  for(auto &i: P) {
    cin >> i;
  }

  sort(P.begin(), P.end());
  vector<int> options;
  if(P[0] - 1) {
    options.push_back(P[0] - 1);
  }
  if(N - P[A - 1]) {
    options.push_back(N - P[A - 1]);
  }
  int three_cnt = 0;
  for(int i = 0; i < A - 1; i++) {
    int gap = P[i + 1] - P[i] - 1;
    if(!gap) {
      continue;
    }
    if(gap == 1) {
      options.push_back(1);
      continue;
    }
    if(gap == 2) {
      options.push_back(1), options.push_back(1);
      continue;
    }
    if(gap == 3) {
      options.push_back(2), three_cnt++;
      continue;
    }
    int first = 1 + (gap - 1) / 2;
    options.push_back(first);
    if(gap & 1) {
      options.push_back(gap - first - 1), options.push_back(1);
    } else {
      options.push_back(gap - first);
    }
  }

  sort(options.begin(), options.end(), greater<int>());
  int ans = 0, B_remain = B;
  for(int i = 0; i < min(B, int(options.size())); i++, B_remain--) {
    ans += options[i];
  }

  for(int i = 0; i < min(B_remain / 2, three_cnt); i++) {
    ans++;
  }

  cout << ans << '\n';
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