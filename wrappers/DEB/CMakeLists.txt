cmake_minimum_required(VERSION 2.6)
 
PROJECT(DistanceBetweenPoints)
 
#FIND_PACKAGE(VTK REQUIRED)
#INCLUDE(${VTK_USE_FILE})
 
ADD_EXECUTABLE(DistanceBetweenPoints DistanceBetweenPoints.cxx)
INSTALL(TARGETS DistanceBetweenPoints DESTINATION distance)
 
SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_NAME "coolprop")
SET(CPACK_DEBIAN_PACKAGE_VERSION "5.0") 
SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386") 
#SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libdl")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Jorrit Wronski <jowr@mek.dtu.dk>") #required

SET(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Fluid properties for the masses
 CoolProp is a C++ library that implements 
  - Pure and pseudo-pure fluid equations of state and transport properties for over 100 components
  - Mixture properties using high-accuracy Helmholtz energy formulations (or cubic EOS)
  - Correlations of properties for approximately 100 incompressible fluids and brines
  - Highest accuracy psychrometric routines")

SET(CPACK_DEBIAN_PACKAGE_SECTION "science")

SET(DEBIAN_PACKAGE_BUILDS_DEPENDS "debhelper (>> 5.0.0)")
SET(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "debian.src/postinst;")
 
INCLUDE(CPack)
 
# To use this:
# cmake $SRC
# make package
# sudo dpkg -i DistanceBetweenPoints-0.1.1-Linux.deb
 
# This will result in the file:
#/usr/distance/DistanceBetweenPoints