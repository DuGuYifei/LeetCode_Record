#include <unordered_map>
#include <vector>
/*
 * @lc app=leetcode.cn id=1399 lang=cpp
 *
 * [1399] 统计最大组的数目
 */

// @lc code=start
class Solution
{
public:
    int countLargestGroup(int n)
    {
        std::unordered_map<int, std::vector<int>> m;
        int maxCount = 0;
        int numGroups = 0;
        for (int i = 1; i <= n; ++i)
        {
            int sum = 0;
            int num = i;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            m[sum].push_back(i);
            if (m[sum].size() > maxCount)
            {
                maxCount = m[sum].size();
                numGroups = 1;
            }
            else if (m[sum].size() == maxCount)
            {
                ++numGroups;
            }
        }
        return numGroups;
    }
};
// @lc code=end
