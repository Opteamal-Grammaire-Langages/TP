#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
EXE=analyseur #Nom du binaire à construire
LIB=libanalyseur.a
SUBDIR=./src
LOBJ=analyseur.o
OBJ=test.o
OBJPATH= $(foreach file, $(OBJ), $(SUBDIR)/$(file))
LOBJPATH= $(foreach file, $(LOBJ), $(SUBDIR)/$(file))
LIBS=$(LIB)

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
	./$(EXE) test/rap1.xml 2>/dev/null >test2.log
	./$(EXE) test/rap2.xml 2>/dev/null >test2.log
	@echo "All tests successfuls"
$(EXE): $(LIB) $(OBJPATH)
	@echo building $<
	$(EDL) -o $(EXE) $(EDLFLAGS) $(OBJPATH) $(LIBS)
	@echo done

$(LIB): $(LOBJPATH) $(SUBDIR)/bison.a
	@echo -n archiving $(LIB)... 
	@ar -x $(SUBDIR)/bison.a
	@ar rcs $(LIB) $(LOBJPATH) ./*.o
	@rm -f ./*.o
	@echo done.

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
	@echo -n cleaning repository... 
	@-rm -f $(SUBDIR)/*.tab.c $(SUBDIR)/lex.*.c $(SUBDIR)/*.tab.h $(SUBDIR)/*.a
	@-rm -f $(SUBDIR)/*.o ./*.output $(EXE) $(LOBJPATH) $(OBJPATH) $(SUBDIR)/*.gch
	@echo cleaned.
