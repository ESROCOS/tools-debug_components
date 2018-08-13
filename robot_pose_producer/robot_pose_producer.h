/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_robot_pose_producer__
#define __USER_CODE_H_robot_pose_producer__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void robot_pose_producer_startup();

void robot_pose_producer_PI_clock();

extern void robot_pose_producer_RI_robotPose(const asn1SccBase_samples_RigidBodyState *);

#ifdef __cplusplus
}
#endif


#endif
