/********************************************************************
created:	26:5:2015   18:32
filename: 	c:\Users\Think pad\Documents\Visual Studio 2013\Projects\boost\boost_6_8 any\Variant.h
file path:	c:\Users\Think pad\Documents\Visual Studio 2013\Projects\boost\boost_6_8 any
file base:	Variant
file ext:	h
author:		张潇健

purpose:	任意类型变量，且支持流输入输出，该类并非模板类
*********************************************************************/
#ifndef VARIANT_H
#define VARIANT_H

#include <boost\any.hpp>
#include <boost\shared_ptr.hpp>
#include <boost\make_shared.hpp>
#include <boost\function.hpp>
#include <boost\bind.hpp>
#include <boost\tuple\tuple.hpp>
#include <list>
#include <map>
#include <boost\assert.hpp>
#include <boost/swap.hpp>

#pragma region 声明所有支持的变量
class Variant;

typedef bool Var_Bool;
typedef int Var_Int;
typedef unsigned int Var_Uint;
typedef short Var_Short;
typedef unsigned short Var_UShort;
typedef long Var_Long;
typedef unsigned long Var_Ulong;
typedef float Var_Float;
typedef double Var_Double;
typedef char Var_Char;
typedef std::map<std::string, Variant> Var_Map;
typedef std::list<Variant> Var_List;
typedef std::string Var_String;
#pragma endregion

class VariantRegister {
	friend class Variant;

public:
	typedef boost::function<void(std::ostream&, void*)> SaveCallback;//流输出函数
	typedef boost::function<void(std::istream&, void*)> LoadCallback;//流输入函数
	typedef boost::tuple<std::string, int, SaveCallback, LoadCallback> RegisterInfo;//自定义类型需要注册信息

	VariantRegister(){}

	VariantRegister(RegisterInfo& info)
	{
		int index = info.get<1>();
		std::map<int, RegisterInfo>::iterator it = userTypeMap().find(index);

		BOOST_ASSERT(index >= 127 && it == userTypeMap().end(), "Please make sure your type number >= UserType and unique.");

		userTypeMap().insert(std::map<int, RegisterInfo>::value_type(index, info));
	}

	static std::map<int, RegisterInfo>& userTypeMap()
	{
		static std::map<int, RegisterInfo> _user_type_map;
		return _user_type_map;
	}

	RegisterInfo getUserTypeInfo(int type)
	{
		std::map<int, RegisterInfo>::iterator it = userTypeMap().find(type);
		if (it != userTypeMap().end()) {
			return it->second;
		}
		else {
			return RegisterInfo("Unknow", 0);
		}
	}

	RegisterInfo getUserTypeInfo(std::string name)
	{
		std::map<int, RegisterInfo>::iterator it = userTypeMap().begin();
		for (; it != userTypeMap().end(); ++it) {
			if (it->second.get<0>() == name) {
				return it->second;
			}
		}

		return RegisterInfo("Unknow", 0);
	}

private:

};

class Variant {
	friend class VariantRegister;
public:

#pragma region 定义支持类型的枚举型
	enum VariantType {
		Invalid = 0,
		Bool = 1,
		Int = 2,
		UInt = 3,
		Short = 4,
		UShort = 5,
		Long = 6,
		ULong = 7,
		Float = 8,
		Double = 9,
		Char = 10,
		Map = 11,
		List = 12,
		String = 13,

		UserType = 127,

		//LastType = 0xfffffff;
	};
#pragma endregion

#pragma region 实现所有类型的构造函数重载
	Variant()
		:_data(boost::make_shared<boost::any>()),
		_type(Invalid)
	{

	}

	Variant(Var_Bool value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(Bool)
	{

	}

	Variant(Var_Int value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(Int)
	{

	}

	Variant(Var_Uint value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(UInt)
	{

	}

	Variant(Var_Short value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(Short)
	{

	}

	Variant(Var_UShort value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(UShort)
	{

	}

	Variant(Var_Long value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(Long)
	{

	}

	Variant(Var_Float value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(Float)
	{

	}

	Variant(Var_Double value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(Double)
	{

	}

	Variant(Var_Char value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(Char)
	{

	}

	Variant(Var_String value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(String)
	{

	}

	Variant(Var_Map value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(Map)
	{

	}

	Variant(Var_List value)
		:_data(boost::make_shared<boost::any>(value)),
		_type(List)
	{

	}

	Variant(const Variant& value)
	{
		_type = value._type;
		_data = value._data;
		_user_data_ptr = value._user_data_ptr;
	}

	template<typename T>
	Variant(const T& value)
		:_data(boost::make_shared<boost::any>())
	{
		int type = nameToType(typeid(T).name());
		BOOST_ASSERT(type != Invalid);

		_type = type;
		if (_type < UserType) {
			*_data = value;
		}
		else {
			*_data = value;
			_user_data_ptr = &_getValueRef<T>();
		}
	}

	template<typename T>
	Variant(const std::list<T>& value)
		:_data(boost::make_shared<boost::any>())
	{
		int type = nameToType(typeid(T).name());
		BOOST_ASSERT(type != Invalid);

		Var_List ret;
		typename std::list<T>::const_iterator it;
		it = value.begin();
		for (; it != value.end(); ++it) {
			Variant var = *it;
			ret.push_back(var);
		}
		_type = List;
		*_data = ret;
		return *this;
	}

	template<typename T>
	Variant(const std::map<std::string, T>& value)
		:_data(boost::make_shared<boost::any>())
	{
		int type = nameToType(typeid(T).name());
		BOOST_ASSERT(type != Invalid);

		Var_Map ret;
		typename std::map<T>::const_iterator it;
		it = value.begin();
		for (; it != value.end(); ++it) {
			Variant var = *it;
			ret.insert(Var_Map::value_type(it->first, it->second));
		}
		_type = List;
		*_data = ret;
		return *this;
	}

#pragma endregion

	~Variant(){}

	//交换
	void swap(Variant& other)
	{
		boost::swap(other._type, _type);
		boost::swap(other._data, _data);
	}

	//操作存储值的类型
	inline int type() const{ return _type; }

	const char* type_name() const { return _data->type().name(); }
	//const char* typeName() const(){ return "null"; }

	//是否可转型
	inline bool canConvert(VariantType t) const{ return _type == t; }

	template<typename T>
	bool canConvert() const
	{
		return _data->type() == typeid(T);
	}

	//是否有效值
	inline bool isValid() const{ return !_data->empty(); }

	//清除存放的值
	void clear(){ _type = Invalid; _data->clear(); }

#pragma region toXXX函数声明
	Var_Bool toBool()
	{
		BOOST_ASSERT(_type == Bool);
		return boost::any_cast<Var_Bool>(*_data);
	}

	Var_Int toInt()
	{
		BOOST_ASSERT(_type == Int);
		return boost::any_cast<Var_Int>(*_data);
	}

	Var_Uint toUInt()
	{
		BOOST_ASSERT(_type == UInt);
		return boost::any_cast<Var_Uint>(*_data);
	}

	Var_Short toShort()
	{
		BOOST_ASSERT(_type == Short);
		return boost::any_cast<Var_Short>(*_data);
	}

	Var_UShort toUShort()
	{
		BOOST_ASSERT(_type == UShort);
		return boost::any_cast<Var_UShort>(*_data);
	}

	Var_Long toLong()
	{
		BOOST_ASSERT(_type == Long);
		return boost::any_cast<Var_Long>(*_data);
	}

	Var_Ulong toULong()
	{
		BOOST_ASSERT(_type == ULong);
		return boost::any_cast<Var_Ulong>(*_data);
	}

	Var_Float toFloat()
	{
		BOOST_ASSERT(_type == Float);
		return boost::any_cast<Var_Float>(*_data);
	}

	Var_Double toDouble()
	{
		BOOST_ASSERT(_type == Float);
		return boost::any_cast<Var_Double>(*_data);
	}

	Var_Char toChar()
	{
		BOOST_ASSERT(_type == Char);
		return boost::any_cast<Var_Char>(*_data);
	}

	Var_String toString()
	{
		BOOST_ASSERT(_type == String);
		return boost::any_cast<Var_String>(*_data);
	}

	Var_Map toMap()
	{
		BOOST_ASSERT(_type == Map);
		return boost::any_cast<Var_Map>(*_data);
	}

	Var_List toList()
	{
		BOOST_ASSERT(_type == List);
		return boost::any_cast<Var_List>(*_data);
	}

	template<typename T>
	T toUserData()
	{
		BOOST_ASSERT(canConvert<T>());
		return boost::any_cast<T>(*_data);
	}
#pragma endregion

	//输入与输出
	void load(std::istream& in)
	{
		in >> _type;
		if (_type == Invalid) {
			Var_String s;
			in >> s;
		}
		else if (_type == Bool) {
			Var_Bool tmp;
			in >> tmp;
			*_data = tmp;
		}
		else if (_type == Int) {
			Var_Int tmp;
			in >> tmp;
			*_data = tmp;
		}
		else if (_type >= UserType) {
			VariantRegister tmp;
			VariantRegister::LoadCallback _loadf;

			boost::tie(boost::tuples::ignore, boost::tuples::ignore, boost::tuples::ignore, _loadf) = tmp.getUserTypeInfo(_type);
			_loadf(in, _user_data_ptr);
		}
	}

	void save(std::ostream& out) const
	{
		out << _type;
		if (_type == Invalid) {
			out << Var_String();
		}
		else if (_type == Bool) {
			out << boost::any_cast<Var_Bool>(*_data);
		}
		else if (_type == Int) {
			out << boost::any_cast<Var_Int>(*_data);
		}
		else if (_type == UInt) {
			out << boost::any_cast<Var_Uint>(*_data);
		}
		else if (_type == Short) {
			out << boost::any_cast<Var_Float>(*_data);
		}
		else if (_type == UShort) {
			out << boost::any_cast<Var_UShort>(*_data);
		}
		else if (_type == Long) {
			out << boost::any_cast<Var_Long>(*_data);
		}
		else if (_type == ULong) {
			out << boost::any_cast<Var_Ulong>(*_data);
		}
		else if (_type == Float) {
			out << boost::any_cast<Var_Float>(*_data);
		}
		else if (_type == Double) {
			out << boost::any_cast<Var_Double>(*_data);
		}
		else if (_type == Char) {
			out << boost::any_cast<Var_Char>(*_data);
		}
		else if (_type == String) {
			out << boost::any_cast<Var_String>(*_data);
		}
		else if (_type == List) {
			Var_List tmp = boost::any_cast<Var_List>(*_data);
			for (Var_List::iterator it = tmp.begin(); it != tmp.end(); ++it) {
				it->save(out);
			}
		}
		else if (_type == Map) {
			Var_Map tmp = boost::any_cast<Var_Map>(*_data);
			for (Var_Map::iterator it = tmp.begin(); it != tmp.end(); ++it) {
				out << it->first;
				it->second.save(out);
			}
		}
		else if (_type >= UserType) {
			VariantRegister tmp;
			VariantRegister::SaveCallback _savef;

			boost::tie(boost::tuples::ignore, boost::tuples::ignore, _savef, boost::tuples::ignore) = tmp.getUserTypeInfo(_type);
			_savef(out, _user_data_ptr);
		}
	}

	static std::string typeToName(VariantType type)
	{
		if (type >= UserType) {
			std::string name;
			VariantRegister tmp;
			boost::tie(name, boost::tuples::ignore, boost::tuples::ignore, boost::tuples::ignore)
				= tmp.getUserTypeInfo(type);
			return name;
		}

		switch (type) {
			case Invalid:
				return "Invalid";
			case Bool:
				return typeid(Var_Bool).name();
			case Int:
				return typeid(Var_Int).name();
			case UInt:
				return typeid(Var_Uint).name();
			case Short:
				return typeid(Var_Short).name();
			case UShort:
				return typeid(Var_UShort).name();
			case Long:
				return typeid(Var_Long).name();
			case ULong:
				return typeid(Var_Ulong).name();
			case Float:
				return typeid(Var_Float).name();
			case Double:
				return typeid(Var_Double).name();
			case Char:
				return typeid(Var_Char).name();
			case Map:
				return typeid(Var_Map).name();
			case List:
				return typeid(Var_List).name();
			case String:
				return typeid(Var_String).name();
			default:
				return "Unkonw";
		}
	}

	static int nameToType(const char* name)
	{
		if (strcmp(name, "Invalid") == 0) {
			return Invalid;
		}
		else if (strcmp(name, typeid(Var_Bool).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_Int).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_Uint).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_Short).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_UShort).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_Long).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_Ulong).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_Float).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_Double).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_Char).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_Map).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_List).name()) == 0) {
			return Bool;
		}
		else if (strcmp(name, typeid(Var_String).name()) == 0) {
			return Bool;
		}
		else {
			int type = Invalid;
			VariantRegister tmp;
			boost::tie(boost::tuples::ignore, type, boost::tuples::ignore, boost::tuples::ignore)
				= tmp.getUserTypeInfo(name);
			return type;
		}

		return Invalid;
	}

	Variant& operator=(Var_Bool value)
	{
		_type = Bool;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_Int value)
	{
		_type = Int;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_Uint value)
	{
		_type = UInt;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_Short value)
	{
		_type = Short;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_UShort value)
	{
		_type = UShort;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_Long value)
	{
		_type = Long;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_Ulong value)
	{
		_type = ULong;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_Float value)
	{
		_type = Float;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_Double value)
	{
		_type = Double;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_Char value)
	{
		_type = Char;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_String value)
	{
		_type = String;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_Map value)
	{
		_type = Map;
		*_data = value;
		return *this;
	}

	Variant& operator=(Var_List value)
	{
		_type = List;
		*_data = value;
		return *this;
	}

	Variant& operator=(const Variant& value)
	{
		_type = value._type;
		_data = value._data;
		_user_data_ptr = value._user_data_ptr;
		return *this;
	}

	template<typename T>
	Variant& operator=(const T& value)
	{
		int type = nameToType(typeid(T).name());
		BOOST_ASSERT(type != Invalid);

		_type = type;
		if (_type < UserType) {
			*_data = value;
		}
		else {
			*_data = value;
			_user_data_ptr = &_getValueRef<T>();
		}

		return *this;
	}

	template<typename T>
	Variant& operator=(const std::list<T>& value)
	{
		int type = nameToType(typeid(T).name());
		BOOST_ASSERT(type != Invalid);

		Var_List ret;
		typename std::list<T>::const_iterator it;
		it = value.begin();
		for (; it != value.end(); ++it) {
			Variant var = *it;
			ret.push_back(var);
		}
		_type = List;
		*_data = ret;
		return *this;
	}

	template<typename T>
	Variant& operator=(const std::map<std::string, T>& value)
	{
		int type = nameToType(typeid(T).name());
		BOOST_ASSERT(type != Invalid);

		Var_Map ret;
		typename std::map<T>::const_iterator it;
		it = value.begin();
		for (; it != value.end(); ++it) {
			Variant var = *it;
			ret.insert(Var_Map::value_type(it->first, it->second));
		}
		_type = List;
		*_data = ret;
		return *this;
	}

#pragma region 操作符重载
	//bool operator==(const Variant& v) const;
	//bool operator!=(const Variant& v) const;

	friend std::istream& operator>>(std::istream&, Variant&);
	friend std::ostream& operator<<(std::ostream&, const Variant&);
#pragma endregion

protected:
	template<typename T>
	inline T _getValue()
	{
		return any_cast<T>(*_data);
	}

	template<typename T>
	inline T& _getValueRef()
	{
		return any_cast<T&>(*_data);
	}

private:
	typedef boost::shared_ptr<boost::any> ValueType;
	ValueType _data; //使用any存放任意类型数据，使用shared_ptr使类可以深度拷贝构造
	int _type;//类型
	void* _user_data_ptr;
};

#define VARIANT_REGISTER(classname,num) \
	BOOST_STATIC_ASSERT(num >= Variant::UserType); \
	void* create_variant_##classname() { return new classname(); } \
	void var_save_##classname(std::ostream& out, void* data){
\
	classname* p = static_cast<classname*>(data); \
if (p) out << *p; \
	} \
	void var_load_##classname(std::istream& in, void* data){
\
	classname* p = static_cast<classname*>(data); \
if (p) in >> *p; \
	} \
	VariantRegister variantregister_##classname(\
	VariantRegister::RegisterInfo(typeid(classname).name(), num, boost::bind(var_save_##classname, _1, _2), boost::bind(var_load_##classname, _1, _2))); \


#endif //VARIANT_H