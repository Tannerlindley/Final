#include "tube.h"
#include <stdexcept>
#include <iomanip>

const double Tube::kPi = 3.14159;

Tube::Tube()
{
    set_circumference(12);
}
Tube::Tube(Address address, double weight, double length, double circumference) : ShippingItem(address, weight, length)
{
    set_circumference(circumference);
    set_length(length_);
        set_weight(weight_);
    if(circumference > kMinSize || circumference < kMaxSize || (length_ + circumference) < kMaxSize || weight > 70)
    {
        // set_circumference(circumference_);
        // set_length(length_);
        // set_weight(weight_);
       throw std::out_of_range("out of range");
    }
    throw std::out_of_range("out of range");
    
}
Tube::~Tube(){}
//getters
double Tube::get_circumference() const
{
    return circumference_;
}
//setters
void Tube::set_circumference(double circumference)
{
    circumference_ = circumference;
    if(circumference < kMinSize || circumference > kMaxSize || (length_ + circumference > kMaxSize))
    {
        throw std::out_of_range("out of range");
    }
}

//other methods
double Tube::Volume() const
{
    double radius;
    double pVol;
    radius = (get_circumference()/(2*kPi));
    //pVol = (kPi*radius * radius * get_length());
    pVol = ((radius * radius) * kPi) * get_length();
    return pVol;

}
double Tube::Girth() const
{
    return circumference_;
}
void Tube::Display(std::ostream &out) const
{
     out << "Tube: " << std::fixed << std::setprecision(1) << weight_ << " lbs. " << length_ << " x " 
        << circumference_ << std::endl;

} 