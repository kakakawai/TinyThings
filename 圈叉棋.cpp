# include <stdio.h>
# include <ctype.h>
int main (void)
{
	/*规则说明*/
	printf("                     【【井字棋游戏规则】】");
	printf("\n================================================================\n");
	printf("两个玩家，一个打圈，一个打叉，轮流在3X3的格上打自己的符号。\n");
	printf("最先以横、直、斜连成一线则为胜。如果双方都下得正确无误，将得和局。\n");
	printf("==================================================================\n");
/*游戏循环*/
	int again = 0;
	do
	{	
	/*定义区*/
	int i = 0;
	int winner = 0;
	int player = 0;
	int choice = 0;
	int row = 0;
	int column = 0;
	int line = 0;
	

	char board[3][3]={
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}};



	/*主循环*/
		for(i = 0;i<9 && winner == 0;i++)
		{
		/*显示格子*/
			printf("\n【【游戏开始】】 \n");
			printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
			printf("---+---+---\n");
			printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
			printf("---+---+---\n");
			printf(" %c | %c | %c \n\n",board[2][0],board[2][1],board[2][2]);
		/*定义玩家*/
			player = i % 2 +1;

		/*轮流输入*/
			do
			{
				printf("玩家%d,请输入所选格子的数字用来放置'%c'：",player,player == 1 ? 'X':'O');
				scanf("%d",&choice);
				row = --choice/3;
				column = choice % 3;
				if(board[row][column]>'9')
				{
					printf("\n%d已被选择，请重新选择。\n",choice);
				}

			}
			while(choice<0||choice>9||board[row][column]>'9');
			board[row][column] = player == 1 ? 'X':'O';

		/*判断胜负*/
			if((board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[2][0]==board[1][1] && board[0][2]==board[1][1]))
			{
				winner = player;
			}
			else
			{
				for(line = 0;line<3;line++)
				{
					if((board[line][0]==board[line][1] && board[line][0]==board[line][2])||(board[0][line]==board[1][line] && board[0][line]==board[2][line]))
					{
						winner = player;
					}				
				}
			
			}
		
		}
	/*输出结果*/
		if(winner == 0)
		{
			printf("真可惜，是个平局。\n");
		}
		else
		{
		printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
		printf("---+---+---\n");
	    printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
		printf("---+---+---\n");
		printf(" %c | %c | %c \n\n",board[2][0],board[2][1],board[2][2]);
     	printf("==================================================================\n");
    	printf("获胜者是player%d.\n",player);
		}
		printf("\n是否再来一局（Y/N）?:");
		scanf(" %c",&again);
	}
	while(tolower(again)== 'y');
	return 0;
}