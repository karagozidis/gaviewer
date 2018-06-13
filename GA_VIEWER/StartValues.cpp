#include "StdAfx.h"
#include "StartValues.h"



   /*
    *Constructor 1 
	*/
StartValues::StartValues(float xStart , float xEnd , float zStart  , float zEnd , System::String^ fx)
 {
 xStart_ = xStart ;  
 xEnd_   = xEnd   ;
 zStart_ = zStart ; 
 zEnd_   = zEnd   ;
 fx_     = fx     ;

 xLength_ = xEnd_ - xStart ;
 zLength_ = zEnd_ - zStart_ ;

 xStep_ = xLength_ / 100 ;
 zStep_ = zLength_ / 100 ;
 readyFunctionNum_ = -1 ;

 VARS_ = 2 ;
TPARENTS_ = 3 ;  
BITS_ = 10;
GEN_ = 1000;
N_ = 40;
CPOINTS_ = 0 ;
CPROB_ = 0.5 ; 
MPROB_ = 0.5;
SELECTION_TYPE_ = 1;
 }

   /*
    *Constructor 2
	*/
StartValues::StartValues(float xStart , float xEnd , float zStart  , float zEnd , System::String^ fx, int readyFunctionNum )
 {
 xStart_ = xStart ;  
 xEnd_   = xEnd   ;
 zStart_ = zStart ; 
 zEnd_   = zEnd   ;
 fx_     = fx     ;

 xLength_ = xEnd_ - xStart ;
 zLength_ = zEnd_ - zStart_ ;

 xStep_ = xLength_ / 100 ;
 zStep_ = zLength_ / 100 ;
 readyFunctionNum_ = readyFunctionNum ;

VARS_ = 2 ;
TPARENTS_ = 3 ;  
BITS_ = 10;
GEN_ = 1000;
N_ = 40;
CPOINTS_ = 0 ;
CPROB_ = 0.5 ; 
MPROB_ = 0.5;
SELECTION_TYPE_ = 1;
 }


StartValues::~StartValues(void)
 {}

void StartValues::operator=(StartValues startValues)
{
	this->xStart_ = startValues.getxStart();
	this->xEnd_ = startValues.getxEnd() ;
	this->zStart_ = startValues.getzStart();
	this->zEnd_  = startValues.getzEnd();
	this->xLength_ = startValues.getxLength() ;
	this->zLength_ = startValues.getzLength() ;
	this->xStep_  = startValues.getxStep(); 
	this->zStep_  = startValues.getzStep();

	this->fx_  = startValues.getfx() ; 
	this->readyFunctionNum_ = startValues.getMathFunctionNumber();/////


	this->BITS_ = startValues.getBITS(); 
	this->GEN_  = startValues.getGEN(); 
	this->N_ = startValues.getN() ;
	this->CPOINTS_ = startValues.getCPOINTS() ;  
	this->CPROB_ = startValues.getCPROB(); 
	this->MPROB_ = startValues.getMPROB(); 
	this->SELECTION_TYPE_  = startValues.getSELECTION_TYPE(); 
}


void StartValues::setGeneticStartValues(int BITS  , int GEN  ,int N 
		, int CPOINTS , double CPROB ,double MPROB , int SELECTION_TYPE)
 {
VARS_ = 2 ;
TPARENTS_ = 3 ;  
BITS_ = BITS;
GEN_ = GEN;
N_ = N;
CPOINTS_ = CPOINTS ;
CPROB_ = CPROB ; 
MPROB_ = MPROB;
SELECTION_TYPE_ = SELECTION_TYPE;
 }


/*
 *Set's the rich text boxes pointers to point to our visual components in which we will receive the results of the algorithm
 */
void  StartValues::setRichTextBoxes(System::Windows::Forms::RichTextBox^  stepOutputRichTextBox , System::Windows::Forms::RichTextBox^  populationOutputRichTextBox )
	{
	this->stepOutputRichTextBox_ = stepOutputRichTextBox ; 
	this->populationOutputRichTextBox_ = populationOutputRichTextBox ;
	}

void  StartValues::setGenerationLabel(System::Windows::Forms::Label^ generationLabel)
	{
	this->generationLabel_ = generationLabel ; 
	}

void StartValues::setChosenAtomLabel(System::Windows::Forms::Label ^chosenAtomLabel)
	{
	this->chosenAtomLabel_ = chosenAtomLabel ; 
	}

/*
 **Get functions***
 */
float StartValues::getxStart()
 {
 	return xStart_;
 }

float StartValues::getxEnd()
 {
	return xEnd_;
 }
float StartValues::getzStart()
 {
	return zStart_;
 }

float StartValues::getzEnd()
 { 
	return zEnd_;
 }

float StartValues::getxLength()
 {
 return xLength_;
 }

float StartValues::getzLength()
 {
	 return zLength_;
 }
System::String^ StartValues::getfx()
 {
	 return fx_;
 }

float StartValues::getxStep()
 {
	 return xStep_;
 }

float StartValues::getzStep()
 {
	 return zStep_;
 }
  
int StartValues::getMathFunctionNumber()
{
	return readyFunctionNum_;
}


int StartValues::getBITS()
{
	return this->BITS_;
}

int StartValues::getGEN()
{
	return this->GEN_;
}
int StartValues::getN()
{
	return this->N_;
}

int StartValues::getCPOINTS()
{
	return this->CPOINTS_;
}

double StartValues::getCPROB()
{
	return this->CPROB_;
}

double StartValues::getMPROB()
{
	return this->MPROB_;
}

int StartValues::getSELECTION_TYPE()
{
	return this->SELECTION_TYPE_;
}
