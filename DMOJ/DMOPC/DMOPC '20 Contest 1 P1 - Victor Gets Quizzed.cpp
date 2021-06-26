#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  while(N--) {
    string S;
    cin >> S;
    int find = (S.find('M') != -1) + (S.find('C') != -1);
    if(find == 0) {
      cout << "PASS";
    } else if(find == 1) {
      cout << "FAIL";
    } else {
      cout << "NEGATIVE MARKS";
    }
    cout << '\n';
  }

  return 0;
}