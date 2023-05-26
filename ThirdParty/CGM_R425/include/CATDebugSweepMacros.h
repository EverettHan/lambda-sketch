/* -*-c++-*- */
#ifndef CATDebugSweepMacros_H_
#define CATDebugSweepMacros_H_

// The macros in this file are those used in header files that use the BEGIN/END/THROWFUNC 
// macros in SweepRelimit. This is to prevent unnecessary leakage of macros into other classes.
// Define CATDEBUG here to enable sweep debug (CATDebugSweep.h)
//#define CATDEBUG

#ifdef CATDEBUG
// VARSFORTRACE defines the data members required for the macros. The argument describes
// whether this trace method is to be switched on for this class.
// CARSFORTRACESUBCLASS just defined whether the method is switched on for this class,
// as the data members are defined in the base class.
// It is also necessary to initialise _CallLevel to 0 in the base class constructors.

// Activate traces with
// set StraSweep=1 for the extrusion traces
// set StraRelimit=1 for the relimit traces
// set StraGraph=1 for the graph traces
// set StraNaming=1 for the Naming debug

#define VARSFORTRACE(on) \
   protected: \
CATLONG32 _CallLevel; \
   static const CATBoolean _onForClass = CATBoolean(on);
#define VARSFORTRACESUBCLASS(on) \
   static const CATBoolean _onForClass = CATBoolean(on);

#else
#define VARSFORTRACE(on)
#define VARSFORTRACESUBCLASS(on)
#endif

#endif
