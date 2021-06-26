#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> m_values, b_values;

bool bad(int i, int j, int k) {
  return (b_values[k] - b_values[i]) * (m_values[i] - m_values[j]) < (b_values[j] - b_values[i]) * (m_values[i] - m_values[k]);
}

void add(int m, int b) {
  m_values.push_back(m), b_values.push_back(b);
  while(m_values.size() >= 3 && bad(m_values.size() - 3, m_values.size() - 2, m_values.size() - 1)) {
    m_values.erase(m_values.end() - 2), b_values.erase(b_values.end() - 2);
  }
}

int pointer = 0;
int query(int x) {
  if(pointer >= m_values.size()) {
    pointer = m_values.size() - 1;
  }
  while(pointer < m_values.size() - 1 && m_values[pointer + 1] * x + b_values[pointer + 1] < m_values[pointer] * x + b_values[pointer]) {
    pointer++;
  }

  return m_values[pointer] * x + b_values[pointer];
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, H;
  cin >> N >> H;
  vector<int> locations(N);
  for(int i = 0; i < N; i++) {
    cin >> locations[i];
  }

  int dp_i = H, last_dp = 0;
  add(-2 * locations[0], locations[0] * locations[0] + last_dp);
  last_dp = dp_i;
  for(int i = 1; i < N; i++) {
    dp_i = H;
    dp_i += min(last_dp, locations[i] * locations[i] + query(locations[i]));
    add(-2 * locations[i], locations[i] * locations[i] + last_dp);
    last_dp = dp_i;
  }

  cout << dp_i << '\n';

  return 0;
}