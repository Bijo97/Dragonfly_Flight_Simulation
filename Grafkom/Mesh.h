#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <Vector>
#include "GL\glut.h"
#include "Matriks.h"
using namespace std;

class Face {
public:
	int data[3];
	void setFace(int a, int b, int c) {
		data[0] = a - 1;
		data[1] = b - 1;
		data[2] = c - 1;
	}
};

class Mesh {
public:
	vector<Vector> vertices;
	vector<Vector> vecdraw;
	vector<Face> face;
	Vector dummy2;
	Face dummy;
	int count;
	Matrix transform;

	Mesh (char *filename) {
		char temp[100];
		int countv = 0, countf = 0;
		count = 0;
		fstream fio;
		fio.open(filename, ios::in);
		while (!fio.eof() && fio.good()) {
			fio >> temp;
			if (strcmp(temp, "v") == 0) {
				double x, y, z;
				fio >> x >> y >> z;
				dummy2.setAll(x, y, z, 1);
				vertices.push_back(dummy2);
			} else if (strcmp(temp, "f") == 0) {
				int f1, f2, f3;
				fio >> f1 >> f2 >> f3;
				dummy.setFace(f1, f2, f3);
				count++;
				face.push_back(dummy);
			}
		}
		fio.close();
	}
	void rotateX(double degree) {
		transform.setBack();
		transform.setMatrix(1, 1, cos(degree * 3.14 / 180));
		transform.setMatrix(1, 2, sin(degree * 3.14 / 180));
		transform.setMatrix(2, 1, -sin(degree * 3.14 / 180));
		transform.setMatrix(2, 2, cos(degree * 3.14 / 180));
	}

	void rotateY(double degree) {
		transform.setMatrix(0, 0, cos(degree * 3.14 / 180));
		transform.setMatrix(0, 2, -sin(degree * 3.14 / 180));
		transform.setMatrix(2, 0, sin(degree * 3.14 / 180));
		transform.setMatrix(2, 2, cos(degree * 3.14 / 180));
	}
	void rotateZ(double degree) {
		transform.setMatrix(0, 0, cos(degree * 3.14 / 180));
		transform.setMatrix(0, 1, sin(degree * 3.14 / 180));
		transform.setMatrix(1, 0, -sin(degree * 3.14 / 180));
		transform.setMatrix(1, 1, cos(degree * 3.14 / 180));
	}
	void translasi(int i, int j, int k) {
		transform.setMatrix(3, 0, i);
		transform.setMatrix(3, 1, j);
		transform.setMatrix(3, 2, k);
	}

	void Draw () {
		rotateX(90.0);

		transform.display();
		Vector x,y,z;
		for (int i=0; i<count; i++) {
			glColor3f(1, 1, 1);
			x=transform * vertices[face[i].data[0]];
			y=transform * vertices[face[i].data[1]];
			z=transform * vertices[face[i].data[2]];
			glBegin(GL_LINE_LOOP);
			glVertex3d(x.getX(), x.getY(), x.getZ());
			glVertex3d(y.getX(), y.getY(), y.getZ());
			glVertex3d(z.getX(), z.getY(), z.getZ());
			glEnd();
		}
	}
};