/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.
*/

#include <list>
#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

class Solution
{
    struct ServerNodeInfo
    {
        int linksNb{ 0 };
        std::list<int> links;

        void addLink(const int serverIdx)
        {
            linksNb++;
            links.push_back(serverIdx);
        }
    };

    std::unordered_map<int, ServerNodeInfo> severMap;

public:
    std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections)
    {
        for (const auto& conPair : connections)
        {
            const int s1 = conPair.at(0), s2 = conPair.at(1);
            severMap[s1].addLink(s2);
            severMap[s2].addLink(s1);
        }

        std::vector<std::vector<int>> resultPairsVec;
        resultPairsVec.reserve(n);

        for (const auto& serverInfo: severMap)
        {
            const int serverIdx = serverInfo.first;
            const ServerNodeInfo& serverNodeInfo = serverInfo.second;

            if (serverNodeInfo.linksNb > 1)
            {
                continue;
            }
            const int pairServerIdx = *serverNodeInfo.links.begin();

            resultPairsVec.push_back({ serverIdx, pairServerIdx });
            severMap[pairServerIdx].linksNb++;
        }

        return resultPairsVec;
    }
};
class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1)
{
    // Solution sol;
    // ASSERT_EQ(sol.criticalConnections(4, 
    //                                   std::vector<std::vector<int>>{ { 0, 1 }, { 1, 2 }, { 2, 0 }, { 1, 3 } }
    //                                  ), 
    //           std::vector<std::vector<int>>{ { 1, 3 } }
    //          );
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}