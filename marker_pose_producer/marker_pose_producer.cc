/* User code: This file will not be overwritten by TASTE. */

#include "marker_pose_producer.h"

void marker_pose_producer_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

asn1SccBase_samples_RigidBodyState markerPose;

void marker_pose_producer_PI_clock()
{
  Eigen::Matrix3d r1;
  r1 << 1,0,0,
        0,1,0,
        0,0,1;

  base::Quaterniond q1(r1);

  base::Vector3d t1;
  t1 << 2,0,0;

  asn1Scc_Vector3d_toAsn1(markerPose.position, t1);  
  asn1Scc_Quaterniond_toAsn1(markerPose.orientation, q1);

  marker_pose_producer_RI_markerPose(&markerPose);  
}

