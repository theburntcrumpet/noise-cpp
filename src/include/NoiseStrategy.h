#ifndef NOISE_STRATEGY_H
#define NOISE_STRATEGY_H

#include "Noise.h"

class NoiseStrategy {
    public:
        virtual Noise GenerateNoise(size_noise width, size_noise height, seed_noise seed, double frequency) = 0;
};
#endif
