#include <iostream>
#include "Quadric.h"
using namespace std;

class Hierarchy {
public:
	Quadric base;
	int id_parent;
	Matrix pos, trans;
	Hierarchy() {
		id_parent = -1;
	}
	void setParent(int parent) {
		id_parent = parent;
	}
	void setKepala(int i, int radius) {
		if (i == 1) {
			base.kepala(radius);
		}
	}
	void setBadan(int i, int radius){
		if (i == 1){
			base.badan(radius);
		}
	}
	void setEkor(int i, int radius){
		if (i == 1){
			base.ekor(radius);
		}
	}
	void setKakiAtas(int i, int radius){
		if (i == 1){
			base.kakiatas(radius);
		}
	}
	void setKakiBawah(int i, int radius){
		if (i == 1){
			base.kakibawah(radius);
		}
	}
	void setSayapDepan(int i, int radius){
		if (i == 1){
			base.sayapdepan(radius);
		}
	}
	void setMata(int i, int radius){
		if (i == 1){
			base.mata(radius);
		}
	}
	void setTangkai(int i, int radius){
		if (i == 1){
			base.tangkai(radius);
		}
	}
	void setLangit(int i, int radius){
		if (i == 1){
			base.langit(radius);
		}
	}
	void setPos(Matrix _pos) {
		pos = pos * _pos;
	}
	void addTransform(Matrix _trans) {
		trans = trans * _trans;
	}
	Matrix getPos() {
		return pos;
	}

	Matrix getTransform(Hierarchy *other) {
		Matrix temp;
		if(id_parent != -1){
			temp = other[id_parent].getTransform(other);}
		temp = temp * pos * trans;
		return temp;
	}

	void draw(double r, double g, double b, double o, Hierarchy *other) {
		glColor4f(r, g ,b, o);
		Vector dummy[100][100];

		Matrix temp = getTransform(other);

		for (int i=0; i<100; i++) {
			for (int j=0; j<100; j++) {
				dummy[i][j] = base.titik[i][j];
				dummy[i][j] = temp * dummy[i][j];
			}
		}
		for (int i = 0; i < 99; i++)
		{
			for (int j = 0; j < 49; j++)
			{
				glBegin(GL_TRIANGLES);
				glVertex3f(dummy[i][j].getX(), dummy[i][j].getY(), dummy[i][j].getZ());
				glVertex3f(dummy[i + 1][j].getX(), dummy[i + 1][j].getY(), dummy[i + 1][j].getZ());
				glVertex3f(dummy[i + 1][j + 1].getX(), dummy[i + 1][j + 1].getY(), dummy[i + 1][j + 1].getZ());
				glEnd();

				glBegin(GL_TRIANGLES);
				glVertex3f(dummy[i][j].getX(), dummy[i][j].getY(), dummy[i][j].getZ());
				glVertex3f(dummy[i + 1][j + 1].getX(), dummy[i + 1][j + 1].getY(), dummy[i + 1][j + 1].getZ());
				glVertex3f(dummy[i][j + 1].getX(), dummy[i][j + 1].getY(), dummy[i][j + 1].getZ());
				glEnd();
			}
			glBegin(GL_TRIANGLES);
			glVertex3f(dummy[i][49].getX(), dummy[i][49].getY(), dummy[i][49].getZ());
			glVertex3f(dummy[i + 1][49].getX(), dummy[i + 1][49].getY(), dummy[i + 1][49].getZ());
			glVertex3f(dummy[i + 1][0].getX(), dummy[i + 1][0].getY(), dummy[i + 1][0].getZ());
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3f(dummy[i][49].getX(), dummy[i][49].getY(), dummy[i][49].getZ());
			glVertex3f(dummy[i + 1][0].getX(), dummy[i + 1][0].getY(), dummy[i + 1][0].getZ());
			glVertex3f(dummy[i][0].getX(), dummy[i][0].getY(), dummy[i][0].getZ());
			glEnd();
		}
		//draw sumbu X(atas ke bawah)
		for (int j = 0; j < 50; j++)
		{
			for (int i = 0; i < 99; i++)
			{
				glBegin(GL_TRIANGLES);
				glVertex3f(dummy[i][j].getX(), dummy[i][j].getY(), dummy[i][j].getZ());
				glVertex3f(dummy[i + 1][j].getX(), dummy[i + 1][j].getY(), dummy[i + 1][j].getZ());
				glVertex3f(dummy[i + 1][j + 1].getX(), dummy[i + 1][j + 1].getY(), dummy[i + 1][j + 1].getZ());
				glEnd();

				glBegin(GL_TRIANGLES);
				glVertex3f(dummy[i][j].getX(), dummy[i][j].getY(), dummy[i][j].getZ());
				glVertex3f(dummy[i + 1][j + 1].getX(), dummy[i + 1][j + 1].getY(), dummy[i + 1][j + 1].getZ());
				glVertex3f(dummy[i][j + 1].getX(), dummy[i][j + 1].getY(), dummy[i][j + 1].getZ());
				glEnd();
			}
			glBegin(GL_TRIANGLES);
			glVertex3f(dummy[99][j].getX(), dummy[99][j].getY(), dummy[99][j].getZ());
			glVertex3f(dummy[0][j].getX(), dummy[0][j].getY(), dummy[0][j].getZ());
			glVertex3f(dummy[0][j + 1].getX(), dummy[0][j + 1].getY(), dummy[0][j + 1].getZ());
			glEnd();

			glBegin(GL_TRIANGLES);
			glVertex3f(dummy[99][j].getX(), dummy[99][j].getY(), dummy[99][j].getZ());
			glVertex3f(dummy[0][j + 1].getX(), dummy[0][j + 1].getY(), dummy[0][j + 1].getZ());
			glVertex3f(dummy[99][j + 1].getX(), dummy[99][j + 1].getY(), dummy[99][j + 1].getZ());
			glEnd();
		}
		//draw sumbu Y(kanan kiri)
	}
};