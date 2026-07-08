#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function to calculate the total words in a string
int countWords(const string& sentence) {
    stringstream ss(sentence); 
    string word;
    int count = 0;

    // Extract word by word from the stream
    while (ss >> word) {
        count++;
    }

    return count;
}

int main() {
    string sentence;

    // Read the complete sentence including spaces
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // Call the function and display the result
    int totalWords = countWords(sentence);
    cout << "Total number of words: " << totalWords << endl;

    return 0;
}
