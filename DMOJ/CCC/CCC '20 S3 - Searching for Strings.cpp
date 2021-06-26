#include <bits/stdc++.h>
using namespace std;

#define int long long

const string alph = "abcdefghijklmnopqrstuvwxyz";
const int p = 53, m_1 = 104395303, m_2 = 	179424691;

bool valid(unordered_map<char, int> freq_1, unordered_map<char, int> freq_2) {
  for(auto i: freq_1) {
    if(i.second != freq_2[i.first]) {
      return false;
    }
  }

  return true;
}

string H;
vector<int> ppow_1, ppow_2, pref_hash_1, pref_hash_2;
int hsh_1(int i, int j) {
  return ((pref_hash_1[j] - pref_hash_1[i - 1] + m_1) * ppow_1[H.length() - j]) % m_1;
}
int hsh_2(int i, int j) {
  return ((pref_hash_2[j] - pref_hash_2[i - 1] + m_2) * ppow_2[H.length() - j]) % m_2;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string N;
  cin >> N >> H;

  if(N.length() > H.length()) {
    cout << "0\n"; 
    return 0;
  }

  H = ' ' + H;

  unordered_map<char, int> N_freq;
  for(char i: N) {
    N_freq[i]++;
  }

  ppow_1.resize(H.length());
  ppow_1[1] = 1;
  for(int i = 2; i < H.length(); i++) {
    ppow_1[i] = (ppow_1[i - 1] * p) % m_1;
  }
  ppow_2.resize(H.length());
  ppow_2[1] = 1;
  for(int i = 2; i < H.length(); i++) {
    ppow_2[i] = (ppow_2[i - 1] * p) % m_2;
  }
  pref_hash_1.resize(H.length());
  for(int i = 1; i < H.length(); i++) {
    pref_hash_1[i] = (pref_hash_1[i - 1] + (H[i] - 'a' + 1) * ppow_1[i]) % m_1;
  }
  pref_hash_2.resize(H.length());
  for(int i = 1; i < H.length(); i++) {
    pref_hash_2[i] = (pref_hash_2[i - 1] + (H[i] - 'a' + 1) * ppow_2[i]) % m_2;
  }

  unordered_map<char, int> slide_freq;
  for(int i = 1; i <= N.length(); i++) {
    slide_freq[H[i]]++;
  }
  set<pair<int, int>> ans;
  if(valid(slide_freq, N_freq)) {
    ans.insert({hsh_1(1, N.length()), hsh_2(1, N.length())});
  }
  for(int i = N.length() + 1, j = 2; i < H.length(); i++, j++) {
    slide_freq[H[j - 1]]--, slide_freq[H[i]]++;
    if(valid(slide_freq, N_freq)) {
      ans.insert({hsh_1(j, i), hsh_2(j, i)});
    }
  }
  
  cout << ans.size() << '\n';

  return 0;
}