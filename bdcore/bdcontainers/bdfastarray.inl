// SPDX-License-Identifier: GPL-3.0-or-later

#ifdef    __UNIMPLEMENTED__

// bdfastarray.inl:0x567BD0
void __thiscall bdFastArray<void (__cdecl *)(void)>::pushBack(
        bdFastArray<void (__cdecl*)(void)> *this,
        void (__cdecl *const *value)())
{
  if ( this->m_size == this->m_capacity )
    bdFastArray<void (__cdecl *)(void)>::increaseCapacity(this, 1u);
  this->m_data[this->m_size++] = *value;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdfastarray.inl:0x567C30
void __thiscall bdFastArray<void (__cdecl *)(void)>::increaseCapacity(
        bdFastArray<void (__cdecl*)(void)> *this,
        const unsigned int increase)
{
  unsigned int m_capacity; // [esp+0h] [ebp-1Ch]
  unsigned int m_size; // [esp+Ch] [ebp-10h]
  unsigned __int8 *newData; // [esp+14h] [ebp-8h]
  unsigned int newCapacity; // [esp+18h] [ebp-4h]

  if ( increase <= this->m_capacity )
    m_capacity = this->m_capacity;
  else
    m_capacity = increase;
  newCapacity = m_capacity + this->m_capacity;
  newData = 0;
  if ( newCapacity )
  {
    newData = (unsigned __int8 *)bdMemory::allocate(4 * newCapacity);
    m_size = this->m_size;
    if ( m_size )
      memcpy(newData, (unsigned __int8 *)this->m_data, 4 * m_size);
  }
  bdMemory::deallocate(this->m_data);
  this->m_data = (void (__cdecl **)())newData;
  this->m_capacity = newCapacity;
}

#endif // __UNIMPLEMENTED__
