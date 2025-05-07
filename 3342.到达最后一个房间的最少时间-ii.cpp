#include <vector>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=3342 lang=cpp
 *
 * [3342] 到达最后一个房间的最少时间 II
 */

// @lc code=start
class Solution
{
private:
    struct State
    {
        int x, y, dist, time;
        State(int x, int y, int dist) : x(x), y(y), dist(dist) {}
        bool operator<(const State &other) const
        {
            return dist > other.dist; // Min-heap based on distance
        }
    };

public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        dist[0][0] = 0;
        priority_queue<State> pq;
        pq.push(State(0, 0, 0));
        while (!pq.empty())
        {
            State curr = pq.top();
            pq.pop();
            int x = curr.x, y = curr.y, d = curr.dist;
            if (visited[x][y])
                continue;
            visited[x][y] = true;

            if (x == n - 1 && y == m - 1)
                return d;

            for (const auto &dir : directions)
            {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int newDist = max(moveTime[nx][ny], dist[x][y]) + (x + y) % 2 + 1;
                    if (newDist < dist[nx][ny])
                    {
                        dist[nx][ny] = newDist;
                        pq.push(State(nx, ny, newDist));
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
// @lc code=end
