#ifndef PID_H
#define PID_H

class PID {
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  double ctePrevious;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

public:
  /*
  * Constructor
  */
  PID(const double Kp, const double Ki, const double Kd);

  /*
  * Update the PID error variables given cross track error.
  * Calculate the total PID error (= correction factor)
  */
  double step(double cte);
};

#endif /* PID_H */
