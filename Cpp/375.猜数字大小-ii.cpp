/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> dp;
public:
    int getMoneyAmount(int n) {
        dp.resize(n + 1, vector<int>(n + 1, 0));
        return dfs(1, n);
    }
    
    int dfs(int l, int r) {
        if (l >= r) return 0;
        if (dp[l][r] != 0) {
            return dp[l][r];
        }
        int ans = 0x3f3f3f3f;
        for (int x = l; x <= r; ++x) {
            int val = max(dfs(l, x - 1), dfs(x + 1, r)) + x;
            ans = min(ans, val);
        }
        dp[l][r] = ans;
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    int res;
    
    /**
     输入：n = 10
     输出：16
     解释：制胜策略如下：
     - 数字范围是 [1,10] 。你先猜测数字为 7 。
         - 如果这是我选中的数字，你的总费用为 $0 。否则，你需要支付 $7 。
         - 如果我的数字更大，则下一步需要猜测的数字范围是 [8,10] 。你可以猜测数字为 9 。
             - 如果这是我选中的数字，你的总费用为 $7 。否则，你需要支付 $9 。
             - 如果我的数字更大，那么这个数字一定是 10 。你猜测数字为 10 并赢得游戏，总费用为 $7 + $9 = $16 。
             - 如果我的数字更小，那么这个数字一定是 8 。你猜测数字为 8 并赢得游戏，总费用为 $7 + $9 = $16 。
         - 如果我的数字更小，则下一步需要猜测的数字范围是 [1,6] 。你可以猜测数字为 3 。
             - 如果这是我选中的数字，你的总费用为 $7 。否则，你需要支付 $3 。
             - 如果我的数字更大，则下一步需要猜测的数字范围是 [4,6] 。你可以猜测数字为 5 。
                 - 如果这是我选中的数字，你的总费用为 $7 + $3 = $10 。否则，你需要支付 $5 。
                 - 如果我的数字更大，那么这个数字一定是 6 。你猜测数字为 6 并赢得游戏，总费用为 $7 + $3 + $5 = $15 。
                 - 如果我的数字更小，那么这个数字一定是 4 。你猜测数字为 4 并赢得游戏，总费用为 $7 + $3 + $5 = $15 。
             - 如果我的数字更小，则下一步需要猜测的数字范围是 [1,2] 。你可以猜测数字为 1 。
                 - 如果这是我选中的数字，你的总费用为 $7 + $3 = $10 。否则，你需要支付 $1 。
                 - 如果我的数字更大，那么这个数字一定是 2 。你猜测数字为 2 并赢得游戏，总费用为 $7 + $3 + $1 = $11 。
     在最糟糕的情况下，你需要支付 $16 。因此，你只需要 $16 就可以确保自己赢得游戏。
     */
    n = 10;
    res = 16;
    assert(res == Solution().getMoneyAmount(n));
    
    /**
     输入：n = 1
     输出：0
     解释：只有一个可能的数字，所以你可以直接猜 1 并赢得游戏，无需支付任何费用。
     */
    n = 1;
    res = 0;
    assert(res == Solution().getMoneyAmount(n));
    
    /**
     输入：n = 2
     输出：1
     解释：有两个可能的数字 1 和 2 。
     - 你可以先猜 1 。
         - 如果这是我选中的数字，你的总费用为 $0 。否则，你需要支付 $1 。
         - 如果我的数字更大，那么这个数字一定是 2 。你猜测数字为 2 并赢得游戏，总费用为 $1 。
     最糟糕的情况下，你需要支付 $1 。
     */
    n = 2;
    res = 1;
    assert(res == Solution().getMoneyAmount(n));

    cout << "OK~" << endl;

    return 0;
}
