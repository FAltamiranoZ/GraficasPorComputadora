#include "GL/glut.h"
#include <math.h>

//GLint cont = 20;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 120.0, 0.0, 120.0);//Esto es lo que afecta verdaderamente a la ventana
}

void lineSegment(void) {
	int i = 8, j = 0, pos = 40, cont = 0;
	float angle = 0, k = 0, x = 0, y = 0, a = 2, b = 2;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS); //Rectángulos
	glColor3f(0.349, 0.714, 0.329);
	//Marco izquierdo
	glVertex2i(4, 4);
	glVertex2i(4, 100);
	glVertex2i(8, 100);
	glVertex2i(8, 4);
	//Marco derecho
	glVertex2i(96, 4);
	glVertex2i(96, 100);
	glVertex2i(100, 100);
	glVertex2i(100, 4);
	//Marco superior
	glVertex2i(8, 96);
	glVertex2i(96, 96);
	glVertex2i(96, 100);
	glVertex2i(8, 100);
	//Marco inferior
	glVertex2i(8, 4);
	glVertex2i(96, 4);
	glVertex2i(96, 8);
	glVertex2i(8, 8);

	glColor3f(0.349, 0.714, 0.329);
	//Blanco izquierdo
	glVertex2i(12, 12);
	glVertex2i(24, 12);
	glVertex2i(24, 92);
	glVertex2i(12, 92);
	//Blanco derecho
	glVertex2i(80, 12);
	glVertex2i(92, 12);
	glVertex2i(92, 92);
	glVertex2i(80, 92);
	//Blanco superior
	glVertex2i(24, 80);
	glVertex2i(80, 80);
	glVertex2i(80, 92);
	glVertex2i(24, 92);
	//Blanco inferior
	glVertex2i(24, 12);
	glVertex2i(80, 12);
	glVertex2i(80, 24);
	glVertex2i(24, 24);

	glColor3f(0.694, 0.447, 0.125);
	//Exterior negro izquierdo
	glVertex2i(8, 8);
	glVertex2i(8, 96);
	glVertex2i(12, 96);
	glVertex2i(12, 8);
	//Exterior negro derecho
	glVertex2i(92, 8);
	glVertex2i(92, 96);
	glVertex2i(96, 96);
	glVertex2i(96, 8);
	//Exterior negro superior
	glVertex2i(12, 96);
	glVertex2i(92, 96);
	glVertex2i(92, 92);
	glVertex2i(12, 92);
	//Exterior negro inferior
	glVertex2i(12, 8);
	glVertex2i(92, 8);
	glVertex2i(92, 12);
	glVertex2i(12, 12);
	//Interior negro izquierdo
	glVertex2i(24, 24);
	glVertex2i(28, 24);
	glVertex2i(28, 80);
	glVertex2i(24, 80);
	//Interior negro derecho
	glVertex2i(76, 24);
	glVertex2i(80, 24);
	glVertex2i(80, 80);
	glVertex2i(76, 80);
	//Interior negro superior
	glVertex2i(28, 76);
	glVertex2i(76, 76);
	glVertex2i(76, 80);
	glVertex2i(28, 80);
	//Interior negro inferior
	glVertex2i(28, 24);
	glVertex2i(76, 24);
	glVertex2i(76, 28);
	glVertex2i(28, 28);
	//Fondo negro
	glVertex2i(28, 28);
	glVertex2i(76, 28);
	glVertex2i(76, 76);
	glVertex2i(28, 76);
	glEnd();


	glBegin(GL_LINES);//Lineas
	glColor3f(1.0, 1.0, 1.0);
	while (i != 32) { 	//Esquina Izquierda
		//Verticales
		glVertex2f(i, 8);
		glVertex2f(i, 96);
		//Horizontales
		glVertex2f(8, i);
		glVertex2f(96, i);
		i = i + 4;
	}
	i = 76;
	while (i != 100) { 	//Esquina Derecha
		//Verticales
		glVertex2f(i, 8);
		glVertex2f(i, 96);
		//Horizontales
		glVertex2f(8, i);
		glVertex2f(96, i);
		i = i + 4;
	}
	i = 32;
	while (i != 76) { 	//Centro
		//Verticales
		glVertex2f(i, 8);
		glVertex2f(i, 28);
		glVertex2f(i, 76);
		glVertex2f(i, 96);
		//Horizontales
		glVertex2f(8, i);
		glVertex2f(28, i);
		glVertex2f(76, i);
		glVertex2f(96, i);
		i = i + 4;
	}
	glEnd();


	//Circulos
	glColor3f(1.0, 0.345, 0.345);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior izquierdo grande
		angle = j*3.142 / 180;
		//El izquierdo es x y el derecho es y; cualquier modificación sobre pos afecta la posición, sobre angle afecta la forma.
		glVertex2f((pos)+12*cos(angle), (pos+24) +12* sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior derecho grande
		angle = j*3.142 / 180;
		glVertex2f((pos + 24) + 12 * cos(angle), (pos)+12 * sin(angle));
	}
	glEnd();
	glColor3f(0.243, 0.573, 0.914);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior derecho grande
		angle = j*3.142 / 180;
		glVertex2f((pos + 24) + 12 * cos(angle), (pos + 24) + 12 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior izquierdo grande
		angle = j*3.142 / 180;
		glVertex2f((pos)+12 * cos(angle), (pos)+12 * sin(angle));
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior izquierdo chico
		angle = j*3.142 / 180;
		glVertex2f((pos)+10 * cos(angle), (pos + 24) + 10 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior derecho chico
		angle = j*3.142 / 180;
		glVertex2f((pos + 24) + 10 * cos(angle), (pos)+10 * sin(angle));
	}
	glEnd();
	glColor3f(0.026, 0.384, 0.761);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior derecho chico
		angle = j*3.142 / 180;
		glVertex2f((pos + 24) + 10 * cos(angle), (pos + 24) + 10 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior izquierdo chico
		angle = j*3.142 / 180;
		glVertex2f((pos)+10 * cos(angle), (pos)+10 * sin(angle));
	}
	glEnd();


	glBegin(GL_QUADS); //Rectángulos de los círculos
	glColor3f(1.0, 0.345, 0.345);
	//Rectángulo Rojo
	//Exterior izquierdo superior
	glVertex2f(31.5, 55.5);
	glVertex2f(33, 57);
	glVertex2f(36.5, 53.5);
	glVertex2f(35, 52);
	//Exterior izquierdo inferior
	glVertex2f(57, 33);
	glVertex2f(55.5, 31.5);
	glVertex2f(42.5, 44.5);
	glVertex2f(44, 46);
	//Exterior derecho superior
	glVertex2f(48.5, 72.5);
	glVertex2f(47, 71);
	glVertex2f(60, 58);
	glVertex2f(61.5, 59.5);
	//Exterior derecho inferior
	glVertex2f(71, 47);
	glVertex2f(72.5, 48.5);
	glVertex2f(69, 52);
	glVertex2f(67.5, 50.5);
	glColor3f(1.0, 0.0, 0.0);
	//Interior izquierdo superior
	glVertex2f(33, 57);
	glVertex2f(36.5, 53.5);
	glVertex2f(42.5, 59.5);
	glVertex2f(39, 63);
	//Interior izquierdo inferior
	glVertex2f(57, 33);
	glVertex2f(63, 39);
	glVertex2f(50, 52);
	glVertex2f(44, 46);
	//Interior derecho superior
	glVertex2f(47, 71);
	glVertex2f(60, 58);
	glVertex2f(54, 52);
	glVertex2f(41, 65);
	//Interior derecho inferior
	glVertex2f(71, 47);
	glVertex2f(67.5, 50.5);
	glVertex2f(61.5, 44.5);
	glVertex2f(65, 41);


	glColor3f(0.243, 0.573, 0.914);
	//Rectángulo Azul
	//Exterior derecho superior
	glVertex2f(55.5, 72.5);
	glVertex2f(57, 71);
	glVertex2f(53.5, 67.5); //3.5 y 1.5
	glVertex2f(52, 69);
	//Exterior derecho inferior//13
	glVertex2f(72.5, 55.5);
	glVertex2f(71, 57);
	glVertex2f(58, 44);
	glVertex2f(59.5, 42.5);
	//Exterior izquierdo superior
	glVertex2f(31.5, 48.5);
	glVertex2f(33, 47);
	glVertex2f(46, 60);
	glVertex2f(44.5, 61.5);
	//Exterior izquierdo inferior
	glVertex2f(48.5, 31.5);
	glVertex2f(47, 33);
	glVertex2f(50.5, 36.5);
	glVertex2f(52, 35);
	glColor3f(0.026, 0.384, 0.761);
	//Interior derecho superior
	glVertex2f(57, 71);
	glVertex2f(53.5, 67.5);
	glVertex2f(59.5, 61.5);
	glVertex2f(63, 65);
	//Interior derecho inferior
	glVertex2f(71, 57);
	glVertex2f(58, 44);
	glVertex2f(52, 50);
	glVertex2f(65, 63);
	//Interior izquierdo superior
	glVertex2f(33, 47);
	glVertex2f(46, 60);
	glVertex2f(52, 54);
	glVertex2f(39, 41);
	//Interior izquierdo inferior
	glVertex2f(47, 33);
	glVertex2f(50.5, 36.5);
	glVertex2f(44.5, 42.5);
	glVertex2f(41, 39);

	glColor3f(0.694, 0.447, 0.125);
	//Rectángulos cafes
	//Superior izquierdo//3.5 y 2
	glVertex2f(39, 63);
	glVertex2f(41, 65);
	glVertex2f(44.5, 61.5);
	glVertex2f(42.5, 59.5);
	//Inferior Derecho
	glVertex2f(63, 39);
	glVertex2f(65, 41);
	glVertex2f(61.5, 44.5);
	glVertex2f(59.5, 42.5);
	//Inferior izquierdo
	glVertex2f(39, 41);
	glVertex2f(41, 39);
	glVertex2f(44.5, 42.5);
	glVertex2f(42.5, 44.5);
	//Superior Derecho
	glVertex2f(63, 65);
	glVertex2f(65, 63);
	glVertex2f(61.5, 59.5);
	glVertex2f(59.5, 61.5);
	glEnd();


	glColor3f(0.014, 0.451, 0.098);
	glLineWidth(3);
	glBegin(GL_LINES);//Tallo
	glVertex2f(18, 12);
	glVertex2f(18, 80);
	glEnd();
	glLineWidth(1);

	//Hojas
	glBegin(GL_POLYGON); //Hoja derecha inferior
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		//El izquierdo es x y el derecho es y; cualquier modificación sobre pos afecta la posición, sobre angle afecta la forma.
		glVertex2f((pos + 44.2) + 4 * cos(angle + 4), (pos - 10) + 2.5 * sin(angle));
		//glVertex2f((pos+posición horizontal)+ tamaño horizontal* cos(angle), (pos + posición vertical) + tamaño verticaL* sin(angle));
		//cos(angle+x) = sin(angle-x), cos(angle+20) va del punto izquierdo superior al punto derecho inferior, entre menor el ángulo más se parece a un círculo
	}
	glEnd();
	glBegin(GL_POLYGON); //Hoja central inferior
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos - 10) + 2.5 * cos(angle + 4), (pos - 24) + 4 * sin(angle));
	}
	glEnd();
	///Hojas derechas
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos - 19.4) + 2.5 * cos(angle + 4), (pos - 20) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos - 19.4) + 2.5 * cos(angle + 4), (pos - 4) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos - 19.4) + 2.5 * cos(angle + 4), (pos + 12) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos - 19.4) + 2.5 * cos(angle + 4), (pos + 28) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos - 19.4) + 2.5 * cos(angle + 4), (pos + 43.5) + 4 * sin(angle));
	}
	glEnd();
	//Hojas izquierdas
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos - 25) + 2.5 * cos(angle - 4), (pos + 36) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos - 25) + 2.5 * cos(angle - 4), (pos + 20) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos - 25) + 2.5 * cos(angle - 4), (pos + 4) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos - 25) + 2.5 * cos(angle - 4), (pos - 12) + 4 * sin(angle));
	}
	glEnd();


	//Senos
	glPointSize(1);
	glBegin(GL_POINTS);
	for (k = 32; k < 76; k = k + .01) {//punto de inicio y de fin, k+1 es la distancia entre puntos{
		x = k;
		y = 5 * sin(k *(6.284 / 30)) + 18; //y= altura; 6.284/frecuencia (entre menor mas seguido); ))+desplazamiento vertical
		glVertex2f(x, y);
		x = k;//Invertido
		y = 5 * sin(k *(6.284 / 30)) + 86;
		glVertex2f(y, x);
	}
	glEnd();
	glColor3f(0.026, 0.384, 0.761);//Seno superior
	glBegin(GL_POINTS);
	for (k = 28; k < 79.1; k = k + .01) {
		x = k;
		y = 5 * sin(k *(6.284 / 30)) + 86;
		glVertex2f(x, y);
	}
	glEnd();
	//Cosenos
	glPointSize(1);
	glBegin(GL_POINTS);
	for (k = 28; k < 76; k = k + .01) {
		x = k;
		y = 5 * cos(k *(6.284 / 30)) + 18;
		glVertex2f(x, y);
		x = k;//Invertido
		y = 5 * cos(k *(6.284 / 30)) + 86;
		glVertex2f(y, x);
	}
	glEnd();


	//Espirales
	angle = 0, pos = 84;
	x = a*pow(2.718281, b*angle)*cos(angle);
	y = a*pow(2.718281, b*angle)*sin(angle);
	for (int i = 0; i < 750; i++){//Espiral inferior derecha
		glBegin(GL_LINES);
		angle = 0.025*i;
		glVertex2f(x + pos + 1.3, y + pos - 66);
		glVertex2f(a*pow(2.718281, .032* b*angle)*cos(angle) + pos + 1.3, a*pow(2.718281, .032* b*angle)*sin(angle) + pos - 66);
		x = a*pow(2.718281, .032* b*angle)*cos(angle);
		y = a*pow(2.718281, .032* b*angle)*sin(angle);
		glEnd();
	}
	angle = 0, pos = 84;
	x = a*pow(2.718281, b*angle)*cos(angle);
	y = a*pow(2.718281, b*angle)*sin(angle);
	for (int i = 0; i < 670; i++){//Espiral superior izquierda
		glBegin(GL_LINES);
		angle = 0.025*i;
		glVertex2f(y + pos + .11,x + pos + 1.3);
		glVertex2f(a*pow(2.718281, .032* b*angle)*sin(angle) + pos + .11 , a*pow(2.718281, .032* b*angle)*cos(angle) + pos + 1.3);
		x = a*pow(2.718281, .032* b*angle)*cos(angle);
		y = a*pow(2.718281, .032* b*angle)*sin(angle);
		glEnd();
	}

































	glBegin(GL_QUADS); //Rectángulos
	glColor3f(0.349, 0.714, 0.329);
	//Marco izquierdo
	glVertex2i(-4, -4);
	glVertex2i(-4, -100);
	glVertex2i(-8, -100);
	glVertex2i(-8, -4);
	//Marco derecho
	glVertex2i(-96, -4);
	glVertex2i(-96, -100);
	glVertex2i(-100, -100);
	glVertex2i(-100, -4);
	//Marco superior
	glVertex2i(-8, -96);
	glVertex2i(-96, -96);
	glVertex2i(-96, -100);
	glVertex2i(-8, -100);
	//Marco inferior
	glVertex2i(-8, -4);
	glVertex2i(-96, -4);
	glVertex2i(-96, -8);
	glVertex2i(-8, -8);

	glColor3f(0.349, 0.714, 0.329);
	//Blanco izquierdo
	glVertex2i(-12, -12);
	glVertex2i(-24, -12);
	glVertex2i(-24, -92);
	glVertex2i(-12, -92);
	//Blanco derecho
	glVertex2i(-80, -12);
	glVertex2i(-92, -12);
	glVertex2i(-92, -92);
	glVertex2i(-80, -92);
	//Blanco superior
	glVertex2i(-24, -80);
	glVertex2i(-80, -80);
	glVertex2i(-80, -92);
	glVertex2i(-24, -92);
	//Blanco inferior
	glVertex2i(-24, -12);
	glVertex2i(-80, -12);
	glVertex2i(-80, -24);
	glVertex2i(-24, -24);

	glColor3f(0.694, 0.447, 0.125);
	//Exterior negro izquierdo
	glVertex2i(-8, -8);
	glVertex2i(-8, -96);
	glVertex2i(-12, -96);
	glVertex2i(-12, -8);
	//Exterior negro derecho
	glVertex2i(-92, -8);
	glVertex2i(-92, -96);
	glVertex2i(-96, -96);
	glVertex2i(-96, -8);
	//Exterior negro superior
	glVertex2i(-12, -96);
	glVertex2i(-92, -96);
	glVertex2i(-92, -92);
	glVertex2i(-12, -92);
	//Exterior negro inferior
	glVertex2i(-12, -8);
	glVertex2i(-92, -8);
	glVertex2i(-92, -12);
	glVertex2i(-12, -12);
	//Interior negro izquierdo
	glVertex2i(-24, -24);
	glVertex2i(-28, -24);
	glVertex2i(-28, -80);
	glVertex2i(-24, -80);
	//Interior negro derecho
	glVertex2i(-76, -24);
	glVertex2i(-80, -24);
	glVertex2i(-80, -80);
	glVertex2i(-76, -80);
	//Interior negro superior
	glVertex2i(-28, -76);
	glVertex2i(-76, -76);
	glVertex2i(-76, -80);
	glVertex2i(-28, -80);
	//Interior negro inferior
	glVertex2i(-28, -24);
	glVertex2i(-76, -24);
	glVertex2i(-76, -28);
	glVertex2i(-28, -28);
	//Fondo negro
	glVertex2i(-28, -28);
	glVertex2i(-76, -28);
	glVertex2i(-76, -76);
	glVertex2i(-28, -76);
	glEnd();
	
	glBegin(GL_LINES);//Lineas
	glColor3f(1.0, 1.0, 1.0);
	i = -8;
	while (i != -32) { 	//Esquina Izquierda
						//Verticales
		glVertex2f(i, -8);
		glVertex2f(i, -96);
		//Horizontales
		glVertex2f(-8, i);
		glVertex2f(-96, i);
		i = i - 4;
	}

	i = -76;
	while (i != -100) { 	//Esquina Derecha
						//Verticales
		glVertex2f(i, -8);
		glVertex2f(i, -96);
		//Horizontales
		glVertex2f(-8, i);
		glVertex2f(-96, i);
		i = i - 4;
	}
	
	i = -32;
	while (i != -76) { 	//Centro
						//Verticales
		glVertex2f(i, -8);
		glVertex2f(i, -28);
		glVertex2f(i, -76);
		glVertex2f(i, -96);
		//Horizontales
		glVertex2f(-8, i);
		glVertex2f(-28, i);
		glVertex2f(-76, i);
		glVertex2f(-96, i);
		i = i - 4;
	}
	glEnd();
	
	pos = -40;
	//Circulos
	glColor3f(1.0, 0.345, 0.345);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior izquierdo grande
		angle = j*3.142 / 180;
		//El izquierdo es x y el derecho es y; cualquier modificación sobre pos afecta la posición, sobre angle afecta la forma.
		glVertex2f((pos)-12 * cos(angle), (pos - 24) - 12 * sin(angle));
	}
	glEnd();
	
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior derecho grande
		angle = j*3.142 / 180;
		glVertex2f((pos - 24) - 12 * cos(angle), (pos)-12 * sin(angle));
	}
	glEnd();
	glColor3f(0.243, 0.573, 0.914);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior derecho grande
		angle = j*3.142 / 180;
		glVertex2f((pos - 24) + 12 * cos(angle), (pos - 24) - 12 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior izquierdo grande
		angle = j*3.142 / 180;
		glVertex2f((pos)-12 * cos(angle), (pos)-12 * sin(angle));
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior izquierdo chico
		angle = j*3.142 / 180;
		glVertex2f((pos)-10 * cos(angle), (pos - 24) - 10 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior derecho chico
		angle = j*3.142 / 180;
		glVertex2f((pos - 24) - 10 * cos(angle), (pos)-10 * sin(angle));
	}
	glEnd();
	glColor3f(0.026, 0.384, 0.761);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior derecho chico
		angle = j*3.142 / 180;
		glVertex2f((pos - 24) + 10 * cos(angle), (pos - 24) - 10 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior izquierdo chico
		angle = j*3.142 / 180;
		glVertex2f((pos)-10 * cos(angle), (pos)-10 * sin(angle));
	}
	glEnd();

	
	
	glBegin(GL_QUADS); //Rectángulos de los círculos
	glColor3f(1.0, 0.345, 0.345);
	//Rectángulo Rojo
	//Exterior izquierdo superior
	glVertex2f(-31.5, -55.5);
	glVertex2f(-33, -57);
	glVertex2f(-36.5, -53.5);
	glVertex2f(-35, -52);
	//Exterior izquierdo inferior
	glVertex2f(-57, -33);
	glVertex2f(-55.5, -31.5);
	glVertex2f(-42.5, -44.5);
	glVertex2f(-44, -46);
	//Exterior derecho superior
	glVertex2f(-48.5, -72.5);
	glVertex2f(-47, -71);
	glVertex2f(-60, -58);
	glVertex2f(-61.5, -59.5);
	//Exterior derecho inferior
	glVertex2f(-71, -47);
	glVertex2f(-72.5, -48.5);
	glVertex2f(-69, -52);
	glVertex2f(-67.5, -50.5);
	glColor3f(1.0, 0.0, 0.0);
	//Interior izquierdo superior
	glVertex2f(-33, -57);
	glVertex2f(-36.5, -53.5);
	glVertex2f(-42.5, -59.5);
	glVertex2f(-39, -63);
	//Interior izquierdo inferior
	glVertex2f(-57, -33);
	glVertex2f(-63, -39);
	glVertex2f(-50, -52);
	glVertex2f(-44, -46);
	//Interior derecho superior
	glVertex2f(-47, -71);
	glVertex2f(-60, -58);
	glVertex2f(-54, -52);
	glVertex2f(-41, -65);
	//Interior derecho inferior
	glVertex2f(-71, -47);
	glVertex2f(-67.5, -50.5);
	glVertex2f(-61.5, -44.5);
	glVertex2f(-65, -41);

	
	glColor3f(0.243, 0.573, 0.914);
	//Rectángulo Azul
	//Exterior derecho superior
	glVertex2f(-55.5, -72.5);
	glVertex2f(-57, -71);
	glVertex2f(-53.5, -67.5); //3.5 y 1.5
	glVertex2f(-52, -69);
	//Exterior derecho inferior//13
	glVertex2f(-72.5, -55.5);
	glVertex2f(-71, -57);
	glVertex2f(-58, -44);
	glVertex2f(-59.5, -42.5);
	//Exterior izquierdo superior
	glVertex2f(-31.5, -48.5);
	glVertex2f(-33, -47);
	glVertex2f(-46, -60);
	glVertex2f(-44.5, -61.5);
	//Exterior izquierdo inferior
	glVertex2f(-48.5, -31.5);
	glVertex2f(-47, -33);
	glVertex2f(-50.5, -36.5);
	glVertex2f(-52, -35);
	glColor3f(0.026, 0.384, 0.761);
	//Interior derecho superior
	glVertex2f(-57, -71);
	glVertex2f(-53.5, -67.5);
	glVertex2f(-59.5, -61.5);
	glVertex2f(-63, -65);
	//Interior derecho inferior
	glVertex2f(-71, -57);
	glVertex2f(-58, -44);
	glVertex2f(-52, -50);
	glVertex2f(-65, -63);
	//Interior izquierdo superior
	glVertex2f(-33, -47);
	glVertex2f(-46, -60);
	glVertex2f(-52, -54);
	glVertex2f(-39, -41);
	//Interior izquierdo inferior
	glVertex2f(-47, -33);
	glVertex2f(-50.5, -36.5);
	glVertex2f(-44.5, -42.5);
	glVertex2f(-41, -39);

	glColor3f(0.694, 0.447, 0.125);
	//Rectángulos cafes
	//Superior izquierdo//3.5 y 2
	glVertex2f(-39, -63);
	glVertex2f(-41, -65);
	glVertex2f(-44.5, -61.5);
	glVertex2f(-42.5, -59.5);
	//Inferior Derecho
	glVertex2f(-63, -39);
	glVertex2f(-65, -41);
	glVertex2f(-61.5, -44.5);
	glVertex2f(-59.5, -42.5);
	//Inferior izquierdo
	glVertex2f(-39, -41);
	glVertex2f(-41, -39);
	glVertex2f(-44.5, -42.5);
	glVertex2f(-42.5, -44.5);
	//Superior Derecho
	glVertex2f(-63, -65);
	glVertex2f(-65, -63);
	glVertex2f(-61.5, -59.5);
	glVertex2f(-59.5, -61.5);
	glEnd();


	glColor3f(0.014, 0.451, 0.098);
	glLineWidth(3);
	glBegin(GL_LINES);//Tallo
	glVertex2f(-18, -12);
	glVertex2f(-18, -80);
	glEnd();
	glLineWidth(1);
	
	//Hojas
	glBegin(GL_POLYGON); //Hoja derecha inferior
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		//El izquierdo es x y el derecho es y; cualquier modificación sobre pos afecta la posición, sobre angle afecta la forma.
		glVertex2f((pos - 44.2) - 4 * cos(angle + 4), (pos + 10) - 2.5 * sin(angle));
		//glVertex2f((pos+posición horizontal)+ tamaño horizontal* cos(angle), (pos + posición vertical) + tamaño verticaL* sin(angle));
		//cos(angle+x) = sin(angle-x), cos(angle+20) va del punto izquierdo superior al punto derecho inferior, entre menor el ángulo más se parece a un círculo
	}
	glEnd();
	
	glBegin(GL_POLYGON); //Hoja central inferior
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 10) - 2.5 * cos(angle + 4), (pos + 24) - 4 * sin(angle));
	}
	glEnd();
	///Hojas derechas
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 19.4) - 2.5 * cos(angle + 4), (pos + 20) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 19.4) - 2.5 * cos(angle + 4), (pos + 4) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 19.4) - 2.5 * cos(angle + 4), (pos - 12) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 19.4) - 2.5 * cos(angle + 4), (pos - 28) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 19.4) - 2.5 * cos(angle + 4), (pos - 43.5) - 4 * sin(angle));
	}
	glEnd();
	//Hojas izquierdas
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 25) - 2.5 * cos(angle - 4), (pos - 36) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 25) - 2.5 * cos(angle - 4), (pos - 20) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 25) - 2.5 * cos(angle - 4), (pos - 4) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 25) - 2.5 * cos(angle - 4), (pos + 12) - 4 * sin(angle));
	}
	glEnd();

	
	//Senos
	glPointSize(1);
	glBegin(GL_POINTS);
	for (k = -32; k > -76; k = k - .01) {//punto de inicio y de fin, k+1 es la distancia entre puntos{
		x = k;
		y = -5 * sin(k *(6.284 / 30)) - 18; //y= altura; 6.284/frecuencia (entre menor mas seguido); ))+desplazamiento vertical
		glVertex2f(x, y);
		x = k;//Invertido
		y = -5 * sin(k *(6.284 / 30)) - 86;
		glVertex2f(y, x);
	}
	glEnd();
	
	glColor3f(0.026, 0.384, 0.761);//Seno superior
	glBegin(GL_POINTS);
	for (k = -28; k > -79.1; k = k - .01) {
		x = k;
		y = -5 * sin(k *(6.284 / 30)) - 86;
		glVertex2f(x, y);
	}
	glEnd();
	//Cosenos
	glPointSize(1);
	glBegin(GL_POINTS);
	for (k = -28; k > -76; k = k - .01) {
		x = k;
		y = -5 * cos(k *(6.284 / 30)) - 18;
		glVertex2f(x, y);
		x = k;//Invertido
		y = -5 * cos(k *(6.284 / 30)) - 86;
		glVertex2f(y, x);
	}
	glEnd();

	
	//Espirales
	angle = 0, pos = -84;
	x = a*pow(2.718281, b*angle)*cos(angle);
	y = a*pow(2.718281, b*angle)*sin(angle);
	for (int i = 0; i < 750; i++) {//Espiral inferior derecha
		glBegin(GL_LINES);
		angle = 0.025*i;
		glVertex2f(x + pos - 1.3, y + pos + 66);
		glVertex2f(a*pow(2.718281, .032* b*angle)*cos(angle) + pos - 1.3, a*pow(2.718281, .032* b*angle)*sin(angle) + pos + 66);
		x = a*pow(2.718281, .032* b*angle)*cos(angle);
		y = a*pow(2.718281, .032* b*angle)*sin(angle);
		glEnd();
	}
	angle = 0, pos = -84;
	x = a*pow(2.718281, b*angle)*cos(angle);
	y = a*pow(2.718281, b*angle)*sin(angle);
	for (int i = 0; i < 670; i++) {//Espiral superior izquierda
		glBegin(GL_LINES);
		angle = 0.025*i;
		glVertex2f(y + pos - .11, x + pos - 1.3);
		glVertex2f(a*pow(2.718281, .032* b*angle)*sin(angle) + pos - .11, a*pow(2.718281, .032* b*angle)*cos(angle) + pos - 1.3);
		x = a*pow(2.718281, .032* b*angle)*cos(angle);
		y = a*pow(2.718281, .032* b*angle)*sin(angle);
		glEnd();
	}


































	
	glBegin(GL_QUADS); //Rectángulos
	glColor3f(0.349, 0.714, 0.329);
	//Marco izquierdo
	glVertex2i(-4, 4);
	glVertex2i(-4, 100);
	glVertex2i(-8, 100);
	glVertex2i(-8, 4);
	//Marco derecho
	glVertex2i(-96, 4);
	glVertex2i(-96, 100);
	glVertex2i(-100, 100);
	glVertex2i(-100, 4);
	//Marco superior
	glVertex2i(-8, 96);
	glVertex2i(-96, 96);
	glVertex2i(-96, 100);
	glVertex2i(-8, 100);
	//Marco inferior
	glVertex2i(-8, 4);
	glVertex2i(-96, 4);
	glVertex2i(-96, 8);
	glVertex2i(-8, 8);

	glColor3f(0.349, 0.714, 0.329);
	//Blanco izquierdo
	glVertex2i(-12, 12);
	glVertex2i(-24, 12);
	glVertex2i(-24, 92);
	glVertex2i(-12, 92);
	//Blanco derecho
	glVertex2i(-80, 12);
	glVertex2i(-92, 12);
	glVertex2i(-92, 92);
	glVertex2i(-80, 92);
	//Blanco superior
	glVertex2i(-24, 80);
	glVertex2i(-80, 80);
	glVertex2i(-80, 92);
	glVertex2i(-24, 92);
	//Blanco inferior
	glVertex2i(-24, 12);
	glVertex2i(-80, 12);
	glVertex2i(-80, 24);
	glVertex2i(-24, 24);

	glColor3f(0.694, 0.447, 0.125);
	//Exterior negro izquierdo
	glVertex2i(-8, 8);
	glVertex2i(-8, 96);
	glVertex2i(-12, 96);
	glVertex2i(-12, 8);
	//Exterior negro derecho
	glVertex2i(-92, 8);
	glVertex2i(-92, 96);
	glVertex2i(-96, 96);
	glVertex2i(-96, 8);
	//Exterior negro superior
	glVertex2i(-12, 96);
	glVertex2i(-92, 96);
	glVertex2i(-92, 92);
	glVertex2i(-12, 92);
	//Exterior negro inferior
	glVertex2i(-12, 8);
	glVertex2i(-92, 8);
	glVertex2i(-92, 12);
	glVertex2i(-12, 12);
	//Interior negro izquierdo
	glVertex2i(-24, 24);
	glVertex2i(-28, 24);
	glVertex2i(-28, 80);
	glVertex2i(-24, 80);
	//Interior negro derecho
	glVertex2i(-76, 24);
	glVertex2i(-80, 24);
	glVertex2i(-80, 80);
	glVertex2i(-76, 80);
	//Interior negro superior
	glVertex2i(-28, 76);
	glVertex2i(-76, 76);
	glVertex2i(-76, 80);
	glVertex2i(-28, 80);
	//Interior negro inferior
	glVertex2i(-28, 24);
	glVertex2i(-76, 24);
	glVertex2i(-76, 28);
	glVertex2i(-28, 28);
	//Fondo negro
	glVertex2i(-28, 28);
	glVertex2i(-76, 28);
	glVertex2i(-76, 76);
	glVertex2i(-28, 76);
	glEnd();
	
	glBegin(GL_LINES);//Lineas
	glColor3f(1.0, 1.0, 1.0);
	i = -8;
	while (i != -32) { 	//Esquina Izquierda
						//Verticales
		glVertex2f(i, 8);
		glVertex2f(i, 96);
		//Horizontales
		glVertex2f(-8, -i);
		glVertex2f(-96, -i);
		i = i - 4;
	}

	i = -76;
	while (i != -100) { 	//Esquina Derecha
							//Verticales
		glVertex2f(i, 8);
		glVertex2f(i, 96);
		//Horizontales
		glVertex2f(-8, -i);
		glVertex2f(-96, -i);
		i = i - 4;
	}

	i = -32;
	while (i != -76) { 	//Centro
						//Verticales
		glVertex2f(i, 8);
		glVertex2f(i, 28);
		glVertex2f(i, 76);
		glVertex2f(i, 96);
		//Horizontales
		glVertex2f(-8, -i);
		glVertex2f(-28, -i);
		glVertex2f(-76, -i);
		glVertex2f(-96, -i);
		i = i - 4;
	}
	glEnd();
	
	pos = -40;
	//Circulos
	glColor3f(1.0, 0.345, 0.345);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior izquierdo grande
		angle = j*3.142 / 180;
		//El izquierdo es x y el derecho es y; cualquier modificación sobre pos afecta la posición, sobre angle afecta la forma.
		glVertex2f((pos)-12 * cos(angle), (-pos + 24) + 12 * sin(angle));
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior derecho grande
		angle = j*3.142 / 180;
		glVertex2f((pos - 24) - 12 * cos(angle), (-pos)+12 * sin(angle));
	}
	glEnd();
	glColor3f(0.243, 0.573, 0.914);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior derecho grande
		angle = j*3.142 / 180;
		glVertex2f((pos - 24) + 12 * cos(angle), (-pos + 24) + 12 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior izquierdo grande
		angle = j*3.142 / 180;
		glVertex2f((pos)-12 * cos(angle), (-pos)+12 * sin(angle));
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior izquierdo chico
		angle = j*3.142 / 180;
		glVertex2f((pos)-10 * cos(angle), (-pos + 24) + 10 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior derecho chico
		angle = j*3.142 / 180;
		glVertex2f((pos - 24) - 10 * cos(angle), (-pos)+10 * sin(angle));
	}
	glEnd();
	glColor3f(0.026, 0.384, 0.761);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior derecho chico
		angle = j*3.142 / 180;
		glVertex2f((pos - 24) + 10 * cos(angle), (-pos + 24) + 10 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior izquierdo chico
		angle = j*3.142 / 180;
		glVertex2f((pos)-10 * cos(angle), (-pos)+10 * sin(angle));
	}
	glEnd();

	

	glBegin(GL_QUADS); //Rectángulos de los círculos
	glColor3f(1.0, 0.345, 0.345);
	//Rectángulo Rojo
	//Exterior izquierdo superior
	glVertex2f(-31.5, 55.5);
	glVertex2f(-33, 57);
	glVertex2f(-36.5, 53.5);
	glVertex2f(-35, 52);
	//Exterior izquierdo inferior
	glVertex2f(-57, 33);
	glVertex2f(-55.5, 31.5);
	glVertex2f(-42.5, 44.5);
	glVertex2f(-44, 46);
	//Exterior derecho superior
	glVertex2f(-48.5, 72.5);
	glVertex2f(-47, 71);
	glVertex2f(-60, 58);
	glVertex2f(-61.5, 59.5);
	//Exterior derecho inferior
	glVertex2f(-71, 47);
	glVertex2f(-72.5, 48.5);
	glVertex2f(-69, 52);
	glVertex2f(-67.5, 50.5);
	glColor3f(1.0, 0.0, 0.0);
	//Interior izquierdo superior
	glVertex2f(-33, 57);
	glVertex2f(-36.5, 53.5);
	glVertex2f(-42.5, 59.5);
	glVertex2f(-39, 63);
	//Interior izquierdo inferior
	glVertex2f(-57, 33);
	glVertex2f(-63, 39);
	glVertex2f(-50, 52);
	glVertex2f(-44, 46);
	//Interior derecho superior
	glVertex2f(-47, 71);
	glVertex2f(-60, 58);
	glVertex2f(-54, 52);
	glVertex2f(-41, 65);
	//Interior derecho inferior
	glVertex2f(-71, 47);
	glVertex2f(-67.5, 50.5);
	glVertex2f(-61.5, 44.5);
	glVertex2f(-65, 41);


	glColor3f(0.243, 0.573, 0.914);
	//Rectángulo Azul
	//Exterior derecho superior
	glVertex2f(-55.5, 72.5);
	glVertex2f(-57, 71);
	glVertex2f(-53.5, 67.5); //3.5 y 1.5
	glVertex2f(-52, 69);
	//Exterior derecho inferior//13
	glVertex2f(-72.5, 55.5);
	glVertex2f(-71, 57);
	glVertex2f(-58, 44);
	glVertex2f(-59.5, 42.5);
	//Exterior izquierdo superior
	glVertex2f(-31.5, 48.5);
	glVertex2f(-33, 47);
	glVertex2f(-46, 60);
	glVertex2f(-44.5, 61.5);
	//Exterior izquierdo inferior
	glVertex2f(-48.5, 31.5);
	glVertex2f(-47, 33);
	glVertex2f(-50.5, 36.5);
	glVertex2f(-52, 35);
	glColor3f(0.026, 0.384, 0.761);
	//Interior derecho superior
	glVertex2f(-57, 71);
	glVertex2f(-53.5, 67.5);
	glVertex2f(-59.5, 61.5);
	glVertex2f(-63, 65);
	//Interior derecho inferior
	glVertex2f(-71, 57);
	glVertex2f(-58, 44);
	glVertex2f(-52, 50);
	glVertex2f(-65, 63);
	//Interior izquierdo superior
	glVertex2f(-33, 47);
	glVertex2f(-46, 60);
	glVertex2f(-52, 54);
	glVertex2f(-39, 41);
	//Interior izquierdo inferior
	glVertex2f(-47, 33);
	glVertex2f(-50.5, 36.5);
	glVertex2f(-44.5, 42.5);
	glVertex2f(-41, 39);

	glColor3f(0.694, 0.447, 0.125);
	//Rectángulos cafes
	//Superior izquierdo//3.5 y 2
	glVertex2f(-39, 63);
	glVertex2f(-41, 65);
	glVertex2f(-44.5, 61.5);
	glVertex2f(-42.5, 59.5);
	//Inferior Derecho
	glVertex2f(-63, 39);
	glVertex2f(-65, 41);
	glVertex2f(-61.5, 44.5);
	glVertex2f(-59.5, 42.5);
	//Inferior izquierdo
	glVertex2f(-39, 41);
	glVertex2f(-41, 39);
	glVertex2f(-44.5, 42.5);
	glVertex2f(-42.5, 44.5);
	//Superior Derecho
	glVertex2f(-63, 65);
	glVertex2f(-65, 63);
	glVertex2f(-61.5, 59.5);
	glVertex2f(-59.5, 61.5);
	glEnd();


	glColor3f(0.014, 0.451, 0.098);
	glLineWidth(3);
	glBegin(GL_LINES);//Tallo
	glVertex2f(-18, 12);
	glVertex2f(-18, 80);
	glEnd();
	glLineWidth(1);
	
	//Hojas
	glBegin(GL_POLYGON); //Hoja derecha inferior
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		//El izquierdo es x y el derecho es y; cualquier modificación sobre pos afecta la posición, sobre angle afecta la forma.
		glVertex2f((pos - 44.2) - 4 * cos(angle + 4), (-pos - 10) + 2.5 * sin(angle));
		//glVertex2f((pos+posición horizontal)+ tamaño horizontal* cos(angle), (pos + posición vertical) + tamaño verticaL* sin(angle));
		//cos(angle+x) = sin(angle-x), cos(angle+20) va del punto izquierdo superior al punto derecho inferior, entre menor el ángulo más se parece a un círculo
	}
	glEnd();

	glBegin(GL_POLYGON); //Hoja central inferior
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 10) - 2.5 * cos(angle + 4), (-pos - 24) + 4 * sin(angle));
	}
	glEnd();
	///Hojas derechas
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 19.4) - 2.5 * cos(angle + 4), (-pos - 20) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 19.4) - 2.5 * cos(angle + 4), (-pos - 4) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 19.4) - 2.5 * cos(angle + 4), (-pos + 12) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 19.4) - 2.5 * cos(angle + 4), (-pos + 28) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 19.4) - 2.5 * cos(angle + 4), (-pos + 43.5) + 4 * sin(angle));
	}
	glEnd();
	//Hojas izquierdas
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 25) - 2.5 * cos(angle - 4), (-pos + 36) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 25) - 2.5 * cos(angle - 4), (-pos + 20) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 25) - 2.5 * cos(angle - 4), (-pos + 4) + 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((pos + 25) - 2.5 * cos(angle - 4), (-pos - 12) + 4 * sin(angle));
	}
	glEnd();

	
	//Senos
	glPointSize(1);
	glBegin(GL_POINTS);
	for (k = -32; k > -76; k = k - .01) {//punto de inicio y de fin, k+1 es la distancia entre puntos{
		x = k;
		y = 5 * sin(-k *(6.284 / 30)) + 18; //y= altura; 6.284/frecuencia (entre menor mas seguido); ))+desplazamiento vertical
		glVertex2f(x, y);
		x = k+108;//Invertido
		y = 5 * sin(-k *(6.284 / 30)) - 86;
		glVertex2f(y, x);
	}
	glEnd();
	
	glColor3f(0.026, 0.384, 0.761);//Seno superior
	glBegin(GL_POINTS);
	for (k = -28; k > -79.1; k = k - .01) {
		x = k;
		y = 5 * sin(-k *(6.284 / 30)) + 86;
		glVertex2f(x, y);
	}
	glEnd();
	
	//Cosenos
	glPointSize(1);
	glBegin(GL_POINTS);
	for (k = -28; k > -76; k = k - .01) {
		x = k;
		y = 5 * cos(-k *(6.284 / 30)) + 18;
		glVertex2f(x, y);
		x = k+108;//Invertido
		y = 5 * cos(-k *(6.284 / 30)) - 86;
		glVertex2f(y, x);
	}
	glEnd();

	
	//Espirales
	angle = 0, pos = -84;
	x = a*pow(2.718281, b*angle)*cos(angle);
	y = a*pow(2.718281, b*angle)*sin(angle);
	for (int i = 0; i < 750; i++) {//Espiral inferior derecha
		glBegin(GL_LINES);
		angle = 0.025*i;
		glVertex2f(x + pos - 1.3, y - pos - 66);
		glVertex2f(a*pow(2.718281, .032* b*angle)*cos(angle) + pos - 1.3, a*pow(2.718281, .032* b*angle)*sin(angle) - pos - 66);
		x = a*pow(2.718281, .032* b*angle)*cos(angle);
		y = a*pow(2.718281, .032* b*angle)*sin(angle);
		glEnd();
	}
	angle = 0, pos = -84;
	x = a*pow(2.718281, b*angle)*cos(angle);
	y = a*pow(2.718281, b*angle)*sin(angle);
	for (int i = 0; i < 670; i++) {//Espiral superior izquierda
		glBegin(GL_LINES);
		angle = 0.025*i;
		glVertex2f(y + pos - .11, x - pos + 1.3);
		glVertex2f(a*pow(2.718281, .032* b*angle)*sin(angle) + pos - .11, a*pow(2.718281, .032* b*angle)*cos(angle) - pos + 1.3);
		x = a*pow(2.718281, .032* b*angle)*cos(angle);
		y = a*pow(2.718281, .032* b*angle)*sin(angle);
		glEnd();
	}
































	
	glBegin(GL_QUADS); //Rectángulos
	glColor3f(0.349, 0.714, 0.329);
	//Marco izquierdo
	glVertex2i(4, -4);
	glVertex2i(4, -100);
	glVertex2i(8, -100);
	glVertex2i(8, -4);
	//Marco derecho
	glVertex2i(96, -4);
	glVertex2i(96, -100);
	glVertex2i(100, -100);
	glVertex2i(100, -4);
	//Marco superior
	glVertex2i(8, -96);
	glVertex2i(96, -96);
	glVertex2i(96, -100);
	glVertex2i(8, -100);
	//Marco inferior
	glVertex2i(8, -4);
	glVertex2i(96, -4);
	glVertex2i(96, -8);
	glVertex2i(8, -8);

	glColor3f(0.349, 0.714, 0.329);
	//Blanco izquierdo
	glVertex2i(12, -12);
	glVertex2i(24, -12);
	glVertex2i(24, -92);
	glVertex2i(12, -92);
	//Blanco derecho
	glVertex2i(80, -12);
	glVertex2i(92, -12);
	glVertex2i(92, -92);
	glVertex2i(80, -92);
	//Blanco superior
	glVertex2i(24, -80);
	glVertex2i(80, -80);
	glVertex2i(80, -92);
	glVertex2i(24, -92);
	//Blanco inferior
	glVertex2i(24, -12);
	glVertex2i(80, -12);
	glVertex2i(80, -24);
	glVertex2i(24, -24);

	glColor3f(0.694, 0.447, 0.125);
	//Exterior negro izquierdo
	glVertex2i(8, -8);
	glVertex2i(8, -96);
	glVertex2i(12, -96);
	glVertex2i(12, -8);
	//Exterior negro derecho
	glVertex2i(92, -8);
	glVertex2i(92, -96);
	glVertex2i(96, -96);
	glVertex2i(96, -8);
	//Exterior negro superior
	glVertex2i(12, -96);
	glVertex2i(92, -96);
	glVertex2i(92, -92);
	glVertex2i(12, -92);
	//Exterior negro inferior
	glVertex2i(12, -8);
	glVertex2i(92, -8);
	glVertex2i(92, -12);
	glVertex2i(12, -12);
	//Interior negro izquierdo
	glVertex2i(24, -24);
	glVertex2i(28, -24);
	glVertex2i(28, -80);
	glVertex2i(24, -80);
	//Interior negro derecho
	glVertex2i(76, -24);
	glVertex2i(80, -24);
	glVertex2i(80, -80);
	glVertex2i(76, -80);
	//Interior negro superior
	glVertex2i(28, -76);
	glVertex2i(76, -76);
	glVertex2i(76, -80);
	glVertex2i(28, -80);
	//Interior negro inferior
	glVertex2i(28, -24);
	glVertex2i(76, -24);
	glVertex2i(76, -28);
	glVertex2i(28, -28);
	//Fondo negro
	glVertex2i(28, -28);
	glVertex2i(76, -28);
	glVertex2i(76, -76);
	glVertex2i(28, -76);
	glEnd();

	glBegin(GL_LINES);//Lineas
	glColor3f(1.0, 1.0, 1.0);
	i = -8;
	while (i != -32) { 	//Esquina Izquierda
						//Verticales
		glVertex2f(-i, -8);
		glVertex2f(-i, -96);
		//Horizontales
		glVertex2f(8, i);
		glVertex2f(96, i);
		i = i - 4;
	}

	i = -76;
	while (i != -100) { 	//Esquina Derecha
							//Verticales
		glVertex2f(-i, -8);
		glVertex2f(-i, -96);
		//Horizontales
		glVertex2f(8, i);
		glVertex2f(96, i);
		i = i - 4;
	}

	i = -32;
	while (i != -76) { 	//Centro
						//Verticales
		glVertex2f(-i, -8);
		glVertex2f(-i, -28);
		glVertex2f(-i, -76);
		glVertex2f(-i, -96);
		//Horizontales
		glVertex2f(8, i);
		glVertex2f(28, i);
		glVertex2f(76, i);
		glVertex2f(96, i);
		i = i - 4;
	}
	glEnd();
	
	pos = -40;
	//Circulos
	glColor3f(1.0, 0.345, 0.345);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior izquierdo grande
		angle = j*3.142 / 180;
		//El izquierdo es x y el derecho es y; cualquier modificación sobre pos afecta la posición, sobre angle afecta la forma.
		glVertex2f((-pos)+12 * cos(angle), (pos - 24) - 12 * sin(angle));
	}
	glEnd();

	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior derecho grande
		angle = j*3.142 / 180;
		glVertex2f((-pos + 24) + 12 * cos(angle), (pos)-12 * sin(angle));
	}
	glEnd();
	glColor3f(0.243, 0.573, 0.914);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior derecho grande
		angle = j*3.142 / 180;
		glVertex2f((-pos + 24) - 12 * cos(angle), (pos - 24) - 12 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior izquierdo grande
		angle = j*3.142 / 180;
		glVertex2f((-pos)+12 * cos(angle), (pos)-12 * sin(angle));
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior izquierdo chico
		angle = j*3.142 / 180;
		glVertex2f((-pos)+10 * cos(angle), (pos - 24) - 10 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior derecho chico
		angle = j*3.142 / 180;
		glVertex2f((-pos + 24) + 10 * cos(angle), (pos)-10 * sin(angle));
	}
	glEnd();
	glColor3f(0.026, 0.384, 0.761);
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo superior derecho chico
		angle = j*3.142 / 180;
		glVertex2f((-pos + 24) - 10 * cos(angle), (pos - 24) - 10 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {//Circulo inferior izquierdo chico
		angle = j*3.142 / 180;
		glVertex2f((-pos)+10 * cos(angle), (pos)-10 * sin(angle));
	}
	glEnd();


	
	glBegin(GL_QUADS); //Rectángulos de los círculos
	glColor3f(1.0, 0.345, 0.345);
	//Rectángulo Rojo
	//Exterior izquierdo superior
	glVertex2f(31.5, -55.5);
	glVertex2f(33, -57);
	glVertex2f(36.5, -53.5);
	glVertex2f(35, -52);
	//Exterior izquierdo inferior
	glVertex2f(57, -33);
	glVertex2f(55.5, -31.5);
	glVertex2f(42.5, -44.5);
	glVertex2f(44, -46);
	//Exterior derecho superior
	glVertex2f(48.5, -72.5);
	glVertex2f(47, -71);
	glVertex2f(60, -58);
	glVertex2f(61.5, -59.5);
	//Exterior derecho inferior
	glVertex2f(71, -47);
	glVertex2f(72.5, -48.5);
	glVertex2f(69, -52);
	glVertex2f(67.5, -50.5);
	glColor3f(1.0, 0.0, 0.0);
	//Interior izquierdo superior
	glVertex2f(33, -57);
	glVertex2f(36.5, -53.5);
	glVertex2f(42.5, -59.5);
	glVertex2f(39, -63);
	//Interior izquierdo inferior
	glVertex2f(57, -33);
	glVertex2f(63, -39);
	glVertex2f(50, -52);
	glVertex2f(44, -46);
	//Interior derecho superior
	glVertex2f(47, -71);
	glVertex2f(60, -58);
	glVertex2f(54, -52);
	glVertex2f(41, -65);
	//Interior derecho inferior
	glVertex2f(71, -47);
	glVertex2f(67.5, -50.5);
	glVertex2f(61.5, -44.5);
	glVertex2f(65, -41);


	glColor3f(0.243, 0.573, 0.914);
	//Rectángulo Azul
	//Exterior derecho superior
	glVertex2f(55.5, -72.5);
	glVertex2f(57, -71);
	glVertex2f(53.5, -67.5); //3.5 y 1.5
	glVertex2f(52, -69);
	//Exterior derecho inferior//13
	glVertex2f(72.5, -55.5);
	glVertex2f(71, -57);
	glVertex2f(58, -44);
	glVertex2f(59.5, -42.5);
	//Exterior izquierdo superior
	glVertex2f(31.5, -48.5);
	glVertex2f(33, -47);
	glVertex2f(46, -60);
	glVertex2f(44.5, -61.5);
	//Exterior izquierdo inferior
	glVertex2f(48.5, -31.5);
	glVertex2f(47, -33);
	glVertex2f(50.5, -36.5);
	glVertex2f(52, -35);
	glColor3f(0.026, 0.384, 0.761);
	//Interior derecho superior
	glVertex2f(57, -71);
	glVertex2f(53.5, -67.5);
	glVertex2f(59.5, -61.5);
	glVertex2f(63, -65);
	//Interior derecho inferior
	glVertex2f(71, -57);
	glVertex2f(58, -44);
	glVertex2f(52, -50);
	glVertex2f(65, -63);
	//Interior izquierdo superior
	glVertex2f(33, -47);
	glVertex2f(46, -60);
	glVertex2f(52, -54);
	glVertex2f(39, -41);
	//Interior izquierdo inferior
	glVertex2f(47, -33);
	glVertex2f(50.5, -36.5);
	glVertex2f(44.5, -42.5);
	glVertex2f(41, -39);

	glColor3f(0.694, 0.447, 0.125);
	//Rectángulos cafes
	//Superior izquierdo//3.5 y 2
	glVertex2f(39, -63);
	glVertex2f(41, -65);
	glVertex2f(44.5, -61.5);
	glVertex2f(42.5, -59.5);
	//Inferior Derecho
	glVertex2f(63, -39);
	glVertex2f(65, -41);
	glVertex2f(61.5, -44.5);
	glVertex2f(59.5, -42.5);
	//Inferior izquierdo
	glVertex2f(39, -41);
	glVertex2f(41, -39);
	glVertex2f(44.5, -42.5);
	glVertex2f(42.5, -44.5);
	//Superior Derecho
	glVertex2f(63, -65);
	glVertex2f(65, -63);
	glVertex2f(61.5, -59.5);
	glVertex2f(59.5, -61.5);
	glEnd();


	glColor3f(0.014, 0.451, 0.098);
	glLineWidth(3);
	glBegin(GL_LINES);//Tallo
	glVertex2f(18, -12);
	glVertex2f(18, -80);
	glEnd();
	glLineWidth(1);
	
	//Hojas
	glBegin(GL_POLYGON); //Hoja derecha inferior
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		//El izquierdo es x y el derecho es y; cualquier modificación sobre pos afecta la posición, sobre angle afecta la forma.
		glVertex2f((-pos + 44.2) + 4 * cos(angle + 4), (pos + 10) - 2.5 * sin(angle));
		//glVertex2f((pos+posición horizontal)+ tamaño horizontal* cos(angle), (pos + posición vertical) + tamaño verticaL* sin(angle));
		//cos(angle+x) = sin(angle-x), cos(angle+20) va del punto izquierdo superior al punto derecho inferior, entre menor el ángulo más se parece a un círculo
	}
	glEnd();

	glBegin(GL_POLYGON); //Hoja central inferior
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((-pos - 10) + 2.5 * cos(angle + 4), (pos + 24) - 4 * sin(angle));
	}
	glEnd();
	///Hojas derechas
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((-pos - 19.4) + 2.5 * cos(angle + 4), (pos + 20) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((-pos - 19.4) + 2.5 * cos(angle + 4), (pos + 4) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((-pos - 19.4) + 2.5 * cos(angle + 4), (pos - 12) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((-pos - 19.4) + 2.5 * cos(angle + 4), (pos - 28) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((-pos - 19.4) + 2.5 * cos(angle + 4), (pos - 43.5) - 4 * sin(angle));
	}
	glEnd();
	//Hojas izquierdas
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((-pos - 25) + 2.5 * cos(angle - 4), (pos - 36) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((-pos - 25) + 2.5 * cos(angle - 4), (pos - 20) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((-pos - 25) + 2.5 * cos(angle - 4), (pos - 4) - 4 * sin(angle));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (j = 0; j < 360; j++) {
		angle = j * 3.142 / 180;
		glVertex2f((-pos - 25) + 2.5 * cos(angle - 4), (pos + 12) - 4 * sin(angle));
	}
	glEnd();

	
	//Senos
	glPointSize(1);
	glBegin(GL_POINTS);
	for (k = -32; k > -76; k = k - .01) {//punto de inicio y de fin, k+1 es la distancia entre puntos{
		x = -k;
		y = -5 * sin(k *(6.284 / 30)) - 18; //y= altura; 6.284/frecuencia (entre menor mas seguido); ))+desplazamiento vertical
		glVertex2f(x, y);
		x = k;//Invertido
		y = -5 * sin(k *(6.284 / 30)) + 86;
		glVertex2f(y, x);
	}
	glEnd();

	glColor3f(0.026, 0.384, 0.761);//Seno superior
	glBegin(GL_POINTS);
	for (k = -28; k > -79.1; k = k - .01) {
		x = -k;
		y = -5 * sin(k *(6.284 / 30)) - 86;
		glVertex2f(x, y);
	}
	glEnd();
	
	//Cosenos
	glPointSize(1);
	glBegin(GL_POINTS);
	for (k = -28; k > -76; k = k - .01) {
		x = -k;
		y = -5 * cos(k *(6.284 / 30)) - 18;
		glVertex2f(x, y);
		x = k;//Invertido
		y = -5 * cos(k *(6.284 / 30)) + 86;
		glVertex2f(y, x);
	}
	glEnd();

	
	//Espirales
	angle = 0, pos = -84;
	x = a*pow(2.718281, b*angle)*cos(angle);
	y = a*pow(2.718281, b*angle)*sin(angle);
	for (int i = 0; i < 750; i++) {//Espiral inferior derecha
		glBegin(GL_LINES);
		angle = 0.025*i;
		glVertex2f(x - pos + 1.3, y + pos + 66);
		glVertex2f(a*pow(2.718281, .032* b*angle)*cos(angle) - pos + 1.3, a*pow(2.718281, .032* b*angle)*sin(angle) + pos + 66);
		x = a*pow(2.718281, .032* b*angle)*cos(angle);
		y = a*pow(2.718281, .032* b*angle)*sin(angle);
		glEnd();
	}
	angle = 0, pos = -84;
	x = a*pow(2.718281, b*angle)*cos(angle);
	y = a*pow(2.718281, b*angle)*sin(angle);
	for (int i = 0; i < 670; i++) {//Espiral superior izquierda
		glBegin(GL_LINES);
		angle = 0.025*i;
		glVertex2f(y - pos + .11, x + pos - 1.3);
		glVertex2f(a*pow(2.718281, .032* b*angle)*sin(angle) - pos + .11, a*pow(2.718281, .032* b*angle)*cos(angle) + pos - 1.3);
		x = a*pow(2.718281, .032* b*angle)*cos(angle);
		y = a*pow(2.718281, .032* b*angle)*sin(angle);
		glEnd();
	}
	





	/*glLineWidth(3000);
	glBegin(GL_LINES);
	glVertex2f(cont, 20);
	glVertex2f(80, 80);
	glEnd();
	cont = cont + 1;
	*/
	glRotatef(.8, 0, 0, 1);
	



	glutSwapBuffers();


	


}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(800, 0);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Ejemplo");
	init();
	glutDisplayFunc(lineSegment);
	glutIdleFunc(lineSegment);
	
	glutMainLoop();
	
}
