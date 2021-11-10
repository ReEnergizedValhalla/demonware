// SPDX-License-Identifier: GPL-3.0-or-later

#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5A1C70
void __thiscall bdArray<bdReference<bdGameInfo>>::clear(bdArray<bdReference<bdGameInfo> > *this)
{
  unsigned int m_size; // [esp+8h] [ebp-1Ch]
  bdReference<bdGameInfo> *m_data; // [esp+Ch] [ebp-18h]
  unsigned int i; // [esp+20h] [ebp-4h]

  m_size = this->m_size;
  m_data = this->m_data;
  for ( i = 0; i < m_size; ++i )
    bdReference<bdRemoteTask>::~bdReference<bdRemoteTask>((bdReference<bdCommonAddr> *)&m_data[i]);
  bdMemory::deallocate(this->m_data);
  this->m_data = 0;
  this->m_size = 0;
  this->m_capacity = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5A1D10
void __thiscall bdArray<bdReference<bdGameInfo>>::pushBack(
        bdArray<bdReference<bdGameInfo> > *this,
        const bdReference<bdGameInfo> *value)
{
  bdReference<bdGameInfo> *v3; // [esp+14h] [ebp-40h]

  if ( this->m_size == this->m_capacity )
    bdArray<bdReference<bdGameInfo>>::increaseCapacity(this, 1u);
  v3 = &this->m_data[this->m_size];
  if ( v3 )
  {
    v3->m_ptr = value->m_ptr;
    if ( v3->m_ptr )
      InterlockedIncrement(&v3->m_ptr->m_refCount);
  }
  ++this->m_size;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5A1E60
void __thiscall bdArray<bdReference<bdGameInfo>>::increaseCapacity(
        bdArray<bdReference<bdGameInfo> > *this,
        const unsigned int increase)
{
  unsigned int m_capacity; // [esp+0h] [ebp-44h]
  unsigned int m_size; // [esp+Ch] [ebp-38h]
  bdReference<bdGameInfo> *m_data; // [esp+10h] [ebp-34h]
  unsigned int i; // [esp+24h] [ebp-20h]
  bdReference<bdGameInfo> *newData; // [esp+3Ch] [ebp-8h]
  unsigned int newCapacity; // [esp+40h] [ebp-4h]

  if ( increase <= this->m_capacity )
    m_capacity = this->m_capacity;
  else
    m_capacity = increase;
  newCapacity = m_capacity + this->m_capacity;
  newData = 0;
  if ( newCapacity )
  {
    newData = (bdReference<bdGameInfo> *)bdMemory::allocate(4 * newCapacity);
    bdArray<bdReference<bdGameInfo>>::copyConstructArrayArray(this, newData, this->m_data, this->m_size);
  }
  m_size = this->m_size;
  m_data = this->m_data;
  for ( i = 0; i < m_size; ++i )
    bdReference<bdRemoteTask>::~bdReference<bdRemoteTask>((bdReference<bdCommonAddr> *)&m_data[i]);
  bdMemory::deallocate(this->m_data);
  this->m_data = newData;
  this->m_capacity = newCapacity;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5A1F50
void __thiscall bdArray<bdReference<bdGameInfo>>::copyConstructArrayArray(
        bdArray<bdReference<bdGameInfo> > *this,
        bdReference<bdGameInfo> *dest,
        const bdReference<bdGameInfo> *src,
        const unsigned int n)
{
  bdReference<bdGameInfo> *v4; // [esp+10h] [ebp-10h]
  unsigned int i; // [esp+1Ch] [ebp-4h]

  for ( i = 0; i < n; ++i )
  {
    v4 = &dest[i];
    if ( v4 )
    {
      v4->m_ptr = (bdGameInfo *)src[i];
      if ( v4->m_ptr )
        InterlockedIncrement(&v4->m_ptr->m_refCount);
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5A4400
void __thiscall bdArray<bdString>::clear(bdArray<bdString> *this)
{
  unsigned int m_size; // [esp+8h] [ebp-10h]
  bdString *m_data; // [esp+Ch] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-4h]

  m_size = this->m_size;
  m_data = this->m_data;
  for ( i = 0; i < m_size; ++i )
    bdString::~bdString(&m_data[i]);
  bdMemory::deallocate(this->m_data);
  this->m_data = 0;
  this->m_size = 0;
  this->m_capacity = 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5A44A0
void __thiscall bdArray<bdString>::pushBack(bdArray<bdString> *this, const bdString *value)
{
  if ( this->m_size == this->m_capacity )
    bdArray<bdString>::increaseCapacity(this, 1u);
  if ( &this->m_data[this->m_size] )
    bdString::bdString(&this->m_data[this->m_size], value);
  ++this->m_size;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5A4510
void __thiscall bdArray<bdInetAddr>::pushBack(bdArray<bdInetAddr> *this, const bdInetAddr *value)
{
  if ( this->m_size == this->m_capacity )
    bdArray<bdInetAddr>::increaseCapacity(this, 1u);
  if ( &this->m_data[this->m_size] )
    bdInetAddr::bdInetAddr(&this->m_data[this->m_size], value);
  ++this->m_size;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5A4580
void __thiscall bdArray<bdString>::increaseCapacity(bdArray<bdString> *this, const unsigned int increase)
{
  unsigned int m_capacity; // [esp+4h] [ebp-3Ch]
  unsigned int v4; // [esp+10h] [ebp-30h]
  bdString *v5; // [esp+14h] [ebp-2Ch]
  unsigned int j; // [esp+1Ch] [ebp-24h]
  unsigned int m_size; // [esp+20h] [ebp-20h]
  bdString *m_data; // [esp+24h] [ebp-1Ch]
  bdString *v9; // [esp+28h] [ebp-18h]
  unsigned int i; // [esp+34h] [ebp-Ch]
  bdString *newData; // [esp+38h] [ebp-8h]
  unsigned int newCapacity; // [esp+3Ch] [ebp-4h]

  if ( increase <= this->m_capacity )
    m_capacity = this->m_capacity;
  else
    m_capacity = increase;
  newCapacity = m_capacity + this->m_capacity;
  newData = 0;
  if ( newCapacity )
  {
    newData = (bdString *)bdMemory::allocate(4 * newCapacity);
    m_size = this->m_size;
    m_data = this->m_data;
    for ( i = 0; i < m_size; ++i )
    {
      v9 = &newData[i];
      if ( v9 )
        bdString::bdString(v9, &m_data[i]);
    }
  }
  v4 = this->m_size;
  v5 = this->m_data;
  for ( j = 0; j < v4; ++j )
    bdString::~bdString(&v5[j]);
  bdMemory::deallocate(this->m_data);
  this->m_data = newData;
  this->m_capacity = newCapacity;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5A46C0
void __thiscall bdArray<bdInetAddr>::increaseCapacity(bdArray<bdInetAddr> *this, const unsigned int increase)
{
  unsigned int m_capacity; // [esp+4h] [ebp-3Ch]
  unsigned int v4; // [esp+10h] [ebp-30h]
  bdInetAddr *v5; // [esp+14h] [ebp-2Ch]
  unsigned int j; // [esp+1Ch] [ebp-24h]
  unsigned int m_size; // [esp+20h] [ebp-20h]
  bdInetAddr *m_data; // [esp+24h] [ebp-1Ch]
  bdInetAddr *v9; // [esp+28h] [ebp-18h]
  unsigned int i; // [esp+34h] [ebp-Ch]
  bdInetAddr *newData; // [esp+38h] [ebp-8h]
  unsigned int newCapacity; // [esp+3Ch] [ebp-4h]

  if ( increase <= this->m_capacity )
    m_capacity = this->m_capacity;
  else
    m_capacity = increase;
  newCapacity = m_capacity + this->m_capacity;
  newData = 0;
  if ( newCapacity )
  {
    newData = (bdInetAddr *)bdMemory::allocate(4 * newCapacity);
    m_size = this->m_size;
    m_data = this->m_data;
    for ( i = 0; i < m_size; ++i )
    {
      v9 = &newData[i];
      if ( v9 )
        bdInetAddr::bdInetAddr(v9, &m_data[i]);
    }
  }
  v4 = this->m_size;
  v5 = this->m_data;
  for ( j = 0; j < v4; ++j )
    bdInetAddr::~bdInetAddr(&v5[j]);
  bdMemory::deallocate(this->m_data);
  this->m_data = newData;
  this->m_capacity = newCapacity;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdarray.inl:0x5A4800
void __thiscall bdArray<bdInetAddr>::clear(bdArray<bdInetAddr> *this)
{
  unsigned int m_size; // [esp+8h] [ebp-10h]
  bdInetAddr *m_data; // [esp+Ch] [ebp-Ch]
  unsigned int i; // [esp+14h] [ebp-4h]

  m_size = this->m_size;
  m_data = this->m_data;
  for ( i = 0; i < m_size; ++i )
    bdInetAddr::~bdInetAddr(&m_data[i]);
  bdMemory::deallocate(this->m_data);
  this->m_data = 0;
  this->m_size = 0;
  this->m_capacity = 0;
}

#endif // __UNIMPLEMENTED__
