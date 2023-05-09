/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        std::vector<int> result;
        int height = matrix.size(), width = matrix[0].size();
        result.reserve(height * width);

        int startXIdx = 0, endXIdx = width - 1,
            startYIdx = 0, endYIdx = height - 1,
            curIdx;

        while (height > 0 && width > 0)
        {
            // left-right traverse
            if (height > 0 && (startXIdx <= endXIdx))
            {
                for (curIdx = startXIdx; curIdx <= endXIdx; curIdx++)
                {
                    result.push_back(matrix[startYIdx][curIdx]);
                }
                startYIdx++;
                height--;
            }

            // top-bot traverse
            if (width > 0 && (startYIdx <= endYIdx))
            {
                for (curIdx = startYIdx; curIdx <= endYIdx; curIdx++)
                {
                    result.push_back(matrix[curIdx][endXIdx]);
                }
                endXIdx--;
                width--;
            }

            // right-left traverse
            if (height > 0 && (startXIdx <= endXIdx))
            {
                for (curIdx = endXIdx; curIdx >= startXIdx; curIdx--)
                {
                    result.push_back(matrix[endYIdx][curIdx]);
                }
                endYIdx--;
                height--;
            }

            // bot-top traverse
            if (width > 0 && (startYIdx <= endYIdx))
            {
                for (curIdx = endYIdx; curIdx >= startYIdx; curIdx--)
                {
                    result.push_back(matrix[curIdx][startXIdx]);
                }
                startXIdx++;
                width--;
            }
        }

        return result;
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    Solution sol;
    const std::vector<int> templ{ 1,2,3,6,9,8,7,4,5 };
    std::vector<int> res = sol.spiralOrder(std::vector<std::vector<int>>{ {1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 } });

    ASSERT_TRUE(res.size() == templ.size());

    for (int i = 0; i < res.size(); i++)
    {
        ASSERT_TRUE(res[i] == templ[i]);
    }
}

TEST_F(TestSolution, TestExample2)
{
    Solution sol;
    const std::vector<int> templ{ 1,2,3,4,8,12,11,10,9,5,6,7 };
    std::vector<int> res = sol.spiralOrder(std::vector<std::vector<int>>{ {1, 2, 3, 4}, { 5,6,7,8 }, { 9,10,11,12 } });

    ASSERT_TRUE(res.size() == templ.size());

    for (int i = 0; i < res.size(); i++)
    {
        ASSERT_TRUE(res[i] == templ[i]);
    }
}

TEST_F(TestSolution, ManuallyExample1)
{
    Solution sol;
    const std::vector<int> templ{ 1 };
    std::vector<int> res = sol.spiralOrder(std::vector<std::vector<int>>{ {1} });

    ASSERT_TRUE(res.size() == templ.size());

    for (int i = 0; i < res.size(); i++)
    {
        ASSERT_TRUE(res[i] == templ[i]);
    }
}

TEST_F(TestSolution, ManuallyExample2)
{
    Solution sol;
    const std::vector<int> templ{ 1, 2, 3, 6, 5, 4 };
    std::vector<int> res = sol.spiralOrder(std::vector<std::vector<int>>{ {1, 2, 3}, { 4, 5, 6 } });

    ASSERT_TRUE(res.size() == templ.size());

    for (int i = 0; i < res.size(); i++)
    {
        ASSERT_TRUE(res[i] == templ[i]);
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}