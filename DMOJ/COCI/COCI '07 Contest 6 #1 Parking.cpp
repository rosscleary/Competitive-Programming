#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int A, B, C;
  cin >> A >> B >> C;
  vector<int> diff_arr(102);
  for(int i = 0; i < 3; i++) {
    int arr_time, dep_time;
    cin >> arr_time >> dep_time;
    diff_arr[arr_time]++, diff_arr[dep_time]--;
  }

  int ans = 0;
  for(int i = 1; i <= 100; i++) {
    diff_arr[i] += diff_arr[i - 1];
    ans += diff_arr[i] * (diff_arr[i] == 1 ? A : diff_arr[i] == 2 ? B : C);
  }

  cout << ans << '\n';

  return 0;
}