#include <iostream> 
#include <string>
#include <fstream> //Used for execution trace
#include <ctime> //Used for timestamp in execution trace

#include "account.h"
#include "user.h"

using namespace std;

void traceExecution(string function, int userID){ //Function for printing to execution trace file
    ofstream executionTrace;
    executionTrace.open("trace.txt", std::fstream::app); //Open and append to trace.txt
    
    time_t timeNow;
    struct tm * timeinfo;
    time (&timeNow);
    timeinfo = localtime (&timeNow); //Get the current date and time for timestamp
    
    executionTrace <<function<<" | "<<userID<<" | "<<asctime (timeinfo); //Write to executionTrace file the function, userID, and timestamp
    executionTrace.flush();
    executionTrace.close();

}

int main(){
    Manager man(123456, "Manager"); //Create manager object
    Maintenance main(234567, "Maintenance"); //Create maintenance object
    
    bool tracer(0); //Execution trace toggle, set to off by default
    
start:
    system("clear");
    cout<<"Hello, please enter login ID:\n";
    int loginID;
    cin>>loginID; //Storing login ID in int variable
    
    if(loginID==man.getID()){ //If the ID matches the manager's ID, we provide managerial features
        while(1){
            int choice;
            
            //system("clear");
            cout<<"\nWhat would you like to do?\n"; //Manegrial options
            cout<<"1)   Open a user account\n";
            cout<<"2)   Close a user account\n";
            cout<<"3)   View details of a customer account\n";
            cout<<"4)   View details of all customers\n";
            cout<<"5)   Logout\n";
            cout<<"6)   Exit\n";
            cin>>choice;
            
            switch(choice){
                case 1:{ //Opening a new user account
                uniqueID:
                    cout<<"\nPlease create a new unique ID number: ";
                    int userID;
                    cin>>userID; //Storing unique ID
                    
                    if (man.custExists(userID)){ //Check to see if ID is unique
                        cout<<"ID number already exists\n";
                        goto uniqueID; //If it already exists, print out a message and loop
                    }
                    cout<<"Enter the user's name: "; //If ID is unique, continue new user account
                    string userName;
                    cin>>userName; //Storing username
                    
                    if(tracer) //If tracer is enabled, call it with custExists string, and current login ID
                        traceExecution("custExists", loginID);
                    
                    man.createUser(userID, userName); //Calling createUser with stored userID and userName
                    break; //Break from switch case to prevent cascading
                }
                case 2:{
                removeUser: //Removing a user account
                    if (man.custList().size() == 0){ //If the customer list is 0, there's no customer to remove
                        cout<<"\nNo customer accounts to remove!\n";
                        break;
                    }
                    else{ //If there is an object in the customer list
                        cout<<"\nPlease enter user's ID number:\n"; //Asking for customer to remove
                        int userID;
                        cin>>userID;
                        if (!man.custExists(userID)){ //Checking if the ID exists
                            cout<<"User does not exist\n";
                            goto removeUser; //If it does not exist, print out a message and loop
                        }
                        
                        if(tracer) //If tracer is enabled, call it with deleteUser string, and current login ID
                            traceExecution("deletUser", loginID);
                        
                        man.deleteUser(userID); //Deleting user
                        break;
                    }
                }
                case 3:{
                displayAccount: //Display a specific account
                    if (man.custList().size() == 0){ //If the customer list is 0, there are no customers to display
                        cout<<"\nNo customer accounts to display!\n";
                        break;
                    }
                    else{ //If there is an object in the customer list
                        cout<<"\nPlease enter user's ID number:\n"; //Asking for customer to display
                        int userID;
                        cin>>userID;
                        if (!man.custExists(userID)){ //Checking if the ID exists
                            cout<<"User does not exist\n";
                            goto displayAccount; //If it does not exist, print out a message and loop
                        }
                        
                        if(tracer)  //If tracer is enabled, call it with dispAccount string, and current login ID
                            traceExecution("dispAccount", loginID);
                        
                        man.dispAccount(userID); //Display user account
                    }
                    break;
                }
                case 4 :{ //Display all accounts
                    if (man.custList().size() == 0){ //If the customer list is 0, there are no customers to display
                        cout<<"\nNo customer accounts to display!\n";
                        break;
                    }
                    else{
                        
                        if(tracer)  //If tracer is enabled, call it with disAllAccounts string, and current login ID
                            traceExecution("dispAllAccounts", loginID);
                        
                        man.dispAllAccounts(); //Display all accounts
                    }
                    break;
                }
                case 5:{ //Logging out
                    goto start; //Go to the beginning
                }
                case 6:{ //Exit
                    goto end; //Return 0
                }
                default:{
                    cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\""; //Invalid entry, continues through while loop
                }
            }
        }
    }
    
    else if(loginID==main.getID()){ //If the ID matches the maintenance ID, we provide the ability to turn the tracer on or off
        if(tracer==0) //If the tracer is turned off
            cout<<"1)   Turn on execution trace\n"; //Option to turn on
        else
            cout<<"2)   Turn off execution trace\n"; //Option to turn off
        int choice;
        cin>>choice; //Storing choice in an int
        
        switch (choice){ //Switch case
            case 1:{ //Turning on execution trace
                traceExecution("Execution trace on", loginID); //Call execution trace function to print timestamp to file
                tracer=1; //Set tracer boolean to 1 for on
                break;
            }
            case 2:{ //Turning off execution trace
                traceExecution("Execution trace off", loginID); //Call execution trace function to print timestamp to file
                tracer=0; //Set tracer boolean to 0 for off
                break;
            }
            
            default:{
                cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"\n";
            }
        }
        goto start;
    }
    
    else if(man.custExists(loginID)){ //If the ID does not match manager's/mainenence's then we check if it is an existing customer
        Customer userAccount = man.findCust(loginID); //If the customer exists, we load the customer object
        
            while(1){
            cust: //Customer option menu
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
                    deposit: //Customer chooses to deposit money
                        
                        cout<<"\nTo which account?\n"; //Asking which account to deposit from
                        cout<<"1)   Checking Account\n";
                        cout<<"2)   Savings Account\n";
                        cout<<"3)   Go back\n";
                        int accountType;
                        cin>>accountType;
                        
                        Account* account = nullptr;
                        if (accountType == 1) {
                            if (userAccount.hasChequing()){
                                list<Account>::iterator it;
                                for (it = userAccount.getAccounts().begin(); it != userAccount.getAccounts().end(); ++it){
                                    if (it->getType() == 0) {
                                        account = &*it;
                                        goto dep;
                                    }
                                }
                            }
                            else{
                                cout<<"Account does not exist!\n";
                                goto deposit;
                            }
                        }
                        else if (accountType == 2) {
                            if (userAccount.hasSavings()){
                                list<Account>::iterator it;
                                for (it = userAccount.getAccounts().begin(); it != userAccount.getAccounts().end(); ++it){
                                    if (it->getType() == 1) {
                                        account = &*it;
                                        goto dep;
                                    }
                                }
                            }
                            else{
                                cout<<"Account does not exist!\n";
                                goto deposit;
                            }
                        }
                        
                        switch(accountType){
                        dep:
                            case 1:{ //Deposit into checking account
                                cout<<"\nHow much would you like to deposit?\n";
                                int amount;
                                cin>>amount;
                                double newBalance = account->getBalance() + amount; //Calculating new account balance
                                
                                if(tracer) //If tracer is enabled, call it with setCHeckBalance string, and current login ID
                                    traceExecution("setCheckBalance", loginID);
                                
                                account->setBalance(newBalance); //Setting new account balance
                                cout<<"New chequing account balance is: $"<<account->getBalance()<<endl; //Displaying new account balance
                                break;
                            }
                            case 2:{ //Deposit into savings account
                                cout<<"\nHow much would you like to deposit?\n";
                                int amount;
                                cin>>amount;
                                double newBalance = account->getBalance() + amount; //Calculating new account balance
                                
                                if(tracer) //If tracer is enabled, call it with setSavingsBalance string, and current login ID
                                    traceExecution("setSavingsBalance", loginID);
                                
                                account->setBalance(newBalance); //Setting new account balance
                                cout<<"New savings account balance is: $"<<account->getBalance()<<endl; //Displaying new acount balance
                                break;
                            }
                            case 3:{ //Go back a menu
                                goto cust;
                            }
                            default:{
                                cout<<"Invalid choice\n";
                                goto deposit; //Go back two menus
                            }
                        }
                        break;
                    }
                        
                    case 2:{
                    withdraw: //Customer chooses to withdraw money
                        
                        cout<<"\nFrom which account?\n"; //Asking which account to widthraw from
                        cout<<"1)   Checking Account\n";
                        cout<<"2)   Savings Account\n";
                        cout<<"3)   Go back\n";
                        int accountType;
                        cin>>accountType;
                        
                        Account* account = nullptr;
                        if (accountType == 1) {
                            if (userAccount.hasChequing()){
                                list<Account>::iterator it;
                                for (it = userAccount.getAccounts().begin(); it != userAccount.getAccounts().end(); ++it){
                                    if (it->getType() == 0) {
                                        account = &*it;
                                        goto with;
                                    }
                                }
                            }
                            else{
                                cout<<"Account does not exist!\n";
                                goto withdraw;
                            }
                        }
                        else if (accountType == 2) {
                            if (userAccount.hasSavings()){
                                list<Account>::iterator it;
                                for (it = userAccount.getAccounts().begin(); it != userAccount.getAccounts().end(); ++it){
                                    if (it->getType() == 1) {
                                        account = &*it;
                                        goto with;
                                    }
                                }
                            }
                            else{
                                cout<<"Account does not exist!\n";
                                goto withdraw;
                            }
                        }
                        
                        switch(accountType){
                        with:
                            case 1:{ //Withdraw from Checking account
                                cout<<"\nHow much would you like to withdraw?\n";
                                int amount;
                                cin>>amount;
                                
                                if(tracer) //If tracer is enabled, call it with setCheckBalance string, and current login ID
                                    traceExecution("setCheckBalance", loginID);
                                
                                double newBalance = account->getBalance() - amount; //Calculating new account balance
                                if (newBalance < 0) { //If there is a negative balance in the checking account
                                    
                                    if(tracer) //If tracer is enabled, call it with insufficientFunds string, and current login ID
                                        traceExecution("insufficientFunds", loginID);
                                    
                                    cout<<"WARNING: Insufficient funds, withdrawal not possible\n"; //Print a warning stating insufficient funds, balance does not change
                                }
                                else if (newBalance < 1000){ //If the new balance is below 1000
                                    
                                    if(tracer) //If tracer is enabled, call it with lawBalanceWarning string, and current login ID
                                        traceExecution("lowBalanceWarning", loginID);
                                    
                                    cout<<"WARNING: Balance will drop below $1000 and each following transaction will incur a  $2 fee.\n Do you wish to continue?\n 1) Yes\n"; //Print low balance warning
                                    int decision;
                                    cin>>decision;
                                    if (decision == 1){ //Customer may decide to continue or abort
                                        
                                        if(tracer) //If tracer is enabled, call it with setCheckBalanceAfterWarning string, and current login ID
                                            traceExecution("setCheckBalanceAfterWarning", loginID);
                                        
                                        account->setBalance(newBalance - 2); //Set new balance and charge a $2 fee
                                    }
                                }
                                else //If there is enough money to withdraw, and the balance remains above 1000
                                    account->setBalance(newBalance); //Setting new balance
                                
                                cout<<"Chequing account balance is/remains: $"<<account->getBalance()<<endl; //Displaying new balance
                                break;
                            }
                            case 2:{ //Withdraw from savings account
                                cout<<"\nHow much would you like to withdraw?\n";
                                int amount;
                                cin>>amount;
                                
                                if(tracer) //If tracer is enabled, call it with savingsWithrawal string, and current login ID
                                    traceExecution("savingsWithdrawal", loginID);
                                
                                double newBalance = account->getBalance() - amount; //Calculating new account balance
                                
                                if(newBalance < 0){ //If there is a negative balance in the saving account
                                    
                                    if(tracer) //If tracer is enabled, call it with insufficientFunds string, and current login ID
                                        traceExecution("insufficientFunds", loginID);
                                    
                                    cout<<"WARNING: Insufficient funds, withdrawal not possible\n"; //Print a warning stating insufficient funds, balance does not change
                                }
                                else
                                    account->setBalance(newBalance); //Setting new account balance
                                
                                cout<<"New balance is/remains: $"<<newBalance<<endl; //Displaying new account balance
                                break;
                            }
                            case 3:{ //Go back a menu
                                goto cust;
                            }
                            default:{
                                cout<<"Invalid choice\n";
                                goto withdraw; //Go back two menus
                            }
                        }
                        break;
                    }
                    case 3:{
                    transfer: //Customer chooses to transfer money
                     
                        if (!userAccount.hasChequing() || !userAccount.hasSavings()) {
                            cout<<"Chequing Account and Savings Account required to do a transfer\n";
                            goto cust;
                        }
                        
                        cout<<"\nWhich transfer would you like to do?\n"; //Asking what type of transfer the customer would like
                        cout<<"1)   Checking Account to Savings Account\n";
                        cout<<"2)   Savings Account to Chequing Assount\n";
                        cout<<"3)   Go back\n";
                        int account;
                        cin>>account;
                        
                        list<Account>::iterator it;
                        Account *checkAccount = nullptr;
                        for (it = userAccount.getAccounts().begin(); it != userAccount.getAccounts().end(); ++it){
                            if (it->getType() == 0) {
                                checkAccount = &*it;
                            }
                        }
      
                        Account *saveAccount = nullptr;
                        for (it = userAccount.getAccounts().begin(); it != userAccount.getAccounts().end(); ++it){
                            if (it->getType() == 1) {
                                saveAccount = &*it;
                            }
                        }
                        switch(account){
                            case 1:{ //Transfer from checking to savings account
                                cout<<"\nHow much would you like to transfer?\n";
                                int amount;
                                cin>>amount;
                                
                                double newBalance1 = saveAccount->getBalance() + amount; //Calculating new saving account balance
                                double newBalance2 = checkAccount->getBalance() - amount; //Calculating new checking account balance
                                if (newBalance2 < 0) { //If there is a negative balance in the checking account
                                    
                                    if(tracer) //If tracer is enabled, call it with inssuficientFunds string, and current login ID
                                        traceExecution("insufficientFunds", loginID);
                                    
                                    cout<<"WARNING: Insufficient funds, transfer not possible\n"; //Print a warning stating insufficient funds, balance does not change
                                }
                                else if (newBalance2 < 1000){ //If the new checking balance is below 1000
                                    
                                    if(tracer) //If tracer is enabled, call it with lowBalanceWarning string, and current login ID
                                        traceExecution("lowBalanceWarning", loginID);
                                    
                                    cout<<"WARNING: Balance will drop below $1000 and each following transaction will incur a  $2 fee.\n Do you wish to continue?\n 1) Yes\n"; //Print low balance warning
                                    int decision;
                                    cin>>decision;
                                    if (decision == 1){ //Customer may decide to continue or abort
                                        
                                        if(tracer) //If tracer is enabled, call it with setCheckBalanceAfterWarning string, and current login ID
                                            traceExecution("setCheckBalanceAfterWarning", loginID);
                                        
                                        checkAccount->setBalance(newBalance2 - 2); //Set new balance with a $2 fee
                                    }
                                }
                                else{
                                    
                                    if(tracer) //If tracer is enabled, call it with transferCheckToSave string, and current login ID
                                        traceExecution("transferCheckToSave", loginID);
                                    
                                    saveAccount->setBalance(newBalance1); //
                                    checkAccount->setBalance(newBalance2);
                                }
                                cout<<"Savings account is/remains: $"<<saveAccount->getBalance()<<endl;
                                cout<<"Chequing account is/remains: $"<<checkAccount->getBalance()<<endl;
                                break;
                            }
                            case 2:{
                                cout<<"\nHow much would you like to transfer?\n";
                                int amount;
                                cin>>amount;
                                
                                double newBalance1 = checkAccount->getBalance() + amount;
                                double newBalance2 = saveAccount->getBalance() - amount;
                                if (newBalance2 < 0) {
                                    
                                    if(tracer)
                                        traceExecution("insufficientFunds", loginID);

                                    
                                    cout<<"WARNING: Insufficient funds, transfer not possible\n";
                                }
                                else{
                                    
                                    if(tracer)
                                        traceExecution("transferSaveToCheck", loginID);
                                    
                                    checkAccount->setBalance(newBalance1);
                                    saveAccount->setBalance(newBalance2);
                                }
                                cout<<"Savings account is/remains: $"<<saveAccount->getBalance()<<endl;
                                cout<<"Chequing account is/remains: $"<<checkAccount->getBalance()<<endl;
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
                        int accountType;
                        cin>>accountType;
                        
                        Account* account = nullptr;
                        if (accountType == 1) {
                            if (userAccount.hasChequing()){
                                list<Account>::iterator it;
                                for (it = userAccount.getAccounts().begin(); it != userAccount.getAccounts().end(); ++it){
                                    if (it->getType() == 0) {
                                        account = &*it;
                                        goto disp;
                                    }
                                }
                            }
                            else{
                                cout<<"Account does not exist!\n";
                                goto deposit;
                            }
                        }
                        else if (accountType == 2) {
                            if (userAccount.hasSavings()){
                                list<Account>::iterator it;
                                for (it = userAccount.getAccounts().begin(); it != userAccount.getAccounts().end(); ++it){
                                    if (it->getType() == 1) {
                                        account = &*it;
                                        goto disp;
                                    }
                                }
                            }
                            else{
                                cout<<"Account does not exist!\n";
                                goto deposit;
                            }
                        }
                        
                        switch(accountType){
                        disp:
                            case 1:{
                                
                                if(tracer)
                                    traceExecution("displayChecking", loginID);
                                
                                cout<<"\nCurrent balance is: $"<<account->getBalance()<<endl;
                                break;
                            }
                            case 2:{
                                
                                if(tracer)
                                    traceExecution("displaySavings", loginID);
                                
                                cout<<"\nCurrent balance is: $"<<account->getBalance()<<endl;
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