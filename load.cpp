#include "load.h"
#include "shipping_item.h"
#include "flat.h"
#include "tube.h"
#include <iostream>
#include <fstream>
#include <string>

int Load::get_count() const
{
    return count_packages_;
}
double Load::get_total_volume() const
{
    return total_volume_;
}
double Load::get_total_weight() const
{
    return total_weight_;
}
Load::Load()
{
    current_package_ = 0;
    count_packages_ = 0;
    total_weight_ = 0;
    total_volume_ = 0;

}
void Load::FillLoad(std::string filename)
{
    std::string type;
    
    std::ifstream in(filename);
     while(!in.eof())
    {
        getline(in, type);
        Address location;
        Flat* current;
        Carton* c1;
        Load* l1;
        Tube* tube;
        switch (type[0])
        {
        case 'F':
            double weight;
            double length; 
            double height; 
            double thickness;
            getline(in, location.name);
            getline(in, location.street_address);
            getline(in, location.city);
            getline(in, location.state);
            getline(in, location.zip);
            
            in >> weight;
            in >> length;
            in >> height;
            in >> thickness;
            in.ignore();
            current = new Flat(location, weight, length, height, thickness);
            ship_vec.push_back(current);
            count_packages_++;
            total_weight_ += weight;
            total_volume_ += length * height * thickness;
            break;
        case 'T':
        //Address location; 
        // double weight;
        // double length; 
        double circumference;
        getline(in, location.name);
        getline(in, location.street_address);
        getline(in, location.city);
        getline(in, location.state);
        getline(in, location.zip);
        in.ignore();

        in >> weight;
        in >> length;
        in >> circumference;
        in.ignore();
        tube = new Tube(location, length,weight,circumference);
        break;
        
        case 'C':
        int current_package_;
        int count_packages_;
        double total_weight_;
        double total_volume_;
        getline(in, location.name);
        getline(in, location.street_address);
        getline(in, location.city);
        getline(in, location.state);
        getline(in, location.zip);
        in.ignore();
        in >> current_package_;
        in >> count_packages_;
        in >> total_weight_;
        in >> total_volume_;
        c1 = new Carton(location, current_package_,count_packages_,total_weight_,total_volume_);
        


        //break;
        // default:
        //     break;
        }
    }


}

void Load::DisplayNextDelivery(std::ofstream &out) const
{
    for(int i = 0; i < ship_vec.size(); i++)
    {
        ship_vec[i]->Display(out);
    }
}
void Load::ItemDelivered()
{
    ///Load* current = new Load(current_package_, count_packages_, total_weight_, total_volume_);
    for(int i = 0; i < ship_vec.size(); i++)
    {
    current_package_ = true;
    ship_vec[i]->get_delivered();
    current_package_++;
    // ship_vec[i]->get_delivered()
    // ship_vec[i]->MarkDelivered();
    // ship_vec[i].push_back(current_package_);
    //ship_vec[i]->Display(current_package_);
    }
}
void Load::NotDeliverable()
{
    current_package_++;

}
int Load::HowManyDelivered() const
{
    double count = 0;
    for (ShippingItem* single_item : ship_vec)
    {
        if(single_item->get_delivered())
        {
            count++;
            
        }
}
    return count;
}
int Load::HowManyNotDelivered() const
{
    double count = 0;
    for (ShippingItem* single_item : ship_vec)
    {
        if(!single_item->get_delivered())
        {
            count++;
            
        }
}
    return count;

}
Load::~Load(){}