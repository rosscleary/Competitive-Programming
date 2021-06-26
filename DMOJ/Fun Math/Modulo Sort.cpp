#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;

int N, K;
pair<int, int> values[maxN + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  for(int i = 0; i < N; i++) {
    cin >> values[i].second;
    values[i].first = values[i].second % K;
  }

  sort(values, values + N);

  for (int i = 0; i < N; i++) cout << values[i].second << " ";

  cout << "\n";

  return 0;
}