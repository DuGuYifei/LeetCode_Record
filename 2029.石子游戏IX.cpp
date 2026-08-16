class Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {
        int counts[3]{};
        for (const int i : stones)
        {
            counts[i % 3]++;
        }
        // 11212121...
        // 22121212...
        // 11 21 21 22
        // 22 12 12 11
        if (counts[0] % 2)
        {
            return abs(counts[2] - counts[1]) > 2;
        }
        return counts[1] >= 1 && counts[2] >= 1;
    }
};