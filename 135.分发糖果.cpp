#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                ans[i] = ans[i - 1] + 1;
            }
        }
        int res = 0, compensation = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (i < n - 1 && ratings[i] > ratings[i + 1])
            {
                ++compensation;
            }
            else
            {
                compensation = 1;
            }

            res += max(ans[i], compensation);
        }

        return res;
    }
};
// @lc code=end
