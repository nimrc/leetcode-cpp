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

#define NONE -1

#define assert_true(val) assert(val == true)

struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {}};

struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}};

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

TreeNode *createTree(std::vector<int> nodes, int idx = 0)
{
    if (idx >= nodes.size())
        return nullptr;

    if (nodes[idx] == NONE)
        return nullptr;

    auto *node = new TreeNode(nodes[idx]);

    node->left = createTree(nodes, idx + 1);
    node->right = createTree(nodes, idx + 2);

    return node;
};

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

void dump(TreeNode *tree, bool root = true)
{
    if (root) {
        std::cout << " " << tree->val << std::endl;
        std::cout << "/ \\" << std::endl;
    }

    if (tree->left) {
        std::cout << tree->left->val << "   ";
        dump(tree->left, false);
    }

    if (tree->right) {
        std::cout << "   " << tree->right->val;
        std::cout << std::endl;
        std::cout << "   / \\" << std::endl;
        dump(tree->right, false);
    }
}

#endif //LEETCODE_CPP_H
