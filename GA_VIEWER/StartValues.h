#pragma once

ref class StartValues
{
	/*
	 *Graph Start Values 
	 */
public:
	float xStart_;
	float xEnd_ ;
	float zStart_;
	float zEnd_ ;

	float xLength_ ;
	float zLength_ ;

	float xStep_ ; 
	float zStep_ ;

	System::String^ fx_  ; 
	
	int readyFunctionNum_;

public:

	/*
	 *Genetic Algorithm Start Values 
	 */
	static const int ROULETTE_SELECTION = 0; 
	static const int TOURNAMENT_SELECTION = 1; 
	static const int RANK_SELECTION = 2; 


	int VARS_; // Always 2 because we are on 3d 
	int BITS_; //Bits
	int GEN_ ; //Generations
	int N_ ; // Population
	int CPOINTS_ ;  //Crossover points for the multipointCrossover()
	int TPARENTS_;
	double CPROB_; //crossover probability 0..1
	double MPROB_; // Mutation probability 0..1
	int SELECTION_TYPE_ ; 

	/*
	 *RichTextBoxes' pointers for the genetic algorithm's results.
	 */
	System::Windows::Forms::RichTextBox^  stepOutputRichTextBox_;
	System::Windows::Forms::RichTextBox^  populationOutputRichTextBox_;
	System::Windows::Forms::Label^ generationLabel_;
	System::Windows::Forms::Label^ chosenAtomLabel_;

	/*
	 *Constructors
	 */
	StartValues(float xStart , float xEnd , float zStart  , float zEnd , System::String^ fx  );
	StartValues(float xStart , float xEnd , float zStart  , float zEnd , System::String^ fx ,int readyFunctionNum  );
	~StartValues(void);

	/*
	 *operator=
	 */
	void operator=(StartValues startValues); 

	/*
	 *Inits the Genetic Algoriths start values
	 */
	void setGeneticStartValues(int BITS  , int GEN  ,int N 
		, int CPOINTS , double CPROB ,double MPROB , int SELECTION_TYPE); 

	/*
	 *Set's the rich text boxes pointers to point to our visual components in which we will receive the results of the algorithm
	 */
	void setRichTextBoxes(System::Windows::Forms::RichTextBox^  stepOutputRichTextBox , System::Windows::Forms::RichTextBox^  populationOutputRichTextBox ); 
	void setGenerationLabel(System::Windows::Forms::Label^ generationLabel);
	void setChosenAtomLabel(System::Windows::Forms::Label^ chosenAtomLabel);
	/*
	 **Get functions***
     */
	float getxStart();
	float getxEnd();
	float getzStart();
	float getzEnd();

	float getxLength();
	float getzLength();
	System::String^ getfx();

	float getxStep();
	float getzStep();
    int getMathFunctionNumber();
	
	int getBITS();
	int getGEN();  
	int getN(); 
	int getCPOINTS(); 
	double getCPROB();
	double getMPROB(); 
	int getSELECTION_TYPE(); 

	

	

};
