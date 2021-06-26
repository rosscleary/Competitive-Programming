#include <bits/stdc++.h>
using namespace std;
 
int test_case = 10;
int N, T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  while(test_case--) {
    cin >> N >> T;
    cout << (2 * N) - 1 << "\n";
  }
 
  return 0;
}