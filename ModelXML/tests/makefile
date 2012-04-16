#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
EXE= XMLTests #Nom du binaire à construire
SUBDIR= ./src
OBJ= AnalyseurSyntaxique.o XMLTest.o
BUILDDIR= ./build
EXTERNALDIR = ..
LIBS=

all: $(EXE) test

$(EXE): $(OBJ) $(LIBS)
	@echo building $<
	$(EDL) -o $(EXE) $(EDLFLAGS) $(BUILDDIR)/*.o $(EXTERNALDIR)/build/*.o $(LIBS)
	@echo done

%.o: $(SUBDIR)/%.cpp $(SUBDIR)/*.h #$(EXTERNALDIR)/src/*.h
	@echo compiling $<
	$(CC) $(CCFLAGS) -c -o $(BUILDDIR)/$@ $<
	@echo done

clean:
	@echo -n cleaning repository... 
	-rm -rf $(BUILDDIR)/*.o $(EXE)
	@echo cleaned.
	
.PHONY : test clean

validate:
	@echo "Start testing ModelXML"
	./$(EXE)
	@echo "End testing ModelXML"

