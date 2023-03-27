/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <vector>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int curY = grid.size() - 1, curX = grid.at(0).size() - 1;
        int pathSum = grid.at(0).at(0);
        while (curY || curX)
        {
            pathSum += grid.at(curY).at(curX);
            if (!curY) // if y == 0, take left cell value
            {
                curX--;
                continue;
            }
            if (!curX) // if x == 0, take top cell value
            {
                curY--;
                continue;
            }

            int leftVal = grid.at(curY).at(curX - 1),
                topVal = grid.at(curY - 1).at(curX);
            if (leftVal < topVal)
            {
                curX--;
            }
            else
            {
                curY--;
            }
        }
        return pathSum;
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    Solution sol;
    vector<vector<int>> grid = { {1,3,1}, {1,5,1}, {4,2,1} };
    ASSERT_EQ(sol.minPathSum(grid), 7);
}

/*
123
456
*/
TEST_F(TestSolution, TestExample2)
{
    Solution sol;
    vector<vector<int>> grid = { {1,2,3}, {4,5,6} };
    ASSERT_EQ(sol.minPathSum(grid), 12);
}

/*
1,4,8,6,2,2,1,7
4,7,3,1,4,5,5,1
8,8,2,1,1,8,0,1
8,9,2,9,8,0,8,9
5,7,5,7,1,8,5,5
7,0,9,4,5,6,5,6
4,9,9,7,9,1,9,0
*/
TEST_F(TestSolution, TestExample3)
{
    Solution sol;
    vector<vector<int>> grid = { {1,4,8,6,2,2,1,7}, {4,7,3,1,4,5,5,1}, {8,8,2,1,1,8,0,1}, {8,9,2,9,8,0,8,9}, {5,7,5,7,1,8,5,5}, {7,0,9,4,5,6,5,6}, {4,9,9,7,9,1,9,0} };
    ASSERT_EQ(sol.minPathSum(grid), 47);
}

/*
1,4,8,6,2,2,1,7
4,7,3,1,4,5,5,1
8,8,2,1,1,8,0,1
8,9,2,9,8,0,8,9
5,7,5,7,1,8,5,5
7,0,9,4,5,6,5,6
4,9,9,7,9,1,9,0
*/
TEST_F(TestSolution, TestExample3)
{
    Solution sol;
    vector<vector<int>> grid = { {1,4,8,6,2,2,1,7}, {4,7,3,1,4,5,5,1}, {8,8,2,1,1,8,0,1}, {8,9,2,9,8,0,8,9}, {5,7,5,7,1,8,5,5}, {7,0,9,4,5,6,5,6}, {4,9,9,7,9,1,9,0} };
    ASSERT_EQ(sol.minPathSum(grid), 47);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}