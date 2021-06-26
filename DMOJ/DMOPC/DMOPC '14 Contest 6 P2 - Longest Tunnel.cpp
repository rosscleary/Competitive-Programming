#include <bits/stdc++.h>
using namespace std;

int N;
int answer = 0;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  while(N--) {
    int X_t1, X_t2;
    cin >> X_t1 >> X_t2;
    answer = max(answer, X_t2 - X_t1);
  }

  cout << answer << '\n';

  return 0;
}