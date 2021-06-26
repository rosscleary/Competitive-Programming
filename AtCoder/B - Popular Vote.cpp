#include <bits/stdc++.h>
using namespace std;
 
const int maxN = 100;
 
double N, M, A[maxN];
int total_votes = 0;
int popular_count = 0;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    total_votes += A[i];
  }
 
  for(int i = 0; i < N; i++) {
    if(A[i] / total_votes >= 1 / (4.0 * M)) popular_count++;
  }
 
  if(popular_count >= M) cout << "Yes\n";
  else cout << "No\n";
 
  return 0;
}