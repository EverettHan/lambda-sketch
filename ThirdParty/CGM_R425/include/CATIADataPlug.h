

/**
 * @level Private
 * @usage U1
 */

/* CATIADataPlug.h : COPYRIGHT DASSAULT SYSTEMES 1995 */
#ifndef CATIADataPlug_h
#define CATIADataPlug_h

#include<ExportedByCATIAEntity.h>

class CATIAEntity;
class CATIAPlug;
class CATIAModel;

  /*--------------------------------------------------------------*/
  /* Cette classe regroupe tous les services de plus niveau       */
  /*  que le framework CATIADataBasics peut avoir besoin          */
  /*  en evitant de mettre en defaut la hierarchie des frameworks */
  /*--------------------------------------------------------------*/


class ExportedByCATIAEntity CATIADataPlug 
{
public:
    CATIADataPlug();
    virtual ~CATIADataPlug();

   /*-----------------------------------------------------------------------*/
   /*  Pour la trap logicielle vers les services de la shared-lib CATIAPlug */
   /*-----------------------------------------------------------------------*/
    static CATIADataPlug* _DataPlugIn;
    static int CATIA_DETECT_TEMPORARY;
    static int CATIADataBasicsMUTATE;
    static int CATIADataFormatDEBUG;
    static int CATIADataFormatTYPE;
    static int CATIADataBasicsDEBUG;
    static int CATIAERRMSG;

    // pour le tracage du debug
    static void DebugInit();
    static  int _SoftLevel;
    static  int _DebugLevel;

    /*----------------------------------------------------------*/
    /* Services necessaires au couplage ObjectModeler-CATIA */
    /*----------------------------------------------------------*/
    virtual void synchronize(CATIAPlug* plug, CATIAEntity*const entity);

    virtual void DynamicPlug(CATIAEntity* entity, 
                             char* type, char* superType, CATIAPlug* &plug);

    /*-----------------------------------------------*/
    /*  Gestion de la persistance des .prt, .drw ... */
    /*-----------------------------------------------*/

    virtual int CATIAModelRead(const char *name, 
	 CATIAModel* &mnum, int &ier, const int forRoll);

    virtual int CATIAModelWrite(CATIAModel*const mnum, const char *name,
          const int CodePage, const int Real,const int Integer,
	  int &ier, const int forRoll);

    /*-----------------------------------------------*/
    /*  Gestion des execptions logicielles           */
    /*-----------------------------------------------*/    
    
    virtual void Errmsg_panel(const int numabend ,
			      const int igra, const char msg[]);
};

//--------------------------------------------------------------------------
//  l implementation effective de ces services est realisee dans      
// une classe derivee situee dans un shared explicitement connue "CATIAPlug"
// cette shared fournit egalement une fonction globale encapsulant la creation
// d un representant de cette classe derivee, cette fonction est un symbole
// non manglee (fortran/c) est attendue sous le nom "GetDataPlug"
// avec la signature :    CATIADataPlug* GetDataPlug();
//--------------------------------------------------------------------------
//  l implementation LoadCATIADataPlug s occupe de la creation du bon
//  representant par les outils adequats du framework "System" ... 
//--------------------------------------------------------------------------

ExportedByCATIAEntity CATIADataPlug* LoadCATIADataPlug();

#define CATIADataPlugLibrary     "CATObjectModelerCATIA"
#define CATIADataPlugEntryPoint  "GetDataPlug"

#endif
