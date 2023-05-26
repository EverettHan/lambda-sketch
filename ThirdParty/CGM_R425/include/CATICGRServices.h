#ifndef CATICGRServices_H
#define CATICGRServices_H

//****************************************************************
// CATIA Version 5 Release 9 Framework VISUALIZATION
// Copyright Dassault Systemes 2002
//****************************************************************
//  Abstract:
//  ---------
//    Interface defining high level cgr services
//
//****************************************************************
//  Usage:
//  ------
//
//****************************************************************
//  Main Methods:
//  -------------
//
//     CGRStream()
//
//****************************************************************

#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"
#include "CATReadWriteCgr.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATICGRServices;
#else
extern "C" const IID IID_CATICGRServices;
#endif

#include "CATListOfCATUnicodeString.h"
class CATRep;
class CATColorMap;
class CATStorage;
class CATUnicodeString;

#include "CATReadWriteCgr.h"

class ExportedBySceneGraphManager CATICGRServices : public CATBaseUnknown
{

   CATDeclareInterface;

public:
    
   virtual HRESULT CGRStream(CATBaseUnknown* iFactory,
                             CATRep* iRep,
                             char*& oBuffer,
                             int& oLBuffer,
                             CATSettingCgr iSettingCgr,
                             CATColorMap *iColMap) = 0;

   virtual HRESULT CGRStream(CATBaseUnknown* iFactory,
                             CATRep* iRep,
                             CATStorage * oStorage,
                             CATSettingCgr iSettingCgr,
                             CATColorMap *iColMap) = 0;

   virtual HRESULT CGRStream(CATBaseUnknown* iFactory,
                             CATRep* iRep,
                             CATILockBytes2 * ioLB2,
                             CATSettingCgr iSettingCgr,
                             CATColorMap *iColMap) = 0;
   
   virtual HRESULT CGRStream(CATBaseUnknown* iFactory,
                             CATRep* iRep,
                             const CATUnicodeString& iPath,
                             CATSettingCgr iSettingCgr,
                             CATColorMap *iColMap,
							        CATVizCGRAccessMode iCGRAccessMode = CATVizCGRAccessModeDirect) = 0;

   /** List of applicative containers to stream added */
   virtual HRESULT CGRStream(CATBaseUnknown* iFactory,
                             CATRep* iRep,
                             CATILockBytes2 * ioLB2,
                             CATSettingCgr iSettingCgr,
                             const CATListOfCATUnicodeString & iContainerList) = 0;
};

CATDeclareHandler(CATICGRServices,CATBaseUnknown);

#endif
