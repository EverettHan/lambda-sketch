#ifndef CATSysDicoAccessPro_h
#define CATSysDicoAccessPro_h

// COPYRIGHT DASSAULT SYSTEMES 2012

/**
 * Warning : this interface must only be used by System frameworks.
 * Do not use it without permission.
 */
#include "JS0CORBA.h"
#include "CATUnicodeString.h"
#include "CATCollec.h"

class CATSysTSUnicodeString;
class CATSysTSVectorOfUnicodeString;
 
// Compute the path of 
//          - the directory that contains classical OM dictionaries 
//          - the OM binary dictionary 
// relative to the input parameter iInstallDirPath.
// iInstallDirPath is the path of the runtimeview directory.
// oRelativeClassicalDicDirPath returns the relative path of the directory that should contain classical ObjectModeler Dictionaries .
// oRelativeBinaryDicPath returns the relative path of the OM binary dictionary.
// Warning, subdirectorie are not checked to really exist.
// Returns 0 if the call has succeeded else 1
ExportedByJS0CORBA short ComputeDicosPathesFromRtvPath(const CATUnicodeString & iInstallDirPath, 
    CATUnicodeString & oRelativeClassicalDicDirPath, CATUnicodeString & oRelativeBinaryDicPath);
// @deprecated R418
ExportedByJS0CORBA short ComputeDicosPathesFromRtvPath(CATSysTSUnicodeString & iInstallDirPath, 
    CATSysTSUnicodeString & oRelativeClassicalDicDirPath, CATSysTSUnicodeString & oRelativeBinaryDicPath);

// Compile the ObjectModeler dictionaries to create a binary directionary from them.
// iDictionariesDirPath is the directory where classical OM directionaries are searched.
// iBinaryDicPath is the path of the resulting binary dictionary. If one directory in its hierarchy doesn't exist it will be created.
// Returns 0 if the call has succeeded else 1
ExportedByJS0CORBA short CompileBinaryDictionary(
    const CATUnicodeString & iDictionariesDirPath, 
    const CATUnicodeString & iBinaryDicPath, 
    int iVerbose = 0);
// @deprecated R418
ExportedByJS0CORBA short CompileBinaryDictionary(CATSysTSUnicodeString & iDictionariesDirPath, 
    CATSysTSUnicodeString & iBinaryDicPath, int iVerbose = 0);


// Calls specific to devices (_IOS_SOURCE or _ANDROID_SOURCE)
// Compile the ObjectModeler dictionaries to create a binary directionary from them.
// iAllRessourceFiles : [IN] la liste des tous les fichiers (fullpath) de resources pour l’apps.
// iOutputDir : [IN] le directory a partir duquel generer le fichier (le répertoire de l’app par exemple).
// oOMDicFiles : [OUT] la sous liste de iAllFiles qui sont des fichiers utilisés pour la compilation des dicos et donc a ne pas mettre dans l’app
// oNotOMDicFiles : [OUT] La sous liste de iAllFiles qui ne sont pas relatifs aux dico (et donc a mettre dans l’app)
// iBinaryDicPath : [OUT] le chemin relatif du fichier dans iOutputDir
// Returns 0 if the call has succeeded else 1
ExportedByJS0CORBA short CompileBinaryDictionaryForDevices(
	const CATListOfCATUnicodeString& iAllRessourceFiles,
	const CATUnicodeString& iOutputDir,
	CATListOfCATUnicodeString& oOMDicFiles,
	CATListOfCATUnicodeString& oNotOMDicFiles,
	CATUnicodeString& oBinaryDicPath, 
	int iVerbose = 0);
// @deprecated R418
ExportedByJS0CORBA short CompileBinaryDictionaryForDevices(
	CATSysTSVectorOfUnicodeString& iAllRessourceFiles,
	CATSysTSUnicodeString& iOutputDir,
	CATSysTSVectorOfUnicodeString& oOMDicFiles,
	CATSysTSVectorOfUnicodeString& oNotOMDicFiles,
	CATSysTSUnicodeString& oBinaryDicPath, 
	int iVerbose = 0);

// Calls specific to devices (_IOS_SOURCE or _ANDROID_SOURCE)
// Determine if a file is an ObjectModeler dictionary
// iAllRessourceFiles : [IN] la liste des tous les fichiers (fullpath) de resources pour l’apps.
// oOMDicFiles : [OUT] la sous liste de iAllFiles qui sont des fichiers utilisés pour la compilation des dicos et donc a ne pas mettre dans l’app
// oNotOMDicFiles : [OUT] La sous liste de iAllFiles qui ne sont pas relatifs aux dico (et donc a mettre dans l’app)
// Returns 0 if the call has succeeded else 1
ExportedByJS0CORBA short GetDicoTypeFilesForDevices(
	const CATListOfCATUnicodeString& iAllRessourceFiles,
	CATListOfCATUnicodeString& oOMDicFiles,
	CATListOfCATUnicodeString& oNotOMDicFiles,
	int iVerbose = 0);
// @deprecated R418
ExportedByJS0CORBA short GetDicoTypeFilesForDevices(
	CATSysTSVectorOfUnicodeString& iAllRessourceFiles,
	CATSysTSVectorOfUnicodeString& oOMDicFiles,
	CATSysTSVectorOfUnicodeString& oNotOMDicFiles,
	int iVerbose = 0);

#endif // CATSysDicoAccessPro_h
