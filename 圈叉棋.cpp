# include <stdio.h>
# include <ctype.h>
int main (void)
{
	/*����˵��*/
	printf("                     ������������Ϸ���򡿡�");
	printf("\n================================================================\n");
	printf("������ң�һ����Ȧ��һ����棬������3X3�ĸ��ϴ��Լ��ķ��š�\n");
	printf("�����Ժᡢֱ��б����һ����Ϊʤ�����˫�����µ���ȷ���󣬽��ú;֡�\n");
	printf("==================================================================\n");
/*��Ϸѭ��*/
	int again = 0;
	do
	{	
	/*������*/
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



	/*��ѭ��*/
		for(i = 0;i<9 && winner == 0;i++)
		{
		/*��ʾ����*/
			printf("\n������Ϸ��ʼ���� \n");
			printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
			printf("---+---+---\n");
			printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
			printf("---+---+---\n");
			printf(" %c | %c | %c \n\n",board[2][0],board[2][1],board[2][2]);
		/*�������*/
			player = i % 2 +1;

		/*��������*/
			do
			{
				printf("���%d,��������ѡ���ӵ�������������'%c'��",player,player == 1 ? 'X':'O');
				scanf("%d",&choice);
				row = --choice/3;
				column = choice % 3;
				if(board[row][column]>'9')
				{
					printf("\n%d�ѱ�ѡ��������ѡ��\n",choice);
				}

			}
			while(choice<0||choice>9||board[row][column]>'9');
			board[row][column] = player == 1 ? 'X':'O';

		/*�ж�ʤ��*/
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
	/*������*/
		if(winner == 0)
		{
			printf("���ϧ���Ǹ�ƽ�֡�\n");
		}
		else
		{
		printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
		printf("---+---+---\n");
	    printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
		printf("---+---+---\n");
		printf(" %c | %c | %c \n\n",board[2][0],board[2][1],board[2][2]);
     	printf("==================================================================\n");
    	printf("��ʤ����player%d.\n",player);
		}
		printf("\n�Ƿ�����һ�֣�Y/N��?:");
		scanf(" %c",&again);
	}
	while(tolower(again)== 'y');
	return 0;
}