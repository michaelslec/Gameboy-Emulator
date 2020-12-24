#include <array>
#include <bitset>
#include <fstream>
#include <iostream>
#include <string>

typedef unsigned char BYTE;
typedef char SIGNED_BYTE;
typedef unsigned short WORD;
typedef signed short SIGNED_WORD;

using namespace std;

const size_t kMEMORY_SIZE = 0x200000;

int main() {
  array<BYTE, kMEMORY_SIZE> cartridge_memory;

  fstream game_file("tetris.gb", ios::binary | ios::in);
  if (!game_file) {
    cerr << "Could not open tetris.gb" << endl;
    return 1;
  }

  // reinterpret_cast is supposedly dangerous; however, seems like it's fine
  // here
  game_file.read(reinterpret_cast<char *>(cartridge_memory.data()),
                 kMEMORY_SIZE);

  return 0;
}
