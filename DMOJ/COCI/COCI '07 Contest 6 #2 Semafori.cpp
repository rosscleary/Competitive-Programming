#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e2 + 5, M2 = 3;

int N, L;
int lights[M1][M2];
int time_elapsed = 0;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> N >> L;
  for(int i = 0; i < N; i++) cin >> lights[i][0] >> lights[i][1] >> lights[i][2];

  for(int i = 0; i < N; i++) {
    if(i == 0) time_elapsed = lights[0][0];
    else time_elapsed += lights[i][0] - lights[i - 1][0];
    time_elapsed += max(0, lights[i][1] - (time_elapsed % (lights[i][1] + lights[i][2])));
  }
  time_elapsed += L - lights[N - 1][0];

  cout << time_elapsed << "\n";

  return 0;
}