#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
EXE=analyseur #Nom du binaire à construire
OBJ=analyseur.o
LIBS=

#analyseDTD: *.l *.y makefile
#	flex dtd.l
#	bison --debug --verbose --defines=yy.tab.h dtd.y
#	g++ -g -DYYDEBUG=1 -o analyseDTD  lex.yy.c dtd.tab.c 
#analyseXML: *.l *.y makefile
#	flex  xml.l
#	bison --debug --verbose --defines=yy.tab.h xml.y
#	g++ -g -DYYDEBUG=1 -o analyseXML  lex.yy.c  xml.tab.c 

.PHONY : test clean
all: $(EXE) test

test: 
	./$(EXE) test/rap1.xml 2>/dev/null >/dev/null
	./$(EXE) test/rap2.xml 2>/dev/null >/dev/null
	@echo "All tests successfuls"

$(EXE): $(OBJ) bison.a $(LIBS)
	@echo building $<
	$(EDL) -o $(EXE) $(EDLFLAGS) $(OBJ) bison.a $(LIBS)
	@echo done

%.o : %.cpp *.h
	@echo compiling $<
	$(CC) $(CCFLAGS) -c $<
	@echo done

bison.a: *.l *.y  
	@echo flexing...
	@flex -Pxml xml.l
	@flex -Pdtd dtd.l
	@echo bisoning...
	@bison --debug --verbose --name-prefix=xml --defines=xml.tab.h xml.y
	@bison --debug --verbose --name-prefix=dtd --defines=dtd.tab.h dtd.y
#@$(CC) -Wall -g -DYYDEBUG=1 -c analyseur lex.xml.c xml.tab.c lex.dtd.c dtd.tab.c analyseur.c
	@echo compiling...
	@$(CC) -w -c -DYYDEBUG=1 -c *.c
	@echo archiving...
	@ar rcs bison.a *.o
	@echo done

clean:
	@echo -n cleaning repository... 
	-rm -rf *.tab.c lex.*.c *.tab.h *.a *.o *.output $(EXE) $(OBJ)
	@echo cleaned.
