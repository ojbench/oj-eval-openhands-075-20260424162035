
#include "str.hpp"
#include <iostream>

int main() {
    // Test basic functionality
    str s1;
    str s2('A');
    str s3("Hello");
    
    std::cout << "s1 length: " << s1.len() << std::endl;
    std::cout << "s2 length: " << s2.len() << ", s2[0]: " << s2[0] << std::endl;
    std::cout << "s3 length: " << s3.len() << ", s3[0]: " << s3[0] << std::endl;
    
    // Test assignment
    s1 = "World";
    std::cout << "After assignment, s1 length: " << s1.len() << std::endl;
    
    // Test copy constructor
    str s4 = s3;
    std::cout << "s4 length: " << s4.len() << std::endl;
    
    // Test slice
    str s5 = s3.slice(1, 3);
    std::cout << "s3.slice(1,3) length: " << s5.len() << std::endl;
    
    // Test join
    std::vector<str> strs;
    strs.push_back(str("1"));
    strs.push_back(str("2"));
    strs.push_back(str("3"));
    str separator(", ");
    str joined = separator.join(strs);
    std::cout << "Joined length: " << joined.len() << std::endl;
    
    return 0;
}
