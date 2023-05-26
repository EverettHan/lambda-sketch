#ifndef CATSYPCommandCallbackDescriptor_H
#define CATSYPCommandCallbackDescriptor_H

#include <IntroInfra.h>
#include <CATUnicodeString.h>
#include <CATCommand.h>
#include <CATSYPDescriptorBase.h>
#include <UIVCoreToolsInline.h>

/**
* Data class containing the description of a command callback.
* <b>Role</b>: Used by introspection mechanisms. 
* Recovered from a CATISYPIntrospectable.
*/
class ExportedByIntroInfra CATSYPCommandCallbackDescriptor : public CATSYPDescriptorBase
{
public:

  /** Constructor. */
  CATSYPCommandCallbackDescriptor();

  /** Destructor. */
  virtual ~CATSYPCommandCallbackDescriptor();

  /** Constructor 
   * @param i_name name of the command callback.
   * @param i_pCommandCallbackFunc the command callback method as a CATCommandMethod.
   */
  CATSYPCommandCallbackDescriptor(const CATUnicodeString& i_name, CATCommandMethod i_pCommandCallbackFunc);

  /** 
   * Copy Constructor.
   * @param i_toCopy the CATSYPCommandCallbackDescriptor to copy
   */
  CATSYPCommandCallbackDescriptor(const CATSYPCommandCallbackDescriptor & i_toCopy);

  /** 
   * Assignement operator. 
   */
  CATSYPCommandCallbackDescriptor& operator=(const CATSYPCommandCallbackDescriptor & i_toCopy);

  /**
    * Get the name of the command callback method.
    *
    * @return the name of the command callback method.
    */
  const CATUnicodeString& GetName () const{return _name;}
   /**
   * Get the command callback function as a CATCommandMethod.
   *
   * @return the CATCommandMethod.
   */
  const CATCommandMethod GetCommandCallbackFunc() const{return _pCommandCallbackFunc;}

private:

  /** Name of the CATCommandMethod. */
  CATUnicodeString _name;
  /** The CATCommandMethod points directly on the command callback method */
  CATCommandMethod _pCommandCallbackFunc;
};


#endif
