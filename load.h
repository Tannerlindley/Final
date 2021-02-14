#ifndef LOAD_H
#define LOAD_H
#include "shipping_item.h"
#include <vector>


class Load
{
    private:
    std::vector<ShippingItem*> ship_vec; 
    int current_package_;
    int count_packages_;
    double total_weight_;
    double total_volume_;

    public:

Load();
~Load();
//getters
int get_count() const;
double get_total_volume() const;
double get_total_weight() const;

//other methods    
void FillLoad(std::string filename);
void DisplayNextDelivery(std::ofstream &out) const;
void ItemDelivered();
void NotDeliverable();
int HowManyDelivered() const;
int HowManyNotDelivered() const;

};
#endif
