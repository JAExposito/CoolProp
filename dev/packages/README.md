The CoolProp packages
---------------------

This directory contains special files needed to generate the CoolProp packages. We use CPack and the subdirectories
if this folder are all named like the CPackPackageGenerators they belong to. 

 - There is *ZIP* to create a distributable version of the source code. 
 - *NSIS* builds a Windows installer with the shared library and some wrappers. 
 - *Bundle* does the same on OSX
 - *DEB* is our Linux packager
 
