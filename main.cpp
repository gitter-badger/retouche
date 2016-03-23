#include <iostream>

#include "persistence/all.h"

int main() {
  Persistence::get("bmp")->load("something");
}
