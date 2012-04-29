#Génère la librarie static ValidatorXML

#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
SUBDIR= ./src
BUILDDIR=./build
LIBDIR=./lib
TESTDIR= ./tests
OBJ:= Validator.o
OUT= ./lib/libvalidator.a
OBJPATH= $(foreach file, $(OBJ), build/$(file))

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
	
.PHONY:  clean validate


