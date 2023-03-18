/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/

#include <string>
#include <unordered_map>

#include <gtest/gtest.h>

using namespace std;

// Definition for singly - linked list.
class Trie 
{
    bool isFinal_{ false };

    std::unordered_map<char, std::unique_ptr<Trie>> childs_;

public:
    void insert(const string& word)
    {
        if (word.empty())
        {
            isFinal_ = true;
            return;
        }

        const char childVal = word.front();
        const std::string childWord{ word.begin() + 1, word.end() };

        auto childIter = childs_.find(childVal);
        if (childIter == childs_.end())
        {
            childs_[childVal] = std::make_unique<Trie>();
            childs_[childVal]->insert(childWord);
        }
        else
        {
            childIter->second->insert(childWord);
        }
    }

    bool search(string word)
    {
        if (word.empty())
        {
            return isFinal_;
        }

        const char nextC = word.front();
        auto nextIter = childs_.find(nextC);
        if (nextIter == childs_.end())
        {
            return false;
        }

        const std::string nextWord{ word.begin() + 1, word.end() };
        return nextIter->second->search(nextWord);
    }

    bool startsWith(string prefix)
    {
        if (prefix.empty())
        {
            return true;
        }

        const char nextC = prefix.front();
        auto nextIter = childs_.find(nextC);
        if (nextIter == childs_.end())
        {
            return false;
        }

        const std::string nextPrefix{ prefix.begin() + 1, prefix.end() };
        return nextIter->second->startsWith(nextPrefix);
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    Trie* obj = new Trie();

    obj->insert("apple");

    ASSERT_EQ(obj->search("apple"), true);
    ASSERT_EQ(obj->startsWith("app"), true);

    ASSERT_EQ(obj->search("app"), false);

    obj->insert("app");

    ASSERT_EQ(obj->search("app"), true);
    ASSERT_EQ(obj->startsWith("app"), true);
}

TEST_F(TestSolution, ManuallyExample1)
{
    Trie* obj = new Trie();

    obj->insert("a");

    ASSERT_EQ(obj->search("a"), true);
    ASSERT_EQ(obj->startsWith("a"), true);

    obj->insert("app");

    ASSERT_EQ(obj->search("app"), true);
    ASSERT_EQ(obj->search("ap"), false);
    ASSERT_EQ(obj->startsWith("ap"), true);
    ASSERT_EQ(obj->startsWith("app"), true);
    ASSERT_EQ(obj->startsWith("appp"), false);

    obj->insert("b");

    ASSERT_EQ(obj->search("b"), true);
    ASSERT_EQ(obj->startsWith("b"), true);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}