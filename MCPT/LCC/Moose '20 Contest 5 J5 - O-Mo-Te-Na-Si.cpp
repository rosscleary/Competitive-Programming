#include <bits/stdc++.h>
using namespace std;

#define int long long

int K;

int max_K(vector<int> options) {
  sort(options.begin(), options.end(), greater<int>());
  int ans = 0;
  for(int i = 0; i < K; i++) {
    ans += options[i];
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);

  int N;
  cin >> N >> K;
  vector<int> pos_pos, pos_neg, neg_pos, neg_neg;
  while(N--) {
    int A_i, B_i;
    cin >> A_i >> B_i;
    pos_pos.push_back(A_i + B_i), pos_neg.push_back(A_i - B_i), neg_pos.push_back(-A_i + B_i), neg_neg.push_back(-A_i - B_i);
  }

  cout << max(max(max_K(pos_pos), max_K(pos_neg)), max(max_K(neg_pos), max_K(neg_neg))) << '\n';
	
  return 0;
}