#ifndef FUSION_UKF_H_
#define FUSION_UKF_H_

#include <Eigen/Dense>
#include <vector>
#include "measurementpredictor.h"
#include "statepredictor.h"
#include "stateupdater.h"
#include "settings.h"
#include "data_point.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;

void UKF_process(const vector<DataPoint>& all_sensor_data,vector<MatrixXd>& predictions);

class FusionUKF{

  private:
    bool initialized;
    long long timestamp;
    double nis;
    VectorXd x = VectorXd(NX);
    MatrixXd P = MatrixXd(NX, NX);
    StatePredictor statePredictor;
    MeasurementPredictor measurementPredictor;
    StateUpdater stateUpdater;

    //PRIVATE FUNCTIONS
    void initialize(const DataPoint& data);
    void update(const DataPoint& data);

  public:
    FusionUKF();
    void process(const DataPoint& data);
    VectorXd get() const;
    double get_nis() const;
};

#endif //FUSIONUKF_H_
