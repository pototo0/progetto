#include "Replay.h"
#include <iostream>
#include <fstream>
#include "Exception.hpp"
using namespace std;
Replay::Replay(){
	for(int riga=2; riga<=5; riga++){
		for(int colonna=0; colonna<8; colonna++){
			replay[riga][colonna]=' ';
		}
	}
	//parte bianca
	for(int colonna=0; colonna<8; colonna++){
		replay[1][colonna]='p';
	}

	replay[0][0]='t';
	replay[0][1]='c';
	replay[0][2]='a';
	replay[0][3]='d';
	replay[0][4]='r';
	replay[0][5]='a';
	replay[0][6]='c';
	replay[0][7]='t';
	
	//parte nera
	for(int colonna=0; colonna<8; colonna++){
		replay[6][colonna]='P';
	}
	
	replay[7][0]='T';
	replay[7][1]='C';
	replay[7][2]='A';
	replay[7][3]='D';
	replay[7][4]='R';
	replay[7][5]='A';
	replay[7][6]='C';
	replay[7][7]='T';
}

void Replay::setting(string nome_file){
	ifstream file;
	file.open(nome_file,ios::in);
	if(!file.is_open()){
		throw Exception("Il file non può essere aperto");
	}
	char temp;
	ofstream fileout("replay.txt", ios::app);
	for(string s; getline(file,s);){  //con questo dovrebbe poter leggere riga per riga
		for(int i=0; i<5;i++){
			if(s[i]=='A'){s[i]=0;}
			if(s[i]=='B'){s[i]=1;}
			if(s[i]=='C'){s[i]=2;}
			if(s[i]=='D'){s[i]=3;}
			if(s[i]=='E'){s[i]=4;}
			if(s[i]=='F'){s[i]=5;}
			if(s[i]=='G'){s[i]=6;}
			if(s[i]=='H'){s[i]=7;}
		}
		temp=replay[s[1]][s[0]];
		replay[s[1]][s[0]]=' ';
		replay[s[4]][s[3]]=temp;
		for(int riga=0; riga<8; riga++){   //stampa a video
			cout<<(riga+1)<<" ";
			for(int colonna=0; colonna<8; colonna++){
				cout<<replay[riga][colonna];
			}
			cout<<endl;
		}
		cout<<"  "<<"ABCDEFGH"<<endl<<endl;
		
		for(int riga=0; riga<8; riga++){   //stampa su file 
			fileout<<(riga+1)<<" ";
			for(int colonna=0; colonna<8; colonna++){
				fileout<<replay[riga][colonna];
			}
			fileout<<endl;
		}
		fileout<<"  "<<"ABCDEFGH"<<endl<<endl;
	}
	
	file.close();
	fileout.close();
}

void Replay::print(){
	for(int riga=0; riga<8; riga++){
		cout<<(riga+1)<<" ";
		for(int colonna=0; colonna<8; colonna++){
			cout<<replay[riga][colonna];
		}
		cout<<endl;
	}
	 cout<<"  "<<"ABCDEFGH"<<endl<<endl;
	
	
	ofstream fileout("replay.txt", ios::app);
	for(int riga=0; riga<8; riga++){
		fileout<<(riga+1)<<" ";
		for(int colonna=0; colonna<8; colonna++){
			fileout<<replay[riga][colonna];
		}
		fileout<<endl;
	}
	fileout<<"  "<<"ABCDEFGH"<<endl<<endl;

	fileout.close();
}
	