/*
 * @lc app=leetcode.cn id=2894 lang=cpp
 *
 * [2894] 分类求和并作差
 */

// @lc code=start
class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        int num = n / m;
        // int sum1 = (m + num * m) * num / 2;
        // int sum2 = (1 + n) * n / 2 - sum1;
        // return sum2 - sum1;
        return (1 + n) * n / 2 - (m + num * m) * num;
    }
};
// @lc code=end
