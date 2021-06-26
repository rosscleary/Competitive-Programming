#include <bits/stdc++.h>
using namespace std;

const int M1 = 5e6;

string seats;
int N;
unordered_map<char, int> type_cnt;
unordered_map<char, vector<int>> prefix_freq;

int solve_perm(string perm) {
  int start_1 = 1, end_1 = type_cnt['A'];
  int start_2 = end_1 + 1, end_2 = start_2 + type_cnt[perm[1]] - 1;
  int start_3 = end_2 + 1, end_3 = start_3 + type_cnt[perm[2]] - 1;
  int ans = M1;
  for(; start_1 <= N; start_1++, end_1++, start_2++, end_2++, start_3++, end_3++) {
    int curr_opt = type_cnt['A'] - (prefix_freq['A'][end_1] - prefix_freq['A'][start_1 - 1]);
    curr_opt += type_cnt[perm[1]];
    curr_opt -= prefix_freq[perm[1]][end_2] - prefix_freq[perm[1]][start_2 - 1];
    curr_opt -= min(prefix_freq[perm[1]][end_1] - prefix_freq[perm[1]][start_1 - 1], prefix_freq['A'][end_2] - prefix_freq['A'][start_2 - 1]);
    ans = min(ans, curr_opt);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> seats;
  N = seats.size();
  seats = ' ' + seats;
  for(int i = 1; i <= N; i++) {
    seats += seats[i];
    type_cnt[seats[i]]++;
  }

  int sz = seats.size();
  prefix_freq['A'].resize(sz), prefix_freq['B'].resize(sz), prefix_freq['C'].resize(sz);
  for(int i = 1; i < sz; i++) {
    prefix_freq['A'][i] = prefix_freq['A'][i - 1];
    prefix_freq['B'][i] = prefix_freq['B'][i - 1];
    prefix_freq['C'][i] = prefix_freq['C'][i - 1];
    prefix_freq[seats[i]][i]++;
  }

  int ans = min(solve_perm("ABC"), solve_perm("ACB"));
  cout << ans << '\n';

  return 0;
}