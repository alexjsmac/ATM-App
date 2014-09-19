#include <iostream> 
#include <string>
#include "account.h"
#include "user.h"

using namespace std;

int main(){
    //create manager object
    Manager man(123456, "Manager");
    
    //create maintenance object
    Maintenance main(234567, "Maintenance");
    
start:
    cout<<"\nHello, please enter login ID\n\n";
    int loginID;
    cin>>loginID;
    
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
                    cout<<"Enter the user's name:";
                    string userName;
                    cin>>userName;
                    man.createUser(userID, userName);
                    break;
                }
                case 2 :
                {
                    cout<<"Please enter user's ID number:";
                    int userID;
                    cin>>userID;
                    man.deleteUser(userID);
                    break;
                }
                case 3 :
                {
                    cout<<"Please enter a user ID number:";
                    int userID;
                    cin>>userID;
                    cout<<man.dispAccount(userID)<<endl;
                    break;
                }/*
                case 4 : man.display_all_accounts();
                    break;*/
                case 5 :
                {
                    goto end;
                }
                default: cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
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
    else{
        cout<<"Invalid ID, try again"<<endl;
        goto start;
    }
    
    end:
        return 0;
    
};
