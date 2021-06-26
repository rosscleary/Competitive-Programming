#include <bits/stdc++.h>
using namespace std;

#define LL long long

int T;
LL N, A, B, C;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> T;

  while(T--) {
    cin >> N >> A >> B >> C;

    if(N > A + B + C) {
      cout << "-1\n";
      continue;
    }
    LL ans_1, ans_2, ans_3;
    ans_3 = min(N, C);
    ans_2 = min(N - ans_3, B);
    ans_1 = min(N - ans_3 - ans_2, A);
    
    cout << ans_1 << " " << ans_2 << " " << ans_3 << '\n';
  }

  return 0;
}