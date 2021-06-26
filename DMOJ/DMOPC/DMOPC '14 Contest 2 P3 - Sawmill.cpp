#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int M1 = 5e4 + 5;

int N; vector<ll> e; vector<ll> l;
ll answer;

void linear_sort(vector<ll> &values) {
    vector<int> freq(M1);
    for(int i = 0; i < N; i++) freq[values[i]]++;
    values.clear();
    for(int i = 0; i < M1; i++) {
      for(int j = 0; j < freq[i]; j++) values.push_back(i);
    }
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N;
  e.resize(N);
  for(int i = 0; i < N; i++) cin >> e[i];
  l.resize(N);
  for(int i = 0; i < N; i++) cin >> l[i];

  linear_sort(e);
  linear_sort(l);
  for(int i = 0; i < N; i++) answer += e[i] * l[N - i - 1];

  cout << answer << '\n';

  return 0;
}