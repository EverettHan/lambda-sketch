#ifndef CATExtHybProject_h_
#define CATExtHybProject_h_

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATHybDef.h"
#include "CATExtHybOperatorImp.h"
#include "CATHybProject.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATDomain.h"

class CATSimplifyParallelTool;  // QPY

class ExportedByPBELight CATExtHybProject : public CATExtHybOperatorImp
{
   
   friend class CATHybProject;
   
   
protected:
   
   //-------------------------------------------------------------------------------------------------------
   // Constructeur 
   //   iOperateur peut etre NULL,  mais ca doit etre reserver au cas tres particuliers sous constructeur
   //   il faut dans ce cas s'empresser de retablir la definition avec la methode SetOperator
   //-------------------------------------------------------------------------------------------------------
   CATExtHybProject(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iBodyToProject, CATBody* iBodySupport, CATMathDirection* iDirection, CATHybProject* iOperateur = NULL);
   
public:
   
   // Destructor
   virtual ~CATExtHybProject();
   
   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;
   
   /**
    * Defines which domain of the first body must be projected.
    * @param iDomain
    * The pointer to the domain to project.
    */
   void SetDomainToProject(CATDomain* iDomain); 
   /**
    * Defines on which domain of the second body the projection is done.
    * @param iDomain
    * The pointer to the domain on which to project.
    */
   void SetDomainSupport(CATDomain* iDomain);   
   
   /**
    * Returns the maximum distance of projection for a given domain of the resulting body.
    * @param iDomainOfResultBody
    * The pointer to the domain.
    * @return
    * The distance.
    */
   double GetDistance(CATDomain* iDomainOfResultBody);
   
   // treatment with Suppress Flatten domain of the Result (to use before run)
   // default value is : 0 --> No Suppression of the Result
   //                    1 --> Domain in wich all cells result from flatten operation are eliminated ...
   void SetSuppressFlattenDomainMode(int yes_or_no=1);
   int  GetSuppressFlattenDomainMode() const;

   // In case LayDown Wire On Shell, we can precise the faces on the support
   // default is : all the faces are take into account
   void SetCoveredFaces(CATLISTP(CATFace) & iCoveredFaces);
   int IsCoveredFacesActive() const;

   void        SetSimplificationMode(CATBoolean iSimplification);
   CATBoolean  GetSimplificationMode() const;

   // In case of Projection, we can precise a maximum distance value for the solution to keep 
   // default is : all the solutions are kept
   void SetMaxDistanceValue(double iMaxDistance);
   double GetMaxDistanceValue() const;
   int IsMaxDistanceActive() const;  
   
   CATHybProjectionContext GetContext();
   void SetContext(CATHybProjectionContext iContext);
   void SetSmartContext(int ); // 1 smart context 0 sinon
   int GetSmartContext(); // idem precednet 0 par defaut

   void SetRemoveArtefacts(int iRemoveArtefacts);

   // TRUE if LayDown is complete.
   CATBoolean IsCompletelyLaidDown();

   static CATHybProject *Load(CATCGMStream &Str,const short LevelOfRuntime, const short VersionOfStream);

  // New Smoothing option
  // 0  => No smoothing
  // 1  => Smooth for tangency continuity 
  // 2  => Smooth for curvature continuity 
   void SetNewSmoothing(CATLONG32 iSmooth);										// QPY
   void GetNewSmoothing(CATLONG32 & oSmooth);									// QPY

  // Cleaning3DMode option :
  // 0  => Default 2D cleaning
  // 1  => 3D Cleaning for the output 
   void SetOutputWireCleaning3DMode(CATLONG32 iOutputWireCleaning3DMode);		// QPY
   void GetOutputWireCleaning3DMode(CATLONG32 & oOutputWireCleaning3DMode);		// QPY

  /** @nodoc 
   * Extrapolation mode 
   * for the extrapolation of the projection result wire on the SupportSurface
   * @param iExtrapolationMode
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No Extrapolation. 
   *     <dt><tt>1</tt><dd> Extrapolation in tangency continuity. </dl>
   *     <dt><tt>1</tt><dd> Extrapolation in curvature continuity. </dl>
   */
   void SetExtrapolationMode ( short iExtrapolationMode = 0);
   void GetExtrapolationMode ( short &oExtrapolationMode);
   void SetTMMaxDeviation ( double iTMMaxDeviation);
   void GetTMMaxDeviation ( double &oTMMaxDeviation);

#ifdef CATIAR419
   // Poly/Exact Config Management 
   virtual CATBoolean Is_PolyInputs_Allowed();
   virtual CATBoolean Is_MixedPolyExactInputs_Allowed();
   //============================
   // Poly/Exact Config Management 
   //============================
   virtual int RunPolyOperator();

#endif

protected :
   
//#ifdef CATIAR419
//   //============================
//   // Poly/Exact Config Management 
//   //============================
//   virtual int RunPolyOperator();
//#endif

   void StoreCell(CATCell* CellToAdd, CATCell* CellRef, CATCell* CellSupport, double dist=0.0); 

   void StoreCell(CATCell* CellToAdd, int OriCellToAdd, 
                  CATCell* CellRef, int OriCellRef, CATCell* CellSupport, double dist=-1.0); 
   
   int FindCorrespondingCellInResultList(CATCell* CellToFind);
   
   int FindCorrespondingCellInReferenceList(CATCell* CellToFind);
   
   int FindCorrespondingCellInSupportList(CATCell* CellToFind);
  
   CATCell* FindCorrespondingCellInDomain(CATDomain* Domain, CATCell* CellToFind);

   double FindCorrespondingCellDistance(CATCell* CellToFind);
   
   CATVertex* CheckDuplicateVertices(CATVertex* Vx);
   
   void StoreResultInBody(CATBody* TargetBody);
   
   void DumpList();
   
   void AssembleListInBody(CATBody* Body);
   CATBody* GetStockBody() const;                 // Access the Stock Body
   void SetStockBody(CATBody* NewBody, int iRemove=1);          
   
   double GetDistance(CATCell* aCellOfResultBody);
   
   double ComputeDistance(CATCell* iCell1, CATCell* iCell2);
   
   virtual int StabilizeOrientation(CATBody* aBodyToStabilize, CATBody* StabilizedBody);
   
   void SetInputsToReportChecker();

   void ReportCreationOnDuplicatedBody(CATBody * iDuplicatedBody, CATCGMJournalList * iLocalJournal);
   void  ReportCreationOnDuplicatedDomain(CATDomain * iDuplicatedDomain, CATCGMJournalList * iLocalJournal);
      
   void Dump( CATCGMOutput& os ) ;
   
   void WriteInput(CATCGMStream  & ioStream);
   
   void RequireDefinitionOfInputAndOutputObjects();
   


   // Data
   CATBody*                  _BodyToProject;   // the Body operande to project
   CATBody*                  _BodySupport;     // the Body operande support
   CATMathDirection*         _Direction;       // the optionnal direction of projection
   CATDomain*                _DomainToProject; // the Domain operande to project
   CATDomain*                _DomainSupport;   // the Domain operande support
   CATHybProjectionContext   _ProjectContext;  // the operator context  
   CATBody*                  _BodyStock;       // the Body for stocking solution cells
   int                       _SmartContext   ;
   // des listes de cellules en association pour des correspondances rapides
   int                       _CurrentCellIndex;
   ListPOfCATCell            _ResultList;
   ListPOfCATCell            _ReferenceList;
   ListPOfCATCell            _SupportList;
   CATListOfDouble           _DistanceList;
   CATListOfInt              _ResultOris;      // Orientation of Result Cells
   CATListOfInt              _ReferenceOris;   // Orientation of Reference Cells
   ListPOfCATFace            _CoveredFaces;    // CoveredFaces management
   ListPOfCATVertex          _PointSolutions;

   ListPOfCATDomain          _ResultDomList;   // to satisfy the API GetDistance for each result domain
   CATListOfDouble           _DomainDistList;

   int                       _CoveredFacesMode;   
   int                       _SuppressFlattenDomain;
   short                     _MaxDistanceMode;
   double                    _MaxDistance;    // the Maximum projection Distance  ...
   CATBoolean                _CompletelyLaidDown;
   CATBoolean                _SimplificationMode;
   CATLONG32                 _NewSmoothing;
   CATLONG32                 _OutputWireCleaning3DMode;
   int                       _RemoveArtefacts;

    /*========= Attributes for Extrapolation =============
   *   @attribute ContinuityType for Extrapolation
   *     Input argument.
   *     No Extrapolation = 0
   *     Tangency   = 1
   *     Curvature  = 2
   *   @attribute TMMaxDeviation
   *     Input argument.
   *     Tolerant Modeling Maximum Deviation.
   *     You can put 0 or CATIA's tolerance.
   */
   short                    _ExtrapolationMode;
   double                   _TMMaxDeviation;
};
#endif
