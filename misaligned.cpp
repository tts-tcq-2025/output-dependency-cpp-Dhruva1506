#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};


int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n"; 
        }
    }
    return i * j;
}


std::string getColorPair(int i, int j) {
    std::ostringstream oss;
    oss << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[j]; 
    return oss.str();
}


void testColorMappingLogic() {
    std::cout << "\nColor mapping logic test\n";

  
    assert(getColorPair(0, 0) == "0 | White | Blue");
    assert(getColorPair(0, 1) == "1 | White | Orange");
    assert(getColorPair(1, 0) == "5 | Red | Blue");
    assert(getColorPair(4, 4) == "24 | Violet | Slate");

    

    std::cout << "All logic tests passed (should fail if getColorPair is wrong)\n";
}


void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
}
