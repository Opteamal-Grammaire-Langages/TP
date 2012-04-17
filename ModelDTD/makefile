#Génère la librarie static modelDTD

#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
SUBDIR= ./src
BUILDDIR= build
TESTDIR= ./tests
OBJ:= Document.o Element.o
OUT= ./lib/libmodelDTD.a
OBJPATH= $(foreach file, $(OBJ), build/$(file))

$(OUT): $(OBJPATH)
	ar rcs $(OUT) $(OBJPATH)
	
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


