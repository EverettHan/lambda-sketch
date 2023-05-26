#ifndef CATMMCPROPERTYVALUEBASE_H
#define CATMMCPROPERTYVALUEBASE_H

#include "CATMMediaCore.h"
#include "CATMMCReturnCode.h"
#include "CATUnicodeString.h"
//@MMNJNinf @QDesc: Base class for supported values
//@MMNJNinf @FDesc: Base class for values supported in properties.

class ExportedByCATMMediaCore CATMMCPropertyValueBase
{
public:
  /**
   * Constructor.
   */
  CATMMCPropertyValueBase();

  /**
   * Copy constructor.
   **/
  CATMMCPropertyValueBase(const CATMMCPropertyValueBase&);

  /**
   * Desctructor
   */
  virtual ~CATMMCPropertyValueBase();

  /**
   * Gets the type of value of CATMMCPropertyValueBase
   * @return a string defining the type of CATMMCPropertyValueBase
   */
  virtual CATUnicodeString     GetType()     const;

  /**
   * Returns a copy of CATMMCPropertyValueReal
   * @return a pointer on created CATMMCPropertyValueBase. Pointer has to be deleted.
   */
  virtual CATMMCPropertyValueBase*  Duplicate()   const;

  /**
   * Applies the value from a CATMMCPropertyValueBase.
   * @param iPropertyValue the CATMMCPropertyValueBase to get the value of type T from.
   * @return if CATMMCPropertyValueBase is of the same type, and its value set with new one, return CATMmRCOK, CATMmRcFailed otherwise.
   */
  virtual CATMmRC                   SetValueFromProperty(const CATMMCPropertyValueBase& iPropertyValue);

  /**
   * Check that both values have same types and values.
   * @param iPropertyValue the CATMMCPropertyValueBase to check its type and value.
   * @return if CATMMCPropertyValueBase is of the same type and value, return TRUE, FALSE otherwise.
   */
  virtual bool                      IsPurelyIdenticalTo(const CATMMCPropertyValueBase& iPropertyValue) const;
protected:
  CATMMCPropertyValueBase&          operator=(const CATMMCPropertyValueBase&);
};



#endif
