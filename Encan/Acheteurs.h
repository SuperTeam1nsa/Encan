#pragma once
//en enum #MEF
typedef enum EtatAcheteur { AGRESSIF, MODERE, PATIENT, RAPIDE, LENT };

//on part sur un template #plus lisible
//typedef enum ObjetInteresse{ ART, ANTIQUITE,};
template<class T>
class Acheteurs
{
public:
	Acheteurs(int budgetAchat, EtatAcheteur t) { budget = budgetAchat; type = t; }
	~Acheteurs() {};
	//void acheter(ObjectEncan const& object){ if T::ToString()==objet.ToString()}
	//void setState(EtatAcheteur etat);

private:
	int budget;
	EtatAcheteur type;
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
*/
