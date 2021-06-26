#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
 
int N;
LL sum = 0;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> N;
 
  for(int i = 1; i <= N; i++) {
    if(i % 3 != 0 && i % 5 != 0) sum += i;
  }
 
  cout << sum << "\n";
 
  return 0;
}