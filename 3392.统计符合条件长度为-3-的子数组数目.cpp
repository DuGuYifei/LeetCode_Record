/*
 * @lc app=leetcode.cn id=3392 lang=cpp
 *
 * [3392] 统计符合条件长度为 3 的子数组数目
 */

// @lc code=start
class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0, j = 1, k = 2; k < n; i = j, j = k, ++k)
        {
            if ((nums[i] + nums[k]) * 2 == nums[j])
            {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end
