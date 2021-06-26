#include <bits/stdc++.h>
using namespace std;

int N_len;
vector<string> add_nums;

void rec(string curr) {
  if(curr.length() == N_len) {
    add_nums.push_back(curr);
    return;
  }
  rec(curr + '2'), rec(curr + '3');
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string N;
  cin >> N;
  N_len = N.length();
  long long N_num = stoll(N);

  int ans = pow(2, N_len) - 2;
  rec("");
  for(int i = 0; i < add_nums.size(); i++) {
    if(stoll(add_nums[i]) <= N_num) {
      ans++;
    }
  }

  cout << ans << '\n';

  return 0;
}