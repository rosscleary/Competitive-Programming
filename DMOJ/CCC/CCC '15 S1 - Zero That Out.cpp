#include <bits/stdc++.h>
using namespace std;

const int maxK = 1e5;

int K, values[maxK];
vector<int> real_values;
int answer = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> K;

  for(int i = 0; i < K; i++) cin >> values[i];

  for(int i = 0; i < K; i++) {
    if(values[i] != 0) {
      real_values.push_back(values[i]);
    } else {
      real_values.erase(real_values.begin() + real_values.size() - 1);
    }
  }

  for(int i = 0; i < real_values.size(); i++) {
    answer += real_values[i];
  }
  cout << answer << "\n";

  return 0;
}