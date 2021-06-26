#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long

string S;
vector<int> values;
ULL product = 1;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S;

  for(int i = 0; i < S.length(); i += 2) {
    values.push_back(S[i] - '0');
    product *= S[i] - '0';
  }
  sort(values.begin(), values.end());

  for(int i = 0; i < values.size() - 1; i++) {
    cout << values[i] << "x";
  }
  cout << values[values.size() - 1] << "\n" << product << "\n";

  return 0;
}