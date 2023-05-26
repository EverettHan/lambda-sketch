#ifndef CATISavedMesh_H
#define CATISavedMesh_H

//****************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1998
//****************************************************************
//  Abstract:
//  ---------
//    Interface defining access to Graphic primitives 
//
//****************************************************************
//  Usage:
//  ------
//
//  the gp beyond to the interface. she is destroyed when the
//  interface is deleted or when the element is invalided
//
//****************************************************************
//  Main Methods:
//  -------------
//
//     GetPrimitive()
//     SetPrimitive()
//     InvalidePrimitive()
//
//****************************************************************

#include "CATVisItf.h"
#include "CATBaseUnknown.h"

class CAT3DLineGP;
class CATGraphicPrimitive;
class CATTessSettings;
class CATTopObject;

#include "CATGeomType.h"
#include "CATBodyIdentificators.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATVisItf IID IID_CATISavedMesh;
#else
extern "C" const IID IID_CATISavedMesh;
#endif

#include "CATErrorDef.h"

/*
 *  Values are 32 bit values layed out as follows:
 *
 *   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
 *   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *  +---+-+-+-----------------------+-------------------------------+
 *  |Sev|C|R|     Facility          |               Code            |
 *  +---+-+-+-----------------------+-------------------------------+
 *
 *  where
 *      Sev - is the severity code
 *
 *          00 - Success
 *          01 - Informational
 *          10 - Warning
 *          11 - Error
 *
 *      C - is the Customer code flag
 *      R - is a reserved bit
 *      Facility - is the facility code
 *      Code - is the facility's status code
 *
 *  MAKE_HRESULT(Severity, Factory, Code)
 */

#define FACILITY_CACHE 12


#define S_CACHED                       MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_CACHE, 0x200)
#define S_FACE_CACHED                  MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_CACHE, 0x201)
#define S_WIRE_CACHED                  MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_CACHE, 0x202)
#define S_EDGE_CACHED                  MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_CACHE, 0x203)
#define S_VERTEX_CACHED                MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_CACHE, 0x204)
#define S_CGR_CACHED                   MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_CACHE, 0x205)

#define W_EDGE_CACHED_ON_MASTER_FACE1  MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_CACHE, 0x206)
#define W_EDGE_CACHED_ON_MASTER_FACE2  MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_CACHE, 0x207)

#define E_NOTCACHED                    MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_CACHE, 0x300)
#define E_FACE_NOTCACHED               MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_CACHE, 0x301)
#define E_WIRE_NOTCACHED               MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_CACHE, 0x302)
#define E_EDGE_NOTCACHED               MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_CACHE, 0x303)
#define E_VERTEX_NOTCACHED             MAKE_HRESULT(SEVERITY_ERROR,   FACILITY_CACHE, 0x304)

class ExportedByCATVisItf CATISavedMesh : public CATBaseUnknown
{
  CATDeclareInterface;
  
  public:
    
    //
    // you must duplicate the primitive in your application
    //
    virtual HRESULT GetPrimitive(CATTopObject * iContext,
                                 const CATTessSettings& iSettings,
                                 const char  iUserData,
                                 CATGraphicPrimitive * & oGP) = 0 ;

    //
    // you have to store the gp
    //
    virtual void SetPrimitive(CATGraphicPrimitive *iGP,
                              CATTopObject * iContext,
                              const CATTessSettings& iSettings,
                              const char  iUserData) = 0 ;
    

    //
    // All the gp are deleted 
    //
    virtual  void InvalidPrimitive() = 0 ;

  virtual CAT3DLineGP**  GetIsopars(const CATTessSettings& iSettings,
                                    const char iOrientation,
                                    int& oNbIsopars) = 0;
  
  virtual void           SetIsopars(CAT3DLineGP** iGP,
                                    const int iNbIsopars,
                                    const CATTessSettings& iSettings,
                                    const char  iOrientation) = 0;

  /*
  //
  // Return whether the object is in the cache or not.
  //
  virtual HRESULT IsCached(CATTopObject * iContext,
                           const CATTessSettings& iSettings,
                           char  iOrientation) = 0;
  */
  virtual HRESULT SetType(CATTopObject * iContext, CATGeomType iGeomType,  CATIdentType iIdentType) = 0;
  virtual HRESULT GetType(CATTopObject * iContext, CATGeomType& oGeomType, CATIdentType& oIdentType) = 0;
};


CATDeclareHandler(CATISavedMesh,CATBaseUnknown);


#endif
