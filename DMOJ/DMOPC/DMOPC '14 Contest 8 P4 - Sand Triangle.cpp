#include <bits/stdc++.h>
using namespace std;

#define int long long
 
int32_t main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  int last = 0, increment = 1, answer = 0;
  while(true) {
    int curr = last + increment;
    if(N <= curr) {
      for(int num = last + 1; num <= curr; num++) answer += num;
      break;
    }
    last = curr;
    increment++;
  }

  cout << answer << '\n';
 
  return 0;
}