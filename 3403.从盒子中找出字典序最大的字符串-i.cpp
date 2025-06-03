#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3403 lang=cpp
 *
 * [3403] 从盒子中找出字典序最大的字符串 I
 */

// @lc code=start
class Solution
{
public:
    string answerString(string word, int numFriends)
    {
        if (numFriends == 1)
        {
            return word;
        }
        int n = word.size();
        string res;
        for (int i = 0; i < n; i++)
        {
            res = max(res, word.substr(i, min(n - numFriends + 1, n - i)));
        }
        return res;
    }
};
// @lc code=end
