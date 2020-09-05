#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>

using namespace std;

map<string, int> mp[2];
typedef pair<string, int> Elem;

int toNumber(string str, int &pos) {
    int re = 0;
    while (isdigit(str[pos])) 
        re = re * 10 + str[pos++] - '0';
    return re;
}

void solve(string str, int tag) {
    int coe = 1, pos = 0;		// coe: 系数， pos: 字符串下标
    vector<Elem> arr;			// 存元素的数组
    if (isdigit(str[pos])) coe = toNumber(str, pos); //算出全局系数，也就是最前面的数字

    while (pos < str.size()) {
        if (isdigit(str[pos])) {	// 遇到数字，就开始计算，除了全局系数，其他系数都存在于元素末尾
            int num = toNumber(str, pos);
            int i = arr.size() - 1;
            if (arr[i].first == ")") {	// 数字前一位是')'，那么就要一个 '(' , ')' 组合内的所有元素乘倍数
                arr[i].first = "pass";	// 并修改标记，表示已经用过，避免嵌套的括号二次利用
                while (arr[--i].first != "(") arr[i].second *= num; // 找到对应的'('并修改标记
                arr[i].first = "pass";
            }
            else arr[i].second *= num; // 若数字前不是括号，则为元素本身，那么直接乘倍就好了
        }
        else if (str[pos] == '(') { //直接入数组
            arr.push_back(Elem("(", 0));
            pos++;
        }
        else if (str[pos] == ')') {
            arr.push_back(Elem(")", 0));
            if (!isdigit(str[++pos])) str.insert(pos, "1"); // 如果')'后面没有数字，那么我们就给他一个‘1’，保证所有都是')'数字结尾
        }
        else if (isupper(str[pos])) { // 遇到元素
            string name = "";
            name += str[pos];
            pos++;
            if (islower(str[pos])) {
                name += str[pos];
                pos++;
            }
            arr.push_back(Elem(name, 1));
        }
    }

    for (int i = 0; i != arr.size(); i++) { 
        if (arr[i].first == "pass" ) continue; // 遇到非元素直接pass
        mp[tag][arr[i].first] += arr[i].second * coe;
    }
}

bool Judge(string str) {
    mp[0].clear();
	mp[1].clear();
    int pos = str.find('=');
    string tmp;
    string left = str.substr(0, pos);
    string right = str.substr(pos + 1);
    stringstream left_ss(left), right_ss(right);

    while (getline(left_ss, tmp, '+')) solve(tmp, 0);
    while (getline(right_ss, tmp, '+')) solve(tmp, 1);

    if (mp[0].size() != mp[1].size()) return false;
    for (map<string, int>::iterator it = mp[0].begin(); it != mp[0].end(); ++it) 
        if (mp[1][it->first] != it->second) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        if (Judge(str)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
