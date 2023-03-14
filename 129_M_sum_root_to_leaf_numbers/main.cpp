/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.
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
    void accountNode(int &total, int temp, TreeNode* node)
    {
        if (!node)
        {
            return;
        }

        temp = temp * 10 + node->val;

        if (node->left || node->right)
        {
            accountNode(total, temp, node->left);
            accountNode(total, temp, node->right);
        }
        else
        {
            total += temp;
        }
    }

public:
    int sumNumbers(TreeNode* root)
    {
        int total = 0;
        accountNode(total, total, root);
        return total;
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
    ASSERT_EQ(sol.sumNumbers(makeTree(std::vector<int>{1, 2, 3})), 25);
}

TEST_F(TestSolution, TestExample2) {
    Solution sol;
    ASSERT_EQ(sol.sumNumbers(makeTree(std::vector<int>{4, 9, 0, 5, 1})), 1026);
}

TEST_F(TestSolution, ManuallyTest1) {
    Solution sol;
    ASSERT_EQ(sol.sumNumbers(makeTree(std::vector<int>{7, 3, 2, 6, -101, 1, 5, -101, -101, -101, -101, -101, -101, -101, 4})), 8711);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}