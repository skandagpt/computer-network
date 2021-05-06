#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <random>

#define ROW 25
#define COL 70
#define N 3

void igrid(char [][COL]);
void printgrid(char[][COL]);
void move (char [][COL], int, int*, int*, int*, float);

main()
{
	float p;
	char grid [ROW][COL];
	int count, ff1 = 0, ff2 =0, ff3=0;

	rand();
	printf("			The Slotted ALOHA Simulation\n\n");
	printf("		press any key to continue");
	getch();
	printf("\n\nEnter the probability from 0 to 1 for the packet transmission: ");
	scanf("%f",&p);
	printf("\n\nPress any key to simulate each time slot\n\n");
	printf("		press any key to continue");
	getch();
	igrid(grid);
	printgrid(grid);
	for (count=1; count<10; count++)
		move (grid, count, &ff1,&ff2, &ff3,p);

}

void igrid (char grid[][COL])
{
	int i, j ;

	for (i = 0; i <ROW; i++)
		for (j= 0; j<COL;j++)
			grid[i][j]= ' ';

	for (i=3; i<ROW-4; i++)
		grid[i][7] = '|';
	for (j= 7; j<COL; j++)
		grid[20][j] = '_';
	for (j = 1; j<10; j ++)
		grid [20][j*7] = '|';
	for (i = 1; i <4; i++){
		grid [i *5][1] = 'N';
		grid [i *5][2] = 'o';
		grid [i *5][3] = 'd';
		grid [i *5][4] = 'e';
	}
		grid [5][6]  ='1';
		grid [10][6] ='2';
		grid [15][6] ='3';

		for (i = 0; i<3; i++)
			for (j = 1; j<6; j++){
				grid [(i*5)+6][j] = '*';
				grid [(i*5)+7][j] = '*';
				grid [(i*5)+8][j] = '*';
}           }

void printgrid(char grid[][COL])
{
	int i,j;
	for(i=0; i<ROW; i++)
	{	for( j=0; j<COL; j++)
			printf("%c", grid[i][j]);
		printf("\n");
	}
	getch();
}

void move (char grid[][COL], int count1, int *ff1,int *ff2, int*ff3, float p1)
{
	float prob;

	int j, f1 = 0, f2 = 0, f3 = 0,
		 n1 = 0, n2 =0 , n3= 0, newp=0;

	prob = p1 * 100;
	newp = ceil(prob);

	n1 = rand()%100;
	n2 = rand()%100;
	n3 = rand()%100;

	if (n1 < newp && *ff1 == 0)
		f1 = 1;
	else
		f1 = 0;

	if (n2 < newp && *ff2 == 0)
		f2 = 2;
	 else
		f2 = 0;

	if(n3 < newp && *ff3 == 0)
		f3 = 3;
	 else
		f3 = 0;

	if (f1==1)
			for (j = 1; j<6; j++){
				grid [6][j+1+(7* count1)] = '*';
				grid [7][j+1+(7* count1)] = '*';
				grid [8][j+1+(7* count1)] = '*';
			 }

	if (f2==2)
			for (j = 1; j<6; j++){
				grid [11][j+1+(7* count1)] = '*';
				grid [12][j+1+(7* count1)] = '*';
				grid [13][j+1+(7* count1)] = '*';
			  }
	if (f3==3)
			for (j = 1; j<6; j++){
				grid [16][j+1+(7* count1)] = '*';
				grid [17][j+1+(7* count1)] = '*';
				grid [18][j+1+(7* count1)] = '*';
				}

	if (f1==1 && f2==0 && f3==0){
		*ff1 = 1;
		grid [22][3 + (7*count1)] = 'S';
	}

	if (f1==0 && f2==2 && f3==0){
		*ff2 = 1;
		grid [22][3 + (7*count1)] = 'S';
	}

	if (f1==0 && f2==0 && f3==3){
		*ff3 = 1;
		grid [22][3 + (7*count1)] = 'S';
	}

	if (f1==0 && f2==0 && f3==0)
		grid [22][3 + (7*count1)] = 'E';
	if (f1==0 && f2==2 && f3==3)
		grid [22][3 + (7*count1)] = 'C';
	if (f1==1 && f2==0 && f3==3)
		grid [22][3 + (7*count1)] = 'C';
	if (f1==1 && f2==2 && f3==0)
		grid [22][3 + (7*count1)] = 'C';
	if (f1==1 && f2==2 && f3==3)
		grid [22][3 + (7*count1)] = 'C';
	printgrid(grid);
}

