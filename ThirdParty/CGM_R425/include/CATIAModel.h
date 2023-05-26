/**
 * @level Protected
 * @usage U2
 */

/* CATIAModel.h : COPYRIGHT DASSAULT SYSTEMES 1995 */

#ifndef CATIAModel_h
#define CATIAModel_h

#include "ExportedByCATIAEntity.h"
#include "CATIAContainer.h"
#include "DataModelerPrivate.h"

class CATCdbErrorManager ;
class CATMnumManager ;
class CATIAWorkspace ;

struct TableForCOPY { CATIAEntity  *tobedup,*dupli;  };

/**
 * enum defining the 2 possible conversion for igra value.
 *  from igra to jele : to become as in V5. igra=jele
 *  from jele to igra : to be as in V4. igra and jele are different.
 */
enum IGRAconversion { IgraToJele=0, JeleToIgra=1 };

/**
 * Class representing V4 data structure.
 *
 * <br><b>Role</b>: Provide the basic class function to manipulate V4 data structure.
 *                  This V4 data structure can be associated with a V4 or a V5 document.
 */
class ExportedByCATIAEntity CATIAModel : public CATIAContainer 
{
  public:
    virtual ~CATIAModel() ;

   /**
    * Scan a V4 data structure to find the master ECC.
    *
    * <br><b>Role</b>: Gives the next master ECC of a V4 data structure scan,
    *                  starting from a given element.
    *                  Master ECC are : MASTER, workspace, Draft, container V5.
    *
    * @param iCriterion [in]
    *   The filter criteria. The possible values are :
    *     none
    *     plugOnly
    *     plugAlreadyGenerated
    *     NonGenericNaming
    * @param iPrevious [in]
    *   The element the scan will start with.
    * @param oNext [out]
    *   The next element of the scan. If no element is found, the value is NULL.
    * @param iOrientation [in]
    *   The orientation of th scan ( direct or reverse )
    *
    * @return
    *   Information of success.
    *   <br><b>0</b> means that the method is successfull.
    *   <br><b>1</b> means that the method fails. No following element has been found.
    *
    */
    virtual int Scan( const ScanCriteria iCriterion, CATIAEntity* const iPrevious,
                      CATIAEntity*& oNext, const ScanOrientation iOrientation=direct ) ;

   /**
    * Scan the session to find all V4 data structure.
    *
    * <br><b>Role</b>: Gives the next V4 data structure in session, starting
    *                  from the given one.
    *
    * @param iMnum [in]
    *   The V4 data structure the scan will start with.
    *
    * @return
    *   The next V4 data structure. If none is found, NULL is returned.
    *
    */
    static CATIAModel* Scan( CATIAModel *const iMnum ) ;

   /**
    * Allocation of an empty  V4 data structure.
    *
    * <br><b>Role</b>: Allocates the 3 main arrays of a V4 data structure,
    *                  INDEX, DATA and GESTOLER.
    *
    * @param iLgestoler [in]
    *   Length of the array GESTOLER.
    * @param iGestoler [in]
    *   array of bytes corresponding to the GESTOLER.
    * @param iLindex [in]
    *   Length of the array INDEX.
    * @param iLdata [in]
    *   Length of the array DATA.
    * @param oPindex [out]
    *   A pointer to the newly allocated array INDEX.
    * @param oPdata [out]
    *   A pointer to the newly allocated array DATA.
    * @param oIer [out]
    *   Value of the return code. A non null value means that a problem occured.
    *
    * @return
    *   The created CATIAModel
    *
    */
    static CATIAModel* Allocate( const int iLgestoler, void *const iGestoler,
                                 const int iLindex, const int iLdata,
                                 void*& oPindex, void*& oPdata, int& oIer ) ;

   /**
    * Create a copy of a V4 data structure.
    *
    * <br><b>Role</b>: Allocates a new CATIAModel which is a copy of the current one.
    *
    * @return
    *   The created copy CATIAModel.
    *
    */
    CATIAModel* CopyAndRecover() ;

   /**
    * Free memory after unstreaming V5 container.
    *
    * <br><b>Role</b>: Memory used by the stream of a V5 container in freed, after unstream.
    *
    */
    void GarbageCollectorCont() ;

   /**
    * Compact the array INDEX and DATA.
    *
    * <br><b>Role</b>: Compact the array INDEX and DATA.
    *
    * @param iWith [in]
    *   Defines if temporary elements have to be removed or not.
    *   1 means that they have to be deleted.
    *
    */
    void GarbageCollector( const int iWith=1 ) ;

   /**
    * Get the current V4 data structure.
    *
    * <br><b>Role</b>: Gives the current CATIAModel..
    *
    * @return
    *   The current CATIAModel.
    *
    */
    static CATIAModel* GetCurrent() ;

   /**
    * Set that no more V4 data structure is current.
    *
    * <br><b>Role</b>: Set that no more CATIAModel is current.
    *
    */
    static  void SetNoCurrent() ;

   /**
    * Set the V4 data structure as the current one.
    *
    * <br><b>Role</b>: ESet the CATIAModel on which this method is applied as the current one.
    *
    */
    virtual void SetCurrent() ;

   /**
    * Check that a pointer is really a V4 data structure.
    *
    * <br><b>Role</b>: Check that a pointer is really a CATIAModel.
    *
    * @param iMnum [in]
    *   The pointer that is supposed to be a valid CATIAModel.
    *
    * @return
    *   If the parameter iMnum really represents a CATIAModel, the result is this pointer.
    *   If not, the result is NULL.
    *
    */
    static CATIAModel* CheckAdress( CATIAModel *const iMnum ) ;

   /**
    * Get the CATIAEntity corresponding to a jele.
    *
    * <br><b>Role</b>: Get the CATIAEntity corresponding to a jele.
    *
    * @param iJele [in]
    *   Value for which, a CATIAEntity is looking for.
    *
    * @return
    *   If this jele correspond to an element, the CATIAEntity is returned.
    *   If not, the result is NULL.
    *
    */
    CATIAEntity* EntityFromJele( const int iJele ) ;

   /**
    * Get the V4 element corresponding to the root container of a V4 data structure.
    *
    * <br><b>Role</b>: Get the CATIAEntity corresponding to the root container of a CATIAModel.
    *
    * @return
    *   Entity representing the root container.
    *
    */
    CATIAEntity* GetRootContainer() ;

   /**
    * Define the extra bytes of an empty V4 data structure.
    *
    * <br><b>Role</b>: An empty V4 data structure has a fixed length. In order to optimize
    *                  the memory consumption, it is possible to extend this initial value.
    *                  This method defines those extension.
    *
    * @param iLindex [in]
    *   The number of R8 ( 8 bytes ) that has to be added to the INDEX initial value.
    * @param iLdata [in]
    *   The number of R8 ( 8 bytes ) that has to be added to the DATA initial value.
    *
    */
    static void PutSize( int iLindex, int iLdata ) ;

   /**
    * Get the extra bytes of an empty V4 data structure.
    *
    * <br><b>Role</b>: An empty V4 data structure has a fixed length. In order to optimize
    *                  the memory consumption, it is possible to extend this initial value.
    *                  This method get the dimension of this extension.
    *
    * @param oLindex [out]
    *   The number of R8 ( 8 bytes ) that has to be added to the INDEX initial value.
    * @param oLdata [out]
    *   The number of R8 ( 8 bytes ) that has to be added to the INDEX initial value.
    *
    */
    static void GetSize( int& oLindex, int& oLdata  ) ;

   /**
    * Change the current workspace.
    *
    * <br><b>Role</b>: Change the current workspace.
    *
    * @param iWsp [in]
    *   The workspace that has to become the current one.
    *
    * @return
    *   Information of success.
    *   <br><b>0</b> means that the method is successfull.
    *   <br><b>1</b> means that the method fails.
    *
    */
    int ChangeWsp( CATIAEntity* const iWsp ) ;

   /**
    * Change the current filter layer.
    *
    * <br><b>Role</b>: Change the current filter layer.
    *
    * @param iLayer[255] [in]
    *   This is the array of logical, that define for each layer ( 0 to 254 )
    *   if it is visible or not.
    *
    * @return
    *   Information of success.
    *   <br><b>0</b> means that the method is successfull.
    *   <br><b>1</b> means that the method fails.
    *
    */
    int ChangeFilter( const unsigned char iLayer[255] ) ;

   /**
    * Get the pathname of the V4 data structure.
    *
    * <br><b>Role</b>: Get the pathname of the V4 data structure.
    *
    * @return
    *   The pathname.
    *
    */
    const char* GetPathName() ;

   /**
    * Change the pathname of the V4 data structure.
    *
    * <br><b>Role</b>: Change the pathname of the V4 data structure.
    *                  It can be usefull, only in very particular case.
    *                  Do not use it.
    *
    * @param iName[255] [in]
    *   The name to affect to the CATIAModel
    * @param iAlloc [in]
    *   0 means that the method is called to put back the initial pathname.
    *   1 means that the method is called to temporarilly change the pathname
    *
    * @return
    *   Information of success.
    *   <br><b>0</b> means that the method is successfull.
    *   <br><b>1</b> means that the method fails.
    *
    */
    int         SetPathName( const char* iName,
                             int iAlloc ) ;

   /**
    * Add a flag on the V4 data structure to indicates that it is under deletion.
    *
    * <br><b>Role</b>: Add a flag on the CATIAModel to indicates that it is under deletion.
    *                  It will avoid some costly test, and individual remove. It gives the
    *                  opportunity to have a global remove process, a transaction notion.
    *
    */
    void ToBeDeleted() ;

   /**
    * Test if the V4 data structure is under remove or not.
    *
    * <br><b>Role</b>: Test if the CATIAModel is under remove or not.
    *                  It tests if the method @href CATIAModel#ToBeDeleted has been called.
    *
    * @return
    *   <br><b>0</b> means that the CATIAModel is not under remove.
    *   <br><b>1</b> means that the CATIAModel is under remove.
    *
    */
    int IsBeingDeleted() ;

   /**
    * Check the validity of the V4 data structure.
    *
    * <br><b>Role</b>: Check the validity of the CATIAModel.
    *
    * @param iWithPrint [in]
    *   Useless in fact
    *
    */
    HRESULT Checker( const int iWithPrint=1 ) ;


   /**
    * Check and Clean the V4 data structure.
    *
    * <br><b>Role</b>: Check the validity of the CATIAModel.
    * The INDEX and DATA tables are modified if a problem is detected.
    *
    */
    HRESULT CheckAndClean( ) ;

	/**
    * Clean the V4 data structure with draw shapes.
	*/
	void CleanerShape(const int Integer);

   /**
    * Ask and reserve some space in the array INDEX and/or DATA.
    *
    * <br><b>Role</b>: Ask and reserve some space in the array INDEX and/or DATA.
    *
    * @param iLindex [in]
    *   The number of R8 ( 8 bytes ) that is needed in the INDEX array.
    * @param iLdata [in]
    *   The number of R8 ( 8 bytes ) that is needed in the DATA array.
    * @param ioPelt [inout]
    *   The pointer to the INDEX position where the modification can take place.
    * @param ioPdat [inout]
    *   The pointer to the DATA position where the modification can take place.
    * @param oIer [out]
    *   Value of the return code. A non null value means that a problem occured.
    * @param iForTemporary [in]
    *   Indicates if the necessary place for permanent or temporary element/description.
    *
    * @return
    *   Information of success.
    *   <br><b>0</b> means that the method is successfull. The memory has been found.
    *   <br><b>1</b> means that the method fails.
    *
    */
    int AskMemory( const int& iLindex, const int& iLdata,
                   union Pindex& ioPelt, union Pdata& ioPdat, int& oIer,
                   const int iForTemporary=0 ) ;

   /**
    * Get the TOLER of the V4 data structure.
    *
    * <br><b>Role</b>: Get the TOLER of the V4 data structure.
    *
    * @return
    *   The TOLER of the CATIAModel
    *
    */
    struct TOLER *AdressToler_Volatil() ;

   /**
    * Compact the INDEX array.
    *
    * <br><b>Role</b>: Compact the INDEX array.
    *                  It gets all available R8 in this array.
    *
    */
    void CompactIndex() ;

    /**
    * Compact the DATA array.
    *
    * <br><b>Role</b>: Compact the DAT array.
    *                  It gets all available R8 in this array.
    *
    */
    void CompactData() ;

   /**
    * Accept all modifications.
    *
    * <br><b>Role</b>: It accepts all modifications.
    *                  It means that no refusal will be possible.
    *                  It is the equivalent to AKKEPT in V4
    *
    */
    void Validate() ;

   /**
    * Remove all temporay informations.
    *
    * <br><b>Role</b>: Remove all temporay informations.
    *                  All temporary entity and descriptions
    *
    */
    void RemoveTemporary() ;

   /**
    * Remove the array of copy element.
    *
    * <br><b>Role</b>: Remove the array of copy element.    *
    *
    */
    void InitDuplicate() ;

   /**
    * Compact the array of copy element.
    *
    * <br><b>Role</b>: Compact the array of copy element.
    *
    */
    void TassDuplicate() ;

   /**
    * Build the familly.
    *
    * <br><b>Role</b>: Build the familly.
    *
    * @param iGenerationMode [in]
    *   0 : usual internal to one geometrical set
    *   1 : internal to one geometrical set, but with split beetween SOLIDE, TextCot
    *
    * @return
    *   Information of success.
    *   <br><b>0</b> means that the method is successfull. The memory has been found.
    *   <br><b>1</b> means that the method fails.
    *
    */
    int MakeFamily( const int iGenerationMode ) ;

   /**
    * Access to the dynamic commun DECALE.
    */
    static struct DECALE * ptrDECALE ;
   /**
    * Access to the dynamic commun MODEL.
    */
    static struct MODEL  virtualMODEL ;

   /**
    * Build all CATIAEntity from array INDEX and DATA.
    *
    * <br><b>Role</b>: Build all CATIAEntity from array INDEX and DATA.
    *                  It transforms the storage format of a V4 structure into
    *                  object that are usable.
    *
    * @param oIier [out]
    *   Value of the return code. A non null value means that a problem occured.
    * @param iName [in]
    *   The parameter role...
    * @param iKillIgra [in]
    *   0 is dedicated to library management
    *   1 is for other documents
    *
    * @return
    *   Information of success.
    *   <br><b>0</b> means that the method is successfull. The memory has been found.
    *   <br><b>1</b> means that the method fails.
    *
    */
    int Recovery( int &oIier, const char *iName=NULL, int iKillIgra=1 ) ;

   /**
    * Convert the igra value.
    *
    * <br><b>Role</b>: Convert the igra value
    *
    * @param iSens [in]
    *   What is the conversion igra to jele or jele to igra
    *   @href CATIAModel#IGRAconversion
    *
    */
    void IgraKiller( const IGRAconversion& iSens ) ;

   /**
    * Get informations on array use ( INDEX, DATA, GES ).
    *
    * <br><b>Role</b>: Get informations on array use ( INDEX, DATA, GES ).
    *                  For the first 2 int array the use is this one :
    *                   0 : length of permanent really used ( nexind or nexdat )
    *                   1 : length of permanent allocated ( lonind or londat )
    *                   2 : length of temporary really used ( nextmi or nextemp )
    *                   3 : length of permanent accepted really used ( lasind or lasdat )
    *                   4 : length of temporary allocated ( lontmi or lontemp )
    *                   5 : length of temporary accepted really used ( lastmi or lastemp )
    *
    * @param oLindex[6] [out]
    *   The 6 pointers inside the INDEX array.
    * @param oLdata[6] [out]
    *   The 6 pointers inside the DATA array.
    * @param oPges [out]
    *   The pointer to the GESTOLER array.
    * @param oPindex [out]
    *   The pointer to the INDEX array.
    * @param oPdata [out]
    *   The pointer to the DATA array.
    *
    */
    void MemoryBoundary( int oLindex[6], int oLdata[6],
                         void*& oPges, void*& oPindex,  void*& oPdata ) ;

   /**
    * Get the igra of the BASIC.
    *
    * <br><b>Role</b>: Get the igra of the BASIC.
    *
    *
    * @return
    *   Igra of the BASIC
    *
    */
    const int GetBasic() ;

   /**
    * Change the value of TOLER.
    *
    * <br><b>Role</b>: Change the value of TOLER.
    *                  If nothing is given by parameters, the V5 default value will be imposed.
    *
    * @param iDtol [in]
    *   23 doubles.
    * @param iTol [in]
    *   12 integers.
    *
    */
    void ForceToler( double* iDtol=NULL, int* iTol=NULL ) ;

   /**
    * Get the number of CATIAEntity build for the V4 data structure.
    *
    * <br><b>Role</b>: Get the number of CATIAEntity build for the CATIAModel.
    *
    * @return
    *   Number of CATIAEntity
    *
    */
    int GetNumberOfEntity() ;

    //----------------------------------------------------------
    // Gestion du Code Page (scz - aout 01) et de l'unite
    //----------------------------------------------------------

   /**
    * Set the informations for code page.
    *
    * <br><b>Role</b>: Set the informations for code page.
    *
    * @param iCodePage [in]
    *   Value for codepage.
    * @param iRealCP [in]
    *   Value for rela coding.
    * @param iIntegerCP [in]
    *   Value for integer coding.
    *
    */
    void SetCodePageInfos( int iCodePage, int iRealCP, int iIntegerCP ) ;

   /**
    * Get the informations for code page.
    *
    * <br><b>Role</b>: Get the informations for code page.
    *
    * @param oCodePage [out]
    *   Value for codepage.
    * @param oRealCP [out]
    *   Value for rela coding.
    * @param oIntegerCP [out]
    *   Value for integer coding.
    *
    */
    void GetCodePageInfos( int& oCodePage, int& oRealCP, int& oIntegerCP ) ;

   /**
    * Set the unit.
    *
    * <br><b>Role</b>: Set the unit.
    *
    * @param iUnit [in]
    *   unit ti be set.
    *
    */
    void SetUnitInfo( double iUnit ) ;

   /**
    * Get the unit.
    *
    * <br><b>Role</b>: Get the unit.
    *
    * @return
    *   unit of the CATIAModel
    *
    */
    double GetUnitInfo() ;

#ifndef CNEXT_CLIENT
   /**
    * no doc.
    * It is only for debug purpose.
    */
    int DumpModel( const char* iDocName,
                   const char* iDumpFilePath ) ;

   /**
    * no doc.
    * It is only for debug purpose.
    */
    int DumpMemory( short debugLevel, const char* string=NULL ) ;
#endif

   /**
    * pointer to the log of error
    */
    CATCdbErrorManager* _errorManager ;

   /**
    * Get the value of mnum.
    *
    * <br><b>Role</b>: Get the valueof mnum.
    *                  This mnum is an integer representing the CATIAModel. This value is used
    *                  in the call of V4 CATGEO. In 32bits, this value is a cast of the CATIAModel
    *                  pointer to integer. In 64 bits, it is a unique value build in runtime.
    *
    * @param oMnum [out]
    *   The mnum of the CATIAModel.
    *
    * @return
    *   Information of success.
    *   <br><b>S_OK</b> means that the method is successfull. The returned mnum is correct.
    *   <br><b>E_FAIL</b> means that the method fails. The returned mnum is 0.
    *
    */
    HRESULT                       GetMnum( int& oMnum ) const ;

   /**
    * Get a V4 data structure from its mnum.
    *
    * <br><b>Role</b>: Get a CATIAModel from its mnum.
    *
    * @param iSearchedMnum [in]
    *   The mnum of the data structure.
    * @param oFoundModel [out]
    *   The corresponding pointer to CATIAModel.
    *
    * @return
    *   Information of success.
    *   <br><b>S_OK</b> means that the method is successfull. The returned CATIAModel is correct.
    *   <br><b>E_FAIL</b> means that the method fails. This mnum doesn't correspond to a valid data structure.
    *                     The returned CATIAModel is NULL.
    *
    */
    static HRESULT                GetModelFromMnum( int          iSearchedMnum,
                                                    CATIAModel*& oFoundModel ) ;
    /**
    * Set the containers CATIAEntity and its corresponding UUIDs thanks to CATIEntityAndUUID interface.
    *
    * <br><b>Role</b>: Loops the CATIAModel to retrieve containers and their CATIAEntity and UUIDs.
    *
    * @return
    *   Information of success.
    *   <br><b>S_OK</b> means that the method is successfull. All information have been correctly retrieved and set.
    *   <br><b>E_FAIL</b> means that the method fails. 
    *
    */
    HRESULT SetEntityAndUUID();


  protected:
   /**
    * Number of CATIAEntity still alive
    */
    int _NumberOfEntity ;

  private:
    CATIAModel() ;

    //-----------------------------------------------------------
    // services primaires d allocation memoire
    //-----------------------------------------------------------
    static int New( const int context,
                    const int lindex, const int ldata, const int ltemp,
                    struct MODEL &adresses, int &ier ) ;
    static void Delete( struct MODEL &adresses ) ;

    int ExpandMemory( const int lindex, const int ldata, const int lperm ) ;

    //-----------------------------------
    // Les donnees privees de la classe  
    //-----------------------------------
    char*                     _ModelPathName;
    struct MODEL              _ModelV4;
    CATIAModel*               _PrevModel;
    CATIAModel*               _NextModel;

    // Gestion de la notion de mnum
    static CATMnumManager*    __mnumManager ;
    int                       _mnum ;

    // Ajout OGM le 19/10/2001, pour gerer les IgraKiller
    // et eviter d'en faire 2 dans le meme sens sur le meme model
    // _IgraMode = 0 => igra comme en V4, donc igra different de jele
    // _IgraMode = 1 => igra comme en V5, donc igra egal a jele
    unsigned char _igraMode : 1 ;

    static CATIAModel* _OriginModel ;

    static int _NBdoubleINDEX ;
    static int _NBdoubleDATA  ;

    //----------------------------------------------------------
    // Gestion de la transaction de l effacement de document
    //----------------------------------------------------------
    unsigned char _IsBeingDeleted : 2 ;
    unsigned char _KindOfFamily   : 2 ;

    //-----------------------------------
    //     La table de duplication       
    //-----------------------------------
    TableForCOPY* _TableForCOPY ;
    int _UsedCOPY ;
    int _MaxCOPY ;

    //----------------------------------------------------------
    // Gestion du Code Page (scz - aout 01) et de l'unite
    //----------------------------------------------------------
    int _CodePage;
    int _RealCP;
    int _IntegerCP;
    double _Unit;

    //-------------------------------------------------------------
    // Les petits amis autorises a s'optimiser dans l'acces direct
    //-------------------------------------------------------------
    friend class CATIAEntity;
    friend class CATIAContainer;
    friend class CATIAWorkspace;
} ;

#endif




