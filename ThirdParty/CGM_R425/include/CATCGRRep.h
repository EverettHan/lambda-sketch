#ifndef CATCGRRep_H
#define CATCGRRep_H

#include "SGInfra.h"
#include "CAT3DBagRep.h"
#include "CATVizPtrList.h"
#include "CATVizVoxelGP.h"
class CAT3DBoundingSphere;
class CATMathPointf;
class CAT3DViewpoint;
class CAT3DCustomRep;
class CATVizVoxelRep;
class CATRender;
class CATCGRContainer;
class CATVizVoxelRep;
class CATILockBytes2;

enum CATDownloadState {NOT_DOWNLOADED, IN_PROGRESS, DOWNLOADED, CANDIDATE_FOR_UNLOAD,CORRUPTED};

class ExportedBySGInfra CATCGRRep : public CAT3DBagRep
{
   CATDeclareClass;

public:	

   /** @nodoc */
   static CATCGRRep* CreateRep();
   /** @nodoc */
   static CATCGRRep* CreateRep(const char *url);
   static CATCGRRep* CreateRep(CATILockBytes2 *iLB2);

protected:

   /** @deprecated R417 : Use CreateRep instead.*/
   CATCGRRep();
   /** @deprecated R417 : Use CreateRep instead.*/
   CATCGRRep(const char *url);
   /** @deprecated R417 : Use CreateRep instead.*/
   CATCGRRep(CATILockBytes2 *iLB2);

public:

   /** @nodoc */
   virtual ~CATCGRRep();
   
   /** @nodoc */
   inline void SetUrl(const char *url);
   /** @nodoc */
   const char *GetUrl() const;
   inline CATILockBytes2 *GetILockBytes2() const;
   
   /** @nodoc */
   virtual void Draw(CATRender &iRender, int iInside);
   /** @nodoc */
   virtual void DrawPath(CATRender &ioRender, int iInside, CATRepPath &ioPath); 
   /** @nodoc */
   virtual list<CATRep> * GetChildren();
   /** @nodoc */
   list<CATRep> * SafeGetChildren();
   /** @nodoc */
   virtual const CAT3DBoundingSphere &GetShowBoundingElement();
   /** @nodoc */
   const CAT3DBoundingSphere &GetNoshowBoundingElement(int & ioIsOneRepNoshow);
   /** @nodoc */
   virtual int GetIsValidTC();
   /** @nodoc */
   virtual HRESULT SwitchTo(CATVizSemanticLevel iTargetLevel);
   /** @nodoc */
   virtual HRESULT SwitchToFull();
   /** @nodoc */
   virtual CATRep * GetCullingRep();

   virtual void InternalSwitchTo(CATRep *iRep,CATCGRContainer &iCont, CATVizSemanticLevel iTargetLevel);
   virtual void SetCullingRep(CATRep *rep) {};
   virtual void Unload() {};

   inline CATVizSemanticLevel  GetCurrentLevel();
   inline void                 SetCurrentLevel(CATVizSemanticLevel iLevel);
   inline CATVizSemanticLevel  GetNeededLevel();
   inline void                 SetNeededLevel(CATVizSemanticLevel iLevel);
   
   //CATVizSemanticLevel GetNeededLevel(float iSag);

   //inline void  SetCGRSag(float iSag);
   //inline float GetCGRSag();
   virtual HRESULT GetLODSags(int & oNbSags, float * & oLODSags);
   virtual HRESULT SetLODSags(int iNbSags, float * iLODSags);
   inline void SetBoundingBox(const CATMathPointf & iMin, const CATMathPointf & iMax);
   inline void GetBoundingBox(CATMathPointf & oMin, CATMathPointf & oMax);

   /** @nodoc */
   virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

protected:

   CATILockBytes2 *_iLB2;
   char *_url;
   CATVizSemanticLevel _currentLevel;
   CATVizSemanticLevel _neededLevel;
   float _sag;
   CATMathPointf _min;
   CATMathPointf _max;

private:

   int  InternalGetIsValidTC(CATRep &iRep,int isGraphicMaterial);
   unsigned int _computeValidTCDone : 1;

	 // internal
	 void InitCGRRep(const char *url, CATILockBytes2 *iLB2);
};

class CATViz3DViewer;
class CATSupport;

ExportedBySGInfra CATCGRRep *CreateSmartRep(const char *url);
ExportedBySGInfra CATCGRRep *CreateSmartRep2(CATILockBytes2 *iLB2);
ExportedBySGInfra void CreateSmartLoader(CATViz3DViewer *iViewer);
ExportedBySGInfra void CreateSmartLoader(CATSupport *iSupport);


typedef CATVizPtrList<CATCGRRep> CATCGRRepPtrList;

// INLINED METHODS

inline void CATCGRRep::SetUrl(const char *url)
{
   _url = new char[strlen(url)+1];
   strcpy(_url,url);
}

inline CATILockBytes2 *CATCGRRep::GetILockBytes2() const
{
   return _iLB2;
}

inline CATVizSemanticLevel CATCGRRep::GetCurrentLevel()
{
   return _currentLevel;
}

inline void CATCGRRep::SetCurrentLevel(CATVizSemanticLevel iLevel)
{
   _currentLevel = iLevel;
}

inline CATVizSemanticLevel CATCGRRep::GetNeededLevel()
{
   return _neededLevel;
}

inline void CATCGRRep::SetNeededLevel(CATVizSemanticLevel iLevel)
{
   _neededLevel = iLevel;
}

inline void CATCGRRep::SetBoundingBox(const CATMathPointf & iMin, const CATMathPointf & iMax)
{
   _min = iMin;
   _max = iMax;
}

inline void CATCGRRep::GetBoundingBox(CATMathPointf & oMin, CATMathPointf & oMax)
{
   oMin = _min;
   oMax = _max;
}

#endif
