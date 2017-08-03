#include "DoubleLinkedList.h"
#include <String>
#include "Windows.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

std::ostream & operator<<(std::ostream & out, const Deck::Card & card)
{
	SetConsoleTextAttribute(hConsole, 15);
	if (card.m_cardtype == 'H' || card.m_cardtype == 'D')
	SetConsoleTextAttribute(hConsole, 12);
	out << card.m_cardnumber << " " << card.m_cardtype;
	SetConsoleTextAttribute(hConsole, 15);
	return out;
}
