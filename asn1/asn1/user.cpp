#include <string>
#include "user.h"

class User{
    int userID;
    std::string userName;
    int userType;

public:
    int getID(){
        return userID;
    }

    std::string getUserName(){
        return userName;
    }

    int getUserType(){
        return userType;
    }
};
