#include "refcount_class.hpp"

int main() {
    char* initialData = new char[12];  // Allocate memory for the initial data
    strcpy(initialData, "Hello world");

    RefCounted<char> s(initialData);
    s.print();

    {
        RefCounted<char> t(s);
        s.print();
        t.print();
        std::cout << t.getChar(1) << std::endl;
        s.print();
        t.print();
    }

    s.setChar(1, 'E');
    s.print();

    return 0;
}
