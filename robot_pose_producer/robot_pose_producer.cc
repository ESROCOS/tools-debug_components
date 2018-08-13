/* User code: This file will not be overwritten by TASTE. */

#include "robot_pose_producer.h"
#include "base_support/Base-samples-RigidBodyStateConvert.hpp"
#include "base_support/OpaqueConversion.hpp"
#include <Eigen/Core>
#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

base::Vector3d t0(3,0,0);
base::Vector3d t1(2,2,0);
base::Vector3d t2(0,3,0);
base::Vector3d t3(-2,2,0);
base::Vector3d t4(-3,0,0);
base::Vector3d t5(-2,-2,0);
base::Vector3d t6(0,-3,0);
base::Vector3d t7(2,-2,0);

base::Vector3d positions[8] = {t0,t1,t2,t3,t4,t5,t6,t7};

Eigen::Matrix3d r;

asn1SccBase_samples_RigidBodyState robotPose;

void setRot(double x){
  r << cos(x), -sin(x), 0,
       sin(x),  cos(x), 0,
            0,       0, 1;	  
}

void robot_pose_producer_startup()
{
  r << 1,0,0,
       0,1,0,
       0,0,1;
}

void robot_pose_producer_PI_clock()
{
  static int i = 0;
  //std::cout << "producer: clock tick " << i << std::endl;

  double x = (i % 8) * 0.25 * M_PI;
  setRot(x);

  //std::cout << "rot matrix:\n" << r << std::endl;
  base::Quaterniond q(r);

  asn1Scc_Vector3d_toAsn1(robotPose.position, positions[i%8]);
  asn1Scc_Quaterniond_toAsn1(robotPose.orientation, q);
  
  //std::cout << "producer: push robot pose" << std::endl;
  robot_pose_producer_RI_robotPose(&robotPose);

  i++;
}

