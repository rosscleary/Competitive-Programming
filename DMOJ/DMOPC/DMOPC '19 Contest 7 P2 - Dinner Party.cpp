#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e6;

int N; vector<int> a;
int min_value, min_location;
vector<pair<int, int>> changes;

bool valid(int first_amount) {
  int last_amount = first_amount;
  int i = (min_location == N - 1) ? 0: min_location + 1;
  for(int rep = 0; rep < N; rep++) {
    if(a[i] < last_amount) return false;
    last_amount = a[i] - last_amount;
    (i == N - 1) ? i = 0 : i++;
  }
  if(last_amount == first_amount) return true;
  return false;
}

void add_changes(int first_amount) {
  int last_amount = first_amount;
  int i = (min_location == N - 1) ? 0: min_location + 1;
  for(int rep = 0; rep < N; rep++) {
    int last_i = (i == 0) ? N - 1 : i - 1;
    for(int j = 0; j < last_amount; j++) changes.push_back(make_pair(last_i, i));
    last_amount = a[i] - last_amount;
    (i == N - 1) ? i = 0 : i++;
  }
}

int main() { 
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;
  a.resize(N);
  min_value = M1;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
    if(a[i] < min_value) {
      min_value = a[i];
      min_location = i;
    }
  }

  for(int first_change = 0; first_change <= min_value; first_change++) {
    if(valid(first_change)) {
      add_changes(first_change);
      cout << "YES\n" << changes.size() << '\n';
      for(int j = 0; j < changes.size(); j++) cout << changes[j].first << ' ' << changes[j].second << '\n';
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}