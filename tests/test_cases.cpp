/**
 * Copyright (C) 2026 Tomasz Galaj
 */

#include <gtest/gtest.h>
#include "strutil.h"

/*
* Comparison tests
*/

TEST(Compare, compare_ignore_case)
{
    std::string str1 = "PoKeMoN!";
    std::string str2 = "pokemon!";
    std::string str3 = "POKEMON";

    EXPECT_EQ(true, strutil::compare_ignore_case(str1, str2));
    EXPECT_EQ(false, strutil::compare_ignore_case(str1, str3));
    EXPECT_EQ(false, strutil::compare_ignore_case(str2, str3));

    // Same length, same case-folded prefix, but a single differing letter:
    // ensures the function actually compares character-by-character and is not
    // accidentally equivalent to a length or prefix check.
    EXPECT_EQ(false, strutil::compare_ignore_case("abc", "abd"));
    EXPECT_EQ(false, strutil::compare_ignore_case("ABC", "abd"));

    // Empty strings should compare equal.
    EXPECT_EQ(true, strutil::compare_ignore_case("", ""));
}

TEST(Compare, starts_with_str)
{
    EXPECT_EQ(true, strutil::starts_with("m_DiffuseTexture", "m_"));
    EXPECT_EQ(true, strutil::starts_with("This is a simple test case", "This "));
    EXPECT_EQ(true, strutil::starts_with("This is a simple test case", "This is a simple test case"));
    EXPECT_EQ(true, strutil::starts_with("", ""));

    EXPECT_EQ(false, strutil::starts_with("p_DiffuseTexture", "m_"));
    EXPECT_EQ(false, strutil::starts_with("This is a simple test case", "his "));
    EXPECT_EQ(false, strutil::starts_with("abc", "abc_"));
    EXPECT_EQ(false, strutil::starts_with("abc", "_abc"));

    EXPECT_EQ(false, strutil::starts_with("", "m_"));
}

TEST(Compare, starts_with_char)
{
    EXPECT_EQ(true, strutil::starts_with("m_DiffuseTexture", 'm'));
    EXPECT_EQ(true, strutil::starts_with("This is a simple test case", 'T'));

    EXPECT_EQ(false, strutil::starts_with("p_DiffuseTexture", 'm'));
    EXPECT_EQ(false, strutil::starts_with("This is a simple test case", 'h'));

    EXPECT_EQ(false, strutil::starts_with("", 'm'));
}

TEST(Compare, ends_with_str)
{
    EXPECT_EQ(true, strutil::ends_with("DiffuseTexture_m", "_m"));
    EXPECT_EQ(true, strutil::ends_with("This is a simple test case", " test case"));
    EXPECT_EQ(true, strutil::ends_with("This is a simple test case", "This is a simple test case"));
    EXPECT_EQ(true, strutil::ends_with("", ""));

    EXPECT_EQ(false, strutil::ends_with("DiffuseTexture_p", "_m"));
    EXPECT_EQ(false, strutil::ends_with("This is a simple test case", "test cas"));
    EXPECT_EQ(false, strutil::ends_with("abc", "_abc"));
    EXPECT_EQ(false, strutil::ends_with("abc", "abc_"));

    EXPECT_EQ(false, strutil::ends_with("", "_m"));
}

TEST(Compare, ends_with_char)
{
    EXPECT_EQ(true, strutil::ends_with("DiffuseTexture_m", 'm'));
    EXPECT_EQ(true, strutil::ends_with("This is a simple test case", 'e'));

    EXPECT_EQ(false, strutil::ends_with("DiffuseTexture_p", 'm'));
    EXPECT_EQ(false, strutil::ends_with("This is a simple test case", 's'));

    EXPECT_EQ(false, strutil::ends_with("", 'm'));
}

TEST(Compare, contains_str)
{
    EXPECT_EQ(true, strutil::contains("DiffuseTexture_m", "fuse"));
    EXPECT_EQ(true, strutil::contains("", ""));
    EXPECT_EQ(false, strutil::contains("DiffuseTexture_m", "fuser"));
    EXPECT_EQ(false, strutil::contains("abc", "abc_"));
    EXPECT_EQ(false, strutil::contains("", "abc"));
}

TEST(Compare, contains_char)
{
    EXPECT_EQ(true, strutil::contains("DiffuseTexture_m", 'f'));
    EXPECT_EQ(false, strutil::contains("DiffuseTexture_m", 'z'));
    EXPECT_EQ(false, strutil::contains("", 'z'));
}

TEST(Compare, matches)
{
    const std::regex check_mail("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");

    EXPECT_EQ(true, strutil::matches("jon.doe@somehost.com", check_mail));
    EXPECT_EQ(false, strutil::matches("jon.doe@", check_mail));

    // matches() requires the *entire* string to match (regex_match semantics),
    // not just a substring. Verify that explicitly.
    const std::regex digits("[0-9]+");
    EXPECT_EQ(true,  strutil::matches("12345", digits));
    EXPECT_EQ(false, strutil::matches("abc12345", digits));
    EXPECT_EQ(false, strutil::matches("12345abc", digits));

    // Empty string against a pattern that does not allow empty.
    EXPECT_EQ(false, strutil::matches("", digits));

    // Empty string against a pattern that does allow empty.
    const std::regex maybe_digits("[0-9]*");
    EXPECT_EQ(true, strutil::matches("", maybe_digits));
}

/*
 * Parsing tests
 */

TEST(Parsing, short_int_to_string)
{
    EXPECT_EQ("-255", strutil::to_string<short int>(-255));
}

TEST(Parsing, u_short_int_to_string)
{
    EXPECT_EQ("255", strutil::to_string<unsigned short int>(255));
}

TEST(Parsing, int_to_string)
{
    EXPECT_EQ("-255", strutil::to_string<int>(-255));
}

TEST(Parsing, u_int_to_string)
{
    EXPECT_EQ("255", strutil::to_string<unsigned int>(255));
}

TEST(Parsing, long_int_to_string)
{
    EXPECT_EQ("-255", strutil::to_string<long int>(-255));
}

TEST(Parsing, u_long_int_to_string)
{
    EXPECT_EQ("255", strutil::to_string<unsigned long int>(255));
}

TEST(Parsing, long_long_int_to_string)
{
    EXPECT_EQ("-255", strutil::to_string<long long int>(-255));
}

TEST(Parsing, u_long_long_int_to_string)
{
    EXPECT_EQ("255", strutil::to_string<unsigned long long int>(255));
}

TEST(Parsing, char_to_string)
{
    EXPECT_EQ("d", strutil::to_string<char>('d'));
}

TEST(Parsing, u_char_to_string)
{
    EXPECT_EQ("d", strutil::to_string<unsigned char>('d'));
}

TEST(Parsing, float_to_string)
{
    EXPECT_EQ("5.245", strutil::to_string<float>(5.245f));
}

TEST(Parsing, double_to_string)
{
    EXPECT_EQ("5.245", strutil::to_string<double>(5.245));
}

TEST(Parsing, long_double_to_string)
{
    EXPECT_EQ("-5.245", strutil::to_string<long double>(-5.245));
}

TEST(Parsing, bool_to_string)
{
    EXPECT_EQ("1", strutil::to_string<bool>(true));
}

TEST(Parsing, neg_bool_to_string)
{
    EXPECT_EQ("0", strutil::to_string<bool>(false));
}

TEST(Parsing, string_to_short_int)
{
    EXPECT_EQ(-255, strutil::parse_string<short int>("-255"));
}

TEST(Parsing, string_to_u_short_int)
{
    EXPECT_EQ(255, strutil::parse_string<unsigned short int>("255"));
}

TEST(Parsing, string_to_int)
{
    EXPECT_EQ(-255, strutil::parse_string<int>("-255"));
}

TEST(Parsing, string_to_u_int)
{
    EXPECT_EQ(255, strutil::parse_string<unsigned int>("255"));
}

TEST(Parsing, string_to_long_int)
{
    EXPECT_EQ(-255, strutil::parse_string<long int>("-255"));
}

TEST(Parsing, string_to_u_long_int)
{
    EXPECT_EQ(255, strutil::parse_string<unsigned long int>("255"));
}

TEST(Parsing, string_to_long_long_int)
{
    EXPECT_EQ(-255, strutil::parse_string<long long int>("-255"));
}

TEST(Parsing, string_to_u_long_long_int)
{
    EXPECT_EQ(255, strutil::parse_string<unsigned long long int>("255"));
}

TEST(Parsing, string_to_char)
{
    EXPECT_EQ('d', strutil::parse_string<char>("d"));
}

TEST(Parsing, string_to_u_char)
{
    EXPECT_EQ('d', strutil::parse_string<unsigned char>("d"));
}

TEST(Parsing, string_to_float)
{
    EXPECT_FLOAT_EQ(5.245f, strutil::parse_string<float>("5.245"));
    EXPECT_FLOAT_EQ(-0.5f, strutil::parse_string<float>("-0.5"));
    // Trailing non-numeric characters are parsed up to the first invalid
    // character — consistent across libstdc++ and libc++ thanks to strtof.
    EXPECT_FLOAT_EQ(5.245f, strutil::parse_string<float>("5.245f"));
}

TEST(Parsing, string_to_double)
{
    EXPECT_DOUBLE_EQ(5.245, strutil::parse_string<double>("5.245"));
    EXPECT_DOUBLE_EQ(5.245, strutil::parse_string<double>("5.245xyz"));
}

TEST(Parsing, string_to_long_double)
{
    EXPECT_NEAR(-5.245L, strutil::parse_string<long double>("-5.245"), 1e-12L);
    EXPECT_NEAR(-5.245L, strutil::parse_string<long double>("-5.245L"), 1e-12L);
}

TEST(Parsing, string_to_bool)
{
    EXPECT_EQ(true, strutil::parse_string<bool>("1"));
}

TEST(Parsing, string_to_neg_bool)
{
    EXPECT_EQ(false, strutil::parse_string<bool>("0"));
}

namespace
{
    struct Point2D
    {
        int x = 0;
        int y = 0;

        friend std::ostream & operator<<(std::ostream & os, const Point2D & p)
        {
            return os << p.x << ',' << p.y;
        }

        friend std::istream & operator>>(std::istream & is, Point2D & p)
        {
            char comma = 0;
            is >> p.x >> comma >> p.y;
            return is;
        }

        bool operator==(const Point2D & other) const
        {
            return x == other.x && y == other.y;
        }
    };
}

TEST(Parsing, custom_type_to_string)
{
    EXPECT_EQ("3,4", strutil::to_string<Point2D>({ 3, 4 }));
}

TEST(Parsing, string_to_custom_type)
{
    const auto p = strutil::parse_string<Point2D>("3,4");
    EXPECT_EQ((Point2D{ 3, 4 }), p);
}

/*
* try_parse_string — explicit success/failure reporting via std::optional.
* The key difference from parse_string is that "0", "0.0", and false-like
* inputs can be distinguished from genuine parse failures.
*/

TEST(TryParsing, valid_int_returns_value)
{
    const auto v = strutil::try_parse_string<int>("42");
    ASSERT_TRUE(v.has_value());
    EXPECT_EQ(42, *v);
}

TEST(TryParsing, invalid_int_returns_nullopt)
{
    EXPECT_FALSE(strutil::try_parse_string<int>("abc").has_value());
    EXPECT_FALSE(strutil::try_parse_string<int>("").has_value());
}

TEST(TryParsing, distinguishes_zero_from_failure)
{
    // The whole point of try_parse_string: "0" is a valid parse, "abc" is not,
    // but parse_string returns 0 for both.
    const auto zero = strutil::try_parse_string<int>("0");
    const auto bad  = strutil::try_parse_string<int>("abc");
    ASSERT_TRUE(zero.has_value());
    EXPECT_EQ(0, *zero);
    EXPECT_FALSE(bad.has_value());
}

TEST(TryParsing, valid_float_returns_value)
{
    const auto v = strutil::try_parse_string<float>("5.245");
    ASSERT_TRUE(v.has_value());
    EXPECT_FLOAT_EQ(5.245f, *v);
}

TEST(TryParsing, float_with_trailing_junk_returns_value)
{
    // strtof-backed specialization: trailing non-numeric chars are ignored
    // as long as a numeric prefix was successfully parsed.
    const auto v = strutil::try_parse_string<float>("5.245f");
    ASSERT_TRUE(v.has_value());
    EXPECT_FLOAT_EQ(5.245f, *v);
}

TEST(TryParsing, invalid_float_returns_nullopt)
{
    EXPECT_FALSE(strutil::try_parse_string<float>("abc").has_value());
    EXPECT_FALSE(strutil::try_parse_string<float>("").has_value());
}

TEST(TryParsing, distinguishes_false_from_failure)
{
    // parse_string<bool>("hello") silently returns false — try_parse_string
    // surfaces the failure.
    const auto good = strutil::try_parse_string<bool>("0");
    const auto bad  = strutil::try_parse_string<bool>("hello");
    ASSERT_TRUE(good.has_value());
    EXPECT_FALSE(*good);
    EXPECT_FALSE(bad.has_value());
}

TEST(TryParsing, value_or_provides_default)
{
    EXPECT_EQ(8080, strutil::try_parse_string<int>("not_a_port").value_or(8080));
    EXPECT_EQ(1234, strutil::try_parse_string<int>("1234").value_or(8080));
}

TEST(TryParsing, custom_type_via_primary_template)
{
    // The float/double/long-double overloads use the strtof-based
    // specialization; everything else (including user-defined types like
    // Point2D, defined above) falls through to the primary template's
    // istringstream-based path. Exercise that path explicitly.
    const auto good = strutil::try_parse_string<Point2D>("3,4");
    ASSERT_TRUE(good.has_value());
    EXPECT_EQ((Point2D{ 3, 4 }), *good);

    // Garbage input that cannot satisfy "<int>,<int>" => failure surfaces
    // through the stream's failbit, not as a default-constructed Point2D.
    const auto bad = strutil::try_parse_string<Point2D>("not a point");
    EXPECT_FALSE(bad.has_value());
}

/*
* Splitting and tokenizing
*/

TEST(Splitting, split_char_delim)
{
    std::string str1 = "asdf;asdfgh;asdfghjk";
    std::vector<std::string> res = strutil::split(str1, ';');
    std::vector<std::string> expected = { "asdf", "asdfgh", "asdfghjk" };
    ASSERT_EQ(res.size(), expected.size()) << "Vectors are of unequal length";
    for (unsigned i = 0; i < res.size(); ++i)
    {
        EXPECT_EQ(expected[i], res[i]) << "Vectors differ at index " << i;
    }

    // Empty input => empty string
    res = strutil::split("", ';');
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0], "");

    // No matches => original string
    res = strutil::split(str1, ',');
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0], str1);

    // Leading delimiter => leading empty string
    res = strutil::split(";abc", ';');
    ASSERT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], "");
    EXPECT_EQ(res[1], "abc");

    // Trailing delimiter => trailing empty string
    res = strutil::split("abc;", ';');
    ASSERT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], "abc");
    EXPECT_EQ(res[1], "");

    // Repeated delimiters => repeated empty strings
    res = strutil::split("abc;;;def", ';');
    expected = { "abc", "", "", "def" };
    ASSERT_EQ(res.size(), expected.size());
    for (unsigned i = 0; i < res.size(); ++i)
    {
        EXPECT_EQ(expected[i], res[i]);
    }

    // keep_empty = false => empty tokens are dropped.
    res = strutil::split(";abc;;def;", ';', false);
    expected = { "abc", "def" };
    EXPECT_EQ(res, expected);

    // keep_empty = false on empty input => empty result.
    res = strutil::split("", ';', false);
    EXPECT_TRUE(res.empty());

    // keep_empty = false on a string of only delimiters => empty result.
    res = strutil::split(";;;", ';', false);
    EXPECT_TRUE(res.empty());
}

TEST(Splitting, split_string_delim)
{
    std::string str1 = "asdf>=asdfgh>=asdfghjk";
    std::vector<std::string> res = strutil::split(str1, ">=");
    std::vector<std::string> expected = { "asdf", "asdfgh", "asdfghjk" };
    ASSERT_EQ(res.size(), expected.size()) << "Vectors are of unequal length";
    for (unsigned i = 0; i < res.size(); ++i)
    {
        EXPECT_EQ(expected[i], res[i]) << "Vectors differ at index " << i;
    }

    // Empty input => empty string
    res = strutil::split("", ">=");
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0], "");

    // No matches => original string
    res = strutil::split(str1, "<>");
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0], str1);

    // Leading delimiter => leading empty string
    res = strutil::split(">=abc", ">=");
    ASSERT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], "");
    EXPECT_EQ(res[1], "abc");

    // Trailing delimiter => trailing empty string
    res = strutil::split("abc>=", ">=");
    ASSERT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], "abc");
    EXPECT_EQ(res[1], "");

    // Repeated delimiters => repeated empty strings
    res = strutil::split("abc>=>=>=def", ">=");
    expected = { "abc", "", "", "def" };
    ASSERT_EQ(res.size(), expected.size());
    for (unsigned i = 0; i < res.size(); ++i)
    {
        EXPECT_EQ(expected[i], res[i]);
    }

    // keep_empty = false => empty tokens are dropped.
    res = strutil::split(">=abc>=>=def>=", ">=", false);
    expected = { "abc", "def" };
    EXPECT_EQ(res, expected);

    // keep_empty = false on empty input => empty result.
    res = strutil::split("", ">=", false);
    EXPECT_TRUE(res.empty());

    // keep_empty = false on a string of only delimiters => empty result.
    res = strutil::split(">=>=>=", ">=", false);
    EXPECT_TRUE(res.empty());
}

TEST(Splitting, split_any)
{
    std::vector<std::string> res;

    // Basic usage
    res = strutil::split_any("abc,def|ghi jkl", ",| ");
    ASSERT_EQ(res.size(), 4);
    EXPECT_EQ(res[0], "abc");
    EXPECT_EQ(res[1], "def");
    EXPECT_EQ(res[2], "ghi");
    EXPECT_EQ(res[3], "jkl");

    // Empty input => empty string
    ASSERT_EQ(strutil::split_any("", ",:")[0], "");

    // No matches => original string
    res = strutil::split_any("abc_123", ",; ");
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0], "abc_123");

    // Empty delimiters => original string
    res = strutil::split_any("abc;def", "");
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0], "abc;def");

    // Leading delimiters => leading empty string
    res = strutil::split_any(";abc", ",; ");
    ASSERT_EQ(res.size(), 2);
    ASSERT_EQ(res[0], "");
    ASSERT_EQ(res[1], "abc");

    // Trailing delimiters => trailing empty string
    res = strutil::split_any("abc;", ",; ");
    ASSERT_EQ(res.size(), 2);
    ASSERT_EQ(res[0], "abc");
    ASSERT_EQ(res[1], "");

    // Consecutive delimiters => repeated empty strings
    res = strutil::split_any("abc,;123", ",;");
    ASSERT_EQ(res.size(), 3);
    EXPECT_EQ(res[0], "abc");
    EXPECT_EQ(res[1], "");
    EXPECT_EQ(res[2], "123");

    // keep_empty = false => empty tokens are dropped.
    res = strutil::split_any(",abc,;def;", ",;", false);
    ASSERT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], "abc");
    EXPECT_EQ(res[1], "def");

    // keep_empty = false on empty input => empty result.
    res = strutil::split_any("", ",;", false);
    EXPECT_TRUE(res.empty());

    // keep_empty = false on a string of only delimiters => empty result.
    res = strutil::split_any(",;,;", ",;", false);
    EXPECT_TRUE(res.empty());
}

TEST(Regexsplitting, regex_split)
{
    std::vector<std::string> res;

    // Basic usage
    res = strutil::regex_split("abc,abcd;abce.abcf?", "[,;\\.\\?]+");

    ASSERT_EQ(res.size(), 4);
    EXPECT_EQ(res[0], "abc");
    EXPECT_EQ(res[1], "abcd");
    EXPECT_EQ(res[2], "abce");
    EXPECT_EQ(res[3], "abcf");

    // Empty input => empty string
    ASSERT_EQ(strutil::regex_split("", ",:")[0], "");

    // No matches => original string
    res = strutil::regex_split("abc_123", ",; ");
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0], "abc_123");

    // Empty delimiters => original string
    res = strutil::regex_split("abc;def", "");
    ASSERT_EQ(res.size(), 8);
    EXPECT_EQ(res[0], "");
    EXPECT_EQ(res[1], "a");
    EXPECT_EQ(res[2], "b");
    EXPECT_EQ(res[3], "c");
    EXPECT_EQ(res[4], ";");
    EXPECT_EQ(res[5], "d");
    EXPECT_EQ(res[6], "e");
    EXPECT_EQ(res[7], "f");

    // Leading delimiters => leading empty string.
    // The pattern is a character class so that ';' actually matches; the
    // previous version of this test passed a literal three-character regex
    // that never matched anything and so silently asserted the wrong thing.
    res = strutil::regex_split(";abc", "[,; ]");
    ASSERT_EQ(res.size(), 2);
    EXPECT_EQ(res[0], "");
    EXPECT_EQ(res[1], "abc");

    // keep_empty = false => empty tokens are dropped.
    res = strutil::regex_split(";abc", "[,; ]", false);
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0], "abc");

    res = strutil::regex_split("a,,b,,c", "[,]+", false);
    ASSERT_EQ(res.size(), 3);
    EXPECT_EQ(res[0], "a");
    EXPECT_EQ(res[1], "b");
    EXPECT_EQ(res[2], "c");
}

TEST(Regexsplitting_map, regex_split_map)
{
    std::map<std::string, std::string> res = strutil::regex_split_map("[abc] name = 123; [abd] name = 123;[abe] name = 123;  ", "\\[[^\\]]+\\]");
    std::map<std::string, std::string> ans = {
        {"[abc]", "name = 123;"}, {"[abd]", "name = 123;"}, {"[abe]", "name = 123;"}
    };
    for (auto each: res) {
        ASSERT_EQ(ans.count(each.first), 1);
        if (ans.count(each.first) == 1)
        {
            auto str = each.second;
            strutil::trim(str);
            ASSERT_EQ(str, ans[each.first]);
        }
    }
}

TEST(SplittingVector, join)
{
    std::string str1 = "Col1;Col2;Col3";
    std::vector<std::string> tokens1 = { "Col1", "Col2", "Col3" };

    EXPECT_EQ(str1, strutil::join(tokens1, ";"));

    std::string str2 = "1|2|3";
    std::vector<unsigned> tokens2 = { 1, 2, 3 };

    EXPECT_EQ(str2, strutil::join(tokens2, "|"));
}

TEST(SplittingSet, join)
{
    std::string str1 = "Col1;Col2;Col3";
    std::set<std::string> tokens1 = { "Col1", "Col2", "Col3" };

    EXPECT_EQ(str1, strutil::join(tokens1, ";"));

    std::string str2 = "1|2|3";
    std::set<unsigned> tokens2 = { 1, 2, 3 };

    EXPECT_EQ(str2, strutil::join(tokens2, "|"));
}

TEST(SplittingVector, join_edge_cases)
{
    // Empty container => empty string, no leading/trailing delimiter.
    EXPECT_EQ("", strutil::join(std::vector<std::string>{}, ";"));
    EXPECT_EQ("", strutil::join(std::vector<int>{}, ", "));

    // Single element => no delimiter is emitted.
    EXPECT_EQ("only", strutil::join(std::vector<std::string>{ "only" }, ";"));
    EXPECT_EQ("42",   strutil::join(std::vector<int>{ 42 }, ", "));

    // Empty delimiter concatenates without separator.
    EXPECT_EQ("abc", strutil::join(std::vector<std::string>{ "a", "b", "c" }, ""));

    // Container of empty strings — each "element" contributes nothing,
    // but the delimiters between them are still emitted.
    EXPECT_EQ(",,", strutil::join(std::vector<std::string>{ "", "", "" }, ","));
}

TEST(SplittingDropEmptyVector, drop_empty)
{
    std::vector<std::string> tokens = { "t1", "t2", "", "t4", "" };
    strutil::drop_empty(tokens);
    ASSERT_EQ(tokens.size(), 3);
    ASSERT_EQ(tokens[0], "t1");
    ASSERT_EQ(tokens[1], "t2");
    ASSERT_EQ(tokens[2], "t4");
}

TEST(SplittingDropEmptyCopyVector, drop_empty_copy)
{
    std::vector<std::string> tokens = { "t1", "t2", "", "t4", "" };
    auto res = strutil::drop_empty_copy(tokens);
    ASSERT_EQ(res.size(), 3);
    ASSERT_EQ(res[0], "t1");
    ASSERT_EQ(res[1], "t2");
    ASSERT_EQ(res[2], "t4");
}

TEST(SplittingDropEmptySet, drop_empty)
{
    std::set<std::string> tokens = { "t1", "t2", "", "t4", ""};
    strutil::drop_empty(tokens);
    auto it = tokens.begin();

    ASSERT_EQ(tokens.size(), 3);
    ASSERT_EQ(*(  it), "t1");
    ASSERT_EQ(*(++it), "t2");
    ASSERT_EQ(*(++it), "t4");
}

TEST(SplittingDropEmptyCopySet, drop_empty_copy)
{
    std::set<std::string> tokens = { "t1", "t2", "", "t4", "" };
    auto res = strutil::drop_empty_copy(tokens);
    auto it  = res.begin();

    ASSERT_EQ(res.size(), 3);
    ASSERT_EQ(*(  it), "t1");
    ASSERT_EQ(*(++it), "t2");
    ASSERT_EQ(*(++it), "t4");
}

TEST(TestDropDuplicate, drop_duplicate)
{
    std::vector<std::string> str1 = { "t1", "t2", "", "t4", "", "t1"};
    strutil::drop_duplicate(str1);

    std::vector<std::string> str2 = { "", "t1", "t2", "t4"};

    EXPECT_EQ(std::equal(str1.cbegin(), str1.cend(), str2.cbegin()), true);
}

TEST(TestDropDuplicateCopy, drop_duplicate_copy)
{
    std::vector<std::string> str1 = { "t1", "t2", "", "t4", "", "t1"};
    auto str3 = strutil::drop_duplicate_copy(str1);
    
    std::vector<std::string> str2 = { "", "t1", "t2", "t4"};
    EXPECT_EQ(std::equal(str2.cbegin(), str2.cend(), str3.cbegin()), true);
}

#ifdef STRUTIL_ENABLE_PARALLEL
TEST(TestDropDuplicatePar, drop_duplicate_par)
{
    std::vector<std::string> str1 = { "t1", "t2", "", "t4", "", "t1"};
    strutil::drop_duplicate_par(str1);

    std::vector<std::string> str2 = { "", "t1", "t2", "t4"};

    EXPECT_EQ(std::equal(str1.cbegin(), str1.cend(), str2.cbegin()), true);
}

TEST(TestDropDuplicateCopyPar, drop_duplicate_copy_par)
{
    std::vector<std::string> str1 = { "t1", "t2", "", "t4", "", "t1"};
    auto str3 = strutil::drop_duplicate_copy_par(str1);

    std::vector<std::string> str2 = { "", "t1", "t2", "t4"};
    EXPECT_EQ(std::equal(str2.cbegin(), str2.cend(), str3.cbegin()), true);
}
#endif // STRUTIL_ENABLE_PARALLEL

/*
 * Text manipulation tests
 */

TEST(TextManip, to_lower)
{
    EXPECT_EQ("hello strutil", strutil::to_lower("HeLlo StRUTIL"));
    EXPECT_EQ("", strutil::to_lower(""));
}

TEST(TextManip, to_upper)
{
    EXPECT_EQ("HELLO STRUTIL", strutil::to_upper("HeLlo StRUTIL"));
    EXPECT_EQ("", strutil::to_upper(""));
}

TEST(TextManip, capitalize)
{
    EXPECT_EQ("HeLlo StRUTIL", strutil::capitalize("heLlo StRUTIL"));
    EXPECT_EQ("+ is an operator.", strutil::capitalize("+ is an operator."));
    EXPECT_EQ("", strutil::capitalize(""));
}

TEST(TextManip, capitalize_first_char)
{
    EXPECT_EQ("Hello strutil", strutil::capitalize_first_char("HeLlo StRUTIL"));
    EXPECT_EQ("+ is an operator.", strutil::capitalize_first_char("+ is an operator."));
    EXPECT_EQ("", strutil::capitalize_first_char(""));
}

TEST(TextManip, trim_left_in_place)
{
    std::string test = "   HeLlo StRUTIL";
    strutil::trim_left(test);

    EXPECT_EQ("HeLlo StRUTIL", test);
}

TEST(TextManip, trim_right_in_place)
{
    std::string test = "HeLlo StRUTIL    ";
    strutil::trim_right(test);

    EXPECT_EQ("HeLlo StRUTIL", test);
}

TEST(TextManip, trim_both_in_place)
{
    std::string test = "   HeLlo StRUTIL    ";
    strutil::trim(test);

    EXPECT_EQ("HeLlo StRUTIL", test);
}

TEST(TextManip, trim_left)
{
    EXPECT_EQ("HeLlo StRUTIL", strutil::trim_left_copy("     HeLlo StRUTIL"));
}

TEST(TextManip, trim_right)
{
    EXPECT_EQ("HeLlo StRUTIL", strutil::trim_right_copy("HeLlo StRUTIL       "));
}

TEST(TextManip, trim_both)
{
    EXPECT_EQ("HeLlo StRUTIL", strutil::trim_copy("    HeLlo StRUTIL      "));
}

TEST(TextManip, trim_edge_cases)
{
    // Empty string: should remain empty, no UB.
    {
        std::string s;
        strutil::trim_left(s);   EXPECT_EQ("", s);
        strutil::trim_right(s);  EXPECT_EQ("", s);
        strutil::trim(s);        EXPECT_EQ("", s);
    }
    EXPECT_EQ("", strutil::trim_left_copy(""));
    EXPECT_EQ("", strutil::trim_right_copy(""));
    EXPECT_EQ("", strutil::trim_copy(""));

    // String of only whitespace collapses to empty.
    EXPECT_EQ("", strutil::trim_copy("     \t\n\r"));
    EXPECT_EQ("", strutil::trim_left_copy("   \t  "));
    EXPECT_EQ("", strutil::trim_right_copy("   \t  "));

    // String with no whitespace is unchanged.
    EXPECT_EQ("abc", strutil::trim_copy("abc"));
    EXPECT_EQ("abc", strutil::trim_left_copy("abc"));
    EXPECT_EQ("abc", strutil::trim_right_copy("abc"));

    // Whitespace-only on one side — make sure the OTHER side is preserved.
    EXPECT_EQ("abc   ", strutil::trim_left_copy("   abc   "));
    EXPECT_EQ("   abc", strutil::trim_right_copy("   abc   "));

    // std::isspace should recognize tabs, newlines, CR, vertical tab, form feed.
    EXPECT_EQ("hello", strutil::trim_copy("\t\n\r\v\f hello \f\v\r\n\t"));

    // Internal whitespace must NOT be stripped.
    EXPECT_EQ("hello   world", strutil::trim_copy("   hello   world   "));
}

TEST(TextManip, repeat)
{
    EXPECT_EQ("GoGoGoGo",   strutil::repeat("Go", 4));
    EXPECT_EQ("ZZZZZZZZZZ", strutil::repeat('Z', 10));

    // n == 0 produces an empty string for both overloads.
    EXPECT_EQ("", strutil::repeat("Go", 0));
    EXPECT_EQ("", strutil::repeat('Z', 0));

    // Repeating an empty string is also empty regardless of n.
    EXPECT_EQ("", strutil::repeat("", 5));
}

TEST(TextManip, replace_first)
{
    std::string str1 = "This is $name and that is also $name.";
    bool res = strutil::replace_first(str1, "$name", "Jon Doe");

    EXPECT_EQ(true, res);
    EXPECT_EQ("This is Jon Doe and that is also $name.", str1);
}

TEST(TextManip, no_replace_first)
{
    std::string str1 = "This is $name and that is also $name.";
    bool res = strutil::replace_first(str1, "$name$", "Jon Doe");

    EXPECT_EQ(false, res);
    EXPECT_EQ("This is $name and that is also $name.", str1);
}

TEST(TextManip, replace_last)
{
    std::string str1 = "This is $name and that is also $name.";
    bool res = strutil::replace_last(str1, "$name", "Jon Doe");

    EXPECT_EQ(true, res);
    EXPECT_EQ("This is $name and that is also Jon Doe.", str1);
}

TEST(TextManip, no_replace_last)
{
    std::string str1 = "This is $name and that is also $name.";
    bool res = strutil::replace_last(str1, "$name$", "Jon Doe");

    EXPECT_EQ(false, res);
    EXPECT_EQ("This is $name and that is also $name.", str1);
}

TEST(TextManip, replace_all)
{
    std::string str1 = "This is $name and that is also $name.";
    bool res = strutil::replace_all(str1, "$name", "Jon Doe");

    EXPECT_EQ(true, res);
    EXPECT_EQ("This is Jon Doe and that is also Jon Doe.", str1);
}

TEST(TextManip, no_replace_all)
{
    std::string str1 = "This is $name and that is also $name.";
    bool res = strutil::replace_last(str1, "$name$", "Jon Doe");

    EXPECT_EQ(false, res);
    EXPECT_EQ("This is $name and that is also $name.", str1);
}

TEST(TextManip, replace_all_self_overlapping)
{
    std::string s = "aaa";
    bool res = strutil::replace_all(s, "a", "aa");
    EXPECT_EQ(true, res);
    EXPECT_EQ("aaaaaa", s);

    // Replacement that *fully contains* the target (longer prefix)
    std::string s2 = "ab";
    EXPECT_EQ(true, strutil::replace_all(s2, "a", "ab"));
    EXPECT_EQ("abb", s2);
}

TEST(TextManip, replace_with_empty_replacement)
{
    // Replacement = "" effectively deletes the target. Worth pinning down
    // for all three replace_* variants.
    std::string s1 = "foo bar foo baz foo";
    EXPECT_EQ(true, strutil::replace_first(s1, "foo ", ""));
    EXPECT_EQ("bar foo baz foo", s1);

    std::string s2 = "foo bar foo baz foo";
    EXPECT_EQ(true, strutil::replace_last(s2, " foo", ""));
    EXPECT_EQ("foo bar foo baz", s2);

    std::string s3 = "foo bar foo baz foo";
    EXPECT_EQ(true, strutil::replace_all(s3, "foo", ""));
    EXPECT_EQ(" bar  baz ", s3);
}

TEST(TextManip, replace_first_last_target_empty)
{
    std::string s1 = "abc";
    EXPECT_EQ(false, strutil::replace_first(s1, "", "X"));
    EXPECT_EQ("abc", s1);

    std::string s2 = "abc";
    EXPECT_EQ(false, strutil::replace_last(s2, "", "X"));
    EXPECT_EQ("abc", s2);
}

TEST(TextManip, replace_all_target_empty)
{
    std::string str1 = "This is $name and that is also $name.";
    bool res = strutil::replace_all(str1, "", "Jon Doe");

    EXPECT_EQ(false, res);
    EXPECT_EQ("This is $name and that is also $name.", str1);
}

TEST(TextSortAscending, sorting_ascending)
{
    std::vector<std::string> str1 = {"ABC", "abc", "bcd", "", "-", "  ", "123", "-100"};
    strutil::sorting_ascending(str1);

    std::vector<std::string> str2 = {"", "  ", "-", "-100", "123", "ABC", "abc", "bcd"};
    EXPECT_EQ(std::equal(str1.cbegin(), str1.cend(), str2.cbegin()), true);
}

TEST(TextSortDescending, sorting_descending)
{
    std::vector<std::string> str1 = {"ABC", "abc", "bcd", "", "-", "  ", "123", "-100"};
    strutil::sorting_descending(str1);

    std::vector<std::string> str2 = {"bcd", "abc", "ABC", "123", "-100", "-", "  ", ""};
    EXPECT_EQ(std::equal(str1.cbegin(), str1.cend(), str2.cbegin()), true);
}

#ifdef STRUTIL_ENABLE_PARALLEL
TEST(TextSortAscendingPar, sorting_ascending_par)
{
    std::vector<std::string> str1 = {"ABC", "abc", "bcd", "", "-", "  ", "123", "-100"};
    strutil::sorting_ascending_par(str1);

    std::vector<std::string> str2 = {"", "  ", "-", "-100", "123", "ABC", "abc", "bcd"};
    EXPECT_EQ(std::equal(str1.cbegin(), str1.cend(), str2.cbegin()), true);
}

TEST(TextSortDescendingPar, sorting_descending_par)
{
    std::vector<std::string> str1 = {"ABC", "abc", "bcd", "", "-", "  ", "123", "-100"};
    strutil::sorting_descending_par(str1);

    std::vector<std::string> str2 = {"bcd", "abc", "ABC", "123", "-100", "-", "  ", ""};
    EXPECT_EQ(std::equal(str1.cbegin(), str1.cend(), str2.cbegin()), true);
}
#endif // STRUTIL_ENABLE_PARALLEL

TEST(TextReverseInplace, reverse_inplace)
{
    std::vector<std::string> str1 = {"bcd", "abc", "ABC", "123", "-100", "-", "  ", ""};

    strutil::reverse_inplace(str1);

    std::vector<std::string> str2 = {"", "  ", "-", "-100", "123", "ABC", "abc", "bcd"};

    EXPECT_EQ(std::equal(str1.cbegin(), str1.cend(), str2.cbegin()), true);
}

TEST(TextReverseCopy, reverse_copy)
{
    std::vector<std::string> str1 = {"bcd", "abc", "ABC", "123", "-100", "-", "  ", ""};
    std::vector<std::string> str3(str1.begin(), str1.end());

    auto str4 = strutil::reverse_copy(str1);

    std::vector<std::string> str2 = {"", "  ", "-", "-100", "123", "ABC", "abc", "bcd"};

    EXPECT_EQ(std::equal(str1.cbegin(), str1.cend(), str3.cbegin()), true);
    EXPECT_EQ(std::equal(str4.cbegin(), str4.cend(), str2.cbegin()), true);
}