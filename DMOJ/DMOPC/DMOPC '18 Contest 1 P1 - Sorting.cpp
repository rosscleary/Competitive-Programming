#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e6;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> A(N), real_values;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(A[i] != 0) {
      real_values.push_back(A[i]);
    }
  }

  vector<int> sorted_real = real_values;
  sort(sorted_real.begin(), sorted_real.end());
  if(real_values != sorted_real) {
    cout << "NO\n";
    return 0;
  }
  
  vector<int> lasts(N), nexts(N);
  int last_value = 1;
  for(int i = 0; i < N; i++) {
    last_value = A[i] != 0 ? A[i] : last_value;
    lasts[i] = last_value;
  }
  int next_value = M1;
  for(int i = N - 1; i >= 0; i--) {
    next_value = A[i] != 0 ? A[i] : next_value;
    nexts[i] = next_value;
  }

  vector<int> valid_cnts(M1 + 2);
  int zero_cnt = 0;
  for(int i = 0; i < N; i++) {
    if(A[i] == 0) {
      valid_cnts[lasts[i]]++, valid_cnts[nexts[i] + 1]--;
      zero_cnt++;
    }
  }
  bool ans = false;
  for(int i = 1; i <= M1; i++) {
    valid_cnts[i] += valid_cnts[i - 1];
    if(valid_cnts[i] == zero_cnt) {
      ans = true;
      break;
    }
  }

  cout << (ans ? "YES" : "NO") << '\n';

  return 0;
}