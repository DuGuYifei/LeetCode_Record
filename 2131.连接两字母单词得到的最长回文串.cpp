#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=2131 lang=cpp
 *
 * [2131] 连接两字母单词得到的最长回文串
 */

// @lc code=start
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> seen;
        int count_double = 0;
        int ans = 0;
        for (const string &word : words)
        {
            if (word[0] == word[1])
            {
                // 处理双字母回文
                if (seen[word])
                {
                    ans += 4; // 找到一对可以组成回文的单词
                    seen[word] -= 1;
                    count_double -= 1;
                }
                else
                {
                    seen[word] += 1;   // 记录当前单词
                    count_double += 1; // 记录双字母回文的数量
                }
            }
            else
            {
                string rev = {word[1], word[0]}; // 反转单词
                if (seen.count(rev))
                {
                    ans += 4; // 找到一对可以组成回文的单词
                    seen[rev] -= 1;
                }
                else
                {
                    seen[word] += 1; // 记录当前单词
                }
            }
        }
        // 如果有双字母回文的单词，且没有被完全配对，可以在中间放一个
        if (count_double > 0)
        {
            ans += 2; // 可以放一个双字母回文单词在中间
        }
        return ans;
    }
};
// @lc code=end
