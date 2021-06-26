#include <bits/stdc++.h>
using namespace std;

#define int long long

bool prime(int num) {
  if (num <= 2) {
    return (num == 2);
  }
  if (num % 2 == 0) {
    return false;
  }

  for (int div = 3; div * div <= num; div += 2) {
    if (num % div == 0) {
      return false;
    }
  }

  return true;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int D, N;
  cin >> D >> N;
  D = max(D, 1LL);
  N = max(N, (long long)(powl(10, 2 * D - 1)));

  for (; ; N++) {
    string str_ans = to_string(N);
    for (int i = D - 1; str_ans.size() - i - 1 >= D; i++) {
      if (str_ans[i + 1] != '0' && prime(stoi(str_ans.substr(0, i + 1))) && prime(stoi(str_ans.substr(i + 1, str_ans.size() - i - 1)))) {
        cout << N << '\n';
        return 0;
      }
    }
  }

  return 0;
}