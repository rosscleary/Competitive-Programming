#include <bits/stdc++.h>
using namespace std;

int main ()

{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;

  int answer = 0;

  while (N--)
  {
    int value;
    cin >> value;
    if (value > 0) answer++;
  }

  cout << answer << endl;

}