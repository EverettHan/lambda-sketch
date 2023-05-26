// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBodyBuilder
//
//===================================================================
//
// October 2010  Creation: NDO
//===================================================================
#ifndef CATTessBodyBuilder_H
#define CATTessBodyBuilder_H

#include "TessBodyAdapters.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATTessParam.h"
#include "CATCGMTessBodyList.h"

#include "ListPOfCATFace.h"
class CATSoftwareConfiguration;
class CATBody;
class CATTessCurveDiscretizer;
class CATTessSurfaceDiscretizer;
class CATTessSurfaceRegularizer;

class CATPGMTessBody;
class CATCGMTessBody;
class CATCGMTessParam;
class CATTessParamToken;

//class CATTessBodyBuilderObserver;


/**
 * Builder that creates an instance of CATPGMTessBody from a CATBody and the tessellation parameters.
 * This builder uses global or incremental tessellation.
*/
class ExportedByTessBodyAdapters CATTessBodyBuilder
{

public:

  CATTessBodyBuilder ();

  ~CATTessBodyBuilder ();

  // From CATCGMVirtualItf/IUnknown.
  ULONG Release ();

public:

  void SetSoftwareConfiguration (CATSoftwareConfiguration& iConfiguration); 

  void SetBody (CATBody* iBody);

  // TO DO: Get rid of redundance of parameters.
  void SetTessParam (const CATTessParam& iParam);
  void SetTessParam (const CATCGMTessParam& iParam);

  void SetCurveDiscretizer (CATTessCurveDiscretizer& iCurveDiscretizer);

  void SetSurfaceDiscretizer (CATTessSurfaceDiscretizer& iSurfaceDiscretizer);

  void SetSurfaceRegularizer (CATTessSurfaceRegularizer& iSurfaceRegularizer);

  // Get rid of me?
  void DoDynamicTessellation (CATBoolean iDoDynamicTessellation);

  void AddTessBody (CATCGMTessBody& iCGMTessBody);

  void RemoveTessBody (CATCGMTessBody& iCGMTessBody);

public:

  CATBody* GetBody () const;
  CATSoftwareConfiguration* GetSoftwareConfiguration () const;

  const CATTessParam& GetTessParam () const;

  //LVL TEST LOCALTESS
  int SetListOfFaceToBeTessellated(CATLISTP(CATFace) & iListOfFace,CATBoolean iWithGarantee);
public:

  unsigned int GetNbTessBodies () const;

  // Iterator that cycles through all the input CATCGMTessBody entities.
  class ExportedByTessBodyAdapters Iterator
  {
  public:
    inline Iterator (const CATTessBodyBuilder& iBuilder) : _TessBodies (iBuilder._InputTessBodies), _Index (1) {}

    inline CATCGMTessBody* operator * () const {return _TessBodies[_Index];}
    inline CATBoolean End () const {return _Index > unsigned(_TessBodies.Size ());}
    inline Iterator& operator++ () {++_Index; return *this;}

  private:
    const CATCGMTessBodyList& _TessBodies;
    unsigned int _Index;
  };

public:

  /**
   * Runs the builder.
   * @param oTessBody
   *   The constructed CATPGMTessBody.  The constructed instance must be released by the caller.
   * @return
   *   <ul>
   *      <li> <tt>S_OK</tt> if a CATPGMTessBody is constructed without any tessellation errors.
   *      <li> <tt>S_FALSE</tt> if a CATPGMTessBody is constructed with some tessellation errors.
   *      <li> <tt>E_FAIL</tt> if a serious error occurs and a CATPGMTessBody could not be constructed.
   *   </ul>
   */
  HRESULT Run (CATPGMTessBody*& oTessBody);

public:

  // Phoenix extension.

  // Reserved for Phoenix.
  static CATPGMTessBody* NewTessBody (CATBody& iBody, const CATTessParamToken& iToken);

private:

  CATSoftwareConfiguration* _SoftwareConfiguration;
  CATBody* _Body;
  CATTessParam _TessParam;
  CATBoolean _TessParamSet;

  CATBoolean _DynamicTessellation;

  CATTessCurveDiscretizer* _CurveDiscretizer;
  CATTessSurfaceDiscretizer* _SurfaceDiscretizer;
  CATTessSurfaceRegularizer* _SurfaceRegularizer;

  CATCGMTessBodyList _InputTessBodies;  // List of input tess bodies.

  //LVL TEST LOCALTESS
  CATLISTP(CATFace) _ListOfFaceToBeTessellated;
  CATBoolean _WithGarantee;

  friend class Iterator;

private:

  // For capture of the operator (Phoenix).
  //CATTessBodyBuilderObserver* _Observer; 
  friend class CATechExt_TessBodyBuilder;

};


#endif // !CATTessBodyBuilder_H
