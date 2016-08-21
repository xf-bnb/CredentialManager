#include "bnb_global.h"
#include "RC4.h"

_bnb_space_begin_

/*
const byte_t _just_my_favourite[] = {
    0x54, 0x69, 0x61, 0x6f, 0x74, 0x69, 0x61, 0x6f, 0x71, 0x69, 0x61, 0x6e, 0x6e, 0x69, 0x75, 0x78, 0x69, 0x6e, 0x67,
    0x4a, 0x69, 0x61, 0x6f, 0x6a, 0x69, 0x61, 0x6f, 0x68, 0x65, 0x68, 0x61, 0x6e, 0x6e, 0x76,
    0x58, 0x69, 0x61, 0x6e, 0x78, 0x69, 0x61, 0x6e, 0x7a, 0x68, 0x75, 0x6f, 0x73, 0x75, 0x73, 0x68, 0x6f, 0x75,
    0x5a, 0x68, 0x61, 0x7a, 0x68, 0x61, 0x6e, 0x6f, 0x6e, 0x67, 0x6a, 0x69, 0x7a, 0x68, 0x75,
    0x5a, 0x68, 0x6f, 0x6e, 0x67, 0x72, 0x69, 0x62, 0x75, 0x63, 0x68, 0x65, 0x6e, 0x67, 0x7a, 0x68, 0x61, 0x6e, 0x67,
    0x51, 0x69, 0x74, 0x69, 0x6c, 0x69, 0x6e, 0x67, 0x72, 0x75, 0x79, 0x75,
    0x48, 0x65, 0x68, 0x61, 0x6e, 0x71, 0x69, 0x6e, 0x67, 0x71, 0x69, 0x65, 0x71, 0x69, 0x61, 0x6e,
    0x58, 0x69, 0x61, 0x6e, 0x67, 0x71, 0x75, 0x66, 0x75, 0x6a, 0x69, 0x78, 0x75,
    0x59, 0x69, 0x6e, 0x67, 0x79, 0x69, 0x6e, 0x67, 0x79, 0x69, 0x73, 0x68, 0x75, 0x69, 0x6a, 0x69, 0x61, 0x6e,
    0x4d, 0x6f, 0x6d, 0x6f, 0x62, 0x75, 0x64, 0x65, 0x79, 0x75
};
*/

size_t RC4Encoding(byte_t* dst, const byte_t* src, size_t nsrc, const byte_t* key, size_t nkey)
{
    if (dst && src && 0 < nsrc)
    {
        byte_t _sbox[] = {
            0xd1, 0x45, 0xef, 0x06, 0x0d, 0xa9, 0x50, 0xe9, 0x81, 0x57, 0x32, 0x8c, 0x09, 0x8a, 0xf7, 0xe0,
            0xc0, 0x20, 0xd8, 0x47, 0xbb, 0x03, 0x37, 0xee, 0xe4, 0xeb, 0x49, 0x00, 0xf2, 0x52, 0x0e, 0xb2,
            0x76, 0xb8, 0x72, 0x96, 0xd2, 0xce, 0xc1, 0x92, 0x33, 0x88, 0xf5, 0x1e, 0x74, 0xc8, 0x97, 0xe2,
            0xe1, 0x8b, 0x00, 0x34, 0xdb, 0xdc, 0x3b, 0x08, 0xc4, 0x1b, 0x9f, 0xb5, 0x41, 0x5b, 0xb0, 0xd6,
            0xa6, 0x82, 0x5e, 0x1a, 0x25, 0x7c, 0xb4, 0xcd, 0x8d, 0x58, 0x46, 0x1d, 0x48, 0x99, 0xf4, 0xdf,
            0x4f, 0xa5, 0x12, 0xc7, 0x55, 0x5c, 0x86, 0x78, 0xad, 0xb6, 0x7e, 0xa1, 0xbe, 0x3d, 0x0b, 0xca,
            0x4a, 0xb1, 0x16, 0xfb, 0xbc, 0x9b, 0x2a, 0x9c, 0xd9, 0xd7, 0xe3, 0xf6, 0x26, 0x2f, 0x7f, 0x21,
            0x38, 0x35, 0xfc, 0x8f, 0xfe, 0xe8, 0x5d, 0x6d, 0x01, 0x15, 0xc6, 0x2c, 0xbf, 0x05, 0xd0, 0x7a,
            0xc2, 0xf8, 0x18, 0xdd, 0x68, 0x79, 0x83, 0x98, 0x89, 0xa3, 0x02, 0xed, 0x94, 0x3c, 0x30, 0x5f,
            0xbd, 0xd4, 0xe7, 0x63, 0x07, 0xf0, 0x1c, 0xfa, 0x28, 0x60, 0x24, 0xac, 0x11, 0x85, 0x3a, 0x1f,
            0xda, 0x54, 0x71, 0x6a, 0x2d, 0x43, 0x4c, 0x6c, 0x22, 0x51, 0x9e, 0xcf, 0xaf, 0xc9, 0x2b, 0x7b,
            0x40, 0x53, 0xae, 0x44, 0x10, 0x4d, 0x2e, 0x0a, 0xa2, 0x42, 0xa7, 0xd3, 0x0f, 0x6e, 0x75, 0xb7,
            0x27, 0xf3, 0x8e, 0x39, 0xb3, 0xd5, 0x61, 0x62, 0xa8, 0x9d, 0x29, 0xb9, 0x23, 0xcc, 0x56, 0x95,
            0x6b, 0x14, 0x4e, 0x67, 0xf9, 0x80, 0x87, 0xc5, 0x5a, 0x73, 0x3e, 0x7d, 0x59, 0xec, 0x65, 0xde,
            0xe5, 0x64, 0xa0, 0xea, 0x31, 0x66, 0x69, 0x17, 0xff, 0xab, 0x0c, 0xf1, 0x3f, 0x93, 0xc3, 0x90,
            0x36, 0x4b, 0xa4, 0xaa, 0x13, 0xcb, 0x91, 0x77, 0x19, 0xba, 0x04, 0x6f, 0x70, 0x84, 0x9a, 0xe6,
        };

        if (key && 0 < nkey)
        {
            for (size_t i = 0, k = 0; i < 0x0100; ++i)
            {
                k = ((k + _sbox[i] + key[i % nkey]) & 0xff);
                _sbox[i] ^= _sbox[k] ^= _sbox[i] ^= _sbox[k];
            }
        }

        for (size_t i = 0, x = 0, y = 0; i < nsrc; ++i)
        {
            x = ((x + 1) & 0xff);
            y = ((y + _sbox[x]) & 0xff);
            _sbox[x] ^= _sbox[y] ^= _sbox[x] ^= _sbox[y];
            dst[i] = (src[i] ^ _sbox[(_sbox[x] + _sbox[y]) & 0xff]);
        }

        return nsrc;

    }

    return 0;
}

_bnb_space_end_
