#pragma once
//#include <functional>
//#include "Interet.h"
//en enum #MEF
typedef enum EtatAcheteur { AGRESSIF, MODERE, PATIENT, RAPIDE, LENT };

//on part sur un template #plus lisible
//typedef enum ObjetInteresse{ ART, ANTIQUITE,};

template <typename T>
class Acheteurs
{
public:

	Acheteurs(int budgetAchat, T interessant, EtatAcheteur t) {
		budget = budgetAchat; type = t;
	}
	~Acheteurs() {};
	//return un string, un chifre nevermind ^^
	void acheter(int const& object) {
		if (interessant())
			//if ((*interessant)(object))//etc
	}//if T::categorie() == objet.categorie() }
	//void setState(EtatAcheteur etat);
private:
	int budget;
	EtatAcheteur type;
	//Interet* interessant;
	T interessant; //dans une optique de foncteurs sans constructeurs #maps (ici on ferait que des Acheteurs<interet> a(new Interet(..)) =>useless)
	//std::function<bool(int)> interessant; //ok mais cycle de vie des foncteurs casse le game => struct
	//ou pourvoir filer une réf sur le foncteur, pas conçu pour initialement #templates yes !
	//rq: https://h-deb.clg.qc.ca/Sujets/TrucsScouts/intro_std_function.html
	//T type;
	//type.acheterOuPas(); // ok
};
//Acheteur<Agressif>();
/*
class State
{
public:
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
