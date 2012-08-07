SUBDIRS := driver/globalfifo test
.PHONY :all
all:
	@for dir in $(SUBDIRS) ;\
	do make -C $${dir} ;\
	done
.PHONY:clean
clean:
	@for dir in $(SUBDIRS);\
	do make clean -C $${dir};\
	done
.PHONY:execute
execute:
	./test/main
