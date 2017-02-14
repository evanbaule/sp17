test : test_loop test_buggy

test_loop : loop
	./loop
	
test_buggy : buggy
	./buggy
	
debug_loop : loop 
	gdb loop
	
debug_buggy : buggy
	gdb buggy

loop : loop.c
	gcc -Wall -g -o loop loop.c	
	
buggy : buggy.c
	gcc -Wall -g -o buggy buggy.c
	
clean :
	-rm loop buggy
	
submit: loop.c
	mkdir lab02_ebaule1
	cp loop.c buggy.c lab02_ebaule1
	tar -cvzf lab02_ebaule1.tar.gz lab02_ebaule1
	rm -r lab02_ebaule1
	echo Turn in lab02_ebaule1.tar.gz on myCourses