#include "zan1/FOCController.h"
#include "arm_math.h"

namespace zan1 {
    void FOCController::threePhaseToRotating(float ia, float ib, float ic, float rotor_angle, float& i_direct, float& i_quadrature) {
        float i_alpha, i_beta;

        arm_clarke_f32(ia, ib, &i_alpha, &i_beta);
        arm_park_f32(i_alpha, i_beta, &i_direct, &i_quadrature, arm_sin_f32(rotor_angle), arm_cos_f32(rotor_angle));
    }

    void FOCController::rotatingToThreePhase(float v_direct, float v_quadrature, float rotor_angle, float& outva, float& outvb, float& outvc) {
        float v_alpha, v_beta;

        arm_inv_park_f32(v_direct, v_quadrature, &v_alpha, &v_beta, arm_sin_f32(rotor_angle), arm_cos_f32(rotor_angle));
        arm_inv_clarke_f32(v_alpha, v_beta, &outva, &outvb);
        outvc = -outva - outvb;
    }
}