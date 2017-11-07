#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
    
    this -> Kp = Kp_in;
    this -> Ki = Ki_in;
    this -> Kd = Kd_in;

    // Initialize errors
    this -> p_error = 0;
    this -> i_error = 0;
    this -> d_error = 0;

}

/*
* Update the PID error variables given cross track error.
*/
void PID::UpdateError(double cte) {

    this -> d_error = cte - p_error;
    this -> p_error = cte;
    this -> i_error += cte;

    // std::cout << "p_error = " << p_error << std::endl;
    // std::cout << "i_error = " << i_error << std::endl;
    // std::cout << "d_error = " << d_error << std::endl;

}

/*
* Calculate the total PID error.
*/
double PID::TotalError() {

    return Kp * p_error + Ki * i_error + Kd * d_error;
}

