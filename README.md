[![Build Status](https://github.com/tgalaj/strutil/actions/workflows/cpp_cmake.yml/badge.svg)](https://github.com/tgalaj/strutil/actions)
[![Coverage Status](https://coveralls.io/repos/github/tgalaj/strutil/badge.svg?branch=master)](https://coveralls.io/github/tgalaj/strutil?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## strutil
Easy to use, header only C++ 11 std::string utility library. 

Any constructive comments and improvements to this little library are very welcome.

## Features
- [x] Generic parsing methods - from std::string and to std::string.
- [x] Splitting std::string to tokens with user defined delimiter (useful for CSV parsing) or regex expression.
- [x] Joining split string that is stored in *std::vector<std::string>* with the specified delimiter.
- [x] Replace a substring with another substring.
- [x] Text manipulation functions: *capitalize*, *repeat* (char or std::string), *to_lower*, *to_upper*, *trim*, *trim_left*, *trim_right* (also in-place).
- [x] Checks: *contains*, *starts_with*, *ends_with*, *matches*.
- [x] Compare two std::string with their case ignored. 
- [x] Removing all empty strings in *std::vector<std::string>* (also in-place).
- [x] Sorting in ascending/descending order elements in *std::vector<std::string>*.
- [x] Header only library - no building required.
- [x] Does not require any dependencies.

## Documentation
Online documentation can be found [here](https://tgalaj.github.io/strutil/).

## Adding strutil to existing project
Simply put *strutil.h* in your *include* directory. Then, in C++ file include it:

```cpp
#include <strutil.h>
```

## Example usage
See **tests/test_cases.cpp** file for the example usage.

## Testing
strutil supports the Google Test library ([link](https://github.com/google/googletest)). 

To build the testing environment execute the following command in the root directory:

```
cmake -B build
```

## Contributions
All contributions are more than welcome. 

Thank you all for your contributions!
