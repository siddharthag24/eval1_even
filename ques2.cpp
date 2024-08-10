#include <iostream>
#include <map>
#include <cctype>

int main() {
    std::map<char, int> freq;
    char ch;

    std::cout << "Enter a paragraph (end input with Ctrl+D on Unix or Ctrl+Z on Windows):\n";

    while (std::cin.get(ch)) {
        if (std::isalpha(ch)) {
            ch = std::tolower(ch);
            freq[ch]++;
        }
    }

    std::cout << "\nCharacter frequencies:\n";
    for (const auto& pair : freq) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}
