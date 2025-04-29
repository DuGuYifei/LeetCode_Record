#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 */

// @lc code=start
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long ans = 0;
        int maxNum = INT32_MIN;
        int count = 0;
        int n = nums.size();
        vector<int> maxIndex(k, -1);
        int currentMaxIndex = -1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > maxNum)
            {
                maxNum = nums[i];
                count = 1;
                currentMaxIndex = 0;
                maxIndex[0] = i;
                ans = 0;
            }
            else if (nums[i] == maxNum)
            {
                ++currentMaxIndex;
                if (currentMaxIndex >= k)
                {
                    currentMaxIndex = 0;
                }
                maxIndex[currentMaxIndex] = i;
                count++;
            }
            if (count >= k)
            {
                int targetLeft = currentMaxIndex - k + 1;
                if (targetLeft < 0)
                {
                    targetLeft = currentMaxIndex + 1;
                }
                ans += maxIndex[targetLeft] + 1;
                        }
        }
        return ans;
    }
};
// @lc code=end
