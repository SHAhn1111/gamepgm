#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define UP 0
#define DOWN 1
#define SUBMIT 2

char player1[10];
char player2[10];
int victoryCountP1 = 0;
int victoryCountP2 = 0;

void setConsole();
void cursorView(char show);
void textcolor(int color_number);
void gotoxy(int x, int y);
void titleDraw();
int keyControl();
int menuDraw();
void creatorDraw();
void infoDraw();
void draw_check(int c, int r);
void display_stone(int matrix[][20][20]);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
int game_end(int matrix[][20][20]);
void nickName();
void display_turn(int other);
void game_control(void);
void game_control1(void);
int retryDraw();
int retryDraw1();
int retryDraw2();
int playCount();

int main() {

	setConsole();
	cursorView(0);


	while(1) {
		titleDraw();
		int menuCode = menuDraw();

		if(menuCode == 0) {
			system("cls");
			int playCode = playCount(); 
			system("cls");
			if(playCode == 0){ 
				nickName();
			do {
				game_control();

				int retryCode = retryDraw();

				if(retryCode ==0) {
					retryCode = 5;
					continue;
				}

				else if(retryCode == 1)
					break;
				else if(retryCode == 2)
					return 0;
			} while(1);
			}
			else if(playCode==1){
				nickName();
			do {
				game_control1();
				if((victoryCountP1 == 3) || (victoryCountP2 ==3)){
					victoryCountP1 =0;
					victoryCountP2 =0;
					int retryCode2 = retryDraw2();
					
					if(retryCode2== 0){
							retryCode2 ==5;
							break;
					}else if(retryCode2 == 1){
							return 0;
						}
					
				}else{
				
				int retryCode1 = retryDraw1();
				
				if(retryCode1 == 0){
					retryCode1 ==5;
					continue;
				}else if(retryCode1 == 1){
				
					victoryCountP1 = 0;
					victoryCountP2 = 0;
				
					break;
			}
				else if(retryCode1 == 2)
					return 0;
			}
				} while(1);
		
			}
		} else if (menuCode == 1)
			infoDraw();
		else if(menuCode ==2)
			creatorDraw(); 
		else if(menuCode ==3)
			break;
		system("cls");
	}


	return 0;
}

void setConsole() {
	system("mode con cols=40 lines=30");
	system("title �������");

}

void cursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}



void gotoxy(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

void titleDraw() {
	PlaySound(TEXT("this-8-bit-music-245266.wav"), NULL, SND_ASYNC | SND_LOOP);
	textcolor(14);
	gotoxy(12,4);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	printf("�� ���� ���� ��");

}

int keyControl() {
	char temp = _getch();

	if(temp == 72) {
		return UP;
	} else if (temp ==80) {
		return DOWN;
	} else if (temp == ' ') {
		return SUBMIT;
	}
}



int menuDraw() {
	int x = 15;
	int y = 10;

	textcolor(11);
	gotoxy(x -2, y);
	printf("> ���� ����");
	gotoxy(x, y+1);
	printf("���� ����");
	gotoxy(x,y+2);
	printf("������ ����");
	gotoxy(x,y+3);
	printf(" ���� ");

	while(1) {
		int n = keyControl();
		switch(n) { 
			case UP: {
				if(y>10) {
					gotoxy(x-2,y);
					printf(" ");
					gotoxy(x-2, --y);
					printf(">");
				}
				break;
			}
			case DOWN: {
				if(y<13) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y-10;
			}
		}
	}

}
void infoDraw() {
	system("cls");

	gotoxy(15,3);
	printf("[���۹�]");

	gotoxy(13,5);
	printf("�̵� : ����Ű �Ǵ� WASD");
	gotoxy(13,6);
	printf("���� : �����̽���");
	gotoxy(9,7);
	printf("�� ���� ���� �����մϴ�.");

	gotoxy(11,10);
	printf("�����̽��ٸ� ������ \n");
	gotoxy(9,11);
	printf("����ȭ������ ���ư��ϴ�.");

	while(1) {
		if(keyControl()==SUBMIT)
			break;
	}
}

void creatorDraw() {
	system("cls");

	gotoxy(15,3);
	printf("[������]");

	gotoxy(13,5);
	printf("2024�г⵵ 2�б�");
	gotoxy(11,6);
	printf("�������α׷��� ����");
	gotoxy(13,8);
	printf("20�й� �ȼ���");
	gotoxy(9,10);
	printf("���� �ҽ��ڵ忡�� �����");
	gotoxy(9,11);
	printf("�߰�&������ ������� ����");



	gotoxy(11,13);
	printf("�����̽��ٸ� ������ \n");
	gotoxy(9,14);
	printf("����ȭ������ ���ư��ϴ�.");

	while(1) {
		if(keyControl()==SUBMIT)
			break;
	}
}

void draw_check(int c, int r) {
	int i,j;
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (i = 1; i<12; i++)
		b[i] = 0xa0 + i;

	printf("%c%c ", a, b[3]);

	for(i=0; i<c-1; i++)
		printf("%c%c ", a, b[8]);

	printf("%c%c ", a, b[4]);
	printf("\n");

	for(i=0; i< r - 1; i++) {
		printf(" ");
		printf("%c%c ", a, b[7]);

		for(j=0; j<c-1; j++)
			printf("%c%c ", a,b[11]);

		printf("%c%c ", a, b[9]);
		printf("\n");
	}

	printf(" ");
	printf("%c%c ",a,b[6]);

	for(i=0; i<c-1; i++)
		printf("%c%c ", a,b[10]);

	printf("%c%c ", a, b[5]);
	printf("\n");


	printf("  ���� : ESC\n");

}
void display_stone(int matrix[][20][20]) {
	int i, x, y;
	const char *stone[2]= {"��", "��"};

	for(i=0; i<2; i++)
		for(x=1; x<20; x++)
			for(y=1; y<20; y++) {
				if (matrix[i][x][y]==1) {
					gotoxy(x*2-1, y);
					printf("%s", stone[i]);
				}
			}
}
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b) {
	switch(key) {
		case 72:  //����(��) ������ ȭ��ǥ Ű �Է�
			*y1=*y1-1;
			if (*y1<1)	*y1=1; //y��ǥ�� �ּҰ�
			break;
		case 119:  //����(��) ������ w Ű �Է�
			*y1=*y1-1;
			if (*y1<1)	*y1=1; //y��ǥ�� �ּҰ�
			break;
		case 75:  //����(��) ������ ȭ��ǥ Ű �Է�
			*x1=*x1-2;             //������������ 2�� ����
			if (*x1<1)	*x1=1; //x��ǥ�� �ּҰ�
			break;
		case 97:  //����(��) ������ a Ű �Է�
			*x1=*x1-2;             //������������ 2�� ����
			if (*x1<1)	*x1=1; //x��ǥ�� �ּҰ�
			break;
		case 77:  //������(��) ������ ȭ��ǥ Ű �Է�
			*x1=*x1+2;               //������������ 2�� ����
			if (*x1>x_b)  *x1=x_b; //x��ǥ�� �ִ밪(���)
			break;
		case 100:  //������(��) ������ d Ű �Է�
			*x1=*x1+2;               //������������ 2�� ����
			if (*x1>x_b)  *x1=x_b; //x��ǥ�� �ִ밪(���)
			break;
		case 80:  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
			*y1=*y1+1;
			if (*y1>y_b)  *y1=y_b; //y��ǥ�� �ִ밪(���)
			break;
		case 115:  //�Ʒ���(��) ������ s Ű �Է�
			*y1=*y1+1;
			if (*y1>y_b)  *y1=y_b; //y��ǥ�� �ִ밪(���)
			break;
		default:
			return;
	}
}

int game_end(int matrix[][20][20]) {
	int count = 0;

	for (int i = 0; i<2; i++) { //���ΰ� 5���� ���
		for(int y = 1; y <20; y++) {
			count = 0;

			for (int x= 1; x <20; x++) {
				if(matrix[i][x][y])
					count++;
				else
					count = 0;
				if(count ==5)
					return (i+1);
			}
		}
	}
	for (int i = 0; i<2; i++) { //���ΰ� 5���� ���
		for(int x = 1; x <20; x++) {
			count = 0;

			for (int y= 1; y <20; y++) {
				if(matrix[i][x][y])
					count++;
				else
					count = 0;
				if(count ==5)
					return (i+1);
			}
		}
	}
	for (int i = 0; i<2; i++) { //���� �� - ������ �Ʒ�(\)�� 5���� ���
		for(int x = 1; x <16; x++) {
			count = 0;

			for (int y= 1; y <16; y++) {
				int temp1 = x;
				int temp2 = y;

				for(int j=0; j<5; j++) {
					if(matrix[i][temp1++][temp2++])
						count++;
					else
						count = 0;
				}
				if(count==5)
					return(i+1);
			}
		}
	}
	for (int i = 0; i<2; i++) { //���� �� - ������ �Ʒ�(\)�� 5���� ���
		for(int x = 1; x <16; x++) {
			count = 0;

			for (int y= 5; y <20; y++) {
				int temp1 = x;
				int temp2 = y;

				for(int j=0; j<5; j++) {
					if(matrix[i][temp1++][temp2--])
						count++;
					else
						count = 0;
				}
				if(count==5)
					return(i+1);
			}
		}
	}
	return 0;
}

void nickName() {

	cursorView(1);
	printf("player 1(�� ��)�� �г����� �Է��ϼ���(9�ڱ�������) : ");
	scanf("%s", player1);
	printf("player 2(�� ��)�� �г����� �Է��ϼ���(9�ڱ�������) : ");
	scanf("%s", player2);
	cursorView(0);
}

void display_turn(int other) {
	// ���� �ش� ������ ����� ���� ������ �����
	gotoxy(13, 0);
	printf("                           ");// ����� 

	gotoxy(13, 0); // �ٵ��� ���ʿ� ǥ��
	if (other == 0) {
		textcolor(12);
		printf("%s ���� (��)\n",player1);
	} else {
		textcolor(15);
		printf("%s ���� (��)\n",player2);
	}
	textcolor(15);
}


void game_control(void) {
	PlaySound("8-bit-music-on-245249.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ���
	int x = 1, y = 1, other = 0;
	int matrix[2][20][20] = {0}; 
	char key;
	const char *stone[2] = {"��", "��"};
	int warningDisplayed = 0; // ��� �޽��� ��� ���θ� �����ϴ� ����

	system("cls");
	do {
		gotoxy(1, 1);
		draw_check(18, 18);
		display_turn(other);
		gotoxy(x, y);
		printf("%s", stone[other]);
		display_stone(matrix);

		key = getch();
		if (key == 27) // ESCŰ�� ������ �� ���� ����
			exit(0);
		else if (key == 32) { // �����̽��ٸ� ������ �� ���� ���� ����
			// ���� ��ġ�� �̹� ���� �ִ��� Ȯ��
			if (matrix[0][(x + 1) / 2][y] == 1 || matrix[1][(x + 1) / 2][y] == 1) {
				gotoxy(0, 25); // �޽����� �ٵ��� �ϴܿ� ���
				printf("�̹� �ڸ��� ������ �ֽ��ϴ�. �ٽ� �����ּ���.");
				warningDisplayed = 1; // ��� �޽����� ǥ�õ��� ���
			} else {
				// �ڸ��� ��������� ���� ����
				matrix[other][(x + 1) / 2][y] = 1;
				other = 1 - other;  // �÷��̾� ��ü

				// ���� ��� �޽����� ������ ǥ�õǾ��ٸ� ����
				if (warningDisplayed) {
					gotoxy(0, 25);
					printf("                                             "); // ��� �޽��� ����
					warningDisplayed = 0; // ��� �޽��� ���� �� ���¸� �ʱ�ȭ
				}
			}
		} else if (key >= 72) {
			move_arrow_key(key, &x, &y, 37, 19);
		}

		// ������ �������� Ȯ��
		if (game_end(matrix) == 1) {
			system("cls");
			PlaySound("goodresult-82807.wav", 0, SND_FILENAME | SND_ASYNC); 
			gotoxy(11, 9);
			textcolor(12);
			printf("%s( �� )��(��) �̰���ϴ�!\n", player1);
			game_end(matrix) == 0;
			break;
		} else if (game_end(matrix) == 2) {
			system("cls");
			PlaySound("goodresult-82807.wav", 0, SND_FILENAME | SND_ASYNC);
			gotoxy(11, 9);
			textcolor(12);
			printf("%s( �� )��(��) �̰���ϴ�!\n", player2);
			game_end(matrix) == 0;
			break;
		}
	} while (1);
}
void game_control1(void) {
	PlaySound("8-bit-music-on-245249.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ���
	int x = 1, y = 1, other = 0;
	int matrix[2][20][20] = {0}; // �浹�� �鵹�� ���� 2���� �迭�� ����
	char key;
	const char *stone[2] = {"��", "��"};
	int warningDisplayed = 0; // ��� �޽��� ��� ���θ� �����ϴ� ����

	system("cls");

	do {
		gotoxy(1, 1);
		draw_check(18, 18);
		display_turn(other);
		gotoxy(x, y);
		printf("%s", stone[other]);
		display_stone(matrix);


		key = getch();
		if (key == 27) // ESCŰ�� ������ �� ���� ����
			exit(0);
		else if (key == 32) { // �����̽��ٸ� ������ �� ���� ���� ����
			// ���� ��ġ�� �̹� ���� �ִ��� Ȯ��
			if (matrix[0][(x + 1) / 2][y] == 1 || matrix[1][(x + 1) / 2][y] == 1) {
				gotoxy(0, 25); // �޽����� �ٵ��� �ϴܿ� ���
				printf("�̹� �ڸ��� ������ �ֽ��ϴ�. �ٽ� �����ּ���.");
				warningDisplayed = 1; // ��� �޽����� ǥ�õ��� ���
			} else {
				// �ڸ��� ��������� ���� ����
				matrix[other][(x + 1) / 2][y] = 1;
				other = 1 - other;  // �÷��̾� ��ü

				// ���� ��� �޽����� ������ ǥ�õǾ��ٸ� ����
				if (warningDisplayed) {
					gotoxy(0, 25);
					printf("                                             "); // ��� �޽��� ����
					warningDisplayed = 0; // ��� �޽��� ���� �� ���¸� �ʱ�ȭ
				}
			}
		} else if (key >= 72) {
			move_arrow_key(key, &x, &y, 37, 19);
		}

		// ������ �������� Ȯ��
		if (game_end(matrix) == 1) {
			
			system("cls");
			victoryCountP1++;
			gotoxy(11, 9);
			textcolor(12);
			if(victoryCountP1 == 3){
				PlaySound("goodresult-82807.wav", 0, SND_FILENAME | SND_ASYNC); 
				printf("%s( �� )��(��) �����¸��߽��ϴ�!\n", player1);
				printf("\n"); 
				printf("%s( �� )�� ���� : %d\n", player1,victoryCountP1);
				printf("%s( �� )�� ���� : %d\n", player2,victoryCountP2);
				
				break;
			}else{
			printf("%s( �� )��(��) �̰���ϴ�!\n", player1);
			printf("\n"); 
			printf("%s( �� )�� ���� : %d\n", player1,victoryCountP1);
			printf("%s( �� )�� ���� : %d\n", player2,victoryCountP2);
			game_end(matrix) == 0;
			break;
		}
		} else if (game_end(matrix) == 2) {
			
			system("cls");
			victoryCountP2++;
			gotoxy(11, 9);
			textcolor(12);
			if(victoryCountP2 == 3){
				PlaySound("goodresult-82807.wav", 0, SND_FILENAME | SND_ASYNC); 
				printf("%s( �� )��(��) �����¸��߽��ϴ�!\n", player2);
				printf("\n"); 
				printf("%s( �� )�� ���� : %d\n", player2,victoryCountP2);
				printf("%s( �� )�� ���� : %d\n", player1,victoryCountP1);
				break;
			}else{
			printf("%s( �� )��(��) �̰���ϴ�!\n", player2);
			printf("\n"); 
			printf("%s( �� )�� ���� : %d\n", player2,victoryCountP2);
			printf("%s( �� )�� ���� : %d\n", player1,victoryCountP1);
			game_end(matrix) == 0;
			break;
			}
			
		}
	} while (1);
}
int retryDraw() {
	int x= 16;
	int y=20;

	textcolor(11);
	gotoxy(x-2,y);
	printf(">�����");
	gotoxy(x-1,y+1);
	printf("Ÿ��Ʋ ȭ������");
	gotoxy(x,y+2);
	printf(" ���� ");

	while(1) {
		int n = keyControl();
		switch(n) {
			case UP: {
				if(y>20) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2,--y);
					printf(">");

				}
				break;
			}
			case DOWN: {
				if(y<22) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2,++y);
					printf(">");

				}
				break;
			}
			case SUBMIT: {
				return y -20;
			}
		}
	}
}
int retryDraw1() {
	int x= 16;
	int y=20;

	textcolor(11);
	gotoxy(x-2,y);
	printf(">������");
	gotoxy(x-1,y+1);
	printf("Ÿ��Ʋ ȭ������");
	gotoxy(x,y+2);
	printf(" ���� ");

	while(1) {
		int n = keyControl();
		switch(n) {
			case UP: {
				if(y>20) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2,--y);
					printf(">");

				}
				break;
			}
			case DOWN: {
				if(y<22) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2,++y);
					printf(">");

				}
				break;
			}
			case SUBMIT: {
				return y -20;
			}
		}
	}
}

int retryDraw2() {
	int x= 16;
	int y=20;

	textcolor(11);
	gotoxy(x-2,y);
	printf(">Ÿ��Ʋ ȭ������");
	gotoxy(x,y+1);
	printf(" ���� ");

	while(1) {
		int n = keyControl();
		switch(n) {
			case UP: {
				if(y>20) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2,--y);
					printf(">");

				}
				break;
			}
			case DOWN: {
				if(y<22) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2,++y);
					printf(">");

				}
				break;
			}
			case SUBMIT: {
				return y -20;
			}
		}
	}
}



int playCount() {
	int x = 15;
	int y = 10;

	textcolor(11);
	gotoxy(x -2, y);
	printf("> ����");
	gotoxy(x, y+1);
	printf("�＼��");
	gotoxy(x,y+2);
	printf("Ÿ��Ʋ��");

	while(1) {
		int n = keyControl();
		switch(n) {
			case UP: {
				if(y>10) {
					gotoxy(x-2,y);
					printf(" ");
					gotoxy(x-2, --y);
					printf(">");
				}
				break;
			}
			case DOWN: {
				if(y<12) {
					gotoxy(x-2, y);
					printf(" ");
					gotoxy(x-2, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y-10;
			}
		}
	}

}
