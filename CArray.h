#pragma once
#define CAP_INDEX 1.5

template <class _T>
class CArray
{
private:
	_T *Elem;
	unsigned int _size;
	unsigned int _capacity;
	void expand();
public: // Interface

		// ����������� �� ���������
	CArray();

	CArray(
		unsigned int _size
	);

	// ���������� �����������
	//CArray(
	//	const CArray & _array
	//);

	void operator= (
		const CArray<_T> & object
	);

	// ����������
	~CArray();

	//��������� ������
	void fill(unsigned int _n, _T _data);

	_T* getData();

	// �������� ������� � ����� �������
	//void push_back(
	//	const _T & _value
	//);

	// �������� ������� � ������ �� ��������� �������
	void insert(
		unsigned int  _index,
		const _T & _value
	);

	// ������� ������� ������� �� ��������� �������
	//void erase(
	//	unsigned int _index
	//);

	// �������� ������
	void clear();

	// �������� ������ �������
	unsigned int size() const;

	// �������� ������� ������� �� ��������� �������
	_T & operator[](
		unsigned int _index
		);

protected: // Attributes

};

template<class _T>
void CArray<_T>::expand()
{
	_capacity = 1  +  _capacity  *  CAP_INDEX;
	_T * temp;
	temp = new _T[_capacity];
	for (size_t i = 0; i < _size; ++i)
	{
		temp[i] = Elem[i];
	}
	delete[] Elem;
	Elem = temp;
}

template<class _T>
inline CArray<_T>::CArray()
{
	_size = 0;
	_capacity = 0;
	Elem = nullptr;
}

template<class _T>
inline CArray<_T>::CArray(unsigned int _size)
{
	this->_size = _size;
	_capacity = 1 + _size*CAP_INDEX;
	Elem = new _T[_capacity];
}

template<class _T>
void CArray<_T>::operator=(const CArray<_T> & object)
{
	if (Elem)
		delete[] Elem;
	_size = object._size;
	_capacity = object._capacity;
	Elem = new _T[_capacity];
	for (size_t i = 0;i < _size; ++i)
	{
		*(Elem+i) =  *(object.Elem+i);
	}
}

template<class _T>
inline CArray<_T>::~CArray()
{
	if (Elem)
		delete[] Elem;
}

template<class _T>
void CArray<_T>::fill(unsigned int _n, _T _data)
{
	for (size_t i = 0; i < _n; ++i)
		*(Elem + i) = _data;
}

template<class _T>
_T* CArray<_T>::getData()
{
	return Elem;
}

template<class _T>
void CArray<_T>::insert(
	unsigned int _index, 
	const _T & _value)
{
	if (_index >= _size)
		//TODO: THROW
		throw "ERROR: NOT ENOUGHT SPACE";
	if (!Elem)
	{
		_capacity = 2;
		Elem = new _T[_capacity];
		_size = 1;
		Elem[0] = _value;
		return;
	}
	if (_size < _capacity)
		//TODO: INSERT
	{
		_T *_end = Elem + _capacity - 1;
		_T * _indx = Elem + _index;
		while (_end != _indx)
		{
			*_end = *(_end - 1);
			--_end;
		}
		++_size;
		*_indx = _value;
	}
	else
		//TODO: EXPAND & INSERT
	{
		expand();
		insert(_index, _value);
	}
}

template<class _T>
inline void CArray<_T>::clear()
{
	if (Elem)
	{
		delete[] Elem;
		Elem = nullptr;
		_size = 0;
		_capacity = 0;
	}
		
}

template<class _T>
inline unsigned int CArray<_T>::size() const
{
	return _size;
}

template<class _T>
inline _T & CArray<_T>::operator[](unsigned int _index)
{
	return *(Elem + _index);
}
