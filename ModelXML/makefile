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

$(OUT): $(BUILDDIR) $(LIBDIR) $(OBJPATH) 
	@echo -n archiving $(OUT)... 
	@ar rcs $(OUT) $(OBJPATH)
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
	@echo cleaned.
	
cleanTests:
	@(cd $(TESTDIR) && $(MAKE) clean); done
	
validate:
	@(cd $(TESTDIR) && $(MAKE) $@); done
	
test:
	@(cd $(TESTDIR) && $(MAKE)); done
	
.PHONY:  clean cleanTests validate


