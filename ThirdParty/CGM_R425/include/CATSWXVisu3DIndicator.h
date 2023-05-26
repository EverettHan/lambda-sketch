#pragma once 

#include "CATVisFoundation.h"
#include "CAT3DIndicator.h"

class CATSWXVisuBasic3DViewpointEditor;
class CAT3DViewpoint;
class CATMouseEvent;

/** Class to retrieve mouse interaction not implying graphic representations.*/
class ExportedByCATVisFoundation CATSWXVisu3DIndicator : public CAT3DIndicator
{
    CATDeclareClass;

public:
    /** Construct a CATSWXVisu3DIndicator 
    * @param iFather
    * @param iName
    * @param iviewpoint  The viewpoint used to compute the CATIndicationSegment*/
    CATSWXVisu3DIndicator(CATVizViewer *iFather, const CATString &iName, CAT3DViewpoint &iViewpoint);
    virtual ~CATSWXVisu3DIndicator();

    void InternalDeviceEventCB(CATCallbackEvent ie, void *, CATNotification *iEvent, CATSubscriberData is, CATCallback icb);

    void SetViewpointEditor(CATSWXVisuBasic3DViewpointEditor* iIndic);

    static void RebuildFromWheelEventCB(CATCommand* iCmd, int iTime, void* iClientData);

private:
    CATSWXVisuBasic3DViewpointEditor* mViewpointEditor;

    CATVizViewer* mVizViewer;
    CATCallback mMouseCB;

    CATMouseEvent *mLastWheelEvent;
    int mRebuildTimerCallbackID;

    void RebuildFromWheelEvent();
    int HandleWheelZoom(CATMouseEvent &iMouseEvent);
    void HandleZoomDynamics();

    static const int mRemoveDynamicTimeoutMS;

    friend class CATSWXVisuBasic3DViewpointEditor;
};
