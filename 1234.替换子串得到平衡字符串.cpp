#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 *
 * https://leetcode-cn.com/problems/replace-the-substring-for-balanced-string/description/
 *
 * algorithms
 * Medium (34.97%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 26.3K
 * Testcase Example:  '"QWER"'
 *
 * 有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。
 *
 * 假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。
 *
 *
 *
 * 给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。
 *
 * 你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。
 *
 * 请返回待替换子串的最小可能长度。
 *
 * 如果原字符串自身就是一个平衡字符串，则返回 0。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "QWER"
 * 输出：0
 * 解释：s 已经是平衡的了。
 *
 * 示例 2：
 *
 *
 * 输入：s = "QQWE"
 * 输出：1
 * 解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "QQQW"
 * 输出：2
 * 解释：我们可以把前面的 "QQ" 替换成 "ER"。
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "QQQQ"
 * 输出：3
 * 解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s.length 是 4 的倍数
 * s 中只含有 'Q', 'W', 'E', 'R' 四种字符
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int balancedString(string s)
    {
        int cnt[26]{0};
        for (char &i : s)
            cnt[i - 'A']++;

        if (cnt[16] == cnt[22] && cnt[22] == cnt[4] && cnt[4] == cnt[17])
            return 0;

        int n = s.size();
        int target = n / 4;
        vector<int> more;
        if (cnt[16] > target)
        {
            cnt[16] -= target;
            more.emplace_back(16);
        }
        if (cnt[22] > target)
        {
            cnt[22] -= target;
            more.emplace_back(22);
        }
        if (cnt[4] > target)
        {
            cnt[4] -= target;
            more.emplace_back(4);
        }
        if (cnt[17] > target)
        {
            cnt[17] -= target;
            more.emplace_back(17);
        }

        int ans = INT_MAX;
        int left = 0, right = -1;

        for (int i = 0; i < n; i++)
        {
            right++;
            
            cnt[s[i] - 'A']--;

            bool satisfy = true;
            for (int &j : more)
                satisfy &= cnt[j] <= 0;
            
            if (satisfy)
            {
                while (!(count(more.begin(), more.end(), s[left] - 'A')) || cnt[s[left] - 'A'] < 0)
                    cnt[s[left++] - 'A']++;
                ans = min(ans, right - left + 1);
            }
        }
        return ans;
    }
};
// @lc code=end
