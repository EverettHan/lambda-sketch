//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZFC / LAP
//
// DESCRIPTION  : Class used to store general run options for Live Shape
//                Operators
//
//=============================================================================
// 28/01/09  ZFC  Creation
//=============================================================================

#ifndef CATGMLiveShapeRunOptionsImpl_H
#define CATGMLiveShapeRunOptionsImpl_H

#include "AdvOpeInfra.h"
#include "CATGMLiveShapeRunOptions.h"
#include "CATCGMStream.h"
#include "CATBoolean.h"
#include "CATCGMOutput.h"
#include "CATMathInline.h"

class ExportedByAdvOpeInfra CATGMLiveShapeRunOptionsImpl : public CATGMLiveShapeRunOptions
{
public:
  //===========================================================================
  // CONSTRUCTORS / DESTRUCTOR
  //===========================================================================

  // Constructors
  CATGMLiveShapeRunOptionsImpl(CATBoolean iEnableSelfIntersectionChecks = TRUE);

  // Destructor
  virtual ~CATGMLiveShapeRunOptionsImpl();

  // ----------------------------
  // Set Methode for Application
  // ----------------------------

  // INTERRUPT WITH BEST RESULT
  // --------------------------
  // Call this methode with the interrupt methode SetParentProgressBar
  // For validation (last run), set iBestResultMode to false.
  // Default value : this mode is desactivate.
  INLINE void SetBestResultMode(CATBoolean iBestResultMode); 

  // VALIDATION WITH BEST TIME COMSUMING
  // -----------------------------------
  // Call this methode only for validation.
  // Default value : this mode is desactivate.
  INLINE void SetSameInputAsPreviousRun(CATBoolean iSameInputAsPreviousRun);

  // IMPLICITE TANGENCY FOR VARIATIONAL SOLVER
  // ------------------------------------------
  // Default behavior : KeepImplicitTangency is false.
  INLINE void SetKeepImplicitTangency(CATBoolean iKeepImplicitTangency);

  //===========================================================================
  // OTHER METHODS / DEBUG
  //===========================================================================

  // Check if the object has the default values
  // @nocgmitf (do not create phase 2 interface) 
  CATBoolean HasDefaultValues() const;

  // Variable DEBUG (ce n'est pas une variable pilote comme les autres)
  // Ne pas changer l'emplacement de ce get / set
  // @nocgmitf (do not create phase 2 interface) 
  INLINE void SetLastRunCheck(CATBoolean iCheck);
  // @nocgmitf (do not create phase 2 interface) 
  INLINE CATBoolean IsLastRunCheckEnabled() const;
  
  // @nocgmitf (do not create phase 2 interface) 
  INLINE void SetPreviousRunInterrupted(CATBoolean iPreviousRunInterrupted);
  // @nocgmitf (do not create phase 2 interface) 
  INLINE CATBoolean WasPreviousRunInterrupted() const;


  // Stream Debug
  // @nocgmitf (do not create phase 2 interface) 
  static void WriteGMLiveRunOptions(CATCGMStream &ioStr, CATGMLiveShapeRunOptions *iRunOptions);
  // @nocgmitf (do not create phase 2 interface) 
  static void ReadGMLiveRunOptions(CATCGMStream &iStr, CATGMLiveShapeRunOptions *&oRunOptions);

  // Streamable
  // @nocgmitf (do not create phase 2 interface) 
  void Stream(CATCGMStream& os);
  // @nocgmitf (do not create phase 2 interface) 
  void UnStream(CATCGMStream& os);
  // @nocgmitf (do not create phase 2 interface) 
  void Dump(CATCGMOutput& os);
  // @nocgmitf (do not create phase 2 interface) 
  void DumpLight(CATCGMOutput& os);

  //===========================================================================
  // RUN OPTIONS GET / SET DECLARATIONS
  //===========================================================================

  // INLINE methods
  // GET methods
  // @nocgmitf (do not create phase 2 interface) 
  INLINE CATBoolean GetRedoFeature() const;
  // @nocgmitf (do not create phase 2 interface) 
  INLINE CATBoolean GetMultiDomainBoolean() const;
  // @nocgmitf (do not create phase 2 interface) 
  INLINE CATBoolean GetLocalSelfIntersectionCheck() const;
  // @nocgmitf (do not create phase 2 interface) 
  INLINE CATBoolean GetGlobalSelfIntersectionCheck() const;
  // @nocgmitf (do not create phase 2 interface) 
  INLINE CATBoolean GetBestResultMode() const;
  // @nocgmitf (do not create phase 2 interface) 
  INLINE CATBoolean GetSameInputAsPreviousRun() const;
  // @nocgmitf (do not create phase 2 interface) 
  INLINE CATBoolean GetKeepImplicitTangency() const;

  // ^^^
  // Nouvelle variable : ajouter au-dessus
  // New variable : add above


  // SET methods
  // @nocgmitf (do not create phase 2 interface) 
  INLINE void SetRedoFeature                (CATBoolean iRedoFeature);
  // @nocgmitf (do not create phase 2 interface) 
  INLINE void SetMultiDomainBoolean         (CATBoolean iMultiDomainBoolean);
  // @nocgmitf (do not create phase 2 interface) 
  INLINE void SetLocalSelfIntersectionCheck (CATBoolean iCheck);
  // @nocgmitf (do not create phase 2 interface) 
  INLINE void SetGlobalSelfIntersectionCheck(CATBoolean iCheck);

  // ^^^
  // Nouvelle variable : ajouter au-dessus
  // New variable : add above

  // For Debug and Test
  // ------------------
  // @nocgmitf (do not create phase 2 interface) 
  static void SetForceRunOptions(CATBoolean iRunOptions);
  // @nocgmitf (do not create phase 2 interface) 
  static void SetForceBestResultMode(CATBoolean iBestResultMode);
  // @nocgmitf (do not create phase 2 interface) 
  static void SetForceSameInputAsPreviousRun(CATBoolean iSameInputAsPreviousRun);
  // @nocgmitf (do not create phase 2 interface) 
  static void SetForceKeepImplicitTangency(CATBoolean iKeepImplicitTangency);
  // @nocgmitf (do not create phase 2 interface) 
  static void SetForceNoSelfIntersectionCheck(CATBoolean iNoCheck);

  // @nocgmitf (do not create phase 2 interface) 
  static CATBoolean GetForceRunOptions();
  // @nocgmitf (do not create phase 2 interface) 
  static CATBoolean GetForceBestResultMode();
  // @nocgmitf (do not create phase 2 interface) 
  static CATBoolean GetForceSameInputAsPreviousRun();
  // @nocgmitf (do not create phase 2 interface) 
  static CATBoolean GetForceKeepImplicitTangency();
  // @nocgmitf (do not create phase 2 interface) 
  static CATBoolean GetForceNoSelfIntersectionCheck();

  // @nocgmitf (do not create phase 2 interface) 
  void SetOptionsWithForceOptions();

private:
  //===========================================================================
  // CONSTRUCTORS / DESTRUCTOR
  //===========================================================================

  // Variable DEBUG (ce n'est pas une variable pilote comme les autres)
  // Ne pas deplacer
  CATBoolean _LastRunCheck;

  //===========================================================================
  // RUN OPTIONS MEMBER DECLARATION
  //===========================================================================

  // Attributes
  CATBoolean _RedoFeature;
  CATBoolean _MultiDomainBoolean;
  CATBoolean _LocalSelfIntersectionCheck;
  CATBoolean _GlobalSelfIntersectionCheck;
  CATBoolean _BestResultMode;
  CATBoolean _SameInputAsPreviousRun;
  CATBoolean _KeepImplicitTangency;
  CATBoolean _PreviousRunInterrupted;

  // ^^^
  // Nouvelle variable : ajouter au-dessus
  // New variable : add above

};

// Variable DEBUG (ce n'est pas une variable pilote comme les autres)
// Ne pas deplacer
INLINE CATBoolean CATGMLiveShapeRunOptionsImpl::IsLastRunCheckEnabled() const {
  return _LastRunCheck;
}

INLINE void CATGMLiveShapeRunOptionsImpl::SetLastRunCheck(CATBoolean iCheck) {
  _LastRunCheck = iCheck;
}

//=============================================================================
// RUN OPTIONS GET / SET IMPLEMENTATION
//=============================================================================
// +-------------+
// | GET methods |
// +-------------+
INLINE CATBoolean CATGMLiveShapeRunOptionsImpl::GetRedoFeature() const {
  return _RedoFeature; }

INLINE CATBoolean CATGMLiveShapeRunOptionsImpl::GetMultiDomainBoolean() const {
  return _MultiDomainBoolean; }

INLINE CATBoolean CATGMLiveShapeRunOptionsImpl::GetLocalSelfIntersectionCheck() const {
  return _LocalSelfIntersectionCheck; }

INLINE CATBoolean CATGMLiveShapeRunOptionsImpl::GetGlobalSelfIntersectionCheck() const {
  return _GlobalSelfIntersectionCheck; }

INLINE CATBoolean CATGMLiveShapeRunOptionsImpl::GetBestResultMode() const {
  return _BestResultMode; }

INLINE CATBoolean CATGMLiveShapeRunOptionsImpl::GetSameInputAsPreviousRun() const {
  return _SameInputAsPreviousRun; }

INLINE CATBoolean CATGMLiveShapeRunOptionsImpl::GetKeepImplicitTangency() const {
  return _KeepImplicitTangency; }

// ^^^
// Nouvelle variable : ajouter au-dessus
// New variable : add above

// +-------------+
// | SET methods |
// +-------------+
INLINE void CATGMLiveShapeRunOptionsImpl::SetRedoFeature(CATBoolean iRedoFeature) {
  _RedoFeature = iRedoFeature; }

INLINE void CATGMLiveShapeRunOptionsImpl::SetMultiDomainBoolean(CATBoolean iMultiDomainBoolean) {
  _MultiDomainBoolean = iMultiDomainBoolean; }

INLINE void CATGMLiveShapeRunOptionsImpl::SetLocalSelfIntersectionCheck(CATBoolean iCheck) {
  _LocalSelfIntersectionCheck = iCheck; }

INLINE void CATGMLiveShapeRunOptionsImpl::SetGlobalSelfIntersectionCheck(CATBoolean iCheck) {
  _GlobalSelfIntersectionCheck = iCheck; }

INLINE void CATGMLiveShapeRunOptionsImpl::SetBestResultMode(CATBoolean iBestResultMode) {
  _BestResultMode = iBestResultMode; }

INLINE void CATGMLiveShapeRunOptionsImpl::SetSameInputAsPreviousRun(CATBoolean iSameInputAsPreviousRun) {
  _SameInputAsPreviousRun = iSameInputAsPreviousRun; }

INLINE void CATGMLiveShapeRunOptionsImpl::SetKeepImplicitTangency(CATBoolean iKeepImplicitTangency) {
  _KeepImplicitTangency = iKeepImplicitTangency;}


INLINE void CATGMLiveShapeRunOptionsImpl::SetPreviousRunInterrupted(CATBoolean iPreviousRunInterrupted)
{
  _PreviousRunInterrupted =iPreviousRunInterrupted;
}
// @nocgmitf (do not create phase 2 interface) 
INLINE CATBoolean CATGMLiveShapeRunOptionsImpl::WasPreviousRunInterrupted() const
{
  return _PreviousRunInterrupted;
}

// ^^^
// Nouvelle variable : ajouter au-dessus
// New variable : add above

#endif /* CATGMLiveShapeRunOptionsImpl_H */
