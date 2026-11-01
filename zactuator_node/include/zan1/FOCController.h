namespace zan1 {
    class FOCController {
        public:
            FOCController() {}

            void threePhaseToRotating(float ia, float ib, float ic, float rotor_angle, float& i_direct, float& i_quadrature);
            void rotatingToThreePhase(float i_direct, float i_quadrature, float rotor_angle, float& outva, float& outvb, float& outvc);
    };
}