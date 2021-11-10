// SPDX-License-Identifier: GPL-3.0-or-later

#ifdef    __UNIMPLEMENTED__

// bdreference.inl:0x56C9B0
bdReference<bdCommonAddr> *__thiscall bdReference<bdCommonAddr>::operator=(
        bdReference<bdCommonAddr> *this,
        const bdReference<bdCommonAddr> *other)
{
  bdCommonAddr *m_ptr; // [esp+10h] [ebp-Ch]

  if ( other != this )
  {
    if ( this->m_ptr )
    {
      m_ptr = this->m_ptr;
      InterlockedDecrement(&this->m_ptr->m_refCount);
      if ( !m_ptr->m_refCount )
      {
        if ( this->m_ptr )
          ((void (__thiscall *)(bdCommonAddr *, int))this->m_ptr->~bdReferencable)(this->m_ptr, 1);
      }
    }
    this->m_ptr = other->m_ptr;
    if ( this->m_ptr )
      InterlockedIncrement(&this->m_ptr->m_refCount);
  }
  return this;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreference.inl:0x56CA60
void __thiscall bdReference<bdRemoteTask>::~bdReference<bdRemoteTask>(bdReference<bdCommonAddr> *this)
{
  bdCommonAddr *m_ptr; // [esp+8h] [ebp-Ch]

  if ( this->m_ptr )
  {
    m_ptr = this->m_ptr;
    InterlockedDecrement(&this->m_ptr->m_refCount);
    if ( !m_ptr->m_refCount )
    {
      if ( this->m_ptr )
        ((void (__thiscall *)(bdCommonAddr *, int))this->m_ptr->~bdReferencable)(this->m_ptr, 1);
      this->m_ptr = 0;
    }
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreference.inl:0x5A5DB0
void __thiscall bdReference<bdCommonAddr>::operator=(bdReference<bdRemoteTask> *this, bdRemoteTask *p)
{
  bdRemoteTask *m_ptr; // [esp+10h] [ebp-Ch]

  if ( this->m_ptr )
  {
    m_ptr = this->m_ptr;
    InterlockedDecrement(&this->m_ptr->m_refCount);
    if ( !m_ptr->m_refCount )
    {
      if ( this->m_ptr )
        ((void (__thiscall *)(bdRemoteTask *, int))this->m_ptr->~bdReferencable)(this->m_ptr, 1);
    }
  }
  this->m_ptr = p;
  if ( this->m_ptr )
    InterlockedIncrement(&this->m_ptr->m_refCount);
}

#endif // __UNIMPLEMENTED__
