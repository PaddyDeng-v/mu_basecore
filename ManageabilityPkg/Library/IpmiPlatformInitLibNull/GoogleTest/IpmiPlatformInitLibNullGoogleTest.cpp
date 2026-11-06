/** @file
  Test the production constructor-free no-op initialization hook.

  Copyright (c) Microsoft Corporation. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/GoogleTestLib.h>
extern "C" {
  #include <Library/IpmiPlatformInitLib.h>
}

using namespace testing;

// The no-op API has no parameters, outputs, dependencies or mutable state.
// Its only observable result must remain success on every explicit invocation.
TEST (IpmiPlatformInitNullTest, RepeatedExplicitInvocation_ReturnsSuccess)
{
  for (UINTN Invocation = 0; Invocation < 3; Invocation++) {
    EXPECT_EQ (IpmiPlatformInitialize (), EFI_SUCCESS);
  }
}

int
main (
  int   Argc,
  char  *Argv[]
  )
{
  InitGoogleTest (&Argc, Argv);
  return RUN_ALL_TESTS ();
}
