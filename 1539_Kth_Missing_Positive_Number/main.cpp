/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.
*/

#include <string>

#include <gtest/gtest.h>

using namespace std;

class Solution 
{
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int prevNumber = 0, missedNb;

        for (const int curVal : arr)
        {
            if (curVal == prevNumber + 1)
            {
                prevNumber = curVal;
                continue;
            }

            missedNb = curVal - prevNumber - 1;
            if (k <= missedNb)
            {
                return prevNumber + k;
            }

            k -= missedNb;
            prevNumber = curVal;
        }

        return prevNumber + k;
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1) {
    Solution sol;
    vector<int> v{ 2, 3, 4, 7, 11 };
    ASSERT_EQ(sol.findKthPositive(v, 5), 9);
}

TEST_F(TestSolution, TestExample2) {
    Solution sol;
    vector<int> v{ 1, 2, 3, 4 };
    ASSERT_EQ(sol.findKthPositive(v, 2), 6);
}

TEST_F(TestSolution, TestExample3) {
    Solution sol;
    vector<int> v{ 2 };
    ASSERT_EQ(sol.findKthPositive(v, 1), 1);
}

TEST_F(TestSolution, ManuallyTest1) {
    Solution sol;
    vector<int> v{ 1 };
    ASSERT_EQ(sol.findKthPositive(v, 1), 2);
}

TEST_F(TestSolution, ManuallyTest2) {
    Solution sol;
    vector<int> v{ 1 };
    ASSERT_EQ(sol.findKthPositive(v, 100), 101);
}

TEST_F(TestSolution, ManuallyTest3) {
    Solution sol;
    vector<int> v{ 5 };
    ASSERT_EQ(sol.findKthPositive(v, 1), 1);
}

TEST_F(TestSolution, ManuallyTest4) {
    Solution sol;
    vector<int> v{ 1, 5 };
    ASSERT_EQ(sol.findKthPositive(v, 1), 2);
}

TEST_F(TestSolution, ManuallyTest5) {
    Solution sol;
    vector<int> v{ 1, 10, 20 };
    ASSERT_EQ(sol.findKthPositive(v, 10), 12);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}