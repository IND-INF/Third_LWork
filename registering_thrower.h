#ifndef _REGISTERING_THROWER_H_
#define _REGISTERING_THROWER_H_

#include "Sequence/List_sequence/mutable_list_sequence.h"
#include "yet_another_vector.h"

namespace Registering{

    typedef MutableListSequence<Vector<double>> Trajectory;

    typedef struct struct_ModulusAngleTraj{

        double modulus;
        double angle;
        Trajectory* traj;

        struct_ModulusAngleTraj& operator=(const struct_ModulusAngleTraj& rhv){

            this->modulus = rhv.modulus;
            this->angle = rhv.angle;
            this->traj = rhv.traj;

            return *this;

        }

    } ModulusAngleTraj;


    MutableListSequence<ModulusAngleTraj>* RegisterThrower(double leftBound, double rightBound,
                double velocityDelta, double gravitation = 9.8);

}

#endif //_REGISTERING_THROWER_H_