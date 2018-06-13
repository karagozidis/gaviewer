#pragma once


#include <windows.h>
#include <GL/gl.h>    
#include <GL/glu.h>

#include "GraphController.h"
#include "StartValues.h"
#include "GeneticAlgorithm.h"

using namespace System::Windows::Forms;


ref class OpenGL:public System::Windows::Forms::NativeWindow
{

private:
    HDC m_hDC;
    HGLRC m_hglrc;

public:	
	GraphController^ graphController_ ; 
	GA::GeneticAlgorithm^ geneticAlgorithm_ ; 

	GLfloat XBeginingPos_ ;
	GLfloat YBeginingPos_ ;
	GLfloat ZBeginingPos_ ;


	/*
	 *Angles for rotation of the graphics
	 */
	GLfloat xAngle_ ;
	GLfloat yAngle_ ;

	GLfloat xAngleSpeed_ ;
	GLfloat yAngleSpeed_ ;



public:
	/*
	 * This constructor takes parameters of a parent form, 
	 * the width of the OpenGL area and the height of the
	 * OpenGL area.
	 */
OpenGL(System::Windows::Forms::Form ^ parentForm, 
            GLsizei iWidth, GLsizei iHeight);


	/*
	 * We write the opengl code in this function
	 * to be drawn in the opengl area.
	 */
virtual System::Void Render(System::Void);

	/*
	 * This is called directly after the OpenGL rendering
	 * to put the contents of the OpenGL buffer into our  
	 * window.
	 */
System::Void SwapOpenGLBuffers(System::Void);

protected:
	/*
	 * When destroying the Form, we dispose of our window.  
	 */
~OpenGL(System::Void);

	/*
	 * Standard function to set a pixel format for a
	 * Win32 SDK / MFC Device Context. See OpenGL 
	 * websites for more on this. 
	 */
GLint MySetPixelFormat(HDC hdc);
  
	/*
	 * All setup for opengl goes here
	 */
bool InitGL(GLvoid);						

	/*
	 * Resize and initialise the gl window
	 */
public: GLvoid setGLSceneSize(GLsizei width, GLsizei height);		


void reSizeGLScene(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight);

virtual void WndProc(Message% m)override;
	
void GetOGLPos(int x, int y);


};

