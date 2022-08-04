/*
 * Conwaymain.c
 *
 *  Created on: Sep 2, 2020
 *      Author: VIRESH GUPTA
 */
/*
 ============================================================================
 Name        : Conwaymain.c
 Author      : VIRESH GUPTA
 Version     :1
 Copyright   : @ VIRESH GUPTA
 Description : Conway Game of Life
 Date        : 1st september 2020
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

//assignPoint function sets live cell in the board and initialize it.
void assignPoint(bool* arr, int m, int n, int c)
	{

	*(arr+(m*c)+n)=1;
	}
// printBoard Function print the board for conway game of life
void printBoard(bool* arr, int m, int n)// it passes 3 arguments
{
	for(int i=0;i<m;i++){
		for (int j=0; j<n; j++)
			printf("%d",*((arr+(i*n))+j));
		printf("\n");}
}
// assign function make the board blank and make it 0 position
void assign(bool* arr, int m, int n)// it passes  arguments
{
	for(int i=0;i<m;i++){
		for (int j=0; j<n; j++)
			*((arr+(i*n))+j) = 0;
	}
}
// play is the function which implements CGOL Four rules and it check neighbours and implement them
void play(bool* arr, int m, int n)
{
	for(int i=0;i<m;i++){
				for (int j=0; j<n; j++){

	int a1 = i-1, a2 = j-1; // checking neighbour of up left
	int b1 = i-1, b2 = j; //  checking from up
	int c1 = i-1, c2 = j+1; // Checking up right
	int d1 = i, d2 = j-1; //  Checking left side
	int e1 = i, e2 = j+1; //Checking  right side
	int f1 = i+1, f2 = j-1;// Checking down left
	int g1= i+1, g2 = j; //Checking  down
	int h1 = i+1, h2 = j+1; // Checking down right
	int f = 0, c = 0;

				if(*((arr+(i*n))+j) == 1)
				{
					if (*((arr+(a1*n))+a2) == 1)
						f++;
					if (*((arr+(b1*n))+b2) == 1)
						f++;
					if (*((arr+(c1*n))+c2) == 1)
						f++;
					if (*((arr+(d1*n))+d2) == 1)
						f++;
					if (*((arr+(e1*n))+e2) == 1)
						f++;
					if (*((arr+(f1*n))+f2) == 1)
							f++;
					if (*((arr+(g1*n))+g2) == 1)
							f++;
					if (*((arr+(h1*n))+h2) == 1)
							f++;

					if(f < 2 || f > 3)
						*((arr+(m*n))+n) = 0;// implementation of CGOL Rule 1 and Rule 2
				}
				if(*((arr+(i*n))+j) == 0)
								{
									if (*((arr+(a1*n))+a2) == 1)
										c++;
									if (*((arr+(b1*n))+b2) == 1)
										c++;
									if (*((arr+(c1*n))+c2) == 1)
										c++;
									if (*((arr+(d1*n))+d2) == 1)
										c++;
									if (*((arr+(e1*n))+e2) == 1)
										c++;
									if (*((arr+(f1*n))+f2) == 1)
											c++;
									if (*((arr+(g1*n))+g2) == 1)
											c++;
									if (*((arr+(h1*n))+h2) == 1)
											c++;

									if( c==3)// It implements CGOL 4th rule
										*((arr+(i*n))+j) = 1;
								}
			}
	}


}
int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);
		setvbuf(stderr, NULL, _IONBF, 0);

	int r,c;
	printf("Enter The Board size: \n"); // entering the size of board
	printf("Enter the number of rows:");// entering thenumber of rows
		scanf("%d" , &r);
	printf("Enter the number of columns:");// entering Number of Column
		scanf("%d" , &c);


bool arr=(bool) malloc(r* c* sizeof(bool));//assign memory using Dynamic memory allocation

assign(arr,r,c);// calling assign Function


   int x,y;
    int f=1;
   while(f != 0){
    printf("Enter the coordinates of your point:");// input coordinates of your cells
    		scanf("%d" , &x);
    		scanf("%d", &y);
    if(x>=0 && x < r)
    		if(y>=0 && y<c)// check coordinate input for cells in CGOL
    			assignPoint(arr,x,y,c);// call assignPoint Function
    		else
    			printf("Out of bound");
    else
    	printf("Out of bound");

    printf("Do you wish to continue entering coordinates (1) or start the game(0): ");
    scanf("%d",&f);
   }
   printBoard(arr, r, c);

  printf("Showing the first generation:");


  int p=1;
do{
   play(arr, r, c);
   printBoard(arr, r, c);// calling printBoard function
   printf("Do you wish to see the next generation (1) or exit(0):");// ask for print next generation
   scanf("%d",&p);
} while (p != 0);
	return EXIT_SUCCESS;
}
