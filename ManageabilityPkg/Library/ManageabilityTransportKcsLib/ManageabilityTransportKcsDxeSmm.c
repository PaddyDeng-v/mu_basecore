/** @file

  KCS instance of Manageability Transport Library

  Copyright (C) 2023-2026 Advanced Micro Devices, Inc. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Uefi.h>
#include <IndustryStandard/IpmiKcs.h>
#include <Library/IoLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/ManageabilityTransportLib.h>
#include <Library/ManageabilityTransportIpmiLib.h>
#include <Library/ManageabilityTransportHelperLib.h>

#include "ManageabilityTransportKcs.h"

MANAGEABILITY_TRANSPORT_KCS_HARDWARE_INFO  mKcsHardwareInfo;
MANAGEABILITY_TRANSPORT_KCS                *SingleSessionToken = NULL;

MANAGEABILITY_TRANSPORT_KCS_HARDWARE_INFO *
KcsGetHardwareInfo (
  VOID
  )
{
  return &mKcsHardwareInfo;
}

MANAGEABILITY_TRANSPORT_KCS *
KcsGetSessionToken (
  VOID
  )
{
  return SingleSessionToken;
}

EFI_STATUS
KcsSetSessionToken (
  MANAGEABILITY_TRANSPORT_KCS  *SessionToken
  )
{
  SingleSessionToken = SessionToken;
  if (SingleSessionToken != SessionToken) {
    DEBUG ((DEBUG_ERROR, "%a: Fail to write session token.\n", __func__));
    return EFI_DEVICE_ERROR;
  }

  return EFI_SUCCESS;
}
