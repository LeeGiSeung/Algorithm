#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
bool check[11][11][4]; //4포인트에서 사방으로 오는걸 검사해야함

int solution(string dirs) {
    int answer = 0;
    memset(check, false, sizeof(check));
    //0~10까지
    int x = 5;
    int y = 5;
    for(int i = 0; i<dirs.size(); i++){
        int nx = x; int ny = y;
        int direction = 0;
        if(dirs[i] == 'U'){
            nx -= 1;
            direction = 0;
        }
        else if(dirs[i] == 'D'){
            nx += 1;
            direction = 1;
        }
        else if(dirs[i] == 'R'){
            ny += 1;
            direction = 2;
        }
        else if(dirs[i] == 'L'){
            ny -= 1;
            direction = 3;
        }
        if(nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;
        if(!check[x][y][direction]){
            bool ch = false;
            check[x][y][direction] = true;
            if(direction == 0 || direction == 1){
                if(direction == 0){
                    if(!check[nx][ny][1]){
                        check[nx][ny][1] = true;
                        ch = true;
                    }
                } 
                if(direction == 1){
                    if(!check[nx][ny][0]){
                        check[nx][ny][0] = true;
                        ch = true;
                    }
                } 
            }
            else if(direction == 2 || direction == 3){
                if(direction == 2){
                    if(!check[nx][ny][3]){
                        check[nx][ny][3] = true;
                        ch = true;
                    }
                }
                if(direction == 3){
                    if(!check[nx][ny][2]){
                        check[nx][ny][2] = true;
                        ch = true;
                    }
                }
            }
            if(ch){
                answer++;
                //cout<<nx<<" "<<ny<<" 추가됨"<<endl;
            }

            
        } 
        x = nx; y = ny;
        //cout<<nx<<" "<<ny<<" 접근이 됨"<<endl;
        //cout<<endl;
    }
    
    return answer;
}