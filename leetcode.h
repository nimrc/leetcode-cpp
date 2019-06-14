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
#include <queue>
#include <assert.h>

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#define NONE -1

#define blank(n) std::string(n, ' ')
#define assert_equal(actual, expect) assert(actual == expect)
#define assert_true(val) assert_equal(val, true)
#define assert_false(val) assert_equal(val, false)
#define assert_null(val) assert_equal(val, nullptr)

struct ListNode { int val; ListNode *next; ListNode(int x) : val(x), next(nullptr) {}};

struct TreeNode { int val; TreeNode *left; TreeNode *right; TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}};

typedef TreeNode *Tree;

namespace leetcode
{
// create new linked list
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
// create new binary tree
Tree createTree(std::vector<int> nodes, int idx = 0)
{
    if (idx >= nodes.size())
        return nullptr;

    if (nodes[idx] == NONE)
        return nullptr;

    auto *node = new TreeNode(nodes[idx]);

    node->left = createTree(nodes, idx * 2 + 1);
    node->right = createTree(nodes, idx * 2 + 2);

    return node;
};

// get binary tree depth
int treeDepth(TreeNode *root)
{
    int depth = 0;

    if (root != nullptr) {
        std::queue<TreeNode *> Q;
        Q.push(root);

        while (!Q.empty()) {
            ++depth;
            for (int i = 0, size = Q.size(); i < size; ++i) {
                TreeNode *node = Q.front();
                Q.pop();

                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
        }
    }

    return depth;
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
