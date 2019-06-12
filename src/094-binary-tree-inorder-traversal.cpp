//
// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res = {};

        if (root != nullptr)
            order(root, &res);

        return res;
    }

    void order(TreeNode *node, vector<int> *res)
    {
        if (node->left) order(node->left, res);
        res->push_back(node->val);
        if (node->right) order(node->right, res);
    }

};

int main(int argc, char **argv)
{
    vector<int> nodes = {1, NONE, 2, 3};

    TreeNode *tree = leetcode::createTree(nodes);

    vector<int> res = (new Solution)->inorderTraversal(tree);

    dump(res);

    return 0;
}
