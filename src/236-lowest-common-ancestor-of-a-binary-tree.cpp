// LCA
// 236. Lowest Common Ancestor of a Binary Tree
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
//
#include <leetcode.h>

using namespace std;

class Solution
{
public:
    TreeNode *ans;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        helper(root, p, q);
        return ans;
    }

private:
    int helper(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return 0;

        if (root == p || root == q) {
            int find = helper(root->left, p, q) + helper(root->right, p, q) + 1;

            if (find > 1) {
                ans = root;

                return 1;
            } else {
                return find;
            }

        } else {
            int find = helper(root->left, p, q) + helper(root->right, p, q);

            if (find > 1) {
                ans = root;
                return 1;
            } else {
                return find;
            }
        }
    }
};

int main(int argc, char **argv)
{
    Tree tree = leetcode::createTree({3, 5, 1, 6, 2, 0, 8, NONE, NONE, 7, 4});
    TreeNode *p = tree->left, *q = tree->right;

    auto res = (new Solution)->lowestCommonAncestor(tree, p, q);
    assert_equal(res->val, 3);
}

