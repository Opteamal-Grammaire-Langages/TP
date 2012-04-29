#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
EXE=modeliseurDTD #Nom du binaire à construire
LIB=libmodeliseurdtd.a
LOBJ=analyseur.o
OBJ=test.o
SUBDIR=./src
OBJPATH= $(foreach file, $(OBJ), $(SUBDIR)/$(file))
LOBJPATH= $(foreach file, $(LOBJ), $(SUBDIR)/$(file))
LIBS=$(LIB) ../ModelDTD/lib/libmodelDTD.a

.PHONY : test clean validate
all: $(EXE) test

test: 
	./$(EXE) test/rap1.dtd 2>/dev/null >/dev/null
	./$(EXE) test/rap2.dtd 2>/dev/null >/dev/null
	@echo "All tests successfuls"

$(EXE): $(OBJPATH) $(LIBS)
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
	flex -Pdxml xml.l;\
	flex -Pddtd dtd.l;\
	echo bisoning...;\
	bison --debug --verbose --name-prefix=dxml --defines=xml.tab.h xml.y;\
	bison --debug --verbose --name-prefix=ddtd --defines=dtd.tab.h dtd.y;\
	echo compiling...;\
	$(CC) -w -c -DYYDEBUG=1 -c *.c;\
	echo archiving...;\
	ar rcs bison.a *.o;\
	echo done;\
	cd ..;\
	)

validate: test
	

clean:
	@echo -n cleaning repository... 
	@-rm -f $(SUBDIR)/*.tab.c $(SUBDIR)/lex.*.c $(SUBDIR)/*.tab.h $(SUBDIR)/*.a
	@-rm -f $(SUBDIR)/*.o ./*.output $(EXE) $(SUBDIR)/$(OBJ) $(SUBDIR)/*.gch
	@echo cleaned.
