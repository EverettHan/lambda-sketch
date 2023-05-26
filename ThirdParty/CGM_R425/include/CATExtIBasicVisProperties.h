/* -*-c++-*- */

#ifndef CATExtIBasicVisProperties_H
#define CATExtIBasicVisProperties_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// COPYRIGHT DASSAULT SYSTEMES 2003
//


#include "CATIVisProperties.h"
#include "CATUnicodeString.h"

#include "CATVisItf.h"

/**
* Base class for CATIVisProperties Adapter.
* <b> Role:</b> Base class for CATIVisProperties Adapter. All its methods are empty.
*/
class ExportedByCATVisItf CATExtIBasicVisProperties : public CATIVisProperties
{  
	CATDeclareClass;

public:

  /** @nodoc */
  CATExtIBasicVisProperties ();

   /** @nodoc */
  virtual ~CATExtIBasicVisProperties ();


  /** @nodoc */
  virtual HRESULT SetProperties   ( CATVisPropertiesValues& iValues,
                                    CATVisPropertyType iPropertyType,
                                    CATPathElement & iPathElement,
                                    int iNotify = 1);

  /** @nodoc */
  virtual HRESULT ResetProperties ( CATVisPropertyType iPropertyType,
                                    CATPathElement & iPathElement, 
                                    int iNotify = 1);
  /** @nodoc */
  virtual HRESULT GetProperties   ( CATVisPropertiesValues& ioValues,
                                    CATVisPropertyType iPropertyType,
                                    CATPathElement & iPathElement );


  /** @nodoc */
  virtual HRESULT SetPropertiesAtt   ( CATVisPropertiesValues& iValues,
                                       CATVisPropertyType iPropertyType,
                                       CATVisGeomType iGeomType = CATVPGlobalType,
                                       unsigned int iPropertyNumber     = 0,
                                       int fromSetProperties            = 0 );
  /** @nodoc */
  virtual HRESULT ResetPropertiesAtt ( CATVisPropertyType iPropertyType,
                                       CATVisGeomType iGeomType = CATVPGlobalType,
                                       unsigned int iPropertyNumber     = 0,
                                       int fromResetProperties          = 0 );

  /** @nodoc */
  virtual HRESULT GetPropertiesAtt   ( CATVisPropertiesValues& ioValues,
                                       CATVisPropertyType iPropertyType,
                                       CATVisGeomType iGeomType = CATVPGlobalType,
                                       unsigned int iPropertyNumber     = 0,
                                       int fromGetProperties            = 0 );


  /** @nodoc */
  virtual HRESULT GetStandardProperties  ( CATVisPropertiesValues& ioValues,
                                           CATVisPropertyType iPropertyType,
                                           CATVisGeomType iGeomType = CATVPGlobalType);

  /** @nodoc */
  virtual HRESULT GetSubTypeFromPath(CATPathElement     & iPathElement,
                                     CATVisPropertyType   iPropertyType,
                                     CATVisGeomType     & oGeomType,
                                     unsigned int       & oPropertyNumber );
  /** @nodoc */
  virtual HRESULT IsGeomTypeDefined (CATVisGeomType& iGeomType);

  /** @nodoc */
  virtual CATIVisPropertiesAbstract * GetPropertyOwner ( CATVisPropertyAction iAction,
                                                         CATVisGeomType       iGeomType,
                                                         unsigned int         iPropertyNumber=0);

  /** @nodoc */
  virtual CATIModelEvents* FindSender (CATPathElement & iPathElement);

  /** @nodoc */
  virtual unsigned int GetPropertyNumber (CATVisGeomType iVisProperty);

  /** @nodoc */
  virtual HRESULT GetGraphicAttributSet ( CATGraphicAttributeSet&      oAttributSet,
                                          CATVisGeomType               iGeomType,
                                          unsigned int                 iPropertyNumber     = 0 );
  /** @nodoc */
  virtual HRESULT IsEditableBy(CATVisPropertyEditorType iEditorType);
};


#endif // CATExtIBasicVisProperties_H
