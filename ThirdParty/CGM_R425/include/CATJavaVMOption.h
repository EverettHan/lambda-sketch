#ifndef CATJavaVMOption_h
#define CATJavaVMOption_h

// CATJavaBridge framework
#include "CATJNIBridge.h"

// System framework
#include "CATUnicodeString.h"

/**
 * Class to represent a JVM option.
 * @author David Morisot (DMO)
 * @author Jean-Francois Doue (JDU)
 */
class ExportedByCATJNIBridge CATJavaVMOption {
	public:
		CATJavaVMOption();
		CATJavaVMOption(
			const CATUnicodeString& iName, 
			const CATUnicodeString& iValue = "", 
			void* iExtraInfo = NULL);
		CATJavaVMOption(
			const CATJavaVMOption& iOption);
		~CATJavaVMOption();
		CATJavaVMOption& operator = (const CATJavaVMOption& iOption);
		int operator == ( const CATJavaVMOption& iOption ) const;
		int operator != ( const CATJavaVMOption& iOption ) const;

		CATUnicodeString GetName() const;
		CATUnicodeString GetValue() const;

		void SetValue(
			const CATUnicodeString& iValue);

		void* GetExtraInfo() const;
		void SetExtraInfo(
			void* iExtraInfo);

	private:
		CATUnicodeString _name;
		CATUnicodeString _value;
		void* _extraInfo;
};
	
#endif // CATJavaVMOption_h
