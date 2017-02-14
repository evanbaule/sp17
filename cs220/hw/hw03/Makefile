test : matMult
	./matMult I 5 8 R 10
	./matMult S 4 6 R 6 <mat4x6_leftcol.txt
	
matMult : matMult.c
	gcc -g -Wall -o matMult matMult.c
	
clean :
	-rm matMult
	
submit: matMult.c
	mkdir hw03_ebaule1
	cp matMult.c hw03_ebaule1
	tar -cvzf hw03_ebaule1.tar.gz hw03_ebaule1
	rm -r hw03_ebaule1
	echo Turn in hw03_ebaule1.tar.gz on myCourses under content, Homework Submissions	