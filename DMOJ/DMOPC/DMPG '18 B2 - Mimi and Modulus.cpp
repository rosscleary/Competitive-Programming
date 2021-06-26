#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> N >> M;

  cout << min(N, M - 1) << "\n";

  return 0;
}