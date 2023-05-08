/*
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal 
and all the elements on the secondary diagonal that are not part of the primary diagonal.
*/

#include <memory>
#include <vector>

#include <gtest/gtest.h>

class Solution {
public:
    int diagonalSum(std::vector<std::vector<int>>& mat)
    {
        int rowIdx1 = 0, rowIdx2 = mat.size() - 1, sum = 0, size = mat.size();
        for (int i = 0; i < (size + 1) / 2; i++)
        {
            sum += mat[i][rowIdx1];
            if (i != (size + 1) / 2 - 1 || !(size % 2))
            {
                sum += mat[size - 1 - i][rowIdx1];
            }

            if (rowIdx2 != rowIdx1)
            {
                sum += mat[i][rowIdx2] + mat[size - 1 - i][rowIdx2];
            }
            rowIdx1++;
            rowIdx2--;
        }
        return sum;
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    Solution sol;
    ASSERT_EQ(sol.diagonalSum(std::vector<std::vector<int>>{ {1,2,3}, {4,5,6}, {7,8,9} }), 25);
}

TEST_F(TestSolution, TestExample2)
{
    Solution sol;
    ASSERT_EQ(sol.diagonalSum(std::vector<std::vector<int>>{ {1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1} }), 8);
}

TEST_F(TestSolution, TestExample3)
{
    Solution sol;
    ASSERT_EQ(sol.diagonalSum(std::vector<std::vector<int>>{ {5} }), 5);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}