// SPDX-License-Identifier: GPL-3.0-or-later

#ifdef    __UNIMPLEMENTED__

// bdfactory.inl:0x5A1BE0
void __thiscall bdCreatorBase<bdGameInfo>::~bdCreatorBase<bdGameInfo>(bdCreatorBase<bdGameInfo> *this)
{
  this->__vftable = (bdCreatorBase<bdGameInfo>_vtbl *)&bdCreatorBase<bdGameInfo>::`vftable';
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdfactory.inl:0x5A1C00
void __thiscall bdCreator<bdGameInfo,bdGameInfo>::~bdCreator<bdGameInfo,bdGameInfo>(
        bdCreator<bdGameInfo,bdGameInfo> *this)
{
  this->__vftable = (bdCreator<bdGameInfo,bdGameInfo>_vtbl *)&bdCreator<bdGameInfo,bdGameInfo>::`vftable';
  bdCreatorBase<bdGameInfo>::~bdCreatorBase<bdGameInfo>(this);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdfactory.inl:0x5A1C20
bdGameInfo *__thiscall bdCreator<bdGameInfo,bdGameInfo>::create(bdCreator<bdGameInfo,bdGameInfo> *this)
{
  bdGameInfo *v3; // [esp+8h] [ebp-4h]

  v3 = (bdGameInfo *)bdMemory::allocate(0x28u);
  if ( v3 )
    return bdGameInfo::bdGameInfo(v3);
  else
    return 0;
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdfactory.inl:0x5A1C60
unsigned int __thiscall bdCreator<bdGameInfo,bdGameInfo>::getSizeOf(bdCreator<bdGameInfo,bdGameInfo> *this)
{
  return 40;
}

#endif // __UNIMPLEMENTED__
