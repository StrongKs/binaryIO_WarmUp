#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // Open file in binary input mode
    std::fstream file("tips.shp", std::ios_base::binary | std::ios_base::in);

    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    unsigned int num_strings;
    // TODO: Read number of strings
    file.read((char *)&num_strings, sizeof(num_strings));
    cout << num_strings;

    // TODO: Add loop to:
    // 1. Read string length
    // 2. Read string characters
    // 3. Print string

    for (unsigned int i = 0; i < num_strings; i++) {
        unsigned int str_len;
        // Read length of string (including null terminator)
        file.read((char *)&str_len, sizeof(str_len));
        // Create buffer and read string
        char* buffer = new char[str_len];
        file.read(buffer, str_len);
        // Print string (stop at null terminator)
        std::cout << "String " << (i + 1) << " (length " << (str_len - 1)
                  << "): " << buffer << std::endl;
    }
    file.close();
    return 0;
}
