#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

class Office
{
private:
    string NoE; //Name of Employee
	string ID; //Employee ID
	double YoJ; //Joyning Year
	string NoP; //Name of post
	string CoP; //Class of post

public:
    Office();
    ~Office();
    void SetNoE(string noe);
	void SetID(string id);
	void SetYoJ(double yoj);
	void SetNoP(string nop);
	void SetCoP(string cop);
    string GetNoE();
	string GetID ();
	double GetYoJ();
	string GetNoP();
	string GetCoP();
    void ShowInfo();
};