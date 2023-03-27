/*
You are given a positive integer n representing n cities numbered from 1 to n.
You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei.
The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:
A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
*/

#include <queue>
#include <vector>
#include <utility>
#include <gtest/gtest.h>

using namespace std;

class Solution
{
public:
    int minScore(int n, vector<vector<int>>& roads)
    {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> graph(n);  // graph[u] := [(v, distance)]
        queue<int> q{ {0} };
        vector<bool> seen(n);
        seen[0] = true;

        for (const vector<int>& r : roads)
        {
            const int u = r[0] - 1;
            const int v = r[1] - 1;
            const int distance = r[2];
            graph[u].emplace_back(v, distance);
            graph[v].emplace_back(u, distance);
        }

        while (!q.empty())
        {
            const int u = q.front();
            q.pop();

            for (const auto& valPair : graph[u])
            {
                ans = min(ans, valPair.second);
                if (seen[valPair.first])
                {
                    continue;
                }
                q.push(valPair.first);
                seen[valPair.first] = true;
            }
        }

        return ans;
    }
};


class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1) {
    Solution sol;
    vector<vector<int>> roads{ {1,2,9}, {2,3,6}, {2,4,5}, {1,4,7} };
    ASSERT_EQ(sol.minScore(4, roads), 5);
}

TEST_F(TestSolution, TestExample2) {
    Solution sol;
    vector<vector<int>> roads{ {1,2,2}, {1,3,4}, {3,4,7} };
    ASSERT_EQ(sol.minScore(4, roads), 2);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}