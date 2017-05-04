//
// Created by guessever on 5/4/17.
//

#include <gtest/gtest.h>
#include "src/Grun.h"

JUDGE_RESULT judge(const char *filename) {
    char *src = new char[255];
    sprintf(src, "/home/guessever/grun/tests/%s.cpp", filename);
    Grun *program = new Grun(
            src, // source code file
            1000, // time limit (MS)
            256 * 1024, // memory limit (KB)
            1 * 1024 // output limit (KB)
    );
    program->prepare("/home/guessever/grun/judge");
    if (program->compile() == SUCCESS) {
        program->run("/home/guessever/grun/tests/000.in", "/home/guessever/grun/tests/000.out");
    }
    return program->result->judge_result;
}

TEST(AC, 0) { EXPECT_EQ(judge("AC"), AC); }
TEST(PE, 0) { EXPECT_EQ(judge("PE"), PE); }
TEST(WA, 0) { EXPECT_EQ(judge("WA"), WA); }
TEST(OLE, 0) { EXPECT_EQ(judge("OLE"), OLE); }
TEST(TLE, 0) { EXPECT_EQ(judge("TLE"), TLE); }
TEST(MLE, 0) { EXPECT_EQ(judge("MLE"), MLE); }
TEST(CE, 0) { EXPECT_EQ(judge("CE"), CE); }
TEST(RE, array) { EXPECT_EQ(judge("REarray"), RE); }
TEST(RE, dfs) { EXPECT_EQ(judge("REdfs"), RE); }
//TEST(RF, execl) { EXPECT_EQ(judge("RFexecl"), RF); }
//TEST(RF, execle) { EXPECT_EQ(judge("RFexecle"), RF); }
//TEST(RF, execlp) { EXPECT_EQ(judge("RFexeclp"), RF); }
//TEST(RF, execv) { EXPECT_EQ(judge("RFexecv"), RF); }
//TEST(RF, execve) { EXPECT_EQ(judge("RFexecve"), RF); }
//TEST(RF, execvp) { EXPECT_EQ(judge("RFexecvp"), RF); }
//TEST(RF, file) { EXPECT_EQ(judge("RFfile"), RF); }
TEST(RF, fork) { EXPECT_EQ(judge("RFfork"), RF); }
TEST(RF, freopen) { EXPECT_EQ(judge("RFfreopen"), RF); }
TEST(RF, system) { EXPECT_EQ(judge("RFsystem"), RF); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
