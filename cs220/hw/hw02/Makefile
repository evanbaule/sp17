test : test_factorial test_primeFactor

test_factorial : factorial
	./factorial

test_primeFactor : primeFactor
	./primeFactor 35460

factorial : factorial.c
	gcc -Wall -g -o factorial factorial.c

primeFactor : primeFactor.c
	gcc -Wall -g -o primeFactor primeFactor.c

clean :
	-rm primeFactor factorial

submit: factorial.c primeFactor.c
	mkdir hw02_ebaule1
	cp factorial.c primeFactor.c hw02_ebaule1
	tar -cvzf hw02_ebaule1.tar.gz hw02_ebaule1
	rm -r hw02_ebaule1
	echo Turn in hw02_ebaule1.tar.gz on myCourses under content, Homework Submissions
