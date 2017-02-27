#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct tnode {
   struct tnode * left;
   struct tnode * right;
   int value;
};

struct tnode * makeNode(int value);
void freeTree(struct tnode * t);

void insertVal(struct tnode * t, int value);
void prLVR(struct tnode * t);
void prRVL(struct tnode * t);
void printTree(struct tnode * t, char * prefix);

int main(int argc, char **argv) {
   int i;

   if (argc<2) {
		printf("You must specify at least one argument to %s\n",argv[0]);
		return 1;
	}
	struct tnode * root=makeNode(atoi(argv[1]));
   for(i=2; i<argc; i++) {
      int val=atoi(argv[i]);
      insertVal(root,val);
   }
   printf("In LVR order: ");
   prLVR(root);
   printf("\nIn RVL order: ");
   prRVL(root);
   printf("\nGraphic Representation...\n");
   printTree(root,"");
   freeTree(root);
   return 0;
}

struct tnode * makeNode(int value) {
   struct tnode * t = malloc(sizeof(struct tnode));
   t->value=value;
   t->left=NULL;
   t->right=NULL;
   return t;
}

void freeTree(struct tnode * t) {
   assert(t);
   if (t->left) freeTree(t->left);
   if (t->right) freeTree(t->right);
   free(t);
}

//check if node is null
//if val is null its not allocated, have to make a new node to store value in order to not get a seg fault

void insertVal(struct tnode * t, int value) {
	assert(t);
	/* Write code to insert value into tree t here */
   if(value < t->value){
      if(t->left == NULL){
         t->left = value;
      }else{
         insertVal(t->left, value);
      }
   } else {
      if(t->right == NULL){
         t->right = value;
      }else{
         insertVal(t->right, value);
      }
   }
}

//if left is not null, go to the left
//if left is null, you print the t.value

//then go right

void prLVR(struct tnode * t) {
	assert(t);
   /* Write code to:
   	- prLVR the left sub-tree,
   	- print the value of the node,
   	- prLVR the right sub-tree
   */

   if()
}


void prRVL(struct tnode * t) {
	assert(t);
   /* Write code to:
   	- prRVL the right sub-tree,
   	- print the value of the node,
   	- prRVL the left sub-tree
   */
}

void printTree(struct tnode * t, char * prefix) {
	assert(t);
	/* Write code to print a tree graphically */
}
