#ifndef PERLIN_NOISE_STRATEGY_H
#define PERLIN_NOISE_STRATEGY_H

#include "Noise.h"
#include "NoiseStrategy.h"
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>

class PerlinNoiseStrategy : public NoiseStrategy {
    public:
        PerlinNoiseStrategy() {}
        ~PerlinNoiseStrategy() {}

        Noise GenerateNoise(size_noise width, size_noise height, seed_noise seed, double frequency) override {
            Noise noise = Noise(width, height);
            std::vector<int> permutation = GeneratePermutation(seed);
            
            for (size_noise y = 0; y < height; ++y) {
                for (size_noise x = 0; x < width; ++x) {
                    double nx = x / static_cast<double>(width) * frequency;
                    double ny = y / static_cast<double>(height) * frequency;
                    double value = Perlin(nx, ny, permutation);
                    noise.SetValueAt(x, y, value);
                }
            }
            
            return noise;
        }

    private:
        std::vector<int> GeneratePermutation(seed_noise seed) {
            std::vector<int> p(256);
            std::iota(p.begin(), p.end(), 0);
            std::default_random_engine engine(seed);
            std::shuffle(p.begin(), p.end(), engine);
            p.insert(p.end(), p.begin(), p.end());
            return p;
        }

        double Fade(double t) {
            return t * t * t * (t * (t * 6 - 15) + 10);
        }

        double Lerp(double t, double a, double b) {
            return a + t * (b - a);
        }

        double Grad(int hash, double x, double y) {
            int h = hash & 15;
            double u = h < 8 ? x : y;
            double v = h < 4 ? y : h == 12 || h == 14 ? x : 0;
            return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
        }

        double Perlin(double x, double y, const std::vector<int>& permutation) {
            int X = static_cast<int>(std::floor(x)) & 255;
            int Y = static_cast<int>(std::floor(y)) & 255;
            x -= std::floor(x);
            y -= std::floor(y);
            double u = Fade(x);
            double v = Fade(y);
            int A = permutation[X] + Y;
            int AA = permutation[A];
            int AB = permutation[A + 1];
            int B = permutation[X + 1] + Y;
            int BA = permutation[B];
            int BB = permutation[B + 1];

            return Lerp(v, Lerp(u, Grad(permutation[AA], x, y),
                                   Grad(permutation[BA], x - 1, y)),
                           Lerp(u, Grad(permutation[AB], x, y - 1),
                                   Grad(permutation[BB], x - 1, y - 1)));
        }
};

#endif
