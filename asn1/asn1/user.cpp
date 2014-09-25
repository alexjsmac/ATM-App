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
        ChequingAccount checkAccount(custID);
        bankAccounts[0] = checkAccount;
    }
    else if (accSetup == 2) {
        SavingsAccount saveAccount(custID);
        bankAccounts[1] = saveAccount;
    }
    else if (accSetup == 3) {
        //cout<<"Go here?\n";
        ChequingAccount checkAccount(custID);
        SavingsAccount saveAccount(custID);
        bankAccounts[0] = checkAccount;
        bankAccounts[1] = saveAccount;
    }
    //cout<<"account balances: "<<bankAccounts[0].getBalance()<<" "<<bankAccounts[1].getBalance()<<endl;
}

bool Customer::hasChequing(){
    bool result = false;
    if (bankAccounts[0].getType() == 0) {
        result = true;
    }
    return result;
}

bool Customer::hasSavings(){
    bool result = false;
    if (bankAccounts[1].getType() == 1) {
        result = true;
    }
    return result;
}

Account *Customer::getAccount(int accountType){
    Account account = bankAccounts[accountType];
    Account *result = &account;
    return result;
}

double Customer::getBalance(int accountType){
    return bankAccounts[accountType].getBalance();
}
void Customer::setBalance(int accountType, double newBalance){
    bankAccounts[accountType].setBalance(newBalance);
}

Manager::Manager(int manID, string manName){
    userID = manID;
    userName = manName;
    userType = 1;
    cout<<customers.size()<<endl;
}

int Manager::getType(){
    return 1;
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
        Account *checkAccount = foundCust.getAccount(0);
        cout<<"\nChequing Account Balance: $"<<checkAccount->getBalance();
    }
    if (foundCust.hasSavings()){
        Account *saveAccount = foundCust.getAccount(1);
        cout<<"\nSavings Account Balance: $"<<saveAccount->getBalance();
    }
    cout<<endl;
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
