#ifndef INCL_IConnectionPointContainerImpl_h
#define INCL_IConnectionPointContainerImpl_h

//
// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
// Nov. 99   Creation
//=============================================================================
//
// Author: JDU
/**
 * This class is the base class of a COM component which provides a 
 * IConnectionPointContainer generic implementation.
 * The component is meant to be COM-aggregate by another component which 
 * needs to broadcast events. The other component must implement
 * CATIConnectionPointContainerInit.
 * The component per se does not do anything (aside from having a CLSID and 
 * being CATCreateInstantiable). It relies on the 
 * CATIConnectionPointContainerImpl extension to deliver its functionalities.
 */

#include "CATBaseUnknown.h"

class IConnectionPointContainerImpl : public CATBaseUnknown {
	CATDeclareClass;

    public:
		IConnectionPointContainerImpl();
		~IConnectionPointContainerImpl();
};

/* dcf63ea4-95f7-11d3-b80a-0008c70fc870 */
extern "C" const CLSID CLSID_IConnectionPointContainerImpl;

#endif
