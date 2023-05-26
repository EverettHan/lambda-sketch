#ifndef __ScalarFieldsHSFunction_h
#define __ScalarFieldsHSFunction_h

#include "CATBaseUnknown.h"
#include "CATUuid.h"

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>
#include <ostream>

#include "ScalarFieldsHSFunctions.h"
#include "ScalarFieldUtils.h"

namespace hs {
	HRESULT StringCopy(char*& dst, const char* src) {
		if(dst!=nullptr) {
			delete [] dst;
			dst = nullptr;
		}
		size_t l = strlen(src);
		if(l>1024) {
			return E_INVALIDARG;
		}
		dst = (char*)malloc(sizeof(char)*(l+1));
		if(dst==nullptr) {
			return E_OUTOFMEMORY;
		}
		memset(dst, 0, sizeof(char)*(l+1));
		strcpy(dst, src);
		return S_OK;
	}

	HRESULT StringCopy(char*& dst, const std::string& str) {
		return StringCopy(dst, str.c_str());
	}

	std::vector<std::string> Tokenize(std::istream& iStream)
  {
    std::string token;
    std::vector<std::string> tokens;

    while (iStream >> token) {
      tokens.push_back(token);
    }

    return tokens;
  }

	std::vector<std::string> Tokenize(const std::string& line, char iSeparator)
  {
    std::vector<std::string> tokens;

    size_t cursorAt = 0;
    size_t at = std::string::npos;
    while((at = line.find(iSeparator, cursorAt)) != std::string::npos) {
      std::string token(line.substr(cursorAt, at-cursorAt));
      tokens.push_back(token);
      cursorAt = ++at;

			while (cursorAt != std::string::npos && line[cursorAt] == ' ') {
				++cursorAt;
			}
    }

    // last token
    std::string token(line.substr(cursorAt, at-cursorAt));
    tokens.push_back(token);

    return tokens;
  }

	std::string StreamToString(std::ostream& oStream)
	{
		std::stringstream sts;
		sts << oStream.rdbuf();
		std::string asString = sts.str();
		return asString;
	}

	enum class ScalarFieldsHSType { SF_NA, SF_BOOL, SF_INT, SF_FLOAT, SF_DOUBLE, SF_STRING, SF_IUNKNOWN, SF_UUID, SF_HRESULT };

	std::string TypeNameFromType (const ScalarFieldsHSType iType)
	{
		std::string typeName;
		switch (iType)
		{
    case ScalarFieldsHSType::SF_NA:
      typeName = "NA";
      break;
    case ScalarFieldsHSType::SF_BOOL:
      typeName = "bool";
      break;
    case ScalarFieldsHSType::SF_INT:
      typeName = "int";
      break;
    case ScalarFieldsHSType::SF_FLOAT:
      typeName = "float";
      break;
    case ScalarFieldsHSType::SF_DOUBLE:
      typeName = "double";
      break;
    case ScalarFieldsHSType::SF_STRING:
      typeName = "char*";
      break;
    case ScalarFieldsHSType::SF_IUNKNOWN:
      typeName = "IUnknown*";
      break;
    case ScalarFieldsHSType::SF_UUID:
      typeName = "CATUuid";
      break;
    case ScalarFieldsHSType::SF_HRESULT:
      typeName = "HRESULT";
    default:
      return "NA";
		}
		return typeName;
	}

	ScalarFieldsHSType TypeFromTypeName(const std::string& iTypeName)
	{
		ScalarFieldsHSType type = ScalarFieldsHSType::SF_NA;
		if(iTypeName=="NA") {
			type = ScalarFieldsHSType::SF_NA;
		} else if(iTypeName=="bool") {
			type = ScalarFieldsHSType::SF_BOOL;
		} else if(iTypeName=="int") {
			type = ScalarFieldsHSType::SF_INT;
		} else if(iTypeName=="float") {
			type = ScalarFieldsHSType::SF_FLOAT;
		} else if(iTypeName=="double") {
			type = ScalarFieldsHSType::SF_DOUBLE;
		} else if(iTypeName=="char*") {
			type = ScalarFieldsHSType::SF_STRING;
		} else if(iTypeName=="IUnknown*") {
			type = ScalarFieldsHSType::SF_IUNKNOWN;
		} else if(iTypeName=="CATUuid") {
			type = ScalarFieldsHSType::SF_UUID;
    } else if(iTypeName=="HRESULT") {
      type = ScalarFieldsHSType::SF_HRESULT;
		} else {
			type = ScalarFieldsHSType::SF_NA;
		}
		return type;
	}

	template <typename T>
	ScalarFieldsHSType TypeFromCPPType(T iT)
	{
		// Default triggers compilation error
		// Specialized version required.
	}

	template <>
	ScalarFieldsHSType TypeFromCPPType<bool>(bool iT)
	{
		return ScalarFieldsHSType::SF_BOOL;
	}

	struct ScalarFieldsHSArgVal
	{
		union
		{
			bool b;
			int  i;
			float f;
			double d;
			char* s;
			IUnknown* ptr;
			CATUuid uuid;
      HRESULT hr;
		};

		ScalarFieldsHSArgVal() {
			this->ptr = nullptr;
		}

		~ScalarFieldsHSArgVal() {
			this->ptr = nullptr;
		}

		void CopyFrom(const ScalarFieldsHSArgVal& iOther, const ScalarFieldsHSType iType)
      {
        switch (iType)
        {
				case ScalarFieldsHSType::SF_NA:
					this->ptr = iOther.ptr;
					break;
				case ScalarFieldsHSType::SF_BOOL:
					this->b = iOther.b;
					break;
				case ScalarFieldsHSType::SF_INT:
					this->i = iOther.i;
					break;
				case ScalarFieldsHSType::SF_FLOAT:
					this->f = iOther.f;
					break;
				case ScalarFieldsHSType::SF_DOUBLE:
					this->d = iOther.d;
					break;
				case ScalarFieldsHSType::SF_STRING:
					this->s = iOther.s;
					break;
				case ScalarFieldsHSType::SF_IUNKNOWN:
					this->ptr = iOther.ptr;
					break;
				case ScalarFieldsHSType::SF_UUID:
					this->uuid = iOther.uuid;
					break;
        case ScalarFieldsHSType::SF_HRESULT:
          this->hr = iOther.hr;
          break;
        }
      }
	};

	class ScalarFieldsHSArg
	{
  public:
    ScalarFieldsHSType type;

    std::string name;
    std::string help;

    ScalarFieldsHSArgVal 		defaultValue;
    ScalarFieldsHSArgVal 		value;

    ScalarFieldsHSArg() :
      type(ScalarFieldsHSType::SF_NA),
      name(""),
      help("")
			{
				this->defaultValue.ptr = nullptr;
				this->value.ptr = nullptr;
			}

    ScalarFieldsHSArg(const ScalarFieldsHSType iType) :
      type(iType),
      name(""),
      help("")
			{
				this->defaultValue.ptr = nullptr;
				this->value.ptr = nullptr;
			}

    ScalarFieldsHSArg(const ScalarFieldsHSArg& iOtherArg) :
      type(iOtherArg.type),
      name(iOtherArg.name),
      help(iOtherArg.help)
			{
				switch (iOtherArg.type)
				{
        case ScalarFieldsHSType::SF_NA:
          break;
        case ScalarFieldsHSType::SF_BOOL:
          this->value.b = iOtherArg.value.b;
          break;
        case ScalarFieldsHSType::SF_INT:
          this->value.i = iOtherArg.value.i;
          break;
        case ScalarFieldsHSType::SF_FLOAT:
          this->value.f =  iOtherArg.value.f;
          break;
        case ScalarFieldsHSType::SF_DOUBLE:
          this->value.d =  iOtherArg.value.d;
          break;
        case ScalarFieldsHSType::SF_STRING:
          if(iOtherArg.value.s!=nullptr) {
            StringCopy(this->value.s, iOtherArg.value.s);
          }
          break;
        case ScalarFieldsHSType::SF_IUNKNOWN:
          if(iOtherArg.defaultValue.ptr!=nullptr) {
            iOtherArg.defaultValue.ptr->AddRef();
            this->defaultValue.ptr = iOtherArg.defaultValue.ptr;
          }
          if(iOtherArg.value.ptr!=nullptr) {
            iOtherArg.value.ptr->AddRef();
            this->value.ptr = iOtherArg.value.ptr;
          }
          break;
        case ScalarFieldsHSType::SF_HRESULT:
          this->value.hr = iOtherArg.value.hr;
          break;
        case ScalarFieldsHSType::SF_UUID:
          this->value.uuid =  iOtherArg.value.uuid;
          break;
				}
			}

    ~ScalarFieldsHSArg()
			{
				if (this->type==ScalarFieldsHSType::SF_IUNKNOWN) {
					if(this->defaultValue.ptr!=nullptr) {
						this->defaultValue.ptr->Release();
						this->defaultValue.ptr = nullptr;
					}
					if(this->value.ptr!=nullptr) {
						this->value.ptr->Release();
						this->value.ptr = nullptr;
					}
				} else if(this->type==ScalarFieldsHSType::SF_STRING) {
					if(this->value.s!=nullptr) {
						free(this->value.s);
						this->value.s = nullptr;
					}
				}
			}

    ScalarFieldsHSArg& operator=(const ScalarFieldsHSArg& iOtherArg)
			{
				this->type = iOtherArg.type;
				this->name = iOtherArg.name.c_str();
				this->help = iOtherArg.help.c_str();

				switch (iOtherArg.type)
				{
        case ScalarFieldsHSType::SF_NA:
          break;
        case ScalarFieldsHSType::SF_BOOL:
          this->value.b = iOtherArg.value.b;
          break;
        case ScalarFieldsHSType::SF_INT:
          this->value.i = iOtherArg.value.i;
          break;
        case ScalarFieldsHSType::SF_FLOAT:
          this->value.f =  iOtherArg.value.f;
          break;
        case ScalarFieldsHSType::SF_DOUBLE:
          this->value.d =  iOtherArg.value.d;
          break;
        case ScalarFieldsHSType::SF_STRING:
          if(iOtherArg.value.s!=nullptr) {
            StringCopy(this->value.s, iOtherArg.value.s);
          }
          break;
        case ScalarFieldsHSType::SF_IUNKNOWN:
          if(iOtherArg.defaultValue.ptr!=nullptr) {
            iOtherArg.defaultValue.ptr->AddRef();
            this->defaultValue.ptr = iOtherArg.defaultValue.ptr;
          }
          if(iOtherArg.value.ptr!=nullptr) {
            iOtherArg.value.ptr->AddRef();
            this->value.ptr = iOtherArg.value.ptr;
          }
          break;
        case ScalarFieldsHSType::SF_HRESULT:
          this->value.hr = iOtherArg.value.hr;
          break;
        case ScalarFieldsHSType::SF_UUID:
          this->value.uuid =  iOtherArg.value.uuid;
          break;
				}
				return *this;
			}
	};

	HRESULT SetArgValue(ScalarFieldsHSArg& iArg, const bool iValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_BOOL) {
			return E_INVALIDARG;
		}
		iArg.value.b = iValue;
		return S_OK;
	}

	HRESULT SetArgValue(ScalarFieldsHSArg& iArg, const int iValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_INT) {
			return E_INVALIDARG;
		}
		iArg.value.i = iValue;
		return S_OK;
	}

	HRESULT SetArgValue(ScalarFieldsHSArg& iArg, const float iValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_FLOAT) {
			return E_INVALIDARG;
		}
		iArg.value.f = iValue;
		return S_OK;
	}

	HRESULT SetArgValue(ScalarFieldsHSArg& iArg, const double iValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_DOUBLE) {
			return E_INVALIDARG;
		}
		iArg.value.d = iValue;
		return S_OK;
	}

	HRESULT SetArgValue(ScalarFieldsHSArg& iArg, const char* iValue)
	{
		HRESULT hr = E_FAIL;
		if(iArg.type!=ScalarFieldsHSType::SF_STRING) {
			hr = E_INVALIDARG;
			return hr;
		}
		hr = StringCopy(iArg.value.s, iValue);
		return hr;
	}

	HRESULT SetArgValue(ScalarFieldsHSArg& iArg, const std::string iValue)
	{
		HRESULT hr = E_FAIL;

		size_t leftbAt = std::string::npos;
		size_t rightbAt = std::string::npos;

		leftbAt = iValue.find('"', 0);
		rightbAt = iValue.find('"', leftbAt+1);

		if(leftbAt!=std::string::npos && rightbAt!=std::string::npos) {
			hr = SetArgValue(iArg, iValue.substr(leftbAt+1, rightbAt-(leftbAt+1)).c_str());
		} else {
			hr = SetArgValue(iArg, iValue.c_str());
		}

		return hr;
	}

	HRESULT SetArgValue(ScalarFieldsHSArg& iArg, const CATUuid iValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_UUID) {
			return E_INVALIDARG;
		}
		iArg.value.uuid = iValue;
		return S_OK;
	}

	HRESULT SetArgValue(ScalarFieldsHSArg& iArg, const HRESULT iValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_HRESULT) {
			return E_INVALIDARG;
		}
		iArg.value.hr = iValue;
		return S_OK;
	}

	// This method does not make AddRef on the provided pointer,
	// it should have been done before (if you have got
  // the pointer from QueryInterface the AddRef should have been
  // done by QueryInterface).
	HRESULT SetArgValue(ScalarFieldsHSArg& iArg, IUnknown* iPtr)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_IUNKNOWN) {
			return E_INVALIDARG;
		}
		iArg.value.ptr = iPtr;
		return S_OK;
	}

	HRESULT SetArgValue(ScalarFieldsHSArg& iArgDst, const ScalarFieldsHSArg& iArgSrc) {
		HRESULT hr = E_FAIL;
		if(iArgSrc.type!=iArgDst.type) {
			hr = E_INVALIDARG;
			return hr;
		}
		iArgDst = iArgSrc;
		return S_OK;
	}

	HRESULT SetValueFromStream(ScalarFieldsHSArg& iArg, std::istream& iStream)
	{
		std::string s;
		switch (iArg.type)
		{
    case ScalarFieldsHSType::SF_NA:
      iArg.value.ptr = nullptr;
      break;
    case ScalarFieldsHSType::SF_BOOL:
      iStream >> iArg.value.b;
      break;
    case ScalarFieldsHSType::SF_INT:
      iStream >> iArg.value.i;
      break;
    case ScalarFieldsHSType::SF_FLOAT:
      iStream >> iArg.value.f;
      break;
    case ScalarFieldsHSType::SF_DOUBLE:
      iStream >> iArg.value.d;
      break;
    case ScalarFieldsHSType::SF_STRING:
      std::getline(iStream, s);
      SetArgValue(iArg, s);
      break;
    case ScalarFieldsHSType::SF_IUNKNOWN:
      // Do nothing at this point.
      // In the future different options
      // identifiers...
      // TODO wzc
      iArg.value.ptr = nullptr;
      break;
    case ScalarFieldsHSType::SF_HRESULT:
      iStream >> iArg.value.hr;
      break;
    case ScalarFieldsHSType::SF_UUID:
      const int max_size = 256;
      char as_char[max_size];
      iStream.getline(as_char, max_size, ' ');
      iArg.value.uuid = CATUuid(as_char);
      break;
		}
		return S_OK;
	}

	HRESULT SetFromStream(ScalarFieldsHSArg& iArg, std::istream& iStream)
	{
		HRESULT hr = S_OK;

		std::vector<std::string> tokens = Tokenize(iStream);

		if(tokens.size()<2) {
			hr = E_FAIL;
			return hr;
		}

		iArg.type = TypeFromTypeName(tokens[0]);
		iArg.name = tokens[1];

		if(tokens.size()>3 && tokens[2]=="=") {
			hr = SetValueFromStream(iArg, std::istringstream(tokens[3]));
			if(hr!=S_OK)
				return hr;

			iArg.defaultValue.CopyFrom(iArg.value, iArg.type);
		}
		return S_OK;
	}

	HRESULT GetArgValue(const ScalarFieldsHSArg& iArg, bool& oValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_BOOL) {
			return E_INVALIDARG;
		}
		oValue = iArg.value.b;
		return S_OK;
	}

	HRESULT GetArgValue(const ScalarFieldsHSArg& iArg, int& oValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_INT) {
			return E_INVALIDARG;
		}
		oValue = iArg.value.i;
		return S_OK;
	}

	HRESULT GetArgValue(const ScalarFieldsHSArg& iArg, float& oValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_FLOAT) {
			return E_INVALIDARG;
		}
		oValue = iArg.value.f;
		return S_OK;
	}

	HRESULT GetArgValue(const ScalarFieldsHSArg& iArg, double& oValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_DOUBLE) {
			return E_INVALIDARG;
		}
		oValue = iArg.value.d;
		return S_OK;
	}

	HRESULT GetArgValue(const ScalarFieldsHSArg& iArg, std::string& oValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_STRING) {
			return E_INVALIDARG;
		}
		oValue.append(iArg.value.s);
		return S_OK;
	}

	HRESULT GetArgValue(const ScalarFieldsHSArg& iArg, CATUuid& oValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_UUID) {
			return E_INVALIDARG;
		}
		oValue = iArg.value.uuid;
		return S_OK;
	}

  HRESULT GetArgValue(const ScalarFieldsHSArg& iArg, HRESULT& oValue)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_HRESULT) {
			return E_INVALIDARG;
		}
		oValue = iArg.value.hr;
		return S_OK;
	}

	// Does the AddRef for you on the return pointer.
	// That way it is aligned with QueryInterface behavior.
	HRESULT GetArgValue(ScalarFieldsHSArg& iArg, IUnknown*& iPtr)
	{
		if(iArg.type!=ScalarFieldsHSType::SF_IUNKNOWN) {
			return E_INVALIDARG;
		}
		if(iArg.value.ptr!=nullptr) {
			iArg.value.ptr->AddRef();
		}
		iPtr = (IUnknown*)iArg.value.ptr;
		return S_OK;
	}

	HRESULT AppendValueToStream(const ScalarFieldsHSArg& iArg, std::ostream& oStream)
	{
		switch (iArg.type)
		{
    case ScalarFieldsHSType::SF_NA:
      return E_FAIL;
    case ScalarFieldsHSType::SF_BOOL:
      oStream << iArg.value.b;
      break;
    case ScalarFieldsHSType::SF_INT:
      oStream << iArg.value.i;
      break;
    case ScalarFieldsHSType::SF_FLOAT:
      oStream << iArg.value.f;
      break;
    case ScalarFieldsHSType::SF_DOUBLE:
      oStream << iArg.value.d;
      break;
    case ScalarFieldsHSType::SF_STRING:
      oStream << iArg.value.s;
      break;
    case ScalarFieldsHSType::SF_IUNKNOWN:
      // See TODO in setValueFromStream
      oStream << "nullptr";
      break;
    case ScalarFieldsHSType::SF_HRESULT:
      oStream << std::hex << iArg.value.hr;
      break;
    case ScalarFieldsHSType::SF_UUID:
      char* as_char = nullptr;
      ScalarFieldsHSArg& theArg = const_cast<ScalarFieldsHSArg&>(iArg);
      theArg.value.uuid.UUID_to_chaine(as_char);
      oStream << as_char;
      break;
		}
		return S_OK;
	}

	HRESULT AppendDefaultValueToStream(const ScalarFieldsHSArg& iArg, std::ostream& oStream)
	{
		switch (iArg.type)
		{
    case ScalarFieldsHSType::SF_NA:
      return E_FAIL;
    case ScalarFieldsHSType::SF_BOOL:
      oStream << iArg.defaultValue.b;
      break;
    case ScalarFieldsHSType::SF_INT:
      oStream << iArg.defaultValue.i;
      break;
    case ScalarFieldsHSType::SF_FLOAT:
      oStream << iArg.defaultValue.f;
      break;
    case ScalarFieldsHSType::SF_DOUBLE:
      oStream << iArg.defaultValue.d;
      break;
    case ScalarFieldsHSType::SF_STRING:
      oStream << iArg.defaultValue.s;
      break;
    case ScalarFieldsHSType::SF_IUNKNOWN:
      // See TODO in setValueFromStream
      oStream << "nullptr";
      break;
    case ScalarFieldsHSType::SF_HRESULT:
      oStream << iArg.defaultValue.hr;
      break;
    case ScalarFieldsHSType::SF_UUID:
      char* as_char = nullptr;
      ScalarFieldsHSArg& theArg = const_cast<ScalarFieldsHSArg&>(iArg);
      theArg.defaultValue.uuid.UUID_to_chaine(as_char);
      oStream << as_char;
      break;
		}
		return S_OK;
	}

	HRESULT AppendToStream(const ScalarFieldsHSArg& iArg, std::ostream& oStream)
	{
		HRESULT hr = S_OK;

		oStream << TypeNameFromType(iArg.type) << " ";
		oStream << iArg.name;
		oStream << " = ";
		hr = AppendDefaultValueToStream(iArg, oStream);
		if(hr!=S_OK) {
			return hr;
		}

		return hr;
	}

	enum class ScalarFieldsHSStatus { SF_TODO, SF_RUNNING, SF_STOPIT, SF_STOPED, SF_DONE, SF_DELETED, SF_INERROR };

	class ScalarFieldsHSActivity
	{
	public:
		ScalarFieldsHSActivity() : _uuid(NULL), _progressInPercent(-1.0), _status(ScalarFieldsHSStatus::SF_TODO) {}
		~ScalarFieldsHSActivity()
      {
        _uuid = CATUuid(NULL);
        _progressInPercent = -1.0;
        _status = ScalarFieldsHSStatus::SF_DELETED;
      }

		inline HRESULT Progress(const double iProgressInPercent)
      {
        HRESULT keep_going = S_OK;

        _progressInPercent = iProgressInPercent;

        switch (_status)
        {
				case ScalarFieldsHSStatus::SF_TODO:
					_status = ScalarFieldsHSStatus::SF_RUNNING;
					keep_going = true;
					break;
				case ScalarFieldsHSStatus::SF_RUNNING:
					keep_going = true;
					break;
				case ScalarFieldsHSStatus::SF_STOPIT:
					keep_going = S_FALSE;
					break;
				case ScalarFieldsHSStatus::SF_STOPED:
					keep_going = E_FAIL;
					break;
				case ScalarFieldsHSStatus::SF_DONE:
					keep_going = E_FAIL;
					break;
				default:
					keep_going = E_FAIL;
					break;
        }

        return keep_going;
      }

		inline HRESULT Log(const std::string& iMessage)
      {
        HRESULT hr = S_OK;
        try {
          _log.append(iMessage);
        } catch (...) {
          hr = E_OUTOFMEMORY;
        }
        return hr;
      }

		inline HRESULT Push(const ScalarFieldsHSArg& iArg)
      {
        HRESULT hr = S_OK;
        try {
          _stack.push_back(iArg);
        } catch (...) {
          hr = E_OUTOFMEMORY;
        }
        return hr;
      }

		inline ScalarFieldsHSArg& Back()
			{
				return _stack.back();	
			}

		inline HRESULT Pop()
      {
        HRESULT hr = E_UNEXPECTED;
        if(_stack.size()>0) {
          _stack.resize(_stack.size()-1);
          hr = S_OK;
        }
        return hr;
      }

		inline HRESULT DumpStackTo(std::vector<ScalarFieldsHSArg> ioStack)
      {
        HRESULT hr = S_OK;
        try {
          ioStack.insert(ioStack.end(), _stack.begin(), _stack.end());
        } catch (...) {
          hr = E_OUTOFMEMORY;
        }
        return S_OK;
      }

		inline HRESULT AttachArg(const std::string& iArgName, const ScalarFieldsHSArg& iArg)
      {
        HRESULT hr = S_OK;
        try {
          _args.insert(std::pair<std::string, ScalarFieldsHSArg>(iArgName, iArg));
        }
        catch (...) {
          hr = E_OUTOFMEMORY;
          return hr;
        }
        return hr;
      }

		inline HRESULT GetArg(const std::string& iArgName, ScalarFieldsHSArg& oArg)
      {
        HRESULT hr = S_OK;
        try {
          auto it = _args.find(iArgName);
          if (it != _args.end()) {
            oArg = it->second;
          }
          else {
            hr = E_INVALIDARG;
            return hr;
          }
        }
        catch (...) {
          hr = E_OUTOFMEMORY;
        }
        return hr;
      }

		inline HRESULT DetachArg(const std::string& iArgName)
      {
        HRESULT hr = S_OK;
        try {
          auto it = _args.find(iArgName);
          if (it != _args.end()) {
            _args.erase(it);
          }
          else {
            hr = E_INVALIDARG;
            return hr;
          }
        }
        catch (...) {
          hr = E_OUTOFMEMORY;
        }
        return hr;
      }

		inline HRESULT ClearArgs()
      {
        HRESULT hr = S_OK;
        try {
          _args.clear();
        }
        catch (...) {
          hr = E_OUTOFMEMORY;
        }
        return hr;
      }

	private:
		// Don't be naive, we need one!
		CATUuid					_uuid;
		double 					_progressInPercent;
		std::string 			_log;
		std::vector<ScalarFieldsHSArg> 	    _stack;
		ScalarFieldsHSStatus				_status;
		std::map<std::string, ScalarFieldsHSArg> _args;
	};

	class ScalarFieldsHSFunction
	{
	public:
		ScalarFieldsHSFunction() {}
		ScalarFieldsHSFunction(const ScalarFieldsHSFunction& iOther) : _fullName(iOther._fullName), _args(iOther._args), _result(iOther._result) {}

		virtual ~ScalarFieldsHSFunction() {}

		virtual HRESULT Execute(ScalarFieldsHSActivity& iProgress) { return E_NOTIMPL; }

		HRESULT AddArg(const ScalarFieldsHSArg& iArg)
      {
        HRESULT hr = S_OK;
        try {
          _args.push_back(iArg);
        } catch (...) {
          hr = E_OUTOFMEMORY;
        }
        return hr;
      }

		HRESULT SetArg(const size_t iAt, const ScalarFieldsHSArg& iArg)
      {
        if(iAt>=_args.size()) {
          return E_INVALIDARG;
        }
        _args[iAt] = iArg;
        return S_OK;
      }

		HRESULT SetArg(const std::string iArgName, const ScalarFieldsHSArg& iArg)
      {
        for(auto arg : _args) {
          if(arg.name==iArgName) {
            arg = iArg;
            return S_OK;
          }
        }
        return E_INVALIDARG;
      }

		HRESULT SetArgValue(const size_t iAt, const ScalarFieldsHSArg& iArg)
      {
        HRESULT hr = E_FAIL;
        if(iAt>=_args.size()) {
          hr = E_INVALIDARG;
          return hr;
        }
        hr = hs::SetArgValue(_args[iAt], iArg);
        return hr;
      }

		HRESULT SetArgValue(const std::string iArgName, const ScalarFieldsHSArg& iArg)
      {
        HRESULT hr = E_FAIL;
        for(auto arg : _args) {
          if(arg.name==iArgName) {
            hr = hs::SetArgValue(arg, iArg);
            return hr;
          }
        }
        return hr;
      }

		HRESULT SetFullName(const std::string& iFullName)
      {
        _fullName = iFullName;
        return S_OK;
      }

		const std::string& GetFullName() const
      {
        return _fullName;
      }

		const std::string& GetHelp() const
      {
        return _help;
      }

		size_t	GetArgCount() const
      {
        return _args.size();
      }

		HRESULT	GetArg(const size_t iAt, ScalarFieldsHSArg& oArg) const
      {
        if(iAt>=_args.size()) {
          return E_INVALIDARG;
        }
        oArg = _args[iAt];
        return S_OK;
      }

		HRESULT	GetArg(const std::string iArgName, ScalarFieldsHSArg& oArg) const
      {
        for(auto arg : _args) {
          if(arg.name==iArgName) {
            oArg = arg;
            return S_OK;
          }
        }
        return E_INVALIDARG;
      }

		HRESULT SetResult(const ScalarFieldsHSArg& iArg)
      {
        _result = iArg;
        return S_OK;
      }

		const ScalarFieldsHSArg& GetResult() const
      {
        return _result;
      }

	protected:
		std::string 			_fullName;
		std::string 			_help;
		std::vector<ScalarFieldsHSArg>	_args;
		ScalarFieldsHSArg 				_result;
	};

	HRESULT SetFromStream(ScalarFieldsHSFunction& iFunction, std::istream& iStream)
	{
		HRESULT hr = S_OK;

		std::string line;
		std::vector<std::string> signature;

		try {
			if(getline(iStream, line)) {
				signature.push_back(line);
			}

			if(signature.size()<=0) {
				hr = E_INVALIDARG;
				return hr;
			}

			auto tokens = Tokenize(signature[0], ' ');

			ScalarFieldsHSArg result;
			result.type = TypeFromTypeName(tokens[0]);
			if(hr!=S_OK) return hr;
			hr = iFunction.SetResult(result);
			if(hr!=S_OK) return hr;
			hr = iFunction.SetFullName(tokens[1]);
			if(hr!=S_OK) return hr;

			if(tokens[2]=="(") {
				int at = 3;
				while(tokens[at]!=")" && tokens[at+1]!=")") {
					ScalarFieldsHSArg newArg;
					std::string type_and_name = tokens[at] + " " + tokens[at+1];
					hr = SetFromStream(newArg, std::istringstream(type_and_name));
					if(hr!=S_OK) return hr;
					hr = iFunction.AddArg(newArg);
					if(hr!=S_OK) return hr;
					++at;
					++at;
				}
			}

		} catch (...) {
			hr = E_OUTOFMEMORY;
		}

		return hr;
	}

	HRESULT SetArgValues(ScalarFieldsHSFunction& iFunction, std::string iCallSrc)
	{
		HRESULT hr = E_FAIL;

		auto tokens = Tokenize(iCallSrc, ',');

		for(int i=0; i<tokens.size(); ++i) {
			ScalarFieldsHSArg arg;
			hr = iFunction.GetArg(i, arg);
			if(hr!=S_OK) return hr;
			hr = SetValueFromStream(arg, std::istringstream(tokens[i]));
			if(hr!=S_OK) return hr;
			hr = iFunction.SetArgValue(i, arg);
			if(hr!=S_OK) return hr;
		}

		return hr;
	}

	HRESULT SetArgValues(ScalarFieldsHSFunction& iFunction, ScalarFieldsHSActivity& iActivity, std::string iCallSrc)
	{
		HRESULT hr = E_FAIL;

		auto tokens = Tokenize(iCallSrc, ',');

		for (int i = 0; i < tokens.size(); ++i) {
			ScalarFieldsHSArg arg;
			hr = iFunction.GetArg(i, arg);
			if (hr != S_OK) return hr;
			if (tokens[i][0]=='$') {
				// Then it means we need to lookup the activity for the arg value
				hr = iActivity.GetArg(tokens[i].substr(1), arg);
				if (hr != S_OK) return hr;
			}
			else {
				hr = SetValueFromStream(arg, std::istringstream(tokens[i]));
				if (hr != S_OK) return hr;
			}
			hr = iFunction.SetArgValue(i, arg);
			if (hr != S_OK) return hr;
		}

		return hr;
	}

	ExportedByScalarFieldsHSFunctions HRESULT AppendToStream(const ScalarFieldsHSFunction& iFunction, std::ostream& oStream);

	template<class T, class R, class A0>
	class ScalarFieldsHSClassMethodFunctionOneArg : public ScalarFieldsHSFunction
	{
	public:
		ScalarFieldsHSClassMethodFunctionOneArg() :
			_ownInstance(false),
			_ourThis(nullptr),
			_ourMethod(nullptr),
			_ourResult()
      {

      }

		ScalarFieldsHSClassMethodFunctionOneArg(const std::string& iSignature, T* iThis, R (T::*iMethod)(A0), bool iOwnInstance=false) :
			_ownInstance(iOwnInstance),
			_ourThis(iThis),
			_ourMethod(iMethod),
			_ourResult()
      {
        std::istringstream signatureStream(iSignature);
        HRESULT hr = SetFromStream(*this, signatureStream);
      }

		~ScalarFieldsHSClassMethodFunctionOneArg()
      {
        _ourMethod = nullptr;
        if(_ownInstance) {
          delete _ourThis;
          _ourThis = nullptr;
        }
        _ourThis = nullptr;
      }

		HRESULT Execute(ScalarFieldsHSActivity& iActivity)
      {
        HRESULT hr = E_FAIL;

        ScalarFieldsHSArg arg;
        GetArg(0, arg);
        A0 		argValue;
        GetArgValue(arg, argValue);

        _ourResult = (_ourThis->*_ourMethod)(argValue);
        hr = hs::SetArgValue(_result, _ourResult);
				CHECK_HR(hr);

				hr = iActivity.Push(_result);
				CHECK_HR(hr);

        return hr;
      }

		R GetResultValue()
      {
        return _ourResult;
      }

	protected:
		T* 		_ourThis;
		R  		_ourResult;
		R  		(T::*_ourMethod) (A0);
		bool 	_ownInstance;
	};

	template<class T, class R, class A0>
	class ScalarFieldsHSClassMethodFunctionOneArgActivity : public ScalarFieldsHSFunction
	{
	public:
		ScalarFieldsHSClassMethodFunctionOneArgActivity() :
			_ownInstance(false),
			_ourThis(nullptr),
			_ourMethod(nullptr),
			_ourResult()
      {

      }

		ScalarFieldsHSClassMethodFunctionOneArgActivity(const std::string& iSignature, T* iThis, R (T::*iMethod)(ScalarFieldsHSActivity&, A0), bool iOwnInstance=false) :
			_ownInstance(iOwnInstance),
			_ourThis(iThis),
			_ourMethod(iMethod),
			_ourResult()
      {
        std::istringstream signatureStream(iSignature);
        HRESULT hr = SetFromStream(*this, signatureStream);
      }

		~ScalarFieldsHSClassMethodFunctionOneArgActivity()
      {
        _ourMethod = nullptr;
        if(_ownInstance) {
          delete _ourThis;
          _ourThis = nullptr;
        }
        _ourThis = nullptr;
      }

		HRESULT Execute(ScalarFieldsHSActivity& iActivity)
      {
        HRESULT hr = E_FAIL;

        ScalarFieldsHSArg arg;
        GetArg(0, arg);
        A0 		argValue;
        GetArgValue(arg, argValue);

        _ourResult = (_ourThis->*_ourMethod)(iActivity, argValue);
        hr = hs::SetArgValue(_result, _ourResult);
				CHECK_HR(hr);

				hr = iActivity.Push(_result);
				CHECK_HR(hr);

        return hr;
      }

		R GetResultValue()
      {
        return _ourResult;
      }

	protected:
		T* 		_ourThis;
		R  		_ourResult;
		R  		(T::*_ourMethod) (ScalarFieldsHSActivity&, A0);
		bool 	_ownInstance;
	};

	template<class T, class R, class A0, class A1>
	class ScalarFieldsHSClassMethodFunctionTwoArgs : public ScalarFieldsHSFunction
	{
	public:
		ScalarFieldsHSClassMethodFunctionTwoArgs() :
			_ownInstance(false),
			_ourThis(nullptr),
			_ourMethod(nullptr),
			_ourResult()
      {

      }

		ScalarFieldsHSClassMethodFunctionTwoArgs(const std::string& iSignature, T* iThis, R(T::*iMethod)(A0, A1), bool iOwnInstance = false) :
			_ownInstance(iOwnInstance),
			_ourThis(iThis),
			_ourMethod(iMethod),
			_ourResult()
      {
        std::istringstream signatureStream(iSignature);
        HRESULT hr = SetFromStream(*this, signatureStream);
      }

		~ScalarFieldsHSClassMethodFunctionTwoArgs()
      {
        _ourMethod = nullptr;
        if (_ownInstance) {
          delete _ourThis;
          _ourThis = nullptr;
        }
        _ourThis = nullptr;
      }

		HRESULT Execute(ScalarFieldsHSActivity& iActivity)
      {
        HRESULT hr = E_FAIL;

        ScalarFieldsHSArg arg0;
        GetArg(0, arg0);
        A0 		arg0Value;
        GetArgValue(arg0, arg0Value);

        ScalarFieldsHSArg arg1;
        GetArg(1, arg1);
        A1 		arg1Value;
        GetArgValue(arg1, arg1Value);

        _ourResult = (_ourThis->*_ourMethod)(arg0Value, arg1Value);
        hr = hs::SetArgValue(_result, _ourResult);
				CHECK_HR(hr);

				hr = iActivity.Push(_result);
				CHECK_HR(hr);

        return hr;
      }

		R GetResultValue()
      {
        return _ourResult;
      }

	protected:
		T* 		_ourThis;
		R  		_ourResult;
		R(T::*_ourMethod) (A0, A1);
		bool 	_ownInstance;
	};
}
#endif __ScalarFieldsHSFunction_h

