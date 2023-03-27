/*
Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include <vector>

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        long long curZeroLength = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                curZeroLength = 0;
                continue;
            }
            sum += ++curZeroLength;
        }

        return sum;
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1) {
    Solution sol;
    vector<int> nums{ 1,3,0,0,2,0,0,4 };
    ASSERT_EQ(sol.zeroFilledSubarray(nums), 6);
}

TEST_F(TestSolution, TestExample2) {
    Solution sol;
    vector<int> nums{ 0,0,0,2,0,0 };
    ASSERT_EQ(sol.zeroFilledSubarray(nums), 9);
}

TEST_F(TestSolution, TestExample3) {
    Solution sol;
    vector<int> nums{ 2,10,2019 };
    ASSERT_EQ(sol.zeroFilledSubarray(nums), 0);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}