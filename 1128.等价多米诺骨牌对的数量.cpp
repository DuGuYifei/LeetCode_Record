#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        unordered_map<int, int> count;
        int ans = 0;
        for (auto &d : dominoes)
        {
            int key = 1 << d[0] | 1 << d[1];
            ans += count[key];
            count[key]++;
        }
        return ans;
    }
};
// @lc code=end
