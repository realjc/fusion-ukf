#ifndef PROCESS_DATA_H_
#define PROCESS_DATA_H_

#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "data_point.h"
using namespace std;


void read_data(ifstream& in_file, vector<DataPoint>& all_sensor_data,vector<DataPoint>& all_truth_data);

void write_data(ofstream& in_file,vector<VectorXd>& predictions);

#endif