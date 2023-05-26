#ifndef CATExtHybBoundary_h_
#define CATExtHybBoundary_h_

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATHybDef.h"
#include "CATExtHybOperatorImp.h"
#include "CATHybBoundary.h"
#include "CATIACGMLevel.h"

class ExportedByPBELight CATExtHybBoundary : public CATExtHybOperatorImp
{
   
   friend class CATHybBoundary;
   
   
protected:
   
   //-------------------------------------------------------------------------------------------------------
   // Constructeur 
   //   iOperateur peut etre NULL,  mais ca doit etre reserver au cas tres particuliers sous constructeur
   //   il faut dans ce cas s'empresser de retablir la definition avec la methode SetOperator
   //-------------------------------------------------------------------------------------------------------
   CATExtHybBoundary(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBody, CATDomain* iDomain, CATCell* iCell, CATHybPropagateMode iPropagateMode, CATHybBoundary* iOperateur = NULL);
   
public:
   
   // Destructor
   virtual ~CATExtHybBoundary();
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;
    
   static CATHybBoundary * Load(CATCGMStream &Str,const short LevelOfRuntime, const short VersionOfStream);


protected:

    void SetInputsToReportChecker();

    CATBody* GetBodyToProceed();
    CATDomain* GetDomainToProceed();
    CATCell* GetCellToPropagate();
    CATHybPropagateMode GetPropagateMode();

    virtual void RequireDefinitionOfInputAndOutputObjects();
    CATExtCGMReplay * IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
    void Dump( CATCGMOutput& os ) ;
    virtual void WriteInput(CATCGMStream  & Str);
    
#ifdef CATIACGMR419CAA
    // Polyhedral body Management 
    virtual CATBoolean Is_PolyInputs_Allowed();
    virtual int RunPolyOperator();
#endif


    // Private Data
    CATBody               *_BodyToProceed;
    CATDomain             *_DomainToProceed; 
    CATCell               *_CellToPropagate;
    CATHybPropagateMode    _PropagateMode;
  
};
#endif
