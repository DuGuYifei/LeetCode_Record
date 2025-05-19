#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3355 lang=cpp
 *
 * [3355] 零数组变换 I
 */

// @lc code=start
class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> delta(n + 1, 0);
        for (auto &query : queries)
        {
            int l = query[0], r = query[1];
            delta[l] += 1;
            delta[r + 1] -= 1;
        }

        vector<int> prefix(n, 0);
        prefix[0] = delta[0];
        for (int i = 1; i < n; ++i)
        {
            prefix[i] = prefix[i - 1] + delta[i];
        }

        for (int i = 0; i < n; ++i)
        {
            if (prefix[i] < nums[i])
                return false;
        }

        return true;
    }
};
// @lc code=end
