/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <string>

#include <gtest/gtest.h>

using namespace std;

class Solution {

private:
    int naiveSolution(const string& haystack, const string& needle)
    {
        if (needle.size() > haystack.size())
        {
            return -1;
        }

        int needleSubIdx;

        for (int haystackIdx = 0; haystackIdx < haystack.size() - needle.size() + 1; haystackIdx++)
        {
            for (needleSubIdx = 0; needleSubIdx < needle.size(); needleSubIdx++)
            {
                if (haystack.at(haystackIdx + needleSubIdx) != needle.at(needleSubIdx))
                {
                    break;
                }
            }

            if (needleSubIdx == needle.size())
            {
                return haystackIdx;
            }
        }
        return -1;
    }

public:
    int strStr(const string& haystack, const string& needle)
    {
        return naiveSolution(haystack, needle);
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1) {
    Solution sol;
    ASSERT_EQ(sol.strStr("sadbutsad", "sad"), 0);
}

TEST_F(TestSolution, TestExample2) {
    Solution sol;
    ASSERT_EQ(sol.strStr("leetcode", "leeto"), -1);
}

TEST_F(TestSolution, TestExample3) {
    Solution sol;
    ASSERT_EQ(sol.strStr("mississippi", "issip"), 4);
}

TEST_F(TestSolution, ManualyTest1) {
    Solution sol;
    ASSERT_EQ(sol.strStr("abcdefg", "cd"), 2);
}

TEST_F(TestSolution, ManualyTest2) {
    Solution sol;
    ASSERT_EQ(sol.strStr("a", "a"), 0);
}

TEST_F(TestSolution, ManualyTest3) {
    Solution sol;
    ASSERT_EQ(sol.strStr("a", "b"), -1);
}

TEST_F(TestSolution, ManualyTest4) {
    Solution sol;
    ASSERT_EQ(sol.strStr("a", "aa"), -1);
}

TEST_F(TestSolution, ManualyTest5) {
    Solution sol;
    ASSERT_EQ(sol.strStr("abba", "bb"), 1);
}

TEST_F(TestSolution, ManualyTest6) {
    Solution sol;
    ASSERT_EQ(sol.strStr("abbaabbaabbaabbba", "bb"), 1);
}

TEST_F(TestSolution, ManualyTest7) {
    Solution sol;
    ASSERT_EQ(sol.strStr("abbaabbaabbaabbba", "bbb"), 13);
}

TEST_F(TestSolution, EqualOnStart) {
    Solution sol;
    ASSERT_EQ(sol.strStr("aaaaaaaaaaaaaa", "aaa"), 0);
}

TEST_F(TestSolution, EqualOnEnd) {
    Solution sol;
    ASSERT_EQ(sol.strStr("aaaaaaaaaaaaaab", "b"), 14);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}