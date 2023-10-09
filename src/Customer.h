#ifndef CUSTOMER
#define CUSTOMER

#include <string>

class Customer {
    protected:
        std::string firstName;
        std::string lastName;
        std::string guestID;
        double amtSpent;
    public:
        Customer();
        Customer(std::string first, std::string last, std::string id, double amt) : firstName(first), lastName(last), guestID(id), amtSpent(amt) {}
        virtual ~Customer() {}
        std::string getFirstName() {return firstName;}
        std::string getLastName() {return lastName;}
        std::string getGuestID() {return guestID;}
        double getAmtSpent() {return amtSpent;}
        void setFirstName(std::string first) {firstName=first;}
        void setLastName(std::string last) {lastName=last;}
        void setGuestID(std::string id) {guestID=id;} 
        void setAmtSpent(double amt) {amtSpent=amt;}
        virtual double getDiscountPercent() {return 0.00;};
        virtual void setDiscountPercent() {};
        virtual int getBonusBucks() {return 0;};
        virtual void setBonusBucks() {};
};

#endif