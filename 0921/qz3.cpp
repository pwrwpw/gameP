#include <stdio.h>
#include <string.h>
int main(void)
{
	char ch[100];
	int len;
	int result = -1;
	
	printf("������ �Է��ϼ��� > ");
	scanf("%s",ch);
	len = strlen(ch);
	for(int i=0;i<len/2;i++){
		if (ch[i] == ch[len-i-1]){
			result = 0;
		}
	}
		if(result==0){
			printf("�� ������ ȸ���Դϴ�.\n");
		}
		else{
			printf("�� ������ ȸ���� �ƴմϴ�.\n");
		}
	return 0;
}
