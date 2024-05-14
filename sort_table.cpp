#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
// Function to trim leading and trailing whitespaces from a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

// Function to split a string by delimiter
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

// Function to compare rows based on the first column
// Function to compare rows based on the first column
bool compareRows(const std::vector<std::string>& row1, const std::vector<std::string>& row2) {
    try {
        return std::stoi(row1[0]) < std::stoi(row2[0]);
    } catch (const std::invalid_argument&) {
        // Handle invalid input gracefully
        return false; // For example, treat invalid inputs as greater than valid inputs
    }
}


int main() {
    std::ifstream inFile("README.md");
    std::ofstream outFile("sorted_README.md");
    std::vector<std::vector<std::string>> table;

    std::string line;
    bool inTable = false;

    // Read the Markdown file line by line
    while (std::getline(inFile, line)) {
        if (!inTable && line.find("|") != std::string::npos) {
            inTable = true;
            continue;
        }
        if (inTable) {
            if (line.find("|") != std::string::npos) {
                // Split the line into columns
                std::vector<std::string> columns = split(line, '|');
                // Ignore header and footer rows
                if (columns.size() > 1) {
                    table.push_back(columns);
                }
            } else {
                inTable = false;
            }
        }
    }

    // Sort the table based on the first column (assuming it's the `#` column)
    std::sort(table.begin(), table.end(), compareRows);

    // Write the sorted table to the output file
    for (const auto& row : table) {
        for (size_t i = 0; i < row.size(); ++i) {
            outFile << row[i];
            if (i < row.size() - 1) {
                outFile << "|";
            }
        }
        outFile << "\n";
    }

    inFile.close();
    outFile.close();

    std::cout << "Table sorted and written to sorted_README.md\n";

    return 0;
}
