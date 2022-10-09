#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define SPACE 4	
int intro_game(void);
int menu();
int game(void);
void levelSelectMenu();
void title();
void draw_check02(int r, int c);
void number_display(int n);
void display_rule(int n, char question[][10],int sleep_speed);
void make_question(int n, char question[][10]);
void game_control(char question[][10], int n, int *count,int sleep_speed);
void clear_text(void);
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);
void textcolor(int color_number);

int main(void)
{
		while(1){
			title();
			int menuValue = menu();
			if(menuValue == 0){
				game();
				system("cls");
				// ���� ���� 
			}
			else if(menuValue == 1){
				system("cls");
				printf("���� �Ǿ����ϴ�.");
				return 0;
			}
	}
	return 0;
}
int game(void)
{
	int n, count=0,select,sleep_speed;
	char question[10][10]={0};
	char answer[10][10]={0};
	long pst, seconds, minutes;
	clock_t start, end;

	srand(time(NULL));
	while(1)
	{
		levelSelectMenu();
		scanf("%d",&select);
		system("cls");
		if(select == 1){
			sleep_speed = 5000;
			break;
			// easy
		}
		else if(select == 2){
			sleep_speed = 3000;
			break;
			// normal
		}
		else if(select == 3){
			sleep_speed = 1000;
			break;
			// hard
		}
		else if(select == 0) return 0; // menu
		else continue;
	}
	n=intro_game();
	system("cls");
	draw_check02(n, n);
	number_display(n);
	display_rule(n, question,sleep_speed);
	number_display(n);
	start=clock();
	do
	{
		game_control(question, n, &count,sleep_speed);
	}while(count<n*n/2);
	gotoxy(2, 18);
	printf("��� �¾ҽ��ϴ�. �ƹ��ų� ������ �޴��� ���ư��ϴ�. \n");
	end=clock();
	pst=(end-start)/CLK_TCK;
	minutes=pst/60;
	seconds=pst-minutes*60;
	gotoxy(2, 19);
	printf("����ð� : %ld�� %ld ��\n", minutes, seconds);
	getch();
	return 0;
}
 
int intro_game(void)
{
 //[�Լ� 11.3.1]�� ���� �κ� ����
	int n;
	system("cls");
	printf("���� ���� ���߱� \n\n");
	printf("���ڸ���� �ǿ� ������ �� ���� ���ڸ� ã�� \n");
	printf("�����Դϴ�. \n\n");
	printf("���� ����(4 �Ǵ� 6)�� �Է��ϰ� Enter>");
	scanf("%d",&n);
	if(n == 4 || n == 6) 	return n;
	else intro_game();
}
void display_rule(int n, char question[][10],int sleep_speed)
{
 //[�Լ� 11.3.2]�� ���� �κ� ����
	gotoxy(2,14);
	printf("���� ���� ���ڸ���� ���� �ڿ��� \n");
	gotoxy(2,15);
	printf("���� ����� ���ڰ� �ΰ��� ���� �ֽ��ϴ�. \n");
	gotoxy(2,16);
	printf("�ƹ�Ű�� ������ ����ȭ���� ��� ��Ÿ���ϴ�. \n");
	getch();
	clear_text();
	make_question(n, question);
	gotoxy(2,14);
	printf("����ȭ���� ���� �����ϴ�. \n");
	gotoxy(2,15);
	printf("%d�� �ڿ� ���� Ǯ�̸� �����մϴ�. \n",sleep_speed/1000);
	Sleep(sleep_speed);
	clear_text();
}
void game_control(char question[][10], int n, int *count,int sleep_speed)
{
 //[�Լ� 11.3.3]�� ���� �κ� ����
int user1, user2, row1, row2, col1, col2;
	int position=14;
	gotoxy(2, position);
	printf("ù��° ���ڸ� �Է��ϰ� Enter>");
	scanf("%d", &user1);
	if(user1 < 0 || user1 >= n*n){
		while(user1 < 0 || user1 >= n*n){
			gotoxy(2, position);
			printf("�Էµ� ���� ���� ���� �ʽ��ϴ�. �ٽ� �Է� ���ּ���.>");
			scanf("%d",&user1);
			clear_text();
	}
}
	row1=user1/n;
        col1=user1%n;
	gotoxy(2, position+1);
	printf("�ι�° ���ڸ� �Է��ϰ� Enter>");
	scanf("%d", &user2);
	if(user2 < 0 || user2 >= n*n ){
		while(user2 < 0 ||user2 >= n*n){
			gotoxy(2, position+1);
			printf("�Էµ� ���� ���� ���� �ʽ��ϴ�. �ٽ� �Է� ���ּ���.>");
			scanf("%d",&user2);
			clear_text();
		}
	}
	else if(user2 == user1){
		while(user2 == user1){
			gotoxy(2, position+2);
			printf("�Էµ� ���� �����մϴ�. �ٽ� �Է� ���ּ���.>");
			scanf("%d",&user2);
			clear_text();
		}
	}	
	row2=user2/n;
	col2=user2%n;
	gotoxy(28, 4);
	printf("���� ����:%2d��(�� %2d��)", *count, n*2);
	for(int i = 0; i < (n*n/2); i++){ // �̺κ� �����ϱ� 
		if (i < (n*n/4))
			gotoxy(28 + (4 * i), 5);
		else
			gotoxy(28 + (4 * (i - (n * n / 4))), 6);
		printf("%c", (char)'A'+i);
		}
	if (question[row1][col1]==question[row2][col2])
	{
		*count=*count+1;
		gotoxy(28, 4);
		printf("���� ����:%2d��(�� %2d��)", *count, n*2);
		  if((int)question[row1][col1] - 65 < (n*n/4))
		  		gotoxy(30 + 4 * ((int)question[row1][col1]-65),5);
		  else
		  		gotoxy(30 + 4 * ((int)question[row1][col1]-65 - (n*n / 4)),6);	
		printf("0"); 
		gotoxy(3+4*col1, 2+2*row1);
		printf("%2c", question[row1][col1]);
		gotoxy(3+4*col2, 2+2*row2);
		printf("%2c", question[row2][col2]);
	  	gotoxy(2, 16);
	    printf("�¾ҽ��ϴ�. �ƹ�Ű�� ������ �ٽ� �����մϴ�. ");
  		getch();
		clear_text();
	}
	else
	{
		  gotoxy(3+4*col1, 2+2*row1);
		  printf("%2c", question[row1][col1]);
		  gotoxy(3+4*col2, 2+2*row2);
		  printf("%2c", question[row2][col2]);
		  Sleep(3000);
		  gotoxy(3+4*col1, 2+2*row1);
		  printf("%2d", user1);
		  gotoxy(3+4*col2, 2+2*row2);
		  printf("%2d", user2);
  	  	  clear_text();
  	  	  gotoxy(2, position+1);
	      printf("Ʋ�Ƚ��ϴ�. �ƹ�Ű�� ������ �����մϴ�. ");
		  getch();
		  clear_text();
	}
}
void clear_text(void)
{
 //[�Լ� 11.3.4]�� ���� �κ� ����
	int i, j;
	for(i=13;i<18;i++)
	{
		gotoxy(1, i);
		for(j=0;j<70;j++)
			printf(" ");
	}
}
void number_display(int n)
{
 //[�Լ� 11.3.5]�� ���� �κ� ����
  textcolor(15);
  int i, j, count=0;
  for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	  {
		  gotoxy(3+4*j, 2+2*i);
		  printf("%2d", count);
		  count++;
	  }
}
void make_question(int n, char question[][10])
{
 //[�Լ� 11.3.6]�� ���� �κ� ����
  int number, i, j, ran, count1=0, count2=0;
  char chr1[26], chr2[26], temp;
  srand(time(NULL));
  number=n*n/2;
  for(i=0;i<26;i++)   {
	  chr1[i]=65+i;
	  chr2[i]=i;
  }
  for(i=0;i<number;i++)   {
	  ran=rand()%number;
	  temp=chr1[i];
	  chr1[i]=chr1[ran];
	  chr1[ran]=temp;
  }
  for(i=0;i<number;i++)   {
	  ran=rand()%number;
	  temp=chr2[i];
	  chr2[i]=chr2[ran];
	  chr2[ran]=temp;
  }
   for(i=0;i<n;i++)
	   for(j=0;j<n;j++) 	   {
		   if (count1<number)    {
				question[i][j]=chr1[count1];
				count1++;
		   }
		   else    {
			   question[i][j]=chr1[chr2[count2]];
			   count2++;
		   }
	   }
   for(i=0;i<n;i++)    {
	   for(j=0;j<n;j++) 	   {
		  gotoxy(3+4*j, 2+2*i);
		  printf("%2c", question[i][j]);
		 }
          }
}
void draw_check02(int r, int c)
{
 //[�Լ� 3.5.4]�� ���� �κ� ����
    int i, j;
    unsigned char a=0xa6;
    unsigned char b[12]; 
    for(i=1;i<12;i++)
	b[i]=0xa0+i;
    printf("%c%c",a, b[3]);
    for(i=0;i<2*c-1;i++)
    {
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[8]);
    }
    printf("%c%c", a, b[1]);
    printf("%c%c", a, b[4]);
    printf("\n");
    for(i=0;i<r-1;i++)
    {
	printf("%c%c", a, b[2]);
	for(j=0;j<2*c;j++)
	{
		printf(" ");
		printf("%c%c",a, b[2]);
	}
	printf("\n");
	printf("%c%c", a, b[7]);
	for(j=0;j<2*c-1;j++)
	{
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[11]);
	}
	printf("%c%c",a, b[1]);
	printf("%c%c",a, b[9]);
	printf("\n");
    }
    printf("%c%c", a, b[2]);
    for(j=0;j<2*c;j++)
    {
	printf(" ");
	printf("%c%c",a, b[2]);
    }
    printf("\n");
    printf("%c%c", a, b[6]);
    for(i=0;i<2*c-1;i++)
    {
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[10]);
    }
    printf("%c%c", a, b[1]);
    printf("%c%c", a, b[5]);
    printf("\n");
}
void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void title(){
	textcolor(10);
	printf("\n\n"); // 3ĭ ���� 
	printf("         ####      #    #       #  ###### \n");
	printf("        #    #     #    ##     ##  #   \n");
	printf("       #          # #   ##     ##  #    \n");
	printf("       #          # #   # #   # #  #      \n");
	printf("       #  ####   #   #  # #   # #  ###### \n");
	printf("       #     #   #   #  #  # #  #  #      \n");
	printf("       #     #   #####  #  # #  #  #      \n");
	printf("       #     #  #     # #   #   #  #      \n");
	printf("        #   ##  #     # #   #   #  #      \n");
	printf("         ### #  #     # #       #  ###### \n");
}
int menu(){
	int x = 20;
	int y = 16;
	char key;
	gotoxy(x-2,y);
	printf("> ���ӽ���");
	gotoxy(x,y+1);
	printf("����");
do
    {
	gotoxy(1,1);
	gotoxy(x-2, y);
	printf("> ");
	gotoxy(35, 16);
	printf("����Ű�� �����ÿ�.");
	gotoxy(35,17);
	printf("������ �����̽��ٸ� �����ּ���.");
	key=getch();
	textcolor(7);
	if (key>=72){
		gotoxy(x-2,y);
		printf(" ");
		move_arrow_key(key, &x, &y, 37, 19); //�����κ�
	}
	else if(key == 32){
		return y-16;
	}

   }while(1);
}
void levelSelectMenu()
{
 textcolor(11);
 system("cls");
 printf("��-------------------------------��\n");
 printf("��    �Ǣ� ���̵� ���� �Ǣ�      ��\n");
 printf("��                               ��\n");
 printf("��        1. E a s y             ��\n");
 printf("��                               ��\n");
 printf("��        2. N o r m a l         ��\n");
 printf("��                               ��\n");
 printf("��        3. H a r d             ��\n");
 printf("��                               ��\n");
 printf("��        0. ���� �޴�           ��\n");
 printf("��                               ��\n");
 printf("��-------------------------------��\n");
 printf(" Select > ");
}
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch(key)
	{
	case 72:  //����(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1-1;
		if (*y1<16)	*y1=16; //y��ǥ�� �ּҰ�
		break;
	case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		*y1=*y1+1;
		if (*y1>17)  *y1=17; //y��ǥ�� �ִ밪(���)
		break;
	default:
		return;
	}
}
void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
