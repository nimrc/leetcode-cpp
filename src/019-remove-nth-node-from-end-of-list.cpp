//
// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> nodes(n + 1);
        ListNode *iter = head;

        while (iter != nullptr) {
            nodes.erase(nodes.begin());
            nodes.push_back(iter);
            iter = iter->next;
        }

        if (nodes[0] == nullptr)
            head = n == 1 ? nullptr : nodes[2];
        else
            nodes[0]->next = nodes[1]->next;

        return head;
    }
};

int main(int argc, char **argv)
{
    ListNode *list = leetcode::createList(54321);
    int n = 2;

    dump(list);

    ListNode *res = (new Solution)->removeNthFromEnd(list, n);

    dump(res);

    check(res, 5321);

    return 0;
}

