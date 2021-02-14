#include "flat.h"
#include "shipping_item.h"
#include <iomanip>

    
    void Flat::set_length(double length)
    {
        if(length < kMinSize || length > 15)
        {
            throw std::out_of_range("out of range");
        //std::__throw_out_of_range("out of range");
        }
        length_ = length;
    }
    void Flat::set_height(double height)
    {
        height_ = height;
        if(height < kMinSize || height > 12)
        {
            throw std::out_of_range("out of range");
            //std::__throw_out_of_range("out of range");
        }
    }
    void Flat::set_thickness(double thickness)
    {
        thickness_ = thickness;
        if(thickness < kMinSize || thickness > 0.75)
        {
            throw std::out_of_range("out of range");
            
        }
    }
      Flat::Flat() : ShippingItem()
    {  
        set_height(8);
        set_thickness(.4);
    }
    Flat::Flat(Address address, double weight, double length, double height, double thickness) : ShippingItem(address, weight, length)
    {
        set_length(length);
        set_height(height);
        set_thickness(thickness);
     
    }
    Flat::~Flat(){}

    double Flat::Volume() const
    {
        double volume = length_ * height_ * thickness_;
        return volume;
      
    }
    void Flat::Display(std::ostream &out) const
    {
        out << "Flat: " << std::fixed << std::setprecision(1) << weight_ << " lbs. " << length_ << " x " << height_ << " x " << thickness_ << std::endl;
    }

    double Flat::get_height() const
    {
        return height_;

    }
    double Flat::get_thickness() const
    {
        return thickness_;
    }





    
