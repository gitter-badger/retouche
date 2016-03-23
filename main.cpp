#include <iostream>
#include <cstring>

#include "persistence/all.h"

using namespace std;

void handle(Persistence::Image *&image, const char *command, const char *value) {
  if (strcmp(command, "read") == 0) {
    image = Persistence::get("bmp")->load("something");
  } else if (strcmp(command, "apply") == 0) {
  } else if (strcmp(command, "write") == 0) {
  }
}

int main(int argc, char **argv) {
  Persistence::Image *image;
  for (int i = 1; i < argc; ++i) {
    char *command = strtok(argv[i], ":"), *value = strtok(nullptr, ":");
    handle(image, command, value);
  }
}
