#include <iostream>
#include <string>

#include "branchAnalysis.h"

int main() {
    branchAnalysis analysis;
    std::string branch1, branch2;

    while (true) {
        std::cout << "Enter the first branch name (enter 0 to exit): ";
        std::cin >> branch1;

        if (branch1 == "0") {
            break;
        }

        std::cout << "Enter the second branch name: ";
        std::cin >> branch2;

        analysis.executeAnalysis(branch1, branch2);
    }

    return 0;
}
