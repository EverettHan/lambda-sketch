// COPYRIGHT Dassault Systemes 2009
//===================================================================



#ifndef CATIAfrDynamicCreationContainer_H
#define CATIAfrDynamicCreationContainer_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
//---------------------------------------------------------------------- System
#include "CATUnicodeString.h"
#include "CATString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIAfrDynamicCreationContainer;
#else
extern "C" const IID IID_CATIAfrDynamicCreationContainer ;
#endif

//------------------------------------------------------------------
class CATCmdAccess;
/**
* Interface representing the dynamic creation of new accesses.
*
* <br><b>Role</b>: Implement this interface to create dynamically new accesses
* from your container view implementation (See @href CATAfrContainerView).
* <p>
* <br><b>Note :</b>
* Using a subclass of @href CATEAfrDynamicCreationContainer is mandatory when 
* implementing the <tt>CATIAfrDynamicCreationContainer</tt> interface.
* <p><b>BOA information</b>: this interface CANNOT be implemented
* using the BOA (Basic Object Adapter).
*/
class ExportedByCATAfrItf CATIAfrDynamicCreationContainer: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

 	 /**
    * Creates new childs and returns them for the concerned container
    * @return 
    *  The created access
    */
    virtual CATCmdAccess * CreateNewChilds()=0;


    /**
    *
    * <br><b>Role</b>: Create new childs by using C-Afr declarative way (CATCAfrToolbar refer to the documentation on codewiki).
    * This methods is prioritary than the first method, that is to say, if the creation of the component is not successful, so the "CreateNewChilds" will be called
    * Your xml file shoulds respects this kind of content:
    * <pre>
    * <code> 
    *   <Template syp:name="MyTemplateName" Target="CATAfrComponent">
    *    <CATCAfrToolbar>
    *        <! -- Here you add your content, for example : -->
    *        <! --  you can add also the declaration of your command headers directly -->
    *        <CATCmdHeadersList>
    *            <CATCommandHeader ID = "MyFirstCommand" ClassName = "MyClassName" SharedLibraryName = "MyLib" ResourceFile = "CATAfrBalloonHeaders" Available = "1"/>
    *            <CATCommandHeader ID = "MySecondCommand" ClassName = "MyClassName" SharedLibraryName = "MyLib" ResourceFile = "CATAfrBalloonHeaders" Available = "1"/>
    *          </CATCmdHeadersList>
    *        <! -- or include some declarations in an other xml file -->
    *        <CATCAfrInclude syp:Template="MyCommandHeadersDeclaration"/>
    *      <CATCmdStarter Name="MyFirstStarter" Command="MyFirstCommand"/>
    *      <CATCmdSeparator Name="MySeparator"/>
    *      <CATCmdStarter Name="MyFirstStarter" Command="MySecondCommand"/>
    *    </CATCAfrToolbar>
    *   </Template>
    * </code>
    * </pre>
    * @param i_containerName the name of the father container that will contains the new child
    * @param o_instanceName the name of your instance, it should be unique for all component; So choose very well your id. It will also be helpful to not scan the model several times.</br>
    *        <strong>Note </strong>that you not worry about the life cycle of your component, it will be deleted in same time of the father container
    * 
    * @param o_templateName the template name of the CAfrComponent
    * 
    * @param o_fileXML the name of the xml file that contains your template
    * 
    */
    virtual void CreateNewChildsByDeclarative(const CATString & i_containerName,CATString & o_instanceName, CATUnicodeString & o_templateName, CATUnicodeString & o_fileXML) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

//------------------------------------------------------------------
//CATDeclareHandler( CATIAfrDynamicCreationContainer, CATBaseUnknown );
#endif
