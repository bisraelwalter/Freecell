#include "Gameboard.h"
#include <iomanip>
#include "Windows.h"

HANDLE hConsole2 = GetStdHandle(STD_OUTPUT_HANDLE);

Gameboard::Gameboard()
{
	this->m_homecellClub = Stack<Deck::Card>(13);
	this->m_homecellDiamond = Stack<Deck::Card>(13);
	this->m_homecellHeart = Stack<Deck::Card>(13);
	this->m_homecellSpade = Stack<Deck::Card>(13);

	this->m_column1.setStackNumber(1);
	this->m_column2.setStackNumber(2);
	this->m_column3.setStackNumber(3);
	this->m_column4.setStackNumber(4);
	this->m_column5.setStackNumber(5);
	this->m_column6.setStackNumber(6);
	this->m_column7.setStackNumber(7);
	this->m_column8.setStackNumber(8);

	//Comment out the next line to get an easy deck
	this->m_deckofcards.shuffleDeck();

	this->m_freecellArea.setLength(4);
	this->m_freecellArea.setStartIndex(10);

	for (int i = 0; i < 4; i++)
		this->m_freecellArea[i].m_cardnumber = "0";

	for (int i = 0; i < 52; i++)
	{
		if (i < 7)
			this->m_column1.Push(this->m_deckofcards.getCardAt(i));
		if (i < 14 && i >= 7)
			this->m_column2.Push(this->m_deckofcards.getCardAt(i));
		if (i < 21 && i >= 14)
			this->m_column3.Push(this->m_deckofcards.getCardAt(i));
		if (i < 28 && i >= 21)
			this->m_column4.Push(this->m_deckofcards.getCardAt(i));
		if (i < 34 && i >= 28)
			this->m_column5.Push(this->m_deckofcards.getCardAt(i));
		if (i < 40 && i >= 34)
			this->m_column6.Push(this->m_deckofcards.getCardAt(i));
		if (i < 46 && i >= 40)
			this->m_column7.Push(this->m_deckofcards.getCardAt(i));
		if (i < 52 && i >= 46)
			this->m_column8.Push(this->m_deckofcards.getCardAt(i));
	}
}

void Gameboard::printBoard()
{
	printHeaders();
	printFreecells();
	printHomecells();
	printEmptyHeader();
	printStack();
	printRowNumbers();

}

void Gameboard::printHeaders()
{
	for (int i = 10; i < 14; i++)
		std::cout << std::setw(7) << i;
	std::cout << std::setw(15);
	SetConsoleTextAttribute(hConsole2, 15);
	std::cout << 'C' << std::setw(7);
	SetConsoleTextAttribute(hConsole2, 12);
	std::cout << 'D' << std::setw(7);
	std::cout << 'H' << std::setw(7);
	SetConsoleTextAttribute(hConsole2, 15);
	std::cout << 'S';
	std::cout << std::endl;
}

void Gameboard::printFreecells()
{
	std::cout << std::setw(9);
	if (this->m_freecellArea[0].m_cardnumber == "0")
	{
		std::cout << std::setw(9);
		std::cout << "Empty";
	}
	else
	{
		std::cout << std::setw(6);
		std::cout << this->m_freecellArea[0];
		std::cout << " ";
	}
	if (this->m_freecellArea[1].m_cardnumber == "0")
	{
		std::cout << std::setw(7);
		std::cout << "Empty";
	}
	else
	{
		std::cout << std::setw(4);
		std::cout << this->m_freecellArea[1];
		std::cout << " ";
	}
	if (this->m_freecellArea[2].m_cardnumber == "0")
	{
		std::cout << std::setw(7);
		std::cout << "Empty";
	}
	else
	{
		std::cout << std::setw(4);
		std::cout << this->m_freecellArea[2];
		std::cout << " ";
	}
	if (this->m_freecellArea[3].m_cardnumber == "0")
	{
		std::cout << std::setw(7);
		std::cout << "Empty";
	}
	else
	{
		std::cout << std::setw(4);
		std::cout << this->m_freecellArea[3];
		std::cout << " ";
	}
}

void Gameboard::printHomecells()
{

	std::cout << std::setw(15);
	if (this->m_homecellClub.isEmpty())
	{
		std::cout << std::setw(15);
		std::cout << "Empty";
	}
	else
	{
		std::cout << std::setw(12);
		std::cout << this->m_homecellClub.Peep();
		std::cout << " ";
	}
	if (this->m_homecellDiamond.isEmpty())
	{
		std::cout << std::setw(7);
		std::cout << "Empty";
	}
	else
	{
		std::cout << std::setw(4);
		std::cout << this->m_homecellDiamond.Peep();
		std::cout << " ";
	}
	if (this->m_homecellHeart.isEmpty())
	{
		std::cout << std::setw(7);
		std::cout << "Empty";
	}
	else
	{
		std::cout << std::setw(4);
		std::cout << this->m_homecellHeart.Peep();
		std::cout << " ";
	}
	if (this->m_homecellSpade.isEmpty())
	{
		std::cout << std::setw(7);
		std::cout << "Empty";
	}
	else
	{
		std::cout << std::setw(4);
		std::cout << this->m_homecellSpade.Peep();
		std::cout << " ";
	}

	std::cout << std::endl << std::endl << std::endl;
}

void Gameboard::printEmptyHeader()
{
	if (this->m_column1.isEmpty())
		std::cout << "        Empty";
	if(!this->m_column1.isEmpty())
		std::cout << "             ";
	if (this->m_column2.isEmpty())
		std::cout << "  Empty";
	if (!this->m_column2.isEmpty())
		std::cout << "       ";
	if (this->m_column3.isEmpty())
		std::cout << "  Empty";
	if (!this->m_column3.isEmpty())
		std::cout << "       ";
	if (this->m_column4.isEmpty())
		std::cout << "  Empty";
	if (!this->m_column4.isEmpty())
		std::cout << "       ";
	if (this->m_column5.isEmpty())
		std::cout << "  Empty";
	if (!this->m_column5.isEmpty())
		std::cout << "       ";
	if (this->m_column6.isEmpty())
		std::cout << "  Empty";
	if (!this->m_column6.isEmpty())
		std::cout << "       ";
	if (this->m_column7.isEmpty())
		std::cout << "  Empty";
	if (!this->m_column7.isEmpty())
		std::cout << "       ";
	if (this->m_column8.isEmpty())
		std::cout << "  Empty";
	if (!this->m_column8.isEmpty())
		std::cout << "       ";
}

void Gameboard::printStack()
{
	Node<Deck::Card> * temp;
	temp = this->m_column1.getHead();
	Node<Deck::Card> * temp2;
	temp2 = this->m_column2.getHead();
	Node<Deck::Card> * temp3;
	temp3 = this->m_column3.getHead();
	Node<Deck::Card> * temp4;
	temp4 = this->m_column4.getHead();
	Node<Deck::Card> * temp5;
	temp5 = this->m_column5.getHead();
	Node<Deck::Card> * temp6;
	temp6 = this->m_column6.getHead();
	Node<Deck::Card> * temp7;
	temp7 = this->m_column7.getHead();
	Node<Deck::Card> * temp8;
	temp8 = this->m_column8.getHead();

	for (int i = 0; i < 13; i++)
	{
		std::cout << std::setw(10) << std::endl;
		for (int j = 0; j < 1; j++)
		{
			if (temp != nullptr)
			{
				std::cout << temp->getData();
				temp = temp->getNext();
			}
			else
				std::cout << "            ";
			std::cout << std::setw(5);
			if (temp2 != nullptr)
			{
				std::cout << temp2->getData();
				temp2 = temp2->getNext();
			}
			else
				std::cout << "       ";
			std::cout << std::setw(5);
			if (temp3 != nullptr)
			{
				std::cout << temp3->getData();
				temp3 = temp3->getNext();
			}
			else
				std::cout << "       ";
			std::cout << std::setw(5);
			if (temp4 != nullptr)
			{
				std::cout << temp4->getData();
				temp4 = temp4->getNext();
			}
			else
				std::cout << "       ";
			std::cout << std::setw(5);
			if (temp5 != nullptr)
			{
				std::cout << temp5->getData();
				temp5 = temp5->getNext();
			}
			else
				std::cout << "       ";
			std::cout << std::setw(5);
			if (temp6 != nullptr)
			{
				std::cout << temp6->getData();
				temp6 = temp6->getNext();
			}
			else
				std::cout << "       ";
			std::cout << std::setw(5);
			if (temp7 != nullptr)
			{
				std::cout << temp7->getData();
				temp7 = temp7->getNext();
			}
			else
				std::cout << "       ";
			std::cout << std::setw(5);
			if (temp8 != nullptr)
			{
				std::cout << temp8->getData();
				temp8 = temp8->getNext();
			}
		}
	}
	std::cout << std::endl << std::endl;
}

void Gameboard::printRowNumbers()
{
	SetConsoleTextAttribute(hConsole2, 23);
	std::cout << std::setw(12);

	for (int i = 1; i < 9; i++)
	{
		SetConsoleTextAttribute(hConsole2, 10);
		std::cout << "Row " << i << std::setw(6);
	}
	SetConsoleTextAttribute(hConsole2, 15);
	std::cout << std::endl << std::endl;
}

Stack<Deck::Card>& Gameboard::getHomcell(int cell)
{
	if (cell == 0)
		return this->m_homecellClub;
	if (cell == 1)
		return this->m_homecellDiamond;
	if (cell == 2)
		return this->m_homecellHeart;
	if (cell == 3)
		return this->m_homecellSpade;

}

StackLL<Deck::Card>& Gameboard::getColumn(int column)
{
	if (column == 1)
		return this->m_column1;
	if (column == 2)
		return this->m_column2;
	if (column == 3)
		return this->m_column3;
	if (column == 4)
		return this->m_column4;
	if (column == 5)
		return this->m_column5;
	if (column == 6)
		return this->m_column6;
	if (column == 7)
		return this->m_column7;
	if (column == 8)
		return this->m_column8;
}
