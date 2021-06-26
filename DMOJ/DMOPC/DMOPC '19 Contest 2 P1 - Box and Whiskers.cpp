#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 5;

int N;
vector<double> a;
vector<double> q_1, q_3;
double min_value = 1e6, max_value = 0, q_1_answer, q_2_answer, q_3_answer;

double median(vector<double> values) {
  int size = values.size();
  if(size % 2 == 0) return (values[size / 2] + values[(size / 2) - 1]) / 2.0;
  return values[size / 2];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> N;
  for(int i = 0; i < N; i++) {
    double value;
    cin >> value;
    a.push_back(value);
    min_value = min(min_value, a[i]);
    max_value = max(max_value, a[i]);
  }

  sort(a.begin(), a.end());
  for(int i = 0; i < N / 2; i++) q_1.push_back(a[i]);
  for(int i = (N / 2) + ((N % 2 == 0) ? 0 : 1); i < N; i++) q_3.push_back(a[i]);

  q_1_answer = median(q_1);
  q_2_answer = median(a);
  q_3_answer = median(q_3);

  cout << setprecision(9) << fixed;
  cout << min_value << " " << max_value << " " << q_1_answer << " " << q_2_answer << " " << q_3_answer << "\n";
 
  return 0;
}