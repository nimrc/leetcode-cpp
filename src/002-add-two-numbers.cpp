#include <leetcode.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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

    static ListNode *createList(int number)
    {
        ListNode *head = nullptr, *tail = nullptr;
        int tmp;

        while (number > 0) {
            tmp = number % 10;
            number /= 10;

            if (head == nullptr) {
                head = tail = new ListNode(tmp);
            } else {
                tail->next = new ListNode(tmp);
                tail = tail->next;
            }
        }

        return head;
    }
};

int main(int argc, char **argv)
{
    ListNode *l1 = Solution::createList(342);
    ListNode *l2 = Solution::createList(465);

    ListNode *res = (new Solution)->addTwoNumbers(l1, l2);

    assert(res->val == 7);
    assert(res->next->val == 0);
    assert(res->next->next->val == 8);
    assert(res->next->next->next == nullptr);

    return 0;
}
