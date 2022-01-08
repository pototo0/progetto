#ifndef REPLAY_H
#define REPLAY_H
#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;
class Replay{
	private:
		static const int rig=8;
		static const int col=8;
		char replay[rig][col];

	public:
		Replay();
		void setting(string nome_file);
		void print();

		~Replay(){}
};
#endif