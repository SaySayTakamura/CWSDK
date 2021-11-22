#ifndef PLASMA_TRANSFORMATION_H
#define PLASMA_TRANSFORMATION_H

#include "../IDA/types.h"
#include "Keyable.h"
#include "DiscreteAttribute.h"
#include "ContinuousAttribute.h"
#include "Vector.h"
#include "Matrix.h"
#include "Map.h"

namespace plasma {
    class Transformation : public plasma::Keyable {
        public:
            plasma::ContinuousAttribute<plasma::Vector<2, float>> translation;
            plasma::ContinuousAttribute<plasma::Matrix<float>> deformation;
            plasma::ContinuousAttribute<plasma::Vector<3, float>> rotation;
            plasma::ContinuousAttribute<plasma::Vector<2, float>> pivot;
            plasma::Map<int, int> some_map; // Not sure of the types, but it sizeof(key) + sizeof(val) == 8 bytes
            plasma::Matrix<float> base_transformation;
            plasma::Matrix<float> local_transformation;
            void* field_320; // Points to something in a list of the D3D11Engine, see => 0x372FB5
        };
}

static_assert(sizeof(plasma::Transformation) == 0x328, "plasma::Transformation is not the correct size.");

#endif // PLASMA_TRANSFORMATION_H
