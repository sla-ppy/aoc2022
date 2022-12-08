#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {

    std::string input_file = "../day01/input.txt";
    std::ifstream file;
    file.open(input_file);

    if(file.is_open()) {
        // 1. get input
        int current_sum{0};
        int largest_sum{0};
        std::vector<int> all_sums;

        std::string line;
        while (std::getline(file, line)) {
            // 2 - loop through vector, calculate all sums
            if (!line.empty()) {
                current_sum += std::stoi(line);
            } else {
                all_sums.push_back(current_sum);
                if (largest_sum < current_sum) {
                    largest_sum = current_sum;
                }
                current_sum = 0;
            }
        }
        std::cout << largest_sum << '\n';

        // part 2:
        std::sort(all_sums.begin(), all_sums.end(), std::greater<>());
        int sum_of_three{0};
        for (int i = 0; i < 3; ++i) {
            sum_of_three += all_sums[i];
        }
        std::cout << sum_of_three << '\n';

        file.close();
    } else {
        std::cout << "File not found!" << '\n';
    }

    return 0;
}


