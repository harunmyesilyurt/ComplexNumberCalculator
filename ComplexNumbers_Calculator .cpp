/**************************
**					SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				    B�LG�SAYAR M�HEND�SL��� B�L�M�
**				          PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 02
**				��RENC� ADI...............: Harun Mahmut Ye�iyurt
**				��RENC� NUMARASI.: G211210089
**				DERS GRUBU����: C Group 2. �nstruction
**************************/

#include <math.h>
#include <string> 
#include <iostream>

using namespace std;

class ComplexNum
{
	//ComplexNum Class
private:
	int _reel;
	int _imag;

public:
	void setReel(int r) { _reel = r; }
	void setImag(int i) { _imag = i; }
	int getReel() { return _reel; }
	int getImag() { return _imag; }

	void print(string i)
	{
		if (_imag > 0)
		{
			cout << i << _reel << " + " << _imag << "i" << endl;
		}
		else if (_imag < 0)
		{
			cout << i << _reel << " - " << _imag << "i" << endl;
		}
		else
		{
			cout << i << _reel << endl;
		}
	}

	ComplexNum ComplexNumTransaction(ComplexNum obj1, ComplexNum obj2, string operation)
	{
		/*
		  1- Addition
		  2- Extraction
		  3- Division
		  4- Multiplation
		*/

		ComplexNum compnum;
		if (operation == "1") {
			compnum.setReel(obj1.getReel() + obj2.getReel());
			compnum.setImag(obj1.getImag() + obj2.getImag());
		}
		else if (operation == "2") {
			compnum.setReel(obj1.getReel() - obj2.getReel());
			compnum.setImag(obj1.getImag() - obj2.getImag());
		}
		else if (operation == "3") { /**/
			float reelsayi = obj1.getReel() * obj2.getReel() + obj1.getImag() * obj2.getImag();
			compnum.setReel(((obj1.getReel() * obj2.getReel()) - obj1.getImag() * (-1 * obj2.getReel()) / reelsayi));
			compnum.setImag(((obj1.getReel() * (-1 * obj2.getImag()) + obj1.getImag() * obj2.getReel()) / reelsayi));
		}
		else if (operation == "4") {
			compnum.setReel(obj1.getReel() * obj2.getReel());
			int aritmethic = (obj2.getImag() * obj1.getImag()) + (obj2.getReel() * obj1.getImag()) + (obj1.getReel() * obj2.getImag()); /**/
			compnum.setImag(aritmethic);
		}
		return compnum;
	}

	void Polar(ComplexNum object)
	{
		//Polar Notation
		int reel = object.getReel(), imag = object.getImag();
		double r = sqrt(reel * reel + imag * imag);
		double Angle = reel / imag;

		cout << "Polar Representation of a Complex Number ," << endl;
		cout << "1) " << "Z = a + bi" << endl << endl;
		cout << "2) " << "|Z| = r" << endl << endl;
		cout << "3) " << "r" << " = " << "(" << reel << "(a)^2  +  " << imag << "(b)^2)^1/2" << endl << endl;
		cout << "4) " << reel << "(a) = " << "sin(Angle).r" << endl << endl;
		cout << "5) " << imag << "(b) = " << "cos(Angle).r" << endl << endl;
		cout << "6) " << "Z = r.(cos(Angle) + i.sin(Angle))" << endl << endl;

		cout << "Angle : " << Angle << " Radian : " << (Angle * 180) / 3.14 << " Degree" << endl << endl;
		cout << "r : " << r << endl << endl << endl;

		cout << "Polar value : " << r << "(" << cos(Angle) << " Pi  +  " << sin(Angle) << "i Pi)" << endl << endl;
	}
};

string MainMenuMethod()
{
	//Menu
	system("cls");
	string Options;

	cout << "Hello ," << endl;
	cout << "Please choose one of the options : " << endl;

	cout << "1- Addition : " << endl;
	cout << "2- Extraction process : " << endl;
	cout << "3- Division : " << endl;
	cout << "4- Multiplication : " << endl;
	cout << "5- Polar value of complex number : " << endl;

	cin >> Options;
	return Options;
}
ComplexNum SetValue(string num)
{
	int reel, imag;
	ComplexNum comp;

	cout << "Please enter reel for " + num + ". Complex num: "; cin >> reel;
	cout << "Please enter imag for " + num + ". Complex num: "; cin >> imag;

	comp.setReel(reel);
	comp.setImag(imag);

	return comp;
}

int main()
{
	ComplexNum complexNum;
	ComplexNum cmp1, cmp2, result;

	//Methods
	string option = MainMenuMethod();
	cmp1 = SetValue("1");
	cmp2 = SetValue("2");


	if (option != "5") //Operation control
	{
		result = complexNum.ComplexNumTransaction(cmp1, cmp2, option);
		result.print(" ");
	}
	else
	{
		system("cls");
		complexNum.Polar(cmp1);
	}

	string Orientation;
	cout << "Please press '0' to return to the previous menu...." << endl;
	cout << "If you want to terminate the program, press any key and click 'Enter'..." << endl;
	cin >> Orientation;

	if (Orientation == "0")
	{
		return main();
	}
}
