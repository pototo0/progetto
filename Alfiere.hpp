#include "Alfiere.h"
#include <iostream>
using namespace std;
Alfiere::Alfiere(const int rig, const int col, bool color){
	mossa=true;
 	setRiga(rig);
	setColonna(col);
	setColore(color);
 }

bool Alfiere::move(const int rig, const int col){
	if(!dentroScacchiera(rig,col)){
		cout<<"posizione non presente in scacchiera"<<endl;
		return false;
	}
	
	int spostRighe=rig-getRiga();
	int spostColonne=col-getColonna();
	if(spostRighe<0){spostRighe=spostRighe*(-1);}
	if(spostColonne<0){spostColonne=spostColonne*(-1);}
	
	if(!getColore()){  //bianchi
		if(mossa && ((spostRighe!=0 && spostColonne==0) || (spostRighe==0 && spostColonne!=0))){  //qui voglio dire che se si muove o solo lungo le ascisse o solo lungo le ordinate il movimento non è consentito in quanto non è il movimento per un Alfiere
			cout<<"movimento non consentito dal pezzo Alfiere"<<endl;
			mossa=false;
			return false;
		}
		if(mossa && (spostRighe==0 && spostColonne==0)){
			cout<<"spostamento non avvenuto"<<endl;
			mossa=false;
			return false;
		}
		if(mossa && (spostRighe==spostColonne)){ //solo se sono uguali i due delta il pezzo si può muovere come un alfiere
			setRiga(rig);
			setColonna(col);
			mossa=false;
			return true;
		}
	}
	
	else{  //neri
		if(mossa && ((spostRighe!=0 && spostColonne==0) || (spostRighe==0 && spostColonne!=0))){
			cout<<"movimento non consentito dal pezzo Alfiere"<<endl;
			mossa=false;
			return false;
		}
		if(mossa && (spostRighe==0 && spostColonne==0)){
			cout<<"spostamento non avvenuto"<<endl;
			mossa=false;
			return false;
		}
		if(mossa && (spostRighe==spostColonne)){  
			setRiga(rig);
			setColonna(col);
			mossa=false;
			return true;
		}
	}
}