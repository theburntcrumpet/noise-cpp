#ifndef SIMPLEX_NOISE_STRATEGY_H
#define SIMPLEX_NOISE_STRATEGY_H

#include "Noise.h"
#include "NoiseStrategy.h"

class SimplexNoiseStrategy : public NoiseStrategy {
    public:
        SimplexNoiseStrategy() {}
        ~SimplexNoiseStrategy() {}

        Noise GenerateNoise(size_noise width, size_noise height) override {
            Noise noise =  Noise(width,height);
            for (size_noise x = 0; x < width; x++) {
                for (size_noise y = 0; y < height; y++)
                {
                    noise.SetValueAt(x, y, (x*y) / 100);
                }
            }
            return noise;
        }
};

#endif
