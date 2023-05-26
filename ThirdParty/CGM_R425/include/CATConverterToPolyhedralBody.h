/* -*-C++-*-*/
#ifndef CATConverterToPolyhedralBody_H
#define CATConverterToPolyhedralBody_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATConverterToPolyhedralBody
//
// DESCRIPTION :
// Convert a CATBody with exact geometry into a polyhedral CATBody in the ContainerCGM
// with the full BRep description
//
//
// History
//
// May. 2016 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolyTessBody.h"     // ExportedBy
#include "CATCGMJournal.h"  


class CATGeoFactory;
class CATTopData;
class CATBody;


class ExportedByGMPolyTessBody CATConverterToPolyhedralBody : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATConverterToPolyhedralBody);

public:


  /**
  * Destructor
  */
  virtual ~CATConverterToPolyhedralBody();


  //=============================================================================
  // Optional Settings
  //=============================================================================
    
  /**
  * Sets the sag as the maximum deviation between the generated triangles (resp. bars) and the original surfaces (resp. curves)
  * The input value must include the scale factor.
  * If not set, the default value will be the Tolerant Resolution (0.1 mm at NormalScale)
  */
  virtual void SetSag (double iSag)=0;

  /**
  * Sets the maximum step size. 
  * The input value must include the scale factor.
  * If not set, the default value will be 1.e12 mm (at NormalScale)
  */
  virtual void SetMaxStep (double iMaxStep)=0;

  /**
  * Sets the maximum radian angle not to be exceeded.  
  * If not set, the default value will be (CATPI * 0.25)
  */
  virtual void SetMaxAngle (double iMaxAngle)=0;


  /** 
  * Sets the type of journal items 
  * (CATCGMJournal::Creation or CATCGMJournal::Modification)
  * default is Creation
  */
  virtual void SetJournalType(CATCGMJournal::Type iJournalType)=0;



protected:

  /*
  * @nodoc
  * @nocgmitf
  * cannot be called, constructor for derived classes only
  */
  CATConverterToPolyhedralBody(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt &iExtensible);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  /** @nodoc @nocgmitf */
  CATConverterToPolyhedralBody();
  /** @nodoc @nocgmitf */
  CATConverterToPolyhedralBody(const CATConverterToPolyhedralBody& iOneOf);
  /** @nodoc @nocgmitf */
  CATConverterToPolyhedralBody& operator =(const CATConverterToPolyhedralBody& iOneOf);
};

/**
 * Creates a CATConverterToPolyhedralBody operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBody
 * The pointer to the exact body to convert
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be deleted with the usual C++ delete operator after use.
 */
ExportedByGMPolyTessBody CATConverterToPolyhedralBody * CATCreateConverterToPolyhedralBody(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBody); 

#endif
