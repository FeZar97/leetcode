/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
*/

#include <string>

#include <gtest/gtest.h>

class TrieNode
{
public:
    TrieNode* child[26];
    bool isWord;

    TrieNode() : isWord(false)
    {
        for (auto& c : child)
        {
            c = nullptr;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(std::string word)
    {
        TrieNode* tmp = root;
        for (auto c : word)
        {
            int i = c - 'a';
            if (!tmp->child[i])
            {
                tmp->child[i] = new TrieNode();
            }

            tmp = tmp->child[i];
        }
        tmp->isWord = true;
    }


    bool search(const std::string& word)
    {
        return searchWord(word, root, 0);
    }

    bool searchWord(const std::string& word, TrieNode* p, int i)
    {
        if (i == word.length())
        {
            return p->isWord;
        }

        if (word[i] == '.')
        {
            for (auto c : p->child)
            {
                if (c && searchWord(word, c, i + 1))
                {
                    return true;
                }
            }
            return false;
        }

        else
        {
            int index = word[i] - 'a';
            return p->child[index] && searchWord(word, p->child[index], i + 1);
        }
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    WordDictionary *wordDictionary = new WordDictionary();
    wordDictionary->addWord("bad");
    wordDictionary->addWord("dad");
    wordDictionary->addWord("mad");
    ASSERT_EQ(wordDictionary->search("pad"), false);
    ASSERT_EQ(wordDictionary->search("bad"), true);
    ASSERT_EQ(wordDictionary->search(".ad"), true);
    ASSERT_EQ(wordDictionary->search("b.."), true);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}