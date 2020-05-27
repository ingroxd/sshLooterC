CFLAGS += -Werror -Wall

looter.so: src/looter.c
	gcc $(CFLAGS) -fPIC -shared -Xlinker -x -o $@ $<

