#include "office.h"

Office :: Office() {}
Office :: ~Office() {}

void Office :: SetNoE(string noe) 
{
    NoE = noe;
}
void Office :: SetID(string id) 
{
    ID = id;
}
void Office :: SetYoJ(double yoj) 
{
    YoJ = yoj;
}
void Office :: SetNoP(string nop) 
{
    NoP = nop;
}
void Office :: SetCoP(string cop) 
{
    CoP = cop;
}


string Office :: GetNoE() 
{
    return NoE;
}
string Office :: GetID() 
{
    return ID;
}
double Office :: GetYoJ() 
{
    return YoJ;
}
string Office :: GetNoP()
{
    return NoP;
}
string Office :: GetCoP() 
{
    return CoP;
}


void Office :: ShowInfo() 
{
    cout << "Employee Name	:"<< GetNoE() << endl << endl;
	cout << "ID Number	:"<< GetID() << endl << endl;
	cout << "Year of joining	:"<< GetYoJ() << endl << endl;
	cout << "Name of Post	:"<< GetNoP() << endl << endl;
	cout << "Class of Post	:" << GetCoP() << endl << endl;
}