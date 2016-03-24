#include <iostream>
#include <cstring>

#include "model/image.h"
#include "persistence/factory.h"
#include "filters/factory.h"

class Retouche {
public:
    void execute(const char *command, const char *value) {
        if (strcmp(command, "read") == 0) {
            persister = Persistence::get(value);
        } else if (strcmp(command, "from") == 0) {
            image = persister->load(value);
        } else if (strcmp(command, "apply") == 0) {
            Filters::get(value)->apply(image);
        } else if (strcmp(command, "write") == 0) {
            persister = Persistence::get(value);
        } else if (strcmp(command, "to") == 0) {
            persister->save(image, value);
        }
    }
private:
    Persistence::Persister *persister;
    Model::Image *image;
};


int main(int argc, char **argv) {
    Retouche retouche;
    for (int i = 1; i < argc; ++i) {
        char *command = strtok(argv[i], ":"), *value = strtok(nullptr, ":");
        retouche.execute(command, value);
    }
}
