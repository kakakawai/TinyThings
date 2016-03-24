# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <time.h>
# include <windows.h>
int main (void)
{
	/*初始化游戏循环*/
	int i,j,k;
	char again = 'y';
	bool correct = true;
	int counter = 0;
	int length = 2;
	int number = 0;
	time_t seed = 0;
    time_t now = 0;
    long time_taken = 0;

	printf("                      记忆游戏\n");
	printf("             将展示一段数字并显示一秒后消失\n");
	printf("               在消失后请按照原来顺序输入\n");
	printf("               【【数字之间用空格隔开】】\n");
	printf("           【【输入最后一个数字后回车确定】】\n");
	printf("=====================================================\n");
	printf("按下y进行游戏：");
	scanf("%c",&again);

	do
	{
		correct = true;
		counter = 0;
		length = 2;
		time_taken = clock();
		while(correct)
		{
			length += counter++%3 ==0;
			seed = time(NULL);
			now = clock();		
			srand((unsigned int)seed);
			for(i = 1;i<=length;i++)
			{
				printf(" %d",rand() % 10);
			}

			Sleep(1000);
			printf("\r");
/*
			for(;clock()-now < CLOCKS_PER_SEC;)
			{
				printf("\r");
			}
*//*延时，较费解语法*/
			for(k = 1;k<=length;k++)
			{
				printf(" ");
			}

			if(counter == 1)
				printf("\n请输入刚才的数字，别忘了空格：\n");
			else
				printf("\r");
			srand((unsigned int)seed);
			for(j = 1;j <=length;j++)
			{
				scanf("%d",&number);/*输入一个字按一次空格*/
				if(number != rand()%10)
				{
					correct = false;
					break;
				}
			}
			printf("%s\n",correct ? "correct!":"wrong!");
		}

    time_taken = (clock() - time_taken)/CLOCKS_PER_SEC;
	printf("==========================================\nYou score is %d\n",--counter*100);
    fflush(stdin);
    printf("Do you want to play again (y/n)?:\n");
	scanf(" %c",&again);
    }
	while(tolower(again)=='y');

	return 0;
}