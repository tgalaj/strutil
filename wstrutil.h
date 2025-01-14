/**
******************************************************************************
*
*  @mainpage strutil v1.1.0 - header-only string utility library documentation
*  @see https://github.com/Shot511/strutil
*
*  @copyright  Copyright (C) 2024 Tomasz Galaj
*  @file       strutil.h
*  @brief      Library public interface header
*
*  @subsection Thank you all for your contributions!!
*
******************************************************************************
*/

#pragma once

#include <algorithm>
#include <cwctype>
#include <execution>
#include <map>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <vector>

//! The wstrutil namespace
namespace wstr
{
    /**
     * @brief Converts any datatype into std::wstring.
     *        Datatype must support << operator.
     * @tparam T
     * @param value - will be converted into std::wstring.
     * @return Converted value as std::wstring.
     */
    template<typename T>
    static inline std::wstring to_wstring(T value)
    {
        std::wstringstream ss;
        ss << value;

        return ss.str();
    }

    /**
     * @brief Converts std::wstring into any datatype.
     *        Datatype must support << operator.
     * @tparam T
     * @param str - std::wstring that will be converted into datatype T.
     * @return Variable of datatype T.
     */
    template<typename T>
    static inline T parse_wstring(const std::wstring& str)
    {
        T result;
        std::wistringstream(str) >> result;

        return result;
    }

    /**
     * @brief Converts std::wstring to lower case.
     * @param str - std::wstring that needs to be converted.
     * @return Lower case input std::wstring.
     */
    static inline std::wstring to_lower(const std::wstring& str)
    {
        auto result = str;
        std::transform(result.begin(), result.end(), result.begin(), [](wchar_t c) -> wchar_t
            {
                return static_cast<wchar_t>(std::towlower(c));
            });

        return result;
    }

    /**
     * @brief Converts std::wstring to upper case.
     * @param str - std::wstring that needs to be converted.
     * @return Upper case input std::wstring.
     */
    static inline std::wstring to_upper(const std::wstring& str)
    {
        auto result = str;
        std::transform(result.begin(), result.end(), result.begin(), [](wchar_t c) -> wchar_t
            {
                return static_cast<wchar_t>(std::towupper(c));
            });

        return result;
    }

    /**
     * @brief Converts the first wchar_tacter of a string to uppercase letter and lowercases all other wchar_tacters, if any.
     * @param str - input string to be capitalized.
     * @return A string with the first letter capitalized and all other wchar_tacters lowercased. It doesn't modify the input string.
     */
    static inline std::wstring capitalize(const std::wstring& str)
    {
        auto result = str;
        if (!result.empty())
        {
            result.front() = static_cast<wchar_t>(std::towupper(result.front()));
        }

        return result;
    }

    /**
     * @brief Converts only the first wchar_tacter of a string to uppercase letter, all other wchar_tacters stay unchanged.
     * @param str - input string to be modified.
     * @return A string with the first letter capitalized. All other wchar_tacters stay unchanged. It doesn't modify the input string.
     */
    static inline std::wstring capitalize_first_wchar_t(const std::wstring& str)
    {
        auto result = to_lower(str);
        if (!result.empty())
        {
            result.front() = static_cast<wchar_t>(std::towupper(result.front()));
        }

        return result;
    }

    /**
     * @brief Checks if input std::wstring str contains specified substring.
     * @param str - std::wstring to be checked.
     * @param substring - searched substring.
     * @return True if substring was found in str, false otherwise.
     */
    static inline bool contains(const std::wstring& str, const std::wstring& substring)
    {
        return str.find(substring) != std::wstring::npos;
    }

    /**
     * @brief Checks if input std::wstring str contains specified wchar_tacter.
     * @param str - std::wstring to be checked.
     * @param wchar_tacter - searched wchar_tacter.
     * @return True if wchar_tacter was found in str, false otherwise.
     */
    static inline bool contains(const std::wstring& str, const wchar_t wchar_tacter)
    {
        return contains(str, std::wstring(1, wchar_tacter));
    }

    /**
     * @brief Compares two std::wstrings ignoring their case (lower/upper).
     * @param str1 - std::wstring to compare
     * @param str2 - std::wstring to compare
     * @return True if str1 and str2 are equal, false otherwise.
     */
    static inline bool compare_ignore_case(const std::wstring& str1, const std::wstring& str2)
    {
        return to_lower(str1) == to_lower(str2);
    }

    /**
     * @brief Trims (in-place) white spaces from the left side of std::wstring.
     *        Taken from: http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring.
     * @param str - input std::wstring to remove white spaces from.
     */
    static inline void trim_left(std::wstring& str)
    {
        str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) { return !std::iswspace(ch); }));
    }

    /**
     * @brief Trims (in-place) white spaces from the right side of std::wstring.
     *        Taken from: http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring.
     * @param str - input std::wstring to remove white spaces from.
     */
    static inline void trim_right(std::wstring& str)
    {
        str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) { return !std::iswspace(ch); }).base(), str.end());
    }

    /**
     * @brief Trims (in-place) white spaces from the both sides of std::wstring.
     *        Taken from: http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring.
     * @param str - input std::wstring to remove white spaces from.
     */
    static inline void trim(std::wstring& str)
    {
        trim_left(str);
        trim_right(str);
    }

    /**
     * @brief Trims white spaces from the left side of std::wstring.
     *        Taken from: http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring.
     * @param str - input std::wstring to remove white spaces from.
     * @return Copy of input str with trimmed white spaces.
     */
    static inline std::wstring trim_left_copy(std::wstring str)
    {
        trim_left(str);
        return str;
    }

    /**
      * @brief Trims white spaces from the right side of std::wstring.
      *        Taken from: http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring.
      * @param str - input std::wstring to remove white spaces from.
      * @return Copy of input str with trimmed white spaces.
      */
    static inline std::wstring trim_right_copy(std::wstring str)
    {
        trim_right(str);
        return str;
    }

    /**
      * @brief Trims white spaces from the both sides of std::wstring.
      *        Taken from: http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring.
      * @param str - input std::wstring to remove white spaces from.
      * @return Copy of input str with trimmed white spaces.
      */
    static inline std::wstring trim_copy(std::wstring str)
    {
        trim(str);
        return str;
    }

    /**
     * @brief Replaces (in-place) the first occurrence of target with replacement.
     *        Taken from: http://stackoverflow.com/questions/3418231/c-replace-part-of-a-string-with-another-string.
     * @param str - input std::wstring that will be modified.
     * @param target - substring that will be replaced with replacement.
     * @param replacement - substring that will replace target.
     * @return True if replacement was successfull, false otherwise.
     */
    static inline bool replace_first(std::wstring& str, const std::wstring& target, const std::wstring& replacement)
    {
        const size_t start_pos = str.find(target);
        if (start_pos == std::wstring::npos)
        {
            return false;
        }

        str.replace(start_pos, target.length(), replacement);
        return true;
    }

    /**
     * @brief Replaces (in-place) last occurrence of target with replacement.
     *        Taken from: http://stackoverflow.com/questions/3418231/c-replace-part-of-a-string-with-another-string.
     * @param str - input std::wstring that will be modified.
     * @param target - substring that will be replaced with replacement.
     * @param replacement - substring that will replace target.
     * @return True if replacement was successfull, false otherwise.
     */
    static inline bool replace_last(std::wstring& str, const std::wstring& target, const std::wstring& replacement)
    {
        size_t start_pos = str.rfind(target);
        if (start_pos == std::wstring::npos)
        {
            return false;
        }

        str.replace(start_pos, target.length(), replacement);
        return true;
    }

    /**
     * @brief Replaces (in-place) all occurrences of target with replacement.
     *        Taken from: http://stackoverflow.com/questions/3418231/c-replace-part-of-a-string-with-another-string.
     * @param str - input std::wstring that will be modified.
     * @param target - substring that will be replaced with replacement.
     * @param replacement - substring that will replace target.
     * @return True if replacement was successfull, false otherwise.
     */
    static inline bool replace_all(std::wstring& str, const std::wstring& target, const std::wstring& replacement)
    {
        if (target.empty())
        {
            return false;
        }

        size_t start_pos = 0;
        const bool found_substring = str.find(target, start_pos) != std::wstring::npos;

        while ((start_pos = str.find(target, start_pos)) != std::wstring::npos)
        {
            str.replace(start_pos, target.length(), replacement);
            start_pos += replacement.length();
        }

        return found_substring;
    }

    /**
     * @brief Checks if std::wstring str ends with specified suffix.
     * @param str - input std::wstring that will be checked.
     * @param suffix - searched suffix in str.
     * @return True if suffix was found, false otherwise.
     */
    static inline bool ends_with(const std::wstring& str, const std::wstring& suffix)
    {
        const auto suffix_start = str.size() - suffix.size();
        const auto result = str.find(suffix, suffix_start);
        return (result == suffix_start) && (result != std::wstring::npos);
    }

    /**
     * @brief Checks if std::wstring str ends with specified wchar_tacter.
     * @param str - input std::wstring that will be checked.
     * @param suffix - searched wchar_tacter in str.
     * @return True if ends with wchar_tacter, false otherwise.
     */
    static inline bool ends_with(const std::wstring& str, const wchar_t suffix)
    {
        return !str.empty() && (str.back() == suffix);
    }

    /**
     * @brief Checks if std::wstring str starts with specified prefix.
     * @param str - input std::wstring that will be checked.
     * @param prefix - searched prefix in str.
     * @return True if prefix was found, false otherwise.
     */
    static inline bool starts_with(const std::wstring& str, const std::wstring& prefix)
    {
        return str.rfind(prefix, 0) == 0;
    }

    /**
     * @brief Checks if std::wstring str starts with specified wchar_tacter.
     * @param str - input std::wstring that will be checked.
     * @param prefix - searched wchar_tacter in str.
     * @return True if starts with wchar_tacter, false otherwise.
     */
    static inline bool starts_with(const std::wstring& str, const wchar_t prefix)
    {
        return !str.empty() && (str.front() == prefix);
    }

    /**
     * @brief Splits input std::wstring str according to input delim.
     * @param str - std::wstring that will be splitted.
     * @param delim - the delimiter.
     * @return std::vector<std::wstring> that contains all splitted tokens.
     */
    static inline std::vector<std::wstring> split(const std::wstring& str, const wchar_t delim)
    {
        std::vector<std::wstring> tokens;
        std::wstringstream ss(str);

        std::wstring token;
        while (std::getline(ss, token, delim))
        {
            tokens.push_back(token);
        }

        // Match semantics of split(str,str)
        if (str.empty() || ends_with(str, delim)) {
            tokens.emplace_back();
        }

        return tokens;
    }

    /**
     * @brief Splits input std::wstring str according to input std::wstring delim.
     *        Taken from: https://stackoverflow.com/a/46931770/1892346.
     * @param str - std::wstring that will be split.
     * @param delim - the delimiter.
     * @return std::vector<std::wstring> that contains all splitted tokens.
     */
    static inline std::vector<std::wstring> split(const std::wstring& str, const std::wstring& delim)
    {
        size_t pos_start = 0, pos_end, delim_len = delim.length();
        std::wstring token;
        std::vector<std::wstring> tokens;

        while ((pos_end = str.find(delim, pos_start)) != std::wstring::npos)
        {
            token = str.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            tokens.push_back(token);
        }

        tokens.push_back(str.substr(pos_start));
        return tokens;
    }

    /**
     * @brief Splits input string using regex as a delimiter.
     * @param src - std::wstring that will be split.
     * @param rgx_str - the set of delimiter wchar_tacters.
     * @return vector of resulting tokens.
     */
    static inline std::vector<std::wstring> regex_split(const std::wstring& src, const std::wstring& rgx_str)
    {
        std::vector<std::wstring> elems;
        const std::wregex rgx(rgx_str);
        std::wsregex_token_iterator iter(src.begin(), src.end(), rgx, -1);
        std::wsregex_token_iterator end;
        while (iter != end)
        {
            elems.push_back(*iter);
            ++iter;
        }
        return elems;
    }

    /**
     * @brief Splits input string using regex as a delimiter.
     * @param src - std::wstring that will be split.
     * @param dest - map of matched delimiter and those being splitted.
     * @param rgx_str - the set of delimiter wchar_tacters.
     * @return True if the parsing is successfully done.
     */
    static inline std::map<std::wstring, std::wstring> regex_split_map(const std::wstring& src, const std::wstring& rgx_str)
    {
        std::map<std::wstring, std::wstring> dest;
        std::wstring tstr = src + L" ";
        std::wregex rgx(rgx_str);
        std::wsregex_token_iterator niter(tstr.begin(), tstr.end(), rgx);
        std::wsregex_token_iterator viter(tstr.begin(), tstr.end(), rgx, -1);
        std::wsregex_token_iterator end;
        ++viter;
        while (niter != end)
        {
            dest[*niter] = *viter;
            ++niter;
            ++viter;
        }

        return dest;
    }

    /**
     * @brief Splits input string using any delimiter in the given set.
     * @param str - std::wstring that will be split.
     * @param delims - the set of delimiter wchar_tacters.
     * @return vector of resulting tokens.
     */
    static inline std::vector<std::wstring> split_any(const std::wstring& str, const std::wstring& delims)
    {
        std::wstring token;
        std::vector<std::wstring> tokens;

        size_t pos_start = 0;
        for (size_t pos_end = 0; pos_end < str.length(); ++pos_end)
        {
            if (contains(delims, str[pos_end]))
            {
                token = str.substr(pos_start, pos_end - pos_start);
                tokens.push_back(token);
                pos_start = pos_end + 1;
            }
        }

        tokens.push_back(str.substr(pos_start));
        return tokens;
    }

    /**
     * @brief Joins all elements of a container of arbitrary datatypes
     *        into one std::wstring with delimiter delim.
     * @tparam Container - container type.
     * @param tokens - container of tokens.
     * @param delim - the delimiter.
     * @return std::wstring with joined elements of container tokens with delimiter delim.
     */
    template<typename Container>
    static inline std::wstring join(const Container& tokens, const std::wstring& delim)
    {
        std::wostringstream result;
        for (auto it = tokens.begin(); it != tokens.end(); ++it)
        {
            if (it != tokens.begin())
            {
                result << delim;
            }

            result << *it;
        }

        return result.str();
    }

    /**
     * @brief Inplace removal of all empty strings in a container of strings
     * @tparam Container - container type.
     * @param tokens - container of strings.
     */
    template<template<typename, typename...> typename Container, typename... Args>
    static inline void drop_empty(Container<std::wstring, Args...>& tokens)
    {
        auto last = std::erase_if(tokens, [](auto& s) { return s.empty(); });
    }

    /**
     * @brief Inplace removal of all empty strings in a container of strings
     * @tparam container - container type.
     * @param tokens - container of strings.
     * @return container of non-empty tokens.
     */
    template<template<typename, typename...> typename Container, typename... Args>
    static inline Container<std::wstring> drop_empty_copy(Container<std::wstring, Args...> tokens)
    {
        drop_empty(tokens);
        return tokens;
    }

    /**
     * @brief Inplace removal of all duplicate strings in a vector<string> where order is not to be maintained
     *        Taken from: C++ Primer V5
     * @tparam T - arbitrary datatype.
     * @param tokens - vector of strings.
     * @return vector of non-duplicate tokens.
     */
    template<typename T>
    static inline void drop_duplicate(std::vector<T>& tokens)
    {
        std::sort(std::execution::par_unseq, tokens.begin(), tokens.end());
        auto end_unique = std::unique(tokens.begin(), tokens.end());
        tokens.erase(end_unique, tokens.end());
    }

    /**
     * @brief Removal of all duplicate strings in a vector<string> where order is not to be maintained
     *        Taken from: C++ Primer V5
     * @tparam T - arbitrary datatype.
     * @param tokens - vector of strings.
     * @return vector of non-duplicate tokens.
     */
    template<typename T>
    static inline std::vector<T> drop_duplicate_copy(std::vector<T> tokens)
    {
        std::sort(std::execution::par_unseq, tokens.begin(), tokens.end());
        auto end_unique = std::unique(tokens.begin(), tokens.end());
        tokens.erase(end_unique, tokens.end());
        return tokens;
    }

    /**
     * @brief Creates new std::wstring with repeated n times substring str.
     * @param str - substring that needs to be repeated.
     * @param n - number of iterations.
     * @return std::wstring with repeated substring str.
     */
    static inline std::wstring repeat(const std::wstring& str, unsigned n)
    {
        std::wstring result;

        for (unsigned i = 0; i < n; ++i)
        {
            result += str;
        }

        return result;
    }

    /**
     * @brief Creates new std::wstring with repeated n times wchar_t c.
     * @param c - wchar_t that needs to be repeated.
     * @param n - number of iterations.
     * @return std::wstring with repeated wchar_t c.
     */
    static inline std::wstring repeat(wchar_t c, unsigned n)
    {
        return std::wstring(n, c);
    }

    /**
     * @brief Checks if input std::wstring str matches specified reular expression regex.
     * @param str - std::wstring to be checked.
     * @param regex - the std::wregex regular expression.
     * @return True if regex matches str, false otherwise.
     */
    static inline bool matches(const std::wstring& str, const std::wregex& regex)
    {
        return std::regex_match(str, regex);
    }

    /**
     * @brief Sort input std::vector<std::wstring> strs in ascending order.
     * @param strs - std::vector<std::wstring> to be checked.
     */
    template<typename T>
    static inline void sorting_ascending(std::vector<T>& strs)
    {
        std::sort(std::execution::par_unseq, strs.begin(), strs.end());
    }

    /**
     * @brief Sorted input std::vector<std::wstring> strs in descending order.
     * @param strs - std::vector<std::wstring> to be checked.
     */
    template<typename T>
    static inline void sorting_descending(std::vector<T>& strs)
    {
        std::sort(std::execution::par_unseq, strs.begin(), strs.end(), std::greater<T>());
    }

    /**
     * @brief Reverse input container strs.
     * @param strs - container to be checked.
     */
    template<typename Container>
    static inline void reverse_inplace(Container& strs)
    {
        std::reverse(strs.begin(), strs.end());
    }

    /**
     * @brief Reverse input container strs.
     * @param strs - container to be checked.
     */
    template<typename Container>
    static inline Container reverse_copy(Container strs)
    {
        std::reverse(strs.begin(), strs.end());
        return strs;
    }
}
