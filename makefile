DIR=analyseurSyntaxique

MAKEFILES := ModelXML AnalyseurSemantiqueXML analyseurSyntaxique ModelDTD

first : $(DIR)
	@for dir in $(MAKEFILES);do (cd ./$$dir && $(MAKE)) ; done
	#@for subdir in $(DIR); do (cd ./$$subdir && $(MAKE)) ; done

clean : $(DIR) 
	@for dir in $(MAKEFILES);do (cd ./$$dir && $(MAKE) $@) ; done
