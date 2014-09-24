#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "user.h"

using namespace std;

User::User(int userID, string userName){ //Constructor
    this->userID = userID;
    this->userName = userName;
}

int User::getID(){
    return userID;
}

string User::getUserName(){
    return userName;
}

int User::getUserType(){
    return userType;
}


Customer::Customer(int custID, string custName, int accSetup){
    userID = custID;
    userName = custName;
    userType = 0;
    if (accSetup == 1) {
        ChequingAccount checkAccount;
        accounts.push_back(checkAccount);
    }
    else if (accSetup == 2) {
        SavingsAccount saveAccount;
        accounts.push_back(saveAccount);
    }
    else if (accSetup == 3) {
        ChequingAccount checkAccount;
        SavingsAccount saveAccount;
        accounts.push_back(checkAccount);
        accounts.push_back(saveAccount);
    }
    cout<<"account list size: "<<accounts.size()<<endl;
}

list<Account> Customer::getAccounts(){
    return accounts;
}

bool Customer::hasChequing(){
    bool result = 0;
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); ++it){
        if (it->getType() == 0) {
            result = 1;
        }
    }
    return result;
}

bool Customer::hasSavings(){
    bool result = 0;
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); ++it){
        if (it->getType() == 1) {
            result = 1;
        }
    }
    return result;
}

Account Customer::getAccount(int accountType){
    Account account;
    if (accountType == 0) {
        if (hasChequing()) {
            list<Account>::iterator it;
            for (it = accounts.begin(); it != accounts.end(); ++it){
                if (it->getType() == 0) {
                    account = *it;
                }
            }
        }
    }
    else if (accountType == 1) {
        if (hasSavings()) {
            list<Account>::iterator it;
            for (it = accounts.begin(); it != accounts.end(); ++it){
                if (it->getType() == 1) {
                    account = *it;
                }
            }
        }
    }
    return account;
}

/*ChequingAccount Customer::getChequing(){
    ChequingAccount check;
    list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); ++it){
        if (it->getType() == 0) {
            check = *it;
        }
    }
    return checkingsAcc;
}*/

//SavingsAccount Customer::getSavings(){
 //   return savingsAcc;
//}

Manager::Manager(int manID, string manName){
    userID = manID;
    userName = manName;
    userType = 1;
    //customers.reserve(1);
    cout<<customers.size()<<endl;
}

int Manager::getType(){
    return 1;
}

void Manager::createUser(int uID, string userName){
    cout<<"\nWhat does the customer require?\n";
    cout<<"1)   Chequing Account\n";
    cout<<"2)   Savings Account\n";
    cout<<"3)   Chequing and Savings Accounts";
    int accSetup;
    cin>>accSetup;
    Customer newCust(uID, userName, accSetup);
    customers.push_back(newCust);
    cout<<"Customer account opened successfully!"<<endl;
}

void Manager::deleteUser(int custID){
    vector<Customer>::iterator it;
    for (it=customers.begin(); it!=customers.end(); ++it){
        if (customers.size() > 0){
            if (it->getID() == custID){
                customers.erase(it);
                cout<<"Customer with ID number \""<<custID<<"\" deleted successfully!\n";
            }
        }
        else break;
    }
}

Customer Manager::findCust(int loginID){
    vector<Customer>::iterator it;
    for (it=customers.begin(); it!=customers.end(); ++it){
        if (it->getID() == loginID){
            return *it;
        }
    }
    return *it;
}

bool Manager::custExists(int loginID){
    bool found = false;
    for (int i=0; i<customers.size(); i++){
        if (customers[i].getID() == loginID){
            found = true;
        }
    }
    return found;
}

void Manager::dispAccount(int uID){
    Customer foundCust = findCust(uID);
    list<Account>::iterator it;
    cout<<"\nUsername: " << foundCust.getUserName() << "\nID Number: " << foundCust.getID()<<endl;
    for (it = foundCust.getAccounts().begin(); it != foundCust.getAccounts().end(); ++it){
        if (it->getType() == 0) {
            cout<<"\nChequing Account Balance: $"<<it->getBalance()<<endl;
        }
        else{
            cout<<"\nSavings Account Balance: $"<<it->getBalance()<<endl;
        }
    }
    
}

void Manager::dispAllAccounts(){
    vector<Customer>::iterator it;
    for (it=customers.begin(); it!=customers.end(); ++it){
        dispAccount(it->getID());
    }
}

vector<Customer> Manager::custList(){
    return customers;
}

Maintenance::Maintenance(int mainID, string mainName){
    userID = mainID;
    userName = mainName;
    userType = 2;
}
