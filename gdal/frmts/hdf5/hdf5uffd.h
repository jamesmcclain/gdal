#ifdef ENABLE_UFFD

#include "cpl_userfaultfd.h"

#ifndef HDF5_UFFD_MAP

#define HDF5_UFFD_MAP(filename, handle, context) { \
    void * pVma = nullptr; \
    uint64_t nVmaSize = 0; \
    context = nullptr; \
    if (!strncmp(filename, "/vsi", strlen("/vsi"))) \
      context = CPLCreateUserFaultMapping(filename, &pVma, &nVmaSize); \
    if (context != nullptr && pVma != nullptr && nVmaSize > 0) \
      handle = H5LTopen_file_image(pVma, nVmaSize, H5LT_FILE_IMAGE_DONT_COPY|H5LT_FILE_IMAGE_DONT_RELEASE); \
    else \
      handle = H5Fopen(filename, H5F_ACC_RDONLY, H5P_DEFAULT); \
}

#endif // HDF5_UUFD_HOOKUP

#endif // ENABLE_UFFD
