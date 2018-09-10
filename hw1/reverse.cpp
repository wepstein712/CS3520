#include <iostream>
#include <fstream>
using namespace std;

int
main()
{
  ifstream inFile;
  inFile.open("input.txt");
 
  if (!inFile) {
    std::cerr << "File Error";
  } else {
    std::string line;
    string output = "";
    string revLine = "";
    while (std::getline(inFile, line)) {
      for (int i = line.length() - 1; i >= 0; i--) {
        revLine += line.at(i);
      }
      revLine += "\n";
      output = revLine + output;
      revLine = "";
      //std::cout << line << std::endl;
    }

  std::cout << output;
  }

  return 0;
}
