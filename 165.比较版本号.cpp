#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        std::vector<int> dot_version1;
        std::vector<int> dot_version2;

        int len1 = version1.size();
        int len2 = version2.size();
        int prevLen = 0;
        for (int i = 0; i < len1; i++)
        {
            if (version1[i] == '.')
            {
                dot_version1.emplace_back(std::stoi(version1.substr(prevLen, i)));
                prevLen = i + 1;
            }
        }
        dot_version1.emplace_back(std::stoi(version1.substr(prevLen, len1)));
        prevLen = 0;
        for (int i = 0; i < len2; i++)
        {
            if (version2[i] == '.')
            {
                dot_version2.emplace_back(std::stoi(version2.substr(prevLen, i)));
                prevLen = i + 1;
            }
        }
        dot_version2.emplace_back(std::stoi(version2.substr(prevLen, len2)));
        int count = std::max(dot_version1.size(), dot_version2.size());
        dot_version1.resize(count);
        dot_version2.resize(count);

        for (int i = 0; i < count; i++)
        {
            if (dot_version1[i] > dot_version2[i])
                return 1;
            if (dot_version1[i] < dot_version2[i])
                return -1;
        }

        return 0;
    }
};