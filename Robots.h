# ifndef ROBOTS_H_
# define  ROBOTS_H_
#include "Restaurar.h" //llamo mi clase Restaurar
#include "Movimientos.h" //llamo mi clase Movimientos
#include "Cajas.h" //llamo mi clase Cajas (agregación con Robots)

class Robots{
	private:
		Restaurar PosicionesServo1;  //objetos (posiciones) de clase Restaurar que me permiten guardar 9 posiciones del ServoX para 3 tipos de cajas
		Restaurar PosicionesServo2;  // Las cajas ya tendrán posiciones constantes en la maqueta, por lo cual los servos tendrían que tener posiciones
		Restaurar PosicionesServo3;  //constantes (posiciones de algoritmo para guardar cajas), pero en la realidad es que los servos nunca mantienen 
		Restaurar PosicionesServo4;  // la misma posicion, esto debido a la temperatura en su interior respecto al tiempo. Es por eso que desarrollo posiciones
		Movimientos servo1;          //para que estas se puedan modificar, entonces los atributos son angulos/posiciones en forma de matrices
		Articulacion servo2;   // objetos de clase Movimientos, estos serán los motores que se mueven a travez de grados, cada uno
		Articulacion servo3;   //inicia con un grado distinto (atributo grado/posicion)
		Mano servo4;
		Cajas cajasVerdes; //inicializo mis 3 cajas (objetos) de clase Cajas, con cantidad inicial de 0 cajas cada una
		Cajas cajasRojas;
		Cajas cajasAmarillas;
	
	public:
		Robots();
		void set_particular_PosicionesServo2(int pose1,int pose2,int pose3,int pose4); //modifico las posiciones del servo2 para el algoritmo de guardado de cajas
		void set_particular_PosicionesServo3(int pose1,int pose2,int pose3,int pose4); //     ||          ||         servo3        ||      
		int get_particular_PosicionesServo1(int nfila,int ncolumna);
		int get_particular_PosicionesServo2(int nfila,int ncolumna); // obtengo el grado de inclinación del robot en una especifica
		int get_particular_PosicionesServo3(int nfila,int ncolumna); // posicion (fila) y color de caja (columna)
		int get_particular_PosicionesServo4(int nfila,int ncolumna);
		void set_anguloServo1(int ang);
		void set_anguloServo2(int ang);  // modifico en tiempo real con un ángulo de inclinacion para mis
		void set_anguloServo3(int ang);   // servomotores
		void set_anguloServo4(int ang);
		int get_anguloServo1();
		int get_anguloServo2();
		int get_anguloServo3();        // obtengo el angulo de inclinación que tiene dicho servomotor
		int get_anguloServo4();
		void set_temperaturaServo2(int temp);  // extraigo la temperatura de mis servos 2 y 3
		void set_temperaturaServo3(int temp);
		int get_temperaturaServo2();
		int get_temperaturaServo3();     // pido la información de la temperatura de los servos 2 y 3
		void set_limiteAberturaServo4(int limA);   // obtengo el limite maximo de abertura de la mano del robot
		void set_limiteCerraduraServo4(int limC);  // obtengo el limite minimo de cerradura de la mano del robot
		int get_limiteAberturaServo4();             
		int get_limiteCerraduraServo4();            // pido la información de dichos limites anteriormente mencionados
		void servo1Aumenta();
		void servo2Aumenta();
		void servo3Aumenta();              //  me permite mover los servos en incrementos de 1 en 1 (grados)
		void servo4Aumenta();
		void servo1Disminuye();
		void servo2Disminuye();    //  me permite mover los servos en decrementos de 1 en 1
		void servo3Disminuye();
		void servo4Disminuye();
		void set_cajasVerdes(Cajas cV);
		void set_cajasRojas(Cajas cR);   // hago la agregación con mis objetos de tipo Cajas creandolas en esta clase como atributos
		void set_cajasAmarillas(Cajas cA);
		void set_CantidadCajasVerdes(int cant);
		void set_CantidadCajasRojas(int cant);      //modifico el factor de cantidad de dichas cajas
		void set_CantidadCajasAmarillas(int cant);
		int get_CantidadCajasVerdes();
		int get_CantidadCajasRojas();     // pido la información de la cantidad de dichas cajas
		int get_CantidadCajasAmarillas();
};
Robots::Robots(){                                              //constructor que inicializa mis objetos de tipo Robots con ...
	int Servo1posicionI[100][100]={{13,42,74},{13,42,74},{13,42,74},{0,28,56},{0,28,56},{94,112,135},{94,112,135},{94,112,135},{101,101,101}}; //angulos iniciales
	int Servo2posicionI[100][100]={{98,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24},{25,26,27}}; //angulos iniciales
	int Servo3posicionI[100][100]={{99,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24},{25,26,27}}; //angulos iniciales
	int Servo4posicionI[100][100]={{50,50,50},{50,50,50},{15,15,15},{15,15,15},{15,15,15},{15,15,15},{15,15,15},{50,50,50},{21,21,21}}; //angulos iniciales
	PosicionesServo1.set_posicionCompleto(Servo1posicionI);    // ... valores por defaut, estos se irán modificando
	PosicionesServo2.set_posicionCompleto(Servo2posicionI);    // con los setters
	PosicionesServo3.set_posicionCompleto(Servo3posicionI);
	PosicionesServo4.set_posicionCompleto(Servo4posicionI);
	servo1.set_angulo(101);
	servo2.set_angulo(70);
	servo3.set_angulo(75);
	servo4.set_angulo(21);
	// en los setters hago mi agregación de dichas cajas
	
}

void Robots::set_particular_PosicionesServo2(int pose1,int pose2,int pose3,int pose4){   //contenido de mis metodos anteriormente mencionados
	PosicionesServo2.set_posicion(pose1,pose2,pose3,pose4);
}

void Robots::set_particular_PosicionesServo3(int pose1,int pose2,int pose3,int pose4){
	PosicionesServo3.set_posicion(pose1,pose2,pose3,pose4);
}

int Robots::get_particular_PosicionesServo1(int nfila,int ncolumna){
	return PosicionesServo1.particular_posicion(nfila,ncolumna);
}

int Robots::get_particular_PosicionesServo2(int nfila,int ncolumna){
	return PosicionesServo2.particular_posicion(nfila,ncolumna);
}

int Robots::get_particular_PosicionesServo3(int nfila,int ncolumna){
	return PosicionesServo3.particular_posicion(nfila,ncolumna);
}

int Robots::get_particular_PosicionesServo4(int nfila,int ncolumna){
	return PosicionesServo4.particular_posicion(nfila,ncolumna);
}

void Robots::set_anguloServo1(int ang){
	servo1.set_angulo(ang);
}

void Robots::set_anguloServo2(int ang){
	servo2.set_angulo(ang);
}

void Robots::set_anguloServo3(int ang){
	servo3.set_angulo(ang);
}

void Robots::set_anguloServo4(int ang){
	servo4.set_angulo(ang);
}

int Robots::get_anguloServo1(){
	return servo1.get_angulo();
}

int Robots::get_anguloServo2(){
	return servo2.get_angulo();
}

int Robots::get_anguloServo3(){
	return servo3.get_angulo();
}

int Robots::get_anguloServo4(){
	return servo4.get_angulo();
}

void Robots::set_temperaturaServo2(int temp){
	servo2.set_temperatura(temp);
}

void Robots::set_temperaturaServo3(int temp){
	servo3.set_temperatura(temp);
}

int Robots::get_temperaturaServo2(){
	return servo2.get_temperatura();
}

int Robots::get_temperaturaServo3(){
	return servo3.get_temperatura();
}

void Robots::set_limiteAberturaServo4(int limA){
	servo4.set_limiteAbertura(limA);
}

void Robots::set_limiteCerraduraServo4(int limC){
	servo4.set_limiteCerradura(limC);
}

int Robots::get_limiteAberturaServo4(){
	return servo4.get_limiteAbertura();
}

int Robots::get_limiteCerraduraServo4(){
	return servo4.get_limiteCerradura();
}

void Robots::servo1Aumenta(){
	servo1.Aumenta();
}

void Robots::servo2Aumenta(){
	servo2.Aumenta();
}

void Robots::servo3Aumenta(){
	servo3.Aumenta();
}

void Robots::servo4Aumenta(){
	servo4.Aumenta();
}

void Robots::servo1Disminuye(){
	servo1.Disminuye();
}

void Robots::servo2Disminuye(){
	servo2.Disminuye();
}

void Robots::servo3Disminuye(){
	servo3.Disminuye();
}

void Robots::servo4Disminuye(){
	servo4.Disminuye();
}

void Robots::set_cajasVerdes(Cajas cV){
	cajasVerdes=cV;
}

void Robots::set_cajasRojas(Cajas cR){
	cajasRojas=cR;
}

void Robots::set_cajasAmarillas(Cajas cA){
	cajasAmarillas=cA;
}

void Robots::set_CantidadCajasVerdes(int cant){
	cajasVerdes.set_cantidad(cant);
}

void Robots::set_CantidadCajasRojas(int cant){
	cajasRojas.set_cantidad(cant);
}

void Robots::set_CantidadCajasAmarillas(int cant){
	cajasAmarillas.set_cantidad(cant);
}

int Robots::get_CantidadCajasVerdes(){
	return cajasVerdes.get_cantidad();
}

int Robots::get_CantidadCajasRojas(){
	return cajasRojas.get_cantidad();
}

int Robots::get_CantidadCajasAmarillas(){
	return cajasAmarillas.get_cantidad();
}
# endif  // ROBOTS_H_