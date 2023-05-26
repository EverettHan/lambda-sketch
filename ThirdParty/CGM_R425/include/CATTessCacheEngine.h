//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATTessCacheEngine
//
//=============================================================================
// 2009-07-29 MPX: New
//=============================================================================
#ifndef CATTessCacheEngine_H
#define CATTessCacheEngine_H

#include "TessCacheEngine.h"
#include "CATTessCacheEngineBase.h"
#include "ListPOfCATFace.h"


class CATTessCurveDiscretizer;
class CATTessSurfaceDiscretizer;
class CATTessSurfaceRegularizer;

////////////////////////////////////////////////////////////////////////////////
//
// class CATTessCacheEngine
//
// Purpose:
//    This class is to be used as an interface for 
//      - defining tessellation parameters.
//           CATTessCacheEngine::DefineTessellationParameters()
//      - querying/creating tessellation (cache) data.
//           CATTessCacheEngine::GetExistingTessParamTokens()
//           CATTessCacheEngine::GetTessParamForGivenToken()
//           CATTessCacheEngine::GetTessellationData()
//           CATTessCacheEngine::GenerateTessCacheForEntireBody()
//      - removing tessellation (cache) data.
//           CATTessCacheEngine::RemoveTessCacheData()
//
// Internals:
//    This class is derived from CATTessCacheEngineBase which provides most
//    of the functionality for this engine class.
//    But CATTessCacheEngineBase does not have the actual tessellation
//    functionality. This is provided by CATTessCacheEngine using
//    functionality from "Tessellation" Fw.
//
// Sample Usage/Workflow:
//
//    Background: Lets say you have a CATBody and you need to get tessellation
//                data for some CATFace(s) and CATEdge(s) "under" this CATBody.
//
//    Steps:
//
//      1. Decide the tessellation parameters you require and represent
//         them in a CATTessParam object (say MyTessParams).
//
//      2. Query for the existing tokens on the CATBody 
//           [ using CATTessCacheEngine::GetExistingTessParamTokens() ]
//
//      3. Get the tessellation parameters corresponding to these tokens
//           [ using CATTessCacheEngine::GetTessParamForGivenToken() ]
//
//      4. Check if any of the tessellation parameters are good enough for you by
//         comparing the existing tessellation parameters (found from #3) with 
//         MyTessParams (from #1)
//           [ using CATTessParam::IsEqualTo() ]
//
//      5. If yes, then choose this token for further use. If not, then create 
//         a new token with MyTessParams.
//           [ using CATTessCacheEngine::DefineTessellationParameters() ]
//
//      6. If yes, then choose this token for further use. If not, then create 
//         a new token with MyTessParams.
//           [ using CATTessCacheEngine::DefineTessellationParameters() ]
// 
//      7. Now get the tessellation data for the required CATFace(s) and CATEdge(s) 
//         "under" this CATBody.
//           [ using CATTessCacheEngine::GetTessellationData() ]
// 
//      8. Remember to call Release() on the CATTessFaceDataCache / CATTessEdgeDataCache
//         after use.
//
//      9. (Optional) Remove all the tessellation cache data generated in this session
//         with the new token you created. 
//           [ using CATTessCacheEngine::RemoveTessCacheData() ]
//
//      If step #9 is not done, then,
//      1. The tessellation cache data will remain on attributes
//         until the CATBody is alive. 
//      2. But it will not cause any memory leak, since it will be deleted
//         when the CATBody gets deleted
//      3. It will be available for use by any subsequent client that needs
//         tessellation cache and thereby save some time.
//      4. At present, the tessellation cache is not persistent (not saved to file).
//         But watch this space, it may get persistent in future.
//
////////////////////////////////////////////////////////////////////////////////


class ExportedByTessCacheEngine CATTessCacheEngine
  : public CATTessCacheEngineBase
{

public:

  
  ////////////////////////////////////////////////////
  // Interfaces for defining tessellation parameters
  ////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Define tessellation parameters
  //
  // Parameters:
  //    iBody : Body whose faces and edges need to be processed subsequently for Tessellation Cache
  //    iTessParam : Parameters for tessellation
  //    ioToken: Returned token. This token will have to be passed by the caller to request for 
  //             tessellation for any CATFace or CATEdge in this CATBody.
  //
  // Note:
  //    1. This function does not trigger tessellation of the CATFace or CATEdge.  It just sets the 
  //       tessellation parameters in an attribute for the CATBody.
  //    2. The token created here, should NOT be used with any CATFace or CATEdge that is not
  //       "under" this CATBody

  INLINE static HRESULT DefineTessellationParameters(
            CATBody& iBody, 
            const CATTessParam& iTessParam, 
            CATTessParamToken& ioToken);


  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Define tessellation parameters
  //    (same as the above function, but with CATFace, instead of CATBody)
  // Note:
  //    1. Use this function only when you need tessellation for only one CATFace and its CATEdge's
  //    2. The token created here, should NOT be used with any other CATFace or any CATEdge that is not
  //       "under" this CATFace

  INLINE static HRESULT DefineTessellationParameters(
            CATFace& iFace, 
            const CATTessParam& iTessParam, 
            CATTessParamToken& ioToken);

  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Define tessellation parameters
  //    (same as the above function, but with CATEdge)
  // Note:
  //    1. Use this function only when you need tessellation for only one CATEdge
  //    2. The token created here, should NOT be used with any other CATFace or CATEdge

  INLINE static HRESULT DefineTessellationParameters(
            CATEdge& iEdge, 
            const CATTessParam& iTessParam, 
            CATTessParamToken& ioToken);



  //////////////////////////////////////////////////////////////////
  // Interfaces for querying parameters for existing tessellation 
  //////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Query for available tokens for a given CATBody/CATFace/CATEdge
  //
  // Parameters:
  //    iBody/iFace/iEdge : Body/Face/Edge to be queried
  //    oTokens : Returned list of all the token's available.

  INLINE static HRESULT GetExistingTessParamTokens(
            CATBody& iBody, 
            ListVOfCATTessParamToken& oTokens);

  INLINE static HRESULT GetExistingTessParamTokens(
            CATFace& iFace, 
            ListVOfCATTessParamToken& oTokens);

  INLINE static HRESULT GetExistingTessParamTokens(
            CATEdge& iEdge, 
            ListVOfCATTessParamToken& oTokens);


  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Query for tessellation parameters for a given token
  //
  // Parameters:
  //    iBody/iFace/iEdge : Body/Face/Edge to be queried
  //    iToken : Token to be used for query
  //    oTessParam : Returned tessellation parameters corresponding to the given token
  //
  // Note: 
  //    This will be useful for the caller to find if any available tessellation parameters 
  //    are good for its use or will a request for new tessellation parameters be needed

  INLINE static HRESULT GetTessParamForGivenToken(
            CATBody& iBody, 
            const CATTessParamToken& iToken,
            CATTessParam& oTessParam);

  INLINE static HRESULT GetTessParamForGivenToken(
            CATFace& iFace, 
            const CATTessParamToken& iToken,
            CATTessParam& oTessParam);

  INLINE static HRESULT GetTessParamForGivenToken(
            CATEdge& iEdge, 
            const CATTessParamToken& iToken,
            CATTessParam& oTessParam);


  //////////////////////////////////////////////////////////////////
  // Interfaces for requesting tessellation data 
  //////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Request tessellation data from a CATFace/CATEdge for the given token.
  //
  // Parameters:
  //    iFace/iEdge : Face/edge whose tessellation data is required
  //    iToken : Token for Tessellation Parameters to be used for creating tessellation
  //             or searching for available tessellation data
  //    oTessData : Returned tessellation data. The caller must call Release() on this
  //                object after its use.
  //
  // Internal action:
  //    Get the tessellation attribute with a matching token.
  //    1. If there is no attribute present, or if no match is found for the token, then:
  //        - tessellate the face/edge and generate new tess cache. 
  //        - create a new cache attribute on face/edge if not present already
  //        - create a new entry in this attribute with the newly created tess cache 
  //          and the given token
  //        - Return the tess cache.
  //    2. If there is tessellation data available in the attribute, and it is computed 
  //       with the same tessellation parameters (within factory resolution), 
  //       but with a different token, then:
  //        - create a new entry in this attribute with the matching tess cache found
  //          (ref incremented) and with the user given token (not the original token)
  //        - Return the tess cache.
  //    3. If a matching token is found, then just return the corresponding tess cache 

  static HRESULT GetTessellationData(
            CATFace& iFace,
            const CATTessParamToken& iToken,
            const CATTessFaceDataCache*& oTessData);

  static HRESULT GetTessellationData(
            CATEdge& iEdge,
            const CATTessParamToken& iToken,
            const CATTessEdgeDataCache*& oTessData);


  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Generate tessellation cache for all CATFace's and CATEdge's "under" the given CATBody 
  //    with the given token. This will generate water-tight tessellation.
  //
  // Parameters:
  //    iBody : Body whose faces and edges need to be tessellated
  //    iToken : Token for Tessellation Parameters to be used for creating tessellation
  //    iExcludeEdges : If TRUE, then no tessellation cache is generated for edges in this call
  //    iExcludeFaces : If TRUE, then no tessellation cache is generated for faces in this call
  //    iProgressBar : Pointer to caller's progress bar. If CATCGMProgressBar::Callback() 
  //                   returns FALSE (indicating interrupt/abort), then the function
  //                   quits immediately and returns E_ABORT.
  //
  // Note:
  //    1. If the progress bar is passed and if CATCGMProgressBar::Callback() returns FALSE 
  //       (indicating interrupt/abort), then the functions quits immediately. It does not remove
  //       the tess cache it has already generated. The caller has the option to remove the cache 
  //       (by calling CATTessCacheEngine::RemoveTessCacheData()) that got generated, or do nothing,
  //       i.e. keep whatever cache has already been computed, so that the next call does not have 
  //       to redo the work that is already done.

    static HRESULT GenerateTessCacheForEntireBody(
            CATBody& iBody, 
            const CATTessParamToken& iToken,
            CATBoolean iExcludeEdges = FALSE,
            CATBoolean iExcludeFaces = FALSE,
            CATCGMProgressBar* iProgressBar = 0);

  //LVL TEST LOCALTESS
    static HRESULT GenerateTessCacheForEntireBody(
            CATBody& iBody, 
            const CATTessParamToken& iToken,
            CATLISTP(CATFace)& iListFaceToBeTessellated,
            CATBoolean iExcludeEdges = FALSE,
            CATBoolean iExcludeFaces = FALSE,
            CATCGMProgressBar* iProgressBar = 0);

  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Generate UV tessellation cache for all CATFace's and CATEdge's "under" the given CATBody 
  //    with the given token.
  //
  // Parameters:
  //    iBody : Body whose faces and edges need to be tessellated
  //    iToken : Token for Tessellation Parameters to be used for creating tessellation
  //    iCurveDiscretizer: Custom curve discretizer for UV
  //    iSurfaceDiscretizer: Custom surface discretizer for UV
  //    iSurfaceRegularizer: Custom surface regularizer for UV
  //
  // Note:
  //    The CATTessParamToken should be created with UV definition of CATTessParam

  static HRESULT GenerateUVTessCacheForEntireBody(
            CATBody& iBody, 
            const CATTessParamToken& iToken,
            CATTessCurveDiscretizer* iCurveDiscretizer,
            CATTessSurfaceDiscretizer* iSurfaceDiscretizer,
            CATTessSurfaceRegularizer* iSurfaceRegularizer);

  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Do incremental tessellation to generate tessellation cache for all 
  //    CATFace's and CATEdge's "under" the given CATBody with the given token.
  //    This will reuse the tessellation corresponding to the given old tokens
  //    wherever possible.
  //
  // Parameters:
  //    iBody : Body whose faces and edges need to be tessellated
  //    iOldTokens : List of old tokens, whose tessellation can be reused for incremental tessellation
  //    iNewToken : New token for Tessellation Parameters to be used for creating tessellation
  //    iExcludeEdges : If TRUE, then no tessellation cache is generated for edges in this call
  //    iExcludeFaces : If TRUE, then no tessellation cache is generated for faces in this call
  //    iProgressBar : Pointer to caller's progress bar. If CATCGMProgressBar::Callback() 
  //                   returns FALSE (indicating interrupt/abort), then the function
  //                   quits immediately and returns E_ABORT.

  static HRESULT GenerateIncrTessCacheForEntireBody(
            CATBody& iBody, 
            ListVOfCATTessParamToken& iOldTokens,
            const CATTessParamToken& iNewToken,
            CATBoolean iExcludeEdges = FALSE,
            CATBoolean iExcludeFaces = FALSE,
            CATCGMProgressBar* iProgressBar = 0);


  //////////////////////////////////////////////////////////////////
  // Interfaces for removing/cleaning up tessellation cache data 
  //////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Remove all tessellation cache data corresponding to a given token 
  //    from attributes on all the faces and edges "under" the given CATBody
  //
  // Parameters:
  //    iBody: Body with which this token was generated (using DefineTessellationParameters)
  //
  // Note:
  //    After calling this function, this token becomes useless for any future use.

  INLINE static HRESULT RemoveTessCacheData(
            CATBody& iBody,
            const CATTessParamToken& iToken);

  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Remove all tessellation cache data corresponding to a given token 
  //    from attributes on this CATface and all edges "under" the given CATFace
  //
  // Parameters:
  //    iFace: Face with which this token was generated (using DefineTessellationParameters)
  //
  // Note:
  //    After calling this function, this token becomes useless for any future use.

  INLINE static HRESULT RemoveTessCacheData(
            CATFace& iFace,
            const CATTessParamToken& iToken);

  /////////////////////////////////////////////////////////////////////////
  // Action: 
  //    Remove all tessellation cache data corresponding to a given token 
  //    from attribute on this CATEdge
  //
  // Parameters:
  //    iEdge: Edge with which this token was generated (using DefineTessellationParameters)
  //
  // Note:
  //    After calling this function, this token becomes useless for any future use.

  INLINE static HRESULT RemoveTessCacheData(
            CATEdge& iEdge,
            const CATTessParamToken& iToken);

public:

  // For internal use

  INLINE static HRESULT GetTessParamForGivenToken(
            const CATTessParamToken& iToken,
            CATTessParam& oTessParam);

  INLINE static HRESULT CreateNewBlankTessellationData(
            CATCell& iCell,
            const CATTessParamToken& iToken,
            CATTessDataCache*& oTessData);

  INLINE static HRESULT GetExistingTessellationData(
            CATCell& iCell,
            const CATTessParamToken& iToken,
            const CATTessDataCache*& oTessData);

  INLINE static HRESULT RemoveLocalTessCache(
            CATCell& iCell, 
            const CATTessParamToken& iToken);

  static HRESULT GenerateTessCacheForEntireBody(
            CATBody& iBody, 
            const CATTessParamToken& iToken,
            ListVOfCATTessParamToken* iRefTokens,
            CATTessCurveDiscretizer* iCurveDiscretizer,
            CATTessSurfaceDiscretizer* iSurfaceDiscretizer,
            CATTessSurfaceRegularizer* iSurfaceRegularizer,
            CATBoolean iExcludeEdges,
            CATBoolean iExcludeFaces,
            CATCGMProgressBar* iProgressBar);

//LVL TEST LOCALTESS
  static HRESULT GenerateTessCacheForEntireBody(
            CATBody& iBody, 
            const CATTessParamToken& iToken,
            CATLISTP(CATFace) & iListFaceToBeTessellated,
            ListVOfCATTessParamToken* iRefTokens,
            CATTessCurveDiscretizer* iCurveDiscretizer,
            CATTessSurfaceDiscretizer* iSurfaceDiscretizer,
            CATTessSurfaceRegularizer* iSurfaceRegularizer,
            CATBoolean iExcludeEdges,
            CATBoolean iExcludeFaces,
            CATCGMProgressBar* iProgressBar);
};




INLINE HRESULT CATTessCacheEngine::DefineTessellationParameters(
            CATBody& iBody, 
            const CATTessParam& iTessParam, 
            CATTessParamToken& ioToken)
{
  return CATTessCacheEngineBase::DefineTessellationParameters(
            iBody, 
            iTessParam, 
            ioToken);
}

INLINE HRESULT CATTessCacheEngine::DefineTessellationParameters(
            CATFace& iFace, 
            const CATTessParam& iTessParam, 
            CATTessParamToken& ioToken)
{
  return CATTessCacheEngineBase::DefineTessellationParameters(
            iFace, 
            iTessParam, 
            ioToken);
}

INLINE HRESULT CATTessCacheEngine::DefineTessellationParameters(
            CATEdge& iEdge, 
            const CATTessParam& iTessParam, 
            CATTessParamToken& ioToken)
{
  return CATTessCacheEngineBase::DefineTessellationParameters(
            iEdge, 
            iTessParam, 
            ioToken);
}

INLINE HRESULT CATTessCacheEngine::GetExistingTessParamTokens(
            CATBody& iBody, 
            ListVOfCATTessParamToken& oTokens)
{
  return CATTessCacheEngineBase::GetExistingTessParamTokens(
            iBody, 
            oTokens);
}

INLINE HRESULT CATTessCacheEngine::GetExistingTessParamTokens(
            CATFace& iFace, 
            ListVOfCATTessParamToken& oTokens)
{
  return CATTessCacheEngineBase::GetExistingTessParamTokens(
            iFace, 
            oTokens);
}

INLINE HRESULT CATTessCacheEngine::GetExistingTessParamTokens(
            CATEdge& iEdge, 
            ListVOfCATTessParamToken& oTokens)
{
  return CATTessCacheEngineBase::GetExistingTessParamTokens(
            iEdge, 
            oTokens);
}

INLINE HRESULT CATTessCacheEngine::GetTessParamForGivenToken(
            CATBody& iBody, 
            const CATTessParamToken& iToken,
            CATTessParam& oTessParam)
{
  return CATTessCacheEngineBase::GetTessParamForGivenToken(
            iBody, 
            iToken,
            oTessParam);
}

INLINE HRESULT CATTessCacheEngine::GetTessParamForGivenToken(
            CATFace& iFace, 
            const CATTessParamToken& iToken,
            CATTessParam& oTessParam)
{
  return CATTessCacheEngineBase::GetTessParamForGivenToken(
            iFace, 
            iToken,
            oTessParam);
}

INLINE HRESULT CATTessCacheEngine::GetTessParamForGivenToken(
            CATEdge& iEdge, 
            const CATTessParamToken& iToken,
            CATTessParam& oTessParam)
{
  return CATTessCacheEngineBase::GetTessParamForGivenToken(
            iEdge, 
            iToken,
            oTessParam);
}

INLINE HRESULT CATTessCacheEngine::GetTessParamForGivenToken(
            const CATTessParamToken& iToken,
            CATTessParam& oTessParam)
{
  return CATTessCacheEngineBase::GetTessParamForGivenToken(
            iToken,
            oTessParam);
}

INLINE HRESULT CATTessCacheEngine::RemoveTessCacheData(
            CATBody& iBody,
            const CATTessParamToken& iToken)
{
  return CATTessCacheEngineBase::RemoveTessCacheData(
            iBody,
            iToken);
}

INLINE HRESULT CATTessCacheEngine::RemoveTessCacheData(
            CATFace& iFace,
            const CATTessParamToken& iToken)
{
  return CATTessCacheEngineBase::RemoveTessCacheData(
            iFace,
            iToken);
}

INLINE HRESULT CATTessCacheEngine::RemoveTessCacheData(
            CATEdge& iEdge,
            const CATTessParamToken& iToken)
{
  return CATTessCacheEngineBase::RemoveTessCacheData(
            iEdge,
            iToken);
}

INLINE HRESULT CATTessCacheEngine::CreateNewBlankTessellationData(
            CATCell& iCell,
            const CATTessParamToken& iToken,
            CATTessDataCache*& oTessData)
{
  return CATTessCacheEngineBase::__CreateNewBlankTessellationData(
            iCell,
            iToken,
            oTessData);
}

INLINE HRESULT CATTessCacheEngine::GetExistingTessellationData(
            CATCell& iCell,
            const CATTessParamToken& iToken,
            const CATTessDataCache*& oTessData)
{
  return CATTessCacheEngineBase::__GetExistingTessellationData(
            iCell,
            iToken,
            oTessData);
}

INLINE HRESULT CATTessCacheEngine::RemoveLocalTessCache(
            CATCell& iCell, 
            const CATTessParamToken& iToken)
{
  return CATTessCacheEngineBase::__RemoveLocalTessCache(
            iCell,
            iToken);
}

#endif // !CATTessCacheEngine_H

