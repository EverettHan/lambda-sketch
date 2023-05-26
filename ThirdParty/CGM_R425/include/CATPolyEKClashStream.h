// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyEKClashStream.h
// Header definition of CATPolyEKClashStream
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// December 2013 Creation JXO
//===================================================================
#ifndef CATPolyEKClashStream_H
#define CATPolyEKClashStream_H

// ExportedBy
#include "PolyEKNodes.h"

// Poly
#include "CATBVHTreeRepBuilder.h"
class CATPolyEKUnstream;
class CATPolyInterferenceList;
class CATIPolyInterference;
class CATPolyCollisionInterfList;

// Visu
class CAT3DRep;

// Math
class CATMathTransformation;

// Experience kernel
#include "EKBinary.h"
namespace EK
{
    class BinaryWriter;
};

class ExportedByPolyEKNodes CATPolyEKClashStream
{
public:
  /** Creates a binary stream to be sent to a CATPolyEKBVHTreeSet */
  static EK::Binary StreamRep(int setid, int objectId, CAT3DRep * object, const CATMathTransformation * pos = 0, CATBVHTreeRepBuilder::EntityType iEntityTypes = CATBVHTreeRepBuilder::eFaceEntities);
  /** Creates a binary stream to be sent to a CATPolyEKBVHTreeSet */
  static EK::Binary StreamRemoveRep(int setid, int objectId);
  /** Creates a binary stream to be sent to a CATPolyEKBVHTreeSet */
  static EK::Binary StreamModifyPosition(int setid, int objectId, const CATMathTransformation * pos);

  /** Creates a binary stream to be sent to any node
   * @param interf won't be released. 
   * @param nbclashes, nbbars, nbcontacts, nbclosedcurves statistics 
   */
  static EK::Binary StreamClashResult(CATPolyInterferenceList * interf, int * nbclashes = 0, int * nbbars = 0, int * nbcontacts = 0, int * nbclosedcurves = 0);

  /** Creates a binary stream to be sent to any node
   * @param interf won't be released. 
   * @param nbclashes, nbcontactpoints statistics 
   */
  static EK::Binary StreamClashResult(CATPolyCollisionInterfList * interf, int * nbclashes = 0, int * nbcontactpoints = 0);


  /** Unstreams a binary. See CATPolyEKUnstream for supported streams.
   * @return [out, IUnknown#Release] 
   */
  static CATPolyEKUnstream * Unstream(const EK::Binary & iBin);


protected:
  // Enum to decrypt binary buffer
  enum binkey
  {
    eUndefined = 0,
    eVersion,
    // Rep
    eSetId,
    eObjectId,
    eTwelveDoublesPosition,
    eEntityType,
    eCgr,
    eUvr,
    eStreamSize,
    // Actions
    eRemoveRep,
    eModifyPosition,
    // Interf
    eNbInterfs,
    eNewInterf,
    eInclusionStatus,
    eNbCurves,
    eThreeDoublesContactPoint1,
    eThreeDoublesContactPoint2,
    ePushInterf,
    eNbBars,
    eNbCurveVertices,
    eCurveIsClosed,
    // Collision interf
    eDepthPenetrationData,
    eNbContactPoints
  };

protected:
  CATPolyEKClashStream(){}
  ~CATPolyEKClashStream(){}
  static HRESULT PushInterf(EK::BinaryWriter & binWriter, CATIPolyInterference * curInterf, int & nbclashes, int & nbbars, int & nbcontacts, int & nbclosedcurves, int & nbcontactpoints);
};

#endif
