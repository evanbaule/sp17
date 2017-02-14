#include <stdio.h>

int boardFeet(int width, int height);
int main(int argc, char **argv){
  //check to make sure we have the right amount of arguments
  if(argc < 3){
    printf("Invoke as: %s <width> <height> \n", argv[0]);
    return 1; //means something is broken
  }

  //atoi converts ascii strings to integers
  int width = atoi(argv[1]); //returns 0 if this conversion fails
  int height = atoi(argv[2]);
  //can check down here for failure in conversion by checking for zeros

  int feet = boardFeet(width, height);
  printf("It takes %d feet of board to cover a wall that is %d inches x %d inches\n",
  feet, width, height);

  return 0;
}

int boardFeet(int width, int height){
  int board = (height+7)/8; //rounds the value up
  int feet = (board * width + 11)/12; //also rounds up
  return feet;
}
