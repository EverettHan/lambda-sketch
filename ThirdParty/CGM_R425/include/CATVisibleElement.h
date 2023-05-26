#ifndef CATVisibleElement_h
#define CATVisibleElement_h

#include "CATVisController.h"

//
// CATIA Version 5 Release 1 Framework Model
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
//  Abstract : contains visible elements
//            
//              
//             
//------------------------------------------------------------------------------
//  Usage :     used to ask for visible elements
//
//------------------------------------------------------------------------------
//  Inheritance : CATVisibleElement
//                 CATSO
//                  CATCallbackManager (Framework System)
//------------------------------------------------------------------------------

#include "CATSO.h"

class ExportedByCATVisController CATVisibleElement : public CATSO
{
  CATDeclareClass;
};

#endif
