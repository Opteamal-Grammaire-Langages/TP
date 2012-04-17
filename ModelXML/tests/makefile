#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
EXE= XMLTests #Nom du binaire à construire
SUBDIR= ./src
OBJ= AnalyseurSyntaxique.o XMLTest.o
OBJPATH= $(foreach file, $(OBJ), build/$(file))
BUILDDIR= build
LIBPATHS = -L../lib
LIBS= -lmodelXML

all: $(EXE) test

$(EXE): $(OBJPATH)
	@echo building $<
	$(EDL) -o $(EXE) $(EDLFLAGS) $(BUILDDIR)/*.o $(LIBPATHS) $(LIBS)
	@echo done
	
$(BUILDDIR)/%.o: %.o
	
%.o: $(SUBDIR)/%.cpp $(SUBDIR)/*.h
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

