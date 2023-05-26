/**
 * @level Protected
 * @usage U2
 */
/* CATIAModel.h : COPYRIGHT DASSAULT SYSTEMES 1995 */
#ifndef CATIAContainer_h
#define CATIAContainer_h

#include "ExportedByCATIAEntity.h"
#include <CATIAEntity.h>
#include <CATIOStream.h>
#include <stdio.h>
#include "DSYExport.h"

class DSYImport CATIAPlug ;

class CATIAGeomManager ;

#define IC_Container_Aggregate 26

/**
 * Class representing a container in the V4 meaning.
 *
 * <br><b>Role</b>: Represents a container in the V4 meaning.
 *                  This container can be a V4 geometrical set,
 *                  a V4 workspace, a V5 container.
 */
class ExportedByCATIAEntity CATIAContainer : public CATIAEntity
{
  public:
    CATIAContainer( CATIAContainer* const set, struct INDEX *pindex ) ;
    virtual ~CATIAContainer() ;

   /**
    * Creation of a container ( in the V4 meaning ) in the V4 data structure.
    *
    * <br><b>Role</b>: This method create a container in the V4 data structure.
    *
    * @param iFather [in]
    *   The father container of the father to create
    * @param oIer [out]
    *   Value of the return code. A non null value means that a problem occured.
    * @param iObject [in]
    *   There is a coupling beetween V4 data structure world which is not ObjectModeler, and
    *   the ObjectModeler world. Each CATIAEntity ( non ObjectModeler )can be coupled with a
    *   CATIAPlug ( ObjectModeler ). This optional parameter represents the CATIAPlug that has
    *   to be coupled with the container that will be created. If this parameter is not set, 
    *   the coupled CATIAPlug will be created when necessary.
    * @param iTpeOfContainer [in]
    *   The late type of the container to create.
    * @param iLgrIdent [in]
    *   Length of the identificator of the container to create.
    * @param iIdent [in]
    *   Array of character containing the identificator.
    * @param iTypECC [in]
    *   It defines the type of container to create. There are 4 possible values.
    *     0 is used for master isolated ECC ( Basic, ... ).
    *     1 is used for master ECC ( MASTER, workspace ).
    *     2 is used for other V4 ECC ( geometrical set, applicative set, ghost set, ... ).
    *     3 is used for V5 containers.
    * @param iTyps [in]
    *   Secondary type of the container.
    * @param iSuperTypeOfContainer [in]
    *   Super late type of the container.
    *
    * @return
    *   The created container entity. In case of problem, this return value is NULL.
    *
    */
    static CATIAEntity* Create( CATIAEntity *const iFather,
                                int&               oIer,
                                CATIAPlug   *const iObject=NULL,
                                char*              iTpeOfContainer=NULL,
                                const int          iLgrIdent=0,
                                const char*        iIdent =NULL,
                                const int          iTypECC=3,
                                const int          iTyps=46,
                                char*              iSuperTypeOfContainer=NULL ) ;

   /**
    * Scan a V4 data structure with a filter capability.
    *
    * <br><b>Role</b>: Gives the next element of a V4 data structure scan, in respect with a filter criteria,
    *                  and starting from a given element.
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
    *   The next element of the scan.
    * @param iOrientation [in]
    *   The orientation of th scan ( direct or reverse )
    *
    * @return
    *   Information of success.
    *   <br><b>0</b> means that the method is successfull.
    *   <br><b>1</b> means that the method fails.
    *
    */
    virtual int Scan( const ScanCriteria    iCriterion,
                      CATIAEntity* const    iPrevious,
                      CATIAEntity*&         oNext,
                      const ScanOrientation iOrientation=direct ) ;

   /**
    * Duplicate all the elements of a container in another one.
    *
    * <br><b>Role</b>: This method duplicates all the lement of the current container,
    *                  into another container.
    *
    * @param iFather [in]
    *   The container where all the elements have to be duplicated.
    * @param iLstand [in]
    *   Descriptions of the elements have to be duplicated too, or not.
    *   Two possible values : L1TRUE and L1FALSE.
    *
    * @return
    *   The target container casted in CATIAEntity. In case of problem, the result is NULL.
    *
    */
    virtual CATIAEntity* Duplicate( CATIAContainer* const iFather,
                                    const unsigned char&  iLstand ) ;


   /**
    * Copy a V5 container entity into another container
    *
    * <br><b>Role</b>: A new container will be created under the input father.
    *                  Some descriptions will copied too.
    *                  The content of the container is copied.
    *                  The son's container are also copied.
    *
    * @param iFather [in]
    *   The container where current container has to be copied.
    * @param oCreatedContainer [out]
    *   The created container.
    *
    * @return
    *   <code>S_OK</code> if everything ran ok.
    *   <code>E_FAIL</code> if a problem occured.
    *
    */
    HRESULT                       Copy( CATIAContainer* const iFather,
                                        CATIAContainer*&      oCreatedContainer ) ;

   /**
    * Extract all federating elements, from an array of CATIAEntity.
    *
    * <br><b>Role</b>: Extract all federating elements, from an array of CATIAEntity.
    *
    * @param iNbelt [in]
    *   Number elements in the array of CATIAEntity.
    * @param iTab_entity[] [inout]
    *   The array of CATIAEntity. This array will aslo contain the resulting federator
    *   element at the end of the execution of this method.
    * @param oNbFound [out]
    *   The number of CATIAEntity found.
    *
    * @return
    *   Information of success.
    *   <br><b>0</b> means that the method is successfull.
    *   <br><b>1</b> means that the method fails.
    *
    */
    int Extract( const int& iNbelt, CATIAEntity* ioTab_entity[], int& oNbFound ) ;

   /**
    * Modify the GenericNaming attribute for the entity of the container.
    *
    * <br><b>Role</b>: This method has 2 roles.
    *                  First it can initialized the GenericNaming attribute.
    *                  Second it can extend the GenericNaming attribute to all the entity belonging
    *                  to the familly of entity allready flagged.
    *
    * @param iInit0_or_extend1 [in]
    *   Defines if it is a initialisation, or an extension.
    *   0 means a initialization.
    *   any other value means an extension.
    *
    */
    void GenericNamingWithFamily( const int iInit0_or_extend1=1) ;

   /**
    * Definition of the object that is responsible for the life cycle of geometrical
    * and topological elements.
    *
    * <br><b>Role</b>: Definition of the object that is responsible for the life cycle
    *                  of geometrical and topological elements. This object will destroyed
    *                  during the container deletion.
    *
    * @param iGeomManager [in]
    *   The object. It is possible to set a NULL value if there is no object.
    *
    */
    void SetCATIAGeomManager( CATIAGeomManager* const iGeomManager ) ;

    friend class CATIAEntity ;

  private :
    CATIAGeomManager*                 _geomManager ;
} ;

#endif





