#include <iostream>
#include "Matrix.h"
#include "GL/glut.h"
#include <stack>
using namespace std;

class Quadric {
public:
	Vector titik[100][100];
	

	void drawquadric() {
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 49; j++)
			{
				glBegin(GL_LINES);
				glVertex3f(titik[i][j].getX(), titik[i][j].getY(), titik[i][j].getZ());
				glVertex3f(titik[i][j + 1].getX(), titik[i][j + 1].getY(), titik[i][j + 1].getZ());
				glEnd();
			}
			glBegin(GL_LINES);
			glVertex3f(titik[i][49].getX(), titik[i][49].getY(), titik[i][49].getZ());
			glVertex3f(titik[i][0].getX(), titik[i][0].getY(), titik[i][0].getZ());
			glEnd();
		}
		//draw sumbu X(atas ke bawah)
		for (int j = 0; j < 50; j++)
		{
			for (int i = 0; i < 99; i++)
			{
				glBegin(GL_LINES);
				glVertex3f(titik[i][j].getX(), titik[i][j].getY(), titik[i][j].getZ());
				glVertex3f(titik[i + 1][j].getX(), titik[i + 1][j].getY(), titik[i + 1][j].getZ());
				glEnd();
			}
			glBegin(GL_LINES);
			glVertex3f(titik[99][j].getX(), titik[99][j].getY(), titik[99][j].getZ());
			glVertex3f(titik[0][j].getX(), titik[0][j].getY(), titik[0][j].getZ());
			glEnd();
		}
		//draw sumbu Y(kanan kiri)
	}

	/*void HiperBola(){
		int ii=0;
		int jj=0;

		for(double i = -phi; i<= phi; i+=phi/50.0){
			jj=0;
			for(double j = -phi/2; j<= phi/2; j+=phi/50.0){
				arr[ii][jj].Set(150*cos(i)*(1/cos(j)) + dx, 150*(1/cos(j))*sin(i) + dy, 150*tan(j) + dz);        
				jj++;
			}
			ii++;
		}
	}
	void HiperBola2(){
		int ii=0;
		int jj=0;


		for(double i = -phi; i<= phi; i+=phi/50.0){
			jj=0;
			if(ii <= 50){
				for(double j = -phi/2; j<= phi/2; j+=phi/50.0){
					arr[ii][jj].Set(150*tan(j)* cos(i) + dx, 150*tan(j)*sin(i) + dy, 150*(1/cos(j)) + dz);        
					jj++;
				}
			}else {
				for(double j = -phi/2; j<= phi/2; j+=phi/50.0){
					arr[ii][jj].Set(150*tan(j)* cos(i) + dx, 150*tan(j)*sin(i) + dy, -150*(1/cos(j)) + dz);            
					jj++;
				}
			}
			ii++;
		}
	}
	void EllipticCone(){
		int ii=0;
		int jj=0;


		for(double i = -phi; i<= phi; i+=phi/50.0){
			jj=0;
			for(double j = -phi/2; j<= phi/2; j+=phi/50.0){
				arr[ii][jj].Set(150*j*cos(i) + dx, 150*j*sin(i) + dy, 150*j + dz);        
				jj++;
			}
			ii++;
		}
	}
	void EllipticPara(){
		int ii=0;
		int jj=0;


		for(double i = -phi; i<= phi; i+=phi/50.0){
			jj=0;
			for(double j = 0; j<= phi; j+=phi/50.0){
				arr[ii][jj].Set(150*j*cos(i) + dx, 150*j*sin(i) + dy, 15*j*j + dz);        
				jj++;
			}
			ii++;
		}
	}
	void HiperPara(){
		int ii=0;
		int jj=0;


		for(double i = -phi; i<= phi; i+=phi/50.0){
			jj=0;
			for(double j = 0; j<= phi/2; j+=phi/50.0){
				arr[ii][jj].Set(200*j*tan(i) + dx, 150*j*(1/cos(i)) + dy, 150*j*j + dz);        
				jj++;
			}
			ii++;
		}
	}*/

	void kepala(int radius) { 
		int ii=0, jj;
		for (double i=-phi; i<=phi; i+=phi/50.0){
			jj=0;
			for (double j=-phi/2; j<=phi/2; j+=phi/50.0){
				//elips
				titik[ii][jj].setX(radius*cos(i)*cos(j));
				titik[ii][jj].setY(radius*sin(i)*cos(j));
				titik[ii][jj].setZ(radius*sin(j));
				jj++;
			}
			ii++;
		}
	}

	void badan (int radius){
		int ii=0, jj;
		for (double i=-phi; i<=phi; i+=phi/50.0){
			jj=0;
			for (double j=-phi/2; j<=phi/2; j+=phi/50.0){
				//elips
				titik[ii][jj].setX(radius*cos(i)*cos(j)*2);
				titik[ii][jj].setY(radius*sin(i)*cos(j));
				titik[ii][jj].setZ(radius*sin(j));
				jj++;
			}
			ii++;
		}
	}

	void ekor (int radius){
		int ii=0, jj;
		for (double i=-phi; i<=phi; i+=phi/50.0){
			jj=0;
			for (double j=-phi/2; j<=phi/2; j+=phi/50.0){
				//elips
				titik[ii][jj].setX(radius*cos(i)*cos(j)*5);
				titik[ii][jj].setY(radius*sin(i)*cos(j)/2);
				titik[ii][jj].setZ(radius*sin(j)/2);
				jj++;
			}
			ii++;
		}
	}

	void kakiatas (int radius){
		int ii = 0;
		int jj = 0;
		for (double i=-phi; i<=phi; i+=phi/50.0){
			jj=0;
			for (double j=-phi/2; j<=phi/2; j+=phi/50.0){
				//elips
				titik[ii][jj].setX(radius*cos(i)*cos(j)/2);
				titik[ii][jj].setY(radius*sin(i)*cos(j)*2);
				titik[ii][jj].setZ(radius*sin(j)/2);
				jj++;
			}
			ii++;
		}
	}

	void kakibawah (int radius){
		int ii = 0;
		int jj = 0;
		for (double i=-phi; i<=phi; i+=phi/50.0){
			jj=0;
			for (double j=-phi/2; j<=phi/2; j+=phi/50.0){
				//elips
				titik[ii][jj].setX(radius*cos(i)*cos(j)/2);
				titik[ii][jj].setY(radius*sin(i)*cos(j)*6);
				titik[ii][jj].setZ(radius*sin(j)/2);
				jj++;
			}
			ii++;
		}
	}

	void sayapdepan (int radius){
		int ii=0, jj;
		for (double i=-phi; i<=phi; i+=phi/50.0){
			jj=0;
			for (double j=-phi/2; j<=phi/2; j+=phi/50.0){
				//elips
				titik[ii][jj].setX(radius*cos(i)*cos(j)/2);
				titik[ii][jj].setY(radius*sin(i)*cos(j)/20);
				titik[ii][jj].setZ(radius*sin(j)*2);
				jj++;
			}
			ii++;
		}
	}

	void mata (int radius){
		int ii=0, jj;
		for (double i=-phi; i<=phi; i+=phi/50.0){
			jj=0;
			for (double j=-phi/2; j<=phi/2; j+=phi/50.0){
				//elips
				titik[ii][jj].setX(radius*cos(i)*cos(j)/2);
				titik[ii][jj].setY(radius*sin(i)*cos(j));
				titik[ii][jj].setZ(radius*sin(j));
				jj++;
			}
			ii++;
		}
	}

	void tangkai(int radius){
		int ii=0, jj;
		for (double i=-phi; i<=phi; i+=phi/50.0){
			jj=0;
			for (double j=-phi/2; j<=phi/2; j+=phi/50.0){
				//elips
				titik[ii][jj].setX(radius*cos(i)*cos(j));
				titik[ii][jj].setY(radius*sin(i)*cos(j) * 20);
				titik[ii][jj].setZ(radius*sin(j));
				jj++;
			}
			ii++;
		}
	}

	void langit(int radius){
		for (int i = 1; i <= 1000; i++){
			for (int j = 1; j <= 1000; j++){
				titik[i][j].setX(i);
				titik[i][j].setY(j);
				titik[i][j].setZ(0);
			}
		}
	}

	/*Matrix getTransform() {
		Matrix temp;
		while (tempTransform.empty() == false) {
			temp = temp * tempTransform.top();
			tempTransform.pop();
		}
		return temp;
	}*/

	void transform(Matrix mat) {
		for (int i=0; i<100; i++) {
			for (int j=0; j<50; j++) {
				titik[i][j] = mat * titik[i][j];
			}
		}
	}
};