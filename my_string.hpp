#include <iostream>
#include <cstring>

class my_string {

private:
        char* data; //pointer to the character data
        int* ref_counter;  // pointer to the reference counter
public:

  //default constructor  
  my_string() {
    data = nullptr;
    ref_counter = new int; 
    *ref_counter = 1;
  }

  // constructor with a C-string parameter
  my_string(const char*s) {
    data = new char [strlen(s) + 1]; //Allocate memory for the data and copy the string 
    strcpy(data, s);
    ref_counter = new int;  // Create a new reference counter and set it to 1
    *ref_counter =1; 
  }

  //copy constructor
  my_string(my_string const& s) {
    data = new char[strlen(s.data) + 1]; //Allocate memory for the data and copy the string 
    strcpy(data, s.data);  
    ref_counter = s.ref_counter;  // Share the reference counter with the source objec
    *ref_counter = *ref_counter+1; // Increment the reference count
  }

  my_string& operator= (my_string const& s){
    if (this != &s) {
        delete[] data;  // Deallocate the current data 
        data = new char[strlen(s.data) + 1]; //Allocate memory for the data and copy the string 
        strcpy(data, s.data);
    }  
    return *this;
  }

  ~my_string(){
    *ref_counter = *ref_counter-1;  // Decrement the reference count
    if (*ref_counter ==0){
      std::cout << "freeing the allocated memory as the reference count is "<< * ref_counter << std::endl; 
      delete[]data;  // Deallocate the data if there are no more references 
    }
  }
  
 // Getter for individual characters
  char getChar(const int& i) const{
    return data[i];
  }

 // Setter for individual characters
  void setChar(const int& i, const char& c) {
    data[i] = c;
  }

 // Print the data and reference count
  void print() const{
    std::cout << data <<"["<< *ref_counter <<"]" << std::endl;
  }

};