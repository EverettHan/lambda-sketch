// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATSYPEnumFactory.h
// Header definition of CATSYPEnumFactory
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2009  Creation: jov
//===================================================================
#ifndef CATSYPEnumFactory_H
#define CATSYPEnumFactory_H


#include <CATSYPDeclareEnumFactory.h>
#include <CATSYPImplementEnumFactory.h>


#define CATSYP_ENUMFACTORY(I_ENUM_NAME, I_VALUES) \
  CATSYP_IMPLEMENT_ENUMFACTORY(I_ENUM_NAME, I_VALUES)
  
#define CATSYP_ENUMFACTORY_CUSTOM(I_ENUM_NAME, I_VALUES, I_CUSTOM_VALUES) \
  CATSYP_IMPLEMENT_ENUMFACTORY_CUSTOM(I_ENUM_NAME, I_VALUES, I_CUSTOM_VALUES)
  

#endif
