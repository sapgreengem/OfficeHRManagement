#include "office_manage.h"

employee :: employee()
{
    top = 0;
}
employee :: ~employee(){}

int employee :: Search(string ID)
{
    for( int i = 0; i < myv.size() ; i++)
	{
		if( myv[i].GetID() == ID )
			return i;
    }
    return -1;
}

void employee :: add_empl()
{
	string name;
	cout << endl;
	cout << "Put Employee name: ";
	cin >> name;
	cout << endl;
	empl.SetNoE(name);
    
	string id;
	cout << "Put Employee ID: ";
	cin >> id;
	cout << endl;
	empl.SetID(id);

	double yoj;
	cout << "Input Year of joining: ";
	cin >> yoj;
	cout << endl;
	empl.SetYoJ(yoj);

	string nop;
	cout << "Input post name: ";
	cin >> nop;
	cout << endl;
	empl.SetNoP(nop);

	string cop;
	cout << "Input class of post: ";
	cin >> cop;
	cout << endl;
	empl.SetCoP(cop);    
	myv.push_back(empl);
	
	ofstream Employeefile;
	Employeefile.open ("Employee data.txt", ios :: trunc );
	if (Employeefile.is_open())
	{
		Employeefile << empl.GetNoE() << "\t" << empl.GetID() << "\t" << empl.GetYoJ() << "\t" << empl.GetNoP() << "\t" << empl.GetCoP() << endl;
	}
	Employeefile.close();

	system("cls");
    cout << endl << endl << "New Employee Added........................." << endl << endl;
    empl.ShowInfo();
}

void employee :: salary()
{
    string ID;
	cout << endl << endl;
    cout << "Enter ID number: ";
    cin >> ID;
    int a = Search(ID);
    if(a > -1)
	{
		cout << endl << "Name of employee : " << myv[a].GetNoE() << endl;
		
		double BasSal; //Basic salary
		cout << endl  << endl;
		cout << "Input basic salary : ";
		cin >> BasSal;
		cout << endl;
		
		double CurYer; //Current year
		cout << "input current year : ";
		cin >> CurYer;
		
		double incr; //incriment
		incr = (CurYer-myv[a].GetYoJ())*1000;
		
		double edu; //children education cost
		{
			int i;
			cout << endl  << endl << "If NO children	Press 0 " << endl << "For 1 child	Press 1 " << endl << "For 2 children	Press 2 " << endl;
			cout << endl;
			cout << "Enter your choice : ";
			cin >> i;
			switch (i)
			{
			case 0:
				edu=0;
				break;

			case 1:
				edu=200;
				break;

			case 2:
				edu=300;
				break;
			default:
				cout << "Wrong choice" << endl;
				break;
			}
		}
		double hr; //House Rent
		hr=BasSal*0.6;
		if(hr<3300)
			hr=3300;
	
		double ext;//Extention
		ext=BasSal*0.2;
		if(ext<1500)
			ext=1500;
		
		double med=700;
		double trnpo=150;
		double tiff=150;
		double risk=60;
		double tot; // total salary
		tot = BasSal + incr + med + trnpo + tiff + risk + hr + ext + edu;
		cout << endl << endl;
		cout << "Monthly Total salary is : " << tot << endl;
	}

	else
        cout << endl << endl << "Invalid Employee" << endl << endl;
}

void employee :: overtime()
{
	string ID;
	cout << endl << endl;
    cout << "Enter ID number: ";
    cin >> ID;
    int a = Search(ID);
    if(a > -1)
	{
		cout << endl << "Name of employee : " << myv[a].GetNoE();
		
		double WH; //Working Hour
		cout << endl  << endl;
		cout << "Input Working Hour : ";
		cin >> WH;
		cout << endl;
		
		double WPH; //Wage per Hour
		cout << "Input Wage per Hour : ";
		cin >> WPH;
		cout << endl;
		
		double month; // days of month
		cout << "Input number of days in this month : ";
		cin >> month;
		cout << endl;

		double OV_bill; //incriment
		OV_bill = WH*WPH*month;
		cout << "Overtime bill is : " << OV_bill << endl << endl;
	}
	else
        cout << endl << endl << "Invalid Employee" << endl << endl;
}

void employee :: edit_empl()
{
    string ID;
	cout << endl;
    cout << "Enter ID Number : ";
    cin >> ID;
	cout << endl;
	cout << endl;
    int a = Search(ID);
    if(a > -1)
	{
		string name;
		cout << "Put Employee New name: ";
		cin >> name;
		cout << endl;
		myv[a].SetNoE(name);
    
		string id;
		cout << "Put New Employee ID: ";
		cin >> id;
		cout << endl;
		myv[a].SetID(id);

		double yoj;
		cout << "Input Year of joining: ";
		cin >> yoj;
		cout << endl;
		myv[a].SetYoJ(yoj);

		string nop;
		cout << "Input post name: ";
		cin >> nop;
		cout << endl;
		myv[a].SetNoP(nop);

		string cop;
		cout << "Input class of post: ";
		cin >> cop;
		cout << endl;
		myv[a].SetCoP(cop);
		system("cls");
        cout << endl << endl << "Employee info updated ............................" << endl << endl;
    }
    else
        cout << endl << "Invalid Employeer" << endl;
	    myv[a].ShowInfo();
}

void employee :: delet()
{
    string ID;
	cout << endl;
    cout << "Enter ID number: ";
    cin >> ID;
	cout << endl;
	cout << endl << endl;
    int a = Search(ID);
    if(a > -1)
	{
        myv[a].SetNoE("\0");
        myv[a].SetID("\0");
        myv[a].SetYoJ(0);
		myv[a].SetNoP("\0");
		myv[a].SetCoP("\0");
		cout << endl << endl << "Employee Deleted ..............................." << endl << endl;
    }
    else
        cout << endl << "Invalid Employee" << endl;
    myv[a].ShowInfo();
}

void employee :: show_employee_details()
{
    string ID;
	cout << endl;
    cout << "Enter the ID number: ";
    cin >> ID;
	cout << endl;
	cout << endl << endl;
    int a = Search(ID);
    if(a > -1)
	{
		myv[a].ShowInfo();
	}
    else
        cout << endl << "Invalid Employee" << endl;
}

void employee :: inp_office_data()
{
	string data;
	cout << endl;
	cout << "Type data to store" << endl << endl;
	cin >> data;
	cout << endl;
	cout << data << endl << endl;
}

void employee :: handler()
{
    char choice = '\0';
	int select;
    while(choice != 'n' && choice != 'N')
	{
		cout << endl << endl << "**************** OFFICE MANAGEMENT ****************" << endl << endl << endl;
		cout << "press 1 : Add Employee" << endl << endl;
		cout << "Press 2 : Monthly Salary Bill of Employee" << endl << endl;
		cout << "Press 3 : Monthly Overtime Bill of Employee" << endl << endl;
		cout << "press 4 : Edit Employee" << endl << endl;
		cout << "press 5 : Delete Employee" << endl << endl;
		cout << "press 6 : Show Employee Details" << endl << endl;
		cout << "Press 7 : Office Data Entry" << endl << endl << endl << endl;
		cout << "Enter Your Choice :" ;
		cin >> select;
		system("cls");
		switch(select)
		{
		case 1:
			add_empl();
			break; 
		case 2:
			salary();
			break;
		case 3:
			overtime();
			break;
		case 4:
			edit_empl();
			break;
		case 5:
			delet();
			break;
		case 6:
			show_employee_details();
			break;
		case 7:
			inp_office_data();
			break;
		default:
			cout << "Wrong choice" << endl;
			break;
		}
		cout << endl << "Press n/N to quit " << "\t" << "Enter any other Key to continue" << endl;
		cin >> choice;
		system("cls");
	}
}