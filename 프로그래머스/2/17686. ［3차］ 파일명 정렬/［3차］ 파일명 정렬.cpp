#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>
using namespace std;

struct Data{
    string s;
    int number;
    int index;
};

bool solve(Data &a, Data&b){
    if(a.s != b.s){
        return a.s < b.s;
    }
    else if(a.number != b.number)
    {
        return a.number < b.number;
    }
    else{
        return a.index < b.index;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<string> file_list;
    vector<Data> v;
    
    //TAIL은 그 나머지 부분으로
    
    //정렬은 number로만
    //대소문자 구분하지않고 정렬해야함 upper


    for(int i = 0; i<files.size(); i++){
        string head = "";
        string number = "";
        int curnumber = 0;
        
        string s = files[i];
        int j = 0;
        
        while(j<s.size() && !isdigit(s[j])){
            head+= tolower(s[j]);
            j++;
        }
        
        while(j<s.size() && isdigit(s[j])){
            number+= s[j];
            j++;
        }
        
        curnumber = stoi(number);
        v.push_back({head,curnumber,i});
    }
    
    sort(v.begin(), v.end(), solve);
    
    for(int i = 0; i<v.size(); i++){
        answer.push_back(files[v[i].index]);
    }
    
    return answer;
}