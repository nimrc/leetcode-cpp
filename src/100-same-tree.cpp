//
// 100. Same Tree
// https://leetcode.com/problems/same-tree/
//
#include <leetcode.h>

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
            return p == q;

        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};

int main()
{
    Tree t1 = leetcode::createTree({1, 2, 3});
    Tree t2 = leetcode::createTree({1, 2, 3});

    bool res1 = (new Solution)->isSameTree(t1, t2);

    assert_true(res1);

    Tree t3 = leetcode::createTree({1, 2});
    Tree t4 = leetcode::createTree({1, NONE, 2});

    bool res2 = (new Solution)->isSameTree(t3, t4);

    assert_false(res2);

    return 0;
}

