#include <GL/freeglut.h>
#include<math.h>

//global variable declaration
bool bFullscreen=false; //variable to toggle for fullscreen

static const GLfloat PI = 3.1415f;

int main(int argc,char** argv)
{
	//function prototypes
	void display(void);
	void resize(int,int);
	void keyboard(unsigned char,int,int);
	void mouse(int,int,int,int);
	void initialize(void);
	void uninitialize(void);

	//code
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(600,600); //to declare initial window size
	glutInitWindowPosition(100,100); //to declare initial window position
	glutCreateWindow("OpenGL First Window : Hello World !!!"); //open the window with "OpenGL First Window : Hello World" in the title bar

	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

//	return(0); 
}

/*
void CreateCircle(GLint k,GLint r,GLint h)
{
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glBegin(GL_LINES);
glColor3f(1.0f,1.0f,1.0f);
for (GLint i=0;i<180;i++)
{
circle.x =(GLfloat) ((r*cos(i)) - h);
circle.y = (GLfloat) ((r*sin(i)) + k);
glVertex3f(circle.x+k,circle.y-k,0.0f);

circle.x = (GLfloat) ((r*cos(i + 0.1)) - h);
circle.y = (GLfloat) ((r*sin(i + 0.1)) + k);
glVertex3f(circle.x+k,circle.y-h, 0.0f);
}
glEnd();
}
*/

void RenderCircle(GLfloat rad, GLfloat *arr, GLfloat *color, GLint circle_points)
{
	GLdouble angle = 0.0f;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 0.0f);
	for (int i = 0; i < circle_points; i++)
	{
		angle = (2 * PI * i) / circle_points;
		glVertex3f((GLfloat)((rad*cos(angle)) + arr[0]), (GLfloat)((rad*sin(angle)) + arr[1]), arr[2]);
	}
	glEnd();

	/*
	void RenderCircle(GLfloat rad, GLfloat *arr, GLfloat *color)
	{
	GLfloat angle = 0.0f;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_POINTS);
	glColor3f(color[0], color[1], color[2]);
	for (angle = 0.0f; angle <= (2.0f*pi); angle = angle + 0.001f)
	{
	glVertex3f((GLfloat)((rad*cos(angle)) + arr[0]), (GLfloat)((rad*sin(angle)) + arr[1]), arr[2]);
	}
	glEnd();
	}
	*/
}


void RenderLine(GLfloat vertices[], GLfloat lineWidth, GLfloat color[])
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLineWidth(lineWidth);
	glBegin(GL_LINES);
	glColor3f(color[0], color[1], color[2]);
	glVertex3f(vertices[0], vertices[1], vertices[2]);
	glVertex3f(vertices[3], vertices[4], vertices[5]);
	glEnd();
}

void DrawGrid(void)
{
	void RenderLine(GLfloat vertices[], GLfloat lineWidth, GLfloat color[]);

	typedef struct
	{
		GLfloat varr[6];
	}vertices;

	typedef struct color
	{
		GLfloat carr[3];
	}color;

	vertices vert;
	color col;

	//Start of vertical lines

	vert = { 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	col = { 0.0f, 1.0f, 0.0f };
	RenderLine(vert.varr, 3.0f, col.carr);

	vert = { 0.05f, -1.0f, 0.0f,0.05f, 1.0f, 0.0f };
	col = { 0.0f, 0.0f, 1.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.10f, -1.0f, 0.0f,0.10f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.15f, -1.0f, 0.0f,0.15f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.20f, -1.0f, 0.0f,0.20f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.25f, -1.0f, 0.0f,0.25f, 1.0f, 0.0f };
	col = { 0.0f, 0.0f, 1.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.30f, -1.0f, 0.0f,0.30f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.35f, -1.0f, 0.0f,0.35f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.40f, -1.0f, 0.0f,0.40f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.45f, -1.0f, 0.0f,0.45f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.50f, -1.0f, 0.0f,0.50f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.55f, -1.0f, 0.0f,0.55f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.60f, -1.0f, 0.0f,0.60f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.65f, -1.0f, 0.0f,0.65f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.70f, -1.0f, 0.0f,0.70f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.75f, -1.0f, 0.0f,0.75f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.80f, -1.0f, 0.0f,0.80f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.85f, -1.0f, 0.0f,0.85f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.90f, -1.0f, 0.0f,0.90f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 0.95f, -1.0f, 0.0f,0.95f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -1.0f, 0.0f,1.0f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	//--------------------------------------------

	vert = { -0.05f, -1.0f, 0.0f,-0.05f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.10f, -1.0f, 0.0f,-0.10f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.15f, -1.0f, 0.0f,-0.15f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.20f, -1.0f, 0.0f,-0.20f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.25f, -1.0f, 0.0f,-0.25f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.30f, -1.0f, 0.0f,-0.30f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.35f, -1.0f, 0.0f,-0.35f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.40f, -1.0f, 0.0f,-0.40f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.45f, -1.0f, 0.0f,-0.45f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.50f, -1.0f, 0.0f,-0.50f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.55f, -1.0f, 0.0f,-0.55f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.60f, -1.0f, 0.0f,-0.60f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.65f, -1.0f, 0.0f,-0.65f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.70f, -1.0f, 0.0f,-0.70f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.75f, -1.0f, 0.0f,-0.75f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.80f, -1.0f, 0.0f,-0.80f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.85f, -1.0f, 0.0f,-0.85f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.90f, -1.0f, 0.0f,-0.90f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -0.95f, -1.0f, 0.0f,-0.95f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { -1.0f, -1.0f, 0.0f,-1.0f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	//End of vertical lines

	//Start of horizontal lines
	vert = { 1.0f, 0.0f, 0.0f,-1.0f, 0.0f, 0.0f };
	col = { 1.0f, 0.0f, 0.0f };
	RenderLine(vert.varr, 3.0f, col.carr);

	vert = { 1.0f, 0.05f, 0.0f,-1.0f, 0.05f, 0.0f };
	col = { 0.0f, 0.0f, 1.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.1f, 0.0f,-1.0f, 0.1f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.15f, 0.0f,-1.0f, 0.15f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.20f, 0.0f,-1.0f, 0.20f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.25f, 0.0f,-1.0f, 0.25f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.30f, 0.0f,-1.0f, 0.30f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.35f, 0.0f,-1.0f, 0.35f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.40f, 0.0f,-1.0f, 0.40f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.45f, 0.0f,-1.0f, 0.45f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.50f, 0.0f,-1.0f, 0.50f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.55f, 0.0f,-1.0f, 0.55f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.60f, 0.0f,-1.0f, 0.60f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.65f, 0.0f,-1.0f, 0.65f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.70f, 0.0f,-1.0f, 0.70f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.75f, 0.0f,-1.0f, 0.75f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.80f, 0.0f,-1.0f, 0.80f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.85f, 0.0f,-1.0f, 0.85f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.90f, 0.0f,-1.0f, 0.90f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 0.95f, 0.0f,-1.0f, 0.95f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, 1.0f, 0.0f,-1.0f, 1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	//Lines drawn below (0,0)

	vert = { 1.0f, -0.05f, 0.0f,-1.0f, -0.05f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.10f, 0.0f,-1.0f, -0.10f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.15f, 0.0f,-1.0f, -0.15f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.20f, 0.0f,-1.0f, -0.20f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.25f, 0.0f,-1.0f, -0.25f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.30f, 0.0f,-1.0f, -0.30f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.35f, 0.0f,-1.0f, -0.35f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.40f, 0.0f,-1.0f, -0.40f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.45f, 0.0f,-1.0f, -0.45f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.50f, 0.0f,-1.0f, -0.50f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.55f, 0.0f,-1.0f, -0.55f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.60f, 0.0f,-1.0f, -0.60f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.65f, 0.0f,-1.0f, -0.65f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.70f, 0.0f,-1.0f, -0.70f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.75f, 0.0f,-1.0f, -0.75f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.80f, 0.0f,-1.0f, -0.80f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.85f, 0.0f,-1.0f, -0.85f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.90f, 0.0f,-1.0f, -0.90f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -0.95f, 0.0f,-1.0f, -0.95f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	vert = { 1.0f, -1.0f, 0.0f,-1.0f, -1.0f, 0.0f };
	RenderLine(vert.varr, 1.0f, col.carr);

	//End of horizontal lines
}

void display(void)
{
	void RenderCircle(GLfloat rad, GLfloat *arr, GLfloat *color, GLint circle_points);
	void DrawGrid(void);

	typedef struct
	{
		GLfloat carr[3];
	}circle;

	typedef struct
	{
		GLfloat carr[3];
	}color;

	circle cc;
	color cl;

	cc = { 0.0f,0.0f,0.0f };
	cl = { 1.0f,1.0f,0.0f };

	glClear(GL_COLOR_BUFFER_BIT);
	DrawGrid();
	//CreateCircle(0,0,1);
	RenderCircle(1.0f, cc.carr, cl.carr, 10000);

	//glFlush();
	glutSwapBuffers();
	
}

void initialize(void)
{
	//code
	//to select clearing (background) clear
	glClearColor(0.0f,0.0f,0.0f,0.0f); //blue 
}

void keyboard(unsigned char key,int x,int y)
{
	//code
	switch(key)
	{
	case 27: // Escape
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if(bFullscreen==false)
		{
			glutFullScreen();
			bFullscreen=true;
		}
		else
		{
			glutLeaveFullScreen();
			bFullscreen=false;
		}
		break;
	default:
		break;
	}
}

void mouse(int button,int state,int x,int y)
{
	//code
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		break;
	default:
		break;
	}
}

void resize(int width,int height)
{
	// code
	if (height == 0)
	{
		height = 1;
	}
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void uninitialize(void)
{
	// code
}

