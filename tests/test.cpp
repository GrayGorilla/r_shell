#include "testcommand.h"
#include "testconnector.h"
#include "testparse.h"
#include "gtest/gtest.h"


/*Command Tests*/
TEST(COMMAND, VALID){
  EXPECT_EQ(0, test_valid_command());
}

TEST(COMMAND, INVALID){
  EXPECT_EQ(2, test_invalid_command());
}

TEST(COMMAND, EMPTY){
  EXPECT_EQ(2, test_empty_command());
}

TEST(COMMAND, EXIT){
  EXPECT_EQ(3, test_exit_command());
}

TEST(COMMAND, VALID_ARGUMENT){
  EXPECT_EQ(0, test_valid_command_with_argument());
}

TEST(COMMAND, EMPTY_ARGUMENT){
  EXPECT_EQ(2, test_valid_command_with_empty_argument());
}

TEST(COMMAND, INVALID_COMMAND_ARGUMENT){
  EXPECT_EQ(2, test_invalid_command_with_argument());
}

/*TEST COMMAND*/
TEST(TEST_COMMAND, VALID_E){
  EXPECT_EQ(0, test_valid_test_e_command());
}

TEST(TEST_COMMAND, INVALID_E){
  EXPECT_EQ(2, test_invalid_test_e_command());
}

TEST(TEST_COMMAND, VALID_D){
  EXPECT_EQ(0, test_valid_test_d_command());
}

TEST(TEST_COMMAND, INVALID_D){
  EXPECT_EQ(2, test_invalid_test_d_command());
}

TEST(TEST_COMMAND, VALID_F){
  EXPECT_EQ(0, test_valid_test_f_command());
}

TEST(TEST_COMMAND, INVALID_F){
  EXPECT_EQ(2, test_invalid_test_f_command());
}

TEST(TEST_COMMAND, VALID_ONE_ARGUMENT){
  EXPECT_EQ(0, test_valid_one_argument_test_command());
}

TEST(TEST_COMMAND, INVALID_ONE_ARGUMENT){
  EXPECT_EQ(2, test_invalid_one_argument_test_command());
}

TEST(TEST_COMMAND, EMPTY){
  EXPECT_EQ(2, test_zero_argument_test_command());
}

TEST(TEST_COMMAND, THREE_ARGUMENT){
  EXPECT_EQ(2, test_three_argument_test_command());
}

/*Connector Tests*/

//Or Test
TEST(OR, LS_OR_EXIT){
  EXPECT_EQ(0, test_ls_or_exit());
}

TEST(OR, QS_OR_EXIT){
  EXPECT_EQ(3, test_qs_or_exit());
}

TEST(OR, EXIT_OR_LS){
  EXPECT_EQ(3, test_exit_or_ls());
}

TEST(OR, EQIT_OR_LS){
  EXPECT_EQ(0, test_eqit_or_ls());
}

TEST(OR, EQIT_OR_QS){
  EXPECT_EQ(2, test_eqit_or_qs());
}

/*Parse Tests*/
TEST(PARSE, VALID_COMMAND){
  EXPECT_EQ(0, test_valid_parse());
}

TEST(PARSE, INVALID_COMMAND){
  EXPECT_EQ(2, test_invalid_parse());
}

TEST(PARSE, EXIT_COMMAND){
  EXPECT_EQ(3, test_exit_parse());
}

TEST(PARSE, COMMAND_WITH_ARGUMENT){
  EXPECT_EQ(0, test_valid_parse_with_arg());
}

TEST(PARSE, COMMAND_EMPTY_ARGUMENTS){
  EXPECT_EQ(0, test_valid_parse_with_empty_arg());
}

TEST(PARSE, INVALID_COMMAND_WITH_ARGUMENT){
  EXPECT_EQ(2, test_invalid_parse_with_arg());
}


//And Test
TEST(AND, LS_AND_EXIT){
  EXPECT_EQ(3, test_ls_and_exit());
}

TEST(AND, QS_AND_EXIT){
  EXPECT_EQ(2, test_qs_and_exit());
}

TEST(AND, EXIT_AND_LS){
  EXPECT_EQ(3, test_exit_and_ls());
}

TEST(AND, EQIT_AND_LS){
  EXPECT_EQ(2, test_eqit_and_ls());
}

TEST(AND, EQIT_AND_QS){
  EXPECT_EQ(2, test_eqit_and_qs());
}

//Separator Test
TEST(SEPARATOR, LS_SEP_EXIT){
  EXPECT_EQ(3, test_ls_sep_exit());
}

TEST(SEPARATOR, QS_SEP_EXIT){
  EXPECT_EQ(3, test_qs_sep_exit());
}

TEST(SEPARATOR, EXIT_SEP_LS){
  EXPECT_EQ(3, test_exit_sep_ls());
}

TEST(SEPARATOR, EQIT_SEP_LS){
  EXPECT_EQ(0, test_eqit_sep_ls());
}

TEST(SEPARATOR, EQIT_SEP_QS){
  EXPECT_EQ(2, test_eqit_sep_qs());
}

//Comment Test
TEST(COMMENT, EXIT_COMMENT){
  EXPECT_EQ(3, test_exit_comment());
}

TEST(COMMENT, LS_COMMENT){
  EXPECT_EQ(0, test_ls_comment());
}

TEST(COMMENT, QS_COMMENT){
  EXPECT_EQ(2, test_qs_comment());
}

//Bracket Test
TEST(BRACKET, E_TEST){
  EXPECT_EQ(0, test_valid_bracket());
}

TEST(BRACKET, NO_SPACE){
  EXPECT_EQ(2, test_invalid_no_space_bracket());
}

TEST(BRACKET, NO_LEFT){
  EXPECT_EQ(2, test_invalid_no_left_bracket());
}

TEST(BRACKET, NO_RIGHT){
  EXPECT_EQ(2, test_invalid_no_right_bracket());
}

TEST(BRACKET, VALID_TEST_STRING){
  EXPECT_EQ(0, test_valid_test_bracket());
}

TEST(BRACKET, INVALID_TEST_STRING){
  EXPECT_EQ(2, test_invalid_test_bracket());
}

//Precedence Test

TEST(PRECEDENCE, VALID_PRECEDENCE){
  EXPECT_EQ(0, test_valid_precedence());
}

TEST(PRECEDENCE, IN_VALID_LEFT_PRECEDENCE){
  EXPECT_EQ(2, test_invalid_left_precedence());
}

TEST(PRECEDENCE, IN_VALID_RIGHT_PRECEDENCE){
  EXPECT_EQ(2, test_invalid_right_precedence());
}

TEST(PRECEDENCE, IN_INVALID_MISMATCH_PRECEDENCE){
  EXPECT_EQ(2, test_invalid_mismatch_precedence());
}

TEST(PRECEDENCE, VALID_LONG_PRECEDENCE){
  EXPECT_EQ(0, test_valid_long_precedence());
}

/*PIPING*/
TEST(REDIRECTION, BASIC_PIPE){
  EXPECT_EQ(0, test_pipe());
}

TEST(REDIRECTION, NECESSARY_CASE){
  EXPECT_EQ(0, test_necessary_case());
}

/*MAIN*/
int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
