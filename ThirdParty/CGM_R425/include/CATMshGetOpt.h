#ifndef CATMshGetOpt_h
#define CATMshGetOpt_h

#include <memory>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <optional>
#include <sstream>
#include <initializer_list>
#include <algorithm>

class CATMshGetOpt{
public:

	class ParsingException : public std::exception{
	public:
		ParsingException(std::initializer_list<std::string> lmsg){
			for(auto& msg : lmsg){
				_msg += msg;
			}
		}
		ParsingException(const std::string& msg) : ParsingException({msg}) {}
		virtual const char* what() const noexcept override{
			return _msg.c_str();
		}
	private:
		std::string _msg;
	};

	class Opt{
	public:
		explicit Opt() noexcept {}
		virtual ~Opt() {}

		virtual std::string GetName() const = 0;
		virtual std::string GetTypeOfParam() const {return {};}
		virtual std::string GetDesc() const {return {};}
		virtual std::vector<std::string> GetPossibleValues() const {return {};}
		virtual std::string GetShort() const {return {};}

		void Set(std::string param){
			std::stringstream strs;
			strs << param;
			while(strs.good()){
				std::string substr;
				getline(strs, substr, ',');
				_values.push_back(substr);
			}
		}

		virtual void Set() {}

		std::string Get() const{
			if(!Empty())
				return _values[0];
			return {};
		}

		bool Empty() const{
			return _values.size() ? false : true;
		}

		bool Find(const std::string& v) const{
			if(std::find(_values.begin(), _values.end(), v) != _values.end())
				return true;
			return false;
		}

		using Iterator = std::vector<std::string>::iterator;

		Iterator begin(){
			return _values.begin();
		}

		Iterator end(){
			return _values.end();
		}

	private:
		std::string _name;
		std::string _typeOfParam;
		std::string _desc;
		std::vector<std::string> _values;
	};

	explicit CATMshGetOpt(int argc, const char **argv) : _argc(argc), _argv(argv) {
		if(!_argv){
			throw ParsingException("Empty options");
		}
	}
	virtual ~CATMshGetOpt() {}

	void Parse(){
		for(auto i=1;i<_argc;i++){
			std::string opt(_argv[i]);
			if(opt.size() < 2 || opt[0] != '-')
				throw ParsingException("Invalid option");
			if(opt[1] == '-'){
				if(opt.size() < 3)
					throw ParsingException("Empty long option");
				opt = opt.substr(2);
				if(i+1 == _argc)
					throw ParsingException({"Long option <", opt,"> required a parameter"});
				std::string param(_argv[i+1]);
				if(!param.size() ||
					(param.size() == 1 && param[0] == '-') ||
					(param.size() > 1 && param[0] == '-' && param[1] == '-'))
					throw ParsingException({"Invalid parameter <", param,
						"> for long option <", opt,">"});
				i++;
				auto rlongOption = FindLongOption(opt);
				if(!rlongOption)
					throw ParsingException({"Long option <", opt,"> does not exist"});
				auto& longOption = (*rlongOption).get();
				longOption.Set(param);
				const auto& possibleValues = longOption.GetPossibleValues();
				if(possibleValues.size()){
					for(const auto& p : longOption){
						if(std::find(possibleValues.begin(), possibleValues.end(), p) ==
								possibleValues.end()){
							throw ParsingException({"Parameter <", p,"> does not match "
								"with option <", opt, ">"});
						}
					}
				}
			}else{
				std::string opt(_argv[i]);
				if(opt.size() != 2)
					throw ParsingException({"Invalid short option <", opt,">"});
				opt = opt[1];
				auto shortOption = FindShortOption(opt);
				if(!shortOption)
					throw ParsingException({"Short option <", opt,"> does not exist"});
				(*shortOption).get().Set();
			}
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const CATMshGetOpt& getOpt){
		os << std::endl << "Help menu : " << std::endl << std::endl;
		os << "command line : ";
		const auto& argc = getOpt._argc;
		const auto& argv = getOpt._argv;
		for(auto i=0;i<argc;i++)
			os << argv[i] << " ";
		os << std::endl << std::endl;
		for(auto& [name, opt] : getOpt._allOpts){
			os << "\t--" << name << " : " << std::endl;
			auto typeOfParam = opt->GetTypeOfParam();
			auto desc = opt->GetDesc();
			auto possibleValues = opt->GetPossibleValues();
			auto shortcut = opt->GetShort();
			if(desc.size())
				os << "\t\t desc  : " << desc << std::endl;
			if(typeOfParam.size())
				os << "\t\t type  : " << typeOfParam << std::endl;
			if(possibleValues.size()){
				os << "\t\t what  : " << std::endl;
				for(auto v : possibleValues)
					os << "\t\t          -> " << v << std::endl;
			}
			if(shortcut.size())
				os << "\t\t short : " << shortcut << std::endl;
		}
		return os;
	}

	std::optional<std::reference_wrapper<Opt>> FindLongOption(const std::string& longOption) const{
		auto iter = _allOpts.find(longOption);
		if(iter == _allOpts.end())
			return {};
		return std::ref(*(iter->second.get()));
	}

	std::optional<std::reference_wrapper<Opt>> FindShortOption(const std::string& shortOption) const{
		for(auto& [name, opt] : _allOpts){
			if(opt->GetShort() != shortOption)
				continue;
			return std::ref(*(opt.get()));
		}
		return {};
	}

	Opt& GetOption(const std::string& option) const{
		auto longOption = FindLongOption(option);
		if(!longOption)
			throw ParsingException({"Long option <", option,"> does not exist"});
		return *longOption;
	}

protected:
	template <class T>
	void AddOption(T&& opt){
		_allOpts[opt.GetName()] = std::make_unique<T>(opt);
	}

private:
	std::map<std::string, std::unique_ptr<Opt>> _allOpts;
	int _argc;
	const char** _argv;
};

#endif
