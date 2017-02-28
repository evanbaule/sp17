SOURCE= arrayList.c arrayList.h
ITEM = hw05

test : tryList
	./tryList <test1.txt
	
valgrind : tryList
	valgrind --leak-check=full tryList <test1.txt
	
tryList : tryList.c arrayList.c arrayList.h
	gcc -Wall -g -o tryList tryList.c arrayList.c
	
clean : 
	-rm tryList $(ITEM)_ebaule1.tar.gz
	
submit: $(SOURCE)
	mkdir $(ITEM)_ebaule1
	cp $(SOURCE) $(ITEM)_ebaule1
	tar -cvzf $(ITEM)_ebaule1.tar.gz $(ITEM)_ebaule1
	rm -r $(ITEM)_ebaule1
	echo Turn in $(ITEM)_ebaule1.tar.gz on myCourses under content, Homework Submissions		
