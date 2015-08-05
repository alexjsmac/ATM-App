#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "user.h"

using namespace std;

/*---------- User Class -------------------------------*/

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

/*----------------- Customer Class -----------------------------*/

Customer::Customer(int custID, string custName, int accSetup){
    userID = custID;
    userName = custName;
    userType = 0;
    
    //Create customer account with specified selection of bank accounts
    if (accSetup == 1) {
        ChequingAccount checkAccount(custID);
        bankAccounts[0] = checkAccount;
    }
    else if (accSetup == 2) {
        SavingsAccount saveAccount(custID);
        bankAccounts[1] = saveAccount;
    }
    else if (accSetup == 3) {
        ChequingAccount checkAccount(custID);
        SavingsAccount saveAccount(custID);
        bankAccounts[0] = checkAccount;
        bankAccounts[1] = saveAccount;
    }
}

bool Customer::hasChequing(){
    bool result = false;
    if (bankAccounts[0].getOwnerID() == userID) {
        result = true;
    }
    return result;
}

bool Customer::hasSavings(){
    bool result = false;
    if (bankAccounts[1].getOwnerID() == userID) {
        result = true;
    }
    return result;
}

double Customer::getBalance(int accountType){
    return bankAccounts[accountType].getBalance();
}

void Customer::setBalance(int accountType, double newBalance){
    bankAccounts[accountType].setBalance(newBalance);
}

void Customer::closeAccount(int accountType){
    if (accountType == 0){
        if (hasChequing()){
            if (getBalance(0) == 0) {
                bankAccounts[0] = 0;
                cout<<"\nAccount closed successfully!\n";
            }
            else{
                cout<<"\nERROR: Cannot close an account with a non-zero balance\n";
            }
        }
        else{
            cout<<"\nERROR: Account does not exist\n";
        }
    }
    else if (accountType == 1){
        if (hasSavings()) {
            if (getBalance(0) == 0) {
                bankAccounts[1] = 0;
                cout<<"\nAccount closed successfully!\n";
            }
            else{
                cout<<"\nERROR: Cannot close an account with a non-zero balance\n";
            }
        }
        else{
            cout<<"\nERROR: Account does not exist\n";
        }
    }
}

void Customer::openAccount(int accountType){
    if (accountType == 0) {
        if (!hasChequing()) {
            ChequingAccount account(userID);
            bankAccounts[0] = account;
            cout<<"\nAccount opened successfully!\n";
        }
        else{
            cout<<"\nERROR: Account already exists\n";
        }
    }
    else if (accountType == 1){
        if (!hasSavings()) {
            SavingsAccount account(userID);
            bankAccounts[1] = account;
            cout<<"\nAccount opened successfully!\n";
        }
        else{
            cout<<"\nERROR: Account already exists\n";
        }
    }
}

/*------------------ Manager Class ---------------------*/

Manager::Manager(int manID, string manName){
    userID = manID;
    userName = manName;
    cout<<customers.size()<<endl;
}

void Manager::createUser(int uID, string userName, int accSetup){
    Customer newCust(uID, userName, accSetup);
    customers.push_back(newCust);
    cout<<"\nCustomer account opened successfully!\n";
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
    cout<<"\nUsername: " << foundCust.getUserName() << "\nID Number: " << foundCust.getID();
    if (foundCust.hasChequing()){
        cout<<"\nChequing Account Balance: $"<<foundCust.getBalance(0);
    }
    if (foundCust.hasSavings()){
        cout<<"\nSavings Account Balance: $"<<foundCust.getBalance(1);
    }
    cout<<endl;
}

// Display all user accounts
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
