#include <bits/stdc++.h>
using namespace std;

const int MAX_L = 65;

int N;
int L, values[MAX_L];
int answer = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  while(N--) {
    cin >> L;
    for(int i = 0; i < L; i++) cin >> values[i];

    for(int i = 0; i < L - 1; i++) {
      for(int j = i + 1; j < L; j++) {
        if(values[i] > values[j]) answer++;
      }
    }
    
    cout << answer << "\n";
    answer = 0;
  }

  return 0;
}