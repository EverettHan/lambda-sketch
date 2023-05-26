#ifndef CATICAMERA_H
#define CATICAMERA_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

//===========================================================================
// General Interface for Viewpoint Manipulation
//===========================================================================

#include "CATVisItf.h"
#include "CATBaseUnknown.h"
#include "CATDataType.h"
#include "CATViewerUtility.h"

class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATICamera;
#else
extern "C" const IID IID_CATICamera;
#endif
/** 
 * interface to make viewpoint persistent.
 * <b>Role</b>:
 * This is the base interface to create a persistent viewpoint.
 * It provides the basic methods to manage the name and type of camera.
 */
class  ExportedByCATVisItf CATICamera : public CATBaseUnknown
{
   CATDeclareInterface;

   public:
      // Name and type of camera
/**
 * Returns the name of the camera.
 */
      virtual CATUnicodeString & GetName() =0;
/**
 * Changes the name of the camera.
 * @param iName
 *    New name of the camera.
 */
      virtual void             SetName(const CATUnicodeString & iName)=0;

/**
 * Returns the type of the camera. 
 * @return 
 *   <li><tt>CAT3DConicCamera</tt> for a 3D perspective projection</li>
 *   <li><tt>CAT3DCylindricCamera</tt> for a 3D parallel projection</li>.
 *   <li><tt>CAT3DUnknownCamera</tt> for any type of 3D projection</li>
 *   <li><tt>CAT2DCamera</tt> for a 2D view</li>.
 * @see CATCameraType
 */
      virtual CATCameraType    GetType() =0;

      // Persistence
  /** @nodoc */
      virtual void WriteToStream(void ** stream, CATULONG32& length) =0;
  /** @nodoc */
      virtual void ReadFromStream(void * stream, CATULONG32  length) =0;

/**
 * Makes a camera identical with another one in copying all its parameters.
 * @param iCamera
 *    The camera to copy.
 */
      virtual void CopyFrom(CATICamera * iCamera)=0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------
CATDeclareHandler(CATICamera, CATBaseUnknown);

#endif
