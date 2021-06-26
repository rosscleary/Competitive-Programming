#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e5;
const int pow_value = 53, m_1 = 122949829, m_2 = 300000521;
vector<int> pow_values_1, pow_values_2;

int X_len;
vector<int> pref_hash_1;
int hsh_1(int i, int j) {
  if(i == 0) {
    return (pref_hash_1[j] * pow_values_1[X_len - j - 1]) % m_1;
  }
  return ((pref_hash_1[j] - pref_hash_1[i - 1] + m_1) * pow_values_1[X_len - j - 1]) % m_1;
}
vector<int> pref_hash_2;
int hsh_2(int i, int j) {
  if(i == 0) {
    return (pref_hash_2[j] * pow_values_2[X_len - j - 1]) % m_2;
  }
  return ((pref_hash_2[j] - pref_hash_2[i - 1] + m_2) * pow_values_2[X_len - j - 1]) % m_2;
}


signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  pow_values_1.resize(M1), pow_values_2.resize(M1);
  pow_values_1[0] = 1, pow_values_2[0] = 1;
  for(int i = 1; i < M1; i++) {
    pow_values_1[i] = (pow_values_1[i - 1] * pow_value) % m_1;
    pow_values_2[i] = (pow_values_2[i - 1] * pow_value) % m_2;
  }

  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }
  string X;
  cin >> X;
  X_len = X.length();

  vector<unordered_map<int, int>> length_hashes(M1 + 1);
  set<int> lengths;
  for(string i: S) {
    int len = i.length();
    lengths.insert(len);
    if(len > X_len) {
      continue;
    }

    unordered_set<int> rotation_hashes;
    int suffix_hash_1 = i[len - 1] - 'a' + 1, prefix_hash_1 = 0;
    int suffix_hash_2 = i[len - 1] - 'a' + 1, prefix_hash_2 = 0;
    for(int j = 0; j < len - 1; j++) {
      prefix_hash_1 += ((i[j] - 'a' + 1) * pow_values_1[j + 1]) % m_1; 
      prefix_hash_2 += ((i[j] - 'a' + 1) * pow_values_2[j + 1]) % m_2; 
    }
    pair<int, int> hash_value;
    hash_value.first = ((prefix_hash_1 + suffix_hash_1) * pow_values_1[X_len - len]) % m_1;
    hash_value.second = ((prefix_hash_2 + suffix_hash_2) * pow_values_2[X_len - len]) % m_2;
    rotation_hashes.insert(hash_value.first + hash_value.second * hash_value.second);
    for(int j = len - 2; j >= 0; j--) {
      suffix_hash_1 *= pow_value, suffix_hash_1 %= m_1, suffix_hash_1 += i[j] - 'a' + 1, suffix_hash_1 %= m_1;
      prefix_hash_1 -= ((i[j] - 'a' + 1) * pow_values_1[len - 1]) % m_1, prefix_hash_1 += m_1, prefix_hash_1 %= m_1;
      prefix_hash_1 *= pow_value, prefix_hash_1 %= m_1;
      suffix_hash_2 *= pow_value, suffix_hash_2 %= m_2, suffix_hash_2 += i[j] - 'a' + 1, suffix_hash_2 %= m_2;
      prefix_hash_2 -= ((i[j] - 'a' + 1) * pow_values_2[len - 1]) % m_2, prefix_hash_2 += m_2, prefix_hash_2 %= m_2;
      prefix_hash_2 *= pow_value, prefix_hash_2 %= m_2;
      pair<int, int> hash_value;
      hash_value.first = ((prefix_hash_1 + suffix_hash_1) * pow_values_1[X_len - len]) % m_1;
      hash_value.second = ((prefix_hash_2 + suffix_hash_2) * pow_values_2[X_len - len]) % m_2;
      rotation_hashes.insert(hash_value.first + hash_value.second * hash_value.second);
    }

    for(auto i: rotation_hashes) {
      length_hashes[len][i]++;
    }
  }

  pref_hash_1.resize(X_len);
  pref_hash_1[0] = X[0] - 'a' + 1;
  for(int i = 1; i < X_len; i++) {
    pref_hash_1[i] = (pref_hash_1[i - 1] + (X[i] - 'a' + 1) * pow_values_1[i]) % m_1;
  }
  pref_hash_2.resize(X_len);
  pref_hash_2[0] = X[0] - 'a' + 1;
  for(int i = 1; i < X_len; i++) {
    pref_hash_2[i] = (pref_hash_2[i - 1] + (X[i] - 'a' + 1) * pow_values_2[i]) % m_2;
  }

  vector<int> dp(X_len + 1);
  dp[X_len] = 1;
  for(int i = X_len - 1; i >= 0; i--) {
    for(auto j: lengths) {
      if(i + j > X_len) {
        break;
      }
      pair<int, int> length_hash = {hsh_1(i, i + j - 1), hsh_2(i, i + j - 1)};
      int hashed_hash = length_hash.first + length_hash.second * length_hash.second;
      if(length_hashes[j].count(hashed_hash)) {
        dp[i] += (length_hashes[j][hashed_hash]) * dp[i + j];
        dp[i] %= M;
      }
    }
  }

  cout << dp[0] << '\n';

  return 0;
}