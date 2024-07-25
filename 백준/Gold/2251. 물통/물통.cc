#include <iostream>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

queue<pair<pair<int, int>, int>> check;
int visited[201][201][201];
set<int> can_c;

int main (void){
    int a, b, c;
    int p_a, p_b, p_c;
    int n_a, n_b, n_c;
    int move;
    set<int>::iterator it;
    
    scanf("%d %d %d", &a, &b, &c);
    
    check.push(make_pair(make_pair(0, 0),c));
    can_c.insert(c);
    
    while(!check.empty()){
        p_a = check.front().first.first;
        p_b = check.front().first.second;
        p_c = check.front().second;
        check.pop();
        
        if(visited[p_a][p_b][p_c])
            continue;
        
        visited[p_a][p_b][p_c] = 1;
        
       // printf("%d %d %d\n", p_a, p_b, p_c);
        
        if(p_a!=0){
            if(p_b!=b){      //A->B
                move = min(p_a, b - p_b);
                n_a = p_a - move;
                n_b = p_b + move;
                n_c = p_c;
                check.push(make_pair(make_pair(n_a, n_b),n_c));
                if(n_a == 0)
                    can_c.insert(n_c);
            }
            if(p_c!=c){     //A->C
                move = min(p_a, c - p_c);
                n_a = p_a - move;
                n_b = p_b;
                n_c = p_c + move;
                check.push(make_pair(make_pair(n_a, n_b),n_c));
                if(n_a == 0)
                    can_c.insert(n_c);
            }
        }
        
        if(p_b!=0){
            if(p_a!=a){      //B->A
                move = min(p_b, a - p_a);
                n_a = p_a + move;
                n_b = p_b - move;
                n_c = p_c;
                check.push(make_pair(make_pair(n_a, n_b),n_c));
                if(n_a == 0)
                    can_c.insert(n_c);
           
            }
            if(p_c!=c){     //B->C
                move = min(p_b, c - p_c);
                n_a = p_a;
                n_b = p_b - move;
                n_c = p_c + move;
                check.push(make_pair(make_pair(n_a, n_b),n_c));
                if(n_a == 0)
                    can_c.insert(n_c);
            }
        }
        
        if(p_c!=0){
            if(p_a!=a){      //C->A
                move = min(p_c, a - p_a);
                n_a = p_a + move;
                n_b = p_b;
                n_c = p_c - move;
                check.push(make_pair(make_pair(n_a, n_b),n_c));
                if(n_a == 0)
                    can_c.insert(n_c);
           
            }
            if(p_b!=b){     //C->B
                move = min(p_c, b - p_b);
                n_a = p_a;
                n_b = p_b + move;
                n_c = p_c - move;
                check.push(make_pair(make_pair(n_a, n_b),n_c));
                if(n_a == 0)
                    can_c.insert(n_c);
            }
        }
    }
    
    for (it = can_c.begin(); it != can_c.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
}