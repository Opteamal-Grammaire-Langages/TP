//============================================================================
// Name        : DTD_Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "../../src/Document.h"
#include "../../src/Element.h"
#include "../../src/DTDattribut.h"

using namespace std;
int test1();
int test2();

int main() {
	bool succes = true;
	
	if(test1() == false){
		succes = false;
		cout<<"Test 1 failed"<<endl;
	}else{
		cout<<"Test 1 succeed"<<endl;
	}
	
	if(test2() == false){
		succes = false;
		cout<<"Test 2 failed"<<endl;
	}else{
		cout<<"Test 2 succeed"<<endl;
	}
	
	return !succes;
}

//Test les elements
int test1(){
	Element elem1("titre","CDATA");
	Element elem2("document","titre, corps");
	Element elem3("corps","paragraphe*");
	Element elem4("paragraphe"," CDATA");
	Document doc;
	doc.addElement(&elem1);
	doc.addElement(&elem2);
	doc.addElement(&elem3);
	doc.addElement(&elem4);

	string resultatAttendu =
"<!ELEMENT paragraphe  CDATA>\n\
<!ELEMENT corps paragraphe*>\n\
<!ELEMENT document titre, corps>\n\
<!ELEMENT titre CDATA>\n"; 
	//cout << "DTD: \n"<<doc->toString() << endl;
	return (resultatAttendu == doc.toString());
}

//Test les attributs
int test2(){
	Element elem1("titre","CDATA");
	Element elem2("document","titre, corps");
	Element elem3("corps","paragraphe*");
	Element elem4("paragraphe"," CDATA");
	Document doc;
	doc.addElement(&elem1);
	doc.addElement(&elem2);
	doc.addElement(&elem3);
	doc.addElement(&elem4);
	
	DTDattribut a("id","CDATA","#REQUIRED");
	list<DTDattribut*> atts1;
	atts1.push_back(&a);
	
	DTDattribut a2("id","CDATA","#REQUIRED");
	DTDattribut a3("name","CDATA","#REQUIRED");
	list<DTDattribut*> atts2;
	atts2.push_back(&a2);
	atts2.push_back(&a3);
	
	pair<string, list<DTDattribut*> > p1("titre",atts1);
	pair<string, list<DTDattribut*> > p2("document",atts2);
	doc.addAttributsElement(p1);
	doc.addAttributsElement(p2);

	string resultatAttendu =
"<!ELEMENT paragraphe  CDATA>\n\
<!ELEMENT corps paragraphe*>\n\
<!ELEMENT document titre, corps>\n\
<!ELEMENT titre CDATA>\n\
<!ATTLIST document\n\
	id CDATA #REQUIRED\n\
	name CDATA #REQUIRED\n\
>\n\
<!ATTLIST titre\n\
	id CDATA #REQUIRED\n\
>\n";



	//cout << "DTD: \n"<<doc.toString() << endl;
	return (resultatAttendu == doc.toString());
}
