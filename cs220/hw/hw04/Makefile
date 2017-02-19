ME = ebaule1

test : numLetters
	./numLetters 342
	./numLetters 115
	
numLetters : numLetters.c
	gcc -Wall -g -o numLetters numLetters.c
	
clean : 
	-rm numLetters hw04_$(ME).tar.gz
	
submit: numLetters.c
	mkdir hw04_$(ME)
	cp numLetters.c hw04_$(ME)
	tar -cvzf hw04_$(ME).tar.gz hw04_$(ME)
	rm -r hw04_$(ME)
	echo Turn in hw04_$(ME).tar.gz on myCourses under content, Homework Submissions		