/* -*-c++-*- */

#ifndef CATExtIVisProperties_H
#define CATExtIVisProperties_H

//
// COPYRIGHT DASSAULT SYSTEMES 1999
//

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATExtIBasicVisProperties.h"
#include "list.h"
#include "CATUnicodeString.h"

#include "CATGraphicProperties.h"

/**
* Adapter for the CATIVisProperties interface.
* @see  CATIVisProperties
*/
class ExportedByCATGraphicProperties CATExtIVisProperties : public CATExtIBasicVisProperties
{

  CATDeclareClass;
public:

  /** 
  * Constructor.
  */
  CATExtIVisProperties ();

  virtual ~CATExtIVisProperties ();


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

  /**
  * Gives the appropriated sub type and property number to read/write.
  * <br><b>Role</b>: 
  * @param iPathElement
  *   Precise the environement of the object 
  *   you want to modify its graphic properties.
  * @param iPropertyType
  *   The type of property to read or write.
  * @param oGeomType
  *   Return the geometrical sub-type.
  * @param oPropertyNumber
  *   Return the property number to use (default value is 0).
  * @return
  * <dt><tt>S_OK</tt>
  * <dd>
  * <dt><tt>E_FAIL</tt>
  * <dd>
  * </dl>
  */
  virtual HRESULT GetSubTypeFromPath(CATPathElement     & iPathElement,
                                     CATVisPropertyType   iPropertyType,
                                     CATVisGeomType     & oGeomType,
                                     unsigned int       & oPropertyNumber );

 /**
  * Asks if a given geometry type is defined.
  * @param iGeomType
  *   The geometrical type
  * @return
  *  <b>Legal value</b>:
  * <dl>
  * <dt><tt>S_OK</tt>
  * <dd>iGeomType is defined for the object.
  * <dt><tt>E_FAIL</tt>
  * <dd>iGeomType isn't defined for the object.
  * </dl>
  */
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

protected:

  /** @nodoc */
  virtual HRESULT SetOneProperty    ( CATVisPropertiesValues& iValue,
                                      CATVisPropertyType iPropertyType,
                                      CATPathElement & iPathElement,
                                      int iNotify = 1 );
  /** @nodoc */
  virtual HRESULT ResetOneProperty ( CATVisPropertyType iPropertyType,
                                     CATPathElement & iPathElement, 
                                     int iNotify = 1 );
  /** @nodoc */
  virtual HRESULT GetOneProperty    ( CATVisPropertiesValues& ioValue,
                                      CATVisPropertyType iPropertyType,
                                      CATPathElement & iPathElement );
  /** @nodoc */
  virtual HRESULT GetOneStandardProperty (  CATVisPropertiesValues& ioValues,
                                            CATVisPropertyType iPropertyType,
                                            CATVisGeomType iGeomType );
  /** @nodoc */
  virtual HRESULT SetOnePropertyAtt ( CATVisPropertiesValues& iValues,
                                      CATVisPropertiesValues& oValues,
                                      CATVisPropertyType iPropertyType,
                                      int fromSetProperties = 0 );
  /** @nodoc */
  virtual HRESULT ResetOnePropertyAtt   ( CATVisPropertiesValues& oValues,
                                          CATVisPropertyType iPropertyType,
                                          int fromResetProperties = 0  );
  /** @nodoc */
  virtual HRESULT GetOnePropertyAtt ( CATVisPropertiesValues& iValues,
                                      CATVisPropertiesValues& oValues,
                                      CATVisPropertyType iPropertyType,
                                      int fromGetProperties = 0 );
  /** @nodoc */
  virtual HRESULT GetPropertyName ( CATVisGeomType iGeomType, CATUnicodeString& oName);

  /** @nodoc */
  void ActivatePropertyOwner();

  /** @nodoc */
  void DesactivatePropertyOwner();

  /** @nodoc */
  virtual int IsPropertyOwnerActivated();

  /** @nodoc */
  virtual HRESULT IsPropertyDefined(CATVisGeomType iGeomType, CATVisPropertyType type);

private:

  HRESULT ReadAttributs ( CATVisGeomType iGeomType, list<CATVisPropertiesValues>& oValues);
 
  HRESULT WriteAttributs (CATVisGeomType iGeomType, list<CATVisPropertiesValues>&  iValues, CATVisPropertyType iPropertyType);
  
  HRESULT SendNotification ( CATPathElement & iPathElement, CATVisPropertyType iPropertyType,
                             CATVisGeomType iGeomType, unsigned int iPropertyNumber);

  CATIVisPropertiesAbstract* GetNoShowOwner (CATPathElement & iPathElement);

  //------------------------------------------------
  // migration objet < R3 (uniquement en mode ODT)
  //------------------------------------------------
  HRESULT FindLastProperties();
  HRESULT ReadLastAttributs ( CATVisGeomType iGeomType, list<CATVisPropertiesValues>& oValues);
  HRESULT MigrateProperty();
  
  // flag pour voir si l'on a des nouvelles proprietes graphiques sur l'objet
  unsigned int _migrated : 1;

  // flag pour voir si l'on a des anciennes proprietes graphiques sur l'objet
  unsigned int _lastProperty:1;


  unsigned int _isPropertyOwnerActivated:1;

  unsigned int _renderingStyle : 4;
  unsigned int _renderingStyleSet : 1;
};


#endif // CATExtIVisProperties_H
