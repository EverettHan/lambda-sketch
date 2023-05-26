//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2013/08/13
//===================================================================
// CATSYPTweakerFactory.h
// Header definition of class CATSYPTweakerFactory
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2013/08/13 Creation: Code generated by the 3DS wizard  VV6
//===================================================================

#ifndef CATSYPTweakerFactory_H
#define CATSYPTweakerFactory_H

#include <IntroInfra.h>
#include <CATUnicodeString.h>
#include <CATString.h>

class CATSYPTweaker;
class CATSYPPropertyDescriptorEx;

/**
 * Factory class for the CATSYPTweaker objects.
 *
 * This class offers the capacity to build the corresponding CATSYPTweaker
 * object depending on a data type.
 */
class ExportedByIntroInfra CATSYPTweakerFactory
{

public:

  /**
   * Build the CATSYPTweaker corresponding to the given type of data.
   *
   * @param i_propertyType type of data for which a tweaker must be built.
   *
   * @return the built tweaker or NULL in case of failure.
   */
  static CATSYPTweaker * Create(const CATUnicodeString& i_typeName, 
                                            const CATString & i_pIdentifier= "", 
                                            const CATUnicodeString& i_tweakType = "",
                                            CATSYPPropertyDescriptorEx * i_pPropertyDescriptorEx = NULL,
                                            const CATUnicodeString& i_tweakClassName="");

private:
  // Default constructor and destructor are not implemented
  CATSYPTweakerFactory();
  ~CATSYPTweakerFactory();
  // Copy constructor and assignement operator are not implemented
  CATSYPTweakerFactory(const CATSYPTweakerFactory &);
  CATSYPTweakerFactory& operator= (const CATSYPTweakerFactory &);

};

#endif