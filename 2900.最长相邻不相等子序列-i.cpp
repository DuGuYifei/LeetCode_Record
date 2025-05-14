#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2900 lang=cpp
 *
 * [2900] 最长相邻不相等子序列 I
 */

// @lc code=start
class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> result;
        int n = words.size();
        result.push_back(words[0]);
        for (int i = 1; i < n; ++i)
        {
            if (groups[i] != groups[i - 1])
            {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};
// @lc code=end
