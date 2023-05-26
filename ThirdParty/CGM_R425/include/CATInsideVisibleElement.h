#ifndef CATInsideVisibleElement_h
#define CATInsideVisibleElement_h

#include "CATVisController.h"

//
// CATIA Version 5 Release 1 Framework Model
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
//  Abstract : contains visible elements which bounding sphere is
//             completely enclosed within the viewing volume.
//            
//              
//             
//------------------------------------------------------------------------------
//  Usage :     used to ask for visible elements
//
//------------------------------------------------------------------------------
//  Inheritance : CATInsideVisibleElement
//                 CATSO
//                  CATCallbackManager (Framework System)
//------------------------------------------------------------------------------

#include "CATSO.h"

class ExportedByCATVisController CATInsideVisibleElement : public CATSO
{
  CATDeclareClass;
};

#endif
