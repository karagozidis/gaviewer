#include "StdAfx.h"
#include "OpenGL.h"


/*
 * I define those here because , i can not define them inside managed ref OpenGl class.  
 * Those are the values of the lights of the opengl scene. 
 */
		//Add ambient light
	GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f}; //Color 

	//Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color 
	GLfloat lightPos0[] = {0.0f, 25.0f, 0.0f, 1.0f}; //Positioned at
	
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
	GLfloat lightPos1[] = {0.0f, 0.5f, -35.5f, 1.0f};
	

	



OpenGL::OpenGL(System::Windows::Forms::Form ^ parentForm, 
            GLsizei iWidth, GLsizei iHeight)
    {

	this->graphController_ = gcnew GraphController();

	this->XBeginingPos_ = 0;
	this->YBeginingPos_ = 0;
	this->ZBeginingPos_ = 40;

	this->xAngle_ = 0.0;
	this->yAngle_ = 0.0;

	this->xAngleSpeed_ = 0.0;
	this->yAngleSpeed_ = 0.0;

			CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 377;
			cp->Y = 88;
			cp->Height = iHeight;
			cp->Width = iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// Create the actual window
			this->CreateHandle(cp);

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if(m_hDC)
			{
				MySetPixelFormat(m_hDC);
				setGLSceneSize(iWidth, iHeight);
				InitGL();
			}

		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);


		

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_COLOR_MATERIAL);

			glEnable(GL_LIGHTING); //Enable lighting

			glEnable(GL_LIGHT1);
			glEnable(GL_LIGHT2); 
		//	glEnable(GL_LIGHT3); 
		//	glEnable(GL_LIGHT4); 
		//	glEnable(GL_LIGHT5); 
		//	glEnable(GL_LIGHT6);

			glEnable(GL_NORMALIZE); //Automatically normalize normals
			glShadeModel(GL_SMOOTH); //Enable smooth shading
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    }


	/*
	 * We write the opengl code in this function
	 * to be drawn in the opengl area.
	 */
 System::Void OpenGL::Render(System::Void)
	{

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
			glLoadIdentity();									// Reset the current modelview matrix

			gluLookAt (XBeginingPos_,YBeginingPos_, ZBeginingPos_, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

			glRotatef(xAngle_,1.0 , 0.0, 0.0);
			glRotatef(yAngle_,0.0 , 1.0, 0.0);

			
			/*Those doesnt draw anything to the opengl scene but , they work with lights and give a nice  
			 *light sense.
			 */
			glColor3f(1,0.5,0.5);
			glutSolidCube(0);
			glTranslatef(0, 12 , 5 );
			glutSolidCube(0);
			glTranslatef(0, -12 , -5 );

			glTranslatef(0, 12 , -5 );
			glutSolidCube(0);
			glTranslatef(0, -12 , 5 );

			glTranslatef(0, -12 , 5 );
			glutSolidCube(0);
			glTranslatef(0, 12 , -5 );

			glTranslatef(0, -12 , -5 );
			glutSolidCube(0);
			glTranslatef(0, 12 , 5 );



			this->graphController_->paintGraph();
			this->graphController_->paintAxes();
			this->graphController_->paintOppositeAxes();

			if ( this->geneticAlgorithm_ != nullptr )
				{
				this->geneticAlgorithm_->paintAtoms();
				}

			Sleep(10);

	xAngle_ += xAngleSpeed_ ;
	yAngle_ += yAngleSpeed_ ;
	}


	/*
	 * This is called directly after the OpenGL rendering
	 * to put the contents of the OpenGL buffer into our  
	 * window.
	 */
System::Void OpenGL::SwapOpenGLBuffers(System::Void)
{
   SwapBuffers(m_hDC) ;
}

	/*
	 * When destroying the Form, we dispose of our window.  
	 */

   OpenGL::~OpenGL(System::Void)
    {
        this->DestroyHandle();
    }


	/*
	 * Standard function to set a pixel format for a
	 * Win32 SDK / MFC Device Context. See OpenGL 
	 * websites for more on this. 
	 */
 GLint OpenGL::MySetPixelFormat(HDC hdc)
    {
        PIXELFORMATDESCRIPTOR pfd = { 
            sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd 
            1,                                // version number 
            PFD_DRAW_TO_WINDOW |              // support window 
            PFD_SUPPORT_OPENGL |              // support OpenGL 
            PFD_DOUBLEBUFFER,                 // double buffered 
            PFD_TYPE_RGBA,                    // RGBA type 
            24,                               // 24-bit color depth 
            0, 0, 0, 0, 0, 0,                 // color bits ignored 
            0,                                // no alpha buffer 
            0,                                // shift bit ignored 
            0,                                // no accumulation buffer 
            0, 0, 0, 0,                       // accum bits ignored 
            32,                               // 32-bit z-buffer     
            0,                                // no stencil buffer 
            0,                                // no auxiliary buffer 
            PFD_MAIN_PLANE,                   // main layer 
            0,                                // reserved 
            0, 0, 0                           // layer masks ignored 

        }; 
    
        GLint  iPixelFormat; 
     
        // get the device context's best, available pixel format match 

        if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
        {
            MessageBox::Show("ChoosePixelFormat Failed");
            return 0;
        }
         
        // make that match the device context's current pixel format 

        if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
        {
            MessageBox::Show("SetPixelFormat Failed");
            return 0;
        }
    
        if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
        {
            MessageBox::Show("wglCreateContext Failed");
            return 0;
        }
        
        if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
        {
            MessageBox::Show("wglMakeCurrent Failed");
            return 0;
        }
    
        return 1;
    }

 	/*
	 * All setup for opengl goes here
	 */
bool OpenGL::InitGL(GLvoid)										
	{
		glShadeModel(GL_SMOOTH);							// Enable smooth shading
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black background
		glClearDepth(1.0f);									// Depth buffer setup
		glEnable(GL_DEPTH_TEST);							// Enables depth testing
		glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
		return TRUE;										// Initialisation went ok
	}

	/*
	 *Initializes the size of the gl scene
	 */
GLvoid OpenGL::setGLSceneSize(GLsizei width, GLsizei height)		
	{
		if (height==0)										// Prevent A Divide By Zero By
		{
			height=1;										// Making Height Equal One
		}

		glViewport(0,0,width,height);						// Reset The Current Viewport

		glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
		glLoadIdentity();									// Reset The Projection Matrix

		// Calculate The Aspect Ratio Of The Window
		gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

		glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
		glLoadIdentity();									// Reset The Modelview Matrix
	}


	/*
	 *We call this to resize the gl scene , when we resize the parent window. 
	 */

void OpenGL::reSizeGLScene(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight)
	{
	CreateParams^ cp = gcnew CreateParams;

	// Set the position on the form
	cp->X = 377; 
	cp->Y = 88; 
	cp->Height = iHeight;
	cp->Width = iWidth;

//	resizeWidth_ = iHeight ; 
//	resizeHeight_ = iWidth ; 

	// Specify the form as the parent.
	cp->Parent = parentForm->Handle;

	// Create as a child of the specified parent and make OpenGL compliant (no clipping)
	cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	// Create the actual window
	this->DestroyHandle();
	this->CreateHandle(cp);

	m_hDC = GetDC((HWND)this->Handle.ToPointer());
			
	if(m_hDC)
		{
		MySetPixelFormat(m_hDC);
		setGLSceneSize(iWidth, iHeight);
		InitGL();
		}


		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);


		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		
		glEnable(GL_LIGHTING); //Enable lighting
			glEnable(GL_LIGHT1);
			glEnable(GL_LIGHT2); 

		glEnable(GL_NORMALIZE); //Automatically normalize normals
		glShadeModel(GL_SMOOTH); //Enable smooth shading
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	}

/*
 * This is an event handler , that takes the x , y of the mouse over the openglScene
 * When the user clicks his mouse over opengl scene , this function calls the void GetOGLPos(xPos,yPos); function
 */
void OpenGL::WndProc(Message% m)
	{
		
		switch (m.Msg) {
			case WM_LBUTTONDOWN:
				System::IntPtr value;
				value =m.LParam;
				WORD xPos = LOWORD(value.ToInt32()); 
				WORD yPos = HIWORD(value.ToInt32()); 
			    GetOGLPos(xPos,yPos);
				break;
		}

		NativeWindow::WndProc(m);	
	}

/*
 * This function takes 2 parameters, x and y positions and turns them to the x , y , z positions of the opengl scene.
 * Then it calls the GeneticAlgorithm_::displayAtomsValues(X,Y,Z); which searches if we any atom located in this x ,y, z position,
 * and displays its values.
 */

void OpenGL::GetOGLPos(int x, int y)
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);


	if(this->geneticAlgorithm_ != nullptr ) this->geneticAlgorithm_->displayAtomsValues((float)posX,(float)posY,(float)posZ );

}
