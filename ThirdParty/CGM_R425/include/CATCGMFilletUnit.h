#ifndef CATCGMFilletUnit_h
#define CATCGMFilletUnit_h

#include "BOIMPOPE.h"
#include "CATCGMUnit.h"
//#include "ListPOfCATBody.h"
#include "CATDynFilletRadius.h"
#include "CATDynFilletRibbon.h"


//class CATBody;
class CATGeoFactory;
class CATTopOperator;
class CATTopData;
class CATCGMJournalList;

class ExportedByBOIMPOPE CATCGMFilletUnit : public CATCGMUnit
{
public:
	CATCGMFilletUnit(CATGeoFactory* f, CATTopData * iData, CATCGMJournalList* iJournal);
	virtual ~CATCGMFilletUnit();

          virtual void Dump (CATCGMOutput & ioWhereToWrite, int Index = 0,  int iIndent = 0);

	virtual CATCGMUnitType GetType();


	
	/* 
	    gestion des données applicatives 
	*/
	//void AddFilletRibbons ( CATDynFilletRibbon *iRib);
	//void AddRadius (CATDynFilletRadius *iRadius);

	virtual void UpdateOperatorWithNewEntry (CATBody *iOldBody, CATBody *iNewBody);
    //virtual int  RunOperator ();
          virtual int RunOperator (CATBoolean WithFast=FALSE, CATCGMChainLinkManager *iLink=NULL);



	virtual void GetLinkedGeometry (CATLISTP(CATICGMObject) & CGMLinkedObjectList);



private :

	/* 
	   ici nous avons les donnees allouées habituellement par l'appli
	   dans un feature.
	   On les note ici pour 2 choses :
	   - gestion du cycle de vie
	   - mise a jour lors du run 
	*/
	//CATLISTP(CATDynFilletRadius)         _FilletRadiiBuffer;  
	//CATLISTP(CATDynFilletRibbon)         _ListOfRibbons;  

	//CATLISTP(CATDynFilletBlendVertex)    _VertexBlendList;  

	//  
	//  Private  data  ????? 
	//  
	/*
	CATBody                             *_InitialBody;  
	CATBody                             *_BodyHold;  
	CATBody                             *_SpineBody;  
	CATLISTP(CATBody)                    _ListOfRelimitBodies;  
	CATLISTP(CATDomain)                  _ListOfRelimitShells;  
	CATListOfInt                         _ListOfShellOrientations;  
	CATListOfInt                         _ListOfSmartCrossParting;  
	CATBody                             *_CrossPartingLinker;  
	*/



};

ExportedByBOIMPOPE CATCGMFilletUnit* CATCreateCGMFilletUnit (CATGeoFactory* ifactory, CATTopData * iData, CATCGMJournalList* iJournal);

#endif
