#include "office.h"

class employee : public Office
{
protected:
    Office empl;
	vector <Office> myv;
    int top ;
public:
    employee();
    ~employee();
    int Search(string ID);
    void add_empl();
	void edit_empl();
    void delet();
	void salary();
	void overtime();
	void show_employee_details();
	void inp_office_data();
	void handler();
    
};