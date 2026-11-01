#include <cmath>

namespace zan1 {
    class PidController {
        public:
            PidController(float kp, float ki, float kd, float kv) : m_kp(kp), m_ki(ki), m_kd(kd), m_kv(kv), m_last_error(0), m_last_target(0) {}

            float update(float target, float current) {
                float output = 0.0f;
                m_error = target - current;

                if(fabsf(output) < 1.0f) {
                    m_integral_error += m_error * m_dt;
                }

                if(m_error < ERROR_DEADBAND) {
                    output = 0.0f;
                } else {
                    output = m_kp * m_error + m_ki * m_integral_error + m_kd * (m_error - m_last_error) / m_dt + m_kv * (target - m_last_target);
                }

                if(output < -1.0f) {
                    output = -1.0f;
                } else if(output > 1.0f) {
                    output = 1.0f;
                }

                return output;
            }
        
        private:
            float m_kp;
            float m_ki;
            float m_kd;
            float m_kv;
            float m_error;
            float m_integral_error;
            float m_last_error;
            float m_last_target;
            const float m_dt = 0.005f;
            const float ERROR_DEADBAND = 0.01f;
    };
}