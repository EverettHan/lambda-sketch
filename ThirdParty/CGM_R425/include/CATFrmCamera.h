#ifndef CATFrmCamera_H 
#define CATFrmCamera_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//------------------------------------------------------------------------------
// Abstract: Implementation of CATICamera
//
//------------------------------------------------------------------------------
// Usage:    Internal Only!
//------------------------------------------------------------------------------

#include "CATAfrFoundation.h"
#include "CATBaseUnknown.h"
#include "CATICamera.h"
#include "CATUnicodeString.h"

/**
 * deprecated V5R16
 * <br>Instead, use the factory @href CATCreateDefaultCamera in CATCameraToolkit to create a camera and
 * the APIs of the interface @href CATICamera
 * <br>Implementation class of the CATICamera interface.
 * <br><b>Role</b>:This implementation class (can not be instanciated) provides 
 * the basic methods to manage the name and the type of a camera.
 * @see CATICamera
 */
class ExportedByCATAfrFoundation CATFrmCamera: public CATBaseUnknown
{
//------------------------------------------------------------------------------
      CATDeclareClass;

   public:


      // Destructor
      // ----------
      virtual ~CATFrmCamera();

      // CATICamera data
      // ---------------
/**
 * Returns the name of a camera.
 */
      virtual CATUnicodeString & GetName();
/**
 * Changes the name of a camera.
 * @param iName
 *    New name of the camera.
 */
      virtual void             SetName(const CATUnicodeString & iName);

/**
 * Returns the type of a camera. 
 * @see CATCameraType
 */
      virtual CATCameraType    GetType();

  /** @nodoc */
      virtual void WriteToStream(void ** stream, CATULONG32& length)=0;
  /** @nodoc */
      virtual void ReadFromStream(void * stream, CATULONG32  length)=0;

/**
 * Makes a camera identical with another one in copying all its parameters.
 * @param iCamera
 *    camera to copy.
 */
      virtual void CopyFrom(CATICamera * iCamera)=0;

   protected:

      /** nodoc */
      CATCameraType            _cameraType;

      // Protected Constructor
      // ---------------------
      /** nodoc */
      CATFrmCamera(CATUnicodeString name, CATCameraType type);

   private:

      CATUnicodeString         _cameraName;
}; 
#endif
