/*
 * @lc app=leetcode.cn id=1550 lang=cpp
 *
 * [1550] 存在连续三个奇数的数组
 */

// @lc code=start
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int cnt = 0;
        for (const auto &num : arr)
        {
            if (num % 2 == 1)
            {
                cnt++;
                if (cnt == 3)
                {
                    return true;
                }
            }
            else
            {
                cnt = 0;
            }
        }
        return false;
    }
};
// @lc code=end
