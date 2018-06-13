#include "StdAfx.h"
#include "Graph.h"


Graph::Graph(StartValues^ startValues)
{
	yValues_ = gcnew array<float,2>(101,101);
	yPixelValues_= gcnew array<float,2>(101,101);
	grainPixelColor_= gcnew array<float,3>(101,101,2);

	int x = 0 , z = 0 ; 
	schemeBlend_ = 1 ; 
	float xPos;
	float zPos;

	startValues_ = startValues;


    xPixelDist_ = xPixelEnd_ - xPixelStart_ ; 
    zPixelDist_ = zPixelEnd_ - zPixelStart_ ; 

	xPixelStep_ = xPixelDist_ / 100;
	zPixelStep_ = zPixelDist_ / 100;

	//mathFunction_ = MathFunction::getInstance();
	//mathFunction_->setFunctionNumber( startValues_->getMathFunctionNumber() , startValues_->fx_  ) ;
	this->parser_ = gcnew ExprParser::Parser();
	this->parser_->createBuffer(this->startValues_->fx_);



	xPos = this->startValues_->getxStart();
	zPos = this->startValues_->getzStart();

	xGrainLineNum_ = 2;
	zGrainLineNum_ = 2;

	/*
	 *Fill yValues_[][] table with f(x,z) values 
	 */
	for (x = 0 ; x < 101 ; x++)
		{
		for (z = 0 ; z < 101 ; z++)
			{
			this->parser_->setXY(xPos , zPos);
			yValues_[x,z] =this->parser_->calculateExpression(); //mathFunction_->calculate(xPos , zPos);
			zPos = zPos + this->startValues_->getzStep();
			}
		xPos = xPos + this->startValues_->getxStep();
		zPos = this->startValues_->getzStart();
		}


	/*
	 *Find min,max from yValues_[][] table
	 */
	yMin_= yValues_[0,0];
	yMax_= yValues_[0,0];
	for (x = 0 ; x < 101 ; x++)
		{
		for (z = 0 ; z < 101 ; z++)
			{
			if (yMax_ < yValues_ [x,z]) yMax_ = yValues_[x,z];
			if (yMin_ > yValues_ [x,z]) yMin_ = yValues_[x,z];
			}
		}


	/*
	 *Normalize yValues to the pixels' values tables and fill yPixelValues[100][100] table
	 */
	float yDist = yMax_-yMin_;
	float yPixelDistance = yPixelEnd_ - yPixelStart_;
	   
	for (x = 0 ; x < 101 ; x++)
		{
		for (z = 0 ; z < 101 ; z++)
			{
			yPixelValues_[x,z] = (yValues_[x,z] - yMin_) / yDist;
			yPixelValues_[x,z] = yPixelValues_[x,z] * yPixelDistance + yPixelStart_;
			}
		}

	this->initNumbers();
	this->initGraphColor();
}

Graph::~Graph(void)
{
}


void Graph::paintGraph()
 {
	
 xPixelPos_ = Graph::xPixelStart_; 
 zPixelPos_ = Graph::zPixelStart_;


//*****************************Color************************
		//Create 4 stages
		//float grainColorStageStep_ = (yPixelEnd_-yPixelStart_)/4;
	//	float color;
//*****************************Color************************


 for (x_ = 0 ; x_ < 100 ; x_++)
	{
	for (z_ = 0 ; z_ < 100 ; z_++)
		{
		
	    glBegin(GL_QUADS); 
		  this->paintGraphColor(x_,z_);
		  glVertex3f(xPixelPos_ ,yPixelValues_[x_,z_]     ,zPixelPos_); 
		  this->paintGraphColor(x_,z_+1);
		  glVertex3f(xPixelPos_ ,yPixelValues_[x_,z_+1]   ,zPixelPos_+ zPixelStep_); 	
		  this->paintGraphColor(x_+1,z_+1);
		  glVertex3f(xPixelPos_ + xPixelStep_ ,yPixelValues_[x_+1,z_+1] ,zPixelPos_+ zPixelStep_); 	
		  this->paintGraphColor(x_+1,z_);
		  glVertex3f(xPixelPos_ + xPixelStep_ ,yPixelValues_[x_+1,z_]   ,zPixelPos_); 	
	    glEnd(); //end the shape we are currently working on
	    zPixelPos_ += zPixelStep_ ; 
		}
	xPixelPos_ += xPixelStep_ ; 
    zPixelPos_ = zPixelStart_;
	}
 //glEnd();

 //this->paintNumbers();
 }


void Graph::paintGrayGraph()
 {
	
 xPixelPos_ = Graph::xPixelStart_; 
 zPixelPos_ = Graph::zPixelStart_;

glColor4f(0.9,0.9,1, 0.4);

 for (x_ = 0 ; x_ < 100 ; x_++)
	{
	for (z_ = 0 ; z_ < 100 ; z_++)
		{
	    glBegin(GL_QUADS); 
		  glVertex3f(xPixelPos_ ,yPixelValues_[x_,z_]     ,zPixelPos_); 
		  glVertex3f(xPixelPos_ ,yPixelValues_[x_,z_+1]   ,zPixelPos_+ zPixelStep_); 	
		  glVertex3f(xPixelPos_ + xPixelStep_ ,yPixelValues_[x_+1,z_+1] ,zPixelPos_+ zPixelStep_); 	
		  glVertex3f(xPixelPos_ + xPixelStep_ ,yPixelValues_[x_+1,z_]   ,zPixelPos_); 	
	    glEnd(); //end the shape we are currently working on
	    zPixelPos_ += zPixelStep_ ; 
		}
	xPixelPos_ += xPixelStep_ ; 
    zPixelPos_ = zPixelStart_;
	}
// this->paintNumbers();
 }


void Graph::paintLineGraph() 
 {
 xPixelPos_ = xPixelStart_; 
 zPixelPos_ = zPixelStart_;

 glColor4f(0.8f , 0.8f , 0.8f  , 0.5f);

 for (x_ = 0 ; x_ < 99 ; x_= x_ +xGrainLineNum_)
	{
	for (z_ = 0 ; z_ < 99 ; z_++)
		{
		glBegin(GL_LINES);
		glVertex3f(xPixelPos_ ,yPixelValues_[x_,z_]     ,zPixelPos_); 
		glVertex3f(xPixelPos_  ,yPixelValues_[x_,z_+1]   ,zPixelPos_+zPixelStep_); 
		glEnd(); 

	    zPixelPos_ += zPixelStep_ ; 
		}
	xPixelPos_ += xPixelStep_*xGrainLineNum_ ; 
    zPixelPos_ = zPixelStart_;

	}

xPixelPos_ = xPixelStart_;
 for (z_ = 0 ; z_ < 99 ; z_+=zGrainLineNum_)
		{
    for (x_ = 0 ; x_ < 99 ; x_ ++)
	{
		glBegin(GL_LINES);
		glVertex3f(xPixelPos_ ,yPixelValues_[x_,z_]     ,zPixelPos_); 
		glVertex3f(xPixelPos_+xPixelStep_  ,yPixelValues_[x_+1,z_]   ,zPixelPos_); 
		glEnd(); 

      xPixelPos_ += xPixelStep_ ; 
		}
	zPixelPos_ += zPixelStep_*zGrainLineNum_ ; 
    xPixelPos_ = xPixelStart_;
	}

//this->paintNumbers(); 

 }

void Graph::paintAxes()
 {
//***Draw the X,Z Axe***
glColor4f(1.0f, 1.0f, 1.0f,0.3f);
	//glColor4f(0.75f, 0.75f, 1.0f,0.2f);
	for (int i=-10 ; i <= 10 ; i++ )
	{
	
	glBegin(GL_LINES);
		
		glVertex3f( (float)i , -10.0f , 10.0f );
		glVertex3f( (float)i , -10.0f , -10.0f );
	glEnd();
	}


	for (int i =10; i >= -10 ; i --)
	{
	glBegin(GL_LINES);
	glVertex3f( -10.0f ,-10.0f ,(float)i);
	glVertex3f( 10.0f ,-10.0f , (float)i);
	glEnd();
	}

	//***Draw the Y,Z Axe***
	for (int i=-10 ; i <= 10 ; i++ )
	{
	
	glBegin(GL_LINES);
		
		glVertex3f(-10.0f , (float)i , 10.0f );
		glVertex3f(-10.0f , (float)i ,-10.0f );
	glEnd();
	}

	for (int i =10; i >= -10 ; i --)
	{
	glBegin(GL_LINES);
	glVertex3f(-10.0f , -10.0f , (float)i );
	glVertex3f(-10.0f , 10.0f , (float)i);
	glEnd();
	}


	//***Draw the X,Y Axe***
	for (int i=-10 ; i <= 10 ; i++ )
	{
	
	glBegin(GL_LINES);
		
		glVertex3f( (float)i ,10.0f  , -10.0f );
		glVertex3f( (float)i ,-10.0f , -10.0f );
	glEnd();
	}

	for (int i =10; i >= -10 ; i --)
	{
	glBegin(GL_LINES);
	glVertex3f(-10.0f ,(float)i , -10.0f );
	glVertex3f( 10.0f ,(float)i , -10.0f );
	glEnd();
	}

}

void Graph::initGraphColor()
{
float grainColorStageStep_ = (yPixelEnd_-yPixelStart_)/4;

for (x_ = 0 ; x_ < 100 ; x_++)
	{
	for (z_ = 0 ; z_ < 100 ; z_++)
		{

		if(yPixelValues_[x_,z_] <= yPixelStart_+grainColorStageStep_)
			{	
			grainPixelColor_[x_,z_,0] = yPixelValues_[x_,z_] +5;
			grainPixelColor_[x_,z_,0] = grainPixelColor_[x_,z_,0]  / (-5) ;
			grainPixelColor_[x_,z_,0] = 1 - grainPixelColor_[x_,z_,0] ; 

			grainPixelColor_[x_,z_,1] = 1;
			}

		else if(yPixelValues_[x_,z_] <= yPixelStart_+grainColorStageStep_*2 && yPixelValues_[x_,z_] > yPixelStart_+grainColorStageStep_)
			{	
			grainPixelColor_[x_,z_,0]  = yPixelValues_[x_,z_]/(-5);
			
			grainPixelColor_[x_,z_,1] = 2;
			}

		else if(yPixelValues_[x_,z_] <= yPixelStart_+grainColorStageStep_*3 && yPixelValues_[x_,z_] > yPixelStart_+grainColorStageStep_*2)
			{
			grainPixelColor_[x_,z_,0] = yPixelValues_[x_,z_]/5;
			
			grainPixelColor_[x_,z_,1] = 3;
			}

		else if(yPixelValues_[x_,z_] <= yPixelStart_+grainColorStageStep_*4 && yPixelValues_[x_,z_] > yPixelStart_+grainColorStageStep_*3 )
			{
			grainPixelColor_[x_,z_,0] = yPixelValues_[x_,z_] -5;
			grainPixelColor_[x_,z_,0] = grainPixelColor_[x_,z_,0]  / 5 ;
			grainPixelColor_[x_,z_,0] = 1 - grainPixelColor_[x_,z_,0];
			
			grainPixelColor_[x_,z_,1] = 4;
			}
		}
	}
}

void Graph::paintGraphColor(int x,int z)
 {
	 if (grainPixelColor_[x,z,1] == 1)
							glColor3f(1, grainPixelColor_[x,z,0],0);

	 else if (grainPixelColor_[x,z,1] == 2)
							glColor3f(grainPixelColor_[x,z,0],1,0);

	 else if (grainPixelColor_[x,z,1] == 3)
							glColor3f(0,1,grainPixelColor_[x,z,0]);

	 else if (grainPixelColor_[x,z,1] == 4)
							glColor3f(0,grainPixelColor_[x,z,0],1);
 }

//***************print text******************
void Graph::renderBitmapString(
		float x, 
		float y, 
		float z, 
		void *font, 
		const char* string) {  
		glColor4f(0.8f,0.8f,0.8f,1.0f);
  const char *c;
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
	//renderBitmapSystem::String^( 0, 0, 10, GLUT_BITMAP_HELVETICA_10,"poddddddint1"); 
	//renderBitmapSystem::String^( 0, 1, 10, GLUT_BITMAP_TIMES_ROMAN_10 ,"poddddddint2");
	//renderBitmapSystem::String^( 0, 2, 10, GLUT_BITMAP_8_BY_13 ,"poddddddint3");
	//renderBitmapSystem::String^( 0, 3, 10, GLUT_BITMAP_9_BY_15 ,"poddddddint4");
}

void Graph::initNumbers(){

System::String^ mx_my_mz_number_String;
System::String^ x_my_mz_number_String;
System::String^ mx_my_z_number_String;
System::String^ x_my_z_number_String;

System::String^ mx_y_mz_number_String;
System::String^ x_y_mz_number_String;
System::String^ mx_y_z_number_String;
System::String^ x_y_z_number_String;

mx_my_mz_number_String = "(" + this->startValues_->getxStart() +  "," + this->yMin_ + "," + this->startValues_->getzStart() + ")";	
x_my_mz_number_String = "(" + this->startValues_->getxEnd() + "," + this->yMin_ + "," + this->startValues_->getzStart() + ")" ;
mx_my_z_number_String = "(" + this->startValues_->getxStart() + "," + this->yMin_ + "," + this->startValues_->getzEnd() + ")";
x_my_z_number_String =  "(" + this->startValues_->getxEnd() + "," + this->yMin_ + "," + this->startValues_->getzEnd() + ")";
mx_y_mz_number_String = "(" + this->startValues_->getxStart() + "," + this->yMax_ + "," + this->startValues_->getzStart() + ")";
x_y_mz_number_String = "(" + this->startValues_->getxEnd() + "," + this->yMax_ + "," + this->startValues_->getzStart() + ")";
mx_y_z_number_String =  "(" + this->startValues_->getxStart() + "," + this->yMax_ + "," + this->startValues_->getzEnd() + ")";
x_y_z_number_String =  "(" + this->startValues_->getxEnd() + "," + this->yMax_ + "," + this->startValues_->getzEnd() + ")";

mx_my_mz_number_ =this->to_char_pointer( mx_my_mz_number_String )  ;
x_my_mz_number_ = this->to_char_pointer( x_my_mz_number_String  )  ;
mx_my_z_number_ = this->to_char_pointer( mx_my_z_number_String  )  ;
x_my_z_number_ =  this->to_char_pointer( x_my_z_number_String   )  ;

mx_y_mz_number_ = this->to_char_pointer(  mx_y_mz_number_String  ) ;
x_y_mz_number_ =  this->to_char_pointer(  x_y_mz_number_String   ) ;
mx_y_z_number_ =  this->to_char_pointer(  mx_y_z_number_String   ) ;
x_y_z_number_ =   this->to_char_pointer(  x_y_z_number_String    ) ;

}

void Graph::paintNumbers()
{
	
this->renderBitmapString(  Graph::xPixelStart_ ,Graph::yPixelStart_, Graph::zPixelStart_, GLUT_BITMAP_TIMES_ROMAN_10 ,mx_my_mz_number_ );
this->renderBitmapString(  Graph::xPixelEnd_ ,Graph::yPixelStart_, Graph::zPixelStart_, GLUT_BITMAP_TIMES_ROMAN_10 ,x_my_mz_number_ );
this->renderBitmapString(  Graph::xPixelStart_ ,Graph::yPixelStart_, Graph::zPixelEnd_, GLUT_BITMAP_TIMES_ROMAN_10 , mx_my_z_number_ );
this->renderBitmapString(  Graph::xPixelEnd_ ,Graph::yPixelStart_, Graph::zPixelEnd_, GLUT_BITMAP_TIMES_ROMAN_10 , x_my_z_number_ );

this->renderBitmapString(  Graph::xPixelStart_ ,Graph::yPixelEnd_, Graph::zPixelStart_, GLUT_BITMAP_TIMES_ROMAN_10 , mx_y_mz_number_ );
this->renderBitmapString(  Graph::xPixelEnd_ ,Graph::yPixelEnd_, Graph::zPixelStart_, GLUT_BITMAP_TIMES_ROMAN_10 , x_y_mz_number_ );
this->renderBitmapString(  Graph::xPixelStart_ ,Graph::yPixelEnd_, Graph::zPixelEnd_, GLUT_BITMAP_TIMES_ROMAN_10 , mx_y_z_number_ );
this->renderBitmapString(  Graph::xPixelEnd_ ,Graph::yPixelEnd_, Graph::zPixelEnd_, GLUT_BITMAP_TIMES_ROMAN_10 , x_y_z_number_ );


}

char* Graph::to_char_pointer( String^ source)
{
    pin_ptr<const wchar_t> wch = PtrToStringChars( source );
    int len = (( source->Length+1) * 2);
    char *ch = new char[ len ];
    bool result = wcstombs( ch, wch, len ) != -1;
    return ch;
}