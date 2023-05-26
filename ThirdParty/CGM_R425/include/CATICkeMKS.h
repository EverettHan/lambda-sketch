// Copyright Dassault Systemes 2000
#ifndef CATICkeMKS_h
#define CATICkeMKS_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Engineering Equations Framework
//
//      Resp : frh
//
//////////////////////////////////////////////////////////////////////////
//
//      CATICkeMKS :This interface manages the MKS Facet of parameters
//
//////////////////////////////////////////////////////////////////////////
//
// Dec 98 Revision  GetFacet, SetFacet for facet management     C.Lenguin
//
//////////////////////////////////////////////////////////////////////////

// Its an interface
#include <CATBaseUnknown.h>

// Forwords for CkeAdapter
#include "CATLifSpecs.h"
#include <CATICkeRelationForwards.h>
#include "CATListOfDouble.h"
#include "CATListOfCATUnicodeString.h"

// OLE
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATICkeMKS;
#else
extern "C" const IID IID_CATICkeMKS;
#endif

class ExportedByCATLifSpecs CATICkeMKS : public CATBaseUnknown
{
public :

	//----------------------------------------------
	// Enum facet type :
	// ---------
	//  facet types that can be added dynamically to any parameter
	// 
	enum FacetType  
	{
		Tolerance	      = 0,   // the tolerance values
		Range             = 1,   // the range
		ListOfValues      = 2    // the list of authorized values
	};
	
  
  // Internal or external to expression ?
  virtual CATCke::Boolean            IsOutside () const = 0;

  // Gets the facet (bounds, tolerance, list of authorized values)
  virtual void GetFacet(CATICkeMKS::FacetType iFacetType, void* oFacet) = 0;
  // Sets the facet (bounds, tolerance, list of authorized values)
  virtual void SetFacet(CATICkeMKS::FacetType iFacetType, void* iFacet) = 0;
 

  // Gets the facet (bounds, tolerance, list of authorized values)
  virtual HRESULT GetFacet(CATICkeMKS::FacetType iFacetType, CATListOfDouble & oList) const=0;
  virtual HRESULT GetFacet(CATICkeMKS::FacetType iFacetType, CATListOfCATUnicodeString & oList) const=0;

  // Sets the facet (bounds, tolerance, list of authorized values)
  virtual HRESULT SetFacet(CATICkeMKS::FacetType iFacetType, const CATListOfDouble & iList)=0;
  virtual HRESULT SetFacet(CATICkeMKS::FacetType iFacetType, const CATListOfCATUnicodeString & iList)=0;
  
  virtual CATICkeMKSUnit_var GetMKS () const = 0;

  // return true is OK MKS, false instead
  virtual CATCke::Boolean    SetMKS (const CATICkeMKSUnit_var u) = 0; 
  
private:

  // 2 define ClassName
  CATDeclareInterface;


}; 

CATDeclareHandler(CATICkeMKS,CATBaseUnknown);

#endif


