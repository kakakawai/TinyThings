# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <time.h>
# include <windows.h>
int main (void)
{
	/*��ʼ����Ϸѭ��*/
	int i,j,k;
	char again = 'y';
	bool correct = true;
	int counter = 0;
	int length = 2;
	int number = 0;
	time_t seed = 0;
    time_t now = 0;
    long time_taken = 0;

	printf("                      ������Ϸ\n");
	printf("             ��չʾһ�����ֲ���ʾһ�����ʧ\n");
	printf("               ����ʧ���밴��ԭ��˳������\n");
	printf("               ��������֮���ÿո��������\n");
	printf("           �����������һ�����ֺ�س�ȷ������\n");
	printf("=====================================================\n");
	printf("����y������Ϸ��");
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
*//*��ʱ���Ϸѽ��﷨*/
			for(k = 1;k<=length;k++)
			{
				printf(" ");
			}

			if(counter == 1)
				printf("\n������ղŵ����֣������˿ո�\n");
			else
				printf("\r");
			srand((unsigned int)seed);
			for(j = 1;j <=length;j++)
			{
				scanf("%d",&number);/*����һ���ְ�һ�οո�*/
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