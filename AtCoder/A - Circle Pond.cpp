#include <bits/stdc++.h>
using namespace std;
 
const double pi = 3.1415;
 
double R;
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
 
  cin >> R;
 
  cout << setprecision(6) << fixed << (R * 2.0) * pi << endl;
 
  return 0;
}