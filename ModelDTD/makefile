#Génère la librarie static modelDTD

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
OBJ:= Document.o Element.o
OUT= ./lib/libmodelDTD.a
OBJPATH= $(foreach file, $(OBJ), $(BUILDDIR)/$(file))

$(OUT): directories $(OBJPATH) 
	@echo -n archiving $(OUT)...  
	@ar rcs $(OUT) $(OBJPATH)
	@echo done.
	
directories :
	@-mkdir -p $(BUILDDIR)
	@-mkdir -p $(LIBDIR)
	
$(BUILDDIR)/%.o: $(SUBDIR)/%.cpp $(SUBDIR)/*.h
	@echo compiling $<
	$(CC) $(CCFLAGS) -c -o $@ $<
	@echo done

clean:
	@echo -n cleaning repository... 
	@-rm -rf $(BUILDDIR)/*.o $(OUT)
	@echo cleaned.
	
cleanTests:
	@(cd $(TESTDIR) && $(MAKE) clean); done
	
validate:
	@(cd $(TESTDIR) && $(MAKE) $@); done
	
test:
	@(cd $(TESTDIR) && $(MAKE)); done
	
.PHONY:  clean cleanTests validate

