#include "registering_thrower.h"
#include <numbers>

#define MIN_BOUND_GAP 0.0001

static constexpr double origin[2] = {0, 0};

class TrajectoryCalculator{
    private:
        Vector<double> acceleration;
        Vector<double> halfAcceleration;
    public:
        TrajectoryCalculator(double *accComponents);
        Registering::ModulusAngleTraj Calculate(Vector<double> &position, double vModulus, double vAngle);
};

TrajectoryCalculator::TrajectoryCalculator(double *accComponents) : acceleration(accComponents, 2){
    halfAcceleration = .5 * acceleration;
}

Registering::ModulusAngleTraj TrajectoryCalculator::Calculate(Vector<double> &position, double vModulus,
            double vAngle){

    Registering::Trajectory *traj = new Registering::Trajectory;

    double vComponents[2] = {vModulus*cos(vAngle), vModulus*sin(vAngle)};
    Vector<double> velocity(vComponents, 2);

    do{

        traj->DirectAppend(position);

        position += velocity;
        position += halfAcceleration;

        velocity += acceleration;

    }while(position.Get(1) > 0);

    double timeReturn = (-vComponents[1] - velocity.Get(1))/acceleration.Get(1);

    Vector<double> subserv = timeReturn * velocity;
    position += subserv;

    subserv = (timeReturn*timeReturn) * halfAcceleration;
    position += subserv;

    traj->DirectAppend(position);

    Registering::ModulusAngleTraj ans;

    ans.modulus = vModulus;
    ans.angle = vAngle;
    ans.traj = traj;

    return ans;

}

MutableListSequence<Registering::ModulusAngleTraj>* Registering::RegisterThrower(double leftBound, double rightBound,
            double velocityDelta, double gravitation){

    if(rightBound - leftBound < MIN_BOUND_GAP) throw TooLittleGap(rightBound - leftBound, MIN_BOUND_GAP);

    MutableListSequence<Registering::ModulusAngleTraj>* ans = new MutableListSequence<Registering::ModulusAngleTraj>;

    double accComponents[2] = {0, -gravitation};
    TrajectoryCalculator calculator(accComponents);

    int vModulusToDelta = 1;
    double vAngle = std::numbers::pi_v<double>/4;

    Vector<double> *position = nullptr;

    do{

        delete position;
        position = new Vector<double>(origin, 2);

        ans->DirectAppend(calculator.Calculate(*position, vModulusToDelta*velocityDelta, vAngle));

        if(position->Get(0) < leftBound) vModulusToDelta *= 2;
        else break;

    }while(1);

    if(position->Get(0) <= rightBound){
        delete position;
        return ans;
    }

    int leftModulusToDelta = vModulusToDelta/2;
    int rightModulusToDelta = vModulusToDelta;

    while(rightModulusToDelta - leftModulusToDelta > 1){

        delete position;
        position = new Vector<double>(origin, 2);

        vModulusToDelta = (leftModulusToDelta + rightModulusToDelta)/2;

        ans->DirectAppend(calculator.Calculate(*position, vModulusToDelta*velocityDelta, vAngle));

        if(position->Get(0) < leftBound){
            leftModulusToDelta = vModulusToDelta;
        }else if(position->Get(0) > rightBound){
            rightModulusToDelta = vModulusToDelta;
        }else{
            delete position;
            return ans;
        }

    }

    vModulusToDelta = rightModulusToDelta;

    double rightAngle = vAngle;
    vAngle /= 2;

    do{

        delete position;
        position = new Vector<double>(origin, 2);

        ans->DirectAppend(calculator.Calculate(*position, vModulusToDelta*velocityDelta, vAngle));

        if(position->Get(0) > rightBound){
            rightAngle = vAngle;
            vAngle /= 2;
        }else break;

    }while(1);

    if(position->Get(0) >= leftBound){
        delete position;
        return ans;
    }

    double leftAngle = vAngle;

    do{

        delete position;
        position = new Vector<double>(origin, 2);

        vAngle = (leftAngle + rightAngle)/2;

        ans->DirectAppend(calculator.Calculate(*position, vModulusToDelta*velocityDelta, vAngle));

        if(position->Get(0) < leftBound){
            leftAngle = vAngle;
        }else if(position->Get(0) > rightBound){
            rightAngle = vAngle;
        }else{
            delete position;
            return ans;
        }

    }while(1);
                
}