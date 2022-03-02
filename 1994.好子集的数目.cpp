#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1994 lang=cpp
 *
 * [1994] 好子集的数目
 */

// @lc code=start
class Solution
{
    int mod = 1000000007;
    int premier[18] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 6, 10, 14, 15, 21, 22, 26, 30};
    //特殊：6，10，14，15，21，22，26，30
    int freq[31] = {0};

public:
    int numberOfGoodSubsets(vector<int> &nums)
    {
        int ans = 1;
        {
            for (int &i : nums)
            {
                freq[i]++;
            }
            for (int &i : premier)
            {
                if (freq[i] != 0)
                {
                    ans *= 2;
                }
            }
        }
    }

    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};
// @lc code=end
