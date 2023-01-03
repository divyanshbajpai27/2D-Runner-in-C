#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>

void delay(int);
void welscr();

int main(){
	int locy=0, locx=0, n=10, strx=2, stry=3, scr=00;
	char key='n',s[100];
	float time=50;
	printf("\n\n\n\n              SNAKYY            \n\n\n\n\n  press any key to continue...");
	while(!kbhit()){}
	maingame:
	locy=5, locx=5, n=11, strx=2, stry=3, scr=00;
	key='d',s[100];
	time=50;
	while(1){
		//Printing ground///////////////////////////////////////
		if(key=='a' || key=='w' || key=='s' || key=='d'){
			system("cls");
			for(int i=0; i<=n; i++){
				for(int j=0; j<=n; j++){
					if(i==locy && j==locx){
						printf("X ");
					}
					else if(i==strx && j==stry){
						printf("* ");
					}
					else if(j==n && i!=0 || j==0 && i!=0){
						printf("|");
					}
					else if(i==n && j!=n || i==0 && j!=n){
						printf("__");
					}
					else{
						printf("  ");
					}
				}
			printf("\n");
			}
		}
		////////////////////////////////////////////////////////
		
		
		//Food Printing//////Score Printing///////
		if(locy==strx && locx==stry){
			scr+=1;
			strx=(rand() % 10)+1;
			stry=(rand() % 10)+1;
		}
		if(key=='a' || key=='w' || key=='s' || key=='d')
			printf("Score: %d\n", scr);
		delay(time);
		if(time!=5){
			time=time-0.1;
		}
		//////////////////////////////////////////
		
		//directing acc. to keys//////////////////
		if(kbhit()){
			key=getch();
		}
		if(key=='w'){
			if(locy==1){
				break;
			}
			else{
				locy--;
			}
		}
		else if(key=='s'){
			if(locy==n-1){
				break;
			}
			else{
				locy++;
			}
		}
		else if(key=='a'){
			if(locx==1){
				break;
			}
			else{
				locx--;
			}
		}
		else if(key=='d'){
			if(locx==n-1){
				break;
			}
			else{
				locx++;
			}
		}  
		else if(key=='.'){
			break;
		}
		////////////////////////////////////////
	}
	snprintf(s,100,"OUT!!!\nScore = %d",scr);
	if(MessageBox(0,s,"SNAKYY",5)==4){
		goto maingame;
	}
}

//FUNCTIONS
void delay(int n){
    int ms = 10 * n;
    clock_t t = clock();
    while (clock() < t + ms);
}
