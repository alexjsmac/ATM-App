//
//  main.cpp
//  asn1
//
//  Created by ernie k on 2014-09-10.
//  Copyright (c) 2014 uwo. All rights reserved.
//

#include <iostream> 

using namespace std;

class Account
{
public:
    virtual double getBalance() = 0;
    virtual bool getType() = 0;
protected:
    double balance;
    bool type;
};

class CheckingAccount: public Account
{
public:
    double getBalance()
    {
        return this->balance;
    }
    bool getType()
    {
        return 0;
    }
};

class SavingsAccount: public Account
{
public:
    double getBalance()
    {
        return this->balance;
    }
    bool getType()
    {
        return 1;
    }
};

class User
{
public:
    virtual int getID() = 0;
protected:
    int userID;
    char[20] userName;
};

class Customer: public User
{
    
};

class Manager: public User
{
    
};

class Maintenance: public User
{
    
};

int main()
{
    //create manager object
    
    cout<<"\nEnter login ID\n\n";
    int loginID;
    cin>>loginID;
    
    int manID = 214345454;
    
    //Or should we use strings?
    if(loginID==manID)
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
                case 1 : cout<<"Please create a new ID number:";
                    int userID;
                    cin>>userID;
                    man.create_user(userID);
                    cin.get();
                    break;
                case 2 : cout<<"Please enter user's ID number:";
                    cin>>userID;
                    man.close_user(userID);
                    cin.get();
                    break;
                case 3 : cout<<"Please enter a user ID number:";
                    cin>>userID;
                    man.disp_account(userID);
                    cin.get();
                    break;
                case 4 : man.display_all_accounts();
                    cin.get();
                    break;
                case 5 : goto end;
                default: cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
            }
        }
    }
    else if(/*ID entered matches an existing ID number*/)
    {
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
        }
    end:
        return 0;
    }
}

