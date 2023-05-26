/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//==============================================================================
// Inheritance
// -----------
//	CATExtIV4VisProperties
//	   CATExtIVisProperties
//		  CATBaseUnknown
//
//==============================================================================
// Abstract
// --------
/**
 *    This interface defines the ability to define graphic properties on V4 elements
 *
 */
//
//==========================================================================


#ifndef CATExtIV4VisProperties_H
#define CATExtIV4VisProperties_H

#include "CATExtIBasicVisProperties.h"
#include "CATUnicodeString.h"

#include "SceneGraphManager.h"

class ExportedBySceneGraphManager CATExtIV4VisProperties : public CATExtIBasicVisProperties
{
public:

  // macros
  CATDeclareClass;

  CATExtIV4VisProperties ();

  ~CATExtIV4VisProperties ();


  virtual HRESULT SetPropertiesAtt   ( CATVisPropertiesValues& iValues,
                                       CATVisPropertyType iPropertyType,
                                       CATVisGeomType iGeomType = CATVPGlobalType,
                                       unsigned int iPropertyNumber     = 0,
                                       int fromSetProperties            = 0 );

  virtual HRESULT ResetPropertiesAtt ( CATVisPropertyType iPropertyType,
                                       CATVisGeomType iGeomType = CATVPGlobalType,
                                       unsigned int iPropertyNumber     = 0,
                                       int fromResetProperties          = 0 );

  virtual HRESULT GetPropertiesAtt   ( CATVisPropertiesValues& ioValues,
                                       CATVisPropertyType iPropertyType,
                                       CATVisGeomType iGeomType = CATVPGlobalType,
                                       unsigned int iPropertyNumber     = 0,
                                       int fromGetProperties            = 0 );

  virtual HRESULT SetProperties   ( CATVisPropertiesValues& iValues,
                                    CATVisPropertyType iPropertyType,
                                    CATPathElement & iPathElement,
                                    int iNotify = 1);


  virtual HRESULT ResetProperties ( CATVisPropertyType iPropertyType,
                                    CATPathElement & iPathElement, 
                                    int iNotify = 1);

  virtual HRESULT GetProperties   ( CATVisPropertiesValues& ioValues,
                                    CATVisPropertyType iPropertyType,
                                    CATPathElement & iPathElement );



  virtual HRESULT GetStandardProperties  ( CATVisPropertiesValues& ioValues,
                                           CATVisPropertyType iPropertyType,
                                           CATVisGeomType iGeomType = CATVPGlobalType);


  virtual HRESULT GetSubTypeFromPath(CATPathElement     & iPathElement,
                                     CATVisPropertyType   iPropertyType,
                                     CATVisGeomType     & oGeomType,
                                     unsigned int       & oPropertyNumber );


  virtual HRESULT IsGeomTypeDefined (CATVisGeomType& iGeomType);


  virtual CATIVisPropertiesAbstract * GetPropertyOwner ( CATVisPropertyAction iAction,
                                                         CATVisGeomType       iGeomType,
                                                         unsigned int         iPropertyNumber=0);

  
  virtual CATIModelEvents* FindSender (CATPathElement & iPathElement);


  virtual unsigned int GetPropertyNumber (CATVisGeomType iVisProperty);


  virtual HRESULT GetGraphicAttributSet ( CATGraphicAttributeSet&      oAttributSet,
                                          CATVisGeomType               iGeomType,
                                          unsigned int                 iPropertyNumber     = 0 );

  /** @nodoc */
  virtual HRESULT IsEditableBy(CATVisPropertyEditorType iEditorType);

protected:

  virtual HRESULT SetOneProperty    ( CATVisPropertiesValues& iValue,
                                      CATVisPropertyType iPropertyType,
                                      CATPathElement & iPathElement,
                                      int iNotify = 1 );

  virtual HRESULT ResetOneProperty ( CATVisPropertyType iPropertyType,
                                     CATPathElement & iPathElement, 
                                     int iNotify = 1 );

  virtual HRESULT GetOneProperty    ( CATVisPropertiesValues& ioValue,
                                      CATVisPropertyType iPropertyType,
                                      CATPathElement & iPathElement );

  virtual HRESULT GetOneStandardProperty (  CATVisPropertiesValues& ioValues,
                                            CATVisPropertyType iPropertyType,
                                            CATVisGeomType iGeomType );

  virtual HRESULT SetOnePropertyAtt ( CATVisPropertiesValues& iValues,
                                      CATVisPropertiesValues& oValues,
                                      CATVisPropertyType iPropertyType,
                                      int fromSetProperties = 0 );

  virtual HRESULT ResetOnePropertyAtt   ( CATVisPropertiesValues& oValues,
                                          CATVisPropertyType iPropertyType,
                                          int fromResetProperties = 0  );

  virtual HRESULT GetOnePropertyAtt ( CATVisPropertiesValues& iValues,
                                      CATVisPropertiesValues& oValues,
                                      CATVisPropertyType iPropertyType,
                                      int fromGetProperties = 0 );

  virtual HRESULT IsPropertyDefined(CATVisGeomType iGeomType, CATVisPropertyType type);

private :
	HRESULT ReadAttributs ( CATVisGeomType iGeomType, CATVisPropertiesValues& oValues);
	HRESULT WriteAttributs (CATVisGeomType iGeomType, CATVisPropertiesValues&  iValues);
	CATVisPropertiesValues * GetValue (CATVisGeomType geomtype);

	HRESULT SendNotification ( CATPathElement & iPathElement, CATVisPropertyType iPropertyType,
                             CATVisGeomType iGeomType, unsigned int iPropertyNumber);
	CATIVisPropertiesAbstract* GetNoShowOwner (CATPathElement & iPathElement);

	CATVisPropertiesValues * asmValue_;
	CATVisPropertiesValues * edgeValue_;
	CATVisPropertiesValues * meshValue_;
	CATVisPropertiesValues * lineValue_;
	CATVisPropertiesValues * pointValue_;

	// juste un pointeur sur la value qui contient les valeurs globales
	CATVisPropertiesValues * globalValue_;
};

#endif

