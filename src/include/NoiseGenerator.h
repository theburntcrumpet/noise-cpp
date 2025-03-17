#ifndef NOISE_GENERATOR_H
#define NOISE_GENERATOR_H
#include "NoiseStrategy.h"
#include "Noise.h"
enum NoiseStrategyEnum {UNDEFINED, SIMPLEX};
class NoiseGenerator {
    int m_noiseWidth;
    int m_noiseHeight;
    double m_frequency = 10.0f;
    NoiseStrategy* m_strategy = nullptr;

    public:
        NoiseGenerator(size_noise noiseWidth, size_noise noiseHeight, NoiseStrategy* strategy) {
            m_noiseWidth = noiseWidth;
            m_noiseHeight = noiseHeight;
            m_strategy = strategy;
        }

        ~NoiseGenerator() {};

        Noise GenerateNoise(seed_noise seed) {
            if (m_strategy == nullptr) return Noise(m_noiseWidth, m_noiseHeight); // return empty noise
            return m_strategy->GenerateNoise(m_noiseWidth, m_noiseHeight, seed, m_frequency);
        }

        void SetNoiseStrategy(NoiseStrategy* noiseStrategy) {
            m_strategy = noiseStrategy;
        }

        void SetNoiseStrategy(NoiseStrategy& noiseStrategy) {
            m_strategy = &noiseStrategy;
        }

        double GetFrequency() {return m_frequency;}
        void SetFrequency(double frequency) {m_frequency = frequency;}
};
#endif
