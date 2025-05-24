/*
 * @lc app=leetcode.cn id=2942 lang=cpp
 *
 * [2942] 查找包含给定字符的单词
 */

// @lc code=start
class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> result;
        int i = 0;
        for (const string &word : words)
        {
            if (word.find(x) != string::npos)
            {
                result.push_back(i);
            }
            ++i;
        }
        return result;
    }
};
// @lc code=end
