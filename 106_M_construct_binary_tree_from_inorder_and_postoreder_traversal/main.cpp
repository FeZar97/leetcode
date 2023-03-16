/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
and postorder is the postorder traversal of the same tree, construct and return the binary tree.
*/

#include <unordered_map>

#include <gtest/gtest.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution 
{
private:
    // Recursive function to construct a binary tree from a given
    // inorder and postorder traversals
    TreeNode* construct(int start, int end, vector<int> const& postorder, int& pIndex, unordered_map<int, int>& map)
    {
        // base case
        if (start > end) {
            return nullptr;
        }

        // Consider the next item from the end of a given postorder sequence.
        // This value would be the root node of a subtree formed by sequence
        // inorder[start, end].
        TreeNode* root = new TreeNode(postorder[pIndex--]);

        // search the current node index in inorder sequence to determine
        // the boundary of the left and right subtree of the current node
        int index = map[root->val];

        // recursively construct the right subtree
        root->right = construct(index + 1, end, postorder, pIndex, map);

        // recursively construct the left subtree
        root->left = construct(start, index - 1, postorder, pIndex, map);

        // return the root node
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int n = inorder.size();

        // map is used to efficiently find the index of any element in
        // a given inorder sequence
        std::unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) 
        {
            map[inorder[i]] = i;
        }

        // `pIndex` stores the index of the next unprocessed node from the end
        // of the postorder sequence
        int pIndex = n - 1;
        return construct(0, n - 1, postorder, pIndex, map);
    }
};

TreeNode* makeNode(int nodeIdx, const std::vector<int>& vec)
{
    if (nodeIdx < 0 || nodeIdx >= vec.size())
    {
        return nullptr;
    }

    int val = vec.at(nodeIdx);
    return val == -101 ? nullptr : new TreeNode(val, makeNode(2 * nodeIdx + 1, vec), makeNode(2 * nodeIdx + 2, vec));
}

TreeNode* makeTree(const std::vector<int>& vec)
{
    if (vec.empty())
    {
        return nullptr;
    }

    TreeNode* root = makeNode(0, vec);
    return root;
}

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1) {
    Solution sol;
    ASSERT_EQ(sol.buildTree(makeTree(std::vector<int>{1, 2, 3, 4, 5, 6})), true);
}
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}