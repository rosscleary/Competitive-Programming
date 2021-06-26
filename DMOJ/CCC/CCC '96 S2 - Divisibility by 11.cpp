#include <bits/stdc++.h>
using namespace std;

void solve_tc() {
  string num;
  cin >> num;
  string num_orig = num;
  
  cout << num << '\n';
  while(num.size() > 2) {
    int curr_sz = num.size();
    int last_digit = num[curr_sz - 1] - '0';
    int next_digit = num[curr_sz - 2] - '0';
    if(next_digit - last_digit >= 0) {
      num[curr_sz - 2] -= last_digit;
    } else {
      int i = curr_sz - 3;
      for(; num[i] == '0'; i--) {
        num[i] = '9';
      }
      num[i]--;
      num[curr_sz - 2] += 10 - last_digit;
    }
    int start = 0;
    while(start < curr_sz && num[start] == '0') {
      start++;
    }
    num.erase(curr_sz - 1, 1), num.erase(0, start);
    cout << num << '\n';
  }

  cout << "The number " << num_orig << " is ";
  int final_num = stoi(num.substr(0, 2));
  if(final_num % 11 == 0) {
    cout << "divisible by 11.";
  } else {
    cout << "not divisible by 11.";
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    solve_tc();
    if(tc != 0) {
      cout << '\n';
    }
  }

  return 0;
}