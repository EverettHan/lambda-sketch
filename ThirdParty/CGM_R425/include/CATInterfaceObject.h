/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000
/** @CAA2Required */
//**********************************************************************
//* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS *
//* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME *
//**********************************************************************

#ifndef CAT_INTERFACE_OBJECT_H
#define CAT_INTERFACE_OBJECT_H

///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........Object Modeler                                      //
//    AUTEUR:............Jean-Louis MALAVAL                                  //
//    DATE:..............15/03/1996                                          //
//             -----------------------------------------------               //
//    AUTEUR:............Jean-Louis MALAVAL                                  //
//    MODIF:.............New TIE management                                  //
//    DATE:..............05/11/1996                                          //
//                                                                           //
//    AUTEUR:............                                                    //
//    MODIF:.............                                                    //
//    DATE:..............  /  /1996                                          //
///////////////////////////////////////////////////////////////////////////////

// ==========================================================================
//                Definition of the basic Interface class
//
//          All user interfaces have to inherit from this class
// ==========================================================================

// --------------------------------------------------------------------------
//                         Export for Window NT
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
//                              System
// --------------------------------------------------------------------------

#include <CATIOStream.h>
#include <stddef.h>

// --------------------------------------------------------------------------
//                         Set Interface Mode
// --------------------------------------------------------------------------

#include "CATBaseUnknown.h"

#include "CATMacForIUnknown.h"

// --------------------------------------------------------------------------
//                          Traces for Debug
// --------------------------------------------------------------------------


// --------------------------------------------------------------------------
//                       Preliminary declarations
// --------------------------------------------------------------------------



//===================================================================================
//              CATInterfaceObject :  D E C L A R A T I O N S
//===================================================================================

// WARNING : in System Framework for compatibility with former version we have the following typedefs
// System - OM family affair :
//typedef CATBaseUnknown          CATInterfaceObject ;   
//typedef CATBaseUnknown_var      CATInterfaceObject_var ;     
//typedef CATBaseUnknown*         CATInterfaceObject_ptr ;
//typedef CATBaseUnknown*         CATBaseUnknown_ptr ; 
// For convenient redirection to base CNEXT classes
//#define AddRefForPtr            AddRef 
//#define ReleaseForPtr           Release
//For Collections and sequence compatibility between CATInterfaceObject und CATBaseUnknown (UnGewissenedItem..Doch!!)
//#define CATListValCATInterfaceObject_var CATListValCATBaseUnknown_var
//#define _SEQUENCE_CATInterfaceObject_ptr _SEQUENCE_CATBaseUnknown_ptr
//#define CATListPtrCATInterfaceObject     CATListPtrCATBaseUnknown 

#endif
