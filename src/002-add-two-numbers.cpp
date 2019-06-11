#include <leetcode.h>

using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr, *tail = nullptr;
        int tmp = 0;

        while (l1 != nullptr || l2 != nullptr || tmp != 0) {
            if (l1 != nullptr) {
                tmp += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                tmp += l2->val;
                l2 = l2->next;
            }

            if (head == nullptr) {
                head = tail = new ListNode(tmp % 10);
            } else {
                tail->next = new ListNode(tmp % 10);
                tail = tail->next;
            }

            tmp /= 10;
        }

        return head;
    }
};

int main(int argc, char **argv)
{
    ListNode *l1 = leetcode::createList(342);
    ListNode *l2 = leetcode::createList(465);

    ListNode *res = (new Solution)->addTwoNumbers(l1, l2);

    check(res, 807);

    return 0;
}
