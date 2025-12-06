#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

class user {
private:
    int* userID;
    char* email;

protected: 
    char* name;

public:
    user(const int* userNo, const char*userName, const char* userEmail);
    
    const int* getuserID() const;   
    const char* getname() const;
    const char* getemail() const;

    virtual void displayInfo() const = 0;
    virtual ~user();

};


#endif 