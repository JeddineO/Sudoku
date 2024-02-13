#pragma once
#include <random>
#include <vector>

class SudokuGenerator{
public:
	SudokuGenerator(int difficultyLevel);
	
	std::vector<std::vector<int>> getBoard();
	bool isGameFinished();
	void setValueAt(int row, int col, int value);
	void solve();
	
	void solveAt(int row, int col);
private:
	
	bool removeNumbersFromBoard(const std::vector<int>& removeOrder, int index);
	
	 
	int solveSudoku(int row = 0, int col = 0, int solutions = 0);
	
	bool isSafe(int value, int row, int col);
	
	std::vector<int> generateRandomPermutation(int vectorSize);

	std::vector<std::vector<int>> m_board; 
	std::vector<std::vector<int>> m_solvedBoard; 
	
	int m_missingValues; 
	int m_emptySquares;

	std::random_device m_rd;
	std::mt19937 m_mt{m_rd()};
	std::uniform_int_distribution<int> m_dist{0,8};
};

