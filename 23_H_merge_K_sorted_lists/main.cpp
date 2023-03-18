/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
*/

#include <string>

#include <gtest/gtest.h>

using namespace std;

// Definition for singly - linked list.
struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Base condition
        if (lists.size() == 0) {
            return nullptr;
        }
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        // Mid of list of lists
        int mid = start + (end - start) / 2;
        // Recursive call for left sublist
        ListNode* left = mergeKLists(lists, start, mid);
        // Recursive call for right sublist
        ListNode* right = mergeKLists(lists, mid + 1, end);
        // Merge the left and right sublist
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        // Create a dummy node
        ListNode* head = new ListNode(-1);
        // Temp node
        ListNode* temp = head;
        // Loop until any of the list becomes null
        while (left && right) {
            // Choose the value from the left and right which is smaller
            if (left->val < right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        // Take all nodes from left list if remaining
        while (left) {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        // Take all nodes from right list if remaining
        while (right) {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
        return head->next;
    }
};

ListNode* makeList(const std::vector<int>& values)
{
    if (values.empty())
    {
        return nullptr;
    }

    ListNode *startNode = nullptr, 
             *prevNode = nullptr;
    for (int i = 0; i < values.size(); i++)
    {
        ListNode* newNode = new ListNode(values.at(i));
        if (prevNode)
        {
            prevNode->next = newNode;
        }
        else
        {
            startNode = newNode;
        }
        prevNode = newNode;
    }
    return startNode;
}

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    Solution sol;
    ASSERT_TRUE(
        isEqualLists(
            sol.mergeKLists(std::vector<ListNode*>{ makeList({1,4,5}), makeList({1,3,4}), makeList({2,6}) }),
            makeList({ 1,1,2,3,4,4,5,6 })
        )
    );
}

TEST_F(TestSolution, TestExample2)
{
    Solution sol;
    ASSERT_EQ(sol.mergeKLists(std::vector<ListNode*>{ }), makeList({ }));
}

TEST_F(TestSolution, TestExample3)
{
    Solution sol;
    ASSERT_EQ(sol.mergeKLists(std::vector<ListNode*>{ {} }), makeList({ }));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}