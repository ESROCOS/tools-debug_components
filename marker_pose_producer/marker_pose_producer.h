/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_marker_pose_producer__
#define __USER_CODE_H_marker_pose_producer__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void marker_pose_producer_startup();

void marker_pose_producer_PI_clock();

extern void marker_pose_producer_RI_markerPose(const asn1SccBase_samples_RigidBodyState *);

#ifdef __cplusplus
}
#endif


#endif
