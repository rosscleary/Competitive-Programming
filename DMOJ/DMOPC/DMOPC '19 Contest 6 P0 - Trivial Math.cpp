#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int lengths[3];

  cin >> lengths[0] >> lengths[1] >> lengths[2];

  sort(lengths, lengths + 3);

  if (lengths[0] + lengths[1] > lengths[2]) {
    cout << "yes\n";
  }
  else {
    cout << "no\n";
  }

  return 0;
}