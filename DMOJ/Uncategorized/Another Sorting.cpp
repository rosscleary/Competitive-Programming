#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> values[10];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    int value;
    cin >> value;
    values[value % 10].push_back(value);
  }

  for(int i = 0; i < 10; i++) {
    sort(values[i].begin(), values[i].end());
    for(int j = values[i].size() - 1; j >= 0; j--) {
      cout << values[i][j] << " ";
    }
  }
  cout << "\n";

  return 0;
}