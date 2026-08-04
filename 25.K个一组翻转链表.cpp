/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *currentChainStart;
    ListNode *currentChainEnd;
    ListNode *active;
    ListNode *activetNext;
    ListNode *prevEnd;

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *ans;
        currentChainStart = head;
        currentChainEnd = head;
        active = head;
        prevEnd = nullptr;

        for (int i = 0; i < k; i++)
        {
            activetNext = active->next;
            active->next = currentChainStart;
            currentChainStart = active;
            active = activetNext;
        }
        ans = currentChainStart;

        prevEnd = currentChainEnd;
        currentChainEnd->next = active;
        currentChainStart = active;
        currentChainEnd = active;
        int count = 0;
        while (active)
        {
            if (count == 0)
            {
                ListNode *tmp = active;
                int tmpCount = 0;
                while (tmp)
                {
                    tmpCount++;
                    if (tmpCount == k)
                    {
                        break;
                    }
                    tmp = tmp->next;
                }
                if (tmpCount % k)
                {
                    return ans;
                }
            }
            count++;

            activetNext = active->next;
            active->next = currentChainStart;
            currentChainStart = active;
            active = activetNext;

            if (count == k)
            {
                count = 0;
                prevEnd->next = currentChainStart;
                prevEnd = currentChainEnd;
                currentChainEnd->next = active;
                currentChainStart = active;
                currentChainEnd = active;
            }
        }
        if (count != 0)
        {
            currentChainEnd->next = nullptr;
            prevEnd->next = currentChainStart;
        }
        return ans;
    }
};