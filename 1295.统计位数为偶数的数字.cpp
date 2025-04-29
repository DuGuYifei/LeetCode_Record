/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count = 0;
        for (const int &num : nums)
        {
            int digits = 0;
            int n = num;
            while (n > 0)
            {
                n /= 10;
                ++digits;
            }
            if (digits % 2 == 0)
            {
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end
