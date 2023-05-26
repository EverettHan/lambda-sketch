//-- EnoDicEnvVarMgr assure la gestion des variables d'environnement (CATGetEnv) utilisées dans le composant CATPLMDictionary    
//-- nb: EnoDicEnvVarMgr est supposé être un singleton

#ifndef EnoDicEnvVarMgr_h
#define EnoDicEnvVarMgr_h

#include "CATUnicodeString.h"

#ifdef _WINDOWS_SOURCE
#define SEP ";"
#define SLASH "\\"
#else
#define SEP ":"
#define SLASH "/"
#endif

#if 1
//-- juste pour la méthode CATUnicodeString Strip(CATUnicodeString::CATStripModeBoth, ' ')
static const CATUnicodeChar _Space_asUChar_(' ');

//-- caractères de base
static const CATUnicodeString _Slash_("/");
static const CATUnicodeString _BackSlashR_("\r"); //-- retour chariot
static const CATUnicodeString _BackSlash_("\\");
static const CATUnicodeString _BackSlashN_("\n"); //-- saut de ligne 
static const CATUnicodeString _BackSlashT_("\t"); //-- tabulation 
static const CATUnicodeString _Empty_("");
static const CATUnicodeString _Space_(" ");
static const CATUnicodeString _Equal_("=");
static const CATUnicodeString _Inf_("<");
static const CATUnicodeString _Sup_(">");
static const CATUnicodeString _Dot_(".");
static const CATUnicodeString _Coma_(",");
static const CATUnicodeString _Colon_(":");
static const CATUnicodeString _SemiColon_(";");
static const CATUnicodeString _Ampersand_("&");
static const CATUnicodeString _Dash_("-");
static const CATUnicodeString _UnderScore_("_");
static const CATUnicodeString _Percent_("%");
static const CATUnicodeString _Star_("*");
static const CATUnicodeString _Hash_("#");
static const CATUnicodeString _A_("A");
static const CATUnicodeString _C_("C");
static const CATUnicodeString _D_("D");
static const CATUnicodeString _E_("E");
static const CATUnicodeString _K_("K");
static const CATUnicodeString _N_("N");
static const CATUnicodeString _P_("P");
static const CATUnicodeString _R_("R");
static const CATUnicodeString _S_("S");
static const CATUnicodeString _T_("T");
static const CATUnicodeString _Y_("Y");
static const CATUnicodeString _ExclamationMark_("!");
static const CATUnicodeString _QuestionMark_("?");
static const CATUnicodeString _DoubleQuote_("\"");
static const CATUnicodeString _Quote_("'");

//-- combinaisons de caractères de base
static const CATUnicodeString _Equal_DoubleQuote_("=\"");
static const CATUnicodeString _DoubleQuote_SemiColon_("\";");
static const CATUnicodeString _DoubleQuote_SemiColon_BackSlashN_("\";\n");
static const CATUnicodeString _DoubleQuote_Slash_Sup_BackSlashN_("\"/>\n");
static const CATUnicodeString _Slash_Sup_("/>");
static const CATUnicodeString _Inf_Slash_("</");
static const CATUnicodeString _Sup_BackSlashN_(">\n");
static const CATUnicodeString _Slash_Sup_BackSlashN_("/>\n");

//-- caractères un peu moins de base
static const CATUnicodeString _tokenSEP_(_SemiColon_);
static const CATUnicodeString _NlsIsUndefined_(" (NLS is undefined)");

static const CATUnicodeString _Top_("Top");
static const CATUnicodeString _Custo_("Custo");
static const CATUnicodeString _Specialization_("Specialization");
static const CATUnicodeString _Deployment_("Deployment");
static const CATUnicodeString _Core_("Core");
static const CATUnicodeString _Abstract_("Abstract");
static const CATUnicodeString _Resources_("Resources");

#else
#define _tokenSEP_ ";"
#endif 

class EnoDicEnvVarMgr
{
private:
  EnoDicEnvVarMgr();
  ~EnoDicEnvVarMgr();

public:
  static const EnoDicEnvVarMgr & getInstance();

  //unsigned int _var:1;
  //unsigned int _var:1;

  int _ENODIC_abendInfoSize;
  unsigned int _ENODIC_LogLoadedMetadata : 1; //-- [chd:17.10.2017] pour venir en place/doublon de _ENODIC_LogLoadedMetadata de EnoDicData
  unsigned int _ENODIC_loadEntireCacheOnceIdle : 1; //-- pour éventuellement charger tout le cache au 1er GetVPMIDicMgr après le login initial (passage dans EnodicCommand::OnIdleCB)   
  //unsigned int _ENODIC_EnableTraces:1; //-- [chd:25.01.2017] on ne va vraiment activer les traces QUE si on le demande !
  unsigned int _ENODIC_EnablePrintCallStack : 1;
  unsigned int _CKE_INCREMENTAL_DICO : 1;  //-- va conditionner _ENODIC_isIncrementalLoading et _ENODIC_BuildStreamCacheByPackage
  unsigned int _ENODIC_isIncrementalLoading : 1;
  unsigned int _ENODIC_forgetEscapeNameToXML : 1;
  unsigned int _ENODIC_TrackObsoleteTag : 1;
  unsigned int _ENODIC_REMEMBER_checkBuildTime : 1;
  //unsigned int _ENODIC_CacheEnumAsRange:1;
  //unsigned int _ENODIC_UnscramblingNoCheckHeader : 1;
  unsigned int _ENODIC_DumpPerfoLoadStream : 1;
  unsigned int _ENODIC_DumpPerfoBuildStreamCache : 1;
  unsigned int _ENODIC_DumpPerfoBuildMetadataIndex : 1;
  unsigned int _ENODIC_DumpPerfoLoadCache : 1;
  unsigned int _ENODIC_DumpPerfoTimers : 1;
  unsigned int _ENODIC_DumpPerfoTimerGetNLSValue : 1;
  unsigned int _ENODIC_DumpDefaultMask : 1;
  unsigned int _ENODIC_DumpAdminAfterParsing : 1;
#if 0
  unsigned int _ENODIC_DumpAdminWhileReading : 1;
#endif
  unsigned int _ENODIC_BuildStreamCacheByStream : 1;
  unsigned int _ENODIC_BuildStreamCacheByPackage : 1;
  //unsigned int _ENODIC_BuildStreamCacheFromMemory:1;
  unsigned int _ENODIC_BuildStreamCacheWhileParsing : 1;
  unsigned int _ENODIC_BuildStreamCacheWhileParsingForDebug : 1;
  //unsigned int _ENODIC_StreamCacheScrambling : 1;
  //unsigned int _ENODIC_StreamCacheNoScrambling : 1;
  unsigned int _ENODIC_PREREQ_PACKAGES_NOLOAD : 1;
  //unsigned int _ENODIC_RememberSystemAttributes:1;
  unsigned int _ENODIC_SolveRefByName : 1;
  unsigned int _ENODIC_BuiltTime : 1;                    //-- pour émuler/forcer le mode BuildTime
  unsigned int _ENODIC_DumpCheckError : 1;
  unsigned int _ENODIC_CheckAllERPackages : 1;
  unsigned int _ENODIC_PerfoTimer : 1;
  unsigned int _ENODIC_BuildNLSFileWithTag : 1;
  unsigned int _ENODIC_CacheNLSValue : 1;
  //-- [chd:22.04.2020]
  unsigned int _ENODIC_IsMetadataCacheEnabled : 1;
  unsigned int _ENODIC_IsAdminCacheEnabled : 1;


  unsigned int _isInteractive : 1; //-- pour différencier les modes interactif et ODT
  unsigned int _isPresumablyODT : 1; //-- [chd:29.08.2018] c'est le bordel pour differencier les modes interactif, batch, ODT et pour savoir si on fonctionne sur la RTV ou sur le cache 

  unsigned int _isIRPC_fromPackage : 1;
  unsigned int _extendedValidCharactersForName : 1;

  unsigned int _processDecimalPointInDefaultValue : 1;
  unsigned int _processDecimalPointInAuthorizedValues : 1;

  CATUnicodeString _tempDir;
  CATUnicodeString _applicationName;

};

//-- [chd:03.10.2013] putentraille de foutre chiotte, le preprocesseur Unix ne marche pas quand on utilise ce define !
#define IS_ENABLED(VAR) EnoDicEnvVarMgr::getInstance().##VAR  

#define ENODIC_ForgetIncrementalConvergence 0  

#endif
