//
// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *tmp = swapPairs(head->next->next);
        ListNode *next = head->next;

        next->next = head;
        head->next = tmp;
        head = next;

        return head;
    }
};

int main(int argc, char **argv)
{
    ListNode *list = leetcode::createList(4321);

    dump(list);

    ListNode *res = (new Solution)->swapPairs(list);

    dump(res);

    check(res, 3412);

    return 0;
}
