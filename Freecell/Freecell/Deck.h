#pragma once
#ifndef DECK_H
#define DECK_H
#include "Array.h"

class Deck
{
public:
	struct Card
	{
		std::string m_cardnumber;
		char m_cardtype;
		int m_cardrank;
	};
	Deck();
	void shuffleDeck();
	void printDeck();
	Card & getCardAt(int index);
private:
	Array<Card> m_deck;
	std::string m_numbersoncards[15] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	char m_cardmascot[5] = { 'C', 'D', 'H', 'S' };

};
#endif // !DECK_H

