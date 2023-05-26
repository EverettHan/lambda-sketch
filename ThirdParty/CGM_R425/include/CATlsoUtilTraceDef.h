/* -*-C++-*- */

#ifndef CATlsoUtilTraceDef_H
#define CATlsoUtilTraceDef_H

enum CATlsoUtilTrace_OperatorName {
                      CATlsoUtilTrace_DEBUGMESSAGE=0,
                      CATlsoUtilTrace_MODIFYFACE,
                      CATlsoUtilTrace_SINGLEMODIFYFACE,
                      CATlsoUtilTrace_TRANSFORMFACE,
                      CATlsoUtilTrace_SINGLETRANSFORMFACE,
                      CATlsoUtilTrace_TRANSFORMFACEENGINE,
                      CATlsoUtilTrace_DEFORMFACE,
                      CATlsoUtilTrace_THICKNESSFACE,
                      CATlsoUtilTrace_DRAFTFACE,
                      CATlsoUtilTrace_ERASEFACE,
                      CATlsoUtilTrace_LIVEREMOVEFACE,
                      CATlsoUtilTrace_REMOVEFEATURE,
                      CATlsoUtilTrace_REMOVECHAMFER,
                      CATlsoUtilTrace_REMOVEFILLET,
                      CATlsoUtilTrace_REMOVEPATTERN,
                      CATlsoUtilTrace_REDOFEATURE,
                      CATlsoUtilTrace_MANIFOLDEDITOR,
                      CATlsoUtilTrace_CVMMANIPULATE,
                      CATlsoUtilTrace_GETLIVERESULT,
                      CATlsoUtilTrace_CELLMANIFOLDSMANAGER,
                      CATlsoUtilTrace_SELECTFACE,
                      CATlsoUtilTrace_DEFORMSUBDIV,
                      CATlsoUtilTrace_CONVERTSUBDIV,
                      CATlsoUtilTrace_DEFORMSHELL,
                      CATlsoUtilTrace_BREPTODREP,
                      CATlsoUtilTrace_VARIATIONALTRANSFORMCELL,
                      CATlsoUtilTrace_FUZZYEXTRAPOL,
                      CATlsoUtilTrace_XTRIM,
                      CATlsoUtilTrace_SKINHOLEPLUG,
                      CATlsoUtilTrace_REMOVEEDGEPLUS,
                      CATlsoUtilTrace_REPLACEFACE,
                      CATlsoUtilTrace_DREPDEPENDENCYUPDATER,
                      CATlsoUtilTrace_FILLET,
                      CATlsoUtilTrace_CHAMFER,
                      CATlsoUtilTrace_RUNNER,
                      CATlsoUtilTrace_DISPATCHBODY,
                      CATlsoUtilTrace_CLASHSTATUS,
                      CATlsoUtilTrace_COMPUTECLASH,
                      CATlsoUtilTrace_SOLVECLASH,
                      CATlsoUtilTrace_SOLVEBODYCLASH,
                      CATlsoUtilTrace_SOLVESYSTEM,
                      CATlsoUtilTrace_LIVECOMPATIBLE,
                      CATlsoUtilTrace_LIVEDRAWCLOSURE,
                      CATlsoUtilTrace_LIVEVALIDATE,
                      CATlsoUtilTrace_INTERRUPT,
                      CATlsoUtilTrace_DEFEATURE,
                      CATlsoUtilTrace_GROUP_OPERATOR,
                      CATlsoUtilTrace_PATTERNDREPCREATOR,
                      CATlsoUtilTrace_ADVANCEDREMOVEFACE,
                      CATlsoUtilTrace_LIVEEXTRAPOL,
                      CATlsoUtilTrace_OFFSETDREPCREATOR,
                      CATlsoUtilTrace_SPLIT,
                      CATlsoUtilTrace_SINGLESPLIT,
                      CATlsoUtilTrace_INDUSTRYASSISTANT,
                      CATlsoUtilTrace_CIRCULARSHAPE,
                      CATlsoUtilTrace_POWER_REVOLPRISM,
                      CATlsoUtilTrace_DREPGROUP_OPE,
                      CATlsoUtilTrace_CELLMANIFOLDSMANAGER_OPERATOR,
                      CATlsoUtilTrace_PERSISTENTCELLSBASEDCELLMANIFOLDSMANAGER_OPERATOR,
                      CATlsoUtilTrace_FACEANALYZER,
                      CATlsoUtilTrace_GLOBAL_THICKNESS_ANALYZER,
                      CATlsoUtilTrace_GLOBALFACE_THICKNESS_ANALYZER,
                      CATlsoUtilTrace_CREATEBORDERFACES,
                      CATlsoUtilTrace_ADVANCEDSTAMP,
                      CATlsoUtilTrace_LOCALADVANCEDSTAMPRECOGNIZER,
                      CATlsoUtilTrace_MULTIPLESKINOFFSET,
                      CATlsoUtilTrace_REMOVEDRAFT,
                      CATlsoUtilTrace_REMOVEEXTRUSION,
                      CATlsoUtilTrace_REMOVELOGO,
                      CATlsoUtilTrace_REMOVEADVANCEDSTAMP,
                      CATlsoUtilTrace_FILLETSCAR,
                      CATlsoUtilTrace_SEH,
                      CATlsoUtilTrace_SES,
                      CATlsoUtilTrace_AUTOPARTITIONING,
                      CATlsoUtilTrace_MULTISHELLBODYEXPLODER,
                      CATlsoUtilTrace_BODYSYMMETRY,
                      CATlsoUtilTrace_AUTOPARTITIONING_QUALITYCHECKER,
                      CATlsoUtilTrace_SweepabilityChecker,
                      CATlsoUtilTrace_VOLUMEMERGER,
                      //  /\
                      //  ||   Insert the new operator above
                      //  ||
                      CATlsoUtilTrace_UNKNOWN,
                      CATlsoUtilTrace_NB_OPERATORS};

enum CATlsoUtilTrace_Level1Prefix { CATlsoUtilTrace_CONSTRUCTOR_BEGINNING=0,
                      CATlsoUtilTrace_CONSTRUCTOR_END,
                      CATlsoUtilTrace_RUN_BEGINNING,
                      CATlsoUtilTrace_RUN_END,
                      CATlsoUtilTrace_RUN_FIRSTPASS_BEGINNING,
                      CATlsoUtilTrace_RUN_FIRSTPASS_END,
                      CATlsoUtilTrace_RUN_ALLPASS_BEGINNING,
                      CATlsoUtilTrace_RUN_ALLPASS_END,
                      CATlsoUtilTrace_DESTRUCTOR_BEGINNING,
                      CATlsoUtilTrace_DESTRUCTOR_END };

#endif
