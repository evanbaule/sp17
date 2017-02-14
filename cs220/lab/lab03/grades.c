#include <stdio.h>
#include <string.h>

#define MAXSTUDENTS 20
#define NAMELEN 12
#define NUMGRADES 9

char name[NAMELEN];
int getName();
int getGrade();
void printHeader();
void printSep();

/* Your main function goes here */
int main(){
	/* Initializes the Arrays */
	char students[MAXSTUDENTS][NAMELEN];
	int grades[MAXSTUDENTS][NUMGRADES];
	int activeRows = 0;

	/* Populates Arrays */
	for(int i = 0; i < MAXSTUDENTS; i++){
		if(getName() == 1) {
			for(int j = 0; j < NAMELEN; j++){
				students[i][j] = name[j];
			}
			for(int k = 0; k < NUMGRADES; k++){
				grades[i][k] = getGrade();
			}
			activeRows++;
		}
	}

	/* Calculates Averages and prints out the matrix */
	printHeader();
	float maxAvg = 0;
	float minAvg = 0;
	int minSt;
	int maxSt;
	for(int i = 0; i < activeRows; i++){ 
		int gradeSum = 0;
		float avg = 0.0;
		printf("%*s |",NAMELEN,students[i]);
		for(int j = 0; j < NUMGRADES; j++){
			gradeSum += grades[i][j];
			printf(" %3d |",grades[i][j]);
		}
		avg = (float)gradeSum/NUMGRADES;
		printf(" %6.2f |\n",avg);
		if(minAvg == 0){
			minAvg = avg;
			minSt = i;
		}
		if(avg > maxAvg) {
			maxAvg = avg;
			maxSt = i;
		}
		if(avg < minAvg){
			minAvg = avg;
			minSt = i;
		}
	}

	printSep();

	/* Prints out highest and lowest averages */
	printf("Minimum avg=%6.2f earned by %s\n",minAvg,students[minSt]);
	printf("Maximum avg=%6.2f earned by %s\n",maxAvg,students[maxSt]);

	return 0;
}

int getName() {
	/* --------------------------------------------------------------------------------------------------
		Reads the next name from stdin, and saves it in the "name" global array
		Returns a 1 if name has been updated, or 0 if there was a problem.
	-----------------------------------------------------------------------------------------------------*/
	if (1==scanf("%s ",name)) return 1;
	return 0;
}

int getGrade() {
	/* --------------------------------------------------------------------------------------------------
		Reads the next grade from stdin,
		Returns the grade if succesful, or -1 if there was a problem.
	-----------------------------------------------------------------------------------------------------*/
	int grade;
	if (1==scanf("%d ",&grade)) return grade;
	return -1;
}

void printHeader() {
	printf("%*s | %3s | %3s | %3s | %3s | %3s | %3s | %3s | %3s | %3s | %6s |\n",
		NAMELEN,"Name","HW1","HW2","HW3","LB1","LB2","LB3","TS1","TS2","TS3","Avg");
	printSep();
}

void printSep() {
	/* Print a separator row */
	int i;
	for(i=0;i<NAMELEN; i++) putchar('-');
	printf("-+-----+-----+-----+-----+-----+-----+-----+-----+-----+--------+\n");
}