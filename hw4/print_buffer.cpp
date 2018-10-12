#include <cstring>
#include <iostream>
#include <limits>
using namespace std;



// a class representing a variable length c-string buffer
// that can be read and written
class CStringBuffer {
public:
  // construct a new buffer that is empty
  CStringBuffer() {
   buffer = new char[0];
   buffersize = 0;
  }

  // destruct buffer and free resources
  ~CStringBuffer() {
    delete [] buffer;
  
  }

  // resize the buffer to the given size
  void resize_buffer(int newsize) {
    buffersize = newsize;
    delete [] buffer;
    buffer = new char[buffersize]; 
  }

  // read a line in to the buffer from an istream
  void read_from(istream & in) {
   string temp = "";
   getline (in, temp);
   if (temp.size() > buffersize) {
     resize_buffer(temp.size() + 1);     
   }

   for (int i = 0; i < buffersize; i++) {
      if (i == (buffersize - 1) || i >= temp.size()) {
        buffer[i] = '\0';
      } else {
        buffer[i] = temp.at(i);
      } 
    } 
  
  }

  // write the buffer to an ostream
  void write_to(ostream & out) {
    out << buffer;
  }

private:
  // make not copyable
  CStringBuffer(const CStringBuffer&) = delete;
  CStringBuffer& operator=(const CStringBuffer&) = delete;  

  char * buffer; // the buffer itself
  int buffersize; // size of the buffer
};



int main() {
  CStringBuffer buffer;

  while (true) {
    // red in new buffer size
    int newsize;
    cout << "Enter a buffer size: ";
    cin >> newsize;
    cin.ignore(numeric_limits< streamsize >::max(), '\n'); // skip to end of line
    
    if (newsize <= 0 || newsize >= 10) {
      cout << "Invalid size." << endl;
      break;
    }
    
    // resize buffer
    buffer.resize_buffer(newsize);

    // read in new buffer contents
    cout << "Enter a string: ";
    buffer.read_from(cin);
    cin.clear(); // ignore input errors
    cin.ignore(numeric_limits< streamsize >::max(), '\n'); // skip to end of line

    // display buffer contents
    cout << "You entered: ";
    buffer.write_to(cout);
    cout << endl;
  }
  

}
