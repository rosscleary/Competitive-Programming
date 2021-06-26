#include <bits/stdc++.h>
using namespace std;

const int max_result = 42;

bool value_occured[max_result];
int unique_counter = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 0; i < 10; i++) {
    int value; cin >> value;
    value %= 42;
    if (!value_occured[value]) unique_counter++;
    value_occured[value] = true;
  }

  cout << unique_counter << "\n";

  return 0;
}