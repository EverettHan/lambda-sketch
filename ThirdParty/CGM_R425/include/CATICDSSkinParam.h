#ifndef CATICDSSkinParam_H
#define CATICDSSkinParam_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATCDSAdvancedEnums.h"
#include "CATCDSBoolean.h"
#include "CATCDSInline.h"

class CATICDSSkin;

/**
 * @SKIP
 *
 * Black-box object describing a parameter on a skin. It uses an input adapter 
 * object to make the binding with application implemented methods.
 */
class ExportedBySolverInterface CATICDSSkinParam
{
public:

  /**
   * Constructs an instance of the skin parameter.
   * @param iSkin
   *   A reference to the skin it parameterize.
   */
  CATICDSSkinParam(CATICDSSkin& iSkin);
  
  /** Destructor. */
  virtual ~CATICDSSkinParam();

  /** Retreive parameter's skin. */
  /// @SKIP
  CATICDSSkin& GetSkin() const;
  
  /**
   * Update parameter from another parameter, implementation
   * must make sure the two parameters describe the same skin.
   * @param ipParam
   *   Parameter to use as copy source.
   */
  virtual void CopyFrom(const CATICDSSkinParam *ipParam) = 0;

  /** @nodoc */
  virtual void * GetImp() const;
  
  // TODO peut on cacher tout ca ?
  virtual CATCSParamType GetParamType() = 0;
  virtual CATCDSBoolean IsParamOnWire() = 0;
  virtual CATCDSBoolean IsParamOnVertex() = 0;
  virtual CATCDSBoolean IsParamOnBorder() = 0;
  virtual int GetInformationOnVertex(int& oNbOfWires, int& oNbOfFaces) = 0;
  virtual int GetNextParamOnWire(CATICDSSkinParam* opPointOnSkin) = 0;
  virtual int GetNextParamOnFace(CATICDSSkinParam* opPointOnSkin) = 0;
  virtual int GetNextParamOnVertex(CATICDSSkinParam* opPointOnSkin) = 0;
  virtual CATCSContinuity GetContinuity() = 0;

private:

  void *_pImp;
  CATICDSSkin *_skin;
};

#endif
