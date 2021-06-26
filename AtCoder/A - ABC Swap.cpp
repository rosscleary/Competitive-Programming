#include <bits/stdc++.h>
using namespace std;
 
int X, Y, Z;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> X >> Y >> Z;
 
  int temp = X;
  X = Y;
  Y = temp;
 
  temp = X;
  X = Z;
  Z = temp;
 
  cout << X << " " << Y << " " << Z << "\n";
 
  return 0;
}