#ifndef FLAT_H
#define FLAT_H
#include "shipping_item.h"
#include "carton.h"

class Flat : public ShippingItem
{
    private: 
    double height_;
    double thickness_;

    public:
        Flat();
        Flat(Address address, double weight, double length, double height, double thickness);
         ~Flat();
         double get_height() const;
         double get_thickness() const;
         void set_length(double length);
         void set_height(double height);
         void set_thickness(double thickness);   
         virtual double Volume() const;
         virtual void Display(std::ostream &out) const;
   
    


};


#endif