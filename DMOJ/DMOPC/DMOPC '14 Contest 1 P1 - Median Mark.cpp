#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N; 
  cin >> N;
  vector<int> marks(N);
  for(int i = 0; i < N; i++) cin >> marks[i];

  sort(marks.begin(), marks.end());
  if(N % 2 == 1) cout << marks[N / 2] << '\n';
  else cout << round(double((marks[N / 2] + marks[N / 2 - 1]) / 2.0)) << '\n';

  return 0;
}