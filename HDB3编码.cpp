//qw ���������
//as V������
//zx B������
//�������
//1.��1��ͷ�ҵ�һ��1�ı���Ϊ-1
//2.����1��+1��-1�������
//3.������4��0������ĸ�0ΪV��V����������һ��V�ķ����෴��������һ��������1������ͬ
//4.������������һ��V�෴�Ĺ���������һ�������1���ų�ͻ�����һ��0����ΪB��B����һ��������1�����෴
//5.B�������1ͬ��λ
#include <stdio.h>
/*
typedef struct Node
{
	char code = 'a';
	int index; 
	struct Node *prior;
	struct Node *next;
}Node,*pNode;
*/

char code[] = "1000010000110000000011k";
char curCode,preV,pre1;
int zeroCount = 0;


void HDB3encode(char *code);

int main(void)
{
	int i = 0;
	//gets(code);
	//printf("\nInput finished!%s",code);
	HDB3encode(code);
	i = 0;
	printf("HDB3 = %s",code);
	scanf("%d",i);
	return 0;
}

void HDB3encode(char *code)
{
	int i = 0;
	while(code[i] != 'k')
	{
		curCode = code[i];
		if(curCode == '0')
		{
			zeroCount += 1;
			if(zeroCount == 4)
			{
				zeroCount = 0;
				if(!preV)
				{
					if(pre1 == 'q')
					{
						curCode = preV = 'a';
					}
					if(pre1 == 'w')
					{
						curCode = preV = 's';
					}
				}
				else if(preV == 'a' && pre1 == 'q')
				{
					preV = curCode = 's';
					code[i-3] = 'x';
					pre1 = 'w';
				}
				else if(preV == 'a' && pre1 == 'w')
				{
					preV = curCode = 's';
				}
				else if(preV == 's' && pre1 == 'q')
				{
					preV = curCode = 'a';
				}
				else if(preV == 's' && pre1 == 'w')
				{
					preV = curCode = 'a';
					code[i-3] = 'z';
					pre1 = 'q';
				}
			}
		}
		if(curCode == '1')
		{
			if(!pre1)
			{
				curCode = pre1 = 'w';
			}
			else if(pre1 == 'q')
			{
				pre1 = curCode = 'w';
			}
			else if(pre1 == 'w')
			{
				pre1 = curCode = 'q';
			}
		}
		//printf("\n%c",curCode);
		code[i] = curCode;
		i++;
	}
}