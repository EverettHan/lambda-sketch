// COPYRIGHT Dassault Systemes 2011

#ifndef CATVisFrontBackMaterial_H
#define CATVisFrontBackMaterial_H

#include "SGInfra.h"
#include "CATGraphicMaterial.h"
#include "CATVisMaterialApplication.h"

class ExportedBySGInfra CATVisFrontBackMaterial : public CATGraphicMaterial
{
public:

   /**Front Back Material Constructor
   *  Front and back materials are standard grey material   
   */
  CATVisFrontBackMaterial();

   /**Front Back Material Constructor
   * @param fMaterial 
   * fMaterial will be the front material
   * @param bMaterial 
   * bMaterial will be the back material
   */
  CATVisFrontBackMaterial(const CATGraphicMaterial & fMaterial,const CATGraphicMaterial & bMaterial);
  
   /**Copy Constructor
   * @param the material wich you want to copy
   */
  CATVisFrontBackMaterial(const CATVisFrontBackMaterial &);
    
   /** Sets material properties activation on root and children
   * @param iMode
   * 0:disabled, 1:enabled
   */
  virtual void SetMaterialPropertiesActivation(const int iMode);
  
  /** Sets the front children
   * @param ifMaterial
   * The material to set on front faces
   */
  void SetFrontMaterial(const CATGraphicMaterial & ifMaterial);

  /** Sets the back children
   * @param ifMaterial
   * The material to set on back faces
   */
  void SetBackMaterial(const CATGraphicMaterial & ibMaterial);

  /** Gets the front material 
   * @return a constant reference to the front material    
   */
  const CATGraphicMaterial& GetFrontMaterial() const;
  
  /** Gets the back material 
   * @return a constant reference to the back material    
   */
  const CATGraphicMaterial& GetBackMaterial() const;

  //@nodoc
  inline CATGraphicMaterial& GetFrontMaterial();    
  inline CATGraphicMaterial& GetBackMaterial();
  
  /** Sets the coordinates texture to use for the Front Material. 
  * @param iTexCoordSet : works only for SGV6 Primitive!!   
  */
  void SetFrontTexCoordSet(const VisTexCoordSet iTexCoordSet);
    
  /**   @nodoc */
  //Will work if we bind texture on diffrent OGL channels - not supported yet
  void SetFrontChannel(const Channel iChannel);
  
  /** Sets the coordinates texture to use for the Front Material. 
  * @param iTexCoordSet : works only for SGV6 Primitive!!   
  */
  void SetBackTexCoordSet(const VisTexCoordSet iTexCoordSet);
  
  /**   @nodoc */
  //Will work if we bind texture on diffrent OGL channels - not supported yet
  void SetBackChannel(const Channel iChannel);
  
  /** Gets the front texture coordinates set
   * @return a texture cooridnates set
   */
  VisTexCoordSet GetFrontTexCoordSet() const;
  
  /**   @nodoc */
  Channel GetFrontChannel() const;
  
  /** Gets the front texture coordinates set
   * @return a texture cooridnates set
   */
  VisTexCoordSet GetBackTexCoordSet() const;
  
  /**   @nodoc */
  Channel GetBackChannel() const;

 /** 
 * Creates an iterator on the children of the material.
 * The caller is responsible for deleting the returned iterator.
 * However, it is best to use a stack allocated CATVisMaterialIteratorPtr,
 * which handles the lifecycle automatically.
 */
  virtual CATVisMaterialIterator* CreateIterator() ;    

  /** Returns a pointer to a copy of this pointer
  */
  virtual CATGraphicMaterial* Clone() const;
  
  /** Returns the dynamic type of the material
  * Here returns CATFrontBackMaterial
  */
  virtual CATGraphicMaterialType GetMatType() const;

  /**   @nodoc */
  void SetBackMappingOperator(CATMappingOperator* iOperator);
  
  /**   @nodoc */
  void SetFrontMappingOperator(CATMappingOperator* iOperator);

  /**   @nodoc */
  CATMappingOperator* GetBackMappingOperator();

  /**   @nodoc */
  CATMappingOperator* GetFrontMappingOperator();

  /**   @nodoc */
  virtual void UnStream(CATStreamer& str);

  /**   @nodoc */
  virtual void Stream(CATStreamer& str, int iSaveType);

  /*Ces fonctions sont utilisees dans le CATCullingRender       */
  /*Si non surchargees, on ne detectera pas le texturing        */

  /**   First we check the Front Material */
  /**  Then the back material             */
  virtual CATBoolean GetTexturedMaterialFlag() const;

  /**   First we check the Front Material */
  /**  Then the back material             */
  virtual CATMappingFunction GetMappingFunction() const;

  /**   First we check the Front Material */
  /**  Then the back material    */
  virtual CATIShader  *IsShader(); 

   /**   First we check the Front Material */
  /**  Then the back material             */
  virtual int GetDimTextureImage() const;

 
protected:
  
 /**
  * @nodoc
  * Retreives the list of children of the material.
  * This method is deliberately protected from external use.
  * Clients should use the provided CATVisMaterialIteratorPtr class.
  */
  virtual const CATVisMaterialCollection* GetChildren();
  
  protected:
    virtual ~CATVisFrontBackMaterial();

private:
};

inline CATGraphicMaterial& CATVisFrontBackMaterial::GetFrontMaterial()    
{
  CATGraphicMaterial* fmat = new CATGraphicMaterial();
  return *fmat;
}

inline CATGraphicMaterial& CATVisFrontBackMaterial::GetBackMaterial()
{
  CATGraphicMaterial* bmat = new CATGraphicMaterial();
  return *bmat;
}

#endif // CATVisFrontBackMaterial_H
