#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e4 + 5;

int N;
string values[MAX_N];

bool sort_function(string item_1, string item_2) {
  return (item_1 + item_2) > (item_2 + item_1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> values[i];

  sort(values, values + N, sort_function);
  for(int i = 0; i < N; i++) cout << values[i];
  cout << "\n";

  return 0;
}