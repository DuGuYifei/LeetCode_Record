#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2901 lang=cpp
 *
 * [2901] 最长相邻不相等子序列 II
 */

// @lc code=start
class Solution
{
public:
    bool checkHammingDistance(const string &a, const string &b)
    {
        if (a.size() != b.size())
        {
            return false;
        }
        int distance = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != b[i])
            {
                ++distance;
                if (distance > 1)
                {
                    return false;
                }
            }
        }
        return distance == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxIndex = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (groups[i] != groups[j] && checkHammingDistance(words[i], words[j]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIndex])
            {
                maxIndex = i;
            }
        }

        vector<string> result;
        for (int i = maxIndex; i != -1; i = prev[i])
        {
            result.push_back(words[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
