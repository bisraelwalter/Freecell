#pragma once
#ifndef FREECELL_H
#define FREECELL_H
#include "Gameboard.h"

class Freecell
{
private:
	Gameboard m_game;
	bool m_gamewinner = false;
	bool m_endgame = false;
	int m_firstinput;
	int m_secondinput;

public:
	Freecell();
	void gameStart();
	void displayRules();
	void playerInput();
	void playerMove();
	void checkForWin();
	void playAgain();
	bool validInput(std::string first, std::string second);
	bool validMove();
	void convertStringToInt(std::string first, std::string second);
	void RowToRow();
	void RowToFreecell();
	void RowToHomecell();
	void FreecellToRow();
	void FreecellToHomecell();
	void FreecellToFreecell();
	void HomecellToRow();
	void HomecellToFreecell();
	bool getGameWinner() const;
	bool getEndGame() const;
};


#endif // !FREECELL_H
