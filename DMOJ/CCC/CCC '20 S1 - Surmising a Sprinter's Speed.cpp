#include <bits/stdc++.h>
using namespace std;

#define maxN 100000

int N;
double T, X;
pair<double, double> time_position[maxN + 1];
double largest_speed = 0, speed;

void max_self(double &current, double new_value) {
  if (new_value > current) {
    current = new_value;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> T >> X;
    time_position[i] = make_pair(T, X);
  }

  sort(time_position + 1, time_position + N + 1);

  for (int i = 1; i < N; i++) {
    speed = abs((time_position[i + 1].second - time_position[i].second) / (time_position[i + 1].first - time_position[i].first));
    max_self(largest_speed, speed);
  }

  cout << setprecision(9) << fixed << largest_speed << "\n";

  return 0;
}