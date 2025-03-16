#ifndef NOISE_H
#define NOISE_H
#include <vector>

typedef long size_noise;
typedef std::vector<std::vector<double>> vector_noise;
class Noise {
    private:
        size_noise m_width;
        size_noise m_height;
        vector_noise m_noise;
    public:
        Noise(size_noise width, size_noise height) {
            m_width = width;
            m_height = height;
            m_noise = vector_noise(m_width, std::vector<double>(m_height));
        }

        ~Noise(){};

        vector_noise GetNoise() {return m_noise;}
        size_noise GetWidth() { return m_width; }
        size_noise GetHeight() { return m_height; }
        void SetValueAt(size_noise x, size_noise y, double value) {
            if (!IsInXRange(x) || !IsInYRange(y)) return;
            m_noise[x][y] = value;
        }
    private:
        bool IsInRange(size_noise n, size_noise min, size_noise max) {
            if (n < min) return false;
            if (n >= max) return false;
            return true;
        }

        bool IsInXRange(size_noise n) {
            return IsInRange(n, 0, m_width);
        }

        bool IsInYRange(size_noise n) {
            return IsInRange(n, 0, m_height);
        }
};
#endif
