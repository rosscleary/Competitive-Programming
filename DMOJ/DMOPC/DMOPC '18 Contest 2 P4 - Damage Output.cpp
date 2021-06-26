#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

const int M1 = 5e5 + 5;

int N; LL M, d[M1];
int answer = M1;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++) cin >> d[i];

  int left = 0, right = 0;
  LL sum = d[0];
  while(right < N) {
    if(sum < M) {
      sum += d[right + 1];
      right++;
    } else {
      answer = min(answer, right - left + 1);
      sum -= d[left];
      left++;
    }
  }

  if(answer == M1) cout << "-1\n";
  else cout << answer << '\n';

  return 0;
}