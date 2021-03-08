//	  __             _              
//	 / _\_ __   __ _| | _____       
//	 \ \| '_ \ / _\`| |/ / _ \      
//	 _\ \ | | | (_| |   <  __/      
//	 \__/_| |_|\__,_|_|\_\___|      
//	       ___                      
//	      / _ \__ _ _ __ ___   ___  
//	     / /_\/ _\`| '_ \`_ \ / _ \ 
//	    / /_\\ (_| | | | | | |  __/ 
//	   \____/\__,_|_| |_| |_|\___| 
//
//SNAKE GAME USING C WITHOUT GRAPHICS LIBRARY
//====================================================================================================
//This a snake game developed using C language and no graphics library. This code is written in C using Dev C++ IDE.
//***Using Gcc compiler only. Turbo C will not work. This a snake game developed using C language and no graphics library. Tested in Windows 8, 8.1, 10.
//
//Last Update 28-12-2020
//
//::::|| [@AUTHOR - SOUHARDHYA PAUL [XEVOZEN]]
//::::|| [@GITHUB- "https://github.com/xevozen"]
//::::|| [@LINKEDIN- "https://www.linkedin.com/in/xevozen/"]
//====================================================================================================


#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <time.h> 
extern int cnv_row=11, cnv_col=32, snk_max_len=100, plr_scr=0;
int flag=0, size=1, key=3, food_x, food_y, head=219, body_icon=176, food=42, num;
void display(char game[cnv_row][cnv_col]);
void fod_pos(char game[cnv_row][cnv_col]);
int key_pressed(int);
void delay(int);
void check(int *, int *, char[cnv_row][cnv_col]);
void direction(int, int *, int *, char[cnv_row][cnv_col], int [snk_max_len][2]);
void body_update(int *, int *, int [snk_max_len][2], char[cnv_row][cnv_col]);
int main()
{
	int x, y, row=7, column=7;
	char canvas[cnv_row][cnv_col];
	int body[snk_max_len][2];
	for(x=0;x<cnv_row;x++)
	{
		for(y=0;y<cnv_col;y++)
		{
			canvas[x][y]=' ';
		}
	}
	fod_pos(canvas);
	printf("%c", 201);
	for(num=0;num<32;num++)
	{
		printf("%c",205);
	}
	printf("%c\n", 187);
	printf("%c  __             _              %c\n",186,186);
	printf("%c \/ _\\_ __   __ _| | _____       %c\n",186,186);
	printf("%c \\ \\| '_ \\ / _\\`| |/ / _ \\      %c\n",186,186);
	printf("%c _\\ \\ | | | (_| |   <  __/      %c\n",186,186);
	printf("%c \\__/_| |_|\\__,_|_|\\_\\___|      %c\n",186,186);
	printf("%c       ___                      %c\n",186,186);
	printf("%c      / _ \\__ _ _ __ ___   ___  %c\n",186,186);
	printf("%c     / /_\\/ _\\`| '_ \\`_ \\ / _ \\ %c\n",186,186);
	printf("%c    / /_\\\\ (_| | | | | | |  __/ %c\n",186,186);
	printf("%c    \\____/\\__,_|_| |_| |_|\\___| %c\n",186,186);
	printf("%c                                %c\n",186,186);
	printf("%c     PRESS ANY KEY TO START     %c\n",186,186);
	printf("%c",200);
	for(num=0;num<32;num++)
	{
		printf("%c",205);
	}
	printf("%c\n",188);
	getch();
	system("cls");
	printf("%c", 201);
	for(num=0;num<33;num++)
	{
		printf("%c",205);
	}
	printf("%c\n", 187);
	printf("%c                                 %c\n",186,186);
	printf("%c  RULES:                         %c\n",186,186);
	printf("%c  *  Don't run the snake into    %c\n",186, 186);
	printf("%c     the wall, or his own tail:  %c\n", 186, 186);
	printf("%c     you die.                    %c\n", 186, 186);
	printf("%c  *  Use keypbaord keys W.A.S.D  %c\n", 186, 186);
	printf("%c     up, left, down, and right.  %c\n",186,186);
	printf("%c  *  Eat the \'*\' to gain points. %c\n",186,186);
	printf("%c  *  Higher (and faster) play    %c\n", 186, 186);
	printf("%c     award more points.          %c\n",186,186);
	printf("%c  NOTE:                          %c\n",186,186);
	printf("%c  This game consumes more memory %c\n", 186, 186);
	printf("%c  with more game play.Your game  %c\n", 186, 186);
	printf("%c  may become chooppy after       %c\n", 186, 186);
	printf("%c  certain score or may behave    %c\n", 186, 186);
	printf("%c  abnormally  due to memory      %c\n", 186, 186);
	printf("%c  overflow.                      %c\n", 186, 186);
	printf("%c     PRESS ANY KEY TO START      %c\n",186,186);
	printf("%c",200);
	for(num=0;num<33;num++)
	{
		printf("%c",205);
	}
	printf("%c\n",188);
	getch();
	while(1)
	{
	   // flag=0;
		
		key=key_pressed(key);
		direction(key, &row, &column, canvas, body);
		check(&row, &column, canvas);
		if(flag==2)
		{
			for(flag=1;flag<=3;flag++)
			{
				system("cls");
				delay(300);	
				display(canvas);
				delay(200);
			}
			break;
		}
		display(canvas);
		

	}
	system("cls");
	printf("%c", 201);
	for(num=0;num<32;num++)
	{
		printf("%c",205);
	}
	printf("%c\n", 187);
	printf("%c  __             _              %c\n",186,186);
	printf("%c \/ _\\_ __   __ _| | _____       %c\n",186,186);
	printf("%c \\ \\| '_ \\ / _\\`| |/ / _ \\      %c\n",186,186);
	printf("%c _\\ \\ | | | (_| |   <  __/      %c\n",186,186);
	printf("%c \\__/_| |_|\\__,_|_|\\_\\___|      %c\n",186,186);
	printf("%c       ___                      %c\n",186,186);
	printf("%c      / _ \\__ _ _ __ ___   ___  %c\n",186,186);
	printf("%c     / /_\\/ _\\`| '_ \\`_ \\ / _ \\ %c\n",186,186);
	printf("%c    / /_\\\\ (_| | | | | | |  __/ %c\n",186,186);
	printf("%c    \\____/\\__,_|_| |_| |_|\\___| %c\n",186,186);
	printf("%c                                %c\n",186,186);
	printf("%c     THE END. YOUR SCORE:%2d     %c\n",186, plr_scr,186);
	printf("%c",200);
	for(num=0;num<32;num++)
	{
		printf("%c",205);
	}
	printf("%c\n",188);
	//printf("the end");
	return 0;
}
void fod_pos(char game[cnv_row][cnv_col])
{
	srand(time(0));
	food_x=(rand()%(cnv_col-1 - 1 + 1)) + 1;
	srand(time(0));
	food_y=(rand()%(cnv_row-1 - 1 + 1)) + 1;
	while(game[food_y][food_x]!=' ')
	{
		srand(time(0));
		food_x=(rand()%(cnv_col-1 - 1 + 1)) + 1;
		srand(time(0));
		food_y=(rand()%(cnv_row-1 - 1 + 1)) + 1;
	}
	game[food_y][food_x]=food;
}
void display(char game[cnv_row][cnv_col])
{
	int i,j;
	system("cls");
	for(num=0;num<cnv_col-7;num++)
	{
		printf(" ");
	}
	printf("Score: %d\n", plr_scr);
	printf("%c", 201);
	for(num=0;num<cnv_col;num++)
	{
		printf("%c",205);
	}
	printf("%c\n", 187);
	//printf("=======================\n");
	for(i=0;i<cnv_row;i++)
	{
		printf("%c",186);
		for(j=0;j<cnv_col;j++)
		{
			printf("%c",game[i][j]);
		}
		printf("%c\n",186);
	}
	printf("%c",200);
	for(num=0;num<cnv_col;num++)
	{
		printf("%c",205);
	}
	printf("%c\n", 188);
	//printf("=======================\n");
}
int key_pressed(int key)
{
	if(kbhit())
	{
		char ch;
		ch = getch();
		if(ch==119)
		{
			if(key==0||key==2)
			{}
			else
			{
				return 0;	//up
			}
		}
		if(ch==97)
		{
			if(key==1||key==3)
			{}
			else
			{
				return 1;	//left
			}
		}
		if(ch==115)
		{
			if(key==0||key==2)
			{}
			else
			{
				return 2;	//down
			}
		}
		if(ch==100)
		{
			if(key==1||key==3)
			{}
			else
			{
				return 3;	//right
			}
		}
		if(ch==113)
		{
			flag=1;
		}
	}
	return key;
}
void direction(int key, int *row, int *column, char canvas[cnv_row][cnv_col], int body[snk_max_len][2])
{
	int row2=*row, column2=*column;
	int i;
	if(key==0)						//up function
	{
		if(*row==0)
		{
			flag=2;
		}
		else
		{
			if((canvas[*row-1][*column]!=' ')&&(canvas[*row-1][*column]!=food))
			{
				flag=2;
			}
			body_update(&row2, &column2, body, canvas);
			*row=*row-1;
			
			canvas[*row][*column]=head;		//223
		}
	}
	if(key==2)						//down function
	{
		if(*row==cnv_row-1)
		{
			flag=2;
		}
		else
		{
			if((canvas[*row+1][*column]!=' ')&&(canvas[*row+1][*column]!=food))
			{
				flag=2;
			}
			body_update(&row2, &column2, body, canvas);
			*row=*row+1;
			canvas[*row][*column]=head;		//223
		}
	}
	if(key==1)						//left function
	{
		if(*column==0)
		{
			flag=2;
		}
		else
		{
			if((canvas[*row][*column-1]!=' ')&&(canvas[*row][*column-1]!=food))
			{
				flag=2;
			}
			body_update(&row2, &column2, body, canvas);
			*column=*column-1;
			canvas[*row][*column]=head;		//223
		}
	}
	if(key==3)						//right function
	{
		if(*column==cnv_col-1)
		{
			flag=2;
		}
		else
		{
			if((canvas[*row][*column+1]!=' ')&&(canvas[*row][*column+1]!=food))
			{
				flag=2;
			}
			body_update(&row2, &column2, body, canvas);
			*column=*column+1;
			canvas[*row][*column]=head;			//223
		}
	}
	delay(250-(2.71828*plr_scr));
}
void body_update(int *row, int *column, int body[snk_max_len][2], char canvas[cnv_row][cnv_col])
{
	int i;

	if(flag==1)
    {
        if(size==1)
        {
        }
        else
        {
            canvas[(body[size-2][0])][(body[size-2][1])]=' ';
        }
        for(i=size-2;i>0;i--)
        {
		    body[i][0]=body[i-1][0];
            body[i][1]=body[i-1][1];
        }
        body[0][0]=*row;
        body[0][1]=*column;
        size++;
        plr_scr++;
        for(i=size-2;i>0;i--)
        {
            body[i][0]=body[i-1][0];
            body[i][1]=body[i-1][1];
        }
        body[0][0]=*row;
        body[0][1]=*column;
        for(i=0;i<=size-2;i++)
        {
            canvas[(body[i][0])][(body[i][1])]=body_icon;
        }
    }
    else if(flag==0)
    {
        if(size!=1)
        {
            canvas[(body[size-2][0])][(body[size-2][1])]=' ';
            for(i=size-2;i>0;i--)
            {
                body[i][0]=body[i-1][0];
                body[i][1]=body[i-1][1];
            }
            body[i][0]=*row;
            body[i][1]=*column;
            for(i=0;i<=size-2;i++)
            {
                canvas[(body[i][0])][(body[i][1])]=body_icon;
            }
        }
        else
        {
            canvas[*row][*column]=' ';
        }
    }
}
void check(int *row, int *column, char game[cnv_row][cnv_col])
{
	if(flag==2)
	{}
	else if((food_y==*row)&&(food_x==*column))
	{
		flag=1;
		fod_pos(game);
	}
	else
	{
		flag=0;
	}
}
void delay(int milli_seconds) 
{  
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds); 
}
