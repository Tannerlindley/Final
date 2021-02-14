#include <iostream>
#include <fstream>
#include "carton.h"
#include "shipping_item.h"
#include "flat.h"
#include "tube.h"
#include "load.h"
using namespace std;

int main() { 


  cout << "Part 2.2: Use the Carton Class in Main.cpp\n";

  // Create a Carton object using the new constructor.
  // When using this constructor, use try/catch blocks to handle
  // the exceptions

  Address address;
  //address.name = "c1";
  Carton c1;
  Carton* c2 = new Carton(address, 7.4, 12, 6.8, 3.2);
  
  // Use the Carton object to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  // When calling the setters, use try/catch blocks to handle the exceptions.
  cout << "default constructor using getters:" << endl;

  cout << "Address: " << c1.get_address().name << endl;
  cout << "Address: " << c1.get_address().street_address << endl;
  cout << "Weight: " << c1.get_weight() << endl;
  cout << "Length: " << c1.get_length() << endl;
  cout <<  "Width: " << c1.get_width() << endl;
  cout <<  "Height: " << c1.get_height() << endl;
  
    
  try
  {
    cout << "Using setters with default constructor" << endl;
    c1.set_address(address);
    cout << c1.get_address().street_address << endl;
    c1.set_length(70);
    cout << "Length: " << c1.get_length() << endl;
    c1.set_weight(50);
    cout << "Weight: " << c1.get_weight() << endl;
    c1.set_width(1.2);
    cout << "Width: " << c1.get_width() << endl;

    c1.set_measurements(16.4, 6.7, 3.4);
    cout << "------------------" << endl;

    cout << "getters with non default" << endl;
    cout << "Address: " << c2->get_address().name << endl;
    cout << "Weight: " << c2->get_weight() << endl;
    cout << "Length: " << c2->get_length() << endl;
    cout <<  "Width: " << c2->get_width() << endl;
    cout <<  "Height: " << c2->get_height() << endl;

    cout << "----------------" << endl;
    cout << endl;
    cout << "setters with non default" << endl;
    

    c2->set_address(address);
    cout << c2->get_address().street_address << endl;
    c2->set_length(88);
    cout << "Length: " << c2->get_length() << endl;
    c2->set_weight(25);
    cout << "Weight: " << c2->get_weight() << endl;
    c2->set_width(13.1);
    cout << "Width: " << c2->get_width() << endl;
    cout << "-----------------------" << endl;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  
  // Use the Carton object to call the Display method to print to cout.
  cout << "displaying carton info" << endl;
  c1.Display(cout);
  c2->Display(cout);


 cout << "\nPart 3.3: Use the Flat Class in Main.cpp\n";

  // Create Flat objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.
  //Address address;
   Flat f1;
   Flat* f2 = new Flat(address, 8.1, 5, 6, .01);
  
  // Use the Flat objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.
  std::cout << "Testing getters with default" << std::endl;
  try
  {
      cout << "Address name: " << f1.get_address().name <<   endl;
      cout << "Weight: " << f1.get_weight() << " " << endl;
      cout << "Length: " << f1.get_length() << " " << " " ;
      cout << "Height: " << f1.get_height() << endl;
      cout << "Thickness: " << f1.get_thickness() << endl;
      cout << "------------------" << endl;
      
      
      cout << "getters for non default" << endl;
      cout << "Address name: " << f2->get_address().name <<   endl;
      cout << "Weight: " << f2->get_weight() << " " << endl;
      cout << "Length: " << f2->get_length() << " " << endl;
      cout << "Height: " << f2->get_height() << endl;
      cout << "Thickness: " << f2->get_thickness() << endl;
      cout << endl;
      cout << "using setters on non default" << endl;
      f2->set_address(address);
      cout << "Address: " << f2->get_address().street_address << endl;
      f2->set_weight(5.2);
      cout << "Weight: " << f2->get_weight() << endl;
      f2->set_length(7.0);
      cout << "Length: " << f2->get_length() << endl;
      f2->set_height(3.0);
      cout << "Height: " << f2->get_height() << endl;
      f2->set_thickness(.35); 
      cout << "Thickness: " << f2->get_thickness() << endl;
      cout << "------------------------" << endl; 

  
  // Use the Flat objects to call the Volume and Display methods.
  // Print out the results to cout.
  cout << "default volumes and display" << endl;
  cout << f1.Volume() << endl;
  f1.Display(cout);
  cout << endl;
  cout << " non default volumes and display" << endl;
  cout << f2->Volume() << endl;
  f2->Display(cout);

}

  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  cout << "\nPart 4.3: Use the Tube Class in Main.cpp";

  // 1. Create Tube objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.
   Tube t1;
   Tube* t2 = new Tube(address, 8.1, 5.2, 6.9);
 

  // Use the Tube objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.
  
  try{
    cout << "Testing getters with default" << std::endl;
    cout << "Address name: " << t1.get_address().name <<  endl;
    cout << "Address name: " << t1.get_address().street_address <<  endl;
    cout << "Circumference: " << t1.get_circumference() << endl;
    cout << "Delivered:  " << t1.get_delivered() << endl;
    cout << "Length: " << t1.get_length() << endl;
    cout << "Weight: " << t1.get_weight() << endl;
    cout << "--------------------------" << endl;
    cout << endl;
  
    cout << "Testing setters with non default" << endl;

    t2->set_circumference(5);
    cout << "Circumference: " << t2->get_circumference() << endl;
    t2->set_delivered(true);
    cout << "Delivered:  " << t2->get_delivered() << endl;
    t2->set_length(12);
    cout << "Length: " << t2->get_length() << endl;
    t2->set_weight(3.3);
    cout << "Weight: " << t2->get_weight() << endl;
  cout << "--------------------------" << endl;
  }

catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }


  // Use the Tube objects to call the Volume, Girth and Display methods.
  // Print out the results to cout.
  cout << "test volume, girth, and display methods with both default and non default" << endl;
cout << "Volume method: " << t1.Volume() << endl;
cout << "Girth method: " << t1.Girth() << endl;
cout << "Display method: ";
t1.Display(cout);
cout << "-------------------" << endl;
cout << "Volume method: " << t2->Volume() << endl;
cout << "Girth method: " << t2->Girth() << endl;
cout << "Display method: ";
t2->Display(cout);

  cout << "\nPart 5.3: Use the Load Class in Main.cpp";

  // // 1. Create a Load object.
  Load l1;


  // // 2. Use the Load object to call the getter methods.
  // // Print out the results to see how these getters are working.
  // // Do this right after the Load object is created and after it
  // // is filled from the file.
  l1.FillLoad("../../load_1.txt");
  cout << l1.get_count() << endl;
  cout << l1.get_total_volume()  << endl;
  cout << l1.get_total_weight() << endl;



  // //3. Use the Load object to call the FillLoad method.
  // // Then call the DisplayNextDelivery, ItemDelivered, NotDeliverable,
  // // HowManyDelivered, and HowManyNotDelivered methods multiple times
  // // to see how these work when making deliveries.
  l1.FillLoad("../../my_outTest.txt");

  ofstream out("../../my_outTest.txt");
  l1.DisplayNextDelivery(out);
  l1.ItemDelivered();
  l1.NotDeliverable();
  l1.HowManyDelivered();
  l1.HowManyNotDelivered();
  

  return 0;
  }

 
 



