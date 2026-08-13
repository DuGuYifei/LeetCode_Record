class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int counts[26]{};
        int left = 0, right = 0;
        int n = s.size();
        int ans = 1;
        for (; right < n; right++)
        {
            counts[s[right] - 'a']++;
            if (counts[s[right] - 'a'] > 2)
            {
                ans = max(ans, right - left);
                while (s[left] != s[right])
                {
                    counts[s[left] - 'a']--;
                    left++;
                }
                left++;
                counts[s[right] - 'a']--;
            }
        }
        ans = max(ans, right - left);
        return ans;
    }
};