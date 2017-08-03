#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "Deck.h"
#include <string>
#include "Stack.h"
#include "StackLL.h"


class Gameboard
{
public:
	Gameboard();
	void printBoard();
	Array<Deck::Card> m_freecellArea;
	Stack<Deck::Card> m_homecellClub;
	Stack<Deck::Card> m_homecellDiamond;
	Stack<Deck::Card> m_homecellHeart;
	Stack<Deck::Card> m_homecellSpade;
	StackLL<Deck::Card> m_column1;
	StackLL<Deck::Card> m_column2;
	StackLL<Deck::Card> m_column3;
	StackLL<Deck::Card> m_column4;
	StackLL<Deck::Card> m_column5;
	StackLL<Deck::Card> m_column6;
	StackLL<Deck::Card> m_column7;
	StackLL<Deck::Card> m_column8;
	Stack<Deck::Card> & getHomcell(int cell);
	StackLL<Deck::Card> & getColumn(int column);

private:
	Deck m_deckofcards;
	void printHeaders();
	void printFreecells();
	void printHomecells();
	void printEmptyHeader();
	void printStack();
	void printRowNumbers();
};
#endif // !GAMEBOARD_H




