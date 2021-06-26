#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL a, b;
LL dp[20][12][12][2];
bool dp_solved[20][12][12][2];
LL answer = 0;

LL solve(string max_value, int index, int last, int last_2, bool under) {
  if(max_value == "-1" || max_value == "0") return 0;

  if(index == max_value.length()) return 1;
  if(dp_solved[index][last][last_2][under]) return dp[index][last][last_2][under];

  if(under) {
    for(int i = 0; i < 10; i++) {
      if(index == 0 && i == 0) continue;
      if(i != last && i != last_2) dp[index][last][last_2][under] += solve(max_value, index + 1, i, last, true);
    }
  } else {
    for(int i = 0; i < max_value[index] - '0'; i++) {
      if(index == 0 && i == 0) continue;
      if(i != last && i != last_2) dp[index][last][last_2][under] += solve(max_value, index + 1, i, last, true);
    }
    if(max_value[index] - '0' != last && max_value[index] - '0' != last_2) {
      dp[index][last][last_2][under] += solve(max_value, index + 1, max_value[index] - '0', last, false);
    }
  }

  dp_solved[index][last][last_2][under] = true;
  return dp[index][last][last_2][under];
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> a >> b;

  answer += solve(to_string(b), 0, 10, 10, false);
  for(int i = 1; i < to_string(b).length(); i++) {
    if(i == 1) answer += 9;
    else answer += 81 * pow(8, i - 2);
  }
  memset(dp, 0, sizeof(dp));
  memset(dp_solved, false, sizeof(dp_solved));
  answer -= solve(to_string(a - 1), 0, 10, 10, false);
  for(int i = 1; i < (a == 0 ? 1 : to_string(a - 1).length()); i++) {
    if(i == 1) answer -= 9;
    else answer -= 81 * pow(8, i - 2);
  }

  if(a == 0) answer++;
  cout << answer << "\n";

  return 0;
}