#include <stdio.h>

int main(){
	char c;
	scanf("%c",&c);
	while(1){
		if(c =='\n'){
			break;
		}
		printf("%c",c);
		scanf("%c",&c);

	} 
	printf("Good Bye");
	
	return 0;
}
