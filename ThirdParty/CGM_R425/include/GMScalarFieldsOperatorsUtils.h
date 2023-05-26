// COPYRIGHT DASSAULT SYSTEMES 2022

#ifndef GMSCalarFieldsOperatorsUtils_H
#define GMSCalarFieldsOperatorsUtils_H

#include "GMScalarFieldsOperators.h"

#include <string>
#include <iostream>
#include <vector>

#include "ScalarFieldUtils.h"
#include "GMScalarFieldsObjectsUtils.h"
#include "LatticeHelpers.h"

#include "DSYSysCommon.h"
#include "DSYString.h"

// Let's re expose some stuff of 
// Lattice Helpers with a more convenient
// naming.
namespace SFHelpers = lattice::helpers;

#ifndef GM_SF_COMMON_TYPES
#define GM_SF_COMMON_TYPES
typedef std::vector<CATUnicodeString> CATUnicodeStrings;
ExportedByGMScalarFieldsObjectsTI std::vector<CATUnicodeString>;
#endif // GM_SF_COMMON_TYPES

#ifndef GM_SF_CHECK_HELPERS
#define GM_SF_CHECK_HELPERS

#define CHECK_PTR_CTHROW(ptr) \
  if(ptr==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << " Ln" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
    CATThrowForNullPointer(); \
  }

#define CHECK_CONDITION_CTHROW(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << " Ln" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    CATThrowForNullPointer(); \
  }

#define CHECK_HR_CTHROW(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << " Ln" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    CATThrowForNullPointer(); \
  }

#define CHECK_HR_AND_LOG(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << " Ln" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
  }

#define DEBUG_DUMP_POLYBODY(path, polyBody) \
  if (path != nullptr) { \
    CATBoolean PolyhedralObjectsMode = TRUE; \
    CATUnicodeString fullPath(path); \
    fullPath.Append(DSYSysSlash); \
    fullPath.Append(#polyBody); \
    fullPath.Append(".poly"); \
    std::cout << "" << __func__ \
              << " at " << __FILE__ << " Ln" << __LINE__ << " " \
              << " dumping PolyBody " << #polyBody << " to " << fullPath.CastToCharPtr() << std::endl; \
    HRESULT StreamHRet = CATPolyStreamPolyBody(fullPath, polyBody, PolyhedralObjectsMode); \
  }

#define DEBUG_DUMP_POLYBODY_FROM_PTR(path, polyBodyPtr) \
  if (path != nullptr && polyBodyPtr!=nullptr) { \
    CATBoolean PolyhedralObjectsMode = TRUE; \
    CATUnicodeString fullPath(path); \
    fullPath.Append(DSYSysSlash); \
    fullPath.Append(#polyBodyPtr); \
    fullPath.Append(".poly"); \
    std::cout << "" << __func__ \
              << " at " << __FILE__ << " Ln" << __LINE__ << " " \
              << " dumping PolyBody " << #polyBodyPtr << " to " << fullPath.CastToCharPtr() << std::endl; \
    HRESULT StreamHRet = CATPolyStreamPolyBody(fullPath, *polyBodyPtr, PolyhedralObjectsMode); \
  }

#define DEBUG_DUMP_CATIPOLYMESH(path, catIPolyMesh) \
  if (path != nullptr && catIPolyMeshPtr != nullptr) { \
    CATPolyBody* vrepMeshAsPolyBody = new CATPolyBody(); \
    if (vrepMeshAsPolyBody != nullptr) { \
      vrepMeshAsPolyBody->MakeFace(catIPolyMesh); \
      CATBoolean PolyhedralObjectsMode = TRUE; \
      CATUnicodeString fullPath(path); \
      fullPath.Append(DSYSysSlash); \
      fullPath.Append(#catIPolyMesh); \
      fullPath.Append(".poly"); \
      std::cout << "" << __func__ \
        << " at " << __FILE__ << " Ln" << __LINE__ << " " \
        << " dumping CATIPolyMesh " << #catIPolyMesh << " to " << fullPath.CastToCharPtr() << std::endl; \
      HRESULT StreamHRet = CATPolyStreamPolyBody(fullPath, *vrepMeshAsPolyBody, PolyhedralObjectsMode); \
      vrepMeshAsPolyBody->Release(); \
      vrepMeshAsPolyBody = nullptr; \
    } \
  }

#define DEBUG_DUMP_CATIPOLYMESH_FROM_PTR(path, catIPolyMeshPtr) \
  if (path!= nullptr && catIPolyMeshPtr != nullptr) { \
    CATPolyBody* vrepMeshAsPolyBody = new CATPolyBody(); \
    if (vrepMeshAsPolyBody != nullptr) { \
      vrepMeshAsPolyBody->MakeFace(*catIPolyMeshPtr); \
      CATBoolean PolyhedralObjectsMode = TRUE; \
      CATUnicodeString fullPath(path); \
      fullPath.Append(DSYSysSlash); \
      fullPath.Append(#catIPolyMeshPtr); \
      fullPath.Append(".poly"); \
      std::cout << "" << __func__ \
        << " at " << __FILE__ << " Ln" << __LINE__ << " " \
        << " dumping CATIPolyMesh " << #catIPolyMeshPtr << " to " << fullPath.CastToCharPtr() << std::endl; \
      HRESULT StreamHRet = CATPolyStreamPolyBody(fullPath, *vrepMeshAsPolyBody, PolyhedralObjectsMode); \
      vrepMeshAsPolyBody->Release(); \
      vrepMeshAsPolyBody = nullptr; \
    } \
  }

#define DEBUG_DUMP_BODY(path, body) \
  if (path != nullptr) { \
    CATPGMPolyBodyAdapter* polyBodyAdapter = CATPGMCreatePolyBodyAdapter(&body, softwareConfig); \
    if (polyBodyAdapter==nullptr) { \
      std::cout << "Error in " << __func__ \
                << " at " << __FILE__ << " Ln" << __LINE__ << " " \
                << "polyBodyAdapter" << " is nullptr" << std::endl; \
      return E_FAIL; \
    } \
    CATPolyBody* polyBody = nullptr; \
    hr = polyBodyAdapter->Run(polyBody, FALSE); \
    if(FAILED(hr)) { \
      std::cout << "Error in " << __func__ \
                << " at " << __FILE__ << " Ln" << __LINE__ << " " \
                << " failed with hr: " << hr << std::endl; \
      return hr; \
    } \
    if(polyBody==nullptr) { \
      std::cout << "Error in " << __func__ \
                << " at " << __FILE__ << " Ln" << __LINE__ << " " \
                << "polyBody" << " is nullptr" << std::endl; \
      return E_FAIL; \
    } \
    CATBoolean PolyhedralObjectsMode = TRUE; \
    CATUnicodeString fullPath(path); \
    fullPath.Append(DSYSysSlash); \
    fullPath.Append(#body); \
    fullPath.Append(".poly"); \
    std::cout << "" << __func__ \
              << " at " << __FILE__ << " Ln" << __LINE__ << " " \
              << " dumping Body " << #body << " as PolyBody to " << fullPath.CastToCharPtr() << std::endl; \
    HRESULT StreamHRet = CATPolyStreamPolyBody(fullPath, *polyBody, PolyhedralObjectsMode); \
    delete polyBodyAdapter; polyBodyAdapter = nullptr; \
    polyBody->Release(); polyBody = nullptr; \
  }

#define DEBUG_DUMP_BODY_FROM_PTR(path, bodyPtr) \
  if (path != nullptr && bodyPtr!=nullptr) { \
    CATPGMPolyBodyAdapter* polyBodyAdapter = CATPGMCreatePolyBodyAdapter(bodyPtr, softwareConfig); \
    if (polyBodyAdapter==nullptr) { \
      std::cout << "Error in " << __func__ \
                << " at " << __FILE__ << " Ln" << __LINE__ << " " \
                << "polyBodyAdapter" << " is nullptr" << std::endl; \
      return E_FAIL; \
    } \
    CATPolyBody* polyBody = nullptr; \
    hr = polyBodyAdapter->Run(polyBody, FALSE); \
    if(FAILED(hr)) { \
      std::cout << "Error in " << __func__ \
                << " at " << __FILE__ << " Ln" << __LINE__ << " " \
                << " failed with hr: " << hr << std::endl; \
      return hr; \
    } \
    if(polyBody==nullptr) { \
      std::cout << "Error in " << __func__ \
                << " at " << __FILE__ << " Ln" << __LINE__ << " " \
                << "polyBody" << " is nullptr" << std::endl; \
      return E_FAIL; \
    } \
    CATBoolean PolyhedralObjectsMode = TRUE; \
    CATUnicodeString fullPath(path); \
    fullPath.Append(DSYSysSlash); \
    fullPath.Append(#bodyPtr); \
    fullPath.Append(".poly"); \
    std::cout << "" << __func__ \
              << " at " << __FILE__ << " Ln" << __LINE__ << " " \
              << " dumping Body " << #bodyPtr << " as PolyBody to " << fullPath.CastToCharPtr() << std::endl; \
    HRESULT StreamHRet = CATPolyStreamPolyBody(fullPath, *polyBody, PolyhedralObjectsMode); \
    delete polyBodyAdapter; polyBodyAdapter = nullptr; \
    polyBody->Release(); polyBody = nullptr; \
  }

#define FULL_CHECK_POLYBODY_FROM_PTR(polyBodyPtr) \
  if (polyBodyPtr) { \
    CATPolyBodyGeoChecker geochecker; \
    hr = geochecker.FullCheck(*polyBodyPtr, -1., GetIsolatedScaledCATTolerance(iScale)); \
    if(FAILED(hr)) { \
      std::cout << "Error in " << __func__ \
                << " at " << __FILE__ << " Ln" << __LINE__ << " " \
                << " geochecker.FullCheck failed with hr: " << hr << std::endl; \
      return hr; \
    } \
  }
  
#endif // GM_SF_CHECK_HELPERS

#endif // GMSCalarFieldsOperatorsUtils_H


