DIR=analyseurSyntaxique

FOLDERS := ModelXML ModelDTD AnalyseurSemantiqueXML analyseurSyntaxique \
 arbreXML arbreDTD XSLTProcessor mainProgram 

first : $(DIR)
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE)) ; echo ; done
	@#@for subdir in $(DIR); do (cd ./$$subdir && $(MAKE)) ; done

clean : $(DIR) 
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) $@) ; echo ; done
	
tests:
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) -s test) ; echo ; done
	
cleanTests:
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) $@) ; echo ; done
	
validate:
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) validate) ; echo ; done;
