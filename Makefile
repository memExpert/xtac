CC = gcc
SRCMODULES = tests/unity/unity.c src/list/list.c
OUTDIR = output
OBJMODULES = $(SRCMODULES:.c=.o)

CFALGS = -g -Wall -pedantic -O3

%.o: %.c %.h
	$(CC) $(CFALGS) -c $< -o $@

test: tests/test_list.c $(OBJMODULES)
	$(CC) $(CFALGS) $^ -o $@

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CC) -MM $^ > $@

run: test
	./test

clean:
	rm -f include/*.o
	rm -f src/**/*.o
	rm -f tests/**/*.o
	rm -f deps.mk
	rm -f *.o prog
	rm -f $(OUTDIR)/*
	rm -f ./test