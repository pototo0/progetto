#ifndef TORRE_H
#define TORRE_H
#include "Pezzo.h"
#include <iostream>
using namespace std;
class Torre : public Pezzo{
	private:
	bool mossa; //l'ho messo per verificare che alcune cose avvengano durante un unico turno (non so se sia giusto metterlo nel caso mi dici e lo togliamo)
	public:
		Torre(const int rig, const int col, const bool color);
		bool move(const int rig, const int col);
		~Torre() {}   //il distruttore va fatto?boh
};
#endif
