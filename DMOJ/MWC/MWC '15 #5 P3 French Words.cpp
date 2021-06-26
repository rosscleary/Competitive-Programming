#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  unordered_set<string> line_1;
  for(int i = 0; i < N; i++) {
    string line_1_string;
    cin >> line_1_string;
    line_1.insert(line_1_string);
  }
  unordered_set<string> line_2;
  int answer = 0;
  for(int i = 0; i < M; i++) {
    string line_2_string;
    cin >> line_2_string;
    if(line_1.count(line_2_string) && !line_2.count(line_2_string)) {
      answer++;
      line_2.insert(line_2_string);
    }
  }
  cout << answer << '\n';

  return 0;
}