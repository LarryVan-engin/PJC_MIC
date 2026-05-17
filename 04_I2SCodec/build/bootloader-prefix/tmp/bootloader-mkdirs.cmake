# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/trieunguyen/esp-idf/components/bootloader/subproject"
  "/mnt/c/embedded/FOX M4/PJC_MIC/04_I2SCodec/build/bootloader"
  "/mnt/c/embedded/FOX M4/PJC_MIC/04_I2SCodec/build/bootloader-prefix"
  "/mnt/c/embedded/FOX M4/PJC_MIC/04_I2SCodec/build/bootloader-prefix/tmp"
  "/mnt/c/embedded/FOX M4/PJC_MIC/04_I2SCodec/build/bootloader-prefix/src/bootloader-stamp"
  "/mnt/c/embedded/FOX M4/PJC_MIC/04_I2SCodec/build/bootloader-prefix/src"
  "/mnt/c/embedded/FOX M4/PJC_MIC/04_I2SCodec/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/c/embedded/FOX M4/PJC_MIC/04_I2SCodec/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/c/embedded/FOX M4/PJC_MIC/04_I2SCodec/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
