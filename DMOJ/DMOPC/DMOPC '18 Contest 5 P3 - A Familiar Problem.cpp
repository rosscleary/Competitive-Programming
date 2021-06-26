#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll N, M; vector<ll> C;
int answer;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N >> M;
  C.resize(N);
  for(int i = 0; i < N; i++) cin >> C[i];

  int left = 0, right = -1; ll sum = 0;
  while(right < N - 1) {
    if(sum + C[right + 1] < M) right++, sum += C[right];
    else sum -= C[left], left++;
    answer = max(answer, right - left + 1);
  }

  cout << answer << '\n';

  return 0;
}