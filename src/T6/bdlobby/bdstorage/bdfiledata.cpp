// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdfiledata.cpp:0x937E10
void __cdecl BG_InitWeaponStrings()
{
  memset((unsigned __int8 *)weaponStrings, 0, sizeof(weaponStrings));
  BG_LoadWeaponStrings();
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdfiledata.cpp:0x937E30
void __cdecl BG_AddVehicleName(const char *vehName, int vehType, int drivers, int gunners, int passengers)
{
  const char *v5; // esi
  int v6; // edi
  animStringItem_t *i; // ebx
  char v8; // al
  int v9; // ebx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int seats; // ecx
  int v14; // edx
  int v15; // eax
  int v16; // ecx

  v5 = vehName;
  v6 = 0;
  for ( i = animVehicleNameStr; i->string; ++v6 )
  {
    if ( v6 >= 16 )
      break;
    if ( !I_stricmp(vehName, i->string) )
      return;
    ++i;
  }
  if ( v6 + 1 >= 16
    && !Assert_MyHandler(
          "c:\\t6\\code\\src_noserver\\bgame\\bg_animation.cpp",
          930,
          0,
          "(i+1 < 16)",
          (const char *)&pBlock) )
  {
    __debugbreak();
  }
  I_strncpyz((char *)(24 * v6 + 136286648), vehName, 24);
  animVehicleNameStr[v6].string = (const char *)(24 * v6 + 136286648);
  v8 = *vehName;
  v9 = 0;
  if ( *vehName )
  {
    do
    {
      v10 = (_DWORD)&v5[119 - (_DWORD)vehName] * (char)tolower(v8);
      ++v5;
      v9 += v10;
      v8 = *v5;
    }
    while ( *v5 );
    if ( v9 == -1 )
      v9 = 0;
  }
  animVehicleNameStr[v6].hash = v9;
  animVehicleTypes[v6] = vehType;
  animVehicleSeats[v6].seats = 0;
  if ( drivers > 0 )
    animVehicleSeats[v6].seats = 1;
  v11 = gunners;
  v12 = 2;
  if ( gunners > 0 )
  {
    seats = animVehicleSeats[v6].seats;
    do
    {
      seats |= v12;
      v12 = __ROL4__(v12, 1);
      --v11;
    }
    while ( v11 );
    animVehicleSeats[v6].seats = seats;
  }
  v14 = passengers;
  v15 = 32;
  if ( passengers > 0 )
  {
    v16 = animVehicleSeats[v6].seats;
    do
    {
      v16 |= v15;
      v15 = __ROL4__(v15, 1);
      --v14;
    }
    while ( v14 );
    animVehicleSeats[v6].seats = v16;
  }
  animVehicleNameStr[v6 + 1].string = 0;
  animVehicleNameStr[v6 + 1].hash = -1;
}

#endif // __UNIMPLEMENTED__
