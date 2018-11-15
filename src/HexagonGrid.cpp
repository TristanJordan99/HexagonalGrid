//Tristan Jordan
//This program is using hexagons in a grid to make a design

#include <iostream>
#include <Windows.h>
#include <gl\GL.h>
#include <gl/glut.h>
#include <cmath>
using namespace std;

//Variable columns and rows
int ROWS;
int COLS;

//Create a 2D hexagon
void Hexagon(int x,int y,double V,double R,bool outline){
	double shifter = 2;

	//create the hexagon polygon
	glBegin(GL_POLYGON);
	glVertex2d(x - R, y);
	glVertex2d(x - (R / shifter), y - V);
	glVertex2d(x + (R / shifter), y - V);
	glVertex2d(x + R, y);
	glVertex2d(x + (R / shifter), y + V);
	glVertex2d(x - (R / shifter), y + V);
	glVertex2d(x - R, y);
	glEnd();

	//if outline is 1 then a white outline is displayed
	if (outline) {
		glColor3f(1, 1, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2d(x - R, y);
		glVertex2d(x - (R / shifter), y - V);
		glVertex2d(x + (R / shifter), y - V);
		glVertex2d(x + R, y);
		glVertex2d(x + (R / shifter), y + V);
		glVertex2d(x - (R / shifter), y + V);
		glVertex2d(x - R, y);
		glEnd();
	}
}

//Function that creates the grid
void hexGrid() {
	//width only applies to outline
	glLineWidth(1);
	glClear(GL_COLOR_BUFFER_BIT);

	//layout the grid
	for (int i = 1; i < COLS+1; i++) {
		for (int j = 1; j < ROWS+1; j++) {
			glColor3f((double)i/COLS, 0, (double)j/ROWS);
			Hexagon(i * 44-((j % 2) * 22), j * 15, 15, 15,1);
		}
	}
	
	//display
	glFlush();
	glutSwapBuffers();

}

//draw function
void initDraw() {
	//initial values
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	//camera scales with amount of hexagons
	gluOrtho2D(0, (COLS+1)*44, -15, (ROWS + 2) * 15);
	//grid call
	hexGrid();
}


int main() {
	//input specs
	cout << "How many rows? >";
	cin >> ROWS;
	cout << "How many cols? >";
	cin >> COLS;

	//glut setup
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("HexGrid");
	glutDisplayFunc(initDraw);
	glutMainLoop();
}
