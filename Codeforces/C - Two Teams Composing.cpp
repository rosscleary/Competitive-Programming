#include <bits/stdc++.h>
using namespace std;
 
const int MN = 2e5 + 5;
 
int t;
int n;
vector<int> value_occured;
int freq[MN];
int max_freq = 0;
int x;
 
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      int value;
      cin >> value;
      if(freq[value] == 0) value_occured.push_back(value);
      freq[value]++;
    }
 
    for(int i = 0; i < value_occured.size(); i++) {
      max_freq = max(max_freq, freq[value_occured[i]]);
    }
    x = max(min(max_freq, value_occured.size() - 1), min(max_freq - 1, value_occured.size()));
 
    cout << x << "\n";
 
    value_occured.clear();
    memset(freq, 0, sizeof(freq));
    max_freq = 0;
  }
 
  return 0;
}