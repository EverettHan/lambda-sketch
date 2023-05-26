#ifndef CATDynDraftReorderZone_H
#define CATDynDraftReorderZone_H

#include "Draft.h"

#include "CATCGMVirtual.h"
#include "CATBoolean.h"//CATBoolean
#include "CATTopDefine.h"// CATOrientation
#include "CATMathDef.h"//CATLength

class CATPoint;
class CATPlane;
class CATCGMOutput;
class CATMathPoint;

//class defining parameters used to modify the default reorder zone
class ExportedByDraft CATDynDraftReorderZoneParams: public CATCGMVirtual
{
  public:
  
    virtual ~CATDynDraftReorderZoneParams();

    /**
    * Constructs CATDynDraftReorderZone
    * @param iStartOffset
    * The offset from the start limit of this reorder zone, Positive value widens the default reorder zone
    * @param iEndOffset
    * The offset from the end limit of this reorder zone, Positive value widens the default reorder zone
    * @param iStartRot1
    * The rotation of start default reorder plane about draft surface normal in degrees,
    * Positive value widens the default reorder zone
    * @param iEndRot1
    * The rotation of end default reorder plane about draft surface normal in degrees,
    * Positive value widens the default reorder zone
    * @param iStartRot2
    * The rotation of start default reorder plane about draft direction in degrees,
    * Positive value widens the default reorder zone
    * @param iEndRot2
    * The rotation of end default reorder plane about draft direction in degrees,
    * Positive value widens the default reorder zone
    */

    CATDynDraftReorderZoneParams(CATLength iStartOffset, CATLength iEndOffset = 0
                                ,CATAngle iStartRot1 = 0, CATAngle iEndRot1 = 0
                                ,CATAngle iStartRot2 = 0, CATAngle iEndRot2 = 0 );

    CATDynDraftReorderZoneParams(const CATDynDraftReorderZoneParams &iReorderParamToCopy );

    CATDynDraftReorderZoneParams(const CATDynDraftReorderZoneParams* iReorderParams);

    void GetStartParams(CATLength* oStartOffset, CATAngle* oStartRot1 = 0, CATAngle* oStartRot2 = 0);

    void GetEndParams(CATLength* oEndOffset, CATAngle* oEndRot1 = 0, CATAngle* oEndRot2 = 0);

    void Dump(CATCGMOutput &os);

  protected:

    CATDynDraftReorderZoneParams();  

    void Init();

    CATLength _StartOffset; //offset from start of default reorder zone, 
                            //+ve implies out of reorder zone from the start limit of reorder zone
    CATAngle _StartRotDraftNorm; //rotation of start default reorder plane about draft surface normal
                                //+ve value causes widening of reorder zone
    CATAngle _StartRotDraftDir;//rotation of start default reorder plane about draft direction
                              //+ve value causes widening of reorder zone
    //Parameters for end limit of reorder zone
    CATLength _EndOffset;
    CATAngle _EndRotDraftNorm; 
    CATAngle _EndAngDraftDir;
};

//class defining the reorder zone
class ExportedByDraft CATDynDraftReorderZone: public CATCGMVirtual
{
  public:

    virtual ~CATDynDraftReorderZone();

    /**
    * Constructs CATDynDraftReorderZone
    * @param iStartPoint
    * The Point corresponding to the start limit of this reorder zone
    * @param iEndPoint
    * The Point corresponding to the end limit of this reorder zone
    * @param iStartPlane
    * The Plane corresponding to the start limit of this reorder zone
    * @param iEndPlane
    * The Plane corresponding to the end limit of this reorder zone
    * @param iOrientAtStart
    * Whether we are specifying the orientation of reorder zone w.r.t start plane
    * <br><b>Legal values</b>: <tt>TRUE</tt> if yes, <tt>FALSE</tt> otherwise.
    * @param iOrient
    * The orientation <tt>iStartPlane</tt> or <tt>iEndPlane</tt> w.r.t this reorder zone
    * @param iAddMaterial
    * Whether the reorder zone corresponds to material addition.
    * <br><b>Legal values</b>: <tt>TRUE</tt> if yes, <tt>FALSE</tt> otherwise.
    */

    CATDynDraftReorderZone( CATPoint* iStartPoint, CATPoint* iEndPoint
                          , CATPlane* iStartPlane, CATPlane* iEndPlane
                          , CATBoolean iOrientAtStart = TRUE
                          , CATOrientation iOrient = CATOrientationPositive
                          , CATBoolean iAddMaterial = TRUE);
    
    CATDynDraftReorderZone(const CATDynDraftReorderZone &iReorderZoneToCopy );

    CATDynDraftReorderZone(const CATDynDraftReorderZone* iReorderZone);

    /**
    * Retrieves the definition of start limit of <tt>this</tt> reorder zone
    * @param oStartPoint
    */

    void GetStartLimit(CATPoint** oStartPoint, CATPlane** oStartPlane = 0);

    /**
    * Retrieves the definition of end limit of <tt>this</tt> reorder zone
    * @param oEndPoint
    */

    void GetEndLimit(CATPoint** oEndPoint, CATPlane** oEndPlane = 0);

    /**
    *Retrieves the oreintation of <tt>this</tt> reorder zone 
    * @param oOrient
    *This orienation is always w.r.t start plane for calculated reorder zone  
    */
    void GetOrientation(CATOrientation* oOrient, CATBoolean* oIsOrientAtStart=0);

    /*
    * Set the parameters which modify the reorder zone
    */
    void SetModificationParams( CATDynDraftReorderZoneParams* iParam);

    /*
    * Get the start and end limits 
    */
    void GetLimits(CATMathPoint &oStartPoint, CATMathPoint &oEndPoint);

    CATDynDraftReorderZoneParams* GetModificationParams();

    CATBoolean IsAddMaterial();

		// S9L : Draft Untwist Enhancement : Start
		void ReInitialize(CATPoint* iStartPoint, CATPoint* iEndPoint,
                      CATPlane* iStartPlane, CATPlane* iEndPlane);
		// S9L : Draft Untwist Enhancement : End

    void Dump(CATCGMOutput &os);

  protected:

    CATDynDraftReorderZone();

    void Init();

    //definition of the start of the reorder zone
    CATPoint* _StartPoint; //Point corresponding to the start limit of this reorder zone
    CATPlane* _StartPlane; //Plane corresponding to the start limit of this reorder zone
  
    //definition of the end of the reorder zone
    CATPoint* _EndPoint;
    CATPlane* _EndPlane; 

    CATBoolean _IsOrientAtStart;//TRUE if we are specifying the oreination of reorder zone
                                //w.r.t _StartPlane i.e _StartPlane is reference plane 
                                //else  _EndPlane is reference plane   
    CATOrientation _Orient; //Orientation of reference plane w.r.t reorder zone, 
                            //Positive implies that the reorder zone is on the same side as the
                            //normal of Reference plane

    //whether the reorder zone corresponds to material addition
    CATBoolean _AddMaterial;
    CATDynDraftReorderZoneParams* _ModParams;
    CATBoolean _ToDel;
};


/** 
 * @collection CATLISTP(CATDynDraftReorderZone)
 * Collection class for pointers to CATDynDraftReorderZone.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia. 
 */

#include "CATCGMLISTP_Declare.h"

class CATDynDraftReorderZone;

CATCGMLISTP_DECLARE(CATDynDraftReorderZone);

/** 
 * @collection CATLISTP(CATDynDraftReorderZoneParams)
 * Collection class for pointers to CATDynDraftReorderZoneParams.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia. 
 */

class CATDynDraftReorderZoneParams;

CATCGMLISTP_DECLARE(CATDynDraftReorderZoneParams);

#endif
