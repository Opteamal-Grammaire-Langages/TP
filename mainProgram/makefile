#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
EXE=tpgl #Nom du binaire à construire
SUBDIR=./src
BUILDDIR=./build
OBJ=main.o
OBJPATH= $(foreach file, $(OBJ), build/$(file))
LIBS=../arbreXML/libmodeliseurxml.a ../ModelXML/lib/libmodelXML.a \
		 ../analyseurSyntaxique/libanalyseur.a ../arbreDTD/libmodeliseurdtd.a \
		 ../ModelDTD/lib/libmodelDTD.a ../AnalyseurSemantiqueXML/lib/libvalidator.a \
		 ../XSLTProcessor/lib/libxsltprocessor.a \
		 -lboost_regex

all: $(EXE) 

$(EXE): $(BUILDDIR) $(OBJPATH)
	@echo building $@
	$(EDL) -o $(EXE) $(EDLFLAGS) $(OBJPATH) $(LIBPATHS) $(LIBS)
	@echo done
	
$(BUILDDIR):
	@-mkdir -p $(BUILDDIR)
	
$(BUILDDIR)/%.o: $(SUBDIR)/%.cpp
	@echo compiling $<
	$(CC) $(CCFLAGS) -c -o $@ $<
	@echo done

clean:
	@echo -n cleaning repository... 
	@-rm -f $(BUILDDIR)/*.o $(EXE)
	@echo cleaned.
	
.PHONY : test clean

validate:
	


