#include <bits/stdc++.h>
using namespace std;

vector<int> pref_sum;

int sum(int i, int j) {
  return pref_sum[j] - (i ? pref_sum[i - 1] : 0);
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  pref_sum.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    pref_sum[i] = A[i];
    if(i != 0) {
      pref_sum[i] += pref_sum[i - 1];
    }
  }

  int j = N - 1;
  vector<int> ans;
  for(int i = N - 2; i >= 0; i--) {
    while(2 * j - i + 1 >= N || sum(i, j) > S || sum(j + 1, 2 * j - i + 1) > S) {
      j--;
    }
    ans.push_back(2 * (j - i + 1));
  }

  for(int i = N - 2; i >= 0; i--) {
    cout << ans[i] << '\n';
  }
  cout << "0\n";

  return 0;
}