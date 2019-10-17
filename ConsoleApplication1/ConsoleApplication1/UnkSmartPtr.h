#pragma once

template<class IFace>
class UnkSmartPtr
{
private:
	IFace *_pointer;
public:
	UnkSmartPtr()
	{
		_pointer = nullptr;
	}
	UnkSmartPtr( IFace* ptr )
	{
		_pointer = ptr;
		if ( _pointer )
			_pointer->AddRef();
	}
	
	template<class IFaceOther>
	UnkSmartPtr(IFaceOther* ptr)
	{
		if ( ptr )
			ptr->QueryInterface( IFace::myType, (void**)&_pointer );
		else _pointer = nullptr;
	}
	UnkSmartPtr(const UnkSmartPtr& other)
	{
		_pointer = other.get();
		if (_pointer)
			_pointer->AddRef();
	}
	UnkSmartPtr(UnkSmartPtr&& other)
		: _pointer( std::exchange( other._pointer, nullptr ) )
	{}
	template<class IFaceOther>
	UnkSmartPtr(const UnkSmartPtr<IFaceOther>& other)
	{
		if ( other.get())
			other.get()->QueryInterface( IFace::myType, (void**)&_pointer);
		else _pointer = nullptr;
	}
	~UnkSmartPtr()
	{
		if (_pointer)
			_pointer->Release();
	}

// operator =

	UnkSmartPtr& operator=(IFace* ptr)
	{
		if (_pointer)
			_pointer->Release();
		_pointer = ptr;
		if (_pointer)
			_pointer->AddRef();
		return *this;
	}
	template<class IFaceOther>
	UnkSmartPtr& operator=(IFaceOther* ptr)
	{
		if (_pointer)
			_pointer->Release();
		if (ptr)
			ptr->QueryInterface(IFace::myType, (void**)&_pointer);
		else _pointer = nullptr;
		return *this;
	}
	UnkSmartPtr& operator=(const UnkSmartPtr& other)
	{
		if (_pointer)
			_pointer->Release();
		_pointer = other.get();
		if (_pointer)
			_pointer->AddRef();
		return *this;
	}
	UnkSmartPtr& operator=(UnkSmartPtr&& other)
	{
		if (_pointer)
			_pointer->Release();
		_pointer = std::exchange(other._pointer, nullptr);
		return *this;
	}

	template<class IFaceOther>
	UnkSmartPtr& operator=(const UnkSmartPtr<IFaceOther>& other)
	{
		if (_pointer)
			_pointer->Release();
		if (other.get() )
			other.get()->QueryInterface(IFace::myType, (void**)&_pointer);
		else _pointer = nullptr;
		return *this;
	}


	IFace *operator->() const
	{
		return _pointer;
	}
	IFace *get() const
	{ 
		return _pointer; 
	}
	void Release()
	{
		if (_pointer)
			_pointer->Release();
		_pointer = nullptr;
	}

	operator IFace*() //@#$FDINU - is BAD because it allows: delete sp;
	{
		return _pointer;
	}

	IFace** operator&()//@#$FDINU - is BAD because we can no longer get the address of this smart ptr ( having the address of something is fundamental )
	{
		if (_pointer)
			_pointer->Release();
		_pointer = nullptr;
		
		return &_pointer;//@#$FDINU - should only be used when passed to [out]
	}

private:
	class Tester
	{
		void operator delete(void*);// if trying to delete Tester, compiler will scream about operator deletes implementation
	};
public:
	operator Tester*() const //This will allow SmartPtr<something> sp; if ( sp ) { ... }
	{
		if (!_pointer) return nullptr;
		static Tester test;
		return &test;
	}

	bool operator!() const
	{
		return _pointer == 0;
	}


	template<class IFaceOther>
	inline friend bool operator==(const UnkSmartPtr &left, IFaceOther* right )
	{
		if (left.get() == nullptr && right == nullptr) return true;
		if (left.get() == nullptr || right == nullptr) return false;

		IFaceOther *face = nullptr;
		if (left.get()->QueryInterface(IFaceOther::myType, (void**)&face) == false)
			return false;
		
		bool toRet = false;
		if (face == right)
			toRet = true;
		face->Release();
		return toRet;
	}
	template<class IFaceOther>
	inline friend bool operator==( IFaceOther* right, const UnkSmartPtr &left )
	{
		if (left.get() == nullptr && right == nullptr) return true;
		if (left.get() == nullptr || right == nullptr) return false;

		IFaceOther *face = nullptr;
		if (left.get()->QueryInterface(IFaceOther::myType, (void**)&face) == false)
			return false;

		bool toRet = false;
		if (face == right)
			toRet = true;
		face->Release();
		return toRet;
	}

	template<class IFaceOther>
	inline friend bool operator!=(const UnkSmartPtr &left, IFaceOther* right)
	{
		if (left.get() == nullptr && right == nullptr) return false;
		if (left.get() == nullptr || right == nullptr) return true;

		IFaceOther *face = nullptr;
		if (left.get()->QueryInterface(IFaceOther::myType, (void**)&face) == false)
			return true;

		bool toRet = true;
		if (face == right)
			toRet = false;
		face->Release();
		return toRet;
	}
	template<class IFaceOther>
	inline friend bool operator!=(IFaceOther* right, const UnkSmartPtr &left )
	{
		if (left.get() == nullptr && right == nullptr) return false;
		if (left.get() == nullptr || right == nullptr) return true;

		IFaceOther *face = nullptr;
		if (left.get()->QueryInterface(IFaceOther::myType, (void**)&face) == false)
			return true;

		bool toRet = true;
		if (face == right)
			toRet = false;
		face->Release();
		return toRet;
	}

	bool operator==(UnkSmartPtr& rhs) const
	{
		if (rhs.get() == _pointer) return true;
		return false;
	}
	bool operator!=(UnkSmartPtr& rhs) const
	{
		if (rhs.get() != _pointer) return true;
		return false;
	}
	template<class IFaceOther>
	inline bool operator==(const UnkSmartPtr<IFaceOther> &right)
	{
		if ( _pointer == nullptr && right.get() == nullptr) return true;
		if ( _pointer == nullptr || right.get() == nullptr) return false;

		IFaceOther *face = nullptr;
		if ( _pointer->QueryInterface(IFaceOther::myType, (void**)&face) == false)
			return false;

		bool toRet = false;
		if ( face == right.get() )
			toRet = true;
		_pointer->Release();
		return toRet;
	}
	template<class IFaceOther>
	inline bool operator!=(const UnkSmartPtr<IFaceOther> &right)
	{
		if (_pointer == nullptr && right.get() == nullptr) return false;
		if (_pointer == nullptr || right.get() == nullptr) return true;

		IFaceOther *face = nullptr;
		if (_pointer->QueryInterface(IFaceOther::myType, (void**)&face) == false)
			return true;

		bool toRet = true;
		if (face == right.get())
			toRet = false;
		_pointer->Release();
		return toRet;
	}

};

