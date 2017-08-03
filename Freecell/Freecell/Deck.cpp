#include "Deck.h"
#include <string>
#include <time.h>


Deck::Deck()
{
	this->m_deck.setLength(52);
	
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 4; j++)
		{
			this->m_deck[i * 4 + j].m_cardnumber = this->m_numbersoncards[i];
			this->m_deck[i * 4 + j].m_cardtype = this->m_cardmascot[j];
			this->m_deck[i * 4 + j].m_cardrank = i + 1;
		}
}

void Deck::shuffleDeck()
{	
	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		int r = rand() % 52;
		Card card = this->m_deck[i];
		this->m_deck[i] = this->m_deck[r];
		this->m_deck[r] = card;
	}

}

void Deck::printDeck()
{

		for (int j = 0; j < 52; j++)
		{
			std::cout << this->m_deck[j].m_cardnumber;
			std::cout << this->m_deck[j].m_cardtype << " ";
			std::cout << this->m_deck[j].m_cardrank	<< std::endl;
		}
}

Deck::Card & Deck::getCardAt(int index) 
{
	return this->m_deck[index];
}



