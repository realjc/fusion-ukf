#include "process_data.h"


void read_data(ifstream& in_file, vector<DataPoint>& all_sensor_data,
               vector<DataPoint>& all_truth_data)
{
    string line;
    string sensor_id;
    double val1, val2, val3;
    double x, y, vx, vy, v, yaw, yawrate;
    long long timestamp;

    while(getline(in_file, line)){
        istringstream iss(line);
        DataPoint sensor_data;
        DataPoint truth_data;

        iss >> sensor_id;

        if(sensor_id.compare("L") == 0){

            iss >> val1;
            iss >> val2;
            iss >> timestamp;

            VectorXd lidar_vec(NZ_LIDAR);
            lidar_vec << val1, val2;
            sensor_data.set(timestamp, DataPointType::LIDAR, lidar_vec);

            }
        else if(sensor_id.compare("R") == 0)
            {
            iss >> val1;
            iss >> val2;
            iss >> val3;
            iss >> timestamp;

            VectorXd radar_vec(NZ_RADAR);
            radar_vec << val1, val2, val3;
            sensor_data.set(timestamp, DataPointType::RADAR, radar_vec);
            }

            iss >> x;
            iss >> y;
            iss >> vx;
            iss >> vy;
            iss >> yaw;
            iss >> yawrate;

            v = sqrt(vx * vx + vy * vy);

            VectorXd truth_vec(NX);
            truth_vec << x, y, v, yaw, yawrate;
            truth_data.set(timestamp, DataPointType::STATE, truth_vec);

            all_sensor_data.push_back(sensor_data);
            all_truth_data.push_back(truth_data);
  }
}

void write_data( ofstream& in_file,vector<VectorXd>& predictions)
{
    
}