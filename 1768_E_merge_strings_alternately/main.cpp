/*
You are given two strings word1 and word2.
Merge the strings by adding letters in alternating order, starting with word1.
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.
*/

#include <memory>
#include <string>

#include <gtest/gtest.h>

class Solution
{
public:
    std::string mergeAlternately(const std::string& word1, const std::string& word2)
    {
        const size_t s1 = word1.size(), s2 = word2.size();
        std::string result(s1 + s2, ' ');
        
        for (int i = 0; i < std::min(s1, s2); i++)
        {
            result[i * 2] = word1[i];
            result[i * 2 + 1] = word2[i];
        }

        if (s1 < s2)
        {
            memcpy((char*)result.data() + s1 * 2, word2.data() + s1, s2 - s1);
        }
        else if (s2 < s1)
        {
            memcpy((char*)result.data() + s2 * 2, word1.data() + s2, s1 - s2);
        }

        return result;
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    Solution sol;
    ASSERT_EQ(sol.mergeAlternately("abc", "pqr"), "apbqcr");
}

TEST_F(TestSolution, TestExample2)
{
    Solution sol;
    ASSERT_EQ(sol.mergeAlternately("ab", "pqrs"), "apbqrs");
}

TEST_F(TestSolution, TestExample3)
{
    Solution sol;
    ASSERT_EQ(sol.mergeAlternately("abcd", "pq"), "apbqcd");
}

TEST_F(TestSolution, ManuallyExample1)
{
    Solution sol;
    ASSERT_EQ(sol.mergeAlternately("a", "a"), "aa");
}

TEST_F(TestSolution, ManuallyExample2)
{
    Solution sol;
    ASSERT_EQ(sol.mergeAlternately("abc", "abc"), "aabbcc");
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}