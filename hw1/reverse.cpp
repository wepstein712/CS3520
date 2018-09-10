#include <iostream>
#include <fstream>
using namespace std;

int
main()
{
  ifstream inFile;
  inFile.open("input.txt");
 
  if (!inFile) {
    std::cout << "File Error";
  } else {
    std::string line;
    string output = "";
    while (std::getline(inFile, line)) {
      for (int i = line.length() - 1; i >= 0; i--) {
        output += line.at(i);
      }
      output += "\n";
      //std::cout << line << std::endl;
    }

  std::cout << output;
  }

  return 0;
}
