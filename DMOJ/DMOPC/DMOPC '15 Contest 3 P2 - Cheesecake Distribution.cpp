#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll N; vector<ll> slice_amounts;
ll slice_sum, person_amount;
ll answer;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N;
  slice_amounts.resize(N);
  slice_sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> slice_amounts[i];
    slice_sum += slice_amounts[i];
  }

  if(slice_sum % N != 0) {
    cout << "Impossible\n"; 
    return 0;
  }

  person_amount = slice_sum / N;
  answer = 0;
  for(int i = 0; i < N; i++) {
    if(slice_amounts[i] < person_amount) answer += person_amount - slice_amounts[i];
  }

  cout << answer << '\n';

  return 0;
}