#pragma once

#include "Atom.h"
#include "StartValues.h"
#include "Parser.h"


const double PI = 3.14159265358979323846;

namespace GA
{
 ref class GeneticMethods
  {
  public:

	ExprParser::Parser^ parser_ ; 

	double xFrom_ ; 
	double xTo_ ; 
	double zFrom_ ; 
	double zTo_ ; 

	int N;
	int BITS ;
	double CPROB ;
	double MPROB;
	int GEN ;
	int VARS ;
	int TPARENTS;
	int CPOINTS;

	
	static System::Random^ RandObj = gcnew System::Random; 

	//Mutation && Crossover variables
	array<int>^ pos; 

	//** Mutation variables **
	int mutationPoints_ ; 
	array<int>^ mutationChroms_ ;
	array<int>^ mutationChromPosis_;

	//** Crossover variables **
	array<int>^ crossoverChrom ; 
	array<int>^ crossoverChromPos ;


  	GeneticMethods(StartValues^ startValues);
  	~GeneticMethods(void);
	

	double rnd(void);
	void Geno2Pheno(Atom^ x) ;
	void Fitness(Atom^ x) ; 
	//void Display( System::Collections::Generic::List<Atom^>^ p ) ;
	int FindBest( System::Collections::Generic::List<Atom^>^ f ) ;
	int FindWorst( System::Collections::Generic::List<Atom^>^ f ) ;
	int RouletteSelection( System::Collections::Generic::List<Atom^>^ f ) ;  
	Atom^ Crossover(Atom^ p1,Atom^ p2) ;   // *One Point*
	void Mutation(Atom^ x, double prob) ;
	void HillClimb(Atom^ x) ;
	System::String^ Int2Bin(int x) ; 
	int tournamentSelection( System::Collections::Generic::List<Atom^>^ f ) ; 
	int rankSelection( System::Collections::Generic::List<Atom^>^ f ) ;
	Atom^ multiPointCrossover(Atom^ p1,Atom^ p2) ; // *Multi Point*
	Atom^ uniformCrossover(Atom^ p1,Atom^ p2); // *Uniform*

  };

}
