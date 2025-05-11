/*
 * @lc app=leetcode.cn id=2094 lang=cpp
 *
 * [2094] 找出 3 位偶数
 */

// @lc code=start
class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> ans;
        int maps[10] = {};
        for (const int &digit : digits)
        {
            maps[digit]++;
        }
        for (int i = 1; i < 10; i++)
        {
            if (maps[i] == 0)
                continue;
            for (int j = 0; j < 10; j++)
            {
                if (maps[j] == 0)
                    continue;
                if (i == j && maps[i] < 2)
                    continue;
                for (int k = 0; k < 10; k += 2)
                {
                    if (maps[k] == 0)
                        continue;
                    if (i == j && j == k && maps[i] < 3)
                        continue;
                    else if (i == j && maps[i] < 2)
                        continue;
                    else if (j == k && maps[j] < 2)
                        continue;
                    else if (i == k && maps[i] < 2)
                        continue;
                    ans.push_back(i * 100 + j * 10 + k);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
