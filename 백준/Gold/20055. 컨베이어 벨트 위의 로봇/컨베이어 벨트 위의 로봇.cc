#include <iostream>
#include <vector>
using namespace std;
int n, k;
int belt[202];
bool robot[202] = {0};
int start_pos = 0;
int end_pos;
int inital_robot_pos = -1;
int result = 1;
int cnt = 0;
bool stop = false;
 
void rotation_belt(){
    if(start_pos == 0) // 0이면 맨 뒤의 인덱스로 옮김
        start_pos = 2 * n - 1;
    else
        start_pos--;
    
    if(end_pos == 0) // 0이면 맨 뒤의 인덱스로 옮김
        end_pos = 2 * n - 1;
    else
        end_pos--;
 
    if(robot[end_pos])
        robot[end_pos] = false;
}  
 
void move_robot(){
    if(inital_robot_pos != -1){ 
        // 첫번째 단계에서는 로봇이 없기 때문에 패스
        int idx = end_pos;
        for (int i = 0; i < n-1;i++){
            int next = idx; // 로봇이 갈 다음 위치
            if(idx == 0)
                idx = 2 * n - 1; // 현재 위치      
            else
                idx--; 
 
            if(!robot[next] && robot[idx] && belt[next] > 0){
                // 다음 위치에 로봇이 없는지
                // 현재 위치에 로봇 존재 하는지
                // 다음 위치의 내구도가 0보다 큰지
                belt[next] -= 1; // 내구도 감소
                if(belt[next] == 0){ // 내구도가 0이면
                    cnt++; // 내구도 0 개수 추가
                    if(cnt >= k){
                        stop = true; // 종료 flag
                        break;
                    }
                }
                robot[next] = true; // 다음 좌표 로봇 true
                robot[idx] = false; // 현재 좌표 로봇은 옮겼으니 false
            }
        }
        robot[end_pos] = false; // 내리는 위치 로봇 내려줌
 
    }
}
 
void put_robot(){
    if(belt[start_pos] > 0){ 
        belt[start_pos] -= 1; // 내구도 감소
        if(belt[start_pos] == 0){ // 종료 조건
            cnt++;
            if(cnt >= k){
                stop = true;
            }
        }
        robot[start_pos] = true; // 로봇 올림
        inital_robot_pos = 0; // 로봇 올리기 시작.
    }
}
 
int main(){
    cin >> n >> k;
    int temp;
    for (int i = 0; i < 2*n;i++){
        cin >> belt[i];   
    }
    end_pos = n - 1;
    while(!stop){
        rotation_belt();
        move_robot();
        put_robot();
        if(stop) // 종료
            break;
        result++; // 단계 완수
    }
    cout << result << endl;
    return 0;
}
