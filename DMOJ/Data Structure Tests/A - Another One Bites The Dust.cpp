#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
 
LL a, b, c;
LL answer = 0;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> a >> b >> c;
 
  int min_value = min(a, b);
  answer = (2 * min_value) + (2 * c);
  a -= min_value, b -= min_value;
  answer += min(a, 1LL) + min(b, 1LL);
  cout << answer << endl;
 
  return 0;
}