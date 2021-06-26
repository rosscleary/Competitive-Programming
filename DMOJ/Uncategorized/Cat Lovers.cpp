#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  int cat_cnt = 0, dog_cnt = 0;
  while(N--) {
    string response;
    cin >> response;
    cat_cnt += response == "cats";
    dog_cnt += response == "dogs";
  }

  if(cat_cnt > dog_cnt) {
    cout << "cats";
  } else if(cat_cnt < dog_cnt) {
    cout << "dogs";
  } else {
    cout << "equal";
  }
  cout << '\n';

  return 0;
}