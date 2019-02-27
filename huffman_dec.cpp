/** Template code based off of https://aaronbloomfield.github.io/pdr/labs/lab10/inlab-skeleton.cpp.
 *
 * The template code reads in the input files. 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Missing input file name!" << endl;
    exit(1);
  }

  ifstream file(argv[1], ifstream::binary);
  
  while (true) {
    string character, prefix;
    file >> character;

    if ((character[0] == '-') && (character.length() > 1)) break;

    if (character == "space") character = " ";

    file >> prefix;

    cout << "character '" << character << "' has prefix code '"
	 << prefix << "'" << endl;
  }

  stringstream sstm;
  while (true) {
    string bits;
    file >> bits;

    if (bits[0] == '-') break;

    sstm << bits;
  }

  string allbits = sstm.str();

  cout << "All the bits: " << allbits << endl;

  file.close();
  
  return 0;
}
