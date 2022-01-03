#ifndef ALFIERE_H
#define ALFIERE_H
#include "Pezzo.h"
#include <iostream>
class Alfiere : public Pezzo{
	private:
		bool mossa;  //vedi commento su Torre.h
	public:
		Alfiere(const int rig, const int col, const bool color);
		bool move(const int rig,  const int col);
		~Alfiere() {} //non so se ci vada il costruttore boh
};
#endif