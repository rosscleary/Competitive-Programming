#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e6 + 1;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> A(N), freq(M1);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    freq[A[i]]++;
  }

  int ans = 0;
  set<set<int>> counted;
  for(int i = 0; i < N - 1; i++) {
    for(int j = i + 1; j < N; j++) {
      if(A[i] + A[j] < M1 && freq[A[i] + A[j]] && !counted.count({A[i], A[j], A[i] + A[j]})) {
        ans++;
        counted.insert({A[i], A[j], A[i] + A[j]});
      }
    }
  }

  cout << (ans == 0 ? -1 : ans) << '\n';

  return 0;
}