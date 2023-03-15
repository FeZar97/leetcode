/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2^h nodes inclusive at the last level h.
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
public:
    bool isCompleteTree(TreeNode* root)
    {
        std::list<TreeNode*> curLevelList{ root }, nextLevelList;
        bool isFullLayer = true, isNextFull = true;

        while (!curLevelList.empty())
        {
            for (auto nodeIter = curLevelList.begin(); nodeIter != curLevelList.end(); nodeIter++)
            {
                isNextFull &= (*nodeIter)->right && (*nodeIter)->left || !(*nodeIter)->right && !(*nodeIter)->left;

                if (!isFullLayer && !isNextFull && nodeIter != prev(curLevelList.end()))
                {
                    return false;
                }

                if ((*nodeIter)->right && !(*nodeIter)->left)
                {
                    return false;
                }

                if ((*nodeIter)->left)
                {
                    nextLevelList.push_back((*nodeIter)->left);
                }
                if ((*nodeIter)->right)
                {
                    nextLevelList.push_back((*nodeIter)->right);
                }
            }

            isFullLayer = isNextFull;
            isNextFull = true;

            curLevelList = nextLevelList;
            nextLevelList.clear();
        }

        return true;
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
    ASSERT_EQ(sol.isCompleteTree(makeTree(std::vector<int>{1, 2, 3, 4, 5, 6})), true);
}

TEST_F(TestSolution, TestExample2) {
    Solution sol;
    ASSERT_EQ(sol.isCompleteTree(makeTree(std::vector<int>{1, 2, 3, 4, 5, -101, 7})), false);
}

TEST_F(TestSolution, TestExample3) {
    Solution sol;
    ASSERT_EQ(sol.isCompleteTree(makeTree(std::vector<int>{1, 2, 3, 5, -101, 7, 8})), false);
}

TEST_F(TestSolution, ManuallyExample1) {
    Solution sol;
    ASSERT_EQ(sol.isCompleteTree(makeTree(std::vector<int>{1, 2, 3, 4, 5, 6, 7})), true);
}

TEST_F(TestSolution, ManuallyExample2) {
    Solution sol;
    ASSERT_EQ(sol.isCompleteTree(makeTree(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8})), true);
}

TEST_F(TestSolution, ManuallyExample3) {
    Solution sol;
    ASSERT_EQ(sol.isCompleteTree(makeTree(std::vector<int>{1})), true);
}

TEST_F(TestSolution, ManuallyExample4) {
    Solution sol;
    ASSERT_EQ(sol.isCompleteTree(makeTree(std::vector<int>{1, 2})), true);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}