namespace zan1 {
    template <typename PwmDriver, typename EncoderDriver>

    class Motor {

    public:

        Motor(PwmDriver& pwm, EncoderDriver& encoder) : m_pwm(pwm), m_encoder(encoder) {}

        void set_speed(uint32_t speed) {
            m_pwm.set_duty_cycle(speed);
        }

        float get_position() {
            return m_encoder.get_position();
        }

        void stop() {
            m_pwm.set_duty_cycle(0);
        }
    private:
        PwmDriver m_pwm;
        EncoderDriver m_encoder;
    };
}