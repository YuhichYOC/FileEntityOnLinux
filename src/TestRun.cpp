/*
 * TestRun.cpp
 *
 *  Created on: 2017/02/23
 *      Author: mssqlserver
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
