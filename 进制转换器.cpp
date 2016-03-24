# include <stdio.h>
# include <windows.h>
# include <stdlib.h>
# include <math.h>
# define MAXSIZE 100

typedef struct SqStack
{
	int *base;
	int *top;
	int stacksize;
}SqStack;

void InitStack(SqStack *S);
void push(SqStack *S, int e);
void pop(SqStack *S);
void ten2x(int *p, SqStack *S);
void x2ten(int *p);
int SElemType[MAXSIZE];

int main(void)
{
	int num;
	int *p = &num;
	
	printf("输入数值：");
	scanf("%d",p);
	SqStack S;
	InitStack(&S);
	x2ten(p);
    ten2x(p,&S);
	

	return 0;
}

void ten2x(int *p, SqStack *S)
{
	int system;
	printf("输出的进制为：");
	scanf("%d",&system);
	//if(system == 2){};
	printf("结果：");

	while(*p)
	{
		//printf("%d",*p%system);
		push(S,*p%system);
		*p /= system;
	}
	//printf("\n%d\n%d\n%d\n%d\n",S->base,S->top,*S->base,*S->top); //辅助判断*S和S的作用（指针或值）
	for(int i = 0; i<MAXSIZE; i++)
	{
		//printf("%d\n",SElemType[i]);
	}
	while(S->top != S->base)
	{
		pop(S);
	}
	printf("\n");
    
}

void x2ten(int *p)
{
	int system;
	int sum = 0;
	int i = 0;
	int temp,j;
	printf("输入的进制为：");
	scanf("%d",&system);
	if(system == 10){};

	while(*p)
	{
		if((j = *p%10) >= system)
		{
			printf("输入错误，请查看数据或进制是否正确。\n");
			exit(1);
		}
		temp = pow(system,i);
		sum += j * temp;
		*p /= 10;
		i++;
	}
	*p = sum;
	//printf("ten = %d\n",*p);
}

void InitStack(SqStack *S)
{
	S->base = SElemType;
	if(!S->base)
	{
		printf("内存分配失败\n");
		exit(1);
	}
	S->top = S->base;
	S->stacksize = MAXSIZE;
}

void push(SqStack *S, int e)
{
	if((S->top - S->base) == S->stacksize)
	{
		printf("栈满\n");
		exit(1);
	}
	*(S->top) = e;
	S->top++;
}

void pop(SqStack *S)
{
	int e;
	if(S->top == S->base)
	{
		printf("栈空\n");
		exit(1);
	}
	S->top--;
	e = *(S->top);
	printf("%d",e);
}