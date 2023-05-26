//=============================================================================
//
// CATTopSweepImp internal Data
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Extrait de l'historique de CATTopSweepImp.h
// NLD 22/04/99 Ajout _Factory, _ImplicitFactory, _Journal, _LaidCenter
// NLD 07 12 99 _PullingDirection
// NLD 08 03 01 _TopDataReceived
// NLD 08 11 01 _CenterSupport
//              Ajout _ResultModeSpecified, _BothResultRequired
// NLD 04 12 03 Ajout de _Warning
// NLD 02 01 04 _CuspTreatment, _DiscontinuityTreatment, _TwistReduction, _RecoilDistance,
//              _IntermediateProfileBody
// NLD 18 12 04 Ajout de _TwistDetection
// NLD 26 10 06 Ajout  _ForcedMultipleViewingDirMode
// NLD 18 12 06 Ajout _UseLocalBoolean
//=============================================================================
// 15/06/10 NLD Creation par extraction depuis CATTopSweepImp.h
//              pour partage avec CATExtTopSweepImp.h
//            | ce partage n'existe plus: CATExtTopSweepImp est desormais vide
//            | (depuis longtemps) NLD180618
// 17/06/10 NLD Ajout _DirectSweepCx2CallV1
// 25/11/10 NLD Ajout _IntermediateResultToRemove
// 20/01/11 NLD Ajout _UseLocalBooleanInSweepCx2
// 01/03/11 NLD Ajout _UseLocalJournalInMasterJournal
// 09/01/15 LD2 Moved "_TrimBody" and "_MustRattrapJournal" to CATExtTopExtrude.
// 18/06/18 NLD Ajout _DirectSweepCx2CallV2
// 30/11/18 NLD Ajout _LoadedFromReplay
// 22/02/23 NLD Ajout _InternalSweep2IPGM
//=============================================================================
  protected:
    // Protected Data
    CATGeoFactory           * _Factory;
    CATGeoFactory           * _ImplicitFactory;
    CATCGMJournalList       * _Journal;
    CATBoolean                _ProfileToClose;
    CATBoolType               _BoolType;
    CATMathDirection          _LocalPullingDirection ;
    CATMathDirection        * _PullingDirection ;
    CATSweep2               * _InternalSweep2;
    CATIPGMSweep2           * _InternalSweep2IPGM;
    CATFrFTopologicalSweep  * _TopologicalSweep ;
    CATBody                 * _LaidCenter ;
    // 09/12/99 : JEL : stockage des bodies input pour la
    // declaration des operandes en Copy/NoCopy dans le journal
    CATBody                 * _CenterBody;
    CATBody                 * _SpineBody;
    CATBody                 * _ProfBody;
    CATBody                 * _IntermediateProfileBody;
    CATBody                 * _IntermediateResultToRemove;
    CATGeometry             * _CenterSupport;
    CATBoolean                _TopDataReceived;
    CATBoolean                _ResultModeSpecified;
    CATBoolean                _BothResultRequired;
/*
    CATTopOpInError         * _Warning;
*/
    CATLONG32                 _DiscontinuityTreatment ;
    CATLONG32                 _CuspTreatment ;
    CATBoolean                _TwistReduction ;
    CATBoolean                _TwistDetection ;
    CATBoolean                _UseLocalBoolean ;
    CATBoolean                _UseLocalBooleanInSweepCx2 ;
    CATBoolean                _ForcedFillTwistMode ;
    double                    _RecoilDistance ;
    int                       _ForcedMultipleViewingDirMode ;
    // Fin des donnees existant dans l'implementation initiale

    int                       _DirectSweepCx2CallV1;          // Ajout 170610
    int                       _DirectSweepCx2CallV2;          // Ajout 180618
    int                       _UseLocalJournalInMasterJournal;// Ajout 010311
    int                       _LoadedFromReplay;              // Ajout 301118
