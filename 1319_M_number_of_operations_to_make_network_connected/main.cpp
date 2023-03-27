/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. 
Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
*/

#include <vector>
#include <unordered_set>

#include <gtest/gtest.h>

using namespace std;

class Solution
{
    void dfs(const vector<vector<int>>& graph, int u, unordered_set<int>& seen)
    {
        for (const int v : graph[u])
        {
            if (seen.insert(v).second)
            {
                dfs(graph, v, seen);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        // To connect n nodes, we need at least n - 1 edges
        if (connections.size() < n - 1)
        {
            return -1;
        }

        int numOfConnected = 0;
        vector<vector<int>> graph(n);
        unordered_set<int> seen;

        for (const vector<int>& conn : connections)
        {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }

        for (int i = 0; i < n; ++i)
        {
            if (seen.insert(i).second)
            {
                dfs(graph, i, seen);
                ++numOfConnected;
            }
        }

        return numOfConnected - 1;
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1) {
    Solution sol;
    vector<vector<int>> connections{ {0,1}, {0,2}, {1,2} };
    ASSERT_EQ(sol.makeConnected(4, connections), 1);
}

TEST_F(TestSolution, TestExample2) {
    Solution sol;
    vector<vector<int>> connections{ {0,1}, {0,2}, {0,3}, {1,2}, {1,3} };
    ASSERT_EQ(sol.makeConnected(6, connections), 2);
}

TEST_F(TestSolution, TestExample3) {
    Solution sol;
    vector<vector<int>> connections{ {0,1}, {0,2}, {0,3}, {1,2} };
    ASSERT_EQ(sol.makeConnected(6, connections), -1);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}