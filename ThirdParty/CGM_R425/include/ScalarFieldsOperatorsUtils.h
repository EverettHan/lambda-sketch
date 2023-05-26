// COPYRIGHT DASSAULT SYSTEMES 2023

#ifndef ScalarFieldsOperatorsUtils_H
#define ScalarFieldsOperatorsUtils_H

#include "ScalarFieldsOperators.h"

#include <string>
#include <iostream>
#include <vector>

#include "ScalarFieldUtils.h"
//#include "LatticeHelpers.h"

#include "DSYString.h"
#include "DSYSysCommon.h"

// Let's re expose some stuff of
// Lattice Helpers with a more convenient
// naming.
//namespace SFHelpers = lattice::helpers;

#ifndef GM_SF_COMMON_TYPES
#define GM_SF_COMMON_TYPES
typedef std::vector<CATUnicodeString> CATUnicodeStrings;

#endif // GM_SF_COMMON_TYPES

#ifndef SF_CHECK_HELPERS
#define CHECK_HR(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return hr; \
  }

#define CHECK_HR_RET(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return; \
  }

#define CHECK_HR_RETI(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return 1; \
  }

#define CHECK_HR_RETB(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return FALSE; \
  }

#define CHECK_HR_RETPTR(hr) \
  if(FAILED(hr)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << " failed with hr: " << hr << std::endl; \
    return nullptr; \
  }

#define CHECK_PTR_RETI(ptr) \
  if(ptr==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
    return 1; \
  }

#define LOG_INFO(msg) \
  { \
    std::cout << "Info from " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << msg << std::endl; \
  }

#define LOG_ERROR(msg) \
  { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << msg << std::endl; \
  }

#define LOG_NULL_PTR(ptr) \
  if(ptr==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
  }

#define LOG_NULL_MPTR(ptr) \
  if(ptr.get()==nullptr) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #ptr << " is nullptr" << std::endl; \
  }


#define CHECK_CONDITION(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return E_FAIL; \
  }

#define CHECK_CONDITION_RET(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return; \
  }

#define CHECK_CONDITION_RETI(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return 1; \
  }

#define CHECK_CONDITION_RETB(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return FALSE; \
  }

#define CHECK_CONDITION_RETPTR(cond) \
  if(!(cond)) { \
    std::cout << "Error in " << __func__ \
              << " at " << __FILE__ << ":" << __LINE__ << " " \
              << #cond << " not satisfied." << std::endl; \
    return nullptr; \
  }

#endif // SF_CHECK_HELPERS


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

#define DEBUG_DUMP_GRAPH(path, node) \
  if(path!=nullptr && node!=nullptr) { \
      std::string dagStringpoly = ""; \
      SF::SFDagToGraphViz::Export(*node, dagStringpoly); \
      CATUnicodeString fullPath(path); \
        fullPath.Append(DSYSysSlash); \
        fullPath.Append(#node); \
        fullPath.Append(".gv"); \
        std::cout << "" << __func__ \
        << " at " << __FILE__ << " Ln" << __LINE__ << " " \
        << " dumping implicit DAG " << #node << " as GraphViz graph to " << fullPath.CastToCharPtr() << std::endl; \
      ofstream file; \
      file.open(fullPath.CastToCharPtr()); \
      file << dagStringpoly; \
      file.close(); \
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

#define DEBUG_DUMP_VREP(path, iVRep) \
  if (path != nullptr && iVRep!=nullptr) { \
    CATUnicodeString fullPath(path); \
    fullPath.Append(DSYSysSlash); \
    fullPath.Append(#iVRep); \
    fullPath.Append(".txt"); \
    std::cout << "" << __func__ \
              << " at " << __FILE__ << " Ln" << __LINE__ << " " \
              << " dumping VRep " << #iVRep << " to " << fullPath.CastToCharPtr() << std::endl; \
    HRESULT writeHR = iVRep->WriteToFile((char*)fullPath.CastToCharPtr(), FALSE); \
    if(FAILED(writeHR)) { \
      std::cout << "Error in " << __func__ \
                << " at " << __FILE__ << " Ln" << __LINE__ << " " \
                << " iVRep->WriteToFile failed with hr: " << writeHR << std::endl; \
      return writeHR; \
    } \
  }

#endif // ScalarFieldsOperatorsUtils_H
