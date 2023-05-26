// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : RR 
// Result description of BodyAnalyzer::SearchFeatures
//
//=============================================================================
// Creation RR feb 2017
//=============================================================================
#ifndef CATUfrReport_H
#define CATUfrReport_H

#include "ListPOfListPOfCATDeclarativeManifold.h"
#include "ListPOfListPOfListPOfCATDeclarativeManifold.h"
#include "CATGMOperatorsInterfaces.h"
#include "ListPOfCATCell.h"
#include "CATCGMVirtual.h"
#include "CATCGMNewArray.h"
#include "CATBoolean.h"
#include "CATCollec.h"
#include "CATListOfInt.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"

#include "CATLISTPP_Clean.h"
#include "CATLISTPP_PublicInterface.h"
#include "CATLISTPP_Declare.h"

#include "CATErrorDef.h" //for HRESULT

class CATMathStream;
class CATGeoFactory;
class CATSoftwareConfiguration;

// currently identified types 
// is there a need for squared with round corners?
enum CATPatternType { CATTopUnknown, CATTopRound, CATTopSquared, CATTopOblong};

struct InstanceCharacteristic
{
  CATPatternType _type; //Instance type - round, squared, oblong, unknown
  // for round instance width and height will be the same to ensure that it is round use type classification, too
  double         _width; 
  double         _height;
  CATMathPoint   _centre;
  CATMathVector  _normal;
};

// CATLISTPP_DECLARE_TS(InstanceCharacteristic, 10)
CATCGMLISTPP_DECLARE(InstanceCharacteristic);
typedef CATLISTP(InstanceCharacteristic) ListPOfInstanceCharacteristic;

//CATLISTPP_DECLARE_TS(ListPOfInstanceCharacteristic, 10)
CATCGMLISTPP_DECLARE(ListPOfInstanceCharacteristic);
typedef CATLISTP(ListPOfInstanceCharacteristic) ListPOfListPOfInstanceCharacteristic;

//#define CATListP(InstanceCharacteristic) ListPOfCharacteristic;

class ExportedByCATGMOperatorsInterfaces CATUfrReport : public CATCGMVirtual
{
public:

  // Constructor
  CATUfrReport();
  CATCGMNewClassArrayDeclare;        // Pool allocation

  CATUfrReport(const CATUfrReport& iToCopy); 

  // Destructor
  virtual ~CATUfrReport();

  // Number of features
  int GetFeatureCount() const;

  // Number of instances of a Feature (iFeatureIndex>0)
  int GetInstanceCount(const int iFeatureIndex) const;

  // List of Cells of an instance of a feature (iInstanceIndex>0: instances, iInstanceIndex=0: feature)
  void GetRep(const int iFeatureIndex, const int iInstanceIndex, ListPOfCATCell& oCells) const;

  // List of DeclarativeManifold of an instance of a feature (iInstanceIndex>0: instances, iInstanceIndex=0: feature)
  ListPOfCATDeclarativeManifold GetRep(const int iFeatureIndex, const int iInstanceIndex) const;
  void GetRep(const int iFeatureIndex, const int iInstanceIndex, ListPOfCATDeclarativeManifold& oDMs) const;

  // List of DeclarativeManifold of an instance of a feature grouped to map the declarative manifolds of the pattern
  // if oMappedDMs is set, the mapped DMs in the pattern are also returned
  // !!! the elements of oDMGroups must be CLEANED by the USER !!!
  void GetRep(const int iFeatureIndex, const int iInstanceIndex, ListPOfListPOfCATDeclarativeManifold& oDMGroups, ListPOfCATDeclarativeManifold* oMappedDMs = NULL) const;

  // The following functions are returning characteristics of instances found.
  // They are only applicable to patterns defined by a wire body.
  // Method CreateCharacteristics needs to be called first - it returns E_FAIL if e.g. pattern is not wire body or no config is provided
  // For the other methods an E_FAIL indicates that inputs are incorrect or the characteristics are not yet created.
  HRESULT CreateCharacteristics(CATSoftwareConfiguration* iConfig) const;
  HRESULT GetType(const int iFeatureIndex, CATPatternType& oType) const;
  HRESULT GetDimension( const int iFeatureIndex, const int iInstanceIndex, double& oHeight, double& oWidth) const;
  HRESULT GetInstanceNormal(const int iFeatureIndex, const int iInstanceIndex, CATMathVector& oNormal) const;
  HRESULT GetInstanceCentre(const int iFeatureIndex, const int iInstanceIndex, CATMathPoint& oCentre) const;

  // Dump
  void Dump(CATCGMOutput& ioOS) const;

  // ----------------------------------------------------------------------------
  // CGM Private section
  // ----------------------------------------------------------------------------
  void SetPatternRep(const int iFeatureIndex, const ListPOfCATDeclarativeManifold& iRep);
  
  // Append a List of DeclarativeManifold to an instance of a feature 
  // iMappedRep is the list associating for each DM of iRep a DM of the pattern
  void AppendRep(const int iFeatureIndex, const int iInstanceIndex, const ListPOfCATDeclarativeManifold& iRep, const ListPOfCATDeclarativeManifold& iMappedRep);

  // Reset this
  void Reset(const int iSize);

  // Stream/UnStream
  void Stream(CATMathStream& ioStr) const;
  CATUfrReport(CATMathStream& iStr, CATGeoFactory& iFactory);

  // Compare
  static int Compare(const CATUfrReport& iReport1, const CATUfrReport& iReport2, CATCGMOutput* os = NULL);
  static CATBoolean HaveSameElements(ListPOfCATDeclarativeManifold *iDMs1, ListPOfCATDeclarativeManifold *iDMs2);


protected:
  // this function will fill the struct of characteristics for all the instances found for specified feature index
  void CreateCharacteristics(const int iFeatureIndex, CATSoftwareConfiguration* iConfig) const;
  CATPatternType GetType(const int iFeatureIndex, CATSoftwareConfiguration* iConfig) const;
  void GetDimension(const int iFeatureIndex, const int iInstanceIndex, double& oheight, double& owidth, CATSoftwareConfiguration* iConfig) const;
  void GetDimensionsForRound(const int iFeatureIndex, const int iInstanceIndex, CATSoftwareConfiguration* iConfig, double& oheight, double& owidth, CATMathPoint& ocentre, CATMathVector& oNormal) const;
  void GetDimensions(const int iFeatureIndex, const int iInstanceIndex, CATSoftwareConfiguration* iConfig, double& oheight, double& owidth, CATMathPoint& ocentre, CATMathVector& oNormal) const;
  // ----------------------------------------------------------------------------
  // Private section
  // ----------------------------------------------------------------------------
private:
  int _Size; // Number of Features (Size of _Map)
  ListPOfListPOfListPOfCATDeclarativeManifold* _Map;  // _Map[i-1][j]: i Feature, j instance of feature i, returns a ListPOfListPOfCATDeclarativeManifold*
  ListPOfListPOfInstanceCharacteristic *_C;
  int *_CharacteristicIsSetFor;
  
};

#endif
