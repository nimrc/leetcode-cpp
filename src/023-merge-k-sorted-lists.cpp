//
// 23. Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;

        int tmp = INT_MAX, idx = 0;
        ListNode *res = nullptr, *tail = nullptr;
        bool empty = false;

        while (!empty) {
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] == nullptr) {
                    empty = true;
                } else {
                    if (lists[i]->val < tmp) {
                        tmp = lists[i]->val;
                        idx = i;

                    }
                }
            }

            if (lists[idx] != nullptr) {
                if (res == nullptr) {
                    res = tail = new ListNode(tmp);
                } else {
                    tail->next = new ListNode(tmp);
                    tail = tail->next;
                }

                lists[idx] = lists[idx]->next;

                empty = false;
            }

            tmp = INT_MAX;
        }

        return res;
    }

};

int main()
{
    vector<ListNode *> lists = {
        leetcode::createList(541),
        leetcode::createList(431),
        leetcode::createList(62),
    };

    for (auto &l: lists)
        dump(l);

    ListNode *res = (new Solution)->mergeKLists(lists);

    dump(res);

    check(res, 65443211);

    return 0;
}
