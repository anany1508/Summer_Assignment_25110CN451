#include <iostream>
using namespace std;

// Function to count set bits
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        // Check if the last bit is 1
        count += (n & 1); 
        // Right shift the number to check the next bit
        n = n >> 1;       
    }
    return count;
}

int main() {
    int num ; 
    cout<<"enter a number :";
    cin>>num;
    
    cout << "Number of set bits in " << num << " is: " << countSetBits(num) << endl;
    
    return 0;
}
