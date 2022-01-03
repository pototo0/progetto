#include "Torre.h"
#include <iostream>
using namespace std;

Torre::Torre(const int rig, const int col, const bool color){
	mossa=true;
	setRiga(rig);
	setColonna(col);
	setColore(color);
}
//boh come ti dicevo avevo a suo tempo pensato di fare dei metodi a parte per verificare se il percorso era libero o meno cosi come la destinazione ma penso ci riaggiorneremo per questa cosa qui (anche perche probabilmente non è da fare nelle singole classi)
/*bool freedestination(const int rig, const int col){  //capire se la destinazione è libera o meno, pensavo di usare un oggetto pezzo quindi non lasciando la classe virtuale pura cosi da poter scrivere il costruttore di Pezzo e avere un oggetto pezzo generico (in realtà è meglio come l'avevi spiegata te)
}

bool freepath(){
	//devo scrivere che il percorso tra il punto  di partenza della torre e dove vuole arrivare sia libero altrimenti si deve bloccare(se il pezzo che blocca è del suo stesso colore) alla casella prima o può mangiare (se il pezzo è di colore opposto) e fermarsi nella casella del pezzo mangiato
}
*/
bool Torre::move(const int rig, const int col){
	if(!dentroScacchiera(rig,col)){
		cout<<"posizione non presente in scacchiera"<<endl;
		return false;
	}
	
	int spostRighe = rig - getRiga();
	int spostColonne = col - getColonna(); 
	if(!getColore()){  //bianchi
		if(mossa && (spostRighe!=0 && spostColonne!=0)){  //qui voglio dire che la torre non può muovere entrambe le righe e le colonne nello stesso turno altrimenti andrebbe in diagonale
			cout<<"movimento non consentito per il pezzo Torre"<<endl; 
			mossa=false;
			return false;
		 }
		if(mossa && (spostRighe==0 && spostColonne==0)){
			cout<<"spostamento non avvenuto"<<endl;
			mossa=false;
			return false;
		}

		else{
			setRiga(rig);
			setColonna(col);
			return true;
		}
	}

	else{  //neri
		if(mossa && (spostRighe!=0 && spostColonne!=0)){  
			cout<<"movimento non consentito per il pezzo Torre"<<endl; 
			mossa=false;
			return false;
		 }
		if(mossa && (spostRighe==0 && spostColonne==0)){
			cout<<"spostamento non avvenuto"<<endl;
			mossa=false;
			return false;
		}
		else{
			setRiga(rig);
			setColonna(col);
			return true;
		}
	}
	
}