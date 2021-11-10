// SPDX-License-Identifier: GPL-3.0-or-later

#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x567B10
bdTrulyRandomImpl *__cdecl bdSingleton<bdTrulyRandomImpl>::getInstance()
{
  BOOL m_cleaningUp; // edx
  bdTrulyRandomImpl *Address; // [esp+0h] [ebp-60h]
  void (__cdecl *value)(); // [esp+4h] [ebp-5Ch] BYREF
  bdSingletonRegistryImpl *Instance; // [esp+8h] [ebp-58h]
  bool v5; // [esp+27h] [ebp-39h]
  void *v6; // [esp+58h] [ebp-8h]
  bdAddr *v7; // [esp+5Ch] [ebp-4h]

  if ( !bdSingleton<bdTrulyRandomImpl>::m_instance )
  {
    v7 = (bdAddr *)bdMemory::allocate(1u);
    if ( v7 )
      Address = (bdTrulyRandomImpl *)bdAddr::getAddress(v7);
    else
      Address = 0;
    bdSingleton<bdTrulyRandomImpl>::m_instance = Address;
    if ( Address )
    {
      value = (void (__cdecl *)())bdSingleton<bdTrulyRandomImpl>::destroyInstance;
      Instance = bdSingleton<bdSingletonRegistryImpl>::getInstance();
      m_cleaningUp = Instance->m_cleaningUp;
      v5 = !m_cleaningUp;
      if ( !m_cleaningUp )
        bdFastArray<void (__cdecl *)(void)>::pushBack(&Instance->m_destroyFunctions, &value);
      if ( !v5 )
      {
        v6 = bdSingleton<bdTrulyRandomImpl>::m_instance;
        bdMemory::deallocate(bdSingleton<bdTrulyRandomImpl>::m_instance);
        bdSingleton<bdTrulyRandomImpl>::m_instance = 0;
        DebugBreak();
      }
    }
    else
    {
      DebugBreak();
    }
  }
  return bdSingleton<bdTrulyRandomImpl>::m_instance;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x567CE0
void bdSingleton<bdTrulyRandomImpl>::destroyInstance()
{
  if ( bdSingleton<bdTrulyRandomImpl>::m_instance )
  {
    bdMemory::deallocate(bdSingleton<bdTrulyRandomImpl>::m_instance);
    bdSingleton<bdTrulyRandomImpl>::m_instance = 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x567D10
bdSingletonRegistryImpl *__cdecl bdSingleton<bdSingletonRegistryImpl>::getInstance()
{
  bdSingletonRegistryImpl *v0; // eax
  BOOL m_cleaningUp; // edx
  bdSingletonRegistryImpl *v3; // [esp+4h] [ebp-3Ch]
  void (__cdecl *value)(); // [esp+8h] [ebp-38h] BYREF
  bdSingletonRegistryImpl *Instance; // [esp+Ch] [ebp-34h]
  bool v6; // [esp+2Bh] [ebp-15h]
  bdSingletonRegistryImpl *v7; // [esp+34h] [ebp-Ch]
  bdSingletonRegistryImpl *v8; // [esp+38h] [ebp-8h]
  bdSingletonRegistryImpl *v9; // [esp+3Ch] [ebp-4h]

  if ( !bdSingleton<bdSingletonRegistryImpl>::m_instance )
  {
    v9 = (bdSingletonRegistryImpl *)bdMemory::allocate(0x14u);
    if ( v9 )
    {
      bdSingletonRegistryImpl::bdSingletonRegistryImpl(v9);
      v3 = v0;
    }
    else
    {
      v3 = 0;
    }
    bdSingleton<bdSingletonRegistryImpl>::m_instance = v3;
    if ( v3 )
    {
      value = (void (__cdecl *)())bdSingleton<bdSingletonRegistryImpl>::destroyInstance;
      Instance = bdSingleton<bdSingletonRegistryImpl>::getInstance();
      m_cleaningUp = Instance->m_cleaningUp;
      v6 = !m_cleaningUp;
      if ( !m_cleaningUp )
        bdFastArray<void (__cdecl *)(void)>::pushBack(&Instance->m_destroyFunctions, &value);
      if ( !v6 )
      {
        v7 = bdSingleton<bdSingletonRegistryImpl>::m_instance;
        v8 = bdSingleton<bdSingletonRegistryImpl>::m_instance;
        if ( bdSingleton<bdSingletonRegistryImpl>::m_instance )
          ((void (__thiscall *)(bdSingletonRegistryImpl *, int))v8->~bdSingletonRegistryImpl)(v8, 1);
        bdSingleton<bdSingletonRegistryImpl>::m_instance = 0;
        DebugBreak();
      }
    }
    else
    {
      DebugBreak();
    }
  }
  return bdSingleton<bdSingletonRegistryImpl>::m_instance;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x567ED0
void bdSingleton<bdSingletonRegistryImpl>::destroyInstance()
{
  if ( bdSingleton<bdSingletonRegistryImpl>::m_instance )
  {
    ((void (__thiscall *)(bdSingletonRegistryImpl *, int))bdSingleton<bdSingletonRegistryImpl>::m_instance->~bdSingletonRegistryImpl)(
      bdSingleton<bdSingletonRegistryImpl>::m_instance,
      1);
    bdSingleton<bdSingletonRegistryImpl>::m_instance = 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x5A1A10
bdNetImpl *__cdecl bdSingleton<bdNetImpl>::getInstance()
{
  BOOL m_cleaningUp; // edx
  bdNetImpl *v2; // [esp+4h] [ebp-6Ch]
  void (__cdecl *value)(); // [esp+8h] [ebp-68h] BYREF
  bdSingletonRegistryImpl *Instance; // [esp+Ch] [ebp-64h]
  bool v5; // [esp+2Bh] [ebp-45h]
  bdNetImpl *v6; // [esp+64h] [ebp-Ch]
  bdNetImpl *v7; // [esp+68h] [ebp-8h]
  bdNetImpl *v8; // [esp+6Ch] [ebp-4h]

  if ( !bdSingleton<bdNetImpl>::m_instance )
  {
    v8 = (bdNetImpl *)bdMemory::allocate(0x4760u);
    if ( v8 )
      v2 = bdNetImpl::bdNetImpl(v8);
    else
      v2 = 0;
    bdSingleton<bdNetImpl>::m_instance = v2;
    if ( v2 )
    {
      value = (void (__cdecl *)())bdSingleton<bdNetImpl>::destroyInstance;
      Instance = bdSingleton<bdSingletonRegistryImpl>::getInstance();
      m_cleaningUp = Instance->m_cleaningUp;
      v5 = !m_cleaningUp;
      if ( !m_cleaningUp )
        bdFastArray<void (__cdecl *)(void)>::pushBack(&Instance->m_destroyFunctions, &value);
      if ( !v5 )
      {
        v6 = bdSingleton<bdNetImpl>::m_instance;
        v7 = bdSingleton<bdNetImpl>::m_instance;
        if ( bdSingleton<bdNetImpl>::m_instance )
          ((void (__thiscall *)(bdNetImpl *, int))v7->~bdNetImpl)(v7, 1);
        bdSingleton<bdNetImpl>::m_instance = 0;
        DebugBreak();
      }
    }
    else
    {
      DebugBreak();
    }
  }
  return bdSingleton<bdNetImpl>::m_instance;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x5A1AF0
bdGameInfoFactoryImpl *__cdecl bdSingleton<bdGameInfoFactoryImpl>::getInstance()
{
  bdGameInfoFactoryImpl *v0; // eax
  BOOL m_cleaningUp; // edx
  bdGameInfoFactoryImpl *v3; // [esp+4h] [ebp-64h]
  void (__cdecl *value)(); // [esp+8h] [ebp-60h] BYREF
  bdSingletonRegistryImpl *Instance; // [esp+Ch] [ebp-5Ch]
  bool v6; // [esp+2Bh] [ebp-3Dh]
  bdGameInfoFactoryImpl *v7; // [esp+5Ch] [ebp-Ch]
  bdGameInfoFactoryImpl *v8; // [esp+60h] [ebp-8h]
  void *v9; // [esp+64h] [ebp-4h]

  if ( !bdSingleton<bdGameInfoFactoryImpl>::m_instance )
  {
    v9 = bdMemory::allocate(4u);
    if ( v9 )
    {
      bdGameInfoFactoryImpl::bdGameInfoFactoryImpl(v9);
      v3 = v0;
    }
    else
    {
      v3 = 0;
    }
    bdSingleton<bdGameInfoFactoryImpl>::m_instance = v3;
    if ( v3 )
    {
      value = (void (__cdecl *)())bdSingleton<bdGameInfoFactoryImpl>::destroyInstance;
      Instance = bdSingleton<bdSingletonRegistryImpl>::getInstance();
      m_cleaningUp = Instance->m_cleaningUp;
      v6 = !m_cleaningUp;
      if ( !m_cleaningUp )
        bdFastArray<void (__cdecl *)(void)>::pushBack(&Instance->m_destroyFunctions, &value);
      if ( !v6 )
      {
        v7 = bdSingleton<bdGameInfoFactoryImpl>::m_instance;
        v8 = bdSingleton<bdGameInfoFactoryImpl>::m_instance;
        if ( bdSingleton<bdGameInfoFactoryImpl>::m_instance )
        {
          bdGameInfoFactoryImpl::~bdGameInfoFactoryImpl(v8);
          bdMemory::deallocate(v8);
        }
        bdSingleton<bdGameInfoFactoryImpl>::m_instance = 0;
        DebugBreak();
      }
    }
    else
    {
      DebugBreak();
    }
  }
  return bdSingleton<bdGameInfoFactoryImpl>::m_instance;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x5A1DB0
void bdSingleton<bdNetImpl>::destroyInstance()
{
  if ( bdSingleton<bdNetImpl>::m_instance )
  {
    ((void (__thiscall *)(bdNetImpl *, int))bdSingleton<bdNetImpl>::m_instance->~bdNetImpl)(
      bdSingleton<bdNetImpl>::m_instance,
      1);
    bdSingleton<bdNetImpl>::m_instance = 0;
  }
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdsingleton.inl:0x5A1E00
void bdSingleton<bdGameInfoFactoryImpl>::destroyInstance()
{
  bdGameInfoFactoryImpl *v0; // [esp+8h] [ebp-4h]

  if ( bdSingleton<bdGameInfoFactoryImpl>::m_instance )
  {
    v0 = bdSingleton<bdGameInfoFactoryImpl>::m_instance;
    if ( bdSingleton<bdGameInfoFactoryImpl>::m_instance )
    {
      bdGameInfoFactoryImpl::~bdGameInfoFactoryImpl(bdSingleton<bdGameInfoFactoryImpl>::m_instance);
      bdMemory::deallocate(v0);
    }
    bdSingleton<bdGameInfoFactoryImpl>::m_instance = 0;
  }
}

#endif // __UNIMPLEMENTED__
