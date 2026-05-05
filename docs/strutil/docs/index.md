[![Build Status](https://github.com/tgalaj/strutil/actions/workflows/cpp_cmake.yml/badge.svg)](https://github.com/tgalaj/strutil/actions)
[![Coverage Status](https://coveralls.io/repos/github/tgalaj/strutil/badge.svg?branch=master)](https://coveralls.io/github/tgalaj/strutil?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# strutil v1.1.0 - header-only string utility library documentation

A comprehensive, header-only C++17 string utility library that makes string manipulation simple and intuitive. Designed for developers who need reliable string processing without external dependencies.

We welcome any constructive feedback and contributions to help make this library even better.

## Features

strutil provides everything you need for modern C++ string processing:

- **Generic parsing** - Convert between std::string and any data type seamlessly
- **String splitting** - Break strings into tokens using delimiters, regex patterns, or multiple separators (perfect for CSV parsing)
- **String joining** - Combine vector<string> elements back together with custom delimiters
- **Text replacement** - Replace substrings with powerful first/last/all replacement options
- **Text transformation** - capitalize, repeat, to_lower, to_upper, trim operations (both in-place and copy variants)
- **String validation** - contains, starts_with, ends_with, matches, and case-insensitive comparisons
- **Vector utilities** - Remove empty strings, sort in ascending/descending order, remove duplicates
- **Optional parallel variants** - Sibling `*_par` functions for sort/dedup, opt-in via the `STRUTIL_ENABLE_PARALLEL` macro / CMake option
- **Zero dependencies** - Header-only design means no building or linking required

## Usage

Getting started is as simple as including the header:

```cpp
#include <strutil.h>
```

All functionality is available in the `strutil` namespace.

## Examples

For comprehensive usage examples and test cases, check out our [test suite](https://github.com/tgalaj/strutil/tree/master/tests).

## API Documentation

For detailed function signatures and parameters, see the [strutil namespace documentation](strutil/namespacestrutil.md). 

## Parallel variants (optional)

The default build of strutil is fully serial and does not pull in `<execution>`. For large inputs (typically >= ~10k elements) you can opt into parallel sibling functions by defining the `STRUTIL_ENABLE_PARALLEL` macro before including the header, or by passing `-DSTRUTIL_ENABLE_PARALLEL=ON` to CMake:

```
cmake -B build -DSTRUTIL_ENABLE_PARALLEL=ON
```

This enables the following functions alongside their serial counterparts:

- `strutil::drop_duplicate_par`
- `strutil::drop_duplicate_copy_par`
- `strutil::sorting_ascending_par`
- `strutil::sorting_descending_par`

They execute under `std::execution::par` policy.

## Testing

The project uses Google Test for comprehensive testing. To build and run the test suite:

```
cmake -B build
```

## Contributions

We appreciate all contributions! Whether it's bug reports, feature requests, or code improvements, your help makes strutil better for everyone.

Thank you to all our contributors!