#include <thirdparty/ctest.h>
#include <stdbool.h>
#include <stdio.h>

#include <libgeometry/geometry.h>

CTEST(input, correct)
{
    char* input = "circle(1 1,3)";
    char* cir = "circle";
    bool result = correct(cir, input, 50);
    ASSERT_TRUE(result);
}
CTEST(input, uncorrect_word)
{
    char* input = "cirkle(1 1,3)";
    char* cir = "circle";
    bool result = correct(cir, input, 50);
    ASSERT_FALSE(result);
}
CTEST(input, uncorrect_word_and_minus_comma)
{
    char* input = "circl1 1,3)";
    char* cir = "circle";
    bool result = correct(cir, input, 50);
    ASSERT_FALSE(result);
}
////////////////////////////////////////////////
CTEST(input, finding_bracket_correct)
{
    char* input = "circle(1 1,3)";
    bool result1 = finding_bracket(input);
    ASSERT_TRUE(result1);
}
CTEST(input, finding_comma_correct)
{
    char* input = "circle(1 1,3)";
    bool result1 = finding_comma(input);
    ASSERT_TRUE(result1);
}
CTEST(input, finding_bracket2_correct)
{
    char* input = "circle(1 1,3)";
    bool result1 = finding_bracket2(input);
    ASSERT_TRUE(result1);
}
///////////////////////////////////////////////
CTEST(input, finding_bracket_false)
{
    char* input = "circle1 1,3)";
    bool result1 = finding_bracket(input);
    ASSERT_FALSE(result1);
}
CTEST(input, finding_comma_false)
{
    char* input = "circle(1 13)";
    bool result1 = finding_comma(input);
    ASSERT_FALSE(result1);
}
CTEST(input, finding_bracket2_false)
{
    char* input = "circle(1 1,3";
    bool result1 = finding_bracket2(input);
    ASSERT_FALSE(result1);
}
