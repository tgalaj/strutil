/**
 * Copyright (C) 2020 Tomasz Galaj (Shot511)
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
}

TEST(Compare, starts_with_str)
{
    EXPECT_EQ(true, strutil::starts_with("m_DiffuseTexture", "m_"));
    EXPECT_EQ(true, strutil::starts_with("This is a simple test case", "This "));

    EXPECT_EQ(false, strutil::starts_with("p_DiffuseTexture", "m_"));
    EXPECT_EQ(false, strutil::starts_with("This is a simple test case", "his "));

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

    EXPECT_EQ(false, strutil::ends_with("DiffuseTexture_p", "_m"));
    EXPECT_EQ(false, strutil::ends_with("This is a simple test case", "test cas"));

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
    EXPECT_EQ(false, strutil::contains("DiffuseTexture_m", "fuser"));
}

TEST(Compare, contains_char)
{
    EXPECT_EQ(true, strutil::contains("DiffuseTexture_m", 'f'));
    EXPECT_EQ(false, strutil::contains("DiffuseTexture_m", 'z'));
}

TEST(Compare, matches)
{
    const std::regex check_mail("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$");

    EXPECT_EQ(true, strutil::matches("jon.doe@somehost.com", check_mail));
    EXPECT_EQ(false, strutil::matches("jon.doe@", check_mail));
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
    EXPECT_EQ(5.245f, strutil::parse_string<float>("5.245f"));
}

TEST(Parsing, string_to_double)
{
    EXPECT_EQ(5.245, strutil::parse_string<double>("5.245"));
}

TEST(Parsing, string_to_long_double)
{
    EXPECT_EQ(-5.245L, strutil::parse_string<long double>("-5.245"));
}

TEST(Parsing, string_to_bool)
{
    EXPECT_EQ(true, strutil::parse_string<bool>("1"));
}

TEST(Parsing, string_to_neg_bool)
{
    EXPECT_EQ(false, strutil::parse_string<bool>("0"));
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
}

TEST(Resplitting, resplit)
{
    std::vector<std::string> res;

    // Basic usage
    res = strutil::resplit("abc,abcd;abce.abcf?", "[,;\\.\\?]+");

    ASSERT_EQ(res.size(), 4);
    EXPECT_EQ(res[0], "abc");
    EXPECT_EQ(res[1], "abcd");
    EXPECT_EQ(res[2], "abce");
    EXPECT_EQ(res[3], "abcf");

    // Empty input => empty string
    ASSERT_EQ(strutil::resplit("", ",:")[0], "");

    // No matches => original string
    res = strutil::resplit("abc_123", ",; ");
    ASSERT_EQ(res.size(), 1);
    EXPECT_EQ(res[0], "abc_123");

    // Empty delimiters => original string
    res = strutil::resplit("abc;def", "");
    ASSERT_EQ(res.size(), 8);
    EXPECT_EQ(res[0], "");
    EXPECT_EQ(res[1], "a");
    EXPECT_EQ(res[2], "b");
    EXPECT_EQ(res[3], "c");
    EXPECT_EQ(res[4], ";");
    EXPECT_EQ(res[5], "d");
    EXPECT_EQ(res[6], "e");
    EXPECT_EQ(res[7], "f");

    // Leading delimiters => leading empty string
    res = strutil::resplit(";abc", ",; ");
    ASSERT_EQ(res.size(), 1);
    ASSERT_EQ(res[0], ";abc");
}

TEST(Resplitting, resplit_map)
{
    std::map<std::string, std::string> res;

    // Basic usage
    strutil::resplit_map("[abc] name = 123;[abd] name = 123;[abe] name = 123;",  res, "\\[([^\\]]+)\\]");
}

TEST(Splitting, join)
{
    std::string str1 = "Col1;Col2;Col3";
    std::vector<std::string> tokens1 = { "Col1", "Col2", "Col3" };

    EXPECT_EQ(str1, strutil::join<std::string>(tokens1, ";"));

    std::string str2 = "1|2|3";
    std::vector<unsigned> tokens2 = { 1, 2, 3 };

    EXPECT_EQ(str2, strutil::join<unsigned>(tokens2, "|"));
}

TEST(Splitting, drop_empty)
{
    std::vector<std::string> tokens = { "t1", "t2", "", "t4", "" };
    strutil::drop_empty(tokens);
    ASSERT_EQ(tokens.size(), 3);
    ASSERT_EQ(tokens[0], "t1");
    ASSERT_EQ(tokens[1], "t2");
    ASSERT_EQ(tokens[2], "t4");
}

TEST(Splitting, drop_empty_copy)
{
    std::vector<std::string> tokens = { "t1", "t2", "", "t4", "" };
    auto res = strutil::drop_empty_copy(tokens);
    ASSERT_EQ(res.size(), 3);
    ASSERT_EQ(res[0], "t1");
    ASSERT_EQ(res[1], "t2");
    ASSERT_EQ(res[2], "t4");
}

/*
 * Text manipulation tests
 */

TEST(TextManip, to_lower)
{
    EXPECT_EQ("hello strutil", strutil::to_lower("HeLlo StRUTIL"));
}

TEST(TextManip, to_upper)
{
    EXPECT_EQ("HELLO STRUTIL", strutil::to_upper("HeLlo StRUTIL"));
}

TEST(TextManip, to_capitalize)
{
    EXPECT_EQ("HeLlo StRUTIL", strutil::to_capitalize("heLlo StRUTIL"));
}

TEST(TextManip, to_capitalize_only)
{
    EXPECT_EQ("Hello strutil", strutil::to_capitalize_only("HeLlo StRUTIL"));
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

TEST(TextManip, repeat)
{
    EXPECT_EQ("GoGoGoGo",   strutil::repeat("Go", 4));
    EXPECT_EQ("ZZZZZZZZZZ", strutil::repeat('Z', 10));
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

TEST(TextManip, replace_all_target_empty)
{
    std::string str1 = "This is $name and that is also $name.";
    bool res = strutil::replace_all(str1, "", "Jon Doe");

    EXPECT_EQ(false, res);
    EXPECT_EQ("This is $name and that is also $name.", str1);
}
