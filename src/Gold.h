#ifndef GOLD
#define GOLD

class Gold : public Customer {
    protected:
        double discountPercent;
    public:
        Gold();
        Gold(std::string first, std::string last, std::string id, double amt, double discount) : Customer(first, last, id, amt), discountPercent(discount) {}
        double getDiscountPercent() {return discountPercent;}
        void setDiscountPercent(double discount) {discountPercent=discount;} 
};

#endif