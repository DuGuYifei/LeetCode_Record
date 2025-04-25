#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=2799 lang=cpp
 *
 * [2799] 统计完全子数组的数目
 */

// @lc code=start
class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        unordered_map<int, int> count;
        unordered_set<int> uniqueElements(nums.begin(), nums.end());
        int uniqueCount = uniqueElements.size();
        int n = nums.size();
        int ans = 0;
        for (int left = 0, right = 0; left < n; left++)
        {
            if (left > 0)
            {
                int currentNum = nums[left - 1];
                count[currentNum]--;
                if (count[currentNum] == 0)
                {
                    count.erase(currentNum);
                }
            }
            while (right < n && count.size() < uniqueCount)
            {
                int add = nums[right];
                count[add]++;
                right++;
            }
            if (count.size() == uniqueCount)
            {
                ans += n - right + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
