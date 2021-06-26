#include <bits/stdc++.h>
using namespace std;

bool sort_fun(pair<int, string> i, pair<int, string> j) {
  if(i.first > j.first) {
    return true;
  }
  if(i.first == j.first) {
    return i.second < j.second;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<pair<int, string>> choices(n);
  for(int i = 0; i < n; i++) {
    string name;
    cin >> name;
    int R, S, D;
    cin >> R >> S >> D;
    choices[i] = {2 * R + 3 * S + D, name};
  }

  sort(choices.begin(), choices.end(), sort_fun);

  for(int i = 0; i < min(n, 2); i++) {
    cout << choices[i].second << '\n';
  }

  return 0;
}