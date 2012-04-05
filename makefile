DIR=analyseurSyntaxique

first : $(DIR) 
	@for subdir in $(DIR); do (cd ./$$subdir; make) ; done

clean : $(DIR) 
	@for subdir in $(DIR); do (cd ./$$subdir; make clean) ; done
