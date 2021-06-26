#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double

#define fast_inputandoutput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

// ---------- END OF TEMPLATE ---------- //

const int M1 = 1.3e2 + 5, M2 = 4.745e3 + 5;

int test_case = 10;
int F, D, day_sales[M2][M1];
int answer;

int32_t main() { fast_inputandoutput

  while(test_case--) {
    cin >> F >> D;
    for(int i = 0; i < D; i++) {
      for(int j = 0; j < F; j++) cin >> day_sales[i][j];
    }

    answer = 0;
    for(int i = 0; i < D; i++) {
      int sum = 0;
      for(int j = 0; j < F; j++) sum += day_sales[i][j];
      if(sum % 13 == 0) answer += sum / 13;
    }
    for(int i = 0; i < F; i++) {
      int sum = 0;
      for(int j = 0; j < D; j++) sum += day_sales[j][i];
      if(sum % 13 == 0) answer += sum / 13;
    }

    cout << answer << endl;
  }

  return 0;
}