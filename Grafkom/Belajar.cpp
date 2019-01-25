#include "Hierarchy.h"
#include <iostream>

using namespace std;

Hierarchy obj[40];
//int parent[3] = {-1, 0, 1};
Matrix pos_badan, pos_ekor, pos_kakiatas1, pos_kakiatas2, pos_kakiatas3, pos_kakiatas4, pos_kakiatas5, pos_kakiatas6, rotz_kakiatas1, rotz_kakiatas2, rotz_kakiatas3, rotz_kakiatas4, rotz_kakiatas5, rotz_kakiatas6, roty_kepala;
Matrix trans1, trans2, rotx_kakiatas1, rotx_kakiatas2, rotx_kakiatas3, rotx_kakiatas4, rotx_kakiatas5, rotx_kakiatas6, rotx_kakibawah1, rotx_kakibawah2, rotx_kakibawah3, rotx_kakibawah4, rotx_kakibawah5, rotx_kakibawah6;
Matrix pos_kakibawah1, pos_kakibawah2, pos_kakibawah3, pos_kakibawah4, pos_kakibawah5, pos_kakibawah6, rotz_kakibawah1, rotz_kakibawah2, rotz_kakibawah3, rotz_kakibawah4, rotz_kakibawah5, rotz_kakibawah6, rotx_kepala;
Matrix pos_invisible, rot_invisible1, rot_invisible2, rot_invisible3, rot_invisible4, pos_jalan, rotz_kepala, pos_tangkai, pos_bunga, pos_telur, pos_langit1, pos_langit2;
Matrix pos_inkaki, rot_inkaki1, rot_inkaki2, rot_inkaki3, rot_inkaki4, pos_mata1, pos_mata2, rotx_mata1, rotx_mata2, roty_mata1, roty_mata2, rot_mata;
double degree = 2;
Matrix pos_kepala, pos_sayapdepan1, pos_sayapdepan2, pos_sayapbelakang1, pos_sayapbelakang2, roty_sayapdepan1, roty_sayapdepan2, roty_sayapbelakang1, roty_sayapbelakang2;

void Display(){
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glRotatef(-1, -1, -1, -1);
	//obj[0].setPos(pos*rot2);
	obj[0].draw(0.2, 0.5, 0.2, 1, obj);
	obj[1].draw(0.2, 0.5, 0.2, 1, obj);
	obj[2].draw(0.2, 0.5, 0.2, 1, obj);
	obj[9].draw(0.2, 0.4, 0.2, 1, obj);
	obj[10].draw(0.2, 0.4, 0.2, 1, obj);
	obj[11].draw(0.2, 0.4, 0.2, 1, obj);
	obj[12].draw(0.2, 0.4, 0.2, 1, obj);
	obj[13].draw(0.2, 0.4, 0.2, 1, obj);
	obj[14].draw(0.2, 0.4, 0.2, 1, obj);
	obj[19].draw(0.8, 0.8, 0.8, 0.7, obj);
	obj[20].draw(0.8, 0.8, 0.8, 0.7, obj);
	obj[21].draw(0.8, 0.8, 0.8, 0.7, obj);
	obj[22].draw(0.8, 0.8, 0.8, 0.7, obj);
	obj[23].draw(0.2, 0.3, 0.2, 1, obj);
	obj[24].draw(0.2, 0.3, 0.2, 1, obj);
	obj[25].draw(0.2, 0.3, 0.2, 1, obj);
	obj[26].draw(0.2, 0.3, 0.2, 1, obj);
	obj[27].draw(0.2, 0.3, 0.2, 1, obj);
	obj[28].draw(0.2, 0.3, 0.2, 1, obj);
	obj[29].draw(1, 1, 1, 1, obj);
	obj[30].draw(1, 1, 1, 1, obj);
	obj[31].draw(1, 1, 1, 1, obj);
	obj[32].draw(1, 1, 1, 1, obj);
	obj[33].draw(0, 1, 0, 1, obj);
	obj[34].draw(1, 0, 0.7, 1, obj);
	obj[35].draw(1, 1, 0, 1, obj);
	//obj[36].draw(1, 1, 0, 1, obj);
	glutSwapBuffers();
	degree+=2;
}

void whenidle(){
	glutPostRedisplay();
}

void DoInit(){
	glOrtho(-200, 200, -200, 200, -1000, 1000); //view type: ortho vs perspective
	glClearColor(1, 0.7, 0, 0);

	//Badan
	pos_badan.translation(25, 0, 0);
	
	//Ekor
	pos_ekor.translation(25, 0, 0);

	//Kaki atas
	pos_kakiatas1.translation(-10, -10, 5);
	rotz_kakiatas1.rotatez(-30);
	rotx_kakiatas1.rotatex(60);
	pos_kakiatas2.translation(0, -12, 5);
	//rot_kakiatas2.rotatez(90);
	rotx_kakiatas2.rotatex(60);
	pos_kakiatas3.translation(10, -10, 5);
	rotz_kakiatas3.rotatez(30);
	rotx_kakiatas3.rotatex(60);
	pos_kakiatas4.translation(-10, -10, -5);
	rotz_kakiatas4.rotatez(-30);
	rotx_kakiatas4.rotatex(-60);
	pos_kakiatas5.translation(0, -12, -5);
	//rot_kakiatas5.rotatez(90);
	rotx_kakiatas5.rotatex(-60);
	pos_kakiatas6.translation(10, -10, -5);
	rotz_kakiatas6.rotatez(30);
	rotx_kakiatas6.rotatex(-60);

	//Kaki bawah
	pos_kakibawah1.translation(0, -10, -10);
	//rotz_kakibawah1.rotatez(0);
	rotx_kakibawah1.rotatex(-60);
	pos_kakibawah2.translation(0, -10, -10);
	//rot_kakibawah2.rotatez(90);
	rotx_kakibawah2.rotatex(-60);
	pos_kakibawah3.translation(0, -10, -10);
	//rotz_kakibawah3.rotatez(0);
	rotx_kakibawah3.rotatex(-60);
	pos_kakibawah4.translation(0, -10, 10);
	//rotz_kakibawah4.rotatez(0);
	rotx_kakibawah4.rotatex(60);
	pos_kakibawah5.translation(0, -10, 10);
	//rot_kakibawah5.rotatez(90);
	rotx_kakibawah5.rotatex(60);
	pos_kakibawah6.translation(0, -10, 10);
	//rotz_kakibawah6.rotatez(0);
	rotx_kakibawah6.rotatex(60);
	trans1.translation(-10, 0, 0);
	trans2.translation(10, 0, 0);

	//Invisible Sayap
	pos_invisible.translation(0, 0, 0);
	rot_invisible1.rotatex(5);
	rot_invisible2.rotatex(-5);
	rot_invisible3.rotatex(-5);
	rot_invisible4.rotatex(5);

	//Invisible Kaki
	pos_inkaki.translation(0, 0, 0);
	rot_inkaki1.rotatex(1);
	rot_inkaki2.rotatex(-1);
	rot_inkaki3.rotatex(-1);
	rot_inkaki4.rotatex(1);

	//Sayap
	pos_sayapdepan1.translation(-8, 7, 30);
	pos_sayapdepan2.translation(-8, 7, -30);
	pos_sayapbelakang1.translation(5, 7, 25);
	pos_sayapbelakang2.translation(5, 7, -25);
	roty_sayapdepan1.rotatey(10);
	roty_sayapdepan2.rotatey(-10);
	roty_sayapbelakang1.rotatey(-10);
	roty_sayapbelakang2.rotatey(10);

	//Mata
	pos_mata1.translation(-9, 2, 5);
	pos_mata2.translation(-9, 2, -5);
	rotx_mata1.rotatex(20);
	rotx_mata2.rotatex(-20);
	roty_mata1.rotatey(-30);
	roty_mata2.rotatey(30);
	rot_mata.rotatez(90);

	//Tangkai
	pos_tangkai.translation(220, -120, 0);

	//Bunga
	pos_bunga.translation(0, 100, 0);

	//Telur
	pos_telur.translation(220, -20, 0);

	//Kepala
	roty_kepala.rotatey(-10);
	rotx_kepala.rotatex(10);
	pos_jalan.translation(-5, 1, 0);

	//Langit
	/*pos_langit1.translation(-500, 500, 0);
	pos_langit2.translation(-500, -500, 0);*/

	obj[0].setKepala(1, 10);
	//obj[0].setPos(pos_kepala);

	obj[1].setParent(0);
	obj[1].setBadan(1, 10);
	obj[1].setPos(pos_badan);

	obj[2].setParent(1);
	obj[2].setEkor(1, 10);
	obj[2].setPos(pos_ekor);

	obj[3].setParent(1);
	//obj[3].setKakiAtas(1, 2);
	obj[3].setPos(pos_inkaki);

	obj[4].setParent(1);
	//obj[4].setKakiAtas(1, 2);
	obj[4].setPos(pos_inkaki);

	obj[5].setParent(1);
	//obj[5].setKakiAtas(1, 2);
	obj[5].setPos(pos_inkaki);

	obj[6].setParent(1);
	//obj[6].setKakiAtas(1, 2);
	obj[6].setPos(pos_inkaki);

	obj[7].setParent(1);
	//obj[7].setKakiAtas(1, 2);
	obj[7].setPos(pos_inkaki);

	obj[8].setParent(1);
	//obj[8].setKakiAtas(1, 2);
	obj[8].setPos(pos_inkaki);

	obj[9].setParent(3);
	obj[9].setKakiAtas(1, 2);
	obj[9].setPos(pos_kakiatas1 * rotz_kakiatas1 * rotx_kakiatas1);

	obj[10].setParent(4);
	obj[10].setKakiAtas(1, 2);
	obj[10].setPos(pos_kakiatas2 * rotx_kakiatas2);

	obj[11].setParent(5);
	obj[11].setKakiAtas(1, 2);
	obj[11].setPos(pos_kakiatas3 * rotz_kakiatas3 * rotx_kakiatas3);

	obj[12].setParent(6);
	obj[12].setKakiAtas(1, 2);
	obj[12].setPos(pos_kakiatas4 * rotz_kakiatas4 * rotx_kakiatas4);

	obj[13].setParent(7);
	obj[13].setKakiAtas(1, 2);
	obj[13].setPos(pos_kakiatas5 * rotx_kakiatas5);

	obj[14].setParent(8);
	obj[14].setKakiAtas(1, 2);
	obj[14].setPos(pos_kakiatas6 * rotz_kakiatas6 * rotx_kakiatas6);

	obj[15].setParent(1);
	//obj[15].setKepala(1, 5);
	obj[15].setPos(pos_invisible);

	obj[16].setParent(1);
	//obj[16].setKepala(1, 5);
	obj[16].setPos(pos_invisible);

	obj[17].setParent(1);
	//obj[17].setKepala(1, 5);
	obj[17].setPos(pos_invisible);

	obj[18].setParent(1);
	//obj[18].setKepala(1, 5);
	obj[18].setPos(pos_invisible);

	obj[19].setParent(15);
	obj[19].setSayapDepan(1, 15);
	obj[19].setPos(pos_sayapdepan1 * roty_sayapdepan1);

	obj[20].setParent(16);
	obj[20].setSayapDepan(1, 15);
	obj[20].setPos(pos_sayapdepan2 * roty_sayapdepan2);

	obj[21].setParent(17);
	obj[21].setSayapDepan(1, 15);
	obj[21].setPos(pos_sayapbelakang1 * roty_sayapbelakang1);

	obj[22].setParent(18);
	obj[22].setSayapDepan(1, 15);
	obj[22].setPos(pos_sayapbelakang2 * roty_sayapbelakang2);

	obj[23].setParent(9);
	obj[23].setKakiBawah(1, 2);
	obj[23].setPos(pos_kakibawah1 * rotx_kakibawah1);

	obj[24].setParent(10);
	obj[24].setKakiBawah(1, 2);
	obj[24].setPos(pos_kakibawah2 * rotx_kakibawah2);

	obj[25].setParent(11);
	obj[25].setKakiBawah(1, 2);
	obj[25].setPos(pos_kakibawah3 * rotx_kakibawah3);

	obj[26].setParent(12);
	obj[26].setKakiBawah(1, 2);
	obj[26].setPos(pos_kakibawah4 * rotx_kakibawah4);

	obj[27].setParent(13);
	obj[27].setKakiBawah(1, 2);
	obj[27].setPos(pos_kakibawah5 * rotx_kakibawah5);

	obj[28].setParent(14);
	obj[28].setKakiBawah(1, 2);
	obj[28].setPos(pos_kakibawah6 * rotx_kakibawah6);

	obj[29].setParent(1);
	//obj[29].setKakiBawah(1, 2);
	obj[29].setPos(pos_kakibawah6 * rotx_kakibawah6);

	obj[30].setParent(14);
	//obj[30].setKakiBawah(1, 2);
	obj[30].setPos(pos_kakibawah6 * rotx_kakibawah6);

	obj[31].setParent(0);
	obj[31].setMata(1, 2);
	obj[31].setPos(pos_mata1 * rotx_mata1 * roty_mata1);

	obj[32].setParent(0);
	obj[32].setMata(1, 2);
	obj[32].setPos(pos_mata2 * rotx_mata2 * roty_mata2);

	obj[33].setTangkai(1, 5);
	obj[33].setPos(pos_tangkai);

	obj[34].setParent(33);
	obj[34].setKepala(1, 20);
	obj[34].setPos(pos_bunga);

	obj[35].setKepala(1, 3);
	obj[35].setPos(pos_telur);

	/*obj[36].setLangit(1, 0);
	obj[36].setPos(pos_langit1);*/

	//obj[36].
	
	/*cout << "q -> RotateZ Red" << endl;
	cout << "w -> RotateZ Green" << endl;
	cout << "e -> RotateZ Blue" << endl;
	cout << "r -> RotateZ White" << endl;
	cout << "a -> TranslasiX -10 Red" << endl;
	cout << "z -> TranslasiX 10 Red" << endl;
	cout << "s -> TranslasiX -10 Green" << endl;
	cout << "x -> TranslasiX 10 Green" << endl;
	cout << "d -> TranslasiX -10 Blue" << endl;
	cout << "c -> TranslasiX 10 Blue" << endl;
	cout << "f -> TranslasiX -10 White" << endl;
	cout << "v -> TranslasiX 10 White" << endl;*/
}

void KeyboardEvent(unsigned char key, int x, int y){
	if (key == 'q') {
		obj[0].addTransform(roty_kepala);
	}
	else if (key == 'w') {
		obj[0].addTransform(rotx_kepala);
	}
	else if (key == 'e') {
		obj[15].addTransform(rot_invisible1);
		obj[16].addTransform(rot_invisible2);
		obj[17].addTransform(rot_invisible1);
		obj[18].addTransform(rot_invisible2);
	}
	else if (key == 'f'){
		obj[15].addTransform(rot_invisible3);
		obj[16].addTransform(rot_invisible4);
		obj[17].addTransform(rot_invisible3);
		obj[18].addTransform(rot_invisible4);
	}
	//else if (key == 'r') {
	//	obj[3].addTransform(rot); // rotate white
	//}
	else if (key == 'a') {
		obj[0].addTransform(trans1); // translasi red kiri
	}
	else if (key == 'z') {
		obj[0].addTransform(trans2); // translasi red kanan
	}
	else if (key == 's') {
		obj[3].addTransform(rot_inkaki1);
		obj[4].addTransform(rot_inkaki1);
		obj[5].addTransform(rot_inkaki1);
		obj[6].addTransform(rot_inkaki2);
		obj[7].addTransform(rot_inkaki2);
		obj[8].addTransform(rot_inkaki2);
	}
	else if (key == 'x') {
		obj[3].addTransform(rot_inkaki3);
		obj[4].addTransform(rot_inkaki3);
		obj[5].addTransform(rot_inkaki3);
		obj[6].addTransform(rot_inkaki4);
		obj[7].addTransform(rot_inkaki4);
		obj[8].addTransform(rot_inkaki4);
	}
	else if (key == 'd') {
		obj[2].addTransform(trans1); // translasi blue kiri
	}
	else if (key == 'c') {
		obj[2].addTransform(trans2); // translasi blue kanan
	}
	//else if (key == 'f') {
	//	obj[3].addTransform(trans1); // translasi white kiri
	//}
	//else if (key == 'v') {
	//	obj[3].addTransform(trans2); // translasi white kanan
	//}
}
int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;
bool status1 = false, status2 = false, status4 = false;

void timer_func_sayap(int n){
	if (counter1 >= 0 && status1 == false){
		obj[15].addTransform(rot_invisible1);
		obj[16].addTransform(rot_invisible2);
		obj[17].addTransform(rot_invisible1);
		obj[18].addTransform(rot_invisible2);
		counter1++;
		if (counter1 == 9){
			status1 = true;
		}
	} else if (counter1 <= 9 && status1 == true){
		obj[15].addTransform(rot_invisible3);
		obj[16].addTransform(rot_invisible4);
		obj[17].addTransform(rot_invisible3);
		obj[18].addTransform(rot_invisible4);
		counter1--;
		if (counter1 == 0){
			status1 = false;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(n, timer_func_sayap, n);
}

void timer_func_kaki(int n){
	if (counter2 >= 0 && status2 == false){
		obj[3].addTransform(rot_inkaki1);
		obj[4].addTransform(rot_inkaki1);
		obj[5].addTransform(rot_inkaki1);
		obj[6].addTransform(rot_inkaki2);
		obj[7].addTransform(rot_inkaki2);
		obj[8].addTransform(rot_inkaki2);
		counter2++;
		if (counter2 == 10){
			status2 = true;
		}
	} else if (counter2 <= 10 && status2 == true){
		obj[3].addTransform(rot_inkaki3);
		obj[4].addTransform(rot_inkaki3);
		obj[5].addTransform(rot_inkaki3);
		obj[6].addTransform(rot_inkaki4);
		obj[7].addTransform(rot_inkaki4);
		obj[8].addTransform(rot_inkaki4);
		counter2--;
		if (counter2 == 0){
			status2 = false;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(n, timer_func_kaki, n);
}

void timer_func_mata(int n){
	if (counter3 % 5 == 0 && counter3 != 0){
		obj[31].addTransform(rot_mata);
		obj[32].addTransform(rot_mata);
	}
	counter3++;
	glutPostRedisplay();
	glutTimerFunc(n, timer_func_mata, n);
}

void timer_func_jalan(int n){
	if (counter4 >= 0 && counter4 < 30){
		obj[0].addTransform(pos_jalan);
	} else if (counter4 == 30){
		roty_kepala.rotatey(-20);
	} else if (counter4 > 30 && counter4 < 38){
		obj[0].addTransform(roty_kepala);
	} else if (counter4 == 38){
		pos_jalan.translation(-5, 0, 3);
	} else if (counter4 > 38 && counter4 < 43){
		obj[0].addTransform(pos_jalan);
	} else if (counter4 == 47){
		rotz_kepala.rotatez(-10);
		pos_jalan.translation(-5, 1, -2);
	} else if (counter4 > 47 && counter4 < 51){
		obj[0].addTransform(rotz_kepala * pos_jalan);
	} else if (counter4 >= 51 && counter4 < 62){
		obj[0].addTransform(pos_jalan);
	} else if (counter4 == 62){
		rotz_kepala.rotatez(10);
		pos_jalan.translation(-5, -1, -2);
		pos_tangkai.translation(-20, 0, 0);
	} else if (counter4 > 62 && counter4 < 66){
		obj[0].addTransform(rotz_kepala * pos_jalan);
		obj[33].addTransform(pos_tangkai);
	} else if (counter4 >= 66 && counter4 < 160){
		obj[0].addTransform(pos_jalan);
	} else if (counter4 == 160){
		roty_kepala.rotatey(20);
		rotz_kepala.rotatez(20);
	} else if (counter4 > 160 && counter4 < 167){
		obj[0].addTransform(roty_kepala * rotz_kepala * pos_jalan);
	} else if (counter4 == 167){
		pos_jalan.translation(0, 0, 0);
	} else if (counter4 > 167 && counter4 < 170){
		obj[0].addTransform(pos_jalan);
	} else if (counter4 == 170){
		pos_telur.translation(-50, 0, 0);
		obj[35].addTransform(pos_telur);
		pos_telur.translation(0, -10, 0);
	} else if (counter4 > 170 && counter4 < 190){
		obj[35].addTransform(pos_telur);
	} else if (counter4 == 190){
		rotz_kepala.rotatez(-20);
		pos_jalan.translation(-5, 1, 0);
	} else if (counter4 > 190 && counter4 < 195){
		obj[0].addTransform(rotz_kepala * pos_jalan);
	} else if (counter4 >= 195 && counter4 < 200){
		obj[0].addTransform(pos_jalan);
		rotx_kepala.rotatex(20);
	} else if (counter4 >= 200 && counter4 < 205){
		obj[0].addTransform(rotx_kepala * pos_jalan);
	} else if (counter4 > 205 && counter4 < 300){
		obj[0].addTransform(pos_jalan);
	} else if (counter4 == 300){
		exit(NULL);
	}
	counter4++;
	glutPostRedisplay();
	glutTimerFunc(n, timer_func_jalan, n);
}

void main(int argc, char**argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Dragonfly");
	glutKeyboardFunc(KeyboardEvent);
	glutDisplayFunc(Display);
	glutIdleFunc(whenidle);
	timer_func_sayap(0.001);
	timer_func_kaki(1);
	timer_func_mata(1);
	timer_func_jalan(1);
	DoInit();
	glutMainLoop();


}