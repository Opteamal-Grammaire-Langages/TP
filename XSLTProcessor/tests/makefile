#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
EXE= XSLTProcessorTests #Nom du binaire à construire
SUBDIR= ./src
OBJ= testXSLTProcessor.o testXSLTProcessorMain.o
OBJPATH= $(foreach file, $(OBJ), build/$(file))
BUILDDIR= build
LIBPATHS = -L../lib -L../../ModelXML/lib -L../../ModelDTD/lib
LIBS= -lmodelXML -lmodelDTD -lboost_regex -lxsltprocessor

all: $(EXE) test

$(EXE): $(BUILDDIR) $(OBJPATH)
	@echo building $<
	$(EDL) -o $(EXE) $(EDLFLAGS) $(OBJPATH) $(LIBPATHS) $(LIBS)
	@echo done
	
$(BUILDDIR):
	@-mkdir -p $(BUILDDIR)

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
	@echo "Start testing XSLT Processor"
	./$(EXE)
	@echo "End testing XSLT Processor"


