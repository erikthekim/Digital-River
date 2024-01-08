#include <iostream>

// Function to perform the calculation based on r_1 and r_2
void river(int r_1, int r_2) {
    int k1 = 10;
    int sum1 = r_1, sum2 = r_2; // Initialize sum variables
    int sumtemp = 0, rtemp = 0; // Temporary variables for swapping

    // Loop indefinitely until break
    while (true) {
        // Swap
        if (r_2 < r_1) {
            sumtemp = sum2;
            sum2 = sum1;
            sum1 = sumtemp;
            rtemp = r_2;
            r_2 = r_1;
            r_1 = rtemp;
        }
            // Break the loop if r_1 == r_2
        else if (r_2 == r_1) {
            break;
        }
            // Calculation part if r_1 >=  k1/10
        else if (r_1 >= (k1 / 10)) {
            int digit = (r_1 % k1) / (k1 / 10);
            k1 *= 10;
            sum1 += digit;
        }
            // Reset and update
        else {
            r_1 = sum1;
            k1 = 10;
            std::cout << sum1 << " " << sum2 << std::endl;
        }
    }

    // Final output
    if (sum1 == sum2) {
        std::cout << "The answer is " << sum1 << std::endl;
    } else {
        std::cout << "Oops" << std::endl;
    }
}

int main() {
    int r_1, r_2;
    // take input
    std::cout << "First number: ";
    std::cin >> r_1;
    std::cout << "Second number: ";
    std::cin >> r_2;

    // Call river
    river(r_1, r_2);
    return 0;
}