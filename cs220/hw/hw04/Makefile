test : numLetters
	./numLetters 342
	./numLetters 115
	
numLetters : numLetters.c
	gcc -Wall -g -o numLetters numLetters.c
	
clean : 
	-rm numLetters hw04_ebaule1.tar.gz
	
submit: numLetters.c
	mkdir hw04_ebaule1
	cp numLetters.c hw04_ebaule1
	tar -cvzf hw04_ebaule1.tar.gz hw04_ebaule1
	rm -r hw04_ebaule1
	echo Turn in hw04_ebaule1.tar.gz on myCourses under content, Homework Submissions		