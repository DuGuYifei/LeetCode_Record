#include <algorithm>
#include <vector>
#include <set>
using namespace std;
/*
 * @lc app=leetcode.cn id=2071 lang=cpp
 *
 * [2071] 你可以安排的最多任务数目
 */

// @lc code=start
class Solution
{
public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength)
    {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int n = tasks.size();
        int m = workers.size();

        int l = 0, r = min(n, m);

        auto canAssign = [&](int taskNum) -> bool
        {
            int p = pills;
            multiset<int> ws;
            for (int i = 0; i < m; i++)
            {
                ws.insert(workers[i]);
            }
            for (int i = taskNum - 1; i >= 0; i--)
            {
                int task = tasks[i];
                auto it = prev(ws.end());
                if (*it >= task)
                {
                    ws.erase(it);
                }
                else
                {
                    if (p <= 0)
                        return false;
                    auto w = ws.lower_bound(task - strength);
                    if (w == ws.end())
                        return false;
                    --p;
                    ws.erase(w);
                }
            }
            return true;
        };

        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1; // 取中间值 1 + 4 / 2 = 2
            if (canAssign(mid))
            {
                l = mid;
                ans = mid;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};
// @lc code=end
