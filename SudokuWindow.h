#pragma once
#include "SudokuSquare.h"
class SudokuGenerator;
class DifficultyLevelButton;
class MenuButton;

namespace WindowConfig
{
	const unsigned int width = 625;
	const unsigned int height = 450;
}

class SudokuWindow
{
public:
	SudokuWindow();
	~SudokuWindow();
	void eventHandler();

private:
	void createButtons();
	void onMouseButtonClicked(const sf::Vector2f &mousePosition);
	void onMouseMoved(const sf::Vector2f &mousePosition);
	void onKeyButtonClicked(sf::Event::TextEvent text);
	void onBackspaceButtonClicked();
	void onNewGameButtonClicked();
	void onSolveButtonClicked();
	void onHintButtonClicked();
	/// Update clock on screen
	void updateClock();

	void update(int rowClicked, int colClicked, int valueClicked);
	void onAnimationStageChanged();

	void updateAnimation(int offset, enum SudokuSquare::SquareState state);

	SudokuGenerator *m_generator;
	std::vector<SudokuSquare *> m_sudokuSquares;
	std::vector<MenuButton *> m_menuButtons;
	std::vector<DifficultyLevelButton *> m_difficultybuttons;
	SudokuSquare *m_clickedSquare;

	bool m_gameFinished;
	bool m_animationFinished;
	int m_animationStage;

	enum Difficulty
	{
		EASY = 0,
		MEDIUM,
		HARD
	};

	Difficulty m_difficultySelected;

	sf::Font m_font;
	sf::Text m_clockText;
	sf::Text m_difficultyText;
	sf::Clock *m_clock;
};
