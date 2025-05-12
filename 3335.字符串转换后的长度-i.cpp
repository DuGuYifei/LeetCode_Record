#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=3335 lang=cpp
 *
 * [3335] 字符串转换后的长度 I
 */

// @lc code=start
class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        int cnt[26] = {};
        for (char &c : s)
        {
            ++cnt[c - 'a'];
        }
        int temp0 = 0, temp = 0;
        for (int i = 0; i < t; ++i)
        {
            temp0 = cnt[0];
            cnt[0] = cnt[25];
            temp = cnt[1];
            cnt[1] = (temp0 + cnt[25]) % 1000000007;
            for (int j = 2; j < 26; ++j)
            {
                temp0 = cnt[j];
                cnt[j] = temp;
                temp = temp0;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            ans = (ans + cnt[i]) % 1000000007;
        }
        return ans;
    }
};
// @lc code=end
