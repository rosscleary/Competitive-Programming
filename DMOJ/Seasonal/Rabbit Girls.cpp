#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL N, K;
LL answer;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  answer = K - (N % K);
  if(N >= K) answer = min(answer, N % K);

  cout << answer << "\n";

  return 0;
}