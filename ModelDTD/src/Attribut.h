#ifndef ATTRIBUT_H_
#define ATTRIBUT_H_

class	Attribut{
	public:
	Attribut(string nom, string type, string option):nomAtt(nom),typeAtt(type),optionAtt(option){
	}
	string toString(){
		return nomAtt + " " + typeAtt + " " + optionAtt;
	}
	string nomAtt;
	string typeAtt;
	string optionAtt;

};
#endif
