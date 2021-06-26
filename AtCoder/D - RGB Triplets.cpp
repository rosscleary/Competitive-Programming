#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
 
const int MAX_N = (4 * 1e3) + 5;
 
int N;
string S;
int prefix_r[MAX_N];
int prefix_g[MAX_N];
int prefix_b[MAX_N];
LL answer = 0;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> N >> S;
 
  if(S[0] == 'R') prefix_r[0] = 1;
  if(S[0] == 'G') prefix_g[0] = 1;
  if(S[0] == 'B') prefix_b[0] = 1;
  for(int i = 1; i < N; i++) {
    if(S[i] == 'R') {
      prefix_r[i] = prefix_r[i - 1] + 1;
      prefix_g[i] = prefix_g[i - 1];
      prefix_b[i] = prefix_b[i - 1];
    }
    if(S[i] == 'G') {
      prefix_r[i] = prefix_r[i - 1];
      prefix_g[i] = prefix_g[i - 1] + 1;
      prefix_b[i] = prefix_b[i - 1];
    }
    if(S[i] == 'B') {
      prefix_r[i] = prefix_r[i - 1];
      prefix_g[i] = prefix_g[i - 1];
      prefix_b[i] = prefix_b[i - 1] + 1;
    }
  }
 
  for(int i = 0; i < N - 2; i++) {
    for(int j = i + 1; j < N - 1; j++) {
      if(S[i] == S[j]) continue;
      if(S[i] != 'R' && S[j] != 'R') {
        answer += prefix_r[N - 1] - prefix_r[j];
        if(j + (j - i) < N && S[j + (j - i)] == 'R') answer--;
      }
      if(S[i] != 'G' && S[j] != 'G') {
        answer += prefix_g[N - 1] - prefix_g[j];
        if(j + (j - i) < N && S[j + (j - i)] == 'G') answer--;
      }
      if(S[i] != 'B' && S[j] != 'B') {
        answer += prefix_b[N - 1] - prefix_b[j];
        if(j + (j - i) < N && S[j + (j - i)] == 'B') answer--;
      }
    }
  }
 
  cout << answer << "\n";
 
  return 0;
}