#
# Copyright 2018, Data61
# Commonwealth Scientific and Industrial Research Organisation (CSIRO)
# ABN 41 687 119 230.
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(DATA61_BSD)
#

cmake_minimum_required(VERSION 3.8.2)

project(camkes-arm-tk1-vm C)

include(../../arm_vm_helpers.cmake)

set(KernelARMPlatform "tk1" CACHE STRING "" FORCE)
set(KernelArmSMMU ON CACHE BOOL "" FORCE)
set(KernelARMSMMUInterruptEnable ON CACHE BOOL "" FORCE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

# Create our CPP Flags based on ARM VM config variables
set(cpp_flags "-DKERNELARMPLATFORM_TK1")
AddCamkesCPPFlag(cpp_flags
    CONFIG_VARS VmEmmc2NoDMA VmVUSB VmVchan Tk1DeviceFwd Tk1Insecure)

# Declare tk1 root server
DeclareCAmkESRootserver(tk1_soi.camkes CPP_FLAGS ${cpp_flags})

# Common build definitions
CAmkESAddImportPath(components)
CAmkESAddImportPath(interfaces)

# Add VM components
add_subdirectory(components/PS)

