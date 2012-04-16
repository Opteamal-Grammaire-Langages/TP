#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
EXE= AnalyseurSemantiqueTests #Nom du binaire à construire
SUBDIR= ./src
OBJ= Validate.o testValidator.o
BUILDDIR= ./build
EXTERNALDIR := .. ../../ModelXML ../../ModelDTD
LIBS= -lboost_regex
EXTERNALOBJ= $(foreach direc, $(EXTERNALDIR), $(direc)/build/*.o)

all: $(EXE) first $(OBJ)

$(EXE): $(OBJ) $(LIBS)
	@echo building $<

first : $(DIR)
	#A changer
	#$(foreach direc, $(EXTERNALDIR), EXTERNALOBJ = "$(direc)/build/*.o"); done
	@echo $(EXTERNALOBJ)
	$(EDL) -o $(EXE) $(EDLFLAGS) $(BUILDDIR)/*.o $(EXTERNALOBJ) $(LIBS)
	@echo done

%.o: $(SUBDIR)/%.cpp $(SUBDIR)/*.h #$(EXTERNALDIR)/src/*.h
	@echo compiling $<
	$(CC) $(CCFLAGS) -c -o $(BUILDDIR)/$@ $<
	@echo done

clean:
	@echo -n cleaning repository... 
	-rm -rf $(BUILDDIR)/*.o $(EXE)
	@echo cleaned.
	
.PHONY : clean

validate:
	@echo "Start testing Analyseur Semantique XML"
	./$(EXE)
	@echo "End testing Analyseur Semantique XML"

