# CTL - C Template Library

[![pipeline status](https://gitlab.com/callback/ctl/badges/master/pipeline.svg)](https://gitlab.com/callback/ctl/-/commits/master)
[![license](https://img.shields.io/badge/license-0BSD-blue)](LICENSE)
[![doxygen](https://img.shields.io/badge/doc-doxygen-blue)](https://callback.gitlab.io/ctl)

A `C11` library providing generic type-safe data structures compiling to actual
structures and functions.

## Table of Contents

- [Quick overview](#quick-overview)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Documentation](#documentation)
- [Versioning](#versioning)
- [Changelog](#changelog)
- [Contributing](#contributing)
- [Interesting links](#interesting-links)
- [License](#license)

## Quick overview

```c
#include <ctl/ctl.h>
#include <ctl/ctl_dyn_array.h>

#define CTL_DYN_ARRAY_TYPES_TYPES int, char
CTL_DECLARE(CTL_DYN_ARRAY, CTL_DYN_ARRAY_TYPES);
CTL_DEFINE(CTL_DYN_ARRAY, CTL_DYN_ARRAY_TYPES);

int main(int argc, char * argv[])
{
    CTL_DYN_ARRAY(int) * foo = ctl_DynArray_Create(foo);
    CTL_DYN_ARRAY(char) * bar = ctl_DynArray_Create(bar);
    ctl_DynArray_PushBack(foo, 3);
    ctl_DynArray_PushBack(foo, 7);
    ctl_DynArray_PushBack(bar, 'b');
    int a = ctl_DynArray_PopBack(foo); // a = 7
    char b = ctl_DynArray_PopBack(bar); // b = 'b'
    ctl_DynArray_Destroy(foo);
    ctl_DynArray_Destroy(bar);
    return 0;
}
```

## Getting Started

### Prerequisites

Although `ctl` is a header only library, a `C11` compliant compiler is needed to
use it in your project and to compile the tests.

### Installation

[Download](https://gitlab.com/callback/ctl/-/archive/master/ctl-master.zip) or
clone the repository:

```
git clone https://gitlab.com/callback/ctl.git
```

Optionally run the tests:

```
cd ctl
make all
make check
```

Install the headers globally to the standard default location `/usr/local/include/ctl`:

```
make install
```

Or install them to a different path `/my/custom/path/include/ctl`:

```
make install prefix=/my/custom/path
```

Add `/usr/local/include/ctl` or `/my/custom/path/include/ctl` to your include
paths.

## Documentation

Doxygen documentation is available here: <https://callback.gitlab.io/ctl>

## Versioning

This project follows [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## Changelog

See the [CHANGELOG.md](CHANGELOG.md) file.

## Contributing

See the [CONTRIBUTING.md](CONTRIBUTING.md) file.

## Interesting links

Here are a few interesting generic data structures libraries in C.

- [stb_ds.h](https://github.com/nothings/stb/blob/master/stb_ds.h): _This is a single-header-file library that provides easy-to-use
   dynamic arrays and hash tables for C (also works in C++)._
  - Part of the well known [stb library](https://github.com/nothings/stb) by Sean Barrett.
- [Klib](https://github.com/attractivechaos/klib): _A standalone and lightweight C library._
- [Collections-C](https://github.com/srdja/Collections-C): _A library of generic data structures including a list, array, hashtable, deque etc..._

## License

This project is licensed under the _very_ permissive [BSD Zero Clause License](LICENSE).

More information on the 0BSD license:

- [The 0BSD's creator website](https://landley.net/toybox/license.html)
- [BSD Zero Clause License | Software Package Data Exchange (SPDX)](https://spdx.org/licenses/0BSD.html)
- [Zero-Clause BSD (0BSD) | Open Source Initiative](https://opensource.org/licenses/0BSD)
- [BSD Zero Clause License | Choose a License](https://choosealicense.com/licenses/0bsd/)
