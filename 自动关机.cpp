# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 
int main(void)
{
	char time[20];
	char cmd[100];
	printf("=====================\n");
	printf("��������1ȡ����ʱ�ػ�\n");
	printf("=====================\n");
	printf("������ػ�ʱ�䣨hh:mm:ss����");
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