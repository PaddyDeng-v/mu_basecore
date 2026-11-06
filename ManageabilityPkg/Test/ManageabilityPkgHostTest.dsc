## @file
# ManageabilityPkgHostTest DSC file used to build host-based unit tests.
#
# Copyright (c) Microsoft Corporation.<BR>
# SPDX-License-Identifier: BSD-2-Clause-Patent
#
##
[Defines]
  PLATFORM_NAME           = ManageabilityPkgHostTest
  PLATFORM_GUID           = 6e5c2c1c-0e0d-4f0e-9a3a-3d2f6c8b7a41
  PLATFORM_VERSION        = 0.1
  DSC_SPECIFICATION       = 0x00010005
  OUTPUT_DIRECTORY        = Build/ManageabilityPkg/HostTest
  SUPPORTED_ARCHITECTURES = IA32|X64|AARCH64
  BUILD_TARGETS           = NOOPT
  SKUID_IDENTIFIER        = DEFAULT

!include UnitTestFrameworkPkg/UnitTestFrameworkPkgHost.dsc.inc

[Packages]
  MdePkg/MdePkg.dec
  UnitTestFrameworkPkg/UnitTestFrameworkPkg.dec

[Components]
  #
  # Build HOST_APPLICATION that tests ManageabilityPkg
  #
  ManageabilityPkg/Library/IpmiPlatformInitLibNull/GoogleTest/IpmiPlatformInitLibNullGoogleTest.inf
