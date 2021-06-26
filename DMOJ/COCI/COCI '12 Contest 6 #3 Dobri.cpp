#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> A(N);
  unordered_set<int> pairs;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    for(int j = 0; j < i; j++) {
      if(pairs.count(A[i] - A[j])) {
        ans++;
        break;
      }
    }
    for(int j = 0; j <= i; j++) {
      pairs.insert(A[i] + A[j]);
    }
  }

  cout << ans << '\n';

  return 0;
}