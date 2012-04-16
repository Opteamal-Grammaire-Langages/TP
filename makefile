DIR=analyseurSyntaxique

FOLDERS := ModelXML AnalyseurSemantiqueXML analyseurSyntaxique ModelDTD

first : $(DIR)
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE)) ; done
	#@for subdir in $(DIR); do (cd ./$$subdir && $(MAKE)) ; done

clean : $(DIR) 
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) $@) ; done
	
tests:
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) $@) ; done
	
cleanTests:
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) $@) ; done
	
validate:
	@for dir in $(FOLDERS);do (cd ./$$dir && $(MAKE) validate) ; done
