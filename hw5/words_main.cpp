#include "words.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  Words * w1 = nullptr;
  Words * w2 = nullptr;
  string line;

  while (getline(cin, line)) {
    stringstream sstr(line);

    int index;
    sstr >> index;

    if (index != 1 && index != 2) {
      cout << "Invalid index." << endl;
      continue;
    }

    string input;
    sstr >> input;

    Words *&w = (index == 1) ? w1 : w2;

    if (input == "new-size") {
      if (w) {
	cout << "List already exists." << endl;
	continue;
      }

      int size;
      sstr >> size;

      if (!sstr || size < 0 || size > 50) {
	cout << "Invalid size." << endl;
	continue;
      }

      w = newListFromSize(size);
      if (w) {
	cout << "List allocated." << endl;
      } else {
	cout << "No list allocated." << endl;
      }
    } else if (input == "new-string") {
      if (w) {
	cout << "List already exists." << endl;
	continue;
      }
      
      sstr.ignore(1);
      if (!getline(sstr, input)) {
	continue;
      }

      w = newListFromString(input.c_str());
      cout << "List allocated." << endl;
    } else if (input == "append-string") {
      if (!w) {
	cout << "No list." << endl;
	continue;
      }
      
      sstr.ignore(1);
      if (!getline(sstr, input)) {
	continue;
      }

      cout << appendListFromString(w, input.c_str()) << endl;
    } else if (input == "append-list") {
      if (!w) {
	cout << "No list." << endl;
	continue;
      }

      Words * wo = (index == 1) ? w2 : w1;

      if (!wo) {
	cout << "No other list." << endl;
	continue;
      }

      cout << appendListFromList(w, wo) << endl;
    } else if (input == "print") {
      if (!w) {
	cout << "No list." << endl;
	continue;
      }

      printList(w);
    } else if (input == "meta") {
      if (!w) {
	cout << "No list." << endl;
	continue;
      }

      cout << w->num_words << " " << w->max_words << endl;
    } else if (input == "find") {
      if (!w) {
	cout << "No list." << endl;
	continue;
      }

      sstr >> input;
      
      const char * loc = findWord(w, input.c_str());
      cout << (loc ? loc : "not found") << endl;
    } else if (input == "remove") {
      if (!w) {
	cout << "No list." << endl;
	continue;
      }

      sstr >> input;
      
      cout << removeWord(w, input.c_str()) << endl;
    } else if (input == "delete") {
      if (!w) {
	cout << "No list." << endl;
	continue;
      }

      deleteList(w);
      w = nullptr;
      cout << "List deallocated." << endl;
    } else {
      cout << "Unrecognized command." << endl;
    }
  }

  if (w1) {
    deleteList(w1);
  }

  if (w2) {
    deleteList(w2);
  }

  return 0;
}
