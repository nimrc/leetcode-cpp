//
// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == nullptr && node2 == nullptr)
            return true;
        if (node1 == nullptr || node2 == nullptr)
            return false;

        return (node1->val == node2->val) && isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
    }
};

int main(int argc, char **argv)
{
    vector<int> nodes = {1, 2, 2, 3, 4, 4, 3};

    Tree tree = leetcode::createTree(nodes);

    bool res = (new Solution)->isSymmetric(tree);

    assert_true(res);

    return 0;
}
