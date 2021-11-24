// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#ifdef    __UNIMPLEMENTED__

// bdreference.inl:0x532140
BOOL __cdecl PartyMigrate_MigrateActive(PartyData_s *party)
{
  return !party->partyId
      && (s_migrateClientData.clientState == MIGRATE_ACTIVE || s_migrateClientData.clientState == MIGRATE_BECOMING_HOST);
}

#endif // __UNIMPLEMENTED__
#ifdef    __UNIMPLEMENTED__

// bdreference.inl:0x532170
void __cdecl Party_SetMigrateActive(PartyData_s *party, bool state)
{
  if ( !party->partyId )
  {
    if ( state )
    {
      s_migrateClientData.migrateStartMs = Sys_Milliseconds();
      party->migrateData.startTime = Sys_Milliseconds();
      migrateClient_UpdateState(MIGRATE_ACTIVE);
    }
    else
    {
      s_migrateClientData.currentNominee = 0;
      migrateClient_UpdateState(MIGRATE_CLIENT_IDLE);
    }
  }
}

#endif // __UNIMPLEMENTED__
