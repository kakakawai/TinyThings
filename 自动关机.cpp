# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 
int main(void)
{
	char time[20];
	char cmd[100];
	printf("=====================\n");
	printf("输入数字1取消定时关机\n");
	printf("=====================\n");
	printf("请输入关机时间（hh:mm:ss）：");
	scanf("%s",&time);
	if(!strcmp(time,"1"))
	{
		system("Shutdown -a");
	}
	else
	{
		sprintf(cmd,"at %s Shutdown -s",time);
		system(cmd);
	}
	scanf("%s",cmd);
	return 0;
}