/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.
*/

#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    bool canPlaceFlowers(std::vector<int>& A, int n)
    {
        for (int i = 0; i < A.size() && n > 0; ++i)
        {
            if (A[i] == 1)
            {
                continue;
            }

            if ((i == 0 || A[i - 1] == 0) && (i == A.size() - 1 || A[i + 1] == 0))
            {
                A[i] = 1;
                --n;
            }
        }
        return n == 0;
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    Solution sol;
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}