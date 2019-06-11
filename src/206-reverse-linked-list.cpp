//
// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/
//

#include <leetcode.h>

using namespace std;

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *node, *res = nullptr, *iter = head;

        while (iter != nullptr) {
            node = new ListNode(iter->val);

            if (res == nullptr) {
                res = node;
            } else {
                node->next = res;
                res = node;
            }

            iter = iter->next;
        }

        return res;
    }
};

int main(int argc, char **argv)
{
    ListNode *list = leetcode::createList(54321);

    dump(list);

    ListNode *res = (new Solution)->reverseList(list);

    dump(res);

    check(res, 12345);

    return 0;
}

