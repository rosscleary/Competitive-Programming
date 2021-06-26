#include <bits/stdc++.h>
using namespace std;

#define maxsize 50

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int size, list[maxsize];

  cin >> size;

  for (int i = 0; i < size; i++) cin >> list[i];

  sort(list, list + size);

  for (int i = 0; i < size; i++) cout << list[i] << endl;

  return 0;
}