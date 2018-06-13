#include "StdAfx.h"
#include "GeneticMethods.h"

GA::GeneticMethods::GeneticMethods(StartValues^ startValues)
{

	this->parser_ = gcnew ExprParser::Parser();
	this->parser_->createBuffer(startValues->fx_);

	this->xFrom_ = startValues->getxStart();
	this->xTo_ = startValues->getxEnd();

	this->zFrom_ = startValues->getzStart();
	this->zTo_ = startValues->getzEnd();


	N=startValues->N_;
	BITS =startValues->BITS_;
	CPROB= startValues->CPROB_;
	MPROB=startValues->MPROB_;
	GEN =startValues->GEN_;
	VARS=2 ;
	TPARENTS=startValues->TPARENTS_;
	CPOINTS=startValues->CPOINTS_;

}

GA::GeneticMethods::~GeneticMethods(void)
{
	delete this->mutationChroms_ ;
	delete this->mutationChromPosis_ ;
	delete this->pos;
	//delete this->mathFunction_ ;
	delete this->crossoverChrom ;
	delete this->crossoverChromPos ;
}


double GA::GeneticMethods::rnd(void)
{
//return (double)rand()/RAND_MAX;
	return RandObj->NextDouble();
}
//====================================================================================
void GA::GeneticMethods::Geno2Pheno(Atom^ a) 
{

	double xDist = this->xTo_ - this->xFrom_ ;
	double zDist = this->zTo_ - this->zFrom_ ; 

	a->pheno_[0]=(double)a->geno_[0]/(Math::Pow((double)2,(double)BITS)-1)* xDist  ;
	a->pheno_[1]=(double)a->geno_[1]/(Math::Pow((double)2,(double)BITS)-1)* zDist  ;

    a->pheno_[0] = this->xFrom_ + a->pheno_[0] ; 
	a->pheno_[1] = this->zFrom_ + a->pheno_[1] ; 

}

//====================================================================================
void GA::GeneticMethods::Fitness(Atom^ a)
{
   Geno2Pheno(a);
   //a.fitness_ = this->mathFunction_->calculate( (float)a.pheno_[0] ,(float) a.pheno_[1] );
   //a->fitness_ = (  (float)a->pheno_[0] * (float) a->pheno_[1]  )  ; 
   this->parser_->setXY( (float)a->pheno_[0] ,(float) a->pheno_[1] );
   a->fitness_ = this->parser_->calculateExpression();
}
//====================================================================================
/*void GA::GeneticMethods::Display( System::Collections::Generic::List<Atom^>^ p ) 
{
int i,j;
for(i=0;i<N;i++)
   {
      printf("Atom %2i ",i);
      for(j=0;j<VARS;j++)
		  printf("%6i ",p[i]->geno_[j] ) ; 
      for(j=0;j<VARS;j++)
		  printf("%10.7lf ",p[i]->pheno_[j]); 
      printf("f=%10.7lf\n",p[i]->fitness_); 
   }//for
}*/
//====================================================================================
int GA::GeneticMethods::FindBest( System::Collections::Generic::List<Atom^>^ f )
{
int i=0,best=0;
double bestFitness = f[0]->fitness_; 

   for(i=1;i<N;i++)
   {
      if (f[i]->fitness_ > bestFitness )
      {
		 bestFitness = f[i]->fitness_;
         best=i;
      }
   }
   return best;
}
//====================================================================================
int GA::GeneticMethods::FindWorst( System::Collections::Generic::List<Atom^>^ f )
{
int i=0,worst=0;
double worstFitness = f[0]->fitness_; 

   for(i=1;i<N;i++)
   {
      if (f[i]->fitness_ < worstFitness )
      {
		 worstFitness = f[i]->fitness_;
         worst=i;
      }
   }
   return worst;
}
//====================================================================================
int GA::GeneticMethods::RouletteSelection( System::Collections::Generic::List<Atom^>^ f ) 
{
double sum=0,sumrnd=0 ,sum2=0;
int i = 0;

for(i=0;i<N-1;i++)
sum+=f[i]->fitness_ - this->FindWorst(f) ;//- Graph::yMin_ ; 

sumrnd=rnd()*sum;

for(i=0;i<N-1;i++)
	{
		sum2 += f[i]->fitness_ - this->FindWorst(f) ;// - Graph::yMin_ ;
	if(sum2>sumrnd) break;
	}

return i;
}
//====================================================================================
GA::Atom^ GA::GeneticMethods::Crossover( GA::Atom^ p1 , GA::Atom^ p2)
{
int i=0,monada_aristera=0,monada_sth_thesh=0;
GA::Atom^ child = gcnew Atom();
int mask=0;

   pos = gcnew array<int>(CPOINTS) ; 
   crossoverChrom = gcnew array<int>(1) ; 
   crossoverChromPos = gcnew array<int>(1) ; 

   pos[0]=rand() % (int)(BITS*VARS-1);
   crossoverChrom[0]=pos[0]/BITS;
   crossoverChromPos[0]=pos[0]%BITS;
   //prin apo to chrom
   for(i=0;i<crossoverChrom[0];i++)
      child->geno_[i]=p1->geno_[i];
   //meta to chrom
   for(i=crossoverChrom[0]+1;i<VARS;i++)
      child->geno_[i]=p2->geno_[i];
   //panw sto chromosoma

      monada_aristera=  1<<(BITS-1);
      monada_sth_thesh=monada_aristera >> crossoverChromPos[0];
      mask=monada_sth_thesh-1;

      child->geno_[crossoverChrom[0]] = (p1->geno_[crossoverChrom[0]] & ~mask) | (p2->geno_[crossoverChrom[0]] & mask);

   delete this->pos;
  // delete this->crossoverChrom;
//   delete this->crossoverChromPos;

   return child;
}
//====================================================================================
 void GA::GeneticMethods::Mutation(Atom^ x, double prob)
{
int i,mask;
double shmeia, rest;

   shmeia=BITS*VARS*prob;
   mutationPoints_ =(int)shmeia;
   rest=shmeia-mutationPoints_;

   if(rnd()<rest) mutationPoints_++;
  
pos = gcnew array<int>(mutationPoints_);
mutationChroms_ = gcnew array<int>(mutationPoints_);
mutationChromPosis_ = gcnew array<int>(mutationPoints_ ); 

   for (i=0;i<mutationPoints_;i++)
   {
      pos[i]= rand() % (BITS * VARS);
	  mutationChroms_[i] = pos[i]/BITS;
	  mutationChromPosis_[i] = pos[i]%BITS;
     // monada_aristera= 1 << (BITS-1);
      mask= (1<<(BITS-1)) >> mutationChromPosis_[i];
      x->geno_[ mutationChroms_[i]]=x->geno_[ mutationChroms_[i] ]^mask;
   }

delete this->pos ;

}
//====================================================================================
void GA::GeneticMethods::HillClimb(Atom^ x)
{
int steps[4]={100,1,-100,-1};
int i=0,j=0,k=0,original=0;
double origfeno=0,qual=0;

for (j=0;j<VARS;j++)
        {
        original=x->geno_[j];
        origfeno=x->pheno_[j];
        qual=x->fitness_;
        for (i=0;i<4;i++)
                {
                if(   ( (double)x->geno_[j]+steps[i] ) >= 0 && ( (double)x->geno_[j]+steps[i] ) < Math::Pow((double)2,(double)BITS)  )
                        {
                        x->geno_[j]+=steps[i];
                        this->Fitness(x);
					
                        if(x->fitness_<qual)
                                {//Restore
                                x->geno_[j]=original;
                                x->pheno_[j]=origfeno;
                                x->fitness_=qual;
                                }
                        else
                                {
                                original=x->geno_[j];
                                origfeno=x->pheno_[j];
                                qual=x->fitness_;
                                }
                        }//if
               // getch();
                }//for i
        }//for j
}
//===================================================================
System::String^ GA::GeneticMethods::Int2Bin(int x)
{
   int mask,i;
   System::String^ s="";
   mask=1 << (BITS-1);
   for (i=0;i<BITS;i++)
      {
         if(x & mask)
            s+="1";
         else
            s+="0";
         mask=mask>>1;
      }
	return s; 
}

//===================================================================
int GA::GeneticMethods::tournamentSelection( System::Collections::Generic::List<Atom^>^ f )
{
 //global variable k = 3 ;

	int curPos = 0 ; 
    array<int>^ positions ; 
	int cutPos = 0;
	double curFitness = 0 ;

double sum=0,sumrnd = 0 ,sum2=0;
int i = 0;

positions =  gcnew array<int>(TPARENTS);
for (i = 0 ; i <  TPARENTS ; i++ )
	{
		positions[i] = rand() % N ;   // 0 .. N-1
	}

curFitness = f[positions[0] ]->fitness_ ;
cutPos = 0 ;
for(i=1;i<TPARENTS-1;i++)
	{
		if( f[ positions[i]]->fitness_ > curFitness  )
			{
			curFitness = f[ positions[i] ]->fitness_ ;
			cutPos = i;
			}
	}

 return positions[cutPos];


/*
for(i=0;i<TPARENTS-1;i++)
	sum+=f.at(positions[i]).fitness_ - Graph::yMin_ ; 

sumrnd=rnd()*sum;

for(i=0;i<N-1;i++)
 {
	 sum2 += f.at(positions[i]).fitness_ - Graph::yMin_   ;
 if(sum2>sumrnd)
  break;
 }

delete positions;
return positions[i];
*/
}

//===================================================================

int GA::GeneticMethods::rankSelection( System::Collections::Generic::List<Atom^>^ f ) 
{
Atom tmpAtom;
int tmpPos = 0;
array<double>^ percRankArray ; 
array<int>^ startArray;
int i = 0 , j = 0 ;
int maxPos = 0 ;
double max  = 0 ;
int rankSum = 0 ; 
double sum = 0,sumrnd = 0;

percRankArray = gcnew array<double>(N);
startArray = gcnew array<int>(N);

for (i = 0 ; i < N ; i++ )
	{
		
	startArray[i] = i ;
	}

for(j=0;j<N;j++)
	{
	max =f[j]->fitness_ ; // f[j].fitness_;
	maxPos = j ;
	

	//1. Short Array 
	for(i=j;i<N;i++)
		{
			if(max < f[i]->fitness_ ) //f[i]->fitness_ ) 
				{
				maxPos = i; 
				max= f[i]->fitness_ ; //f[i]->fitness_;
				}
		}

    tmpPos = startArray[j]; 
	startArray[j] = startArray[maxPos];
	startArray[maxPos] = tmpPos; 

	tmpAtom.fitness_  = f[j]->fitness_ ; 
	f[j]->fitness_ = f[maxPos]->fitness_  ; 
	f[maxPos]->fitness_ = tmpAtom.fitness_ ;
	}

	//2. Calculate percentage value 
for(i = 0 ; i < N ; i++ )  rankSum += (i+1) ;  

for(i=0;i<N;i++)
	{
	percRankArray[i] = (double)( N - (i+1) + 1) /(double) rankSum  ; 
	}

	//3. Find Chosen by the percentage rank value  


sumrnd= GA::GeneticMethods::rnd();
for(i=0;i<N-1;i++)
 {
 sum += percRankArray[i] ;
 if(sum > sumrnd)
  break;
 }

delete percRankArray ;

return startArray[i];
}

//===================================================================

GA::Atom^ GA::GeneticMethods::multiPointCrossover( GA::Atom^ p1 , GA::Atom^ p2 )
{
GA::Atom^ child = gcnew Atom() ; 
int i = 0  , j = 0, k = 0 ;
int extra = 0 ; 
int rest = 0 ;
int monada_aristera = 0 , monada_sth_thesh = 0  , mask = 0 ;



int upNow = 0  , mirror = 0; 
int prevMask = 0 ;

pos = gcnew array<int>(CPOINTS) ;  
crossoverChrom = gcnew array<int>(CPOINTS) ; 
crossoverChromPos = gcnew array<int>(CPOINTS) ; 


rest =  (BITS*VARS-1) % CPOINTS ;


  //***1.Init crossover positions***
  //********************************
for( i = 0 ; i < CPOINTS-1 ; i++ )
	{
	 pos[i] = rand() % (int) ( (BITS*VARS-1)  / CPOINTS ) ; // 0 .... 12
	}

	 pos[i] = rand() % (int) ( ( (BITS*VARS-1)  / CPOINTS ) + rest ) ; // 0 .... 13


	 //** Find positions , chroms of position and positions in each chrom **// 
	 //***********************************************************************
	int base = 0 ;
for( i = 0 ; i < CPOINTS ; i++ )
	{
	crossoverChrom[i] = ( pos[i] + base ) / BITS ; 
	crossoverChromPos[i] = ( pos[i] + base ) % BITS ; 
	base = base + (  (BITS*VARS-1) / CPOINTS  ) ;
	}


	//**  Do before the first chosen chrome  **//
	//*******************************************
for (i = 0 ; i < crossoverChrom[0] ; i++ )
	{
		child->geno_[i] = p1->geno_[i] ; 
	}

	

	//**  Do  between the chosen chromes  **//
    //****************************************
for (i = 0 ; i < CPOINTS-1 ; i++ )
 for (j = crossoverChrom[i]+1 ; j < crossoverChrom[i+1]   ; j++ )
	{
		if ( (i%2) == 0  ) child->geno_[j] = p2->geno_[j] ; 
		else child->geno_[j] = p1->geno_[j] ;
	}

	//**  Do after the last chosen chrome  **//
    //*****************************************
for (i = crossoverChrom[ CPOINTS-1 ] + 1 ; i < VARS  ; i++ )
	{
		if ( (CPOINTS%2) == 0  ) child->geno_[i] = p1->geno_[i] ; 
		else child->geno_[i] = p2->geno_[i] ;
	}


	//**  Do in the chosen chromes  **//
	//**********************************
for (i = 0 ; i < CPOINTS ; i++ )
	{
		if (upNow == 0 ) upNow = 1 ;
		else if (upNow == 1 )upNow = 0 ; 

	  mask = 0 ; 
	  monada_aristera = 0 ;
	  monada_sth_thesh = 0 ;

	  monada_aristera=  1<<(BITS-1);
      monada_sth_thesh=monada_aristera >> crossoverChromPos[i] ;
      mask=monada_sth_thesh-1;

	  mask = mask ^ prevMask ;	


	  if (  mirror == 0  )//if ( (i%2) == 0  )
      child->geno_[ crossoverChrom[i] ]=(p1->geno_[crossoverChrom[i] ] & ~mask )|( p2->geno_[ crossoverChrom[i] ] & mask);
	  else 
	  child->geno_[ crossoverChrom[i] ]=(p2->geno_[crossoverChrom[i] ] &  ~mask)|( p1->geno_[ crossoverChrom[i] ] & mask);


	  if ( crossoverChrom[i] == crossoverChrom[i+1] )
		{
			prevMask = mask ; //mask = 0 ; 
		}
	  else 
		{
			prevMask = 0 ; 
			if (upNow == 1 ) mirror = 1 ;
			else if (upNow == 0 ) mirror = 0 ; 
		}

	

	}

delete this->pos;
//delete this->crossoverChrom;
//delete this->crossoverChromPos;

return child ; 
}

//===================================================================

GA::Atom^ GA::GeneticMethods::uniformCrossover(GA::Atom^ p1,GA::Atom^ p2)
 {
   	 int bit = 1 << (BITS - 1);
	 int mask = 0 ; 
	 int var = 0 ; 
 int i  = 0 ,  j = 0 ; 
 Atom^ child = gcnew Atom() ;

 pos = gcnew array<int>(BITS*VARS) ; 
 
for (i = 0 ; i < VARS ; i++ )
	{
	child->geno_[i] =0 ;
	int bit = 1 << (BITS - 1);
	for (j = 0 ; j < BITS ; j++)
		{
		if (rnd() < 0.5)
			{
			pos[ i*BITS + j ] = 1 ; 
			mask = bit & p1->geno_[i];
			}
		else
			{
			pos[ i*BITS + j ] = 2 ; 
			mask = bit & p2->geno_[i];
			}


	    child->geno_[i] = child->geno_[i] | mask ; 

	    bit = bit >> 1; 
		}
	}

 delete pos;
 return child; 
 }