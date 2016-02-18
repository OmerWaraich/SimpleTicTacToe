#include <stdio.h>

int main()
{
	int i = 0; // loop counter
	int player = 0; // 1 or 2 player
	int location = 0; // square location in board
	int row = 0; // row index for a square
	int colum = 0; // colum index for a square
	int line = 0; // row or colum index in checking loop
	int winner = 0; // the Winning Player
	int goloc = 0;
	char playerOne[25];
	char playerTwo[25];
	char board[3][3] = {
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	}; // These initilise values are reference numbers used to select a vacant square for a turn
	printf("Player one please enter your name :");
	scanf("%s", playerOne);
	printf("Second player please enter your name :");
	scanf("%s", playerTwo);
	printf("Welcome %s & %s", playerOne, playerTwo);

	for( i = 0; i < 9 && winner == 0; i++ )
	{

		printf("\n\n");
		printf("-------------------------\n");
		printf("|   %c   |   %c   |   %c   |\n",board[0][0], board[0][1], board[0][2]);
		printf("-------------------------\n");
		printf("|   %c   |   %c   |   %c   |\n",board[1][0], board[1][1], board[1][2]);
		printf("-------------------------\n");
		printf("|   %c   |   %c   |   %c   |\n",board[2][0], board[2][1], board[2][2]);
		printf("-------------------------\n");
		player = i % 2 + 1; // selecting player
		
		//To find the location which player selected
		do
		{
			printf("\n Player %d, please enter the name of the square numer! %c:", player,(player == 1)?'X':'&');
			scanf("%d", &goloc);
			row = -- goloc / 3; // get row index
			colum = goloc % 3; // get colum index 
		}
		while( goloc < 0 || goloc > 9 || board[row][colum]>'9');
			
		board[row][colum] = ( player == 1 ) ? 'X' : '&' ;	
			
		if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || 
		(board[0][2] == board[1][1] && board[0][2] == board[2][0]))
		{
			winner = player;
		}
		else
		{
			for (line = 0; line<= 2; line++)
			{
				if((board[line][0] == board[line][1] && board [line][0] == board[line][2]) || 
				(board[0][line] == board[1][line] && board[0][line] == board[2][line]))
				{
				winner = player;
				}
			}	
		}
	}
	printf("\n\n");
	printf("-------------------------\n");
	printf("|   %c   |   %c   |   %c   |\n",board[0][0], board[0][1], board[0][2]);
	printf("-------------------------\n");
	printf("|   %c   |   %c   |   %c   |\n",board[1][0], board[1][1], board[1][2]);
	printf("-------------------------\n");
	printf("|   %c   |   %c   |   %c   |\n",board[2][0], board[2][1], board[2][2]);
	printf("-------------------------\n");

	if( winner == 0) 
	{
		printf("Sorry! What a waste of time! Its a draw ;(\n");
	}
	if(winner == 1)
	{
		printf("\n Congratulations, %s, You won!!!\n", playerOne);
	}
	if(winner == 2)
	{
		printf("\n Congratulations, %s, You won!!!\n", playerTwo);
	}
	return 0;
}