#Génère uniquement les *.o

#Variables utilisées :
CC=g++ #Compilateur
EDL=g++ #Linker
CCFLAGS=-Wall #Options de compilations
EDLFLAGS=-Wall
ECHO=@echo
SUBDIR= ./src
BUILDDIR= ./build
TESTDIR= ./tests
OBJ= Validator.o

first: $(OBJ)
 
%.o : $(SUBDIR)/%.cpp $(SUBDIR)/*.h
	@echo compiling $<
	$(CC) $(CCFLAGS) -c -o $(BUILDDIR)/$@ $<
	@echo done

clean:
	@echo -n cleaning repository... 
	-rm -rf $(BUILDDIR)/*.o
	@echo cleaned.
	
cleanTests:
	@(cd $(TESTDIR) && $(MAKE) clean); done
	
validate:
	@(cd $(TESTDIR) && $(MAKE) $@); done
	
test:
	@(cd $(TESTDIR) && $(MAKE)); done
	
.PHONY:  clean cleanTests validate
