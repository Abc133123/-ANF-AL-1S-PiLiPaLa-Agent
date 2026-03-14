#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
 
struct Person {
    string name;
    string gender;
    string province;
    string city;
};
 
void showInfo(string title, string message) {
    MessageBoxA(NULL, message.c_str(), title.c_str(), MB_OKCANCEL | MB_ICONINFORMATION);
}
 
int main() {
    system("chcp 65001 > nul");
    
    // 通配目标（所有人）
    Person target = {
        "*",  // 任意姓名
        "*",  // 任意性别
        "*",  // 任意省份
        "*"   // 任意城市
    };
    
    cout << "╔══════════════════════════════════════════╗" << endl;
    cout << "║      太原之恋 · 版本三：通配模式          ║" << endl;
    cout << "╚══════════════════════════════════════════╝" << endl;
    cout << endl;
    cout << "通配符已启用：所有 * 号代表任意匹配" << endl;
    cout << "目标范围：所有人" << endl << endl;
    
    // 第1条信息
    int result = MessageBoxA(NULL, 
        "姓名：*（任意）\n性别：*（任意）\n\n是否继续查看？", 
        "通配目标 - 第1条", 
        MB_OKCANCEL | MB_ICONINFORMATION);
    
    if (result == IDOK) {
        // 用户感兴趣，显示第2条
        result = MessageBoxA(NULL,
            "省份：*（任意）\n城市：*（任意）\n\n是否继续？",
            "通配目标 - 第2条",
            MB_OKCANCEL | MB_ICONINFORMATION);
        
        if (result == IDOK) {
            // 用户还感兴趣，显示第3条
            MessageBoxA(NULL,
                "匹配范围：所有人\n\n这是一个面向全体人民的服务。",
                "通配目标 - 第3条",
                MB_OK | MB_ICONINFORMATION);
            cout << ">>> 用户查看了全部信息 <<<" << endl;
        } else {
            cout << ">>> 用户在第2条失去兴趣 <<<" << endl;
        }
    } else {
        cout << ">>> 用户在第1条失去兴趣 <<<" << endl;
    }
    
    cout << endl;
    system("pause");
    return 0;
}