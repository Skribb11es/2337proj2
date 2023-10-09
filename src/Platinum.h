#ifndef PLATINUM
#define PLATINUM

class Platinum : public Customer {
    protected:
        int bonusBucks;
    public:
        Platinum(std::string first, std::string last, std::string id, double amt, int bonus) : Customer(first, last, id, amt), bonusBucks(bonus) {}
        int getBonusBucks() {return bonusBucks;}
        void setBonusBucks(int bonus) {bonusBucks=bonus;}
};

#endif