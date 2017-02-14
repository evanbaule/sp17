test : grades sectionA.txt
	./grades <sectionA.txt
	
grades : grades.c
	gcc -g -Wall -o grades grades.c
	
clean :
	-rm grades
	
submit: grades.c
	mkdir lab03_ebaule1
	cp grades.c lab03_ebaule1
	tar -czf lab03_ebaule1.tar.gz lab03_ebaule1
	rm -r lab03_ebaule1
	echo Turn in lab03_ebaule1.tar.gz on myCourses	