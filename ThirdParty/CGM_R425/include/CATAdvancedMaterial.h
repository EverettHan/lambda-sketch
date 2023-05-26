#ifndef CATAdvancedMaterial_H
#define CATAdvancedMaterial_H
#if defined _WINDOWS_SOURCE || defined _MOBILE_SOURCE

#include "CATGraphicMaterial.h"

//PLEASE CONTACT VISUALIZATION TEAM (fl9, sbp) BEFORE USING THAT CLASS
class ExportedBySGInfra CATAdvancedMaterial : public CATGraphicMaterial
{
public:      
	/**
	* PLEASE CONTACT VISUALIZATION TEAM (fl9, sbp) BEFORE USING THAT CLASS
	* <br><b>Constructor</b>: 
	*/

	CATAdvancedMaterial();

	/**
	* PLEASE CONTACT VISUALIZATION TEAM (fl9, sbp) BEFORE USING THAT CLASS
	* <br><b>Copy Constructor</b>: 
	*/

	CATAdvancedMaterial(const CATAdvancedMaterial & material);

protected:

	/**
	* PLEASE CONTACT VISUALIZATION TEAM (fl9, sbp) BEFORE USING THAT CLASS
	* <br><b>Destructor</b>:
	*/

	virtual ~CATAdvancedMaterial();
  
public:

	int ForceCompile();

	/**
	* PLEASE CONTACT VISUALIZATION TEAM (fl9, sbp) BEFORE USING THAT CLASS
	* <br><b>Copy the string buffer in the shader include manager</b>: 
	* @param iIncludeName
	* iIncludeName the name used to retrieve the shader include
	* @param iInclude
	* the char* buffer
	* @return
	* 1 if succeeded 0 if failed
	*/	
	static int AddInclude(const CATString& iIncludeName, const char* iInclude);


	/**
	* PLEASE CONTACT VISUALIZATION TEAM (fl9, sbp) BEFORE USING THAT CLASS
	* <br><b>Remove a string buffer from the manager</b>: 
	* @param iIncludeName
	* 
	* 
	*/
	static void RemoveInclude(const CATString& iIncludeName);

	/**
	* PLEASE CONTACT VISUALIZATION TEAM (fl9, sbp) BEFORE USING THAT CLASS
	* <br><b>Get the include</b>: 
	* @param iIncludeName
	* the incldue name
	* @return
	* a char* buffer
	*/
	static const char* GetInclude(const CATString& iIncludeName);

	unsigned int isSticker(); 
   
  void SetisSticker(unsigned int mode);

  inline void SetIsStreamable(unsigned int streamable);
  inline unsigned int GetIsStreamable() const;

  private :
	  unsigned int m_isStreamable;

};

inline void CATAdvancedMaterial::SetIsStreamable(unsigned int streamable)
{
	m_isStreamable = streamable;
}

inline unsigned int CATAdvancedMaterial::GetIsStreamable() const
{
	return m_isStreamable;
}



#endif
#endif // CATAdvancedMaterial_H
