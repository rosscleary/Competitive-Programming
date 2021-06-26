#include <bits/stdc++.h>
using namespace std;

int N;
int smallest, largest;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    int a_i; cin >> a_i;
    smallest = min(smallest, a_i);
    largest = max(largest, a_i);
  }

  cout << largest - smallest << '\n';

  return 0;
}