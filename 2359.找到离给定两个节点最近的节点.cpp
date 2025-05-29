#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=2359 lang=cpp
 *
 * [2359] 找到离给定两个节点最近的节点
 */

// @lc code=start
class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        if (node1 == node2)
        {
            return node1;
        }
        unordered_map<int, int> dist1, dist2; // 实际记录 1 才是 0 距离，即距离始终 +1
        int minimum = INT_MAX;
        int res = -1;
        dist1[node1] = 1;
        dist2[node2] = 1;
        while (edges[node1] != -1 && dist1[edges[node1]] == 0)
        {
            dist1[edges[node1]] = dist1[node1] + 1;
            node1 = edges[node1];
        }
        if (dist1[node2] > 0)
        {
            if (minimum > max(dist1[node2], dist2[node2]))
            {
                minimum = max(dist1[node2], dist2[node2]);
                res = node2;
            }
            else if (minimum == max(dist1[node2], dist2[node2]))
            {
                res = min(res, node2);
            }
        }
        while (edges[node2] != -1 && dist2[edges[node2]] == 0)
        {
            dist2[edges[node2]] = dist2[node2] + 1;
            node2 = edges[node2];
            if (dist1[node2] > 0)
            {
                if (minimum > max(dist1[node2], dist2[node2]))
                {
                    minimum = max(dist1[node2], dist2[node2]);
                    res = node2;
                }
                else if (minimum == max(dist1[node2], dist2[node2]))
                {
                    res = min(res, node2);
                }
            }
        }

        return res;
    }
};
// @lc code=end
