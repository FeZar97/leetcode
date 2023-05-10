/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
*/

#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        int curX = 0, startX = 0, endX = n - 1,
            curY = 0, startY = 0, endY = n - 1,
            curVal = 1;

        std::vector<std::vector<int>> result;
        result.resize(n);
        for (int i = 0; i < n; i++)
        {
            result[i].resize(n);
        }

        while (curVal < n * n)
        {
            // left-right
            if (endX - curX > 0)
            {
                for (curX = startX; curX <= endX; curX++)
                {
                    result[curY][curX] = curVal++;
                }
                curY = ++startY;
                curX = endX;
            }

            // top-bottom
            if (endY - curY >= 0)
            {
                for (curY = startY; curY <= endY; curY++)
                {
                    result[curY][curX] = curVal++;
                }
                curX = --endX;
                curY = endY;
            }

            // right-left
            if (curX - startX >= 0)
            {
                for (curX = endX; curX >= startX; curX--)
                {
                    result[curY][curX] = curVal++;
                }
                curY = --endY;
                curX = startX;
            }

            // bottom-top
            if (curY - startY >= 0)
            {
                for (curY = endY; curY >= startY; curY--)
                {
                    result[curY][curX] = curVal++;
                }
                curX = ++startX;
                curY = startY;
            }
        }

        if (curVal == n * n && n % 2)
        {
            result[n / 2][n / 2] = curVal;
        }

        return result;
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    Solution sol;
    const std::vector<std::vector<int>> templ{ {1, 2, 3}, {8, 9, 4}, {7, 6, 5} };
    std::vector<std::vector<int>> res = sol.generateMatrix(3);

    ASSERT_TRUE(res.size() == templ.size());

    for (int i = 0; i < res.size(); i++)
    {
        ASSERT_TRUE(res[i].size() == templ[i].size());
        for (int j = 0; j < res[i].size(); j++)
        {
            ASSERT_TRUE(res[i][j] == templ[i][j]);
        }
    }
}

TEST_F(TestSolution, TestExample2)
{
    Solution sol;
    const std::vector<std::vector<int>> templ{ {1} };
    std::vector<std::vector<int>> res = sol.generateMatrix(1);

    ASSERT_TRUE(res.size() == templ.size());

    for (int i = 0; i < res.size(); i++)
    {
        ASSERT_TRUE(res[i].size() == templ[i].size());
        for (int j = 0; j < res[i].size(); j++)
        {
            ASSERT_TRUE(res[i][j] == templ[i][j]);
        }
    }
}

// 1  2  3  4
// 12 13 14 5
// 11 16 15 6
// 10 9  8  7
TEST_F(TestSolution, ManuallyExample1)
{
    Solution sol;
    const std::vector<std::vector<int>> templ{ {1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7} };
    std::vector<std::vector<int>> res = sol.generateMatrix(4);

    ASSERT_TRUE(res.size() == templ.size());

    for (int i = 0; i < res.size(); i++)
    {
        ASSERT_TRUE(res[i].size() == templ[i].size());
        for (int j = 0; j < res[i].size(); j++)
        {
            ASSERT_TRUE(res[i][j] == templ[i][j]);
        }
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}