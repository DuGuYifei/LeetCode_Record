#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=2488 lang=cpp
 *
 * [2488] 统计中位数为 K 的子数组
 *
 * https://leetcode.cn/problems/count-subarrays-with-median-k/description/
 *
 * algorithms
 * Hard (40.95%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 12.3K
 * Testcase Example:  '[3,2,1,4,5]\n4'
 *
 * 给你一个长度为 n 的数组 nums ，该数组由从 1 到 n 的 不同 整数组成。另给你一个正整数 k 。
 * 
 * 统计并返回 nums 中的 中位数 等于 k 的非空子数组的数目。
 * 
 * 注意：
 * 
 * 
 * 数组的中位数是按 递增 顺序排列后位于 中间 的那个元素，如果数组长度为偶数，则中位数是位于中间靠 左 的那个元素。
 * 
 * 
 * 例如，[2,3,1,4] 的中位数是 2 ，[8,4,3,5,1] 的中位数是 4 。
 * 
 * 
 * 子数组是数组中的一个连续部分。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,2,1,4,5], k = 4
 * 输出：3
 * 解释：中位数等于 4 的子数组有：[4]、[4,5] 和 [1,4,5] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,3,1], k = 3
 * 输出：1
 * 解释：[3] 是唯一一个中位数等于 3 的子数组。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i], k <= n
 * nums 中的整数互不相同
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    inline int sign(int num) {
        if (num == 0) {
            return 0;
        }
        return num > 0 ? 1 : -1;
    }

    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int kIndex = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == k) {
                kIndex = i;
                break;
            }
        }
        unordered_map<int, int> counts;
        counts[0] = 1;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += sign(nums[i] - k);
            if (i < kIndex) {
                counts[sum]++;
            } else {
                int prev0 = counts[sum];
                int prev1 = counts[sum - 1];
                ans += prev0 + prev1;
            }
        }
        return ans;
    }
};
// @lc code=end

