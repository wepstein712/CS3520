#include <iostream>
#include <fstream>

using namespace std;


int
main()
{
  ifstream inFile;
  inFile.open("input.txt");
  ifstream i2;

  if (!inFile) {
    std::cout << "File Error";
  } else {
    std::string line;
    string output = "";
    int max = 0;
    while (std::getline(inFile, line)) {
      if (line.length() > max) {
        max = line.length();
      }
     // output += "* ";
     // output += line;
     //output += " *\n";
    }
    
    inFile.close();
    i2.open("input.txt");
    while (std::getline(i2, line)) {
      output += "* ";
      output += line;
      for (int i = 0; i + line.length() <= max; i++) {
       output += " ";
      }  
      output += "*\n";
    }
    string sts = "";
    max +=4;
    for (int i = 0; i < max; i++) {
      sts += "*";
    }
    sts += "\n";
    std::cout << sts << output <<sts;
  }



  return 0;
}
