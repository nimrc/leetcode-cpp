//
// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *res = nullptr;
        if (l1 == nullptr)
            return l2;

        if (l2 == nullptr)
            return l1;

        if (l1->val < l2->val) {
            res = l1;
            res->next = mergeTwoLists(l1->next, l2);
        } else {
            res = l2;
            res->next = mergeTwoLists(l1, l2->next);
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    ListNode *l1 = leetcode::createList(421);
    ListNode *l2 = leetcode::createList(431);

    dump(l1);
    dump(l2);

    ListNode *res = (new Solution)->mergeTwoLists(l1, l2);

    dump(res);
    check(res, 443211);

    return 0;
}
