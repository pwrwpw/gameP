#include <stdio.h>
#include <string.h>
int main(void)
{
	char ch[100];
	int len;
	int result = -1;
	
	printf("문장을 입력하세요 > ");
	scanf("%s",ch);
	len = strlen(ch);
	for(int i=0;i<len/2;i++){
		if (ch[i] == ch[len-i-1]){
			result = 0;
		}
	}
		if(result==0){
			printf("이 문장은 회문입니다.\n");
		}
		else{
			printf("이 문장은 회문이 아닙니다.\n");
		}
	return 0;
}
