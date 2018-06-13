#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <glut.h>
#include <vcclr.h>

#include "StartValues.h"
#include "Parser.h"

using namespace std;


ref class Graph
{
private :
	ExprParser::Parser^ parser_ ; 
	StartValues^ startValues_ ;
	

	array<float,2>^ yValues_;
	array<float,2>^ yPixelValues_;
	array<float,3>^ grainPixelColor_;

   

    float xPixelPos_; 
    float zPixelPos_;

	float xPixelDist_ ; 
	float zPixelDist_ ;

	float xPixelStep_ ; 
	float zPixelStep_ ; 


	int x_ ;
	int z_ ;

	int xGrainLineNum_ ;
	int zGrainLineNum_ ;

	float schemeBlend_ ; 


	char* mx_my_mz_number_;
	char* x_my_mz_number_;
	char* mx_my_z_number_;
	char* x_my_z_number_;

	char* mx_y_mz_number_;
	char* x_y_mz_number_;
	char* mx_y_z_number_;
	char* x_y_z_number_;
	
	


public:
	
	static float yMin_ = 0;
	static float yMax_ = 0;
	
	static float xPixelStart_ = -10  ;
	static float xPixelEnd_   =  10  ;
	static float yPixelStart_ = -10  ;
	static float yPixelEnd_   =  10  ;
	static float zPixelStart_ = -10  ; 
	static float zPixelEnd_   =  10  ;

public:

	Graph(StartValues^ startValues);
	~Graph(void);

	void paintGraph();
	void paintGrayGraph();
	void initGraphColor();
	void paintGraphColor(int x,int z);
	void paintLineGraph();
	void paintAxes();
	void renderBitmapString(float x, float y, float z, void *font,const char* string) ;

	void initNumbers();
	void paintNumbers();

	char* to_char_pointer(String^ source);

};
