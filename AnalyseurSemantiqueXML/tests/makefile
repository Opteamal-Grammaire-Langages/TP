#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
EXE= AnalyseurSemantiqueTests #Nom du binaire à construire
SUBDIR= ./src
OBJ= Validate.o testValidator.o
OBJPATH= $(foreach file, $(OBJ), build/$(file))
BUILDDIR= build
LIBPATHS = -L../lib -L../../ModelXML/lib -L../../ModelDTD/lib
LIBS= -lmodelXML -lmodelDTD -lvalidator -lboost_regex

all: $(EXE) test

$(EXE): $(OBJPATH)
	@echo building $<
	$(EDL) -o $(EXE) $(EDLFLAGS) $(OBJPATH) $(LIBPATHS) $(LIBS)
	@echo done
	
$(BUILDDIR)/%.o: $(SUBDIR)/%.cpp $(SUBDIR)/*.h
	@echo compiling $<
	$(CC) $(CCFLAGS) -c -o $@ $<
	@echo done

clean:
	@echo -n cleaning repository... 
	-rm -rf $(BUILDDIR)/*.o $(EXE)
	@echo cleaned.
	
.PHONY : test clean

validate:
	@echo "Start testing Analyseur Semantique XML"
	./$(EXE)
	@echo "End testing Analyseur Semantique XML"


