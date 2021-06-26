#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int N;
  cin >> N;
  set<int> distinct_values;
  for(int i = 0; i < N; i++) {
    int value;
    cin >> value;
    distinct_values.insert(value);
  }

  cout << distinct_values.size() << '\n';
 
  return 0;
}