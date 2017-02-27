SOURCE = btree.c
ITEM = lab05

test : btree
	./btree 10 21 18 52 17 18 22 34 22 12 14 16

btree : btree.c 
	gcc -Wall -g -o btree btree.c
	
clean :
	-rm btree $(ITEM)_ebaule1.tar.gz
	
submit: $(SOURCE)
	mkdir $(ITEM)_$ebaule1
	cp -p $(SOURCE) $(ITEM)_$ebaule1
	tar -cvzf $(ITEM)_ebaule1.tar.gz $(ITEM)_ebaule1
	rm -r $(ITEM)_ebaule1
	echo Turn in $(ITEM)_ebaule1.tar.gz on myCourses	