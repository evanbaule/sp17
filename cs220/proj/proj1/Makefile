SRC_FILES = warehouse.c slots.c slots.h Makefile

test : warehouse
	./warehouse <order1.txt
	
debug : warehouse
	gdb warehouse
	
warehouse : warehouse.c slots.h slots.c
	gcc -Wall -g -o warehouse warehouse.c slots.c
	
submit : $(SRC_FILES)
	mkdir proj1_ebaule1
	cp $(SRC_FILES) proj1_ebaule1
	tar -cvzf proj1_ebaule1.tar.gz proj1_ebaule1
	rm -r proj1_ebaule1
	
clean : 
	-rm warehouse proj1_ebaule1.tar.gz