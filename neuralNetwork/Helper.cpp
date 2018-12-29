#include "Helper.h"

#include <math.h>

float Helper::sigmoid(float x)
{
    float exp_value = exp((double)-x);
    float return_value = 1 / (1 + exp_value);
    return return_value;
}
