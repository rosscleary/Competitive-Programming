#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string direction;
  int amount;
  while(true) {
    string instruction;
    cin >> instruction;
    if(instruction == "99999") {
      break;
    }
    
    int sum_1 = instruction[0] - '0' + instruction[1] - '0', sum_2 = (instruction[2] - '0') * 100 + (instruction[3] - '0') * 10 + instruction[4] - '0';
    if(sum_1) {
      if(sum_1 & 1) {
        direction = "left";
      } else {
        direction = "right";
      }
    }
    amount = sum_2;

    cout << direction << ' ' << amount << '\n';
  }

  return 0;
}