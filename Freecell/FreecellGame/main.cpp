#include <Deck.h>
#include <Gameboard.h>
#include <Freecell.h>
#define _CRTDBG_MAP_ALLOC

bool winner = false;
bool end = false;


void main()
{
	try
	{
		while (!winner && !end)
		{
			Freecell game;
			game.gameStart();

			if (game.getGameWinner())
			{
				winner = true;
				std::cout << "Awesome. YOU WIN!!!!!!!";
				game.playAgain();
				if (!game.getGameWinner())
					winner = false;
			}
			if (game.getEndGame())
			{
				end = true;
				game.playAgain();
				if (!game.getEndGame())
					end = false;
			}
		}
		_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
		_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
		_CrtDumpMemoryLeaks();
	}
	catch (Exception & msg)
	{
		std::cerr << msg.getMessage();
	}
}