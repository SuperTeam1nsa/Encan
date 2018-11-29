#pragma once
#include "ObjetEncan.h"
#include <functional>
#include "MEF.h"
#include <thread>

//#include "Interet.h"
//en enum #MEF= new EtatPatient etc 
//enum EtatAcheteur { AGRESSIF, MODERE, PATIENT, RAPIDE, LENT, nb };

//on part sur un template #plus lisible
//typedef enum ObjetInteresse{ ART, ANTIQUITE,};

//template <class T>
class Acheteurs
{
public:

	Acheteurs(int budgetAchat, EtatAcheteur t, std::function<bool(ObjetGenerique&)>interet, std::string nom_acheteur) {
		budget = budgetAchat;
		interessant = interet;
		type = t;
		nom = nom_acheteur;
		/*if (interet != nullptr)
			interessant = interet;*/
	}
	~Acheteurs() {};
	std::string getNom() { return nom; }
	//return un string, un chifre nevermind ^^
	void acheter();
	//if (interessant(object))
		//return;//end of fonction :p 
	//if ((*interessant)(object))//etc
//}//if T::categorie() == objet.categorie() }
//void setState(EtatAcheteur etat);
private:
	int budget;
	EtatAcheteur type;
	std::function<bool(ObjetGenerique&)> interessant;
	std::string nom;
	std::unique_ptr<Etat> currentEtat;
	MEF mef;
	//Interet* interessant;
	//T interessant; //dans une optique de foncteurs sans constructeurs #maps (ici on ferait que des Acheteurs<interet> a(new Interet(..)) =>useless ou pas
	// => argument optionnel )
	//std::function<bool(int)> interessant; //ok mais cycle de vie des foncteurs casse le game => struct
	//ou pourvoir filer une réf sur le foncteur, pas conçu pour initialement #templates yes !
	//rq: https://h-deb.clg.qc.ca/Sujets/TrucsScouts/intro_std_function.html
	//T type;
	//type.acheterOuPas(); // ok
};
//Acheteur<Agressif>();
/*
Les états sont dans des
classes
•Héritage d’un état abstrait
•C’est extrêmement claire et facile d’utilisation
•Désavantages
•Création de plusieurs petits objets

class Transition
{
public:
	int StateToLeave;//inclut dans la map
	bool testTransitionOk(int temps, int nbEchecs){return test(temps,nbEchecs);}
	Etat* stateToGo(){return StateToGo;}
	private:
	Etat* StateToGo;
	std::function<bool(int,int)> test;//bool(*ptrTestFunction) ();
	//bool(*ptrExitFnIfTransitionOK)();
}
class Acheteurs{
//contient un objet contexte qui lui permet de définir son currentEtat;
=> contenu dans acheteurs
cstr(){trans hardcode}

private:
std::unique_ptr<Etat> currentEtat;
//=> on actualise en mode curentEtat=ctx.getNewState(currentEtat,NbEchecs,getDeltaTime)
}
class ctx{
//std::vector<,Transition*> trans; //+que d'états en G
//etat acheteur = enum;
std::map<EtatAcheteur,transition[]>
===std::map<int,std::vector<transition*>> t;
ex: t[EtatAcheteur::Modere].pushback(new Transition(new EtatEnerve(),[](int n,int t) { return n < temps;} }//nouvel etat+condition
//ou lambada: [](int n,int t) { return n < temps;}//ou fonction //ou foncteurs ModereToEnerve
//en mettant une variable locale temps mis à jour à l'appel de getNewState avec les params passés

Etat* getNewState(Etat*currentEtat,int n,int ti);
return t[currentEtat.getEtatID].testTransitionOK(n,ti))?t[currentEtat.getEtatID].stateToGo() :currentEtat;

}

//dans son .h définit l'énum d'état (qui sera inclut dans à travers les états dans contexte)
=> abstract class Etat{
public:
virtual void makeTheStateAction()=0;//ex acheteOuPas();
virtual int getEtatID()=0;
//static int getNbEtat(){return EtatListe::nb;}
protected:
EtatAcheteteur etat;
}
class EtatPatient{
()eta=EtatListe::Patient;
void makeTheStateAction(){//etc};//ou float getProbabiliteAchat();

}



Hum plutôt C
struct State
{
	int State_ID;
	bool(*ptrFnToExecuteWhenEnteringState)();
}


class Transition
{
public:
	int StateToLeave;
	int StateToGo;
	bool(*ptrTestFunction) ();
	bool(*ptrExitFnIfTransitionOK)();
}



class GenericStateMachine
{
public:
	GenericStateMachine();
	~GenericStateMachine();

	int GetCurrentState();
	bool addState(int State_ID, bool(*ptrFnToExecuteWhenEnteringState)());
	bool addTransition(int StateToLeave, int StateToGo,
		bool(*ptrTestFunction) (), bool(*ptrExitFnIfTransitionOK)());
private:
	int CurrentState;
	std::vector<State> StateVector;
	std::vector<Transition> TransitionVector;


}
*/
//ou
/*
class StateMachine
{
public :
	GenericStateMachine();
	~GenericStateMachine();

	enum State (ID_State1, ID_State2, ID_State3);

	std::vector< std::vector<bool (*ptrFuncTransition)()> > Transition;
	// ou son équivalent en C : ( bool (*ptrFuncTransition) () ) Transition [Max_State][Max_Transition];

	int GetCurrentState();

private :
	int CurrentState;


}

GenericStateMachine::GenericStateMachine ()
{

	new Transition = {  // Transitions de l'état ID_State1
			{ptrFuncTransition11, ptrFuncTransition12, ptrFuncTransition13},

			// Transitions de l'état ID_State2
			{ptrFuncTransition21, ptrFuncTransition22, ptrFuncTransition23},

			// Transitions de l'état ID_State3
			{ptrFuncTransition31, ptrFuncTransition32, ptrFuncTransition33},
			}
	etc...
}

int f() {
   return 3;
}
int g() {
   return 4;
}
#include <iostream>
int main() {
   using namespace std;
   int (*pf)() = f;
   cout << pf() << endl;
   pf = g;
   cout << pf() << endl;
}
*/
