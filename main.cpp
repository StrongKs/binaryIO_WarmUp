#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Open file in binary input mode
    std::fstream file("tips.shp", std::ios_base::binary | std::ios_base::in);
    int sentence_count = 0;
    file.read(reinterpret_cast<char*>(&sentence_count), sizeof(int));
    //cout << sentence_count << endl;



    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    unsigned int num_strings;
    // TODO: Read number of strings
    // Hint: file.read((char *)&num_strings, sizeof(num_strings));

    vector<string> sentences;
    for (int i = 0; i < sentence_count; i++) {
        int string_length = 0;
        file.read(reinterpret_cast<char*>(&string_length), sizeof(int));

        string sentence;

        for (int j = 0; j < string_length; j++) {
            char curr_char;
            file.read(reinterpret_cast<char*>(&curr_char), sizeof(char));
            sentence.push_back(curr_char);
        }
        sentences.push_back(sentence);
    }
    // TODO: Add loop to:
    // 1. Read string length
    // 2. Read string characters
    // 3. Print string

    file.close();
    for (int i = 0; i < sentence_count; i++) {
        cout << sentences[i] << endl;
    }
    return 0;

}
