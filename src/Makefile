OBJS= tokenizer.o history.o uimain.o

# compiler flags.  -g for debug, -O3 for optimization
CFLAGS=-g -O3

# first target is built by default
all: tokenizer

# include file dependencies
tokenizer.o: tokenizer.h
history.o: history.h
uimain.o: tokenizer.h

# $@=target, $^=prerequisites
tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)


# deletes files generated by compilation
clean:
	rm -f *.o tokenizer

run:tokenizer
	./tokenizer

