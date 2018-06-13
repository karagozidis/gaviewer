#include "StdAfx.h"
#include "Atom.h"
GA::Atom::Atom(void)
 {
 this->geno_ = gcnew array<int>(2);
 this->pheno_ = gcnew array<double>(2);

 for (int i = 0 ; i < 2 ; i++ )
		{
			this->geno_[i] = 0;
			this->pheno_[i] = 0;
		}
 this->fitness_ = 0 ;
 }

void GA::Atom::operator=(Atom^ atom)
 {
 int i = 0 ;

 for ( i = 0 ; i < 2 ; i++ )
		{
			this->geno_[i] = atom->geno_[i];
			this->pheno_[i] = atom->pheno_[i];
		}
 this->fitness_ = atom->fitness_ ;

 }


GA::Atom::~Atom(void)
 {
 }


void GA::Atom::setPixelPositions(StartValues^ startValues) 
 {
 /*
  *Normalize yValues to the pixels and Fulfill the yPixelValues[100][100] table
  */
	float normXDist = ( this->pheno_[0] - startValues->xStart_ ) / (startValues->xEnd_ - startValues->xStart_) ;
	float xPixelDist = Graph::xPixelEnd_ - Graph::xPixelStart_ ;
	x_ = xPixelDist * normXDist ; 
	x_ = x_ +  Graph::xPixelStart_ ; 

	
	
	float normZDist = (pheno_[1] - startValues->zStart_ )  / (startValues->zEnd_ - startValues->zStart_ ) ;
	float zPixelDist = Graph::zPixelEnd_ - Graph::zPixelStart_ ;
	z_ = zPixelDist * normZDist ; 
	z_ = z_ +  Graph::zPixelStart_ ; 


	float normYDist = (this->fitness_ -  Graph::yMin_ ) / ( Graph::yMax_ - Graph::yMin_ ) ;
	float yPixelDist = Graph::yPixelEnd_ - Graph::yPixelStart_;
	y_ = yPixelDist * normYDist ; 
	y_ = y_ +  Graph::yPixelStart_ ; 

 }

void GA::Atom::paint()
{
	glTranslatef(x_ , y_ , z_ );
	glColor3f(1,0.5,1);
	glutSolidCube(0.2);
	glTranslatef(-x_ , -y_ , -z_ );
}

void GA::Atom::paintBest()
{
	glTranslatef(x_ , y_ , z_ );
	glColor3f(1,1,0.5);
	glutSolidCube(0.2);
	glTranslatef(-x_ , -y_ , -z_ );
}