#pragma once

#include "StartValues.h"
#include "Graph.h"
#include <windows.h>
#include <GL/gl.h>
#include <glut.h>

namespace GA
 {
ref class Atom
  {
  public:
	Atom(void);
	~Atom(void);

	array<int>^ geno_;
	array<double>^ pheno_;
	double fitness_;

	double x_ ;
	double y_ ;
	double z_ ; 
	

	void operator=(Atom^ atom); 

	void setPixelPositions(StartValues^ startValues) ; 
	void paint();
	void paintBest();
  };
}

