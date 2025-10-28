#pragma once

#include <string>
#include <vector>

using namespace std;

namespace Utils {
string trim(const string& input);
vector<string> split(const string& input, char delimiter);
string boolToString(bool value);
bool stringToBool(const string& value);
}

