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
#include "../../src/Attribut.h"

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
	
	//test2(); TODO
	
	return !succes;
}

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

	string resultatAttendu = "paragraphe  CDATA\n\
corps paragraphe*\n\
document titre, corps\n\
titre CDATA\n"; 
	//cout << "DTD: \n"<<doc->toString() << endl;
	return (resultatAttendu == doc.toString());
}

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
	
	Attribut a("id","CDATA","#REQUIRED");
	list<Attribut*> atts1;
	atts1.push_back(&a);
	
	pair<string, list<Attribut*> > p1("titre",atts1);
	doc.addAttributsElement(p1);

	//TODO
	string resultatAttendu = "paragraphe  CDATA\n\
corps paragraphe*\n\
document titre, corps\n\
titre CDATA\n"; 
	cout << "DTD: \n"<<doc.toString() << endl;
	return (resultatAttendu == doc.toString());
}
