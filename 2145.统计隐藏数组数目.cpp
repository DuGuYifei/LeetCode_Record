#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2145 lang=cpp
 *
 * [2145] 统计隐藏数组数目
 */

// @lc code=start
class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        if (lower > upper)
            return 0;
        long lowest = 0;
        long highest = 0;
        long sum = 0;
        for (const int &i : differences)
        {
            sum += i;
            lowest = min(lowest, sum);
            highest = max(highest, sum);
        }
        if (highest - lowest > upper - lower)
            return 0;
        // upper - lower + 1 - (lower - (lower + lowest) + (upper + highest - upper))
        // = upper - lower + 1 - lowest - highest
        return upper - lower + 1 + lowest - highest;
    }
};
// @lc code=end
