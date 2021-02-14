#include "shipping_item.h"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

    
    const double ShippingItem::kMaxWeight = 70;
    const double ShippingItem::kMaxSize = 108;
    const double ShippingItem::kMinSize = 0.007;
    // const double thickness;
    // const double ShippingItem;


    Address ShippingItem::get_address() const
    {
        return address_;
    }
    double ShippingItem::get_weight() const
    {
        return weight_;
    }   
    double ShippingItem::get_length() const
    {
        return length_;
    }
    bool ShippingItem::get_delivered() const
    {
        return delivered_;
    }

    //setters
    void ShippingItem::set_address(Address address)
    {   
        address_ = address;
    }
    void ShippingItem::set_weight(double weight)
    {
        
        if(weight < 0 || weight > kMaxWeight)
        {
        throw std::out_of_range("Out of range");
        }
        weight_ = weight;
    }
    void ShippingItem::set_length(double length)
    {
        if(length < kMinSize || length > kMaxSize)
        {
            throw out_of_range("Out of range");
        }
          length_ = length;  
           
    }      
    void ShippingItem::set_delivered(bool delivered)
    {
        delivered_ = delivered;
    }
    ShippingItem::ShippingItem()
    {   address_.name = "unknown";
        set_weight(2);
         set_length(12);
         set_delivered(false);
    }
    void ShippingItem::MarkDelivered()
    {
        delivered_ = true;
    } 
    ShippingItem::~ShippingItem(){}
    
    ShippingItem::ShippingItem(Address address, double weight, double length)
    {
        address_ = address;
        set_weight(weight);
        set_length(length);
        set_delivered(false);
    }
    void Display(std::ostream &out) {}

    