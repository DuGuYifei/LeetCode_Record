/*
 * @lc app=leetcode.cn id=2929 lang=cpp
 *
 * [2929] 给小朋友们分糖果 II
 */

// @lc code=start
class Solution
{
public:
    long long cal(int x)
    {
        if (x < 0)
        {
            return 0;
        }
        return (long)x * (x - 1) / 2;
    }

    long long distributeCandies(int n, int limit)
    {
        return cal(n + 2) - 3 * cal(n - limit + 1) + 3 * cal(n - (limit + 1) * 2 + 2) - cal(n - 3 * (limit + 1) + 2);
    }
};
// @lc code=end
