#include "StdAfx.h"
#include "GeneticAlgorithm.h"

/*
 *Constructor 
 */

GA::GeneticAlgorithm::GeneticAlgorithm(StartValues^ startValues)
{
	this->startValues_ = startValues ; 
	geneticMethods_ = gcnew GeneticMethods(startValues_);
	this->parents_ = gcnew 	System::Collections::Generic::List<Atom^>();  
	this->population_ = gcnew System::Collections::Generic::List<Atom^>(); 

	this->initLocalVars();
}

/*
 *Destructor 
 */
GA::GeneticAlgorithm::~GeneticAlgorithm(void)
{
}



/*
 *Fills the population and patents list with atoms 
 *and randomizes every atom's geno values.
 */
void GA::GeneticAlgorithm::initLocalVars()
{
int i , j ; 
Atom^ atom; 
	
//** initialize random seed: **//
//srand ( time(NULL) );

	//**Fill Lists with Atoms**
for(i=0;i<startValues_->N_;i++)
   {
	   atom = gcnew Atom();
	   parents_->Add(atom);
	   population_->Add(atom);
   }

	//**Init population's genotypes**
for(i=0;i<startValues_->N_;i++)
   {
      for(j=0;j<startValues_->VARS_;j++)
		  parents_[i]->geno_[j] = rand() %  (int) Math::Pow((double)2,(double)startValues_->BITS_) ;
   }

	//** Init population fitness , evaluation **
for(i=0 ; i<startValues_->N_ ; i++)
	geneticMethods_->Fitness(parents_[i]);

	//** Init populations pixel positions to be ready to draw **
this->setAtomsPixelPositions();


j = 0 ;
i = 0 ;
gen = 0 ;
child = 1 ;
p1 = 0 ;
p2 = 0 ;
best = 0;
crossoverAction_ = GA::GeneticAlgorithm::CROSSOVER_NOT_HAPPENED;
this->infoMessageGenerationEnabled  = true ;
this->genMessageGenerationEnabled = true ; 

}


/*
 *If we want to rerun the algorithm after a finished execution we have to call this function to initialize tha algorithm
 */
void GA::GeneticAlgorithm::reset()
 {

	//** Clear Lists **
	 parents_->Clear();
	 population_->Clear();

	 this->initLocalVars();
 }
//========================================================================
/*void GA::GeneticAlgorithm::run()
{

for(gen=0 ; gen < startValues_->GEN_ ; gen++)
 {  




	//** Elitism **
 best=geneticMethods_->FindBest(parents_ ) ; 
 population_[0] = parents_[best];

 this->createElitismMessage();

  for(child=1 ; child<startValues_->N_ ; child++)
	{
		//** Roulette **
	if ( startValues_->SELECTION_TYPE_ == StartValues::ROULETTE_SELECTION )
			{
				p1 = geneticMethods_->RouletteSelection( parents_ );
				p2 = geneticMethods_->RouletteSelection( parents_ );
			}

		else if ( startValues_->SELECTION_TYPE_ == StartValues::TOURNAMENT_SELECTION )
			{
				p1 = geneticMethods_->tournamentSelection( parents_ );
				p2 = geneticMethods_->tournamentSelection( parents_ );
			}

		else if ( startValues_->SELECTION_TYPE_ == StartValues::RANK_SELECTION )
			{
				p1 = geneticMethods_->rankSelection( parents_ );
				p2 = geneticMethods_->rankSelection( parents_ );
			}
		this->createSelectionMessage();

		//** Crossover **
	if( geneticMethods_->rnd()<startValues_->CPROB_ )
break;
			if (startValues_->CPOINTS_  < 1)
				population_[child] =geneticMethods_->uniformCrossover(parents_[p1] , parents_[p2] ) ; 

			else if (startValues_->CPOINTS_  == 1)
				population_[child] =geneticMethods_->Crossover(parents_[p1] , parents_[p2] ) ; 

			else if (startValues_->CPOINTS_  > 1)
				population_[child] =geneticMethods_->multiPointCrossover(parents_[p1] , parents_[p2] ) ;
	else
		{
		if( geneticMethods_->rnd()<0.5 )
			population_[child] = parents_[p1];     
		else
			population_[child] = parents_[p2];
		}

		this->createCrossoverMessage();

	//** Mutation **
	 geneticMethods_->Mutation( population_[child] , startValues_->MPROB_ );
	 this->createMutationMessage();

	 //***new child evaluation***
     geneticMethods_->Fitness(population_[child]);
	 this->createChildEvaluationMessage();

	}//child loop end

	//**the best child on HillClimb **
 best = geneticMethods_->FindBest( population_ );
 geneticMethods_->HillClimb( population_[best] );
 this->createHillClimbMessage();

	//** populaiton replacement , children to parents ** 
  for(i=0 ; i<startValues_->N_ ; i++)
		{
		parents_[i] = population_[i];
		}
  this->createPopulationReplacementMessage();

  this->setAtomsPixelPositions();

 }//geneation loop end

}
*/

/*
 *This is the main function that runs a generation 
 *We use this function repeatedly to evolve the population. 
 */
int GA::GeneticAlgorithm::runGeneration()
{
int i ;

	if (gen == startValues_->GEN_ ) return this->GA_EXECUTION_FINISHED ; 

	this->createGenerationMessage();
	this->displayGenerationInLabel();

	//** Elitism **
 best=geneticMethods_->FindBest(parents_ ) ; 
 population_[0] = parents_[best];
 this->createElitismMessage();

  for(child=0 ; child<startValues_->N_ ; child++)
	{
		this->createChildPositionMessage();

		//** Roulette selection **
		if ( startValues_->SELECTION_TYPE_ == StartValues::ROULETTE_SELECTION )
			{
			p1 = geneticMethods_->RouletteSelection( parents_ );
			p2 = geneticMethods_->RouletteSelection( parents_ );
			}

		//**Tournament selection **
		else if ( startValues_->SELECTION_TYPE_ == StartValues::TOURNAMENT_SELECTION )
			{
			p1 = geneticMethods_->tournamentSelection( parents_ );
			p2 = geneticMethods_->tournamentSelection( parents_ );
			}

		//** Rank selection **
		else if ( startValues_->SELECTION_TYPE_ == StartValues::RANK_SELECTION )
			{
			p1 = geneticMethods_->rankSelection( parents_ );
			p2 = geneticMethods_->rankSelection( parents_ );
			}
		this->createSelectionMessage();

		//** Crossover **
		if( geneticMethods_->rnd()<startValues_->CPROB_ )
			{
			crossoverAction_ = GA::GeneticAlgorithm::CROSSOVER_HAPPENED ; 

			if (startValues_->CPOINTS_  < 1)
				population_[child] =geneticMethods_->uniformCrossover(parents_[p1] , parents_[p2] ) ; 

			else if (startValues_->CPOINTS_  == 1)
				population_[child] =geneticMethods_->Crossover(parents_[p1] , parents_[p2] ) ; 

			else if (startValues_->CPOINTS_  > 1)
				population_[child] =geneticMethods_->multiPointCrossover(parents_[p1] , parents_[p2] ) ;
			}
		else
			{
			if( geneticMethods_->rnd()<0.5 )
				{
				crossoverAction_ = GA::GeneticAlgorithm::CROSSOVER_P1_BECAME_CHILD ; 
				population_[child] = parents_[p1];     
				}
			else
				{
				crossoverAction_ = GA::GeneticAlgorithm::CROSSOVER_P2_BECAME_CHILD ; 
				population_[child] = parents_[p2];
				}
			}

		this->createCrossoverMessage();

	//** Mutation **
	this->tmpAtom_ = population_[child] ; 
	geneticMethods_->Mutation( population_[child] , startValues_->MPROB_ );
	this->createMutationMessage();

	 //***new child evaluation***
    geneticMethods_->Fitness(population_[child]);
	this->createChildEvaluationMessage();

	}//child loop end

	//**the best child on HillClimb **
	best = geneticMethods_->FindBest( population_ );
	geneticMethods_->HillClimb( population_[best] );

	//** populaiton replacement , children to parents ** 
 for(i=0 ; i<startValues_->N_ ; i++)
	{
	parents_[i] = population_[i];
	}
 this->createPopulationReplacementMessage();

 this->setAtomsPixelPositions();


		best = geneticMethods_->FindBest( population_);

gen++;

return GA_GENERATION_EXECUTED;
}

//=.-=.=-.=-.=-.=-.=-.=-.=-.=-.=-.=-.=-.=-.=.=-.=-.=.=-.=-.=-.=-.=-.=-.=-.=-.=-.=-=

int GA::GeneticAlgorithm::RunStep()
{

	//** Gen position **
	if (step == GA_STEP_GEN_POSITION )
		{
		//messagePosition_ = GA_STEP_GEN_POSITION;
		this->createGenerationMessage();
		this->displayGenerationInLabel();

		if (gen == startValues_->GEN_ ) 
			step = this->GA_EXECUTION_FINISHED ;
		else 
			step = GA_STEP_ELITISM ;

		return GA_STEP_GEN_POSITION;
		}

	//** Elitism **
	if (step == GA_STEP_ELITISM )
		{
		best=geneticMethods_->FindBest(parents_ ) ; 
		population_[0] = parents_[best];
		step = GA_STEP_CHILD_POSITION ;

		this->createElitismMessage();

		return GA_STEP_ELITISM;
		}


	//** Child position **
	if ( step == GA_STEP_CHILD_POSITION )
		{

		this->createChildPositionMessage();

			if (child < startValues_->N_ )
				 step = GA_STEP_SELECTION ; 
			else
				 step = GA_STEP_HILL_CLIMB ;

			return GA_STEP_CHILD_POSITION;
		}	

		//** Child selection **
	if (step == GA_STEP_SELECTION )
		{

	//** Roulette selection **
		if ( startValues_->SELECTION_TYPE_ == StartValues::ROULETTE_SELECTION )
			{
			p1 = geneticMethods_->RouletteSelection( parents_ );
			p2 = geneticMethods_->RouletteSelection( parents_ );
			}

		//**Tournament selection **
		else if ( startValues_->SELECTION_TYPE_ == StartValues::TOURNAMENT_SELECTION )
			{
			p1 = geneticMethods_->tournamentSelection( parents_ );
			p2 = geneticMethods_->tournamentSelection( parents_ );
			}

		//** Rank selection **
		else if ( startValues_->SELECTION_TYPE_ == StartValues::RANK_SELECTION )
			{
			p1 = geneticMethods_->rankSelection( parents_ );
			p2 = geneticMethods_->rankSelection( parents_ );
			}

		this->createSelectionMessage();
 		step = GA_STEP_CROSSOVER ;

		return GA_STEP_SELECTION;
		}


		//** Crossover **
	if (step == GA_STEP_CROSSOVER  )
		{

		if( geneticMethods_->rnd()<startValues_->CPROB_ )
			{
			crossoverAction_ = GA::GeneticAlgorithm::CROSSOVER_HAPPENED ; 

			if (startValues_->CPOINTS_  < 1)
				population_[child] =geneticMethods_->uniformCrossover(parents_[p1] , parents_[p2] ) ; 

			else if (startValues_->CPOINTS_  == 1)
				population_[child] =geneticMethods_->Crossover(parents_[p1] , parents_[p2] ) ; 

			else if (startValues_->CPOINTS_  > 1)
				population_[child] =geneticMethods_->multiPointCrossover(parents_[p1] , parents_[p2] ) ;
			}
		else
			{
			if( geneticMethods_->rnd()<0.5 )
				{
				crossoverAction_ = GA::GeneticAlgorithm::CROSSOVER_P1_BECAME_CHILD ; 
				population_[child] = parents_[p1];     
				}
			else
				{
				crossoverAction_ = GA::GeneticAlgorithm::CROSSOVER_P2_BECAME_CHILD ; 
				population_[child] = parents_[p2];
				}
			}


		this->createCrossoverMessage();
		step = GA_STEP_MUTATION ;
		return GA_STEP_CROSSOVER;
		}

	//** Mutation **
	if (step == GA_STEP_MUTATION  )
		{

		this->tmpAtom_ = population_[child] ; 
		geneticMethods_->Mutation( population_[child] , startValues_->MPROB_ );
		
		this->createMutationMessage();
		step = GA_STEP_CHILD_EVALUATION ; 

		return GA_STEP_MUTATION;
		}


	 //***New child evaluation***
	if (step == GA_STEP_CHILD_EVALUATION  )
		{

		geneticMethods_->Fitness(population_[child]);
		this->createChildEvaluationMessage();

		child++;
		step = GA_STEP_CHILD_POSITION;

		return GA_STEP_CHILD_EVALUATION;
		}


	//**The best child on HillClimb **
	if ( step == GA_STEP_HILL_CLIMB )
		{
		best = geneticMethods_->FindBest( population_ );
		geneticMethods_->HillClimb( population_[best] );

		child = 1 ; 

		this->createHillClimbMessage();
		step = GA_GENERATION_EXECUTED;

		return GA_STEP_HILL_CLIMB;
		}


	//** populaiton replacement , children to parents ** 
	if ( step == GA_GENERATION_EXECUTED )
		{

		for( i = 0 ; i < this->parents_->Count ; i++ )
			{
			parents_[i] = population_[i];
			}

		this->createPopulationReplacementMessage();

		this->setAtomsPixelPositions();

		step = this->GA_STEP_GEN_POSITION ; 
		gen++;

		return GA_GENERATION_EXECUTED;
	}


	if ( step == this->GA_EXECUTION_FINISHED )
		{
		return GA_EXECUTION_FINISHED ; 
		}

return 0;
}


/*
//=.-=.=-.=-.=-.=-.=-.=-.=-.=-.=-.=-.=-.=-.=.=-.=-.=.=-.=-.=-.=-.=-.=-.=-.=-.=-.=-=
System::String^ GA::GeneticAlgorithm::getMessage()
{
//delete messageColors_;	


//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
if ( messagePosition_ == -1 )
	{
	message_ =  "Genetic algorithm Ready";
	}

//=-=-=-=-GEN_POSITION=-=-=-=-=-=-=-=
else if (messagePosition_ == GA_STEP_GEN_POSITION ) 
	{
	message_ = this->createGenerationMessage();
	}	

//=-=-=-=-=-=-ELITISM-=-=-=-=-=-=-=-=
else if (messagePosition_ == GA_STEP_ELITISM)
	{
	message_ = this->createElitismMessage();
	}

//=-=-=-=-CHILD_POSITION=-=-=-=-=-=-=
else if (messagePosition_ == GA_STEP_CHILD_POSITION)
	{
	message_ = this->createChildPositionMessage();
	}

//=-=-=-=-SELECTION-=-=-=-=-=-=-=-=-=
else if (messagePosition_ == GA_STEP_SELECTION)
	{
	message_ = this->createSelectionMessage();
	}

//-=-=-=-=-=- Crossover -=-=-=-=-=-=-=
else if (messagePosition_ == this->GA_STEP_CROSSOVER)
	{
	message_ = this->createCrossoverMessage();
	}

//=-=-=-=-=-=-Mutation=-=-=-=-=-=-=-=
else if ( messagePosition_ == GA_STEP_MUTATION )
	{
	message_ = this->createMutationMessage();
	}

//=-=-=-=-=Child Evaluation-=-=-=-=-=
else if ( messagePosition_ == GA_STEP_CHILD_EVALUATION )
	{
		message_ = this->createChildEvaluationMessage();
	}

//=-=-=-=-=-Hill Climb=-=-=-=-=-=-=-=
else if ( messagePosition_ == GA_STEP_HILL_CLIMB )
	{
	message_ = this->createHillClimbMessage();
	}

//=-=-=POPULATION_REPLACEMENT-=-=-=-=
else if ( messagePosition_ == GA_GENERATION_EXECUTED )
	{
	message_ = this->createPopulationReplacementMessage();
	}

//=-=-=-=-=-=FINISH-=-=-=-=-=-=-=-=-=
else if ( messagePosition_ == this->GA_EXECUTION_FINISHED )
	{
	message_ = 	this->createFinishMessage();
	}


return message_ ; 
}

System::String^ GA::GeneticAlgorithm::getPopulationMessage()
{
if ( messagePosition_ == GA_GENERATION_EXECUTED )
			return this->createPopulationReplacementMessage();
else 
	return "" ; 
	
}

int *GA::GeneticAlgorithm::getMessageColors()
{
return messageColors_ ;
}

int GA::GeneticAlgorithm::getMessageColorsNumber()
{
return messageColorNumber_ ;
}

*/

/*
 *If messageGeneration is enabled and the this->startValues_->stepOutputRichTextBox_ controll 
 * is not nullptr we create a text that shows the movements of the algorithm. 
 */
void  GA::GeneticAlgorithm::createGenerationMessage()
{
if (this->infoMessageGenerationEnabled == false || this->startValues_->stepOutputRichTextBox_ == nullptr ) return;

this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Red ;
this->startValues_->stepOutputRichTextBox_->AppendText("=-=-= Generation " + gen + " =-=-= \n =-=-=-=-=-=-=-=-=-=- \n =-=-=-=-=-=-=-=-=-=- \n\n");
this->startValues_->stepOutputRichTextBox_->ScrollToCaret();
}

/*
 *If messageGeneration is enabled and the this->startValues_->stepOutputRichTextBox_ controll 
 * is not nullptr we create a text that shows the movements of the algorithm. 
 */
void  GA::GeneticAlgorithm::createElitismMessage()
{
int i;
if (this->infoMessageGenerationEnabled == false || this->startValues_->stepOutputRichTextBox_ == nullptr ) return;

this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Blue ;
this->startValues_->stepOutputRichTextBox_->AppendText(  "=-=-= Elitism =-=-= \n" );

this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black ;
this->startValues_->stepOutputRichTextBox_->AppendText(  "Best: " + best + "\n Geno: " );

for( i=0 ; i<startValues_->VARS_ ; i++)	
	{
	this->startValues_->stepOutputRichTextBox_->AppendText( ""+parents_[best]->geno_[i] );
	}

this->startValues_->stepOutputRichTextBox_->AppendText( " Feno: " );

for( i=0 ; i<startValues_->VARS_ ; i++)	
	{
	this->startValues_->stepOutputRichTextBox_->AppendText( ""+parents_[best]->pheno_[i] );
	}

this->startValues_->stepOutputRichTextBox_->AppendText( " Fitness: " + parents_[best]->fitness_ + "\n\n" );

this->startValues_->stepOutputRichTextBox_->ScrollToCaret();
}

/*
 *If messageGeneration is enabled and the this->startValues_->stepOutputRichTextBox_ controll 
 * is not nullptr we create a text that shows the movements of the algorithm. 
 */
void  GA::GeneticAlgorithm::createChildPositionMessage()
{
if (this->infoMessageGenerationEnabled == false || this->startValues_->stepOutputRichTextBox_ == nullptr ) return;

this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Green ;
this->startValues_->stepOutputRichTextBox_->AppendText( "=-=-= Child " + child + " =-=-= \n =-=-=-=-=-=-=-=-=-=- \n" );

this->startValues_->stepOutputRichTextBox_->ScrollToCaret();
}

/*
 *If messageGeneration is enabled and the this->startValues_->stepOutputRichTextBox_ controll 
 * is not nullptr we create a text that shows the movements of the algorithm. 
 */
void GA::GeneticAlgorithm::createSelectionMessage()
{
if (this->infoMessageGenerationEnabled == false || this->startValues_->stepOutputRichTextBox_ == nullptr ) return;

	this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Blue ;

	if ( startValues_->SELECTION_TYPE_ == StartValues::ROULETTE_SELECTION )
		{
		this->startValues_->stepOutputRichTextBox_->AppendText( "=-=-= Roulette Selection =-=-= \n" );
		}

	if ( startValues_->SELECTION_TYPE_ == StartValues::TOURNAMENT_SELECTION )
		{
		this->startValues_->stepOutputRichTextBox_->AppendText( "=-=- Tournament Selection -=-= \n" );
		}

	if ( startValues_->SELECTION_TYPE_ == StartValues::RANK_SELECTION )
		{
		this->startValues_->stepOutputRichTextBox_->AppendText( "=-=-=-= Rank Selection =-=-=-= \n" );
		}

this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black ;
this->startValues_->stepOutputRichTextBox_->AppendText( "Selected Parents: " + p1 + " , " + p2 + "\n" );

this->startValues_->stepOutputRichTextBox_->ScrollToCaret();
}


/*
 *If messageGeneration is enabled and the this->startValues_->stepOutputRichTextBox_ controll 
 * is not nullptr we create a text that shows the movements of the algorithm. 
 */
void GA::GeneticAlgorithm::createCrossoverMessage()
{
int i ; 
int colorLengthPos;
int colorStartPos;
int secColorStartPos ; 

if (this->infoMessageGenerationEnabled == false || this->startValues_->stepOutputRichTextBox_ == nullptr ) return;


this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Blue ;


	if (startValues_->CPOINTS_ < 1 )
		this->startValues_->stepOutputRichTextBox_->AppendText( "=-=-= Uniform Crossover -==-=-= \n" );
	else if (startValues_->CPOINTS_ == 1 )
		this->startValues_->stepOutputRichTextBox_->AppendText( "=-=-= One point Crossover =-=-= \n" );
	else if (startValues_->CPOINTS_ > 1 )
		this->startValues_->stepOutputRichTextBox_->AppendText( "=-=-= Multi Point Crossover =-= \n" );

this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black ;


	if ( crossoverAction_ == CROSSOVER_HAPPENED ) 
		{
		for (i = 0 ; i < startValues_->CPOINTS_; i++)
			{

			this->startValues_->stepOutputRichTextBox_->AppendText( " \nCrossover point no: " + i + "\n" );
			this->startValues_->stepOutputRichTextBox_->AppendText( "Chrom: " + geneticMethods_->crossoverChrom[i] + "" );
			this->startValues_->stepOutputRichTextBox_->AppendText( "  Chrom position: " +  (geneticMethods_->crossoverChromPos[i] + 1)  + "\n" );

			}
		}
	else if (crossoverAction_ == CROSSOVER_P1_BECAME_CHILD ) //message_ = message_ + "Parent1 became child... \n";
							this->startValues_->stepOutputRichTextBox_->AppendText( "Parent1 became child... \n" );

	else if (crossoverAction_ == CROSSOVER_P2_BECAME_CHILD ) //message_ = message_ + "Parent2 became child... \n";
							this->startValues_->stepOutputRichTextBox_->AppendText( "Parent2 became child... \n" );

		this->startValues_->stepOutputRichTextBox_->AppendText( "\n Parent1: \n" );
		this->startValues_->stepOutputRichTextBox_->AppendText( "Geno: " );

		for( i=0 ; i<startValues_->VARS_ ; i++)	
				{
				this->startValues_->stepOutputRichTextBox_->AppendText( parents_[p1]->geno_[i] + " " );
				}
		
		this->startValues_->stepOutputRichTextBox_->AppendText( "Geno to binary: " );

		this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::CornflowerBlue ;
		for( i=0 ; i<startValues_->VARS_ ; i++)	
				{
				this->startValues_->stepOutputRichTextBox_->AppendText( geneticMethods_->Int2Bin (parents_[p1]->geno_[i] ) + " " );
				}
		this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black;

		this->startValues_->stepOutputRichTextBox_->AppendText( "\n Parent2: \nGeno: " );
		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText(  parents_[p2]->geno_[i] + " " );
			}
		this->startValues_->stepOutputRichTextBox_->AppendText( "Geno to binary: " );

		this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Brown ;
		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText(  geneticMethods_->Int2Bin (parents_[p2]->geno_[i]) + " " );
			}
		this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black ;

	this->startValues_->stepOutputRichTextBox_->AppendText( "\n Child: \nGeno: " );

		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText( population_[child]->geno_[i] + " " );
			}
		
		this->startValues_->stepOutputRichTextBox_->AppendText( "Geno to binary: " );
		colorStartPos = this->startValues_->stepOutputRichTextBox_->Text->Length ; 
		secColorStartPos = colorStartPos ; 

		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText( geneticMethods_->Int2Bin (population_[child]->geno_[i]) + " " );
			}


		
	  if (crossoverAction_ == CROSSOVER_P1_BECAME_CHILD ) 
		{
		this->startValues_->stepOutputRichTextBox_->SelectionStart = colorStartPos ; 
		this->startValues_->stepOutputRichTextBox_->SelectionLength = this->startValues_->stepOutputRichTextBox_->Text->Length - colorStartPos ;
		this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::CornflowerBlue ;
		}
	  else if (crossoverAction_ == CROSSOVER_P2_BECAME_CHILD )
		{
		this->startValues_->stepOutputRichTextBox_->SelectionStart = colorStartPos ; 
		this->startValues_->stepOutputRichTextBox_->SelectionLength = this->startValues_->stepOutputRichTextBox_->Text->Length - colorStartPos ;
		this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Brown ;  
		}

	else if (crossoverAction_ == CROSSOVER_HAPPENED && startValues_->CPOINTS_ >= 1 )
	{
		for(i = 0 ; i < startValues_->CPOINTS_; i++ )
			{
			colorLengthPos = this->geneticMethods_->crossoverChrom[i] * this->startValues_->BITS_  +  this->geneticMethods_->crossoverChromPos[i] + 1 + geneticMethods_->crossoverChrom[i]; 
			
			this->startValues_->stepOutputRichTextBox_->SelectionStart = colorStartPos ; 
			this->startValues_->stepOutputRichTextBox_->SelectionLength = colorLengthPos ;

			colorStartPos = secColorStartPos + colorLengthPos ;

			if ( (i%2) == 0 )
				this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::CornflowerBlue ;
			else 
				this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Brown ;
			}

			colorLengthPos = this->startValues_->stepOutputRichTextBox_->Text->Length -  colorStartPos ;
			
			this->startValues_->stepOutputRichTextBox_->SelectionStart = colorStartPos ; 
			this->startValues_->stepOutputRichTextBox_->SelectionLength = colorLengthPos ;

			if ( (i%2) == 0 )
				this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::CornflowerBlue ;
			else  
				this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Brown ;

	}

	else if (crossoverAction_ == CROSSOVER_HAPPENED && startValues_->CPOINTS_ < 1 )
	{
		for(i = 0 ; i < (startValues_->BITS_ * startValues_->VARS_) ; i++ )
			{
				if (i == startValues_->BITS_)colorStartPos++;

				if (this->geneticMethods_->pos[i] == 1 )
					{
						this->startValues_->stepOutputRichTextBox_->SelectionStart = colorStartPos ; 
						this->startValues_->stepOutputRichTextBox_->SelectionLength = colorStartPos + 1 ;
						this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::CornflowerBlue ;  
					}
				else if (this->geneticMethods_->pos[i] == 2 )
					{
						this->startValues_->stepOutputRichTextBox_->SelectionStart = colorStartPos ; 
						this->startValues_->stepOutputRichTextBox_->SelectionLength = colorStartPos + 1 ;
						this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Brown ;  
					}
			colorStartPos++; 
			}
	}

		this->startValues_->stepOutputRichTextBox_->AppendText("\n");
		this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black ; 

		this->startValues_->stepOutputRichTextBox_->ScrollToCaret();
 }


/*
 *If messageGeneration is enabled and the this->startValues_->stepOutputRichTextBox_ controll 
 * is not nullptr we create a text that shows the movements of the algorithm. 
 */
void  GA::GeneticAlgorithm::createMutationMessage()
{
int i ; 
int colorStartPos ; 
int secColorStartPos ; 

if (this->infoMessageGenerationEnabled == false || this->startValues_->stepOutputRichTextBox_ == nullptr ) return;


	this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Blue ;
	
	this->startValues_->stepOutputRichTextBox_->AppendText( "=-=-= Mutation of child =-=-= \n" ) ;
	this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black ;


	this->startValues_->stepOutputRichTextBox_->AppendText( "Mutation total points: "+ geneticMethods_->mutationPoints_ + "\n " ) ;

	if ( geneticMethods_->mutationPoints_ > 0)
		{
		for (i = 0 ; i < geneticMethods_->mutationPoints_ ; i++)
			{
			this->startValues_->stepOutputRichTextBox_->AppendText( " \npoint no: " + i + "\n" ) ;
			this->startValues_->stepOutputRichTextBox_->AppendText("Chrom: " + geneticMethods_->mutationChroms_[i] + "" ) ;
			this->startValues_->stepOutputRichTextBox_->AppendText( "  ChromPosition: " +( geneticMethods_->mutationChromPosis_[i] + 1 )+ "\n" ) ;
			}

		this->startValues_->stepOutputRichTextBox_->AppendText( "Before: \nGeno: " ) ;
		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText( tmpAtom_.geno_[i] + " " ) ;
			}

		this->startValues_->stepOutputRichTextBox_->AppendText( "Geno in binary: " ) ;
		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText( geneticMethods_->Int2Bin(tmpAtom_.geno_[i]) + " ") ;
			}

		this->startValues_->stepOutputRichTextBox_->AppendText( "\nAfter: \nGeno: ") ;

		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText(  population_[child]->geno_[i] + " ") ;
			}

	
		this->startValues_->stepOutputRichTextBox_->AppendText( "Geno to binary: " ) ;
		
		colorStartPos = this->startValues_->stepOutputRichTextBox_->Text->Length ; 

		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText(geneticMethods_->Int2Bin( population_[child]->geno_[i] ) + " " ) ;
			}

		this->startValues_->stepOutputRichTextBox_->AppendText("\n" ) ;
		}

	for(i = 0 ; i < geneticMethods_->mutationPoints_ ; i++ )
			{
			secColorStartPos = this->geneticMethods_->mutationChroms_[i] * this->startValues_->BITS_  +  this->geneticMethods_->mutationChromPosis_[i]  + geneticMethods_->mutationChroms_[i]; 

			this->startValues_->stepOutputRichTextBox_->SelectionStart = colorStartPos + secColorStartPos ; 
			this->startValues_->stepOutputRichTextBox_->SelectionLength = 1 ;
			this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Red ;  
			}

	this->startValues_->stepOutputRichTextBox_->ScrollToCaret();
}


/*
 *If messageGeneration is enabled and the this->startValues_->stepOutputRichTextBox_ controll 
 * is not nullptr we create a text that shows the movements of the algorithm. 
 */
void  GA::GeneticAlgorithm::createChildEvaluationMessage()
{
int i ; 

if (this->infoMessageGenerationEnabled == false || this->startValues_->stepOutputRichTextBox_ == nullptr ) return;

	this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Blue ; 
	this->startValues_->stepOutputRichTextBox_->AppendText( "=-=-= Child Evaluation =-=-=  \n" ) ;
	this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black; 

	this->startValues_->stepOutputRichTextBox_->AppendText( "Geno: " ) ;

		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText( population_[child]->geno_[i] + " " ) ;
			}

		this->startValues_->stepOutputRichTextBox_->AppendText( "Feno: " ) ;
		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText( population_[child]->pheno_[i] + " "  ) ;
			}

		this->startValues_->stepOutputRichTextBox_->AppendText( "Fitness: " ) ;
		
		this->startValues_->stepOutputRichTextBox_->AppendText( population_[child]->fitness_  + "\n" ) ;
		this->startValues_->stepOutputRichTextBox_->ScrollToCaret();
}

/*
 *If messageGeneration is enabled and the this->startValues_->stepOutputRichTextBox_ controll 
 * is not nullptr we create a text that shows the movements of the algorithm. 
 */
void  GA::GeneticAlgorithm::createHillClimbMessage()
{
int i ;

if (this->infoMessageGenerationEnabled == false || this->startValues_->stepOutputRichTextBox_ == nullptr ) return;


	this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Blue ; 
	this->startValues_->stepOutputRichTextBox_->AppendText(  "=-=-= Hill Climb =-=-= \n"  ) ;
	this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black; 

	this->startValues_->stepOutputRichTextBox_->AppendText(/*"Best Child: " + best + */"Before: Geno: "  ) ;

		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText(  tmpAtom_.geno_[i] + " " ) ;
			}


		this->startValues_->stepOutputRichTextBox_->AppendText(  "Feno: " ) ;

		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText(  tmpAtom_.pheno_[i] + " " ) ;
			}

		this->startValues_->stepOutputRichTextBox_->AppendText(  "Fitness: " + tmpAtom_.fitness_ + "\n After: Geno: ") ;

		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText(  population_[child]->geno_[i] + " ") ;
			}

		this->startValues_->stepOutputRichTextBox_->AppendText( "Feno: " ) ;
		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->stepOutputRichTextBox_->AppendText( population_[child]->pheno_[i] + " " ) ;
			}

		this->startValues_->stepOutputRichTextBox_->AppendText("Fitness: " + population_[child]->fitness_ + "\n") ;
		this->startValues_->stepOutputRichTextBox_->ScrollToCaret();
}

/*
 *If messageGeneration is enabled and the this->startValues_->stepOutputRichTextBox_ controll 
 * is not nullptr we create a text that shows the movements of the algorithm. 
 */
void  GA::GeneticAlgorithm::createPopulationReplacementMessage()
{
int i ; 

if (this->genMessageGenerationEnabled == false || this->startValues_->populationOutputRichTextBox_ == nullptr ) return;


this->startValues_->populationOutputRichTextBox_->SelectionColor = System::Drawing::Color::Blue ; 
this->startValues_->populationOutputRichTextBox_->AppendText("=-=-= Population Report  =-=-= \n") ;
this->startValues_->populationOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black;

this->startValues_->populationOutputRichTextBox_->AppendText("Generation " + this->gen + "\n ") ;
	for (int j = 0 ; j < startValues_->N_ ; j++)
		{
		this->startValues_->populationOutputRichTextBox_->AppendText("Geno: ") ;

		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->populationOutputRichTextBox_->AppendText( parents_[j]->geno_[i] + " ") ;
			}

		this->startValues_->populationOutputRichTextBox_->AppendText( "Feno: " ) ;
		for( i=0 ; i<startValues_->VARS_ ; i++)	
			{
			this->startValues_->populationOutputRichTextBox_->AppendText( parents_[j]->pheno_[i] + " " ) ;
			}

		this->startValues_->populationOutputRichTextBox_->AppendText( "Fitness: " + parents_[j]->fitness_ + "\n" ) ;
		}

	this->startValues_->populationOutputRichTextBox_->ScrollToCaret();
}


/*
 *If messageGeneration is enabled and the this->startValues_->stepOutputRichTextBox_ controll 
 * is not nullptr we create a text that shows the movements of the algorithm. 
 */
void  GA::GeneticAlgorithm::createFinishMessage()
{
if (this->infoMessageGenerationEnabled == false || this->startValues_->stepOutputRichTextBox_ == nullptr ) return;

this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Red ; 
this->startValues_->stepOutputRichTextBox_->AppendText("=-=-= Genetic algorithm's evolution finished =-=-= ") ;
this->startValues_->stepOutputRichTextBox_->SelectionColor = System::Drawing::Color::Black;
this->startValues_->stepOutputRichTextBox_->ScrollToCaret();
}

void  GA::GeneticAlgorithm::displayGenerationInLabel()
{
if (this->startValues_->generationLabel_ == nullptr ) return;

this->startValues_->generationLabel_->Text = "Gen: " + this->gen ;
}

void GA::GeneticAlgorithm::displayChosenAtomInLabel(int atomPos)
{
if (this->startValues_->generationLabel_ == nullptr ) return;

this->startValues_->chosenAtomLabel_->Text =

"Selected atom: Geno: " +  this->geneticMethods_->Int2Bin( this->parents_[atomPos]->geno_[0] ) 
	 + " " + this->geneticMethods_->Int2Bin( this->parents_[atomPos]->geno_[1] ) 
	 + " Pheno: " + this->parents_[atomPos]->pheno_[0] + " " + this->parents_[atomPos]->pheno_[1]  
	 + " Fitness: " + this->parents_[atomPos]->fitness_ ; 
}



void  GA::GeneticAlgorithm::paintAtoms()
{
	int bestAtomPos = 0 ;

	bestAtomPos = this->geneticMethods_->FindBest( this->parents_ );

	for (i = 0 ; i <  this->parents_->Count ; i ++ ) 
				{
				parents_[i]->paint();
				}

	parents_[bestAtomPos]->paintBest();
}

void GA::GeneticAlgorithm::setAtomsPixelPositions()
{
int count = parents_->Count;
for (i = 0 ; i <  count ; i ++ ) 
				parents_[i]->setPixelPositions(this->startValues_);
}


void GA::GeneticAlgorithm::displayAtomsValues( GLfloat xMousePos, GLfloat yMousePos, GLfloat zMousePos )
{
double mouseX = 0 , mouseY = 0 , mouseZ = 0 ; 
double mouseXplus = 0 , mouseYplus = 0 , mouseZplus = 0  ; 
int found = 0 ;


for (i = 0 ; i <  this->parents_->Count ; i ++ ) 
	{
	mouseX = (parents_[i]->x_ - 0.2) ;
	if(xMousePos >= mouseX) found ++; 

	mouseXplus = (parents_[i]->x_ + 0.2);
	if(xMousePos <= mouseXplus) found ++; 


	mouseY = (parents_[i]->y_ - 0.2);
	if(yMousePos >= mouseY) found ++; 

	mouseYplus = (parents_[i]->y_ + 0.2);
	if(yMousePos <= mouseYplus) found ++; 


	mouseZ =  (parents_[i]->z_ - 0.2)  ;
	if(zMousePos >= mouseZ) found ++; 

	mouseZplus = (parents_[i]->z_ + 0.2) ;
	if(zMousePos <= mouseZplus) found ++; 

	if (found >= 6)
		{

			this->displayChosenAtomInLabel(i) ;

		}
	
	found = 0 ; 
	}


}
