#include <bits/stdc++.h>
using namespace std;

int N;
map<string, int> name_freq;
int answer = 0;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) {
    string name; cin >> name;
    if(name_freq[name] > i / 2) answer++;
    name_freq[name]++;
  }

  cout << answer << '\n';

  return 0;
}