//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
// CATSpaceDeformationSplitTool 
// FDF stands for function of deformation
// mother class for the split 
// This object enables the topological apply of deformation
// to know which cells of the bofy will be impacted by the deformation
// 
//==========================================================================
// Usage Notes
//==========================================================================
// Janv. 2000     Creation                       PRG/PMG
//========================================================================== 

#ifndef CATSpaceDeformationSplitToolImp_H
#define CATSpaceDeformationSplitToolImp_H

#include "CATSpaceDeformationSplitTool.h"
#include "PowerTopologicalOpe.h"
class CATCGMJournalList;

class ExportedByPowerTopologicalOpe CATSpaceDeformationSplitToolImp : public CATSpaceDeformationSplitTool
{
  public:
    CATSpaceDeformationSplitToolImp(CATGeoFactory* iFactory);

            void       SetCuttingMode(const CATBoolean WithCutting);
            void       SetBody       (CATBody* iBodyToDeform);
            void       SetTopData    (CATTopData*  iData);

    virtual CATLONG32  Run();

            CATBoolean GetIsDone() const;

            CATBoolean GetWireFrameAccepted() const;

  // Get the result Body (NULL if operation failed)
            CATBody  * GetResult();

            int        GetClusterNumber() const;

            void       GetTheBodyPartToDeform(CATLISTP(CATCell)*& impactedCells, const int iNumCluster = 1) const;

            CATBoolean GetCuttingMode() const;

    virtual CATBoolean CuttingIsNecessary() const;

  /*
  Get Cell to divid in two part :
  This allows to perform a Hole beetwen two connected Cell, in the initial Body

  The following break cells can be set :
  - Edges wich connect two Faces in a shell.
  - Vertices wich connect two edges in a wire.
  
  Where one Face (Edge) is to modify and the other is it not.
  */
            void       GetBreakingCells(CATLISTP(CATCell)*& breakingCells) const;

  /**
  * A IMPLEMENTER EN CAS DE PERSITENCE
  * 
  */
            void       GetPrerequisiteObjects( CATLISTP(CATICGMObject)& olObjects)const {};

   /**
  * A IMPLEMENTER EN CAS DE PERSITENCE
  * 
  */
  virtual   CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersion, CATBoolean & ioReversible )const;

  /**
  * A IMPLEMENTER EN CAS DE PERSITENCE
  * 
  */
  virtual   void       Stream( CATMathStream& ioWriteStream )const;

  /**
   * Increments the reference count of the instance.
   */
            void       AddRef();

  /**
   * Decrements the reference count of the instance.  When the counter reaches 0, the instance is deleted.
   */
            void       Release();

  protected :

   

    virtual ~CATSpaceDeformationSplitToolImp();

    CATGeoFactory*        _factory;
    CATBody*              _skinToDeform;
    CATTopData*           _topData;
    CATCGMJournalList*    _report;

    CATBoolean            _withCutting;
    CATBoolean            _isdone;
    CATBoolean            _WireFrameAccepted;
    CATLISTP(CATCell)*    _impactedCells;
    CATLISTP(CATCell)*    _breakingCells;

    CATBody*              _resultingBody;
    int                   _NbOfCluster;
    short                 _IsReturned;

private :
    int                   _CountRef;
};
#endif

