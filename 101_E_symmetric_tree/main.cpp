/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

#include <list>
#include <string>

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
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
        {
            return true;
        }

        return (left && right) &&
            (left->val == right->val) &&
            isSymmetric(left->left, right->right) &&
            isSymmetric(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root)
    {
        if (!root)
        {
            return true;
        }

        return isSymmetric(root->left, root->right);
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
    ASSERT_EQ(sol.isSymmetric(nullptr), true);
}

TEST_F(TestSolution, TestExample2) {
    Solution sol;
    ASSERT_EQ(sol.isSymmetric(makeTree(std::vector<int>{1, 2, 2, 3, 4, 4, 3})), true);
}

TEST_F(TestSolution, TestExample3) {
    Solution sol;
    ASSERT_EQ(sol.isSymmetric(makeTree(std::vector<int>{1, 2, 2, -101, 3, -101, 3})), false);
}

TEST_F(TestSolution, ManuallyTest1) {
    Solution sol;
    ASSERT_EQ(sol.isSymmetric(makeTree(std::vector<int>{1, 2, 2, 4, 3, 3, 4, 5, 6, 8, 7, 7, 8, 6, 6})), false);
}

TEST_F(TestSolution, ManuallyTest2) {
    Solution sol;
    ASSERT_EQ(sol.isSymmetric(makeTree(std::vector<int>{1, 2, 2, 4, 3, 3, 4, 5, 6, 8, 7, 7, 8, 6, 5})), true);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}