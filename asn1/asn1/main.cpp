//
//  main.cpp
//  asn1
//
//  Created by ernie k on 2014-09-10.
//  Copyright (c) 2014 uwo. All rights reserved.
//

#include <iostream> 
#include <string>

using namespace std;

class Account
{
protected:
    double balance;
    bool type;
public:
    double getBalance()
    {
        return balance;
    }
    bool getType()
    {
        return type;
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount()
    {
        balance = 0;
        type = 0;
    }
};

class SavingsAccount : public Account
{
public:
    SavingsAccount()
    {
        balance = 0;
        type = 1;
    }
};

class User
{
protected:
    int userID;
    string userName;
    int userType;
public:
    int getID()
    {
        return userID;
    }
    string getUserName()
    {
        return userName;
    }
    int getUserType()
    {
        return userType;
    }
    
};

class Customer: public User
{
    CheckingAccount checkingsAcc;
    SavingsAccount savingsAcc;
public:
    Customer(int uID, string uName)
    {
        userID = uID;
        userName = uName;
        userType = 0;
    }
    double chAccBalance()
    {
        return checkingsAcc.getBalance();
    }
    double saAccBalance()
    {
        return savingsAcc.getBalance();
    }
};

class Manager: public User
{
public:
    Manager (int, string);
    int getType()
    {
        return 1;
    }
    void createUser(int uID, string userName)
    {
        Customer newCust (uID, userName);
    }
    string dispAccount(int uID)
    {
        Customer foundCust = findCust(int uID);
        cout<<"Username: ";
    }
};

Manager::Manager(int manID, string manName)
{
    userID = manID;
    userName = manName;
    userType = 1;
}

class Maintenance: public User
{
public:
    Maintenance (int, string);
    void maintenanceMode()
    {
        
    }
};

Maintenance::Maintenance(int mainID, string mainName)
{
    userID = mainID;
    userName = mainName;
    userType = 2;
}

int main()
{
    //create manager object
    Manager man (123456, "Manager");
    
    //create maintanence object
    Maintenance main (234567, "Maintenance");
    
    cout<<"\nHello, please enter login ID\n\n";
    int loginID;
    cin>>loginID;
    
    //Or should we use strings?
    if(loginID==man.getID())
    {
        while(1)
        {
            int choice;
            
            system("clear");
            cout<<"\nWhat would you like to do?\n";
            cout<<"1)   Open a user account\n";
            cout<<"2)   Close a user account\n";
            cout<<"3)   View details of a customer account\n";
            cout<<"4)   View details of all customers\n";
            cout<<"5)   Exit\n";
            cin>>choice;
            
            switch(choice)
            {
                case 1 :
                {
                    cout<<"Please create a new ID number:";
                    int userID;
                    cin>>userID;
                    cout<<"Please enter the user's name:";
                    string userName;
                    cin>>userName;
                    man.createUser(userID, userName);
                    cin.get();
                    break;
                }/*
                case 2 :
                {
                    cout<<"Please enter user's ID number:";
                    cin>>userID;
                    man.close_user(userID);
                    cin.get();
                    break;
                }*/
                case 3 :
                {
                    cout<<"Please enter a user ID number:";
                    cin>>userID;
                    man.dispAccount(userID);
                    cin.get();
                    break;
                }/*
                case 4 : man.display_all_accounts();
                    cin.get();
                    break;*/
                case 5 :
                {
                    goto end;
                }
                //default: cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
            }
        }
    }
    
    //else if(/*ID entered matches an existing ID number*/)
    /*{
        userAccount = man.getUser(loginID);
        checkAccount = userAccount.getChecking();
        saveAccount = userAccount.getSavings();
        {
            while(1)
            {
                cout<<"\nWhat would you like to do?\n";
                cout<<"1)   Deposit\n";
                cout<<"2)   Withdraw\n";
                cout<<"3)   Display Balance\n";
                cout<<"4)   Display with full Details\n";
                cout<<"5)   Exit\n";
                cout<<"6)   Choose Your choice:-";
                int choice;
                cin>>choice;
                switch(choice)
                {
                    case 1 : cout<<"From which account?";
                        cout<<"1) Checking Account";
                        cout<<"2) Savings Account";
                        cin.get();
                        break;
                    case 2 : c1.withdraw_currbal();
                        cin.get();
                        break;
                    case 3 : c1.disp_currbal();
                        cin.get();
                        break;
                    case 4 : c1.display_accinfo();
                        c1.disp_currbal();
                        cin.get();
                        break;
                    case 5 : goto end;
                    default: cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
                }
            }
        }*/
    end:
        return 0;
    
};