#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include "process_data.h"
#include "fusion_ukf.h"


using namespace std;

int main()
{
    /*******************************************************************
    * 将Lidar和Radar数据读入到all_sensor_data,all_truth_data
    *******************************************************************/
    string input_file = "/home/jc/Documents/learn_ukf/data/data-3.txt";
    string output_file = "/home/jc/Documents/learn_ukf/data/out-3.txt";
    ifstream in_file(input_file.c_str(), ifstream::in);
    ofstream out_file(output_file.c_str(), ofstream::out);
    vector<DataPoint> all_sensor_data;
    vector<DataPoint> all_truth_data;
    read_data(in_file,all_sensor_data,all_truth_data);
    /*******************************************************************
    * UKF滤波，获取预测值
    *******************************************************************/
    vector<MatrixXd> predictions;
    UKF_process(all_sensor_data,predictions);
    /*******************************************************************
    * 将预测结果写入文件
    *******************************************************************/
    //write_data(out_file,predictions);
    /*******************************************************************
    * 在同一窗口显示测量值和预测值
    *******************************************************************/
   cout<<predictions.size()<<endl;

}