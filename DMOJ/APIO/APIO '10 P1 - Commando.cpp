#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> m_values;
vector<int> b_values;

bool bad(int i, int j, int k) {
  return (b_values[k] - b_values[i]) * (m_values[i] - m_values[j]) < (b_values[j] - b_values[i]) * (m_values[i] - m_values[k]);
}

void add(int m, int b) {
  m_values.push_back(m), b_values.push_back(b);
  while(m_values.size() >= 3 && bad(m_values.size() - 3, m_values.size() - 2, m_values.size() - 1)) {
    m_values.erase(m_values.end() - 2);
    b_values.erase(b_values.end() - 2);
  }
}

int pointer = 0;
int query(int x) {
  if(pointer >= m_values.size()) {
    pointer = m_values.size() - 1;
  }
  while(pointer < m_values.size() - 1 && m_values[pointer + 1] * x + b_values[pointer + 1] > m_values[pointer] * x + b_values[pointer]) {
    pointer++;
  }
  return m_values[pointer] * x + b_values[pointer];
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> x(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> x[i];
    x[i] += x[i - 1];
  }

  int dp_i = a * x[1] * x[1] + b * x[1] + c;
  add(-2 * a * x[1], dp_i + a * x[1] * x[1] - b * x[1]);
  for(int i = 2; i <= n; i++) {
    dp_i = a * x[i] * x[i] + b * x[i] + c;
    dp_i = max(dp_i, dp_i + query(x[i]));
    add(-2 * a * x[i], dp_i + a * x[i] * x[i] - b * x[i]);
  }

  cout << dp_i << '\n';

  return 0;
}