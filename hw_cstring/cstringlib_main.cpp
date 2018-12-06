#include "cstringlib.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const char *checkstring(const char *str) {
  return str ? str : "NULL";
}

int main() {
  const size_t STRBUFSIZE = 21;
  char strbuf[STRBUFSIZE] = "";

  string line;
  while (getline(cin, line)) {
    stringstream sstr(line);

    string command;
    sstr >> command;

    if (command == "print") {
      cout << strbuf << endl;
    } else if (command == "printall") {
      for (char c: strbuf) {
	cout << ((c < 32 || c > 126) ? '_' : c);
      }
      cout << endl;
    } else if (command == "strlen") {
      cout << str::strlen(strbuf) << endl;
    } else if (command == "strncpy") {
      string input;
      if (getline(sstr.ignore(1), input)) {
	char * res = str::strncpy(strbuf, input.c_str(), STRBUFSIZE);
	strbuf[STRBUFSIZE - 1] = '\0';
	cout << checkstring(res) << endl;
      }
    } else if (command == "strncat") {
      string input;
      if (getline(sstr.ignore(1), input)) {
	char * res = str::strncat(strbuf, input.c_str(), STRBUFSIZE - string(strbuf).size());
	strbuf[STRBUFSIZE - 1] = '\0';
	cout << checkstring(res) << endl;
      }
    } else if (command == "strcmp") {
      string input;
      if (getline(sstr.ignore(1), input)) {
	int res = str::strcmp(strbuf, input.c_str());
	if (res < 0) {
	  cout << "<0" << endl;
	} else if (res > 0) {
	  cout << ">0" << endl;
	} else {
	  cout << "=0" << endl;
	}
      }
    } else if (command == "strchr") {
      char chr;
      if (sstr >> chr) {
	cout << checkstring(str::strchr(strbuf, chr)) << endl;
      }
    } else if (command == "strrchr") {
      char chr;
      if (sstr >> chr) {
	cout << checkstring(str::strrchr(strbuf, chr)) << endl;
      }
    } else if (command == "strstr") {
      string input;
      if (getline(sstr.ignore(1), input)) {
	cout << checkstring(str::strstr(strbuf, input.c_str())) << endl;
      }
    } else if (command == "strspn") {
      string input;
      if (getline(sstr.ignore(1), input)) {
	cout << str::strspn(strbuf, input.c_str()) << endl;
      }
    } else if (command == "strcspn") {
      string input;
      if (getline(sstr.ignore(1), input)) {
	cout << str::strcspn(strbuf, input.c_str()) << endl;
      }
    } else if (command == "strtok-str") {
      string input;
      if (getline(sstr.ignore(1), input)) {
	cout << checkstring(str::strtok(strbuf, input.c_str())) << endl;
      }
    } else if (command == "strtok-null") {
      string input;
      if (getline(sstr.ignore(1), input)) {
	cout << checkstring(str::strtok(nullptr, input.c_str())) << endl;
      }
    } else {
      cout << "Unrecognized command." << endl;
    }
  }

  return 0;
}
