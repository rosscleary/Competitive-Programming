#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

int T, N, K;
ll V[100005];
vector<vector<ll>> dp;

ll solve(int cur, int s) {
    if (cur >= N + 1)
        return 0;
    if (dp[cur][s] != -1)
        return dp[cur][s];

    ll ans = solve(cur + 1, s);
    ll sum = 0;
    int took = 0;

    for (int i = cur; i <= N && took <= K; i++) {
        took++;
        if (i == N)
            took += s;
        if (took > K)
            break;
        sum += V[i];
        ans = max(ans, solve(i + 2, (cur == 1 ? i : s)) + sum);
    }
    return dp[cur][s] = ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> T;
    while (T--) {
        cin >> N >> K;
        dp.clear(), dp.resize(N + 5, vector<ll>(K + 5));
        for (int i = 1; i <= N; i++)
            cin >> V[i];
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= K; j++) {
                dp[i][j] = -1;
            }
        }
        cout << solve(1, 0) << '\n';
    }
}