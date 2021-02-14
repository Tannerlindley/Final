#ifndef SHIPPING_ITEM_H
#define SHIPPING_ITEM_H
#include <string>

struct Address
{
    std::string name;
    std::string street_address;
    std::string city;
    std::string state;
    std::string zip;
};
class ShippingItem
{
    protected:
    Address address_;
    double weight_;
    double length_;
    bool delivered_;

    //add a public section with the following 
    //three static constants of type double
    public:
    static const double kMaxWeight;
    static const double kMaxSize;
    static const double kMinSize;

    //two constructors and a destructor
         ShippingItem();
         ShippingItem(Address address, double weight, double length);
         ~ShippingItem(); 
    //four getters
         Address get_address() const; 
         double get_weight() const; 
         double get_length() const; 
         bool get_delivered() const;
    //four setters
         void set_address(Address address);
         void set_weight(double weight);
         virtual void set_length(double length);
         void set_delivered(bool delivered); 
    //three other methods     
         void MarkDelivered();
          virtual double Volume() const = 0;
         virtual void Display(std::ostream &out) const = 0;
};
#endif
    
  
