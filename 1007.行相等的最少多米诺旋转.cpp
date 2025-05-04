#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=1007 lang=cpp
 *
 * [1007] 行相等的最少多米诺旋转
 */

// @lc code=start
class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        unordered_map<int, pair<int, int>> m;
        int ansTop = INT64_MAX;
        int ansBottom = INT64_MAX;
        int n = tops.size();
        for (int i = 0; i < n; i++)
        {
            m[tops[i]].first++;
            m[bottoms[i]].second++;
            if (m[tops[i]].first + m[tops[i]].second < i + 1 && m[bottoms[i]].first + m[bottoms[i]].second < i + 1)
            {
                return -1;
            }
        }
        if (m[tops[n - 1]].first + m[tops[n - 1]].second == n)
        {
            ansTop = abs()
        }
        if (m[bottoms[n - 1]].first + m[bottoms[n - 1]].second == n)
        {
            ansBottom = min(n - m[bottoms[n - 1]].first, n - m[bottoms[n - 1]].second);
        }
        return min(ansTop, ansBottom);
    }
};
// @lc code=end
