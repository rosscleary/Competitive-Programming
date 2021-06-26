#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  map<string, int> colour_freq;
  for(int i = 0; i < N; i++) {
    string colour;
    cin >> colour;
    colour_freq[colour]++;
  }

  int ans = 0;
  string last = "";
  for(int i = 0; i < N; i++) {
    int max_freq = 0;
    string new_last = last;
    for(auto j: colour_freq) {
      if(j.first != last && j.second > max_freq) {
        max_freq = j.second;
        new_last = j.first;
      }
    }
    ans += max_freq != 0;
    colour_freq[new_last] = max(0, colour_freq[new_last] - 1);
    last = new_last;
  }

  cout << ans << '\n';

  return 0;
}