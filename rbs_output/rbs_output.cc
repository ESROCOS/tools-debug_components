/* User code: This file will not be overwritten by TASTE. */

#include "rbs_output.h"
#include <iostream>
#include "base_support/Base-samples-RigidBodyStateConvert.hpp"
#include "base_support/OpaqueConversion.hpp"
#include <Eigen/Core>

void rbs_output_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void rbs_output_PI_in_rbs(const asn1SccBase_samples_RigidBodyState *IN_pose)
{
  base::Vector3d t;
  base::Quaterniond q;
  Eigen::Matrix3d r;
  // extract orientation / translation
  asn1Scc_Vector3d_fromAsn1(t, IN_pose->position);
  asn1Scc_Quaterniond_fromAsn1(q, IN_pose->orientation);
  // convert quaternion to rotation mat
  r = q.normalized().toRotationMatrix();
  std::cout << "got position:\n" << t << "\n" << r << std::endl;

  rbs_output_RI_out_rbs(IN_pose);
}

