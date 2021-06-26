#include <bits/stdc++.h>
using namespace std;

string X;
int X_value;
int answer = 1e7;

int string_value(string str) {
  int value = 0, power = 0;
  for(int i = str.length() - 1; i >= 0; i--) {
    value += (str[i] - '0') * pow(10, power);
    power++;
  }
  return value;
}

void perm_generate(string current, string available) {
  if(available.length() == 0) {
    int current_value = string_value(current);
    if(current_value > X_value) answer = min(answer, current_value);
    return;
  }

  for(int i = 0; i < available.length(); i++) {
    string new_current = current + available[i];
    string new_available = available;
    new_available.erase(i, 1);
    perm_generate(new_current, new_available);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> X;
  X_value = string_value(X);

  perm_generate("", X);
  if(answer == 1e7) cout << "0\n";
  else cout << answer << "\n";

  return 0;
}