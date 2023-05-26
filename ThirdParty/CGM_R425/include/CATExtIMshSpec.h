#ifndef CATExtIMshSpec_H
#define CATExtIMshSpec_H

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATExtIMshSpec.h
// Define the CATExtIMshSpec adapter : used to set the default behavior of not
// implemented functions
//
//=============================================================================
// Februry  2022   Creation                         Fabien Noblet (FNT1)
//=============================================================================

#include "CATIMshSpec.h"
#include "CATIMshDataOnMesh.h"
#include "CATIMshComplexData.h"
#include <string.h>

class CATIMshMesh;

/**
 * Object descibing a user specificaion f frozen entities.
 */
class ExportedByCATMshMesherCore CATExtIMshSpec : public CATIMshSpec
{

public:

  CATExtIMshSpec();

  /* Destructeur */
  virtual ~CATExtIMshSpec();

  virtual HRESULT SetSupport(CATIMshMesh *iMsh);

  virtual HRESULT SetSupport();

  virtual HRESULT SetSupport(int iSize, int *iTopoIDs, const char* iName = "");

  virtual HRESULT SetSupport(int iGeomID);

  virtual HRESULT SetParameter(const char* iName, int iSize, double *iValue);

  virtual HRESULT SetParameter(const char* iName, int iSize, int *iValue);

  virtual HRESULT SetParameter(const char* iName, int iSize, const char* *iValue);

  virtual HRESULT SetComplexData(CATIMshComplexData * iComplexData);

  virtual HRESULT SetDataOnMesh(CATIMshDataOnMesh * iDataOnMesh);

  virtual CATMshSpecType Type();



  /* Get methods, should not be used : internal purpose */

  virtual CATIMshMesh * GetSupport();

  virtual int * GetSupport(const char* iName, int & oSize);

  virtual HRESULT GetSupport(int & oGeomID);

  virtual bool SupportIsAll();

  virtual HRESULT GetParameterSize(const char* iName, int & oSize);

  virtual HRESULT GetParameter(const char* iName, const char* *ioValues);

  virtual HRESULT GetParameter(const char* iName, int *ioValues);

  virtual HRESULT GetParameter(const char* iName, double *ioValues);

  virtual CATIMshComplexData * GetComplexData();

  virtual CATIMshDataOnMesh * GetDataOnMesh();

};

#endif
