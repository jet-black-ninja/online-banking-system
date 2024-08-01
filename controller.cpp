#include"headers/controller.h"
#include"headers/credentials.h"
#include"headers/customer.h"
#include"headers/employee.h"
#include"headers/support.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<clib>
#include<algorithm>

using namespace ;
void Controller::showBanner(){
    system("clear");
    Support support;
    support.drawLine(100);
    cout<<"\t\t \e[3mBank Management System\e[0m"<<endl;
    support.drawLine(100);
}

void Controller::showMenu(){
    int ch;
    cout<<"1. Customer Login"<< endl;
    cout<<"2. Employee Login"<< endl;
    cout<<"3. Admin(id: sachin,pass: pass)"<<endl;
    cout<<"4. Credits"<<endl;
    cout<<"5. Exit"<< endl;

    cout<< endl << endl;
    cout<<"\t Enter choice :"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
            showCustomerLogin();
            break;
        case 2:
            showEmployeeLogin();
            break;
        case 3:
            {
                string id, pass;
                cout<<"Enter Your ID :\t";
                cin>>id;
                cout<<endl<<"Enter Your Password:\t";
                cin>>pass;
                if(id=="sachin" && pass=="pass")
                showAdmin();
                else 
                    cout<<"Invalid Password"<<endl;

            }
            break;
        case 4:
            showCredits();
            break;
        case 5:
            exit(0);
        default:
            cout<<"Invalid Input. Try Again ..."<<endl;
    }
}

void Controller::showCustomerLogin(){
    Credential credTemp;
    Customer cust;
    vector<Credential> credVector;
    fstream fin("customer.txt",ios::binary | ios::in);//open encrypted customer file
    while(fin.read((char*)& cust, sizeof(Customer))){
        credTemp.setID(cust.getID());
        credTemp.setPass(cust.getPass());
        credVector.push_back(credTemp);
    }
    fin.close(); //close file

    int id;
    char pass[30];
    cout<<"Login ID :";
    cin>>id;
    cout<<"Password : ";
    cin>>pass;
    Credential userCredential(id, pass);
    bool SUCCESS= false;
    int SESSION = -1;
    for(vector<Credential>::iterator itr = credVector.begin(); itr != credVector.end() ; itr++){
        if(userCredential == *itr){
            cout<<"Authentication Successful !"<<endl;
            SUCCESS = true;
            SESSION = userCredential.ID;
            showCustomerPortal(SESSION);
        }
    }
    if(!SUCCESS){
        cout<<"Authentication Failed .Try Again ..."<<endl;
    }
}

void Controller::showCustomerPortal(const int SESSION){
    bool running = true;
    while(running){
        vector<Customer>custVector;
        fstream fin("customer.txt",ios::binary | ios::in);//load in customer file
        Customer customer;
        while(fin.read((char*)& customer, sizeof(Customer))){
            custVector.push_back(customer);
        }

        cout<<"1. View Balance"<<endl;
        cout<<"2. View Transactions"<<endl;
        cout<<"3. Change Password"<<endl;
        cout<<"4. Logout to Main Menu"<<endl;
        int ch;
        cin>>ch;

        switch(ch){
            case 1:
            {
                for(vector<Customer> ::iterator itr = custVector.begin();
                itr!=custVector.end(); itr++){
                    if(itr->getID()==SESSION)
                        itr->showDetails();
                }
            }
            break;
            case 2:
            //TODO implement transactions
            break;
            case 3:
            Controller::changeCustomerPassword(SESSION);
            break;
            case 4:
            running = false;
            break;
            default :
            cout<<"INVALID ARGUMENT . Try Again ..."<<endl;

        }
    }
}

void Controller:: showEmployeeLogin(){
    Credential credTemp;
    Employee emp;
    vector<Credential> credVector;
    fstream fin("employee.txt",ios::binary|ios::in);
    while(fin.read((char*)&emp,sizeof(Employee))){
        credTemp.setID(emp.getID());
        credTemp.setPass(emp.getPass());
        credVector.push_back(credTemp);
    }
    fin.close();
    int id;
    char pass[30];
    cout<<"Login ID : ";
    cin>>id;
    cout<<"Password : ";
    cin>>pass;
    Credential userCredential(id, pass);
    bool SUCCESS= false;
    int SESSION = -1;
    for(vector<Credential>::iterator itr=credVector.begin(); itr!=credVector.end(); ++itr)
    {
        if(userCredential==*itr)
        {
            cout<<"Authentication successful"<<endl<<endl;
            SUCCESS=true;
            SESSION=userCredential.ID;
            showEmployeePortal(SESSION);
        }
    }
    if(!SUCCESS)
    {
        cout<<"Authentication Failed. Try Again ..."<<endl;
    }
}

void Controller:: showEmployeePortal(const int SESSION){
    cout<<"1. Add Customer"<<endl;
    cout<<"2. Modify Customer"<<endl;
    cout<<"3. View Customers(DEFAULT CHRONOLOGICAL)"<<endl;
    cout<<"4. View Customers by"<<endl;
    cout<<"5. Search Customer"<<endl;
    cout<<"6. Deposit Money to Customer account"<<endl;
    cout<<"7. Withdraw Money from Customer account"<<endl;
    cout<<"8. Logout and return to Main Menu"<<endl;
    int ch;
    cin>>ch;
    bool running=true;
    switch(ch){
        case 1:
            addCustomer();
            break;
        case 2:
            modifyCustomer();
            break;
        case 3:
            displayCustomers();
            break;
        case 4:
            displayCustomersBy();
            break;
        case 5:
            //TODO searchCustomer();
            break;
        case 6:
            deposit();
            break;
        case 7:
            withdraw();
            break;
        case 8:
            running = false;
            break;
        default:
            cout<<"Invalid Option. Try Again ...";
            break;
    }
}

void Controller::showAdmin(){
    bool running = true;
    while(1){
    Support support;
    support.drawLine(50);
    cout<<"\e[3mADMIN PORTAL\e[3m";
    support.drawLine(50);
    cout<<"1. Add Employee\n 2. Modify Employee\n 3. Display Employees\n 4. Delete Employees\n 5. Add customer\n 6. Modify Customer\n 7. Display Customers\n 8. Delete Customer\n 9. Deposit to Customer A/C\n 10. Withdraw from Customer A/C\n11. Logout to Main Menu\n";
    int ch;
    cout<<"Enter you Choice : ";
    cin>>ch;
    switch(ch){
        case 1:
            addEmployee();
            break;
        case 2:
            modifyEmployee();
            break;
        case 3:
            displayEmployees();
            break;
        case 4:
            deleteEmployee();
            break;
        case 5:
            addCustomer();
            break;
        case 6:
            modifyCustomer();
            break;
        case 7:
            displayCustomers();
            break;
        case 8:
            deleteCustomer();
            break;
        case 9:
            deposit();
            break;
        case 10:
            withdraw();
            break;
        case 11:
            running = false;
            break;
        default:
            cout<<"Invalid Option . Try Again ..."<<endl;
    }   
    if(!running)
        break;
    }
}

void Controller::showCredits(){
    Support support;
    system("clear");
    support.drawLine(100);
    cout<<"\t\t \e[3mBank Management System\e[0m"<<endl;
    support.drawLine(100);
    cout<<endl<<"\t Created by Sachin Kumar Singh <sachinkmrsin@gmail.com>"<<endl;
    support.drawLine(100);
    char buff[10];
    cout<<"Press to Continue"<<endl;
    cin>>buff;
}

void Controller::addCustomer(){
    vector<Customer> custVector;
    fstream fin("customer.txt",ios::binary | ios::in);
    Customer customer;
    while(fin.read((char*)& customer, sizeof (Customer))){
        custVector.push_back(customer);
    }
    fin.close();
    int id;
    cout<<"Enter Customer ID";
    cin>>id;
    bool flag = true;
    //check if id already exists in the data base
    for(vector<Customer>::iterator itr = custVector.begin() ; itr!= custVector.end() ; itr++){
        if(itr->getID() == id){
            flag= false;
            break;
        }
    }
    if(flag){
        char name[30], address[30],pass[30];
        long int phone;
        TimeStamp dob;
        float bal;
        cin.ignore();
        cout<<"Enter Customer's Name : "<<endl;
        cin.getline(name,30);
        cout<<"Enter Address : "<<endl;
        cin.getline(address, 30);
        cout<<"Enter Phone number : "<<endl;
        cin>>phone;
        cout<<"Enter Date of Birth (DD MM YYYY) [SEPARATED BY SPACES] ";
        int dd, mm ,yy ;
        cin>>dd>>mm>>yy;
        dob.set(dd,mm,yy);
        cout<<endl<<"Enter Password"<<endl;
        cin.ignore();
        cin.getline(pass,30);
        cout<<"Enter Bank Balance"<<endl;
        cin>>bal;
        Customer cust(id, name, address, phone, dob, pass, bal);
        fstream fout("customer.txt", ios::binary | ios::out | ios::app);
        fout.write((char*)&cust , sizeof(Customer));
        fout.close();
    }else {
        cout<<"Customer ID already exist. Please Try another ID "<<endl;
    }
}

void Controller::modifyCustomer(){
    Support support;
    vector<Customer> custVector;
    Customer cust;
    fstream fin("customer.txt", ios::binary | ios:: in);
    while(fin.read((char*)& cust , sizeof(Customer))){
        custVector.push_back(cust);
    }
    fin.close();
    displayCustomers();
    int id ;
    cout<<"Enter the ID of the customer to be Modified : ";
    cin>>id;
    bool flag=false;
    int count = 0;
    for(vector<Customer>::iterator itr= custVector.begin(); itr!= custVector.end(); itr++,count++){
        if(itr->getID() == id){
            flag= true;
            break;
        }
    }
    if(flag){
        char name[30],address[30],pass[30];
        long int phone;
        TimeStamp dob;
        float bal;
        cout<<"Enter the Customer Name :"<<endl;
        cin.ignore();
        cin.getline(name , 30);
        cout<<"Enter Address : "<<endl;
        cin.getline(address,30);
        cout<<"Enter Phone number : "<<endl;
        cin>>phone;
        cout<<"Enter Date of Birth (DD MM YYYY) [SEPARATED BY SPACES] ";
        int dd, mm ,yy ;
        cin>>dd>>mm>>yy;
        dob.set(dd,mm,yy);
        cout<<endl<<"Enter Password"<<endl;
        cin.ignore();
        cin.getline(pass,30);
        cout<<"Enter Bank Balance"<<endl;
        cin>>bal;
        Customer cust(id, name, address, phone, dob, pass, bal);
        custVector.at(count) = cust;
        //Writing cust vector to the customer.txt
        fstream fout("customer.txt", ios::binary | ios::out | ios::app);
        for(int i = 0 ; i<custVector.size(); i++){
            fout.write((char*)&custVector.at(i),sizeof(Customer));
        }
        fout.close();
    }else {
        cout<<"The Customer ID specified doest no exist in the database."<<endl;
    }
}

void Controller::displayCustomers(){
    Support support;
    vector<Customer> custVector;
    Customer cust;
    fstream fin("customer.txt",ios::binary| ios::in);
    while(fin.read((char*)&cust , sizeof(Customer))){
        custVector.push_back(cust);
    }
    fin.close();
    support.drawLine(100);
    cout<<"ID\tNAME\tADDRESS\tPHONE\t\tDOB\tPASSWORD\tBALANCE"<<endl;
    support.drawLine(100);
    for(vector<Customer>::iterator itr= custVector.begin() ; itr!=custVector.end() ; itr++){
        cout<<itr->getID()<<"\t"<<itr->getName()<<"\t"<<itr->getAddress()<<"\t"<<itr->getPhone()<<"\t"<<(itr->getDob()).toString()<<"\t"<<itr->getPass()<<"\t"<<itr->getBalance()<<endl;
    }
    support.drawLine(100);
    cout<<endl;
}

void Controller::deleteCustomer(){
    Support support;
    vector<Customer> custVector;
    Customer cust;
    fstream fin("customer.txt",ios::binary|ios::in);
    while(fin.read((char*)&cust, sizeof(Customer))){
        custVector.push_back(cust);
    }
    fin.close();
    int id ;
    cout<<"Enter ID of customer to delete";
    cin>>id;
    for(int i = 0;i<custVector.size(); i++){
        if(custVector[i].getID() == id){
            custVector.erase(custVector.begin()+i);
        }
    }
    //truncating the cust vector to customer.txt
    fstream fout("customer.txt",ios::binary|ios::in | ios::trunc);
    for(int i = 0; i<custVector.size(); i++){
        fout.write((char*)&custVector[i],sizeof(Customer));
    }
    fout.close();
}

void Controller::displayCustomersBy(){
    Support support;
    vector<Customer>custVector;
    Customer cust;
    fstream fin("customer.txt",ios::binary | ios::in);
    while(fin.read((char*)&cust, sizeof(Customer))){
        custVector.push_back(cust);
    }
    fin.close();
    support.drawLine(100);
    int ch;
    cout<<"1. Sort by ID"<<endl;
    cout<<"2. Sort by Name"<<endl;
    cout<<"3. Sort by Date of Birth"<<endl;
    cout<<"4. Sort by Balance"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
        sort(custVector.begin(), custVector.end(), sortCustomerById);
        break;
        case 2:
        sort(custVector.begin(), custVector.end(), sortCustomerByName);
        break;
        case 3:
        sort(custVector.begin(), custVector.end(), sortCustomerByDob);
        break;
        case 4:
        sort(custVector.begin(), custVector.end(), sortCustomerByBalance);
        break;
        default:
        cout<<"Invalid Choice entered. Try again...";
    }
    cout<<"ID\tNAME\tADDRESS\tPHONE\t\tDOB\tPASSWORD\tBALANCE"<<endl;
    for(vector<Customer>::iterator itr= custVector.begin(); itr!=custVector.end() ; itr++){
        cout<<itr->getID()<<"\t"<<itr->getName()<<"\t"<<itr->getAddress()<<"\t"
        <<itr->getPhone()<<"\t"<<(itr->getDob()).toString()<<"\t"<<itr->getPass()<<
        "\t"<<itr->getBalance()<<endl;
    }
    support.drawLine(100);
    cout<<endl;

}

void Controller:: addEmployee(){
    vector<Employee> empVector;
    Employee employee;
    fstream fin("employee.txt",ios::binary | ios::in);
    while(fin.read((char*)&employee, sizeof(Employee))){
        empVector.push_back(employee);
    }
    fin.close();
    int id; 
    cout<<"Enter Employee ID : ";
    cin>> id;
    bool flag = true;
    for(vector<Employee>::iterator itr = empVector.begin(); itr!= empVector.end() ; itr++){
        if(itr->getID() == id){
            flag = false;
            break;
        }
    }

    if(flag){
        char name[30],address[30],pass[30];
        long int phone;
        TimeStamp dob;
        float salary;
        cout<<"Enter Employee Name: "<<endl;
        cin.ignore();
        cin.getline(name,30);
        cout<<"Enter address "<<endl;
        cin.getline(address,30);
        cout<<"Enter phone "<<endl;
        cin>>phone;
        cout<<"Enter Date of Birth (DD MM YYYY) [SEPARATED BY SPACES] ";
        int dd,mm,yy;
        cin>>dd>>mm>>yy;
        dob.set(dd,mm,yy);
        cout<<"Enter Password ";
        cin.ignore();
        cin.getline(pass,30);
        cout<<"Enter Salary ";
        cin>>salary;
        Employee emp(id,name,address,phone,dob,pass,salary);
        fstream fout("employee.txt",ios::binary | ios::out|ios::app);
        fout.write((char*)&emp,sizeof(Employee));
        fout.close();
    }else {
        cout<< "Employee ID already in use, try another ID."<<endl;
    }
}

void Controller::modifyEmployee(){
    Support support ; 
    vector<Employee> empVector;
    Employee emp;
    fstream fin("employee.txt",ios::binary | ios::in );
    while(fin.read((char*)&emp, sizeof(Employee))){
       empVector.push_back(emp);
    }
    displayEmployees();
    int id;
    cout<<"Enter Id of Employee to Modify : ";
    cin>> id;
    bool flag = true;
    int count = 0;
    for(vector<Employee>::iterator itr = empVector.begin(); itr!=empVector.end(); itr++ , count++){
        if(itr->getID()==id){
            flag =false;
            break;
        }
    }

    if(flag){
        char name[30],address[30],pass[30];
        long int phone;
        TimeStamp dob;
        float salary;
        cout<<"Enter Employee Name: "<<endl;
        cin.ignore();
        cin.getline(name,30);
        cout<<"Enter address "<<endl;
        cin.getline(address,30);
        cout<<"Enter phone "<<endl;
        cin>>phone;
        cout<<"Enter Date of Birth (DD MM YYYY) [SEPARATED BY SPACES] ";
        int dd,mm,yy;
        cin>>dd>>mm>>yy;
        dob.set(dd,mm,yy);
        cout<<"Enter Password ";
        cin.ignore();
        cin.getline(pass,30);
        cout<<"Enter Salary ";
        cin>>salary;
        Employee emp(id,name,address,phone,dob,pass,salary);
        fstream fout("employee.txt",ios::binary|ios::out|ios::app);
        fout.write((char*)&emp,sizeof(Employee));
        fout.close();
    } else {
        cout<<"Employee ID specified does not exist in data base, try again.";
    }
}

void Controller::displayEmployees(){
    Support support; 
    vector<Employee> empVector;
    Employee emp;
    fstream fin("employee.txt",ios::binary | ios::in);
    while(fin.read((char*)&emp,sizeof(Employee)))
    {
        empVector.push_back(emp);
    }
    fin.close();
    support.drawLine(100);
    cout<<"ID\tNAME\tADDRESS\tPHONE\t\tDOB\tPASSWORD\tSALARY"<<endl;
    for(vector<Employee>::iterator itr=empVector.begin(); itr!=empVector.end() ; ++itr)
    {
        cout<<itr->getID()<<"\t"<<itr->getName()<<"\t"<<itr->getAddress()<<"\t"<<itr->getPhone()<<"\t"<<(itr->getDob()).toString()<<"\t"<<itr->getPass()<<"\t"<<itr->getSalary()<<endl;
    }
    support.drawLine(100);
    cout<<endl;
}

void Controller::deleteEmployee(){
    Support support;
    vector<Employee> empVector;
    Employee emp;
    fstream fin("employee.txt", ios::binary | ios::in);
    while(fin.read((char*)&emp, sizeof(Employee))){
        empVector.push_back(emp);
    }
    fin.close();
    int id;
    cout<<"Enter the Id of the Employee to be deleted";
    cin>>id;
    for(int i = 0 ; i < empVector.size() ; i++){
        if(empVector[i].getID()== id){
            empVector.erase(empVector.begin()+i);
        }
    }
    //truncating the cust vector to employee.txt
    fstream fout("employee.txt",ios::binary | ios::out | ios::trunc);
    for(int i = 0; i < empVector.size() ; i++){
        fout.write((char*)&empVector,sizeof(Employee));
    }
    fout.close();
}

void Controller::deposit(){
    Support support;
    vector<Customer>custVector;
    Customer cust;
    fstream fin("customer.txt",ios::binary | ios::in);
    while(fin.read((char*)&cust, sizeof(Customer))){
        custVector.push_back(cust);
    }
    fin.close();
    support.drawLine(100);
    cout<<"\e[3mDeposit Window\e[0m"<<endl;
    support.drawLine(100);
    int id;
    float money;
    cout<<"Enter the Id of the Customer"<<endl;
    cin>>id;
    cout<<"Enter the Amount to Deposit";
    cin>>money;
    bool SUCCESS = false;
    for(vector<Customer>::iterator itr=custVector.begin();itr!=custVector.end();++itr)
    {
        if(itr->getID()==id)
        {
            itr->deposit(money);
            SUCCESS=true;
            break;
        }
    }
    //WRITING CUST VECTOR TO THE CUSTOMER.TXT
    fstream fout("customer.txt",ios::binary|ios::out|ios::trunc);
    for(int i=0;i<custVector.size();i++)
    {
        fout.write((char*)&custVector.at(i),sizeof(Customer));
    }
    fout.close();
    if(SUCCESS)
    cout<<"Successfully deposited Rs."<<money<<endl;
    else
    cout<<"Transaction could not be completed. Please contact the nearest Branch."<<endl;
}

void Controller::withdraw(){
    Support support;
    vector<Customer> custVector;
    Customer cust;
    fstream fin("customer.txt", ios::binary | ios::in);
    while(fin.read((char*)&cust, sizeof(Customer))){
        custVector.push_back(cust);
    }
    fin.close();
    support.drawLine(100);
    cout<<"\e[3mWithdraw Window\e[0m";
    int id;
    float money;
    cout<<"Enter the ID that you want the money to be withdrawn from ";
    cin>>id;
    cout<<"Enter the amount to withdraw ";
    cin>>money;
    bool SUCCESS=false;
    for(vector<Customer>::iterator itr=custVector.begin();itr!=custVector.end();++itr)
    {
        if(itr->getID()==id)
        {
            itr->withdraw(money);
            SUCCESS=true;
            break;
        }
    }
    //WRITING CUSTVECTOR TO THE CUSTOMER.TXT
    fstream fout("customer.txt",ios::binary|ios::out|ios::trunc);
    for(int i=0;i<custVector.size();i++)
    {
        fout.write((char*)&custVector.at(i),sizeof(Customer));
    }
    fout.close();
    if(SUCCESS)
    cout<<"Successfully withdrawn Rs."<<money<<::endl;
    else
    cout<<"Transaction could not be completed. Please contact the nearest Branch."<<endl;
}



//SORTING ALGORITHMS
bool Controller::sortCustomerByName(const Customer& c1,const Customer& c2)
{
    if(strcmp(c1.getName(),c2.getName())<0)
    return true;
    else return false;
}
bool Controller::sortCustomerByDob(const Customer& c1,const Customer& c2)
{
    if(c1.getDob()<c2.getDob())
    return true;
    else return false;
}
bool Controller::sortCustomerById(const Customer& c1,const Customer& c2)
{
    if(c1.getID()<c2.getID())
    return true;
    else return false;
}
bool Controller::sortCustomerByBalance(const Customer& c1,const Customer& c2)
{
    if(c1.getBalance()<c2.getBalance())
    return true;
    else return false;
}
// Sorting End
