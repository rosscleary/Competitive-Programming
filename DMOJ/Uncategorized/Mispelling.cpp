#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  for(int i = 1; i <= N; i++) {
    int M;
    cin >> M;
    string s;
    cin.ignore();
    getline(cin, s);
    s.erase(M - 1, 1);
    cout << i << ' ' << s << '\n';
  }

  return 0;
}