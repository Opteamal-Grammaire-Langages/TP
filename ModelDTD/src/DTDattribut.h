#ifndef DTDATTRIBUT_H_
#define DTDATTRIBUT_H_

class	DTDattribut{
	public:
	DTDattribut(string nom, string type, string option):nomAtt(nom),typeAtt(type),optionAtt(option){
	}
	string toString(){
		return nomAtt + " " + typeAtt + " " + optionAtt;
	}

	string getNomAtt() {
		return nomAtt;
	}

	string nomAtt;
	string typeAtt;
	string optionAtt;

};
#endif
