#include "Utils.h"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace Utils {

string trim(const string& input) {
    auto start = find_if_not(input.begin(), input.end(), [](unsigned char ch) { return isspace(ch); });
    auto end = find_if_not(input.rbegin(), input.rend(), [](unsigned char ch) { return isspace(ch); }).base();
    if (start >= end) {
        return {};
    }
    return string(start, end);
}

vector<string> split(const string& input, char delimiter) {
    vector<string> tokens;
    stringstream ss(input);
    string item;
    while (getline(ss, item, delimiter)) {
        tokens.push_back(item);
    }
    return tokens;
}

string boolToString(bool value) {
    return value ? "1" : "0";
}

bool stringToBool(const string& value) {
    string lower;
    lower.reserve(value.size());
    transform(value.begin(), value.end(), back_inserter(lower), [](unsigned char ch) {
        return static_cast<char>(tolower(ch));
    });
    lower = trim(lower);
    return lower == "1" || lower == "true" || lower == "yes";
}

}
