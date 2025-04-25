#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=2845 lang=cpp
 *
 * [2845] 统计趣味子数组的数目
 */

// @lc code=start
class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        unordered_map<int, int> cnt; // 统计前缀和模 modulo 的余数出现的次数
        cnt[0] = 1;                  // 初始化 cnt[0] 为 1
        int pre;                     // 前缀和
        long long ans = 0;
        // (pre - pre') % modulo == k
        // pre' % modulo == (pre - k) % modulo
        for (const int &num : nums)
        {
            pre += (num % modulo == k ? 1 : 0);
            // 计算需要的前缀和模 modulo 的余数
            int target = (pre - k + modulo) % modulo; // + modulo 确保非负
            // 如果 target 在 cnt 中出现过，说明存在符合条件的子数组
            ans += cnt[target];
            // 计算当前前缀和模 modulo 的余数
            int mod = pre % modulo;
            // 更新 cnt 数组
            cnt[mod]++;
        }
        return ans;
    }
};
// @lc code=end
