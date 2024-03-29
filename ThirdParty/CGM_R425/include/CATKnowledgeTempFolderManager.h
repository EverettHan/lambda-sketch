//===================================================================
// COPYRIGHT Dassault Systèmes 2017/05/23
//===================================================================
// CATKnowledgeTempFolderManager.cpp
// Header definition of class CATKnowledgeTempFolderManager
//===================================================================
//
// Usage notes:
// This class enables to access a temporary folder.
// One instance of this class is strongly linked to a folder.
// When the instance is created a folder is created.
// When the instance is deleted the folder is deleted.
//
//===================================================================
//  2017/05/23 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATKnowledgeTempFolderManager_H
#define CATKnowledgeTempFolderManager_H

#include "KnowledgeItf.h"

#include "DSYString.h"

//-----------------------------------------------------------------------

class ExportedByKnowledgeItf CATKnowledgeTempFolderManager
{
public:
// Standard constructors and destructors
// -------------------------------------
CATKnowledgeTempFolderManager(CATUnicodeString iFolderName);
virtual ~CATKnowledgeTempFolderManager ();

CATUnicodeString GetPath();

//void Clean();

private:
// Copy constructor and equal operator
// -----------------------------------
CATKnowledgeTempFolderManager();
CATKnowledgeTempFolderManager (CATKnowledgeTempFolderManager &);
CATKnowledgeTempFolderManager& operator=(CATKnowledgeTempFolderManager&);

CATUnicodeString _FolderPath;

};

//-----------------------------------------------------------------------

#endif
