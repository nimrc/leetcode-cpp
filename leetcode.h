//
// leetcode
// @link https://leetcode.com/
//

#ifndef LEETCODE_CPP_H
#define LEETCODE_CPP_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <assert.h>

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {}};

namespace leetcode
{

ListNode *createList(int seq)
{
    ListNode *head = nullptr, *tail = nullptr;
    int tmp;

    while (seq > 0) {
        tmp = seq % 10;
        seq /= 10;

        if (head == nullptr) {
            head = tail = new ListNode(tmp);
        } else {
            tail->next = new ListNode(tmp);
            tail = tail->next;
        }
    }

    return head;
}

}

void check(ListNode *list, int seq)
{
    int tmp = 0;
    ListNode *iter = list;

    while (seq > 0) {
        tmp = seq % 10;
        seq /= 10;

        assert(iter->val == tmp);
        iter = iter->next;
    }

    assert(iter == nullptr);
}

template<typename T>
void dump(const T &i)
{
    for (const auto &x: i)
        std::cout << x << " ";
    std::cout << std::endl;
}

void dump(ListNode *list)
{
    ListNode *iter = list;

    while (iter->next != nullptr) {
        std::cout << iter->val << " -> ";
        iter = iter->next;
    }

    std::cout << iter->val << std::endl;
}

#endif //LEETCODE_CPP_H
