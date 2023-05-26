#ifndef GOEOptimizableParameterValue_H
#define GOEOptimizableParameterValue_H

// COPYRIGHT DASSAULT SYSTEMES 2007

#include "GraphicsOptimizer.h"
#include "CATErrorDef.h"
#include "CATUnicodeString.h"

/**
 * This is the Graphics Optimizable Parameter Value class.
 * This class is used to store the value associated to an Optimizable Parameter. 
 * You should not use this class directly but one of its sub-classes.
 */
class ExportedByGraphicsOptimizer GOEOptimizableParameterValue
{
public:

  /**
   * Destructor.
   */
  virtual ~GOEOptimizableParameterValue();

  /**
   * Call this method to compare two @href GOEOptimizableParameterValue.
   */
  virtual CATBoolean IsEqual(const GOEOptimizableParameterValue* ipValue) const = 0;

  /**
   * Do not call this method as it is used for internal purposes.
   */
  virtual HRESULT SetToAdminValue() = 0;

  /**
   * Call this method to retrieve the unsigned int value contained in one instance of this class.
   */
  virtual HRESULT GetValue(unsigned int& oValue) const = 0;

  /**
   * Call this method to modify the unsigned int value contained in one instance of this class.
   */
  virtual HRESULT SetValue(const unsigned int& iValue) = 0;

  /**
   * Call this method to retrieve the float value contained in one instance of this class.
   */
  virtual HRESULT GetValue(float& oValue) const = 0;

  /**
   * Call this method to modify the float value contained in one instance of this class.
   */
  virtual HRESULT SetValue(const float& iValue) = 0;

  /**
   * Call this method to retrieve the color value contained in one instance of this class.
   */
  virtual HRESULT GetValue(unsigned int& oRed, unsigned int& oGreen, unsigned int& oBlue) const = 0;

  /**
   * Call this method to modify the color value contained in one instance of this class.
   */
  virtual HRESULT SetValue(const unsigned int& iRed, const unsigned int& iGreen, const unsigned int& iBlue) = 0;

  /**
   * Call this method to intialize the value specified as input parameter with the one contained inside
   * the instance of this class.
   * Warning! The returned @href GOEOptimizableParameterValue is allocated in this method; it HAS TO BE DELETED by caller.
   */
  virtual HRESULT GetValue(GOEOptimizableParameterValue** opValue) const = 0;

  /**
   * Call this method to modify the value contained inside the instance of this class with the one specified 
   * as input parameter.
   */
  virtual HRESULT SetValue(GOEOptimizableParameterValue* ipValue) = 0;

  /**
   * This method is called to initialize the parameter value with information stored in settings file.
   * The @href CATUnicodeString provided as input parameter is used as a key in the settings file.
   */
  virtual HRESULT ReadValueFromSettings(const CATUnicodeString& iKeyName) = 0;

  /**
   * This method is called to write the parameter value in settings file.
   * The @href CATUnicodeString provided as input parameter is used as a key in the settings file.
   */
  virtual HRESULT WriteValueInSettings(const CATUnicodeString& iKeyName) = 0;

protected:

  /**
   * Constructor.
   * This method is protected so that only inherited classes can call it.
   */
  GOEOptimizableParameterValue();

private:

  /**
  * Copy not allowed.
  */
  GOEOptimizableParameterValue(const GOEOptimizableParameterValue&);
  GOEOptimizableParameterValue& operator=(const GOEOptimizableParameterValue&);
};

//------------------------------------------------------------------

#endif
