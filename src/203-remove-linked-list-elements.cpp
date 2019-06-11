//
// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/
//

#include <leetcode.h>

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *iter = head;

        while (iter != nullptr) {
            if (iter->val == val) {
                iter = iter->next;
                head = iter;
            } else {
                while (iter->next && iter->next->val == val)
                    iter->next = iter->next->next;

                iter = iter->next;
            }
        }

        return head;
    }
};

int main(int argc, char **argv)
{
    ListNode *list = leetcode::createList(6543621);
    int val = 6;

    dump(list);

    auto res = (new Solution)->removeElements(list, val);

    dump(res);

    check(res, 54321);

    return 0;
}
