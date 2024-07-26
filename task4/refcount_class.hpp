#include <iostream>
#include <cstring>


template <typename T>
class RefCounted {

private:
    T* data_;
    int* ref_counter;

public:
    //default constructor 
    RefCounted(T* data): data_(data), ref_counter(new int(1)) {
    }

//copy constructor
  RefCounted(RefCounted const& s) {
    data_ = new char[strlen(s.data_) + 1]; //Allocate memory for the data and copy the string 
    strcpy(data_, s.data_);  
    ref_counter = s.ref_counter;  // Share the reference counter with the source objec
    *ref_counter = (*ref_counter)+1; // Increment the reference count
  }

  RefCounted& operator=(RefCounted const& s){
    if (this != &s) {
        delete[] data_;  // Deallocate the current data 
        data_ = new char[strlen(s.data_) + 1]; //Allocate memory for the data and copy the string 
        strcpy(data_, s.data_);  
    }    
    return *this;
  }

  ~RefCounted(){
    (*ref_counter)--;  // Decrement the reference count
    if (*ref_counter ==0){
    delete[]data_;  // Deallocate the data if there are no more references 
    }
    
  }
  
 // Getter for individual characters
  char getChar(const int& i)const{
    return data_[i];
  }

   // Setter for individual characters
  void setChar(const int& i, const char& c) {
    data_[i] = c;
  }

 // Print the data and reference count
  void print() const{
    std::cout << data_<< " " << * ref_counter << std::endl;
  }
};