/* -*-C++-*-*/
#ifndef CATConverterPolyToExactBody_H
#define CATConverterPolyToExactBody_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATConverterPolyToExactBody
//
// DESCRIPTION :
// Convert a CATBody with polyhedral geometry into an exact CATBody in the ContainerCGM
// with the full BRep description
//
// LIMITATIONS :
// The conversion is limited to bodies with CATVertexInVolume or CATWire as highest domains (body dimension <= 1)
// Each polyhedral edge will be subdivided into a set of connected exact linear edges (one output edge per input bar)
// In the future, we can imagine to convert also polyhedral faces with a planar reference.
// 
//
// History
//
// Oct. 2016 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyImportExport.h"   // ExportedBy
#include "CATCGMJournal.h"
#include "CATCollec.h"
#include "CATListOfCATCells.h"    // ListPOfCATCell

class CATGeoFactory;
class CATTopData;
class CATGeometry;
class CATBody;
class CATDomain;
class CATCell;


class ExportedByGMPolyImportExport CATConverterPolyToExactBody : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATConverterPolyToExactBody);

public:


  /**
  * Destructor
  */
  virtual ~CATConverterPolyToExactBody();


  //=============================================================================
  // Optional Settings
  //=============================================================================

  /** 
  * @nodoc 
  * Sets the type of journal items 
  * (CATCGMJournal::Creation or CATCGMJournal::Modification)
  * default is Creation
	*/
	virtual void SetJournalType(CATCGMJournal::Type iJournalType) = 0;


  //=============================================================================
  // Result Information
  //=============================================================================

  /** 
  * @nodoc @nocgmitf
  * Returns the unique image domain of an input domain to convert
  */
  virtual CATDomain * GetSingleImageDomain(CATDomain * iInputDomain) const = 0;

  /** 
  * @nodoc @nocgmitf
  * Returns the unique image cell of an input cell to convert
  */
  virtual CATCell * GetSingleImageCell(CATCell * iInputCell) const = 0;

  /** 
  * @nodoc @nocgmitf
  * Returns the unique image cell of an input cell to convert
  */
  virtual void GetImageCells(CATCell * iInputCell, ListPOfCATCell &oImageCells) const = 0;

  /** 
  * @nodoc @nocgmitf
  * Returns a list of output geometries reported in Journal (as Creation or Modification depending on JournalType)
  */
  virtual void GetListOfReportedImages(CATLISTP(CATGeometry) &oReportedImages) const = 0;


protected:

  /*
  * @nodoc
  * @nocgmitf
  * cannot be called, constructor for derived classes only
  */
  CATConverterPolyToExactBody(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtensible);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  /** @nodoc @nocgmitf */
  CATConverterPolyToExactBody();
  /** @nodoc @nocgmitf */
  CATConverterPolyToExactBody(const CATConverterPolyToExactBody& iOneOf);
  /** @nodoc @nocgmitf */
  CATConverterPolyToExactBody& operator =(const CATConverterPolyToExactBody& iOneOf);
};

/**
 * Creates a CATConverterPolyToExactBody operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBody
 * The pointer to the polyhedral body to convert
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be deleted with the usual C++ delete operator after use.
 */
ExportedByGMPolyImportExport CATConverterPolyToExactBody * CATCreateConverterPolyToExactBody(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBody); 

#endif
