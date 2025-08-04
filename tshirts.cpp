#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testTshirtSize() {
    std::cout << "\nTshirt size test\n";

    // Original tests
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');

    // New tests to expose boundary bugs:
    // These should FAIL with the current buggy implementation
    assert(size(38) != '\0'); // 38 should be classified, currently returns '\0'
    assert(size(42) != '\0'); // 42 should be classified, currently returns '\0'

    // More specific expected classifications:
    assert(size(38) == 'M'); // expected size for 38 cm
    assert(size(42) == 'M'); // expected size for 42 cm

    std::cout << "All tests passed (this should not print if bugs exist)\n";
}

