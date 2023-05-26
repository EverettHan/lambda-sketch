#ifndef CATExtIVisuModelForRep_H
#define CATExtIVisuModelForRep_H

//
//  copyright dassault systemes 1999
//  --------------------------------
//
//  FrameWork Visualization :
//  -------------------------
//
//          author : Christophe Delattre
//
//  Abstract:
//  --------
//        Default extension of the CATModelForRep object which one wants to derive from
//        when adhering to CATI3DGeoVisu or CATI2DGeoVisu
//  ---------------------------------------------------------------------------
//
#include "SceneGraphManager.h"
#include "CATExtIVisu.h"

class CATRepWeakRef;
class ExportedBySceneGraphManager CATExtIVisuModelForRep : public CATExtIVisu
{
    CATDeclareClass;
public:
    CATExtIVisuModelForRep();
    virtual ~CATExtIVisuModelForRep();
    virtual CATRep* BuildRep();
    virtual CATRep* GiveRep();
    virtual CATRep* GetRep();
    virtual void UnreferenceRep();
    virtual HRESULT SetVisuRep(CATRep* iRep);
    virtual int ModifyRep(const CATNotification& iNotif);
    virtual HRESULT ChangeComponentState(ComponentState iFromState, ComponentState iToState, const CATSysChangeComponentStateContext* iContext);

protected:
    void UpdateWeakRefFromRep();

private:
    CATRepWeakRef* _weakRef;
};

#endif
