#include <vector>
#include <numeric>
using namespace std;

class Solution
{
private:
    vector<bool> removed;
    vector<vector<int>> aUseB;
    vector<vector<int>> bUsedByA;

    void dfs(int i)
    {
        if (removed[i])
            return;
        removed[i] = true;

        for (int j = 0; j < aUseB[i].size(); j++)
        {
            dfs(aUseB[i][j]);
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        removed = vector<bool>(n);
        aUseB = vector<vector<int>>(n);
        bUsedByA = vector<vector<int>>(n);
        for (const vector<int> &i : invocations)
        {
            aUseB[i[0]].emplace_back(i[1]);
            bUsedByA[i[1]].emplace_back(i[0]);
        }
        dfs(k);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!removed[i])
            {
                ans.emplace_back(i);
            }
            else
            {
                for (int j = 0; j < bUsedByA[i].size(); j++)
                {
                    if (!removed[bUsedByA[i][j]])
                    {
                        vector<int> tmp(n);
                        iota(tmp.begin(), tmp.end(), 0);
                        return tmp;
                    }
                }
            }
        }
        return ans;
    }
};