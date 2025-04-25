#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2444 lang=cpp
 *
 * [2444] 统计定界子数组的数目
 */

// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int mini = INT32_MIN;
        int maxi = INT32_MAX;
        int indexLeftLower = -1;
        int indexLeftUpper = -1;
        int indexRight = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                indexLeftLower = indexLeftUpper = -1;
                indexRight = -1;
            }
            else
            {
                if (indexLeftLower == -1)
                {
                    indexLeftLower = i;
                }
                if (nums[i] == minK)
                {
                    indexLeftUpper = i;
                }
                if (nums[i] == maxK)
                {
                    indexRight = i;
                }
                if (indexLeftUpper != -1 && indexRight != -1)
                    ans += min(indexLeftUpper, indexRight) - indexLeftLower + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
