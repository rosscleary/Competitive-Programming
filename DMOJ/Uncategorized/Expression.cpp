#include <bits/stdc++.h>
using namespace std;

#define int long long

#define PB push_back

const string ops("+-*/");

int N;
string s, old_s;

int close_bracket(int l) {
  int open = 1, i;
  for(i = l; i < N; i++) {
    if(s[i] == '(') {
      open++;
    }
    else if(s[i] == ')') {
      open--;
    }
    if(open == 0) {
      break;
    }
  }

  return i;
}

int solve(int l, int r) {
  vector<int> values;
  vector<char> signs;    
  for(int i = l; i <= r; i++) {
    if(isdigit(s[i])) {
      if(i > l && isdigit(s[i-1])) {
        values.back() *= 10;
        if(values.back() < 0) {
          values.back() -= (s[i] - '0');
        } else {
          values.back() += (s[i] - '0');
        }
      } else if((i == l + 1 && s[i - 1] == '-') || (i > l + 1 && s[i-1] == '-' && ops.find(s[i - 2]) != -1)) {
        values.PB((s[i]-'0')*-1);
      } else {
        values.PB(s[i] - '0');
      }
    } else if(ops.find(s[i]) != -1) {
      if((i == l && s[i] == '-') || (i > l && s[i] == '-' && ops.find(s[i - 1]) != -1)) {
        continue;
      }
      signs.PB(s[i]);
    } else {
      int close = close_bracket(i + 1);
      values.PB(solve(i + 1, close - 1));
      i = close;
    }
  }

  int ans = 0;
  
  signs.push_back('+');
  int last_value = values[0];
  char last_op = '+';
  for(int i = 0; i < signs.size(); i++) {
    if(signs[i] == '*') {
      last_value *= values[i + 1];
    } else if(signs[i] == '/') {
      last_value /= values[i + 1];
    } else {
      if(last_op == '+') {
        ans += last_value;
      } else {
        ans -= last_value;
      }
      last_value = values[i + 1];
      last_op = signs[i];
    }
  }

  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> old_s;

  for(int i = 0; i < old_s.size() - 1; i++) {
    if(old_s[i] == '-' && old_s[i+1] == '(') {
      s += "-1*(";
      i++;
    }
    else {
      s += old_s[i];
    }
  }
  s += old_s[old_s.size()-1];

  N = s.size();

  cout << solve(0, N-1) << '\n';
}