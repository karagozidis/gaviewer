#include "StdAfx.h"
#include "Axes.h"

Axes::Axes(void)
{
}



void Axes::paintAxes()
 {
//***Draw the X,Z Axe***
glColor4f(1.0f, 1.0f, 1.0f,0.3f);
	
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

void Axes::paintOppositeAxes()
{
// Opposite Corner lines
	glBegin(GL_LINES);
		glColor4f(1.0f, 0.0f, 0.0f,0.5f);
		glVertex3f( 10.0f  ,10.0f  , 10.0f );
		glColor4f(1.0f, 0.0f, 0.0f,0.0f);
		glVertex3f( -10.0f  ,10.0f  , 10.0f );
	glEnd();

	glBegin(GL_LINES);
		glColor4f(0.0f, 1.0f, 0.0f,0.5f);
		glVertex3f( 10.0f  ,10.0f  , 10.0f );
		glColor4f(0.0f, 1.0f, 0.0f,0.0f);
		glVertex3f( 10.0f  ,-10.0f  , 10.0f );
	glEnd();

	glBegin(GL_LINES);
		glColor4f(0.7f, 0.7f, 1.0f,0.6f);
		glVertex3f( 10.0f  ,10.0f  , 10.0f );
		glColor4f(0.7f, 0.7f, 1.0f,0.0f);
		glVertex3f( 10.0f  ,10.0f  , -10.0f );
	glEnd();


}