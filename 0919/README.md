# 0919 REPORT

---

### 1. 카드 생성 & 생성된 카드 출력

- 숫자(또는문자)와모양즉, 두가지데이터로표시되므로구조체로표현
- 멤버order는 카드의 우선순위
멤버number는 카드의 숫자(또는문자)
- 순위는스페이드(♠) 모양을1순위(order=0), 다이아몬드(◆)는 2순위(order=1),
하트(♥)는 3순위(order=2) 그리고 클로버(♣)는 4순위(order=3)로 가정
- 멤버order는 카드의 우선순위
멤버shape는 카드 모양(2 byte크기의 완성형 기호)
멤버number는 카드의 숫자(또는문자)
- 카드의모양(♠◆♥♣)은2차원배열에저장하여구분
반복문에의해카드의순위를멤버order에저장
멤버order의 값에 따라카드의모양을멤버shpae에저장하고,
멤버number에는 카드의번호를저장하되switch-case문으로
- 1일 경우는number에 'A'를,
11일 경우는'J',
12일 경우는'Q',
13일 경우는'K'를 저장
- number가 10보다 클 경우에는
문자형으로출력.
멤버number는 숫자일 경우최대2자리까지사용되지만, 문자
가저장된경우에는하나의문자이므로문자일경우는형식 지정자"%-2c"(2자리 왼쪽 맞춤)를, 숫자일 경우는 "%-2d "를사용

![image](https://github.com/user-attachments/assets/07d2b5f2-4a4c-46f3-bff7-805a58410c40)


```cpp
#include<stdio.h>
#include<string.h>
struct trump
{
	int order;
	char shape[3]; 
	int number;
};

void make_card(trump m_card[]);
void display_card(trump m_card[]);

int main(void)
{
	trump card[52];
	make_card(card);
	display_card(card);
	return 0;
}
void make_card(trump m_card[])
{
	int i, j;
	char shape[4][3]={"♠","◆","♥","♣"};
	for(i=0;i<4;i++)
	{
		for(j=i*13;j<i*13+13;j++)
		{
			m_card[j].order=i;
			strcpy(m_card[j].shape, shape[i]);
			m_card[j].number=j%13+1;
			switch(m_card[j].number)
			{ 
				case 1:
					m_card[j].number='A';
					break;
				case 11:
					m_card[j].number='J';
					break;
				case 12:
					m_card[j].number='Q';
					break;
				case 13:
					m_card[j].number='K';
					break;
			}
		}
	}
}

void display_card(trump m_card[])
{
	int i, count=0;
	for(i=0;i<52;i++)
	{
		printf("%s", m_card[i].shape); 
		if(10<m_card[i].number) 
			printf("%-2c  ", m_card[i].number);
		else
			printf("%-2d  ", m_card[i].number);
		count++;
		if(i%13+1==13)
		{
			printf("\n");
			count=0;
		}
	}
}
```

### 2. 카드 섞기

- 카드를섞는것은카드의위치를서로교환하는것(카드섞기방법1)
1 단계 : 정수 난수 rnd를 발생하여a[0]과 a[rnd]의 카드를 서로 바꾼다.
2 단계 : 정수 난수 rnd를 발생하여a[1]과 a[rnd]의 카드를 서로 바꾼다.
단계반복

![image 1](https://github.com/user-attachments/assets/f4937d93-bb03-445d-9503-2b56f117c80c)


```cpp
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<time.h>

struct trump
{
	int order;
	char shape[3]; 
	int number; 
};

void make_card(trump m_card[]);
void display_card(trump m_card[]);
void shuffle_card(trump m_card[]);

int main(void)
{
	trump card[52];
	make_card(card);
	shuffle_card(card);
	display_card(card);
	return 0;
}
void make_card(trump m_card[])
{
	int i, j;
	char shape[4][3]={"♠","◆","♥","♣"};
	for(i=0;i<4;i++)
	{
		for(j=i*13;j<i*13+13;j++)
		{
			m_card[j].order=i;
			strcpy(m_card[j].shape, shape[i]);
			m_card[j].number=j%13+1;
			switch(m_card[j].number)
			{ 
				case 1:
					m_card[j].number='A';
					break;
				case 11:
					m_card[j].number='J';
					break;
				case 12:
					m_card[j].number='Q';
					break;
				case 13:
					m_card[j].number='K';
					break;
			}
		}
	}
}

void display_card(trump m_card[])
{
	int i, count=0;
	for(i=0;i<52;i++)
	{
		printf("%s", m_card[i].shape);

		if(10<m_card[i].number) 
			printf("%-2c  ", m_card[i].number);
		else
			printf("%-2d  ", m_card[i].number);
		count++;
		if(i%13+1==13)
		{
			printf("\n");
			count=0;
		}
	}
}

void shuffle_card(trump m_card[])
{
	int i, rnd;
	trump temp;
	srand(time(NULL));
	for(i=0;i<52;i++)
	{
		rnd=rand()%52;
		temp=m_card[rnd];
		m_card[rnd]=m_card[i];
		m_card[i]=temp;
	 } 
}
```

### 3. 음계와 주파수 출력

![image 2](https://github.com/user-attachments/assets/418a6102-af21-45dc-80c9-d540ba890573)


```cpp
#include <stdio.h>
#include <math.h>

void print_frequency(int octave);

int main(void)
{
	char *scale[]={"도","도#","레","레#","미",
				"파","파#","솔","솔#","라","라#","시","도"};
	int i, octave, count=0;
	printf("음계와 주파수\n\n음계\t   ");
	for(i=0;i<12;i++)
		printf("%-5s", scale[i]);
	printf("\n");
	for(i=0;i<=70;i++)
		printf("-");
	printf("\n");
	for(octave=1;octave<7;octave++)
		print_frequency(octave);
	return 0; 
}

void print_frequency(int octave)
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp;
	int i;
	temp=do_scale*pow(2, octave-1);
	printf("%d옥타브: ",octave);
	
	for(i=0;i<12;i++)
	{
		printf("%4ld ", (unsigned long) (temp+0.5));
		temp*=ratio;
	}
	
	printf("\n");
}
```

### 4. 주파수를 이용한 음의 출력

- 실행하면 화면 상에는 아무것도 나타나지 않는 상태에서 "도레미파솔라시도"의 음계를 스피커로 출력하고, 이어서역으로"
도시라솔파미레도"를 출력
- DOS 환경의 Turbo C에는 주파수를 이용하여 컴퓨터 스피커로소리는sound 라는 함수가있었고, Visual C++의 경우에는 ANSI C 표준함수는 아니지만 Win API 함수로서 주파수의값과지속시간을이용하여소리를출력하는라이브러리함수Beep를이용. 함수Beep는헤
더파일<windows.h> 필요

```cpp
#include <stdio.h>
#include <math.h>
#include <windows.h>

int calc_frequency(int octave, int inx);

int main(void)
{
	int index[]={0, 2, 4, 5, 7, 9, 11, 12};
	int freq[8];
	int i;
	for(i=0;i<8;i++)
			freq[i]=calc_frequency(4, index[i]);
	for(i=0;i<=7;i++)
			Beep(freq[i],500);
	Sleep(1000); //A½°￡AC Ao¿￢½A°￡ 1AE
	for(i=7;i>=0;i--)
			Beep(freq[i],500);
	return 0; 
}

int calc_frequency(int octave, int inx)
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp;
	int i;
	temp=do_scale*pow(2, octave-1);
	for(i=0;i<inx;i++)
	{
		temp=(int)(temp+0.5);
		temp*=ratio;
	}
	return (int) temp;
}
```

### 5. 숫자키에 따라 해당 음을 출력

![image 3](https://github.com/user-attachments/assets/fbb1713d-3b84-43f5-a343-868c40c38e06)


```cpp
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

int calc_frequency(int octave, int inx);
void practice_piano(void);

int main(void)
{
	printf("1부터 8까지 숫자 키를 누르면\n");
	printf("각 음의 소리가 출력됩니다.\n\n");
	printf("1:도 2:레 3:미 4:파 5:솔 6:라 7:시 8:도\n");
	printf("프로그램 종료는 Esc키 \n");
	practice_piano();
	return 0;
}

void practice_piano(void)
{
	int index[]={0, 2, 4, 5, 7, 9, 11, 12};
	int freq[8], code, i;
	for(i=0;i<8;i++)
		freq[i]=calc_frequency(4, index[i]);
	do
	{
		code=getch();
		if ('1'<=code && code<='8')
		{
			code-=49;
			Beep(freq[code],300);
		}
	}while(code!=27);
}

int calc_frequency(int octave, int inx)
{
	double do_scale=32.7032;
	double ratio=pow(2., 1/12.), temp;
	int i;
	temp=do_scale*pow(2, octave-1);
	for(i=0;i<inx;i++)
	{
		temp=(int)(temp+0.5);
		temp*=ratio;
	}
	return (int) temp;
}
```
