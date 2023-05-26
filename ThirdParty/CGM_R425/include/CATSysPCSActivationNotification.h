#ifndef CATSysPCSActivationNotification_h
#define CATSysPCSActivationNotification_h

// COPYRIGHT DASSAULT SYSTEMES 2004
//   
//===========================================================================
//  Abstract of the class:
//  ----------------------
//
//  PCS Activation Notification class.
//
//===========================================================================
//  Inheritance:
//  ------------
//            CATNotification  ( System Framework)
//               CATBaseUnknown (System Framework).
//
//===========================================================================

// System Framework
#include "CATNotification.h"    // Needed to derive from CATNotification
#include "JS03TRA.h"

class CATSysPCSActivationNotification : public CATNotification
{
  // Used in conjunction with CATImplementClass in the .cpp file 
  CATDeclareClass;
  
  public:

    CATSysPCSActivationNotification();
    virtual ~CATSysPCSActivationNotification();

  private:
    
    // Copy constructor, not implemented
    // Set as private to prevent from compiler automatic creation as public.
    CATSysPCSActivationNotification(const CATSysPCSActivationNotification &iObjectToCopy);

    // Assignment operator, not implemented
    // Set as private to prevent from compiler automatic creation as public.
    CATSysPCSActivationNotification & operator = (const CATSysPCSActivationNotification &iObjectToCopy);
     
};

// to set and get the 2 parameters to transmit from client to server
HRESULT ExportedByJS03TRA CATSysPCSGetActivation (int *oLevel1, int *oLevel2);
HRESULT ExportedByJS03TRA CATSysPCSSetActivation (int iLevel1, int iLevel2);

#endif
