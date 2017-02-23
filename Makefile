
THING = basic

$(THING): $(THING).lex.o $(THING).tab.o
	cc -o $(THING) $(THING).lex.o $(THING).tab.o -lm
$(THING).lex.o: $(THING).lex.c $(THING).tab.h
	cc -c $(THING).lex.c
$(THING).tab.o: $(THING).tab.c
	cc -c $(THING).tab.c
$(THING).tab.c $(THING).tab.h: $(THING).y
	bison -d $(THING).y
$(THING).lex.c: $(THING).l
	flex -o $(THING).lex.c $(THING).l
clean:
	rm -f *.tab.c *.lex.c *.o $(THING)
