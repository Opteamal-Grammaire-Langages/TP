#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
EXE=analyseur #Nom du binaire à construire
SUBDIR=./src
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

$(EXE): $(SUBDIR)/$(OBJ) $(SUBDIR)/bison.a $(LIBS)
	@echo building $<
	$(EDL) -o $(EXE) $(EDLFLAGS) $(SUBDIR)/$(OBJ) $(SUBDIR)/bison.a $(LIBS)
	@echo done

$(SUBDIR)/%.o : $(SUBDIR)/%.cpp $(SUBDIR)/*.h
	@echo compiling $<
	$(CC) $(CCFLAGS) -c -o $@ $<
	@echo done

$(SUBDIR)/bison.a: $(SUBDIR)/*.l $(SUBDIR)/*.y  
	@(\
	cd $(SUBDIR)/;\
	echo flexing...;\
	flex -Pxml xml.l;\
	flex -Pdtd dtd.l;\
	echo bisoning...;\
	bison --debug --verbose --name-prefix=xml --defines=xml.tab.h xml.y;\
	bison --debug --verbose --name-prefix=dtd --defines=dtd.tab.h dtd.y;\
	echo compiling...;\
	$(CC) -w -c -DYYDEBUG=1 -c *.c;\
	echo archiving...;\
	ar rcs bison.a *.o;\
	echo done;\
	cd ..;\
	)

clean:
	@echo cleaning repository... 
	rm -rf $(SUBDIR)/*.tab.c $(SUBDIR)/lex.*.c $(SUBDIR)/*.tab.h $(SUBDIR)/*.a
	rm -rf $(SUBDIR)/*.o ./*.output $(EXE) $(SUBDIR)/$(OBJ) $(SUBDIR)/*.gch
	@echo cleaned.
