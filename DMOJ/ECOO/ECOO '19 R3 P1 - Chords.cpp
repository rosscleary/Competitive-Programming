#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MV = 1e6 + 5;

int test_case = 10;
int N;
set<int> values_occured;
vector<int> freq;
int max_value;
LL answer;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  while(test_case--) {
    cin >> N;
    values_occured.clear();
    freq.clear();
    freq.resize(MV);
    max_value = 0;
    for(int i = 0; i < N; i++) {
      int value;
      cin >> value;
      values_occured.insert(value);
      freq[value]++;
      max_value = max(max_value, value);
    }
    
    answer = 0;
    for(auto element : values_occured) {
      int pair_count = (freq[element] * (freq[element] - 1)) / 2;
      for(int j = 2 * element; j <= max_value; j += element) {
        pair_count += freq[j];
      }
      answer += pair_count * freq[element];
    }

    cout << answer << "\n";
  }

  return 0;
}