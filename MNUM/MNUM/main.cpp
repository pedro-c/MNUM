#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

double corda() {

	//Função  x ^ 4 + 2x ^ 3 - x - 1 = 0
	double a, b;

	cout << "Indique o intervalo: " << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	double fa, fb, fx, x, xn;
	xn = 0;
	int i = 0;
	do {
		x = xn;
		//função
		fa = pow(a, 4) + 2 * pow(a, 3) - a - 1;
		//função
		fb = pow(b, 4) + 2 * pow(b, 3) - b - 1;
		xn = (a*fb - b*fa) / (fb - fa);
		fx = pow(xn, 4) + 2 * pow(x, 3) - xn - 1;

		if ((fa*fx) < 0) {
			b = xn;
		}
		else {
			a = xn;
		}

		i++;
		cout << "Iteracao n.  " << i << "| x = " << xn << endl;
	} while ((abs(x - xn)) > 0.00001);

	return xn;

}

double bissecao() {

	//Função  x^4 + 2x^3 -x -1 = 0
	double a, b;

	cout << "Indique o intervalo: " << endl;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	double fa, fb, fx, x, xn;
	xn = 0;
	int i = 0;
	do {
		x = xn;
		fa = pow(a, 4) + 2 * pow(a, 3) - a - 1;
		fb = pow(b, 4) + 2 * pow(b, 3) - b - 1;
		xn = (a + b) / 2;
		fx = pow(xn, 4) + 2 * pow(x, 3) - xn - 1;

		if ((fa*fx) < 0) {
			b = xn;
		}
		else {
			a = xn;
		}

		i++;
		cout << "Iteracao n.  " << i << "| x = " << xn << endl;
	} while ((abs(x - xn)) > 0.00001);

	return xn;



}

double tangente() {

	double x = 0, xn = 0, fxn = 0, dfxn = 0;

	//Funçao = x^4 -2x^3- x -1
	//f'(x) = 4x^3 + 6x^2 - 1
	// x = 1, dado pelo enunciado
	//xn = xn-(fxn/dfxn)
	xn = 1;
	fxn = (pow(xn, 4)) - 2 * (pow(xn, 3)) - xn - 1;
	dfxn = 4 * (pow(xn, 3)) + 6 * (pow(xn, 2)) - 1;
	xn = xn - (fxn / dfxn);
	int i = 0;
	do {
		x = xn;
		fxn = pow(xn, 4) + 2 * pow(xn, 3) - xn - 1;
		dfxn = 4 * pow(xn, 3) + 6 * pow(xn, 2) - 1;
		xn = xn - (fxn / dfxn);
		i++;
		cout << "Iteracao n.  " << i << "| x = " << xn << endl;

	} while ((abs(xn - x)) > 0.00001);

	return xn;

}

double picardPeano() {

	//F(x) = 1 + x + e ^ (x)
	//x=-(1+e^(x))
	//

	double x, xn, gx, guess = 0;
	cout << "Enter guess: ";
	cin >> guess;

	x = guess;
	gx = -(1 + exp(x));
	xn = gx;
	int i = 0;

	do {
		x = xn;
		gx = -(1 + exp(x));
		xn = gx;
		i++;
		cout << "Iteracao n.  " << i << "| x = " << xn << endl;

	} while ((abs(xn - x)) > 0.00001);

	return xn;


}


int main() {

	int opcao;
	double x = 0;

	cout << "1.Bissecao" << endl;
	cout << "2.Corda" << endl;
	cout << "3.Tangente/Newton" << endl;
	cout << "4.Picard-Peano" << endl;
	cout << "opcao: ";

	cin >> opcao;

	switch (opcao) {
	case 1:
		x = bissecao();
		break;
	case 2:
		x = corda();
		break;
	case 3:
		x = tangente();
		break;
	case 4:
		x = picardPeano();
		break;
	}





	cout << x << endl;

	return 0;

}