#Génère la librarie static modelXML

#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
SUBDIR=./src
BUILDDIR=./build
LIBDIR=./lib
TESTDIR=./tests
OBJ:=XMLBalise.o XMLData.o XMLElement.o XMLDocument.o
OUT=./lib/libmodelXML.a
OBJPATH= $(foreach file, $(OBJ), $(BUILDDIR)/$(file))

$(OUT): $(BUILDDIR) $(LIBDIR) $(OBJPATH) $(TESTDIR)
	@echo -n archiving $(OUT)... 
	@ar rcs $(OUT) $(OBJPATH)
	@(cd $(TESTDIR) && $(MAKE))
	@echo done.
	
$(BUILDDIR):
	@-mkdir -p $(BUILDDIR)

$(LIBDIR):
	@-mkdir -p $(LIBDIR)
	
$(BUILDDIR)/%.o: $(SUBDIR)/%.cpp $(SUBDIR)/*.h
	@echo compiling $<
	$(CC) $(CCFLAGS) -c -o $@ $<
	@echo done

clean:
	@echo -n cleaning repository... 
	@-rm -f $(BUILDDIR)/*.o $(OUT)
	@(cd $(TESTDIR) && $(MAKE) clean)
	@echo cleaned.
	
validate:
	@(cd $(TESTDIR) && $(MAKE) $@) 
	
.PHONY:  clean cleanTests validate


