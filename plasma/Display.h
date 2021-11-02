#ifndef DISPLAY_H
#define DISPLAY_H

#include "../IDA/types.h"
#include "Keyable.h"
#include "DiscreteAttribute.h"
#include "ContinuousAttribute.h"
#include "Vector.h"

namespace plasma {
    class Display : public plasma::Keyable {
        public:
            plasma::DiscreteAttribute<int> visibility;
            plasma::DiscreteAttribute<int> clipping;
            plasma::ContinuousAttribute<plasma::Vector<4, float>> fill;
            plasma::ContinuousAttribute<plasma::Vector<4, float>> stroke;
            plasma::ContinuousAttribute<float> blurRadius;
            _BYTE gap318[31];
            char end;

            void SetVisibility(int frame, int value);
            void SetVisibility(bool value);
            int GetVisibility(int frame);
            bool IsVisible();
            int GetFrameCount();
        };
}

#endif // DISPLAY_H
