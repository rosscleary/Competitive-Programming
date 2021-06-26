#include <bits/stdc++.h>
using namespace std;

#define maxN 1000000

int N, m[maxN], Q, a, b;

int prefix_sum[maxN];

int main ()

{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++) cin >> m[i];

  prefix_sum[0] = m[0];

  for (int i = 1; i < N; i++) prefix_sum[i] = prefix_sum[i - 1] + m[i];

  cin >> Q;

  while (Q--)
  {
    cin >> a >> b;
    a == 0 ? cout << prefix_sum[b] << endl : cout << prefix_sum[b] - prefix_sum[a - 1] << endl;
  }

  return 0;

}