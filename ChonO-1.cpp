#include <bits/stdc++.h>
using namespace std;

int T, N;
int a[20][20];
int dp[1 << 20];

int solve() {
    int full = 1 << N;
    fill(dp, dp + full, -1);
    dp[0] = 0;

    for (int mask = 0; mask < full; ++mask) {
        int row = __builtin_popcount(mask);  // hàng hi?n t?i tuong ?ng v?i s? bit dã ch?n
        if (row >= N) continue;

        for (int col = 0; col < N; ++col) {
            if ((mask & (1 << col)) == 0) {  // n?u chua ch?n c?t col
                int newMask = mask | (1 << col);
                dp[newMask] = max(dp[newMask], dp[mask] + a[row][col]);
            }
        }
    }

    return dp[full - 1]; // t?t c? các c?t d?u dã ch?n
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> a[i][j];

        cout << solve() << '\n';
    }

    return 0;
}

