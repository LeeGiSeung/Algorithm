#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].find(phone_book[i]) == 0) { //찾았을경우 0번 인덱스부터 찾아야함
            return false;
        }
    }

    return true;
}

int main() {

    vector<string> v({ "1124", "113", "112" });

    solution(v);
}