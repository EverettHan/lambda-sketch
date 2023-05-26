/* -*-C++-*-*/
#ifndef CATGMPolyRelimitBodyTopOper_H
#define CATGMPolyRelimitBodyTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyRelimitBodyTopOper
//
// DESCRIPTION :
// ...
//
//
// History
//
// 201710 WMN Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolyBoolean.h"      // ExportedBy

#include "CATDataType.h"        // HRESULT
#include "CATMathInline.h"      // inline Methods
#include "ListPOfCATBody.h"     // aggregation
#include "CATTopDefine.h"       // CATSide

#include "CATBoolean.h"
#include "CATSysBoolean.h"


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyRelimitBodyTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyRelimitBodyTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyRelimitBodyTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyRelimitBodyTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyRelimitBodyTopOper() method to create an instance
  static CATGMPolyRelimitBodyTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyRelimitBodyTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================
    
  /** @nodoc */
  void SetNoSimplif(CATBoolean iNoSimplif);

  /**
  * Sets Selection Mode.
  * Allows to decide among 3 possible behaviors for the relimitation of a Volume by a shell: 
  * 0 : Keep Input Shell for relimitation, 
  * 1 : Replace single planar face by infinite plane if possible
  * 2 : Double Try - try to relimit with the shell and if no result and single planar shell, try again with infinite place
  * @param VolByShellMode
  * The selection mode. 0 (KeepShell) by default here.
  */
  void SetRelimitVolByShellMode(int VolByShellMode);

  void DisableSimplifMode();

  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();
	

protected:

  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolyRelimitBodyTopOper() method to create an instance
  CATGMPolyRelimitBodyTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyRelimitBodyTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyRelimitBodyTopOper();
  CATGMPolyRelimitBodyTopOper(const CATGMPolyRelimitBodyTopOper& iOneOf); 
  CATGMPolyRelimitBodyTopOper& operator =(const CATGMPolyRelimitBodyTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyRelimitBodyTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodiesToProcess
 * The list of pointers to the bodies to process
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyRelimitBodyTopOper * CATCreatePolyRelimitBodyTopOper(CATGeoFactory * ipFactory , CATTopData * ipTopData, CATBody * iTrimmingBody, CATBody * iRelimitedBody, CATSide iSideToKeep);

#endif
