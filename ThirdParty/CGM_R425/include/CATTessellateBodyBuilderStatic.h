// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessellateBodyBuilderStatic
//
//===================================================================
//
// July 2012  Creation: TPG
//===================================================================
#ifndef CATTessellateBodyBuilderStatic_H
#define CATTessellateBodyBuilderStatic_H

#include "TessBodyAdapters.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATCGMTessellateParam.h"
#include "CATTessellateParam.h"

class CATSoftwareConfiguration;
class CATBody;
class CATPGMTessBody;
class CATCGMTessBody;

/**
 * Builder that creates an instance of CATPGMTessBody from a CATBody and the tessellation parameters.
 * This builder uses global or incremental tessellation.
*/
class ExportedByTessellateCommon CATTessellateBodyBuilderStatic
{

public:

  CATTessellateBodyBuilderStatic(CATBody& iBody, const CATTessellateParam& iParam);

  // deprecated
  CATTessellateBodyBuilderStatic ();

  ~CATTessellateBodyBuilderStatic ();

  // From CATCGMVirtualItf/IUnknown.
  ULONG Release ();

public:

  void SetBody (CATBody* iBody);

  void SetTessParam (const CATTessellateParam& iParam);

  //void SetTessParam (const CATCGMTessellateParam& iParam);

  // void SetSoftwareConfiguration (CATSoftwareConfiguration& iConfiguration); 

public:

  CATBody* GetBody () const;
  CATSoftwareConfiguration* GetSoftwareConfiguration () const;

  const CATTessellateParam& GetTessParam () const;

public:

  /**
   * Runs the builder.
   * @param oTessBody
   *   The constructed CATPGMTessBody.  The constructed instance must be released by the caller.
   * @param iGeomVisu
   *   GeomVisu mode: 3DExperience SG
   *   0: no
   *   1: yes
   * @param iPreProcessBody
   * PreProcessBody: compute internal model
   *   0: cell by cell (good when the Body is activated, upward links available).
   *   1: globally (good when the Body is not activated, upward links not available).
   * @return
   *   <ul>
   *      <li> <tt>S_OK</tt> if a CATPGMTessBody is constructed without any tessellation errors.
   *      <li> <tt>S_FALSE</tt> if a CATPGMTessBody is constructed with some tessellation errors.
   *      <li> <tt>E_FAIL</tt> if a serious error occurs and a CATPGMTessBody could not be constructed.
   *   </ul>
   */
  HRESULT Run (CATPGMTessBody*& oTessBody, int iGeomVisu=0, int iPreProcessBody=1);

  /**
   * Runs the builder.
   *   global computation - do not use only for test.
   */
  HRESULT RunGlobal (CATPGMTessBody*& oTessBody, int iGeomVisu=0);

  /**
  * working mode
  * iMode: 
  * 0: cpu +++ memory + (default).
  * 1: cpu ++  memory ++.
  * 2: cpu +   memory +++.
  * 3: cpu +++ memory + ().
  */
  void SetWorkingMode(int iMode);

  /**
  * vertex position precision
  * 0: float vertex position.
  * 1: double vertex position (by default option)
  */
  void SetPrecision(int iPrecision);

  /**
  * Micron Tessellation
  * 0:
  * 1:
  */
  void SetMicronTessellation(int iUnableMicronTessellation);

private:

  CATSoftwareConfiguration* _SoftwareConfiguration;
  CATBody* _Body;
  CATTessellateParam * _TessParam;
  int _WorkingModeFromTesellateBodyBuilderStatic;
  int _Precision;
  int _GlobalMode; // no delta: local = global
  int _UnableMicronTessellation;

  int _ConstructorWithoutAddRef; // H7W - Nov 2020 : CATICGMTessBodyLink extension of CATBody

private:

  // For capture of the operator (Phoenix).
  //CATTessellateBodyBuilderStaticObserver* _Observer; 
  //friend class CATechExt_TessBodyBuilder;

};


#endif // !CATTessellateBodyBuilderStatic_H
