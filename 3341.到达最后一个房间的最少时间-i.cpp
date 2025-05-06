#include <queue>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=3341 lang=cpp
 *
 * [3341] 到达最后一个房间的最少时间 I
 */

// @lc code=start
class Solution
{
private:
    struct State
    {
        int x;
        int y;
        int dis;
        State(int x, int y, int dis) : x(x), y(y), dis(dis) {};
        bool operator<(const State &rth) const
        {
            return dis > rth.dis;
        }
    };

public:
    const int inf = 0x3f3f3f3f;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右 下 左 上
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();

        vector<vector<int>> dis(n, vector<int>(m, inf));
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        dis[0][0] = 0;
        priority_queue<State> pq;
        pq.push(State(0, 0, 0));
        while (!pq.empty())
        {
            State s = pq.top();
            pq.pop();
            if (vis[s.x][s.y])
                continue;
            vis[s.x][s.y] = true;
            for (int i = 0; i < 4; i++)
            {
                int nx = s.x + dir[i][0];
                int ny = s.y + dir[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                int dist = max(dis[s.x][s.y], moveTime[nx][ny]) + 1;
                if (dis[nx][ny] > dist)
                {
                    dis[nx][ny] = dist;
                    pq.push(State(nx, ny, dist));
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};
// @lc code=end
