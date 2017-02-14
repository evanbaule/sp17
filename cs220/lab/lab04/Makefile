SOURCE = pointers.c
ITEM = lab04
ME = ebaule1

test : pointers
	./pointers

pointers : pointers.c
	gcc -g -Wall -o pointers pointers.c

clean :
	-rm pointers $(ITEM)_$(ME).tar.gz

submit: $(SOURCE)
	mkdir $(ITEM)_$(ME)
	cp -p $(SOURCE) $(ITEM)_$(ME)
	tar -cvzf $(ITEM)_$(ME).tar.gz $(ITEM)_$(ME)
	rm -r $(ITEM)_$(ME)
	echo Turn in $(ITEM)_$(ME).tar.gz on myCourses
