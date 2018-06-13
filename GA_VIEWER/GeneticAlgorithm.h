#pragma once
#include "Atom.h"
#include "GeneticMethods.h"
#include "StartValues.h"

#include <GL/gl.h>


namespace GA
{

	

ref class GeneticAlgorithm
 {
 public:
			
			static const int GA_EXECUTION_FINISHED = -1; 
			static const int GA_RUNS = 0; 
			static const int GA_STEP_GEN_POSITION = 1;
			static const int GA_STEP_ELITISM = 2;
			static const int GA_STEP_CHILD_POSITION = 3;
			static const int GA_STEP_SELECTION = 4;
			static const int GA_STEP_CROSSOVER = 5;
			static const int GA_STEP_MUTATION = 6;
			static const int GA_STEP_CHILD_EVALUATION = 7;
			static const int GA_STEP_HILL_CLIMB = 8 ;
			static const int GA_GENERATION_EXECUTED = 0 ;
/*
			static const int GA_RED = 0;
			static const int GA_GREEN = 1 ; 
			static const int GA_BLUE = 2 ; 
			static const int GA_YELLOW = 3 ; 
			static const int GA_BROWN = 4 ; 
*/
 private:
	    GA::GeneticMethods^ geneticMethods_ ;
		StartValues^ startValues_ ; 

		System::Collections::Generic::List<Atom^>^ parents_;  
		System::Collections::Generic::List<Atom^>^ population_; 

		Atom tmpAtom_ ; 
		//int atomSize_ ; 

	//	System::String^ message_ ;
	//	int^ messageColors_;
	//	int messageColorNumber_ ; 
	//	int messagePosition_ ; 

		int j,i ;
		int gen,child,p1,p2,best;
		int step ; 

		//=-=-=-=- Crossover Action -=-=-=-=
		int crossoverAction_;
		static const int CROSSOVER_NOT_HAPPENED  = -1 ; 
		static const int CROSSOVER_HAPPENED  = 0 ; 
		static const int CROSSOVER_P1_BECAME_CHILD = 1 ;
		static const int CROSSOVER_P2_BECAME_CHILD = 2 ;


 public: GeneticAlgorithm(StartValues^ startValues); 
	~GeneticAlgorithm(void);
	private: void initLocalVars();
	public:	void reset();
//	void run();
		 //** if return = 0 generations are not finished **
		 //** if return = -1 generations are finished **
	public: int runGeneration();
	int RunStep();
/*
	System::String^ getMessage();
	System::String^ getPopulationMessage();
	int ^getMessageColors();
	int getMessageColorsNumber();

*/
	public: bool infoMessageGenerationEnabled ; 
	public: bool genMessageGenerationEnabled ; 

	void  createGenerationMessage();
	void  createElitismMessage();
	void createChildPositionMessage();
	void  createSelectionMessage();
	void  createCrossoverMessage();
	void  createMutationMessage();
	void  createChildEvaluationMessage();
	void createHillClimbMessage();
	void  createPopulationReplacementMessage();
	void  createFinishMessage();

	void displayGenerationInLabel();
	void displayChosenAtomInLabel(int atomPos);

	void paintAtoms(); 
	void setAtomsPixelPositions();
	void displayAtomsValues( GLfloat xMousePos, GLfloat yMousePos, GLfloat zMousePos ) ; 



 };
 
}