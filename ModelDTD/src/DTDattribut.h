/*
 * DTDattribut.h
 *
 *  Cette classe correspond a l'attribut d'un element.
 */

#ifndef DTDATTRIBUT_H_
#define DTDATTRIBUT_H_

class	DTDattribut{

public:

	DTDattribut();
	DTDattribut(string nom, string type, string option):
		nomAtt(nom),typeAtt(type),optionAtt(option){}
	virtual ~DTDattribut();

	string getNomAtt() { return nomAtt;}
	string toString(){ return nomAtt + " " + typeAtt + " " + optionAtt; }

private:
	string nomAtt;
	string typeAtt;
	string optionAtt;

};
#endif
