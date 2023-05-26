#ifndef LatticeHelpers_h
#define LatticeHelpers_h

#ifdef _LINUX_SOURCE
#define LATINLINE __always_inline
#else
#define LATINLINE inline
#endif

#include "ExportedByLatticeOperators.h"

// Sys
#include "CATUnicodeString.h"
#include "CATTrace.h"

// Lattice
#include "LatticeOperators.h"
#include "LatticeNBModel.h"

// Poly
#include "CATPolyBody.h"
#include "CATPolyBodyGeoChecker.h"
#include "CATPolyBodyCheckedEditor.h"
#include "CATPolyBodyRemoveIntersectingSlivers.h"
#include "CATPolyBodyCopier.h"
#include "CATPolyBodyServices.h"
#include "CATMapOf3DoublesToInt.h"
#include "CATMapOfIntIntToInt.h"
#include "CATMathPoint.h"

// GM Poly
#include "CATPGMPolyBodyAdapter.h"
#include "CATPGMVolumePartitionBodyToolKit.h"

// CGM
#include "CATGeoFactory.h"
#include "CATGeoFactoryMngt.h"
#include "CATBody.h"
#include "CATCGMObject.h"
#include "CATCGMStream.h"
#include "CATSoftwareConfiguration.h"
#include "CATICGMObjectsPersistency.h"
#include "CATTopData.h"
#include "CATCGMJournalList.h"
#include "CATIPGMTopCheckJournal.h"
#include "CATCGMOutput.h"
#include "CATCGMDebug.h"

// STD
#include <string>
#include <fstream>
#include <iostream>
#include <map>

// #define LatticeTestPerfos
#ifdef LatticeTestPerfos
#include <iomanip>
#include <chrono>
#endif

// Eigen lib
// #include <Eigen/Core>
// #include <Eigen/Dense>

//#define WZC_LOG_JOURNAL
class CATVolume;

#ifndef LATTICE_CHECK_HELPERS
#define LATTICE_CHECK_HELPERS

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

#ifdef WZC_LOG_JOURNAL
#define LOG_JOURNAL(journal) \
  { \
    CATCGMOutput outDebug(CATCGMOutput::String,NULL,CATCGMOutput::out); \
    journal->Dump(outDebug); \
    CATUnicodeString outDebugString; \
    outDebug.Get(outDebugString); \
    std::cout << "Journal in " << __func__ \
            << " at " << __FILE__ << ":" << __LINE__ << " " \
            << outDebugString << std::endl; \
  }
#else
#define LOG_JOURNAL(journal) \
  { \
  }
#endif // WZC_LOG_JOURNAL

#define CHECK_JOURNAL(iFactory, iTopData, iInputBody, iResultBody) \
  { \
    CATIPGMTopCheckJournal *pJournalChecker = CATPGMCreateTopCheckJournal(0, iFactory, iTopData, iResultBody); \
    if (pJournalChecker==nullptr) \
    { \
      LOG_NULL_PTR(pJournalChecker); \
      hr = E_FAIL; \
      return hr; \
    } \
    if(iInputBody!=nullptr) \
    { \
      pJournalChecker->AddInputBody(iInputBody, CATTopCheckCopy); \
    } \
    pJournalChecker->Check(); \
    hr = !pJournalChecker->JournalIsNotGood() ? S_OK : E_FAIL; \
    pJournalChecker->Release(); \
    pJournalChecker = nullptr; \
    CHECK_HR(hr); \
  }

#define CHECK_JOURNAL_NO_COPY(iFactory, iTopData, iInputBody, iResultBody) \
  { \
    CATIPGMTopCheckJournal *pJournalChecker = CATPGMCreateTopCheckJournal(0, iFactory, iTopData, iResultBody); \
    if (pJournalChecker==nullptr) \
    { \
      LOG_NULL_PTR(pJournalChecker); \
      hr = E_FAIL; \
      return hr; \
    } \
    if(iInputBody!=nullptr) \
    { \
      pJournalChecker->AddInputBody(iInputBody, CATTopCheckNoCopy); \
    } \
    pJournalChecker->Check(); \
    hr = !pJournalChecker->JournalIsNotGood() ? S_OK : E_FAIL; \
    pJournalChecker->Release(); \
    pJournalChecker = nullptr; \
    CHECK_HR(hr); \
  }

// Keep these two even if you don't see the rational for it...
// Macro preprocessors sometime are intricate things.
#define DETAIL(x) #x
#define TOSTRING(x) DETAIL(x)

#define EXPORT_POLYBODY_IF_DUMP_PATH(iDumpPath, ipPolyBody) \
  { \
    if (iDumpPath!=nullptr && ipPolyBody!=nullptr) { \
        CATBoolean PolyhedralObjectsMode = TRUE; \
        CATUnicodeString fullPath(iDumpPath); \
        fullPath.Append(DSYSysSlash); \
        CATUnicodeString filePath(TOSTRING(__FILE__)); \
        int slashAt = -1; \
        int nextSlashAt = filePath.SearchSubString(DSYSysSlash); \
        while(nextSlashAt!=-1) { \
          filePath = filePath.SubString((nextSlashAt+1), filePath.GetLengthInChar() - (nextSlashAt+1)); \
          nextSlashAt = filePath.SearchSubString(DSYSysSlash); \
        } \
        int extAt = filePath.SearchSubString("."); \
        filePath = filePath.SubString(0, extAt); \
        fullPath.Append(filePath); \
        fullPath.Append("_Ln"); \
        fullPath.Append(TOSTRING(__LINE__)); \
        fullPath.Append("_"); \
        fullPath.Append(#ipPolyBody); \
        fullPath.Append(".poly"); \
        HRESULT StreamHRet = CATPolyStreamPolyBody(fullPath.CastToCharPtr(), *ipPolyBody, PolyhedralObjectsMode); \
    } \
  }

#define EXPORT_BODY_IF_DUMP_PATH(iDumpPath, ipBody) \
  { \
    if (iDumpPath!=nullptr && ipBody!=nullptr) { \
      CATBoolean PolyhedralObjectsMode = TRUE; \
      CATUnicodeString fullPath(iDumpPath); \
      fullPath.Append(DSYSysSlash); \
      CATUnicodeString filePath(TOSTRING(__FILE__)); \
      int slashAt = -1; \
      int nextSlashAt = filePath.SearchSubString(DSYSysSlash); \
      while(nextSlashAt!=-1) { \
        filePath = filePath.SubString((nextSlashAt+1), filePath.GetLengthInChar() - (nextSlashAt+1)); \
        nextSlashAt = filePath.SearchSubString(DSYSysSlash); \
      } \
      int extAt = filePath.SearchSubString("."); \
      filePath = filePath.SubString(0, extAt); \
      fullPath.Append(filePath); \
      fullPath.Append("_Ln"); \
      fullPath.Append(TOSTRING(__LINE__)); \
      fullPath.Append("_"); \
      fullPath.Append(#ipBody); \
      fullPath.Append(".NCGM"); \
      lattice::helpers::ExportBody(fullPath.CastToCharPtr(), *ipBody); \
    } \
  }

#define EXPORT_O3P_IF_DUMP_PATH(iDumpPath, ipLattice) \
  { \
    LatticeNBModel* pLattice = const_cast<LatticeNBModel*>(ipLattice); \
    if (iDumpPath!=nullptr && pLattice!=nullptr) { \
      CATBoolean PolyhedralObjectsMode = TRUE; \
      CATUnicodeString fullPath(iDumpPath); \
      fullPath.Append(DSYSysSlash); \
      CATUnicodeString filePath(TOSTRING(__FILE__)); \
      int slashAt = -1; \
      int nextSlashAt = filePath.SearchSubString(DSYSysSlash); \
      while(nextSlashAt!=-1) { \
        filePath = filePath.SubString((nextSlashAt+1), filePath.GetLengthInChar() - (nextSlashAt+1)); \
        nextSlashAt = filePath.SearchSubString(DSYSysSlash); \
      } \
      int extAt = filePath.SearchSubString("."); \
      filePath = filePath.SubString(0, extAt); \
      fullPath.Append(filePath); \
      fullPath.Append("_Ln"); \
      fullPath.Append(TOSTRING(__LINE__)); \
      fullPath.Append("_"); \
      fullPath.Append(#ipLattice); \
      fullPath.Append(".o3p"); \
      lattice::helpers::ExportO3P(fullPath.CastToCharPtr(), *pLattice); \
    } \
  }


#endif // LATTICE_CHECK_HELPERS

namespace lattice
{
  /**
   * Contains some simple RAII smart ptr as well as varied utility functions.
   * RAII (Resource Acquisition is Initialization) is convenient in methods
   * that can exit early because of unexpected conditions (errors, exceptions,
   * out of memory ...).
   * They are convenient, ensure you don't leave anything behind and help
   * writing code in which checks and logic control flow of operations
   * are more distinct.
   */
  namespace helpers
  {
    /**
     * RAII for objects manged by CGM Factory.
     */
    template <typename T>
    class CGMFactoryManagedPtr
    {
    public:
      CGMFactoryManagedPtr(T* ipT) : _pt(ipT) {}
      ~CGMFactoryManagedPtr()
      {
        clear();
      }

      bool isNull() { return (_pt==nullptr) ? true : false; }
      T*  get() { return _pt; }
      T*& operator ~ () { return  _pt; }
      T&  operator * () { return *_pt; }
      T*  operator -> () { return _pt; }

      void clear()
      {
        if (_pt != nullptr) {
          CATGeoFactory* container = _pt->GetContainer();
          LOG_NULL_PTR(container);


          if (container != nullptr && _pt != nullptr) {
            container->Remove(_pt, CATICGMContainer::RemoveDependancies);
          }
          container = nullptr;
          _pt = nullptr;
        }
      }

      void reset(T* ipT)
      {
        clear();
        _pt = ipT;
      }
    private:
      T* _pt;

      CGMFactoryManagedPtr() : _pt(nullptr) {}

      // Commented out because of iOS
      // Simple RAII objects should not be copied
      // CGMFactoryManagedPtr(const CGMFactoryManagedPtr& iOther) = delete;
      // CGMFactoryManagedPtr& operator=(const CGMFactoryManagedPtr& iOther) = delete;
    };

    /**
     * RAII for raw ptr (deleted vi delete)
     */
    template <typename T>
    class ManagedPtr
    {
    public:
      ManagedPtr(T* ipT) : _pt(ipT) {}
      ~ManagedPtr()
      {
        clear();
      }

      void clear() {
        if (_pt != nullptr) {
          delete _pt;
          _pt = nullptr;
        }
      }

      void reset(T* ipT)
      {
        clear();
        _pt = ipT;
      }

      bool isNull() { return (_pt==nullptr) ? true : false; }
      T*  get() { return _pt; }
      T*& operator ~ () { return  _pt; }
      T&  operator * () { return *_pt; }
      T*  operator -> () { return _pt; }

    private:
      T* _pt;

      ManagedPtr() : _pt(nullptr) {}

      // Commented out because of iOS
      // Simple RAII objects should not be copied
      // ManagedPtr(const ManagedPtr& iOther) = delete;
      // ManagedPtr& operator=(const ManagedPtr& iOther) = delete;
    };

    /**
     * RAII for arrays of raw elements (dtor call delete [])
     */
    template <typename T>
    class ManagedArray
    {
    public:
      ManagedArray(T* ipT) : _pt(ipT) {}
      ~ManagedArray()
      {
        if(_pt!=nullptr) {
          delete [] _pt;
          _pt = nullptr;
        }
      }

      bool isNull() { return (_pt==nullptr) ? true : false; }
      T*  get() { return _pt; }
      T*& operator ~ () { return  _pt; }
      T&  operator * () { return *_pt; }
      T*  operator -> () { return _pt; }

    private:
      T* _pt;

      ManagedArray() : _pt(nullptr) {}

      // Commented out because of iOS
      // Simple RAII objects should not be copied
      // ManagedArray(const ManagedArray& iOther) = delete;
      // ManagedArray& operator=(const ManagedArray& iOther) = delete;
    };

    /**
     * RAII for arrays of raw const elements (dtor call delete [])
     */
    template <typename T>
    class ConstManagedArray
    {
    public:
      ConstManagedArray(const T* ipT) : _pt(ipT) {}
      ~ConstManagedArray()
      {
        if(_pt!=nullptr) {
          delete [] _pt;
          _pt = nullptr;
        }
      }

      bool isNull() { return (_pt==nullptr) ? true : false; }
      const T*  get() { return _pt; }
      const T*& operator ~ () { return  _pt; }
      const T&  operator * () { return *_pt; }
      T*  operator -> () { return _pt; }

    private:
      const T* _pt;

      ConstManagedArray() : _pt(nullptr) {}

      // Commented out because of iOS
      // Simple RAII objects should not be copied
      // ConstManagedArray(const ConstManagedArray& iOther) = delete;
      // ConstManagedArray& operator=(const ConstManagedArray& iOther) = delete;
    };

    /**
     * RAII for objects which LF is managed via AddRef / Release.
     * (dtor calls Release).
     */
    template <typename T>
    class ManagedIPtr
    {
    public:
      ManagedIPtr(T* ipT) : _pt(ipT) {}
      ~ManagedIPtr()
      {
        if(_pt!=nullptr) {
          _pt->Release();
          _pt = nullptr;
        }
      }

      bool isNull() { return (_pt==nullptr) ? true : false; }
      T*  get() { return _pt; }
      T*& operator ~ () { return  _pt; }
      T&  operator * () { return *_pt; }
      T*  operator -> () { return _pt; }

    private:
      T* _pt;

      ManagedIPtr() : _pt(nullptr) {}

      // Commented out because of iOS
      // Simple RAII objects should not be copied
      // ManagedIPtr(const ManagedIPtr& iOther) = delete;
      // ManagedIPtr& operator=(const ManagedIPtr& iOther) = delete;
    };

    /* -------------------------------------------------------------------------------------------------------*/
    /* ------------------- Force template instantiation ------------------------------------------------------*/
    typedef CGMFactoryManagedPtr<CATBody>                 CATBodyPtr;

    typedef ManagedPtr<CATPGMVolumePartitionBodyToolKit>  CATPGMVolumePartitionBodyToolKitPtr;

    typedef ManagedPtr<LatticeNBModel>                    CATLatticeNBModelPtr;

    typedef ManagedPtr<CATTopData>                        CATTopDataPtr;

    // Not needed use CATCGMSharedPtr<CATPolyBody> instead.
    //typedef ManagedIPtr<CATPolyBody>                      CATPolyBodyPtr;

    /* ------------------- END Force template instantiation --------------------------------------------------*/
    /* -------------------------------------------------------------------------------------------------------*/

    /**
     * RAII for GeoFactory.
     * (dtor calls close).
     */
    class ExportedByLatticeOperators CATGeoFactoryPtr final
    {
    public:
      /**
       * Default ctor from a CATGeoFactory ptr. From now own that factory
       * is owned by this smart pointer which will close it when going
       * out of score.
       */
      CATGeoFactoryPtr(CATGeoFactory* iFactory);

      /**
       * Default ctor from a file path. If the path is valid
       * init will open the specified container which will be close
       * when this object goes out of scope and is being deleted.
       */
      CATGeoFactoryPtr(const CATUnicodeString& iPath);

      /**
       * dtor. Will close the CATGeoFactory, no need to make
       * a virtual dtor as our class is duly marked as final.
       */
      ~CATGeoFactoryPtr();

      /**
       * If a valid path has been provided this method will open
       * the associated container and manager it's LF.
       */
      HRESULT init();

      /**
       * Let you specific path to container after construction.
       */
      HRESULT init(const CATUnicodeString& iPath);

      /**
       * Does everything that is needed to close the associated
       * CATGeoFactory.
       */
      void close();

      /**
       * If a CATGeoFactory* is associated with this smart ptr will
       * return true. False otherwise.
       */
      bool isNull() { return (_pt == nullptr) ? true : false; }

      CATGeoFactory*  get() { return _pt; }
      CATGeoFactory*& operator ~ () { return  _pt; }
      CATGeoFactory&  operator * () { return *_pt; }
      CATGeoFactory*  operator -> () { return _pt; }

    private:
      std::ifstream           _ifs;
      CATUnicodeString        _path;
      CATGeoFactory*          _pt;

      CATGeoFactoryPtr() : _pt(nullptr) {}
    };

    extern CATTrace trace;

    /**
     * Will build a full file path from folder path and file name.
     * @param iPath, folder path
     * @param iFileName, the desired file name (you can pass paths)
     * @return full path as a CATUnicodeString
     */
    ExportedByLatticeOperators CATUnicodeString BuildFullPath(const char* iPath, const char* iFileName);

    /**
     * WriteObj will write an AliasWavefront .obj file with the provided vertices and triangle
     * information.
     *
     * @param iFileName, the desired file name (you can pass paths)
     * @param iVertices, the vertices x,y,z as an array of double (stride is fixed to 3)
     * @param iVertexCount, number of vertices provided via iVertices
     * @param iIndices, the triangles' vertices's indices as an array of uint32_t
     * @param iTriangleCount, the number of provided triangles.
     * @return S_OK if everything is fine.
     */
    ExportedByLatticeOperators HRESULT WriteObj(const std::string& iFileName,
      const double* iVertices, const uint32_t iVertexCount,
      const uint32_t* iIndices, const uint64_t iTriangleCount);

    /**
     * WriteObj will write an AliasWavefront .obj file with the provided vertices and triangle
     * information.
     *
     * @param iFileName, the desired file name (you can pass paths)
     * @param iVertices, the vertices x,y,z as an array of double (stride is fixed to 3)
     * @param iVertexCount, number of vertices provided via iVertices
     * @param iIndices, the triangles' vertices's indices as an array of uint32_t
     * @param iTriangleCount, the number of provided triangles.
     * @return S_OK if everything is fine.
     */
    ExportedByLatticeOperators HRESULT WriteObj(const std::string& iFileName,
        const float* iVertices, const int iVertexCount,
        const int* iIndices, const int iTriangleCount);

    /**
     * ExportO3P export the provided LatticeNBModel as an o3p file.
     *
     * @param iFilePath, filepath of the o3p file to be written
     * @param iLattice, the bar graph to be persisted
     * @return S_OK if everything went all right.
     */
    ExportedByLatticeOperators HRESULT ExportO3P(const char *iFilePath, const LatticeNBModel &iLattice);

    /**
     * ExportCATPolyBody export the specified CATPolyBody as a .poly
     *
     * @param iFilePath, file path
     * @param iPolyBody, the poly body to be persisted
     * @return S_OK if successful.
     */
    ExportedByLatticeOperators HRESULT ExportCATPolyBody(const char *iFilePath, CATPolyBody* iPolyBody);

    /**
     * ExportCATBody export the specified CATBody after converting it to CATPolyBody as a .poly
     *
     * @param iFilePath, file path
     * @param iBody, the body for which to persist it's polyhedral representation persisted
     * @param iSoftwareConfig,
     * @return S_OK if successful.
     */
    ExportedByLatticeOperators HRESULT ExportCATBody(const char *iFilePath, CATBody* iBody, CATSoftwareConfiguration* iSoftwareConfig);

    /**
     * ExportBody export the provided CATBody as .ncgm
     *
     * @param iFilePath
     * @param iBody, the body to be persisted as .ncgm
     * @return S_OK if all went all right
     */
    ExportedByLatticeOperators HRESULT ExportBody(const char* iFilePath, CATBody& iBody);

    /**
     * GeoChecker run full geometric checks from PolyhedralFrameworks on the provided iPolyBody.
     *
     * @param iPolyBody, poly body to be checked.
     * @param iScaleCategory
     * @return S_OK if everything is fine, S_FALSE if the poly body has pathologies.
     */
    ExportedByLatticeOperators HRESULT GeoChecker(CATPolyBody* iPolyBody, const CATCGMScaleCategory iScaleCategory);

    /**
     * GeoChecker run full geometric checks from PolyhedralFrameworks on the provided iPolyMesh.
     *
     * @param iPolyMesh, iPolyMesh to be checked.
     * @param iScaleCategory
     * @return S_OK if everything is fine, S_FALSE if the poly body has pathologies.
     */
    ExportedByLatticeOperators HRESULT GeoChecker(CATIPolyMesh* iPolyMesh, const CATCGMScaleCategory iScaleCategory, CATPolyBody*& oPolyBody);

    /**
     * Quick compare indices, useful to see if same triangle.
     */
    LATINLINE bool HasSameContent(const int* iIndices, const int* iOtherIndices, const int iElementCount) {
      for (int i = 0; i < iElementCount; ++i) {
        bool ok = false;
        for (int j = 0; j < iElementCount; ++j) {
          if (iIndices[i] == iOtherIndices[j]) {
            ok = true;
            break;
          }
        }
        if (!ok)
          return false;
      }
      return true;
    }

    /**
     * Quick compare indices, useful to see if same triangle with same orientation
     */
    LATINLINE bool HasSameOrderedContent(const int* iIndices, const int* iOtherIndices, const int iElementCount) {
      for (int i = 0; i < iElementCount; ++i) {
        if (iIndices[i] != iOtherIndices[i])
          return false;
      }
      return true;
    }

    /**
     * Check if the specified index is in the array.
     */
    LATINLINE bool Contains(const int iIndex, const int* iIndices, const int iElementCount) {
      for (int i = 0; i < iElementCount; ++i) {
        if (iIndices[i] == iIndex)
          return true;
      }
      return false;
    }

    /**
     * Check which is the first index in iIndices that is not in iOtherIndices
     */
    LATINLINE int DifferenceAt(const int* iIndices, const int* iOtherIndices, const int iElementCount) {
      for (int i = 0; i < iElementCount; ++i) {
        if (!Contains(iIndices[i], iOtherIndices, 3))
          return i;
      }
      return -1;
    }

    // void StreamEigenOrthogonalBasisToSTL(const char* iFilename, double& iScale,
    //   std::array<double, 3>& ibboxMin, std::array<double, 3>& ibboxMax,
    //   std::vector<std::vector<std::vector<Eigen::Matrix3d>>>& iOrthogonalBasisField);

    class ExportedByLatticeOperators CompareLexicoPoints
    {
    public:
    CompareLexicoPoints() {}
    bool operator() (const CATMathPoint & lhs, const CATMathPoint & rhs) const
    {
      return (lhs.GetX() < rhs.GetX() ||
              (lhs.GetX() == rhs.GetX() && (lhs.GetY() < rhs.GetY() ||
                                            (lhs.GetY() == rhs.GetY() && lhs.GetZ() < rhs.GetZ()))));
    }
    };

    /** Operator to iteratively create the union of several
     * lattices. The lattices may have common parts, i.e. nodes and
     * beams at same (exact, not tolerant) positions, but they have to
     * be compatible. That means, if two unioned lattices have two
     * nodes at same positions and a beam between the two same nodes,
     * the two radius of the beam, linked to the two nodes
     * extremities, must be the same as well */
    class ExportedByLatticeOperators LatticeNBFusionOper
    {
    public:
      LatticeNBFusionOper();
      ~LatticeNBFusionOper();

      HRESULT AddLattice(const LatticeNBModel & iLattice);

      /** Delegate the lifecycle of the returned fusionned lattice, so
       * you'd better destroy it yourself! */
      LatticeNBModel * GetFusion();

    private:
      std::map<CATMathPoint, unsigned, CompareLexicoPoints> _NodesSet;
      CATMapOfIntIntToInt _BeamsSet;
      LatticeNBModel * _Fuuuuuusion;
      unsigned _genNodeId;
      unsigned _genBeamId;
    };

    ExportedByLatticeOperators CATVolume * GetCorrespondingVolume(const CATVolume * iVolume, CATBody & iBody);

    LATINLINE double MaxVoxelSizeFromRadius(const double iMinRadius, const double iMaxRadius)
    {
      return iMinRadius > 0.0 ? iMinRadius / 2.0 : 1.5 * iMaxRadius / 4.0;
    }
    LATINLINE double MaxVoxelSizeFromRadius(const LatticeNBModel & iLattice)
    {
      return MaxVoxelSizeFromRadius(iLattice.GetMinRadius(), iLattice.GetMaxRadius());
    }

    LATINLINE double RadiusOffset(const LatticeNBModel & iLattice)
    {
      return 1.5 * iLattice.GetMaxRadius() + 1.733 * MaxVoxelSizeFromRadius(iLattice);
    }

#ifdef LatticeTestPerfos
    /** This class allows to measure the time spent in some steps (set
     * of instructions) of a function. One instance of this class
     * should be declared at the beginning of the function. Each step
     * must be framed between a call to <Reset> with a message (name)
     * for this step, and a call to <Stack> that delimit this
     * step. The alternative constructor with an initial message
     * directly makes an initial call to Reset with this message,
     * marking the beginning of the first step. The alternative
     * StackAndReset method is a short for a stack (end of step
     * measurement) immediately followed by a reset to start a new
     * step. When the instance is destroyed, it prints a summary of
     * each step with its name and measured time, the global time of
     * all the steps measured and the time spent out of scope (time
     * spent in instructions not encompassed in a Reset-Stack frame,
     * from the instance construction to its deletion). To ensure
     * the summary is correct, each call to <Stack> should be made at
     * the same level of indentation than the corresponding call to
     * <Reset>, without any 'return' instruction in between.
     */
    class ExportedByLatticeOperators DebugChrono
    {
    public:
    DebugChrono(std::string iTitle) :
    _title( iTitle ),
    _totalDuration(std::chrono::milliseconds::zero()),
    _lifeTime{ std::chrono::system_clock::now() },
    _start{ std::chrono::system_clock::now() }
    {}
    DebugChrono(std::string iTitle, std::string iMessage) :
    DebugChrono( iTitle )
    { _message = iMessage; }
    ~DebugChrono()
    {
      auto lifeTime =
        std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::system_clock::now() - _lifeTime);
      std::string titleDecoration(_title.length() + 6, '-');
      std::cout << titleDecoration << std::endl <<
        "** " << _title << " **" << std::endl;
      for (auto step : _stack)
      {
        Output(step);
      }
      std::cout << std::left << std::setw(64) << "Total duration" <<
        std::right << std::setw(8) << _totalDuration.count() << " ms (100%)" << std::endl << "-----" << std::endl;
      std::cout << std::left << std::setw(64) << "Out of scope" <<
        std::right << std::setw(8) << (lifeTime - _totalDuration).count() << " ms (" <<
                ((1.0 - static_cast<double>(_totalDuration.count())/static_cast<double>(lifeTime.count())) * 100.0) << "%)" <<
        std::endl << "-----" << std::endl;
    }

    void Stack()
    {
      auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::system_clock::now() - _start);
      _totalDuration += duration;
      _stack.push_back(std::make_pair(_message, duration));
    }

    void Reset(std::string m) {
      _message = m;
      _start = std::chrono::system_clock::now();
    }

    void StackAndReset(std::string m) {
      Stack();
      Reset(m);
    }

    private:

    void Output(std::pair<std::string, std::chrono::milliseconds> & step) const
    {
      std::cout << std::left << std::setw(64) << step.first <<
        std::right << std::setw(8) << step.second.count() << " ms (" <<
        ((static_cast<double>(step.second.count())/static_cast<double>(_totalDuration.count())) * 100.0) << "%)" << std::endl;
    }

    private:
      std::chrono::system_clock::time_point _start, _lifeTime;
      std::chrono::milliseconds _totalDuration;
      std::vector<std::pair<std::string, std::chrono::milliseconds>> _stack;
      std::string _title, _message;
    };
#else
    class ExportedByLatticeOperators DebugChrono
    {
    public:
    DebugChrono(std::string m){}
    DebugChrono(std::string iTitle, std::string iMessage) {}
    void Stack() {};
    void Reset(std::string m) {}
    void StackAndReset(std::string m) {}
    };
#endif

  } // gm -> I don't think so... "helpers", maybe?
} // lattice

#endif // LatticeHelpers
