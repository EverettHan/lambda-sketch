/**
 * @level Protected
 * @usage U1
 */
//================================================================== 
// Classe de creation du Bilan Report sur le transfert de donnees 
//   avec Ecriture des informations globales
//        Enregistrement de statut de transfert / entite
//        Ecriture du bilan / type traite  
//
// OGM le 02/05/2002 :
//   Ajout de la fonction FaceDetailRpt
//==================================================================

#ifndef CATReportServices_H_
#define CATReportServices_H_

#include "AC0CATNAV.h" //uniquement pour ExportedBy

// Includes avec information sur element courant traite
#include "CATIReportMigr.h"
#include "CATListOfCATReportServicesByType.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"
#include "CATListOfCATIReportMigr.h"
#include "CATListOfInt.h"

// Includes standard
# include <fstream.h>

class ExportedByAC0CATNAV CATReportServices
{
  public:
    CATReportServices() ;
    ~CATReportServices() ;

    void                          InitStatusTable( CATListOfCATUnicodeString* iTab_Status ) ;
    void                          AddStatus( CATUnicodeString iStringForStatus ) ;

    // creation du report .rpt
    void                          InitializeRpt( const char *iReportFileName,
                                                 const char *iInputFileName,
                                                 const char *iOutputFileName,
						 const char *iReportDirName = NULL) ;

    // Informations generales
    void                          InfoRpt( const char* iTiltle,
                                           const char* iData ) ;

    // mise a jour des indicateurs significatifs du report
    void                          DetailRpt( CATIReportMigr_var& MyInterface,
                                             int                 iStatut ) ;

    void                          DetailRpt( CATIReportMigr_var& MyInterface,
                                             CATUnicodeString    iStringForStatut ) ;

    HRESULT                       FaceDetailRpt( CATIReportMigr_var&  elementReport,
                                                 int                  nbFaceOK,
                                                 int                  nbFaceKO ) ;

    // cloture du report
    void                          WriteRpt() ;

	void GetRptAsString( CATUnicodeString &oRptAsString );
    // Recuperation de la liste des entites a migrer
    CATLISTV(CATIReportMigr_var ) GetListOfReportMigr() ;

    // liste des statuts correspondant a l'entite migree
    CATListOfInt                  GetListOfCorrespondingStatus();

  private:
    int                           _nbStatus ;
    int                           _firstTime ;
    int                           _nbFaceOK ;
    int                           _nbFaceKO ;
	
    FILE*                         _rptFile ;
    char*                         _rptFileName ; /* nom du report */
    char*                         _inFileName ;  /* nom du fichier entree traite */
    char*                         _outFileName ; /* nom du fichier sortie cree */
	CATUnicodeString			  _rptContent;
    CATListOfCATUnicodeString*    _listOfStatus ; /* liste des statuts */

    // Liste Statut Par Type
    CATLISTP(CATReportServicesByType) *_listOfReportByType ;

    // liste des elements a migrer
    CATLISTV(CATIReportMigr_var) _listOfReportMigr ;

    // liste des statuts correspondants aux elements migres
    CATListOfInt                 _listOfCorrespondingStatus ;
} ;

// Fonctions
ExportedByAC0CATNAV void               SetStaticSpaceReport( CATReportServices* MySpaceReport ) ;

ExportedByAC0CATNAV CATReportServices* GetStaticSpaceReport() ;

ExportedByAC0CATNAV void               CleanStaticSpaceReport() ;

ExportedByAC0CATNAV void               SetStaticDrawReport( CATReportServices* MySpaceReport ) ;

ExportedByAC0CATNAV CATReportServices* GetStaticDrawReport() ;

ExportedByAC0CATNAV void               CleanStaticDrawReport() ;

#endif







