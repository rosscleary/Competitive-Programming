#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int G, P;
  cin >> G >> P;

  set<int> gates;
  for(int gate = 1; gate <= G; gate++) gates.insert(-gate);

  for(int plane = 1; plane <= P; plane++) {
    int g_i;
    cin >> g_i;
    if(gates.lower_bound(-g_i) == gates.end()) {
      cout << plane - 1 << '\n';
      return 0;
    }
    gates.erase(gates.lower_bound(-g_i));
  }
  cout << P << '\n';
 
  return 0;
}