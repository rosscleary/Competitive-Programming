#include <bits/stdc++.h>
using namespace std;

int T;
int N, B;
int M;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> T;

  while(T--) {
    cin >> N >> B;

    M = 0;
    for(int i = 0; i < N - 1; i++) {
      int S;
      cin >> S;
      if(S > B) M++;
    }
    
    cout << "Bob wins $" << setprecision(2) << fixed << double(sqrt(N - M) * 100.0) << " at IOI!\n";
  }

  return 0;
}