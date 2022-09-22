#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=854 lang=cpp
 *
 * [854] 相似度为 K 的字符串
 */

// @lc code=start
class Solution
{
public:
    int dfs(const string &s1, unordered_map<char, vector<char>> &erridx, int i, const char &le)
    {
        if (s1[i] == le)
            return 0;
        int res = 20;
        unordered_map<char, vector<char>> e = erridx;
        for (auto &j : e[s1[i]])
        {
            if (~j)
            {
                int it = i;
                i = j;
                j = -1;
                int times = dfs(s1, e, i, le) + 1;
                if (times < res)
                {
                    res = times;
                    erridx = e;
                }
                j = i;
                i = it;
            }
        }
        return res;
    }

    int kSimilarity(string s1, string s2)
    {
        unordered_map<char, vector<char>> erridx; // length [1,20] 所以 vector char 代替 vector int
        int n = s1.size();
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                erridx[s2[i]].push_back(i);
            }
        }
        int ans = 0;
        for (auto &[le, ids] : erridx)
        {
            for (auto &i : ids)
            {
                if(~i)
                {
                    ans += dfs(s1, erridx, i, le);
                    i = -1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
