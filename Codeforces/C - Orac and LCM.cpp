#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int M1 = 2e5 + 5;
 
vector<int> prime_occured_all;
vector<vector<int>> prime_freq_all;
vector<int> prime_occured;
vector<int> prime_freq;
 
void pf(int num) {
  for(int i = 2; i * i <= num; i++) {
    if(num % i == 0) {
      pf(i), pf(num / i);
      return;
    }
  }
  if(prime_freq[num] == 0) prime_occured.push_back(num);
  prime_freq[num]++;
}
 
void add_pf(int num) {
  for(int i = 0; i < prime_occured.size(); i++) prime_freq[prime_occured[i]] = 0;
  prime_occured.clear();
 
  pf(num);
  for(int i = 0; i < prime_occured.size(); i++) {
    if(prime_freq_all[prime_occured[i]].size() == 0) prime_occured_all.push_back(prime_occured[i]);
    prime_freq_all[prime_occured[i]].push_back(prime_freq[prime_occured[i]]);
  }
}
 
int32_t main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
 
  prime_freq_all.resize(M1);
  prime_freq.resize(M1);
  for(int i = 0; i < n; i++) add_pf(a[i]);
 
  int answer = 1;
  for(int i = 0; i < prime_occured_all.size(); i++) {
    int curr_base = prime_occured_all[i];
    if(prime_freq_all[curr_base].size() < n - 1) continue;
    int pow_value;
    sort(prime_freq_all[curr_base].begin(), prime_freq_all[curr_base].end());
    if(prime_freq_all[curr_base].size() == n - 1) pow_value = prime_freq_all[curr_base][0];
    else pow_value = prime_freq_all[curr_base][1];
    answer *= powl(curr_base, pow_value);
  }
 
  cout << answer << '\n';
 
  return 0;
}