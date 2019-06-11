//
// 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/
//
#include <leetcode.h>

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main()
{
    ListNode *list = leetcode::createList(9154);

    dump(list);

    (new Solution)->deleteNode(list->next); // ListNode(5)

    dump(list);

    check(list, 914);

}


