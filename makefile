DIR=analyseurSyntaxique

FOLDERS := ModelXML AnalyseurSemantiqueXML analyseurSyntaxique ModelDTD

first : $(DIR)
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE)) ; echo ; done
	#@for subdir in $(DIR); do (cd ./$$subdir && $(MAKE)) ; done

clean : $(DIR) 
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) $@) ; echo ; done
	
tests:
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) test) ; echo ; done
	
cleanTests:
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) $@) ; echo ; done
	
validate:
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) validate) ; echo ; done
