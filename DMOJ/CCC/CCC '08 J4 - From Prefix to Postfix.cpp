#include <bits/stdc++.h>
using namespace std;

string expression;

void output(int i, int j) {
  if(i == j) {
    cout << expression[i];
    return;
  }
  int open = 2, last = -1;
  for(int k = i + 2; ; k += 2) {
    if(expression[k] == '+' || expression[k] == '-') {
      open++;
    } else {
      open--;
    }
    if(open == 1 && last == -1) {
      output(i + 2, k);
      cout << ' ';
      last = k + 2;
    }
    if(open == 0) {
      output(last, k);
      cout << ' ';
      break;
    }
  }

  cout << expression[i];
}

void solve_tc() {
  getline(cin, expression);
  if(expression == "0") {
    exit(0);
  }

  output(0, expression.length() - 1);
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  while(true) {
    solve_tc();
  }

  return 0;
}