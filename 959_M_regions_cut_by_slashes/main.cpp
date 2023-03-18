/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.
*/

#include <list>
#include <string>

#include <gtest/gtest.h>

using namespace std;

enum class Neighbour
{
    Top,
    Left,
    Bottom,
    Right,
};

struct Cell
{
    int color1{ -1 }, color2{ -1 };
    char type;

    void addNewColor(int& globalColor)
    {
        if (color1 == -1)
        {
            color1 == globalColor++;
        }
        else if (color2 == -1)
        {
            color2 == globalColor++;
        }
    }

    void fillColorByNeighbour(const Cell& neighbourCell)
    {

    }
};

class Solution 
{
    void fillFirstHorLine(const vector<string>& grid, std::vector<Cell>& cells)
    {

    }


public:
    int regionsBySlashes(const vector<string>& grid) {
        const int gridSize = grid.size();
        const int cellsNb = gridSize * gridSize;

        int colorsNb{ 0 };

        std::vector<Cell> cells(cellsNb);
        cells.at(0).type = grid.at(0).at(0);

        if (cellsNb == 1)
        {
            return grid.at(0).at(0) == ' ' ? 1 : 2;
        }


        for (int rowIdx = 0; rowIdx < gridSize; rowIdx++)
        {
            for (int colIdx = 0; colIdx < gridSize; colIdx++)
            {
                cells.at(rowIdx * gridSize + colIdx).fill(grid.at(rowIdx).at(colIdx), ;
            }
        }
    }
};

class TestSolution : public ::testing::Test { };

TEST_F(TestSolution, TestExample1) {
    Solution sol;
    ASSERT_EQ(sol.regionsBySlashes(std::vector<std::string>{" /", "/ "}), 2);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}