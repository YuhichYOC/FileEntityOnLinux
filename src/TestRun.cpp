/*
 *
 * TestRun.cpp
 *
 * Copyright 2016 Yuichi Yoshii
 *     吉井雄一 @ 吉井産業  you.65535.kir@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "FileEntityOnLinux.h"

void TestMethod01() {
    FileEntityOnLinux f;
    f.SetFullPath("/home/mssqlserver/box/test.txt");
    if (f.FindFile()) {
        cout << "Found /home/mssqlserver/box/test.txt" << "\n";
    }
    else {
        cout << "not Found /home/mssqlserver/box/test.txt" << "\n";
    }
}

void TestMethod02() {
    FileEntityOnLinux f;
    f.SetFullPath("/home/mssqlserver/box/test.txt");
    f.ReadPrepare(false);
    if (!f.IsReadPrepared()) {
        cout << "Prepare to read file Failed." << "\n";
        return;
    }
    f.ReadFile();
    if (!f.IsReadSuccess()) {
        cout << "Read file Failed." << "\n";
        return;
    }
    string out = f.GetFileLines().at(2);
    cout << out << "\n";
}

void TestMethod03() {
    FileEntityOnLinux f;
    f.SetFullPath("/home/mssqlserver/box/test2.txt");
    f.OverWritePrepare(false);
    if (!f.IsWritePrepared()) {
        cout << "Prepare to write file Failed." << "\n";
        return;
    }
    vector<string> lines;
    lines.push_back("test line - 01 : test message 01");
    lines.push_back("test line - 02 : テストメッセージ２");
    lines.push_back("test line - 03 : test message 03");
    f.SetFileLines(lines);
    f.WriteFile();
    if (!f.IsWriteSuccess()) {
        cout << "Write file Failed." << "\n";
        return;
    }
    else {
        cout << "Write file Success." << "\n";
        return;
    }
}

void TestMethod04() {
    FileEntityOnLinux f;
    f.SetFullPath("/home/mssqlserver/box/テスト.txt");
    f.OverWritePrepare(false);
    if (!f.IsWritePrepared()) {
        cout << "Prepare to write file Failed." << "\n";
        return;
    }
    vector<string> lines;
    lines.push_back("test line - 01 : test message 01");
    lines.push_back("test line - 02 : テストメッセージ２");
    lines.push_back("test line - 03 : test message 03");
    f.SetFileLines(lines);
    f.WriteFile();
    if (!f.IsWriteSuccess()) {
        cout << "Write file Failed." << "\n";
        return;
    }
    else {
        cout << "Write file Success." << "\n";
        return;
    }
}

void TestMethod05() {
    FileEntityOnLinux f1;
    f1.SetDirectory("/home/mssqlserver/box/テスト");
    f1.SetFileName("test05.txt");
    cout << "Full path of f1 is        " << f1.GetFullPath() << "\n";
    cout << "Directory name of f1 is   " << f1.GetDirectory() << "\n";
    cout << "File name of f1 is        " << f1.GetFileName() << "\n";
    FileEntityOnLinux f2;
    f2.SetFullPath("/home/mssqlserver/box/テスト/test05.txt");
    cout << "Full path of f2 is        " << f2.GetFullPath() << "\n";
    cout << "Directory name of f2 is   " << f2.GetDirectory() << "\n";
    cout << "File name of f2 is        " << f2.GetFileName() << "\n";
}

int main(int argc, char * argv[]) {
    TestMethod01();
    TestMethod02();
    TestMethod03();
    TestMethod04();
    TestMethod05();
    return 0;
}
