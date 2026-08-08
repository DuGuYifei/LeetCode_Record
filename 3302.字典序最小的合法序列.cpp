#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> validSequence(string word1, string word2)
    {
        // 从word1中能匹配到 word2[i:] 所有字符的最晚位置，这样就可以顺序暴力来假设每个可能是更改的那个字符
        int m = word1.size();
        int n = word2.size();
        vector<int> latest(n, -1);
        for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; i--)
        {
            if (word1[i] == word2[j])
            {
                latest[j] = i;
                j--;
            }
        }
        vector<int> res;
        bool hasChange = false;
        int j = 0;
        for (int i = 0; i < m && j < n; i++)
        {
            if (word1[i] != word2[j])
            {
                if (hasChange)
                {
                    continue;
                }
                if (j + 1 == n || i < latest[j + 1])
                {
                    res.push_back(i);
                    hasChange = true;
                    j++;
                }
            }
            else
            {
                res.push_back(i);
                j++;
            }
        }
        if (j != n)
            return {};
        return res;
    }
};