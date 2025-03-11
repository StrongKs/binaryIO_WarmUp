#include <fstream>
#include <iostream>
#include <string>

int main() {
    // Open file in binary input mode
    std::fstream file("tips.shp", std::ios_base::binary | std::ios_base::in);

    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    // Read number of strings
    unsigned int num_strings;
    file.read((char *)&num_strings, sizeof(num_strings));
    std::cout << "Number of strings: " << num_strings << std::endl;

    // Process each string
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

        // Clean up
        delete[] buffer;
    }

    file.close();
    return 0;
}
