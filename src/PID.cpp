#include "PID.h"

using namespace std;

PID::PID(double Kp, double Ki, double Kd)
{
  p_error = 0;
  i_error = 0;
  d_error = 0;
  ctePrevious = 0;

  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

double PID::step(double cte)
{
  // 1. update the errors
  p_error = cte;
  i_error += cte;
  d_error = cte - ctePrevious;
  ctePrevious = cte;

  // 2. calculate the total error
  return
	- Kp * p_error  // P-part
	- Ki * i_error  // I-part
        - Kd * d_error; // D-part
}

