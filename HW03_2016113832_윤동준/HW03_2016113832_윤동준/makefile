all: CountThou CountTen CountHun test 

CC= gcc
LOL = -lpthread

CountTen: CountTen.c
	$(CC) -o $@ CountTen.c $(LOL)

CountHun: CountHun.c
	$(CC) -o $@ CountHun.c $(LOL)

CountThou: CountThou.c
	$(CC) -o $@ CountThou.c $(LOL)

test: test.c
	$(CC) -o $@ test.c $(LOL)
