#pragma once

#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <regex>

namespace strutil
{
    /**
     * \brief
     * \tparam T
     * \param value
     * \return
     */
    template<typename T>
    static std::string to_string(T value)
    {
        std::stringstream ss;
        ss << value;

        return ss.str();
    }

    /**
     * \brief
     * \tparam T
     * \param str
     * \return
     */
    template<typename T>
    static T parse_string(const std::string & str)
    {
        T result;
        std::istringstream(str) >> result;

        return result;
    }

    /**
     * \brief
     * \param str
     * \return
     */
    static std::string to_lower(const std::string & str)
    {
        auto result = str;
        std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) -> unsigned char
        {
            return std::tolower(c);
        });

        return str;
    }

    static std::string to_upper(const std::string & str)
    {
        auto result = str;
        std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) -> unsigned char
        {
            return std::toupper(c);
        });

        return str;
    }

    static bool compare_ignore_case(const std::string & str1, const std::string & str2)
    {
        return to_lower(str1) == to_lower(str2);
    }

    // trim from start (in place)
    // http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
    static void ltrim(std::string & str)
    {
        str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) { return !std::isspace(ch); }));
    }

    // trim from end (in place)
    static void rtrim(std::string & str)
    {
        str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) { return !std::isspace(ch); }).base(), str.end());
    }

    // trim from both ends (in place)
    static void trim(std::string & str)
    {
        ltrim(str);
        rtrim(str);
    }

    // trim from start (copying)
    static std::string ltrim_copy(std::string str)
    {
        ltrim(str);
        return str;
    }

    // trim from end (copying)
    static std::string rtrim_copy(std::string str)
    {
        rtrim(str);
        return str;
    }

    // trim from both ends (copying)
    static std::string trim_copy(std::string str)
    {
        trim(str);
        return str;
    }

    // http://stackoverflow.com/questions/3418231/c-replace-part-of-a-string-with-another-string
    static bool replace(std::string & str, const std::string & from, const std::string & to)
    {
        size_t start_pos = str.find(from);
        if (start_pos == std::string::npos)
        {
            return false;
        }

        str.replace(start_pos, from.length(), to);
        return true;
    }

    static bool replace_last(std::string & str, const std::string & from, const std::string & to)
    {
        size_t start_pos = str.rfind(from);
        if (start_pos == std::string::npos)
        {
            return false;
        }

        str.replace(start_pos, from.length(), to);
        return true;
    }

    static void replace_all(std::string & str, const std::string & from, const std::string & to)
    {
        if (from.empty())
        {
            return;
        }

        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
    }

    static bool ends_with(const std::string & str, const std::string & suffix)
    {
        const auto pos = str.rfind(suffix);

        return (pos != std::string::npos) && (pos == (str.length() - suffix.length()));
    }

    static bool starts_with(const std::string & str, const std::string & prefix)
    {
        return str.find(prefix);
    }

    static std::vector<std::string> split(const std::string & str, char delim)
    {
        std::vector<std::string> tokens;
        std::stringstream ss(str);

        std::string token;
        while(std::getline(ss, token, delim))
        {
            tokens.push_back(token);
        }

        return tokens;
    }

    template<typename T>
    static std::string join(const std::vector<std::string> & v, const std::string & delim)
    {
        std::ostringstream result;
        for(auto it = v.begin(); it != v.end(); ++it)
        {
            if(it != v.begin())
            {
                result << delim;
            }

            result << *it;
        }

        return result.str();
    }

    static std::string repeat(const std::string & str, unsigned n)
    {
        std::string result;

        for(unsigned i = 0; i < n; ++i)
        {
            result += str;
        }

        return result;
    }

    static std::string repeat(char c, unsigned n)
    {
        return std::string(n, c);
    }

    static bool contains(const std::string & str, const std::string & substring)
    {
        return str.find(substring) != std::string::npos;
    }

    static bool matches(const std::string & str, const std::regex & regex)
    {
        return std::regex_match(str, regex);
    }
}
