#ifndef CATExtHybIntersect_h_
#define CATExtHybIntersect_h_

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
#include "CATHybDef.h"
#include "CATExtHybOperatorImp.h"
#include "CATHybIntersect.h"

class ExportedByPBELight CATExtHybIntersect : public CATExtHybOperatorImp
{

   friend class CATHybIntersect;


protected:

   //-------------------------------------------------------------------------------------------------------
   // Constructeur
   //   iOperateur peut etre NULL,  mais ca doit etre reserver au cas tres particuliers sous constructeur
   //   il faut dans ce cas s'empresser de retablir la definition avec la methode SetOperator
   //-------------------------------------------------------------------------------------------------------
   CATExtHybIntersect(CATGeoFactory* iFactory, CATTopData* iData, CATBody* iFirstBodyToIntersect, CATBody* iSecondBodyToIntersect, CATHybIntersect* iOperateur = NULL);

public:

   // Destructor
   virtual ~CATExtHybIntersect();

   // Surcharge du new/delete
   CATCGMNewClassArrayDeclare;

   /**
    * Defines which domain of the first body must be intersected.
    * @param iDomainOnFirstBody
    * The pointer to the domain to intersect.
    */
   void SetFirstDomainToIntersect(CATDomain* iDomainOnFirstBody);

   /**
    * Defines which domain of the second body must be intersected.
    * @param iDomainOnSecondBody
    * The pointer to the domain to intersect.
    */
   void SetSecondDomainToIntersect(CATDomain* iDomainOnSecondBody);

  /**
   * Set the Boundary Mode to the operator (internal use only).
   */
   void SetBoundaryResultMode(int iYesOrNo=1);

  /**
   * Get the Boundary Mode to the operator (internal use only).
   */
   int GetBoundaryResultMode() const;

  /**
   * Set the OnShell Mode to the operator (internal use only).
   */
   void SetOnShellMode(CATShell* Support, int iYesOrNo=1);

  /**
   * Get the OnShell Mode to the operator (internal use only).
   */
   int GetOnShellMode() const;

   //RITHA
   /** @nodoc 
   * Extrapolation mode 
   * for the extrapolation of the projection result wire on the SupportSurface
   * @param iExtrapolationMode
   * <br><b>Legal values</b>:
   * <dl><dt><tt>0</tt><dd> No Extrapolation. 
   *     <dt><tt>1</tt><dd> Extrapolation in tangency continuity. </dl>
   *     <dt><tt>2</tt><dd> Extrapolation in curvature continuity. </dl>
   */
   void SetExtrapolationMode ( short iExtrapolationMode = 0);
   void GetExtrapolationMode ( short &oExtrapolationMode);
   //void SetTMMaxDeviation ( double iTMMaxDeviation);
   //void GetTMMaxDeviation ( double &oTMMaxDeviation);
   void SetExtrapolationShellSupport(short iShellExtrapolationSupport = 0);
   void GetExtrapolationShellSupport(short &oShellExtrapolationSupport);

   // Analyze result according Tangent Design
   void  SetWarningOnTangentDesign(int yes_or_no=1);
   int  GetTangentDesignMode() const;
   int  IsResultTangentDesign() const;
   int  GetTangentDesignCells(ListPOfCATCell& oListOfCells) const;

   void  SetBooleanOperationWillFollow(int yes_or_no=1);
   int  IsBooleanOperationWillFollow() const;

   //  Control for single support mode. Has a switch, but also requires a reference body.
   void SetSingleSupportMode(int iYesOrNo, CATBody *iReferenceBody);
   int  GetSingleSupportMode(CATBody *&oReferenceBody) const;

   static CATHybIntersect *Load(CATCGMStream &Str,const short LevelOfRuntime, const short VersionOfStream);

   /** @nodoc @nocgmitf */
   void SetBody1ToIntersect(CATBody * iBody1);

   /** @nodoc @nocgmitf */
   void SetBody2ToIntersect(CATBody * iBody2);

   /** @nodoc @nocgmitf */
   CATBody * GetBody1ToIntersect();

   /** @nodoc @nocgmitf */
   CATBody * GetBody2ToIntersect();

   /** @nodoc @nocgmitf */
   CATDomain * GetFirstDomainToIntersect();

   /** @nodoc @nocgmitf */
   CATDomain * GetSecondDomainToIntersect();

protected :

   void RemoveJournalUselessOrders(CATBody * iResult,CATCGMJournalList * ioJournal);
   // methods for CGMReplay
   CATExtCGMReplay  *IsRecordable(short &LevelOfRuntime, short &VersionOfStream);

   void Dump( CATCGMOutput& os ) ;

   void WriteInput(CATCGMStream  & ioStream);

   void RequireDefinitionOfInputAndOutputObjects();
   // end methods for CGMReplay

   void MakeReport();

   void ActivateBodies();

   void CleanActivateBodies();

   void SetInputsToReportChecker();

   int ComputeBoundary();

   void ComputeWarningTangentDesignCells();

   // Data
   CATBody*       _Body1ToIntersect;   // the Body operande to Intersect
   CATBody*       _Body2ToIntersect;   // the Body operande to Intersect
   CATBody*       _Body1Input;         // the Body operande to Intersect
   CATBody*       _Body2Input;         // the Body operande to Intersect
   CATDomain*     _Domain1ToIntersect; // the Domain operande to Intersect
   CATDomain*     _Domain2ToIntersect; // the Domain operande to Intersect
   int            _BoundaryMode;       // boundary mode management
   int            _OnShellMode;        // OnShell management (signs computation)
   int            _RemoveBody1;
   CATShell*      _ShellSupport;       // Support in case of _OnShellMode
   ListPOfCATCell _TangentDesignCells;
   int            _TangentDesignMode;  // Tangent Design Warning ?
   int            _BooleanOperationWillFollow;
   int            _SingleSupportMode;  // Whether single p-curve mode is active
   CATBody*       _SingleSupportReferenceBody;
                                       // Reference body for single p-curve mode
   ListPOfCATCell _InitialTouchedCells;
   ListPOfCATCell _ImageTouchedCells;

   /*========= Attributes for Extrapolation =============
   *   @attribute ContinuityType for Extrapolation
   *     Input argument.
   *     No Extrapolation = 0
   *     Tangency   = 1
   *     Curvature  = 2
   */
   short                    _ExtrapolationMode;
   
   /*
   *   @attribute Shell Support for Extrapolation
   *     Input argument.
   *     No Extrapolation = 0
   *     First Shell   = 1
   *     Second Shell  = 2
   *     First and Second Shell  = 3
   */
   short                    _ShellExtrapolationSupport;

   //*@attribute TMMaxDeviation
   //  *     Input argument.
   //  *     Tolerant Modeling Maximum Deviation.
   //  *     You can put 0 or CATIA's tolerance.
   //double                   _TMMaxDeviation;

};
#endif
