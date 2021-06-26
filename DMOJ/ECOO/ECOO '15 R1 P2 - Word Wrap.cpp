#include <bits/stdc++.h>
using namespace std;


int W; string S;
// https://dmoj.ca/problem/ecoo15r1p2

int tc = 10;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  while(tc--) {

    cin >> W;
    cin.ignore();
    getline(cin, S);

    while(true) {
      if(S.length() <= W) {
        cout << S.substr(0, S.length()) << '\n';
        break;
      }
      if(S.rfind(' ', W) == -1) {
        for(int i = 0; i < W; i++) cout << S[i];
        S.erase(0, W);
        cout << "\n";
        continue;
      }
      cout << S.substr(0, S.rfind(' ', W)) << '\n';
      S.erase(0, S.rfind(' ', W) + 1);
    }

    cout << "=====\n";
  }

  return 0;
}