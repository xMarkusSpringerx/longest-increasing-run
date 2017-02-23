CC = gcc
CFLAGS = -ansi -g -w
LD = gcc
LFLAGS = -lm # link math library
CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

main: $(OFILES)
	$(LD) -o $@ $(OFILES) $(LFLAGS)

clean:
	rm -f main core *.o *..c *% %.bak %.BAK *~

depend:
	@cat < /dev/null > makedep
	@for i in ${CFILES}; do \
	($(CC) -MM $$i >> makedep); done
	@echo '/^# DO NOT DELETE LINE/+1,$$d' > eddep
	@echo '$$r makedep' >> eddep
	@echo 'w' >> eddep
	@echo 'q' >> eddep
	@cp makefile makefile.bak
	@ed - makefile < eddep
	@rm eddep makedep
	@echo '# EDIT ONLY ABOVE # DO NOT' >> makefile
