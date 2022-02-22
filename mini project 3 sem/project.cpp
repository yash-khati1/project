#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<string>
using namespace std;

class graphics
{
    public:
       void border(int, int,int, int);
};
/*
        LOGIN CLASS
*/
class user_login
{
public:
    user_login()
    {
        success = 0;
    }
    void login();
private:
    string passWord="password";
    string userName="Yash";
    bool success;

};


/*
        EMPLOYEE CLASS
*/

class employee
{
    string name,dept,desig;
    int id,age;
    long int basicPay,medicalReimbursement=1500,otherAllowance,npay;

public:
    void getdata();
    void showdata();
    void showpayData(int);

    int  returnId()
    {
        return id;
    }

};

void gotoxy(int x,int y)
{
    COORD coordinates;
    coordinates.X=x;
    coordinates.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void graphics::border(int xLenS = 2, int yLenS = 2,int xLenE = 84, int yLenE = 32 )
{
	gotoxy(xLenS,yLenS);printf("%c",178);

	gotoxy(xLenS,yLenE);printf("%c",178);

    for(int i=xLenS+1;i<=xLenE-1;i++)         //Top and Bottom Border line
    {
        Sleep(5);
        gotoxy(i,yLenS);
        printf("%c",178);
        gotoxy(i,yLenE);
        printf("%c",178);

    }
    gotoxy(xLenE,yLenS);printf("%c",178);
    gotoxy(xLenE,yLenE);printf("%c",178);
    for(int i=yLenS+1;i<=yLenE-1;i++)         //Left and Right Border Line
    {
        Sleep(5);
        gotoxy(xLenS, i);
        printf("%c",178);
        gotoxy(xLenE, i);
        printf("%c",178);
    }
}
/*
 _______________________________________
|CLASS USER LOGIN FUNCTIONS DEFINITIONS |
|_______________________________________|
*/
void user_login::login()
{
    system("cls");
    m:
    graphics g;
    g.border();
    char ch;
    string user_Name;
    string pass_word;
    gotoxy(25,8);
    cout<<"Enter User name :- ";
    getline(cin,user_Name);
    if(!(user_Name.compare(userName)))
    {
        gotoxy(25,10);
        cout<<"Enter Password :- ";
        ch=_getch();
        while(ch != 13)
	    {
    	    pass_word.push_back(ch);
    	    cout << '*';
    	    ch = _getch();
	    }	
        if(!(pass_word.compare(passWord)))
        {
            gotoxy(32,12);
            cout<<"Access Granted ";
            gotoxy(25,14);
            cout<<"Rediricting To Main Menue ";
            char c;
            for(int i=0;i<6;i++)
            {
                printf("%c",254);
                Sleep(200);
            }
        }
        else
        {
            gotoxy(20,12);
            cout<<"Access Denied(Incorrect Password) !! ";
            gotoxy(32,14);
            cout<<"Try again ";
            char c;
            for(int i=0;i<6;i++)
            {
                printf("%c",254);
                Sleep(300);
            }
            system("cls");
            goto m;
        }
    }
    else
    {
        gotoxy(20,10);
        cout<<"Access Denied(Incorrect User name) ";
        gotoxy(30,13);
        cout<<"Try again ";
        char c;
        for(int i=0;i<6;i++)
        {
            printf("%c",254);
            Sleep(300);
        }
        system("cls");
        goto m;
    }
}

/*
 _______________________________________
|  CLASS EMPLOYEE FUNCTIONS DEFINITIONS |
|_______________________________________|
*/
void employee::getdata()
{
        graphics g;
        g.border();
        gotoxy(25,5);
        cout<<"ENTER DETAILS";
        gotoxy(10,8);
        fflush(stdin);
        cout<<"Name: ";
        getline(cin,name);
        gotoxy(10,10);
        cout<<"Id: ";
        cin>>id;
        gotoxy(10,12);
        cout<<"Age: ";
        cin>>age;
        gotoxy(10,14);
        cout<<"Department: ";
        cin>>dept;
        gotoxy(10,16);
        cout<<"Designation: ";
        cin>>desig;
        gotoxy(39,8);
        cout<<"Enter Pay Data";
        gotoxy(35,10);
        cout<<"Basic Pay: ";
        cin>>basicPay;
        gotoxy(35,12);
        cout<<"House Rent Allowance(50% of basic pay): ";
        cout<<(basicPay/2);
        gotoxy(35,14);
        cout<<"Conveyance Allownance(10% of basic pay): ";
        cout<<(basicPay/10);
        gotoxy(35,16);
        cout<<"Medical Reimbursement: ";
        cout<<medicalReimbursement;
        gotoxy(35,18);
        cout<<"Other Allownances: ";
        cin>>otherAllowance;
        npay=basicPay+(basicPay/2)+(basicPay/10)+otherAllowance;
    }

void employee::showdata()
    {
        graphics g;
        g.border();
        long int npay;
        npay=basicPay+(basicPay/2)+(basicPay/10)+otherAllowance;
        gotoxy(10,9);
        cout<<"Employee ID : "<<id;
        gotoxy(10,11);
        cout<<"Employee Name : "<<name;
        gotoxy(10,13);
        cout<<"Age : "<<age;
        gotoxy(10,15);
        cout<<"Department : "<<dept;
        gotoxy(10,17);
        cout<<"Designation : "<<desig;
        gotoxy(10,19);
        cout<<"Basic Pay : Rs "<<basicPay;
        gotoxy(50,9);
        cout<<"Conveyence Allowance : Rs "<<(basicPay/2);
        gotoxy(50,11);
        cout<<"House Rent Allowance: Rs "<<(basicPay/10);
        gotoxy(50,13);
        cout<<"Medical Reimbursement : Rs "<<medicalReimbursement;
        gotoxy(50,15);
        cout<<"Other Allownances : Rs "<<otherAllowance;
        gotoxy(50,17);
        cout<<"Net Pay: Rs "<<npay;
    }

void employee::showpayData(int j)
 {
        gotoxy(10,j);
        cout<<id;
        gotoxy(22,j);
        cout<<name;
        gotoxy(35,j);
        cout<<age;
        gotoxy(42,j);
        cout<<dept;
        gotoxy(54,j);
        cout<<desig;
        gotoxy(65,j);
        cout<<npay;
}
/*____________________
 |  DECLARING OBJECT  |
 |____________________|
*/
fstream fe;
employee ep;

/*
 _______________________________________
|  FUNCTION TO ADD NEW EMPLOYEE         |
|_______________________________________|
*/

void add_Employee()
{
    fe.open("employee.dat",ios::out|ios::app);
    ep.getdata();
    fe.write((char*)&ep,sizeof(employee));
    fe.close();
    gotoxy(25,25);
    cout<<"Employee record has been created!!! ";
    getch();
}


/*
 ________________________________
|  FUNCTION TO SEARCH EMPLOYEE   |
|________________________________|
*/
bool search_Emp(int n)
{
    bool flag=false;
    fe.open("employee.dat",ios::in);
    while(fe.read((char*)&ep,sizeof(employee)))
    {
        if(ep.returnId()==n)
        {
            gotoxy(35,7);
            cout<<"SEARCH RESULT";
            ep.showdata();
            flag=true;
        }
    }
    fe.close();
    if(flag==false)
    {
        system("cls");
        graphics g;
        g.border();
        gotoxy(25,15);
        cout<<"Record doesn't exist!!!";
    }    
    getch();
    return flag;
}

/*____________________________
 |  MODIFY EMPLOYEE RECORD    |
 |____________________________|
*/ 
void modifyEmployee()
{
    int num,found=0;
    system("cls");
    gotoxy(30,5);
    cout<<"Modifying Record ";
    gotoxy(10,6);
    cout<<"Enter The Id of Employee : ";
    cin>>num;
    fe.open("employee.dat",ios::in|ios::out);
    while(fe.read((char*)&ep,sizeof(employee)) && found==0)
    {
        if(ep.returnId()==num)
        {
            gotoxy(30,7);
            cout<<"Previous  Details";
            ep.showdata();
            gotoxy(25,23);
            cout<<"Press enter to fill new details ";
            getch();
            system("cls");
            ep.getdata();
            int pos=-1*sizeof(ep);
            fe.seekp(pos,ios::cur);
            fe.write((char*)&ep,sizeof(employee));
            gotoxy(30,22);
            cout<<" Record Updated!!!";
            found=1;
        }
    }
    fe.close();
    if(found==0)
    {   
        gotoxy(25,15);
        cout<<"Record Not Found!!!";
    }    
    getch();
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
//                FUNCTION TO DELETE RECORD                     <>
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
 
void deleteEmployee()
{
    int num;
    system("cls");
    graphics g;
    g.border();
    gotoxy(35,5);
    cout<<"Delete Record ";
    gotoxy(20,7);
    cout<<"Enter Employee ID to be Deleted : ";
    cin>>num;
    system("cls");
    if(search_Emp(num))
    {
        fe.open("employee.dat",ios::in|ios::out);
        fstream ft;
        ft.open("Temp.dat",ios::out);
        ft.seekg(0,ios::beg);
        while(fe.read((char*)&ep,sizeof(employee)))
        {
            if(ep.returnId()!=num)
            {
                ft.write((char*)&ep,sizeof(employee));
            }
        }
        ft.close();
        fe.close();
        remove("employee.dat");
        rename("Temp.dat","employee.dat");
        gotoxy(30,22);
        cout<<"Record Deleted!!!";
    }    
    getch();
}


/* ___________________________
  |       Display Pay Data    |      
  |___________________________|
*/

void emp_list()
{
    system("cls");
    graphics g;
    g.border();
    fe.open("employee.dat",ios::in);
    if(!fe)
    {
        gotoxy(30,7);
        cout<<"ERROR!!!";
        gotoxy(20,9);
        cout<<"No File Exist of Employee Record ";
        gotoxy(30,11);
        cout<<"Exiting...";
        getch();
        return;
    }
    gotoxy(26,5);
    cout<<"DISPLAYING ALL EMPLOYEE PAY DATA ";
    gotoxy(10,7);
    cout<<"ID";
    gotoxy(25,7);
    cout<<"NAME";
    gotoxy(35,7);
    cout<<"AGE";
    gotoxy(42,7);
    cout<<"DEPT.";
    gotoxy(54,7);
    cout<<"DESIG.";
    gotoxy(66,7);
    cout<<"NETPAY";
    int j=9;
    while(fe.read((char*)&ep,sizeof(employee)))
    {   
        ep.showpayData(j);
        j+=2;
    }
    fe.close();
    getch();
}

/*
 ________________________________
|MAIN MENUE FUNCTION DEFINITION  |
|________________________________| 

*/

void mainMenu()
{
    system("cls");
    graphics g;
    g.border();
    char ch2;
    gotoxy(35,5);
    cout<<" ** MAIN MENU ** ";
    gotoxy(25,7);
    cout<<"1. Add Employee Data";
    gotoxy(25,9);    
    cout<<"2. Search Employee Record ";
    gotoxy(25,11);
    cout<<"3. Modify Employee Data";
    gotoxy(25,13);
    cout<<"4. Delete Employee Data";
    gotoxy(25,15); 
    cout<<"5. Display Employee List";
    gotoxy(25,17);
    cout<<"6. Back to Previous Menu";
    gotoxy(25,22);
    cout<<"Please Enter Your Choice (1-6) ";
    ch2=getche();
    switch(ch2)
    {
    case '1':
        system("cls");
        add_Employee();
        break;
    case '2':
        int num;
        system("cls");
        g.border();
        gotoxy(10,5);
        cout<<"Enter employee ID to Search : ";
        cin>>num;
        bool temp;
        system("cls");
        temp=search_Emp(num);
        break;
    case '3':
        modifyEmployee();
        break;
    case '4':
        deleteEmployee();
        break;
    case '5':
        emp_list();
        break;
    case '6':
        break;
    default:
        cout<<"\a";
        mainMenu();
    }
}

void menue()
{
    graphics g;
    char ch;
    do
    {
        system("cls");
        g.border();
        gotoxy(35,5);
        cout<<"WELCOME";
        gotoxy(39,7);
        cout<<"TO";
        gotoxy(27,9);
        cout<<"PAYROLL MANAGEMENT SYSTEM";
        gotoxy(30,11);
        cout<<"1. ENTER MAIN MEMUE";
        gotoxy(30,13);
        cout<<"2. EXIT";
        gotoxy(27,15);
        cout<<"Please Select Your Option : ";
        ch=getch();
        switch(ch)
        {
        case '1':
            mainMenu();
            break;
        case '2':
            exit(0);
        default :
            cout<<"\a";
        }
    }
    while(ch!='2');    
}


int main()
{
    user_login lobj;
    lobj.login();
    menue();
}
