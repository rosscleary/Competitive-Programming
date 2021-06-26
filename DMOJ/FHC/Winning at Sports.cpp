#include <bits/stdc++.h>
using namespace std;

#define LL long long

#define maxvalue 2000
#define mod 1000000007

LL dp_1[maxvalue + 1][maxvalue + 1] = {0};
LL dp_2[maxvalue + 1][maxvalue + 1] = {0};
int T;
int score_1, score_2;
char dash;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int high = 0; high <= 2000; high++) dp_1[high][0] = 1;

  for (int high = 1; high <= 2000; high++) {
    for (int low = 1; low < high; low++) {
      dp_1[high][low] = dp_1[high][low - 1];
      if (high - 1 > low) dp_1[high][low] += dp_1[high - 1][low];
      dp_1[high][low] %= mod;
    }
  }

  for (int high = 0; high <= 2000; high++) dp_2[high][0] = 1;

  for (int high = 1; high <= 2000; high++) {
    for (int low = 1; low <= high; low++) {
      dp_2[high][low] = dp_2[high][low - 1];
      if (high > low) dp_2[high][low] += dp_2[high - 1][low];
      dp_2[high][low] %= mod;
    }
  }

  cin >> T;
  int test_case = 1;
  while (T--) {
    cin >> score_1 >> dash >> score_2;
    cout << "Case #" << test_case << ": " << dp_1[score_1][score_2] << " " << dp_2[score_2][score_2] << "\n";
    test_case++;
  }

  return 0;
}