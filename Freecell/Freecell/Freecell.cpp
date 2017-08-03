#include "Freecell.h"
#include <stdlib.h>


Freecell::Freecell()
{
}

void Freecell::gameStart()
{
	displayRules();
	while (!m_endgame && !m_gamewinner)
	{
		system("CLS");
		this->m_game.printBoard();
 		playerInput();
		playerMove();
		checkForWin();
	}
}

void Freecell::displayRules()
{
		std::cout << "                 ***************   FREECELL   *****************";
		std::cout << std::endl << std::endl;
		std::cout << "The object of the game is to build up all cards on foundations from Ace to King";
		std::cout << std::endl;
		std::cout << "by following suit. You win when all 52 cards are moved to the home Cell area";
		std::cout << std::endl << std::endl;
		std::cout << "                                    RULES";
		std::cout << std::endl;
		std::cout << "Only one card can be moved at a time. There are four free cells in the upper ";
		std::cout << std::endl;
		std::cout << "left that can be used for any card but only one at a time. If a row is empty, ";
		std::cout << std::endl;
		std::cout << "you can only move a King to that spot. To move a card onto another rpw, the ";
		std::cout << std::endl;
		std::cout << "card must be in sequence and a different color. Example, a 3 can only be moved";
		std::cout << std::endl;
		std::cout << "on top of a 4of a different color. The home cells in the upper right have a";
		std::cout << std::endl;
		std::cout << "stricter sequence. The first card to go into a home cell must be an Ace of";
		std::cout << std::endl;
		std::cout << "the same suite as the cell.The cards that follow would be a 2, 3, 4 ect, all";
		std::cout << std::endl;
		std::cout << "of the same suite.";
		std::cout << std::endl << std::endl;
		std::cout << "		        	 HOW TO PLAY";
		std::cout << std::endl;
		std::cout << "To play you will be asked to enter a move. There are two entries. The first";
		std::cout << std::endl;
		std::cout << "is the origin and the second is the destination. If you want to move from";
		std::cout << std::endl;
		std::cout << "row 4 to row 8,you entry would be (4 8). There needs to be space between the";
		std::cout << std::endl;
		std::cout << " two entries. To moveto a free cell, use the destination numbers above the";
		std::cout << std::endl;
		std::cout << "cell, 10 through 13. For the home cells, use the characters to match. For";
		std::cout << std::endl;
		std::cout << "example, row 5 to home, (5 C)";
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "At anytime you can enter (Q Q) and you will be prompted to quit or play again";
		std::cout << std::endl;
		std::cout << "GOOD LUCK!!!!!!!!!!!";
		std::cout << std::endl;
		system("pause");
}

void Freecell::playerInput()
{
	std::string firstinput;
	std::string secondinput;
	bool correctInput = false;

	while (!(correctInput || this->m_endgame))
	{
		std::cout << "Enter move: ";
		std::cin >> firstinput >> secondinput;
		if (firstinput == "Q")
		{
			this->m_endgame = true;
			this->m_firstinput = 100;
		}
		else
		{
			if (validInput(firstinput, secondinput))
			{
				convertStringToInt(firstinput, secondinput);
				correctInput = true;
			}
			if (!correctInput)
				std::cout << "Invalid input" << std::endl;
		}
	}
}

void Freecell::playerMove()
{
	if (this->m_firstinput <= 8 && this->m_firstinput > 0)
	{
		if (this->m_secondinput <= 8)
			RowToRow();
		if (this->m_secondinput > 8 && this->m_secondinput <= 13)
			RowToFreecell();
		if (this->m_secondinput > 13 && this->m_secondinput <= 17)
			RowToHomecell();
	}
	if (this->m_firstinput > 8 && this->m_firstinput <= 13)
	{
		if (this->m_secondinput <= 8)
			FreecellToRow();
		if (this->m_secondinput > 8 && this->m_secondinput <= 13)
			FreecellToFreecell();
		if (this->m_secondinput > 13 && this->m_secondinput <= 17)
			FreecellToHomecell();
	}
	if (this->m_firstinput > 13 && this->m_firstinput <= 17)
	{
		if (this->m_secondinput <= 8)
			HomecellToRow();
		if (this->m_secondinput > 8 && this->m_secondinput <= 13)
			HomecellToFreecell();
	}

}

void Freecell::checkForWin()
{
	int fullStacks = 0;
	for (int i = 0; i < 4; i++)
	{
		if (this->m_game.getHomcell(i).isFull())
			fullStacks++;
	}
	if (fullStacks == 4)
		this->m_gamewinner = true;
}

void Freecell::playAgain()
{
	char input;
	std::cout << "Wanna play again? (Y or N): ";
	std::cin >> input;
	if (toupper(input) == 'Y')
	{
		this->m_endgame = false;
		this->m_gamewinner = false;
	}
}

bool Freecell::validInput(std::string first, std::string second)
{
	bool firstInputValid = false;
	bool secondInputValid = false;

	std::string checkArray[21] = { "1","2","3","4","5","6","7"
	,"8","10","11","12","13","C","D","H","S","c","d","h","s"};

	for (int i = 0; i < 21; i++)
	{
		if (first == checkArray[i])
		{
			firstInputValid = true;
			i = 21;
		}
	}

	for (int i = 0; i < 21; i++)
	{
		if (second == checkArray[i])
		{
			secondInputValid = true;
			i = 21;
		}
	}

	if (firstInputValid && secondInputValid)
		return true;
	else
	    return false;
}

bool Freecell::validMove()
{
	char firstCard = this->m_game.getColumn(m_firstinput).Peek().m_cardtype;
	char secondCard = this->m_game.getColumn(m_secondinput).Peek().m_cardtype;

	if(firstCard == 'C' && secondCard != 'S')
		if (this->m_game.getColumn(m_firstinput).Peek().m_cardrank
			== this->m_game.getColumn(m_secondinput).Peek().m_cardrank - 1)
				return true;

	if(firstCard == 'D' && secondCard != 'H')
		if (this->m_game.getColumn(m_firstinput).Peek().m_cardrank
			== this->m_game.getColumn(m_secondinput).Peek().m_cardrank - 1)
			return true;

	if(firstCard == 'H' && secondCard != 'D')
		if (this->m_game.getColumn(m_firstinput).Peek().m_cardrank
			== this->m_game.getColumn(m_secondinput).Peek().m_cardrank - 1)
			return true;

	if(firstCard == 'S' && secondCard != 'C')
		if (this->m_game.getColumn(m_firstinput).Peek().m_cardrank
			== this->m_game.getColumn(m_secondinput).Peek().m_cardrank - 1)
			return true;
	else
		return false;
}

void Freecell::convertStringToInt(std::string first, std::string second)
{
	if (first == "1") this->m_firstinput = 1;
	if (first == "2") this->m_firstinput = 2;
	if (first == "3") this->m_firstinput = 3;
	if (first == "4") this->m_firstinput = 4;
	if (first == "5") this->m_firstinput = 5;
	if (first == "6") this->m_firstinput = 6;
	if (first == "7") this->m_firstinput = 7;
	if (first == "8") this->m_firstinput = 8;
	if (first == "10") this->m_firstinput = 10;
	if (first == "11") this->m_firstinput = 11;
	if (first == "12") this->m_firstinput = 12;
	if (first == "13") this->m_firstinput = 13;
	if (first == "C") this->m_firstinput = 14;
	if (first == "D") this->m_firstinput = 15;
	if (first == "H") this->m_firstinput = 16;
	if (first == "S") this->m_firstinput = 17;
	if (first == "c") this->m_firstinput = 14;
	if (first == "d") this->m_firstinput = 15;
	if (first == "h") this->m_firstinput = 16;
	if (first == "s") this->m_firstinput = 17;

	if (second == "1") this->m_secondinput = 1;
	if (second == "2") this->m_secondinput = 2;
	if (second == "3") this->m_secondinput = 3;
	if (second == "4") this->m_secondinput = 4;
	if (second == "5") this->m_secondinput = 5;
	if (second == "6") this->m_secondinput = 6;
	if (second == "7") this->m_secondinput = 7;
	if (second == "8") this->m_secondinput = 8;
	if (second == "10") this->m_secondinput = 10;
	if (second == "11") this->m_secondinput = 11;
	if (second == "12") this->m_secondinput = 12;
	if (second == "13") this->m_secondinput = 13;
	if (second == "C") this->m_secondinput = 14;
	if (second == "D") this->m_secondinput = 15;
	if (second == "H") this->m_secondinput = 16;
	if (second == "S") this->m_secondinput = 17;
	if (second == "c") this->m_secondinput = 14;
	if (second == "d") this->m_secondinput = 15;
	if (second == "h") this->m_secondinput = 16;
	if (second == "s") this->m_secondinput = 17;
}

void Freecell::RowToRow()
{
	if (!this->m_game.getColumn(this->m_firstinput).isEmpty())
	{
		if (!this->m_game.getColumn(this->m_secondinput).isEmpty())
		{
			if (validMove())
				this->m_game.getColumn(m_secondinput).Push(this->m_game.getColumn(m_firstinput).Pop());
			else
			{
				std::cout << "Not a valid move" << std::endl;
				system("pause");
			}
		}
		else
		{
			if (this->m_game.getColumn(this->m_firstinput).Peek().m_cardrank == 13)
				this->m_game.getColumn(this->m_secondinput).Push(this->m_game.getColumn(this->m_firstinput).Pop());
			else
			{
				std::cout << "Not a valid move" << std::endl;
				system("pause");
			}
		}
	}
	else
	{
		std::cout << "Not a valid move" << std::endl;
		system("pause");
	}

}

void Freecell::RowToFreecell()
{
	if (!this->m_game.getColumn(this->m_firstinput).isEmpty())
	{
		if (this->m_game.m_freecellArea[m_secondinput - 10].m_cardnumber == "0")
			this->m_game.m_freecellArea[m_secondinput - 10] = this->m_game.getColumn(m_firstinput).Pop();
		else
		{
			std::cout << "Not a valid move" << std::endl;
			system("pause");
		}
	}
	else
	{
		std::cout << "Not a valid move" << std::endl;
		system("pause");
	}
}

void Freecell::RowToHomecell()
{
	if (!this->m_game.getColumn(this->m_firstinput).isEmpty())
	{
		if (!this->m_game.getHomcell(m_secondinput - 14).isEmpty())
		{
			if (this->m_game.getColumn(m_firstinput).Peek().m_cardtype
				== this->m_game.getHomcell(m_secondinput - 14).Peep().m_cardtype)
				if (this->m_game.getColumn(m_firstinput).Peek().m_cardrank
					== this->m_game.getHomcell(m_secondinput - 14).Peep().m_cardrank + 1)
				{
					this->m_game.getHomcell(m_secondinput - 14).Push(this->m_game.getColumn(m_firstinput).Pop());
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
		}
		else
		{
			if (this->m_game.getColumn(m_firstinput).Peek().m_cardrank == 1)
			{
				if (m_secondinput == 14)
					if (this->m_game.getColumn(m_firstinput).Peek().m_cardtype == 'C')
						this->m_game.getHomcell(m_secondinput - 14).Push(this->m_game.getColumn(m_firstinput).Pop());
					else
					{
						std::cout << "Not a valid move" << std::endl;
						system("pause");
					}
				if (m_secondinput == 15)
					if (this->m_game.getColumn(m_firstinput).Peek().m_cardtype == 'D')
						this->m_game.getHomcell(m_secondinput - 14).Push(this->m_game.getColumn(m_firstinput).Pop());
					else
					{
						std::cout << "Not a valid move" << std::endl;
						system("pause");
					}
				if (m_secondinput == 16)
					if (this->m_game.getColumn(m_firstinput).Peek().m_cardtype == 'H')
						this->m_game.getHomcell(m_secondinput - 14).Push(this->m_game.getColumn(m_firstinput).Pop());
					else
					{
						std::cout << "Not a valid move" << std::endl;
						system("pause");
					}
				if (m_secondinput == 17)
					if (this->m_game.getColumn(m_firstinput).Peek().m_cardtype == 'S')
						this->m_game.getHomcell(m_secondinput - 14).Push(this->m_game.getColumn(m_firstinput).Pop());
					else
					{
						std::cout << "Not a valid move" << std::endl;
						system("pause");
					}
			}
			else
			{
				std::cout << "Not a valid move" << std::endl;
				system("pause");
			}
		}
	}
	else
	{
		std::cout << "Not a valid move" << std::endl;
		system("pause");
	}
}

void Freecell::FreecellToRow()
{
	int firstCardRank = this->m_game.m_freecellArea[this->m_firstinput -10].m_cardrank;
	int secondCardRank = this->m_game.getColumn(this->m_secondinput).Peek().m_cardrank;
	char firstCardType = this->m_game.m_freecellArea[this->m_firstinput -10].m_cardtype;
	char secondCardType = this->m_game.getColumn(this->m_secondinput).Peek().m_cardtype;

	if (!this->m_game.getColumn(this->m_secondinput).isEmpty())
	{
		if (this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber != "0")
		{
			if (firstCardType == 'C')
			{
				if (firstCardRank == secondCardRank - 1 && secondCardType != 'S')
				{
					this->m_game.getColumn(this->m_secondinput).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
			}

			if (firstCardType == 'D')
				if (firstCardRank == secondCardRank - 1 && secondCardType != 'H')
				{
					this->m_game.getColumn(this->m_secondinput).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}

			if (firstCardType == 'H')
				if (firstCardRank == secondCardRank - 1 && secondCardType != 'D')
				{
					this->m_game.getColumn(this->m_secondinput).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}

			if (firstCardType == 'S')
				if (firstCardRank == secondCardRank - 1 && secondCardType != 'C')
				{
					this->m_game.getColumn(this->m_secondinput).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
		}
		else
		{
			std::cout << "You do realize that the freecell is empty" << std::endl;
			system("pause");
		}
	}
	else
	{
		if (this->m_game.m_freecellArea[this->m_firstinput].m_cardrank == 13)
		{
			this->m_game.getColumn(this->m_secondinput).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
		}
		else
		{
			std::cout << "You do realize that the freecell is empty" << std::endl;
			system("pause");
		}
	}
}

void Freecell::FreecellToHomecell()
{


	if (this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber != "0")
	{
		if (!this->m_game.getHomcell(this->m_secondinput - 14).isEmpty())
		{
			int firstCardRank = this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardrank;
			char firstCardType = this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardtype;
			int secondCardRank = this->m_game.getHomcell(this->m_secondinput - 14).Peep().m_cardrank;
			char secondCardType = this->m_game.getHomcell(this->m_secondinput - 14).Peep().m_cardtype;

			if (firstCardType == 'C')
			{
				if (firstCardRank == secondCardRank + 1 && secondCardType == 'C')
				{
					this->m_game.getHomcell(this->m_secondinput - 14).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
			}

			if (firstCardType == 'D')
				if (firstCardRank == secondCardRank + 1 && secondCardType == 'D')
				{
					this->m_game.getHomcell(this->m_secondinput - 14).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}

			if (firstCardType == 'H')
				if (firstCardRank == secondCardRank + 1 && secondCardType == 'H')
				{
					this->m_game.getHomcell(this->m_secondinput - 14).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}

			if (firstCardType == 'S')
				if (firstCardRank == secondCardRank + 1 && secondCardType == 'S')
				{
					this->m_game.getHomcell(this->m_secondinput - 14).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
		}
		else
		{
			if (this->m_secondinput == 14)
			{
				if (this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardtype == 'C')
				{
					this->m_game.getHomcell(this->m_secondinput - 14).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
			}
			if (this->m_secondinput == 15)
			{
				if (this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardtype == 'D')
				{
					this->m_game.getHomcell(this->m_secondinput - 14).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
			}
			if (this->m_secondinput == 16)
			{
				if (this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardtype == 'H')
				{
					this->m_game.getHomcell(this->m_secondinput - 14).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
			}
			if (this->m_secondinput == 17)
			{
				if (this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardtype == 'S')
				{
					this->m_game.getHomcell(this->m_secondinput - 14).Push(this->m_game.m_freecellArea[this->m_firstinput - 10]);
					this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
			}
		}
	}
 	else
	{
		std::cout << "You do realize that the freecell is empty" << std::endl;
		system("pause");
	}
}

void Freecell::FreecellToFreecell()
{
	if (this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber != "0")
	{
		if (this->m_game.m_freecellArea[this->m_secondinput - 10].m_cardnumber == "0")
		{
			this->m_game.m_freecellArea[this->m_secondinput - 10] = this->m_game.m_freecellArea[this->m_firstinput- 10];
			this->m_game.m_freecellArea[this->m_firstinput - 10].m_cardnumber = "0";
		}
		else
		{
			std::cout << "Not a valid move" << std::endl;
			system("pause");
		}
	}
	else
	{
		std::cout << "Not a valid move" << std::endl;
		system("pause");
	}
}

void Freecell::HomecellToRow()
{
	
		if (!this->m_game.getHomcell(this->m_firstinput - 14).isEmpty())
		{
			if (!this->m_game.getColumn(this->m_secondinput).isEmpty())
			{
				if (this->m_game.getHomcell(this->m_firstinput - 14).Peep().m_cardrank
					== this->m_game.getColumn(this->m_secondinput).Peek().m_cardrank - 1)
				{
					this->m_game.getColumn(this->m_secondinput).Push(this->m_game.getHomcell(this->m_firstinput - 14).Pop());
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
			}
			else
				if (this->m_game.getColumn(this->m_secondinput).Peek().m_cardrank == 13)
				{
					this->m_game.getColumn(this->m_secondinput).Push(this->m_game.getHomcell(this->m_firstinput).Pop());
				}
				else
				{
					std::cout << "Not a valid move" << std::endl;
					system("pause");
				}
		}
		else
		{
			std::cout << "Not a valid move" << std::endl;
			system("pause");
		}
	

}

void Freecell::HomecellToFreecell()
{
	if (!this->m_game.getHomcell(this->m_firstinput - 14).isEmpty())
		if (this->m_game.m_freecellArea[this->m_secondinput - 10].m_cardnumber == "0")
		{
			this->m_game.m_freecellArea[this->m_secondinput - 10]
				= this->m_game.getHomcell(this->m_firstinput - 14).Pop();
		}
		else
		{
			std::cout << "Not a valid move" << std::endl;
			system("pause");
		}
}

bool Freecell::getGameWinner() const
{
	return this->m_gamewinner;
}

bool Freecell::getEndGame() const
{
	return this->m_endgame;
}
