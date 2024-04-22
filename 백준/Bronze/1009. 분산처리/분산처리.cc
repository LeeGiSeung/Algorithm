#include <iostream>

int main(int argc, char **argv){
    int T, a, b, tmp = 1;
    scanf("%d",&T);
    for(int i=0; i<T; i++){
        scanf("%d %d",&a,&b); // 1의 자리만 알면 된다.
        // 그냥 pow 불가능, 범위 넘는다.
        for(int j=0; j<b; j++){
            tmp = (tmp * a) % 10;
        }
        if(tmp == 0){
            printf("10\n"); // 나머지 0이면 10이다.
        } else {
            printf("%d\n",tmp);
        }
        tmp = 1; // 초기화
    }

    return 0;
}