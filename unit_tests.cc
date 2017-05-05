//
// Created by guessever on 5/5/17.
//

#include <gtest/gtest.h>
#include "src/Grun.h"

TEST(Code, pascal) {
    Code *code = new Code("/home/username/A.pas");
    EXPECT_STREQ(code->path, "/home/username/A.pas");
    EXPECT_EQ(code->language, Pascal);
    EXPECT_STREQ(code->extension, "pas");
    EXPECT_STREQ(code->filename, "Main.pas");
    EXPECT_STREQ(code->filename2, "Main");
}
TEST(Code, c) {
    Code *code = new Code("/home/username/c.c");
    EXPECT_STREQ(code->path, "/home/username/c.c");
    EXPECT_EQ(code->language, C);
    EXPECT_STREQ(code->extension, "c");
    EXPECT_STREQ(code->filename, "Main.c");
    EXPECT_STREQ(code->filename2, "Main");
}
TEST(Code, cpp) {
    Code *code = new Code("/home/username/filename.cpp");
    EXPECT_STREQ(code->path, "/home/username/filename.cpp");
    EXPECT_EQ(code->language, CC);
    EXPECT_STREQ(code->extension, "cc");
    EXPECT_STREQ(code->filename, "Main.cc");
    EXPECT_STREQ(code->filename2, "Main");
}
TEST(Code, cc) {
    Code *code = new Code("/home/username/random.cpp.cc");
    EXPECT_STREQ(code->path, "/home/username/random.cpp.cc");
    EXPECT_EQ(code->language, CC);
    EXPECT_STREQ(code->extension, "cc");
    EXPECT_STREQ(code->filename, "Main.cc");
    EXPECT_STREQ(code->filename2, "Main");
}
TEST(Code, cxx) {
    Code *code = new Code("/home/username/filename.cxx");
    EXPECT_STREQ(code->path, "/home/username/filename.cxx");
    EXPECT_EQ(code->language, CC);
    EXPECT_STREQ(code->extension, "cc");
    EXPECT_STREQ(code->filename, "Main.cc");
    EXPECT_STREQ(code->filename2, "Main");
}
TEST(Code, java) {
    Code *code = new Code("/home/username/A.java");
    EXPECT_STREQ(code->path, "/home/username/A.java");
    EXPECT_EQ(code->language, Java);
    EXPECT_STREQ(code->extension, "java");
    EXPECT_STREQ(code->filename, "Main.java");
    EXPECT_STREQ(code->filename2, "Main");
}
TEST(Code, python) {
    Code *code = new Code("/home/username/A.py");
    EXPECT_STREQ(code->path, "/home/username/A.py");
    EXPECT_EQ(code->language, Python);
    EXPECT_STREQ(code->extension, "py");
    EXPECT_STREQ(code->filename, "Main.py");
    EXPECT_STREQ(code->filename2, "Main");
}
TEST(Code, lua) {
    Code *code = new Code("/home/username/A.lua");
    EXPECT_STREQ(code->path, "/home/username/A.lua");
    EXPECT_EQ(code->language, Lua);
    EXPECT_STREQ(code->extension, "lua");
    EXPECT_STREQ(code->filename, "Main.lua");
    EXPECT_STREQ(code->filename2, "Main");
}

TEST(Result, set_used) {
    Result *result = new Result();
    rusage usage;
    usage.ru_maxrss = 666;
    usage.ru_utime.tv_sec = 1;
    usage.ru_utime.tv_usec = 667000;
    usage.ru_stime.tv_sec = 0;
    usage.ru_stime.tv_usec = 666000;
    result->set(&usage);
    EXPECT_EQ(result->time_used, 2333);
    EXPECT_EQ(result->memory_used, 666);
}
TEST(Result, set_judge_result_ole) {
    Result *result = new Result();
    Limit *limit = new Limit(1000, 512 * 1024, 1024);
    result->set(limit, SIGXFSZ);
    EXPECT_EQ(result->judge_result, OLE);
}
TEST(Result, set_judge_result_tle1) {
    Result *result = new Result();
    Limit *limit = new Limit(1000, 512 * 1024, 1024);
    result->set(limit, SIGALRM);
    EXPECT_EQ(result->judge_result, TLE);
}
TEST(Result, set_judge_result_tle2) {
    Result *result = new Result();
    Limit *limit = new Limit(1000, 512 * 1024, 1024);
    result->set(limit, SIGKILL);
    EXPECT_EQ(result->judge_result, TLE);
}
TEST(Result, set_judge_result_tle3) {
    Result *result = new Result();
    Limit *limit = new Limit(1000, 512 * 1024, 1024);
    result->set(limit, SIGXCPU);
    EXPECT_EQ(result->judge_result, TLE);
}
TEST(Result, set_judge_result_mle) {
    Result *result = new Result();
    result->memory_used = 256 * 1024;
    Limit *limit = new Limit(1000, 128 * 1024, 1024);
    result->set(limit, SIGSEGV);
    EXPECT_EQ(result->judge_result, MLE);
}
TEST(Result, set_judge_result_re) {
    Result *result = new Result();
    result->memory_used = 256 * 1024;
    Limit *limit = new Limit(1000, 512 * 1024, 1024);
    result->set(limit, SIGSEGV);
    EXPECT_EQ(result->judge_result, RE);
}

TEST(Result, fix_judge_result_tle) {
    Result *result = new Result();
    result->time_used = 2000;
    result->memory_used = 256 * 1024;
    Limit *limit = new Limit(1000, 512 * 1024, 1024);
    result->fix(limit);
    EXPECT_EQ(result->judge_result, TLE);
}
TEST(Result, fix_judge_result_mle) {
    Result *result = new Result();
    result->time_used = 2000;
    result->memory_used = 256 * 1024;
    Limit *limit = new Limit(3000, 128 * 1024, 1024);
    result->fix(limit);
    EXPECT_EQ(result->judge_result, MLE);
}
TEST(Result, fix_judge_result_ac) {
    Result *result = new Result();
    result->time_used = 2000;
    result->memory_used = 256 * 1024;
    Limit *limit = new Limit(3000, 512 * 1024, 1024);
    result->fix(limit);
    EXPECT_EQ(result->judge_result, AC);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
