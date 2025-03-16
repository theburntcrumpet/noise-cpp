#ifndef NOISE_GENERATOR_H
#define NOISE_GENERATOR_H
#include "NoiseStrategy.h"
#include "SimplexNoiseStrategy.h"
enum NoiseStrategyEnum {UNDEFINED, SIMPLEX};
class NoiseGenerator {
    int m_noiseWidth;
    int m_noiseHeight;
    NoiseStrategy* m_strategy = new SimplexNoiseStrategy();

    public:
        NoiseGenerator(size_noise noiseWidth, size_noise noiseHeight, NoiseStrategy* strategy) {
            m_noiseWidth = noiseWidth;
            m_noiseHeight = noiseHeight;
            m_strategy = strategy;
        }

        ~NoiseGenerator() {};

        Noise GenerateNoise() {
            return m_strategy->GenerateNoise(m_noiseWidth, m_noiseHeight);
        }

        void SetNoiseStrategy(NoiseStrategy* noiseStrategy) {
            m_strategy = noiseStrategy;
        }

        void SetNoiseStrategy(NoiseStrategy& noiseStrategy) {
            m_strategy = &noiseStrategy;
        }
};
#endif
