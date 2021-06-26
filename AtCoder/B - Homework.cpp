#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
 
int N, M;
LL sum = 0;
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
 
  cin >> N >> M;
 
  while(M--) {
    int A;
    cin >> A;
    sum += A;
  }
 
  (sum <= N) ? cout << N - sum << "\n" : cout << "-1\n";
 
  return 0;
}