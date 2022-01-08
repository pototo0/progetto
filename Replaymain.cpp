#include "Replay.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(void){
	Replay rep;
	string file;
	cout<<"inserire il nome del file da cui copiare i passaggi della partita"<<endl;  //bisognerebbe inoltre chiedere se si vuole il replay stampato a schermo o in un file esterno
	cin>>file;																			  //perchè al momento quando invoco i due metodi mi fa estrambe le cose
	rep.print();
	rep.setting(file);
	cout<<"-----fine partita-----"<<endl;
	return 0;
}