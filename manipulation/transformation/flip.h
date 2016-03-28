#ifndef MANIPULATION_TRANSFORMATION_FLIP_H
#define MANIPULATION_TRANSFORMATION_FLIP_H

#include "../../model/image.h"
#include "../operation.h"

namespace manipulation {
namespace transformation {

// Encapsulates a horizontal/vertical image flip operation.
class Flip : public Operation {
public:
    enum Type { horizontal, vertical };

    Flip(Type type);

    void apply(model::Image *&image);

private:
    Type _type;
};
}
}

#endif
