#include "stdexcept"
#include "iostream"
#include "application.h"

// Welcome to minecpp!
int main(int argc, char** argv) {
   try {
      Application application;
      application.loop();
      return 0;
   }
   catch(std::exception& e) {
      std::cerr << e.what() << std::endl;
      return 1;
   }
}
