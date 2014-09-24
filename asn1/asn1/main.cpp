#include <iostream> 
#include <string>
#include <fstream>
#include <ctime>

#include "account.h"
#include "user.h"

using namespace std;

void traceExecution(string function, int userID){
    ofstream executionTrace;
    executionTrace.open("trace.txt", std::fstream::app);
    
    time_t timeNow;
    struct tm * timeinfo;
    time (&timeNow);
    timeinfo = localtime (&timeNow);
    
    executionTrace <<function<<" | "<<userID<<" | "<<asctime (timeinfo);
    executionTrace.flush();
    executionTrace.close();

}

int main(){
    Manager man(123456, "Manager"); //Create manager object
    Maintenance main(234567, "Maintenance"); //Create maintenance object
    
    //Execution trace
    bool tracer(0); //Won't leave as global var, testing.
    
start:
    system("clear");
    cout<<"Hello, please enter login ID:\n";
    int loginID;
    cin>>loginID;
    
    if(loginID==man.getID()){
        while(1){
            int choice;
            
            //system("clear");
            cout<<"\nWhat would you like to do?\n";
            cout<<"1)   Open a user account\n";
            cout<<"2)   Close a user account\n";
            cout<<"3)   View details of a customer account\n";
            cout<<"4)   View details of all customers\n";
            cout<<"5)   Logout\n";
            cout<<"6)   Exit\n";
            cin>>choice;
            
            switch(choice){
                case 1:{
                uniqueID:
                    cout<<"\nPlease create a new unique ID number:\n";
                    int userID;
                    cin>>userID;
                    
                    if(tracer)
                        traceExecution("custExists", loginID);
                    
                    if (man.custExists(userID)){
                        cout<<"ID number already exists\n";
                        goto uniqueID;
                    }
                    cout<<"\nEnter the user's name:\n";
                    string userName;
                    cin>>userName;
                    man.createUser(userID, userName);
                    break;
                }
                case 2:{
                removeUser:
                    if (man.custList().size() == 0){
                        cout<<"\nNo customer accounts to remove!\n";
                        break;
                    }
                    else{
                        cout<<"\nPlease enter user's ID number:\n";
                        int userID;
                        cin>>userID;
                        if (!man.custExists(userID)){
                            cout<<"User does not exist\n";
                            goto removeUser;
                        }
                        
                        if(tracer)
                            traceExecution("deletUser", loginID);
                        
                        man.deleteUser(userID);
                        break;
                    }
                }
                case 3:{
                displayAccount:
                    if (man.custList().size() == 0){
                        cout<<"\nNo customer accounts to display!\n";
                        break;
                    }
                    else{
                        cout<<"\nPlease enter user's ID number:\n";
                        int userID;
                        cin>>userID;
                        if (!man.custExists(userID)){
                            cout<<"User does not exist\n";
                            goto displayAccount;
                        }
                        
                        if(tracer)
                            traceExecution("dispAccount", loginID);
                        
                        man.dispAccount(userID);
                    }
                    break;
                }
                case 4 :{
                    if (man.custList().size() == 0){
                        cout<<"\nNo customer accounts to display!\n";
                        break;
                    }
                    else{
                        
                        if(tracer)
                            traceExecution("dispAllAccounts", loginID);
                        
                        man.dispAllAccounts();
                    }
                    break;
                }
                case 5:{
                    goto start;
                }
                case 6:{
                    goto end;
                }
                default:{
                    cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
                }
            }
        }
    }
    
    else if(loginID==main.getID()){
        int choice;
        
        if(tracer==0)
            cout<<"1)   Turn on execution trace\n";
        else
            cout<<"2)   Turn off execution trace\n";
        cin>>choice;
        
        switch (choice) {
            case 1:{
                traceExecution("Execution trace on", loginID);
                tracer=1;
                break;
            }
            case 2:{
                tracer=0;
                break;
            }
            default:{
                cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
            }
        }
        goto start;
    }
    
    else if(man.custExists(loginID)){
        Customer userAccount = man.findCust(loginID);
        ChequingAccount checkAccount = userAccount.getChequing();
        SavingsAccount saveAccount = userAccount.getSavings();
            while(1){
            cust:
                //system("clear");
                cout<<"\nWhat would you like to do?\n";
                cout<<"1)   Deposit\n";
                cout<<"2)   Withdraw\n";
                cout<<"3)   Transfer\n";
                cout<<"4)   Display Balance\n";
                cout<<"5)   Open an account\n";
                cout<<"6)   Close an account\n";
                cout<<"7)   Logout\n";
                cout<<"8)   Exit\n";
                int choice;
                cin>>choice;
                
                switch(choice)
                {
                    case 1:{
                    deposit:
                        //system("clear");
                        cout<<"\nTo which account?\n";
                        cout<<"1)   Checking Account\n";
                        cout<<"2)   Savings Account\n";
                        cout<<"3)   Go back\n";
                        int account;
                        cin>>account;
                        switch(account){
                            case 1:{
                                cout<<"\nHow much would you like to deposit?\n";
                                int amount;
                                cin>>amount;
                                double newBalance = checkAccount.getBalance() + amount;
                                
                                if(tracer)
                                    traceExecution("setCheckBalance", loginID);
                                
                                checkAccount.setBalance(newBalance);
                                cout<<"New balance is: $"<<newBalance<<endl;
                                break;
                            }
                            case 2:{
                                cout<<"\nHow much would you like to deposit?\n";
                                int amount;
                                cin>>amount;
                                double newBalance = saveAccount.getBalance() + amount;
                                
                                if(tracer)
                                    traceExecution("setSavingsBalance", loginID);
                                
                                saveAccount.setBalance(newBalance);
                                cout<<"New balance is: $"<<newBalance<<endl;
                                break;
                            }
                            case 3:{
                                goto cust;
                            }
                            default:{
                                cout<<"Invalid choice\n";
                                goto deposit;
                            }
                        }
                        break;
                    }
                    case 2:{
                    withdraw:
                        //system("clear");
                        cout<<"\nFrom which account?\n";
                        cout<<"1)   Checking Account\n";
                        cout<<"2)   Savings Account\n";
                        cout<<"3)   Go back\n";
                        int account;
                        cin>>account;
                        switch(account){
                            case 1:{
                                cout<<"\nHow much would you like to withdraw?\n";
                                int amount;
                                cin>>amount;
                                
                                if(tracer)
                                    traceExecution("setCheckBalance", loginID);
                                
                                double newBalance = checkAccount.getBalance() - amount;
                                if (newBalance < 0) {
                                    
                                    if(tracer)
                                        traceExecution("insufficientFunds", loginID);
                                    
                                    cout<<"WARNING: Insufficient funds, withdrawal not possible\n";
                                }
                                else if (newBalance < 1000){
                                    
                                    if(tracer)
                                        traceExecution("lowBalanceWarning", loginID);
                                    
                                    cout<<"WARNING: Balance will drop below $1000 and each following transaction will incur a  $2 fee.\n Do you wish to continue?\n 1) Yes\n";
                                    int decision;
                                    cin>>decision;
                                    if (decision == 1){
                                        
                                        if(tracer)
                                            traceExecution("setCheckBalanceAfterWarning", loginID);
                                        
                                        checkAccount.setBalance(newBalance - 2);
                                    }
                                }
                                else
                                    checkAccount.setBalance(newBalance);
                                cout<<"Chequing account balance is/remains: $"<<checkAccount.getBalance()<<endl;
                                break;
                            }
                            case 2:{
                                cout<<"\nHow much would you like to withdraw?\n";
                                int amount;
                                cin>>amount;
                                
                                if(tracer)
                                    traceExecution("savingsWithdrawal", loginID);
                                
                                double newBalance = saveAccount.getBalance() - amount;
                                saveAccount.setBalance(newBalance);
                                cout<<"New balance is: $"<<newBalance<<endl;
                                break;
                            }
                            case 3:{
                                goto cust;
                            }
                            default:{
                                cout<<"Invalid choice\n";
                                goto withdraw;
                            }
                        }
                        break;
                    }
                    case 3:{
                    transfer:
                        //system("clear");
                        cout<<"\nWhich transfer would you like to do?\n";
                        cout<<"1)   Checking Account to Savings Account\n";
                        cout<<"2)   Savings Account to Chequing Assount\n";
                        cout<<"3)   Go back\n";
                        int account;
                        cin>>account;
                        switch(account){
                            case 1:{
                                cout<<"\nHow much would you like to transfer?\n";
                                int amount;
                                cin>>amount;
                                
                                double newBalance1 = saveAccount.getBalance() + amount;
                                double newBalance2 = checkAccount.getBalance() - amount;
                                if (newBalance2 < 0) {
                                    
                                    if(tracer)
                                        traceExecution("insufficientFunds", loginID);
                                    
                                    cout<<"WARNING: Insufficient funds, transfer not possible\n";
                                }
                                else if (newBalance2 < 1000){
                                    
                                    if(tracer)
                                        traceExecution("lowBalanceWarning", loginID);
                                    
                                    cout<<"WARNING: Balance will drop below $1000 and each following transaction will incur a  $2 fee.\n Do you wish to continue?\n 1) Yes\n";
                                    int decision;
                                    cin>>decision;
                                    if (decision == 1){
                                        
                                        if(tracer)
                                            traceExecution("setCheckBalanceAfterWarning", loginID);
                                        
                                        checkAccount.setBalance(newBalance2 - 2);
                                    }
                                }
                                else{
                                    
                                    if(tracer)
                                        traceExecution("transferCheckToSave", loginID);
                                    
                                    saveAccount.setBalance(newBalance1);
                                    checkAccount.setBalance(newBalance2);
                                }
                                cout<<"Savings account is/remains: $"<<saveAccount.getBalance()<<endl;
                                cout<<"Chequing account is/remains: $"<<checkAccount.getBalance()<<endl;
                                break;
                            }
                            case 2:{
                                cout<<"\nHow much would you like to transfer?\n";
                                int amount;
                                cin>>amount;
                                
                                double newBalance1 = checkAccount.getBalance() + amount;
                                double newBalance2 = saveAccount.getBalance() - amount;
                                if (newBalance2 < 0) {
                                    
                                    if(tracer)
                                        traceExecution("insufficientFunds", loginID);

                                    
                                    cout<<"WARNING: Insufficient funds, transfer not possible\n";
                                }
                                else{
                                    
                                    if(tracer)
                                        traceExecution("transferSaveToCheck", loginID);
                                    
                                    checkAccount.setBalance(newBalance1);
                                    saveAccount.setBalance(newBalance2);
                                }
                                cout<<"Savings account is/remains: $"<<saveAccount.getBalance()<<endl;
                                cout<<"Chequing account is/remains: $"<<checkAccount.getBalance()<<endl;
                                break;
                            }
                            case 3:{
                                goto cust;
                            }
                            default:{
                                cout<<"Invalid choice\n";
                                goto transfer;
                            }
                        }
                        break;
                    }
                    case 4:{
                    display:
                        //system("clear:");
                        cout<<"\nWhich account?\n";
                        cout<<"1)   Checking Account\n";
                        cout<<"2)   Savings Account\n";
                        cout<<"3)   Go back\n";
                        int account;
                        cin>>account;
                        switch(account){
                            case 1:{
                                
                                if(tracer)
                                    traceExecution("displayChecking", loginID);
                                
                                cout<<"\nCurrent balance is: $"<<checkAccount.getBalance()<<endl;
                                break;
                            }
                            case 2:{
                                
                                if(tracer)
                                    traceExecution("displaySavings", loginID);
                                
                                cout<<"\nCurrent balance is: $"<<saveAccount.getBalance()<<endl;
                                break;
                            }
                            case 3:{
                                goto cust;
                            }
                            default:{
                                cout<<"Invalid choice\n";
                                goto display;
                            }
                        }
                        break;
                    }
                    case 5:{
                        break;
                    }
                    case 6:{
                        break;
                    }
                    case 7:{
                        goto start;
                    }
                    case 8:{
                        goto end;
                    }
                    default:{
                        cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
                    }
                }
            }
        }
    
    else{
        cout<<"Invalid ID, try again\n";
        goto start;
    }
    
    end:
        return 0;
};