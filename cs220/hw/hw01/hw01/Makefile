test : hw01
	./hw01 input1
	cat input1_results.txt
	
debug : hw01
	gdb hw01

hw01 : hw01.c
	gcc -Wall -g -o hw01 hw01.c	
	
clean :
	-rm hw01 *_results.txt
	
submit: hw01.c
	mkdir hw01_ebaule1
	cp hw01.c hw01_ebaule1
	tar -cvzf hw01_ebaule1.tar.gz hw01_ebaule1
	rm -r hw01_ebaule1
	echo Turn in hw01_ebaule1.tar.gz on myCourses under content, Homework Submissions
