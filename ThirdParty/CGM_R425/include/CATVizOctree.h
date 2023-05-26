#ifndef CATVizOctree_H
#define CATVizOctree_H


#include "CATVisOctreeTools.h"
#include "CATVizPtrList.h"

void ExportedByCATVisOctreeTools GetChildPosition(const float *center, float iHalfSize, int iPosition, float *oCenter, float & oHalfSizes);


typedef ExportedByCATVisOctreeTools struct _CATVizOctreeLevel
{
	unsigned int nbBoxes;
	unsigned int cursor	  :31; /** @win64 fbq : 64-bit structure padding **/
	unsigned int allocMode :1;
	unsigned char *boxesDef;
} CATVizVoxelLevel; // to be renamed

class ExportedByCATVisOctreeTools CATVizOctree
{
   
public:
   
   // Standard constructors and destructors
   // -------------------------------------
   
   CATVizOctree(const unsigned char *buffer, int allocMode);
   CATVizOctree(float x, float y, float z, float halfSize, int nbLevels);
   
   virtual ~CATVizOctree ();
   
   void BuildLevels(int level,int nbBoxes, unsigned char *boxesDef, int & cursor);	
   void ComputeLevelSize(int level,int nbBoxes, unsigned char *boxesDef, int & cursor);
  
   void AddLevel(CATVizVoxelLevel *level);
   
   unsigned int GetCurrentNbLevels() {return _levels.Length();};
   unsigned int GetNbLevels() {return _nbLevels;};
   const float *GetCenter() {return (float *)_center;}
   float GetHalfSize() {return _halfSize;};
   void ClearAllLevels(); 
   void ClearLastLevel(); 
   const CATVizPtrList<CATVizVoxelLevel> & GetLevels() {return _levels;};
   
   unsigned int ComputeStreamSize();
   unsigned char *BuildBuffer();

   // Copy constructor and equal operator
   // -----------------------------------
   CATVizOctree (CATVizOctree &);
   CATVizOctree& operator=(CATVizOctree&);
         
protected:
   CATVizPtrList<CATVizVoxelLevel> _levels;
   float _center[3];
   float _halfSize;
   unsigned int _nbLevels;
};

#endif
