/*
Evan M. Baule
CS220
Binghamton University

*/

#include "arrayList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#define INITSIZE 16

bool arrayListAddHelper(arrayList list);
bool arrayListEnlarge(arrayList list);

arrayList arrayListCreate() {
	arrayList list = (arrayList)malloc(sizeof(struct arrayListStruct));
	if (list==NULL) return list;
	list->data=(int *)malloc(sizeof(int)*INITSIZE);
	list->numUsed=0;
	list->numAlloc=INITSIZE;
	return list;
}

bool arrayListEnlarge(arrayList list) {
	list->data=(int *)realloc(list->data,sizeof(int) * (2*list->numAlloc));
	if (list->data==NULL) return false;
	list->numAlloc *=2;
	return true;
}

/* Put definitions of the other arrayList methods in arrayList.h here */


/*
Notes
1. if we do not assert the list for ever function we end up trying 
to do the functions on lists that are null which is bad
2. Not being able to set list->numUsed as a global is annoying, 
not sure how that would be done though but it seems like it would have made things cleaner
*/

/*
.add(i);
Appends the specified element to the end of this list.
@return true if succeeds
*/
bool arrayListAdd(arrayList list, int item){
	assert(list);
	if(arrayListAddHelper(list)){
		return false;
	}else {
		list->data[list->numUsed++] = item; //adds the new item on to the end of the list
		return true;
	}
}

//Returns true if the list is full
bool arrayListAddHelper(arrayList list){
	if(list->numAlloc == list->numUsed){
		return true;
	}
	return false;
} //After only using this once I think it may have been useless to make a helper, but I will leave it

/*
.clear();
Removes all of the elements from this list. The list will be empty after this call returns.
void
*/
void arrayListClear(arrayList list){
	assert(list);
	int holder = list->numUsed;
	int i;
	for(i = 0; i < holder; i++){
		list->data[i] = 0;
	}
	list->numUsed = 0;
}

/*
.contains(i);
Returns true if this list contains the specified element.
Returns t/f
*/
bool arrayListContains(arrayList list, int item){
	assert(list);
	int holder = list->numUsed; //I do this multiple times to save typing I guess
	int i; //ITERATOR
	for(i = 0; i < holder; i++){
		if(list->data[i] == item){
			return true;
		}
	}
	return false;
}

/*
.get(i);
Returns the element at the specified position in this list.
*/
int arrayListGet(arrayList list,int index){
	assert(list);
	return list->data[index];
}

/*
.indexOf(i)
Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element.
More formally, returns the lowest index i such that (o==null ? get(i)==null : o.equals(get(i))), or -1 if there is no such index.
*/
int arrayListIndexOf(arrayList list, int item){
	assert(list);
	int holder = list->numUsed;
	int i; //ITERATOR
	for(i = 0; i < holder; i++){
		if(list->data[i] == item){
			return i;
		}
	}
	return -1;
}

/*
isEmpty();
Returns true if this list contains no elements.
*/
bool arrayListIsEmpty(arrayList list){
	assert(list);
	int holder = list->numUsed;
	if(holder == 0) return true;
	return false;
}

/*
.set(x, y);
Replaces the element at the specified position in this list with the specified element.
*/

int arrayListSet(arrayList list, int index, int item){
	assert(list);
	int holder = list->numUsed;
	int temp = 0; //Temporary to hold the return value, this is what we return
	if(index > holder){
		//store temp
		int this = list->data[index];
		temp = this; //saves return variable to what is currently at [index]
		this = item; //does the work to set the new value
	}
	return temp;

}

/*
.size();
Returns the number of elements in this list.
*/
int arrayListSize(arrayList list){
	if(list){
		return list->numUsed;
	}
	return 0;
}

/*
.toString();
Returns a string representation of this collection. 
The string representation consists of a list of the collection's elements 
in the order they are returned by its iterator, enclosed in square brackets ("[]"). 
Adjacent elements are separated by the characters ", " (comma and space).
*/
char * arrayListToString(arrayList list,char *buffer){
	//not sure if safe to use strncat here so I will stick to using strcat
	assert(list);

	buffer[0] = 0; //init buffer

	strcat(buffer, "[ "); //added to match sample output

	//Populate the buffer
	int i; //ITERATOR
	for (i = 0; i < list->numUsed; i++) {
		char str[64]; //64 bit os? not sure I fully understand what this value is supposed to be, I assume it is max length? and we are using integers

		sprintf(str, "%d", list->data[i]);
		strcat(buffer, str);
		
		if (i != arrayListSize(list)-1) {
			strcat(buffer, ", ");
		}else {
			strcat(buffer, " ]"); //Ends the output string
		}
	}

	//shout look like [w, x, y, z]
	return buffer;
}

void arrayListFree(arrayList list) {
	free(list->data);
	free(list);
}