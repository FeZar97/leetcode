/*
You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

    * BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
    
    * void visit(string url) Visits url from the current page. It clears up all the forward history.
    
    * string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps.
        Return the current url after moving back in history at most steps.
    
    * string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps.
        Return the current url after forwarding in history at most steps.
*/

#include <list>
#include <string>

#include <gtest/gtest.h>

using namespace std;

class BrowserHistory
{
    std::list<std::string> pagesSequence;
    std::list<std::string>::iterator curPageIter;

public:
    BrowserHistory(string homepage)
    {
        pagesSequence.push_back(homepage);
        curPageIter = std::prev(pagesSequence.end());
    }

    void visit(string url)
    {
        if (curPageIter != std::prev(pagesSequence.end()))
        {
            pagesSequence.erase(++curPageIter, pagesSequence.end());
        }

        pagesSequence.push_back(url);
        curPageIter = std::prev(pagesSequence.end());
    }

    string back(int steps)
    {
        while (steps && curPageIter != pagesSequence.begin())
        {
            steps--;
            curPageIter--;
        }
        return *curPageIter;
    }

    string forward(int steps)
    {
        while (steps && curPageIter != std::prev(pagesSequence.end()))
        {
            steps--;
            curPageIter++;
        }
        return *curPageIter;
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    BrowserHistory* obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");

    ASSERT_EQ(obj->back(1), "facebook.com");
    ASSERT_EQ(obj->back(1), "google.com");
    ASSERT_EQ(obj->forward(1), "facebook.com");

    obj->visit("linkedin.com");
    ASSERT_EQ(obj->forward(2), "linkedin.com");
    ASSERT_EQ(obj->back(2), "google.com");
    ASSERT_EQ(obj->back(7), "leetcode.com");
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}