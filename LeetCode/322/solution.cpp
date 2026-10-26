#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 5};
    vector<int> b = {2};
    vector<int> c = {1};
    cout << s.coinChange(a, 11) << " (expected 3)" << endl;
    cout << s.coinChange(b, 3) << " (expected -1)" << endl;
    cout << s.coinChange(c, 0) << " (expected 0)" << endl;
    return 0;
}
