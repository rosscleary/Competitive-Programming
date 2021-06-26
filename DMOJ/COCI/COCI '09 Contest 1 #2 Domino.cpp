#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double

#define fast_inputandoutput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

// ---------- END OF TEMPLATE ---------- //

int N;

int32_t main() { fast_inputandoutput

  cin >> N;
  
  cout << (((N + 1) * (N + 2)) / 2) * N << endl;

  return 0;
}