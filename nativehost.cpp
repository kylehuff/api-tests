#include "common.h"

// Compile example:
//  g++ nativehost.cpp -o nativehost

void writeOut(const std::string output) {
  std::cerr << "writing out:"
            << std::endl
            << output
            << std::endl;

#ifdef HAVE_W32_SYSTEM
  _setmode(_fileno(stdin),_O_BINARY);
#endif

#ifdef HAVE_W32_SYSTEM
  // Remove all newlines on w32
  output.erase(std::remove(output.begin(), output.end(), '\n'), output.end());
#endif

  unsigned int a = output.length();

  // We need to send the 4 btyes of length information, then the string
  std::cout << char(((a>>0) & 0xFF))
            << char(((a>>8) & 0xFF))
            << char(((a>>16) & 0xFF))
            << char(((a>>24) & 0xFF))
            << output;
}

int main(int argc, char* argv[]) {

  if (argv[1] != NULL) {
    std::string output;
    unsigned int len = 0;

    std::cin.read((char*) &len, sizeof(len));

    std::cout.sync_with_stdio(false);
    std::cin.sync_with_stdio(false);

    char str[len];

    size_t res = fread(str, sizeof(char), len, stdin);

    std::cerr << "received message:"
              << std::endl
              << str
              << std::endl;

    if (res) { // We are going to pretend that any data without the string "echo"
               // is a request for the version
      apitest apitest;
      if (strstr (str,"echo"))
        output = apitest.echo(str);
      else
        output = apitest.get_version();
    }

    writeOut(output);
  }
  return 0;
}
