#ifndef DATA_POINT_H_
#define DATA_POINT_H_

#include <stdlib.h>
#include <iostream>
#include <Eigen/Dense>
#include "settings.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

class DataPoint{

  private:
    long long timestamp;
    bool initialized;
    DataPointType data_type;
    VectorXd raw;

  public:
    DataPoint();
    DataPoint(const long long timestamp, const DataPointType& data_type, const VectorXd& raw);
    void set(const long long timestamp, const DataPointType& data_type, const VectorXd& raw);
    VectorXd get() const;
    VectorXd get_state() const;
    VectorXd get_vec() const;
    DataPointType get_type() const;
    long long get_timestamp() const;
    void print() const;
};

#endif /* DATAPOINT_H_*/
