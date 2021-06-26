#include <bits/stdc++.h>
using namespace std;
 
const int M1 = 2e5 + 5;
 
int N;
int freq[M1];
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
 
  cin >> N;
 
  for(int i = 0; i < N - 1; i++) {
    int A;
    cin >> A;
    freq[A]++;
  }
 
  for(int i = 1; i <= N; i++) cout << freq[i] << "\n";
 
  return 0;
}