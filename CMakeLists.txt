# ======================================================================
#  FILE:  $URL$
# ======================================================================
#  PROJECT:             :  tools-debugcomponents
#  VERSION              :  @VERION@
#  LANGUAGE             :  CMake script
#  AUTHOR               :  @AUTHOR@
#  COPYRIGHT            :  @COPYRIGHT@
#  COMPILER             :  cmake version 3.0.2
#  CREATED              :  @CREATED@
#  CLASS                :  -
#  LAST MODIFIED        :  @LASTMODIFIED@
#  GENERATED FROM MODEL :  -
#  ORIGINAL MODEL AUTHOR:  -
# ----------------------------------------------------------------------
#  @DESCRIPTION@
# ----------------------------------------------------------------------
#  HISTORY
#  $History$
# ======================================================================

cmake_minimum_required(VERSION 3.2)

project(tools-debugcomponents)

include($ENV{ESROCOS_CMAKE})

#required function call to set up esrocos
esrocos_init()

########### FOR INTEGRATION PROJECTS ##############

#uncomment if you want to add dependencies for the build process (only required in integration projects)
#esrocos_add_dependency(PARTITION <Name Of Partition>
#                       MODULES   <PKG-Config findable module>[,secondmodule,thirdmodule...])

########### FOR COMPONENT PROJECTS ################

#uncomment if you want to export a function
esrocos_export_function("rbs_printer" "share/taste_components/debugging")
esrocos_export_function("rbs_output" "share/taste_components/debugging")
esrocos_export_function("robot_pose_producer" "share/taste_components/debugging")
esrocos_export_function("marker_pose_producer" "share/taste_components/debugging")

#uncomment to export PKG-CONFIG-file
esrocos_export_pkgconfig( VERSION 1.0
                          DESCRIPTION "none"
                          REQUIRES base-types base_support
                          LIBS ""
                          STATIC_LIBS "" 
                          C_FLAGS ""
                        ) 
