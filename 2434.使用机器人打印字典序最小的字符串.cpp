/*
 * @lc app=leetcode.cn id=2434 lang=cpp
 *
 * [2434] 使用机器人打印字典序最小的字符串
 */

// @lc code=start
class Solution
{
public:
    string robotWithString(string s)
    {
        unordered_map<char, int> cnt;
        // 统计每个字符出现的次数
        for (char c : s)
        {
            cnt[c]++;
        }

        stack<char> stk;         // 模拟机器人中的栈
        string res;              // 最终结果字符串
        char minCharacter = 'a'; // 当前还存在于字符串中的最小字符

        for (char c : s)
        {
            stk.emplace(c); // 将当前字符放入机器人栈中
            cnt[c]--;       // 当前字符剩余次数减少

            // 更新当前最小的存在字符（跳过已经用完的字符）
            while (minCharacter != 'z' && cnt[minCharacter] == 0)
            {
                minCharacter++;
            }

            // 当栈顶字符小于等于当前最小存在字符时，可以将其弹出放入结果中
            while (!stk.empty() && stk.top() <= minCharacter)
            {
                res.push_back(stk.top());
                stk.pop();
            }
        }

        return res;
    }
};
// @lc code=end
