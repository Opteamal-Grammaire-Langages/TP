all: analyseur

#analyseDTD: *.l *.y makefile
#	flex dtd.l
#	bison --debug --verbose --defines=yy.tab.h dtd.y
#	g++ -g -DYYDEBUG=1 -o analyseDTD  lex.yy.c dtd.tab.c 
#analyseXML: *.l *.y makefile
#	flex  xml.l
#	bison --debug --verbose --defines=yy.tab.h xml.y
#	g++ -g -DYYDEBUG=1 -o analyseXML  lex.yy.c  xml.tab.c 

analyseur: *.l *.y makefile
	flex -Pxml xml.l
	flex -Pdtd dtd.l
	bison --debug --verbose --name-prefix=xml --defines=xml.tab.h xml.y
	bison --debug --verbose --name-prefix=dtd --defines=dtd.tab.h dtd.y
	g++ -g -DYYDEBUG=1 -o analyseur lex.xml.c xml.tab.c lex.dtd.c dtd.tab.c analyseur.c
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseDTD
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML

