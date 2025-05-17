#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        size_t n = nums.size();
        int left = 0, right = n - 1, current = 0;
        while (current <= right)
        {
            if (nums[current] == 0)
            {
                swap(nums[left++], nums[current]);
                ++current;
            }
            else if (nums[current] == 2)
                swap(nums[current], nums[right--]);
            else
                ++current;
        }

        return;
    }
};
// @lc code=end
