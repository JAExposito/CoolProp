/**
This file contains flash routines in which the state is unknown,
and a solver of some kind must be used to obtain temperature and
density, the two state variables upon which the equation of 
state is based.
*/

// ***************************************************************
// *******************  FLASH ROUTINES  **************************
// ***************************************************************

#ifndef FLASHROUTINES_H
#define FLASHROUTINES_H

#include "HelmholtzEOSMixtureBackend.h"

namespace CoolProp{

/**
This class is a friend class of HelmholtzEOSMixtureBackend, therefore the 
static methods contained in it have access to the private and
protected variables in the HelmholtzEOSMixtureBackend instance.

In this way the Flash routines can be kept in their own separate file
and not pollute the HelmholtzEOSMixtureBackend namespace
*/
class FlashRoutines{
public:

    /// Flash for given pressure and (molar) quality
    /// @param HEOS The HelmholtzEOSMixtureBackend to be used
    static void PQ_flash(HelmholtzEOSMixtureBackend &HEOS);
    
    /// Flash for given temperature and (molar) quality
    /// @param HEOS The HelmholtzEOSMixtureBackend to be used
    static void QT_flash(HelmholtzEOSMixtureBackend &HEOS);
    
    /// Flash for given pressure and temperature
    /// @param HEOS The HelmholtzEOSMixtureBackend to be used
    static void PT_flash(HelmholtzEOSMixtureBackend &HEOS);
    
    /// A generic flash routine for the pairs (T,D), (T,H), (T,S), and (T,U).  Similar analysis is needed
    /// @param HEOS The HelmholtzEOSMixtureBackend to be used
    /// @param other The index for the other input, see CoolProp::parameters; allowed values are iDmolar, iHmolar, iSmolar, iUmolar
    static void DHSU_T_flash(HelmholtzEOSMixtureBackend &HEOS, int other);
    
    /// A generic flash routine for the pairs (P,H), (P,S), and (P,U).  Similar analysis is needed
    /// @param HEOS The HelmholtzEOSMixtureBackend to be used
    /// @param other The index for the other input, see CoolProp::parameters; allowed values are iHmolar, iSmolar, iUmolar
    static void HSU_P_flash(HelmholtzEOSMixtureBackend &HEOS, int other);
    
    /// A generic flash routine for the pairs (D,P), (D,H), (D,S), and (D,U).  Similar analysis is needed
    /// @param HEOS The HelmholtzEOSMixtureBackend to be used
    /// @param other The index for the other input, see CoolProp::parameters; allowed values are iP, iHmolar, iSmolar, iUmolar
    static void PHSU_D_flash(HelmholtzEOSMixtureBackend &HEOS, int other);
};

} /* namespace CoolProp */
#endif /* FLASHROUTINES_H */